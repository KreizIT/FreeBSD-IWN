/*-
 * Copyright (c) 2013 Cedric GROSS <cg@cgross.info>
 * Copyright (c) 2011 Intel Corporation
 * Copyright (c) 2007-2009
 *	Damien Bergamini <damien.bergamini@free.fr>
 * Copyright (c) 2008
 *	Benjamin Close <benjsc@FreeBSD.org>
 * Copyright (c) 2008 Sam Leffler, Errno Consulting
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

/*
 * Driver for Intel WiFi Link 4965 and 1000/2000/5000/6000 Series 802.11
 * network adapters.
 */

#include "opt_wlan.h"
#include "opt_iwn.h"

#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/socket.h>
#include <sys/bus.h>
#include <sys/endian.h>

#include <machine/bus.h>

#include <net/if.h>
#include <net/if_dl.h>
#include <net/if_media.h>

#include <net80211/ieee80211_var.h>

#include <dev/iwn/if_iwnreg.h>
#include <dev/iwn/if_iwnvar.h>

#include <dev/iwn/if_iwn_pan.h>

static int	iwn_auth_pan(struct iwn_softc *, struct ieee80211vap *);
static int	iwn_set_timing_pan(struct iwn_softc *);
static int	iwn_run_pan(struct iwn_softc *, struct ieee80211vap *);
static int	iwn_config_pan(struct iwn_softc *);
static int	iwn_updateedca_pan(struct ieee80211com *);
static int	iwn_add_broadcast_node_pan(struct iwn_softc *, int);

int
iwn_newstate_pan(struct ieee80211vap *vap, enum ieee80211_state nstate,
    int arg)
{
	struct iwn_vap *ivp = IWN_VAP(vap);
	struct ieee80211com *ic = vap->iv_ic;
	struct iwn_softc *sc = ic->ic_ifp->if_softc;

	int error = 0;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	DPRINTF(sc, IWN_DEBUG_STATE, "%s: %s -> %s\n", __func__,
	    ieee80211_state_name[vap->iv_state], ieee80211_state_name[nstate]);

	IEEE80211_UNLOCK(ic);
	IWN_LOCK(sc);
	callout_stop(&sc->calib_to);

	sc->rxon = &sc->rx_on[IWN_RXON_PAN_CTX];

	switch (nstate) {
	case IEEE80211_S_ASSOC:
		if (vap->iv_state != IEEE80211_S_RUN)
			break;
		/* FALLTHROUGH */
	case IEEE80211_S_AUTH:
		if (vap->iv_state == IEEE80211_S_AUTH)
			break;

		/*
		 * !AUTH -> AUTH transition requires state reset to handle
		 * reassociations correctly.
		 */
		sc->rxon->associd = 0;
		sc->rxon->filter &= ~htole32(IWN_FILTER_BSS);
		sc->calib.state = IWN_CALIB_STATE_INIT;

		if ((error = iwn_auth_pan(sc, vap)) != 0) {
			device_printf(sc->sc_dev,
			    "%s: could not move to auth state\n", __func__);
		}
		break;

	case IEEE80211_S_SCAN:

		if ((error = iwn_set_timing_pan(sc)) != 0) {
			device_printf(sc->sc_dev,
			    "%s: iwn_set_timing_pan error %d\n", __func__, error);
			return error;
		}

		break;

	case IEEE80211_S_RUN:

		/*
		 * RUN -> RUN transition; Just restart the timers.
		 */
		if (vap->iv_state == IEEE80211_S_RUN) {
			sc->calib_cnt = 0;
			break;
		}

		/*
		 * !RUN -> RUN requires setting the association id
		 * which is done with a firmware cmd.  We also defer
		 * starting the timers until that work is done.
		 */
		if ((error = iwn_run_pan(sc, vap)) != 0) {
			device_printf(sc->sc_dev,
			    "%s: could not move to run state\n", __func__);
		}
		break;

	case IEEE80211_S_INIT:
		sc->calib.state = IWN_CALIB_STATE_INIT;
		break;

	default:
		break;
	}
	IWN_UNLOCK(sc);
	IEEE80211_LOCK(ic);
	if (error != 0) {
		DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end in error\n", __func__);
		return error;
	}
	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);
	return ivp->iv_newstate(vap, nstate, arg);
}

static int
iwn_auth_pan(struct iwn_softc *sc, struct ieee80211vap *vap)
{
	struct iwn_ops *ops = &sc->ops;
	struct ifnet *ifp = sc->sc_ifp;
	struct ieee80211com *ic = ifp->if_l2com;
	struct ieee80211_node *ni = vap->iv_bss;
	int error;
	struct iwn_vap *ivp = IWN_VAP(vap);

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	sc->rxon = &sc->rx_on[IWN_RXON_PAN_CTX];
	IEEE80211_ADDR_COPY(sc->rxon->myaddr, ivp->macaddr);
	IEEE80211_ADDR_COPY(sc->rxon->wlap, IF_LLADDR(ifp));
	/* Update adapter configuration. */
	IEEE80211_ADDR_COPY(sc->rxon->bssid, ni->ni_bssid);
	sc->rxon->chan = ieee80211_chan2ieee(ic, ni->ni_chan);
	sc->rxon->flags = htole32(IWN_RXON_TSF | IWN_RXON_CTS_TO_SELF);
	if (IEEE80211_IS_CHAN_2GHZ(ni->ni_chan))
		sc->rxon->flags |= htole32(IWN_RXON_AUTO | IWN_RXON_24GHZ);
	if (ic->ic_flags & IEEE80211_F_SHSLOT)
		sc->rxon->flags |= htole32(IWN_RXON_SHSLOT);
	if (ic->ic_flags & IEEE80211_F_SHPREAMBLE)
		sc->rxon->flags |= htole32(IWN_RXON_SHPREAMBLE);
	if (IEEE80211_IS_CHAN_A(ni->ni_chan)) {
		sc->rxon->cck_mask  = 0;
		sc->rxon->ofdm_mask = 0x15;
	} else if (IEEE80211_IS_CHAN_B(ni->ni_chan)) {
		sc->rxon->cck_mask  = 0x03;
		sc->rxon->ofdm_mask = 0;
	} else {
		/* Assume 802.11b/g. */
		sc->rxon->cck_mask  = 0x0f;
		sc->rxon->ofdm_mask = 0x15;
	}
	DPRINTF(sc, IWN_DEBUG_STATE, "rxon chan %d flags %x cck %x ofdm %x\n",
	    sc->rxon->chan, sc->rxon->flags, sc->rxon->cck_mask,
	    sc->rxon->ofdm_mask);
	sc->rxon->mode = IWN_MODE_2STA;
	error = iwn_cmd(sc, IWN_CMD_WIPAN_RXON, sc->rxon, sc->rxonsz, 0);
	if (error != 0) {
		device_printf(sc->sc_dev, "%s: RXON command failed, error %d\n",
		    __func__, error);
		return error;
	}

	/* Configuration has changed, set TX power accordingly. */
	if ((error = ops->set_txpower(sc, ni->ni_chan, 1)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not set TX power, error %d\n", __func__, error);
		return error;
	}
	/*
	 * Reconfiguring RXON clears the firmware nodes table so we must
	 * add the broadcast node again.
	 */
	if ((error = iwn_add_broadcast_node_pan(sc, 0)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not add broadcast node, error %d\n", __func__,
		    error);
		return error;
	}
	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

	return 0;
}

static int
iwn_set_timing_pan(struct iwn_softc *sc)
{
	struct iwn_cmd_timing cmd;
	int error = 0;
	struct ieee80211vap *vap;
	struct iwn_vap *ivp;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	vap = sc->ivap[IWN_RXON_PAN_CTX];
	ivp = IWN_VAP(vap);

	if ((error = iwn_config_pan(sc)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: iwn_config1 error %d\n", __func__, error);
		return error;
	}

	if ((error = iwn_set_pan_params(sc)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: iwn_set_pan_params error %d\n", __func__, error);
		return error;
	}

	memset(&cmd, 0, sizeof cmd);
	cmd.lintval = htole16(10);
	cmd.bintval = htole16(IWN_BEACON_INTERVAL_DEFAULT);
	ivp->beacon_int = cmd.bintval;
	cmd.binitval = htole32(0x032000);
	cmd.dtim_period = 1;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

	return iwn_cmd(sc, IWN_CMD_WIPAN_RXON_TIMING, &cmd, sizeof cmd, 0);
}
static int
iwn_run_pan(struct iwn_softc *sc, struct ieee80211vap *vap)
{
	struct iwn_ops *ops = &sc->ops;
	struct ifnet *ifp = sc->sc_ifp;
	struct ieee80211com *ic = ifp->if_l2com;
	struct ieee80211_node *ni = vap->iv_bss;
	struct iwn_vap *ivp = IWN_VAP(vap);
	struct iwn_node_info node;
	uint32_t htflags = 0;
	int error;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	if (ic->ic_opmode == IEEE80211_M_MONITOR) {
		/* Link LED blinks while monitoring. */
		return 0;
	}

	if ((error = iwn_set_timing_pan(sc)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not set timing, error %d\n", __func__, error);
	}

	if ((error = iwn_updateedca_pan(ic)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: iwn_updateedca_pan, error %d\n", __func__, error);
		return error;
	}

	sc->rxon = &sc->rx_on[IWN_RXON_PAN_CTX];
	IEEE80211_ADDR_COPY(sc->rxon->myaddr, ivp->macaddr);
	IEEE80211_ADDR_COPY(sc->rxon->wlap, IF_LLADDR(ifp));
	/* Update adapter configuration. */
	IEEE80211_ADDR_COPY(sc->rxon->bssid, ni->ni_bssid);
	sc->rxon->associd = htole16(IEEE80211_AID(ni->ni_associd));
	sc->rxon->chan = ieee80211_chan2ieee(ic, ni->ni_chan);
	sc->rxon->flags = htole32(IWN_RXON_TSF | IWN_RXON_CTS_TO_SELF);
	if (IEEE80211_IS_CHAN_2GHZ(ni->ni_chan))
		sc->rxon->flags |= htole32(IWN_RXON_AUTO | IWN_RXON_24GHZ);
	if (ic->ic_flags & IEEE80211_F_SHSLOT)
		sc->rxon->flags |= htole32(IWN_RXON_SHSLOT);
	if (ic->ic_flags & IEEE80211_F_SHPREAMBLE)
		sc->rxon->flags |= htole32(IWN_RXON_SHPREAMBLE);
	if (IEEE80211_IS_CHAN_A(ni->ni_chan)) {
		sc->rxon->cck_mask  = 0;
		sc->rxon->ofdm_mask = 0x15;
	} else if (IEEE80211_IS_CHAN_B(ni->ni_chan)) {
		sc->rxon->cck_mask  = 0x03;
		sc->rxon->ofdm_mask = 0;
	} else {
		/* Assume 802.11b/g. */
		sc->rxon->cck_mask  = 0x0f;
		sc->rxon->ofdm_mask = 0x15;
	}
	if (IEEE80211_IS_CHAN_HT(ni->ni_chan)) {
		htflags |= IWN_RXON_HT_PROTMODE(ic->ic_curhtprotmode);
		if (IEEE80211_IS_CHAN_HT40(ni->ni_chan)) {
			switch (ic->ic_curhtprotmode) {
			case IEEE80211_HTINFO_OPMODE_HT20PR:
				htflags |= IWN_RXON_HT_MODEPURE40;
				break;
			default:
				htflags |= IWN_RXON_HT_MODEMIXED;
				break;
			}
		}
		if (IEEE80211_IS_CHAN_HT40D(ni->ni_chan))
			htflags |= IWN_RXON_HT_HT40MINUS;
	}
	sc->rxon->flags |= htole32(htflags);
	sc->rxon->filter |= htole32(IWN_FILTER_BSS);
	DPRINTF(sc, IWN_DEBUG_STATE, "rxon chan %d flags %x\n",
	    sc->rxon->chan, sc->rxon->flags);
	sc->rxon->mode = IWN_MODE_2STA;
	error = iwn_cmd(sc, IWN_CMD_WIPAN_RXON, sc->rxon, sc->rxonsz, 0);
	if (error != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not update configuration, error %d\n", __func__,
		    error);
		return error;
	}

	/* Configuration has changed, set TX power accordingly. */
	if ((error = ops->set_txpower(sc, ni->ni_chan, 1)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not set TX power, error %d\n", __func__, error);
		return error;
	}

	/* Fake a join to initialize the TX rate. */
	((struct iwn_node *)ni)->id = IWN_STA_ID;
	iwn_newassoc(ni, 1);

	/* Add BSS node. */
	memset(&node, 0, sizeof node);
	node.htflags |= htole32(IWN_STA_FLAG_PAN_STATION);
	IEEE80211_ADDR_COPY(node.macaddr, ni->ni_macaddr);
	node.id = IWN_STA_ID;
	if (IEEE80211_IS_CHAN_HT(ni->ni_chan)) {
		switch (ni->ni_htcap & IEEE80211_HTCAP_SMPS) {
		case IEEE80211_HTCAP_SMPS_ENA:
			node.htflags |= htole32(IWN_SMPS_MIMO_DIS);
			break;
		case IEEE80211_HTCAP_SMPS_DYNAMIC:
			node.htflags |= htole32(IWN_SMPS_MIMO_PROT);
			break;
		}
		node.htflags |= htole32(IWN_AMDPU_SIZE_FACTOR(3) |
		    IWN_AMDPU_DENSITY(5));	/* 4us */
		if (IEEE80211_IS_CHAN_HT40(ni->ni_chan))
			node.htflags |= htole32(IWN_NODE_HT40);
	}
	DPRINTF(sc, IWN_DEBUG_STATE, "%s: adding BSS node1\n", __func__);
	error = ops->add_node(sc, &node, 0);
	if (error != 0) {
		device_printf(sc->sc_dev,
		    "%s: could not add BSS node1, error %d\n", __func__, error);
		return error;
	}

	/* Setting the initial rate for node */
	ni->ni_txrate = ni->ni_rates.rs_rates[0];

	/* XXX: init rate scaling */

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

#ifdef IWN_DTIM_INDICATES_UNICAST_PENDING_AT_AP
	return iwn_set_pslevel(sc, IWN_POWERSAVE_DTIM_VOIP_COMPATIBLE,
	    sc->desired_pwrsave_level, 0);
#else
	return 0;
#endif

}

static int
iwn_config_pan(struct iwn_softc *sc)
{
	struct ifnet *ifp = sc->sc_ifp;
	struct ieee80211com *ic = ifp->if_l2com;
	struct ieee80211vap *vap = sc->ivap[IWN_RXON_PAN_CTX];
	struct iwn_vap *ivp = IWN_VAP(vap);
	uint16_t rxchain;
	int error;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	sc->rxon = &sc->rx_on[IWN_RXON_PAN_CTX];
	IEEE80211_ADDR_COPY(sc->rxon->myaddr, ivp->macaddr);
	IEEE80211_ADDR_COPY(sc->rxon->wlap, IF_LLADDR(ifp));
	sc->rxon->chan = ieee80211_chan2ieee(ic, ic->ic_curchan);
	sc->rxon->flags = htole32(IWN_RXON_TSF);
	if (IEEE80211_IS_CHAN_2GHZ(ic->ic_curchan))
		sc->rxon->flags |= htole32(IWN_RXON_AUTO | IWN_RXON_24GHZ);
	sc->rxon->mode = IWN_MODE_P2P;
	sc->rxon->filter = htole32(IWN_FILTER_MULTICAST);
	sc->rxon->cck_mask  = 0x0f;	/* not yet negotiated */
	sc->rxon->ofdm_mask = 0xff;	/* not yet negotiated */
	sc->rxon->ht_single_mask = 0xff;
	sc->rxon->ht_dual_mask = 0xff;
	sc->rxon->ht_triple_mask = 0xff;
	rxchain =
	    IWN_RXCHAIN_VALID(sc->rxchainmask) |
	    IWN_RXCHAIN_MIMO_COUNT(2) |
	    IWN_RXCHAIN_IDLE_COUNT(2);
	sc->rxon->rxchain = htole16(rxchain);
	sc->rxon->associd = 0;
	sc->rxon->filter &= ~htole32(IWN_FILTER_BSS);

	error = iwn_cmd(sc, IWN_CMD_WIPAN_RXON, sc->rxon, sc->rxonsz, 0);
	if (error != 0) {
		device_printf(sc->sc_dev, "%s: IWN_CMD_WIPAN_RXON command failed\n",
		    __func__);
		return error;
	}
	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

	return 0;
}

int
iwn_set_pan_params(struct iwn_softc *sc)
{
	struct iwn_pan_params_cmd cmd;
	int slot0 = 300, slot1 = 0;
	int bcnint;
	int error = 0;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	/*
	 * If the PAN context is inactive, then we do not need
	 * to update the PAN parameters
	 */
	if (sc->ctx != IWN_RXON_PAN_CTX) {
		DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end with no need to do that\n",
		    __func__);
		return 0;
	}

	memset(&cmd, 0, sizeof(cmd));

	/* only 2 slots are currently allowed */
	cmd.num_slots = 2;

	cmd.slots[0].type = IWN_RXON_BSS_CTX;	/* BSS */
	cmd.slots[1].type = IWN_RXON_PAN_CTX;	/* PAN */

	cmd.flags |= htole16(IWN_PAN_PARAMS_FLG_SLOTTED_MODE);
	bcnint = IWN_BEACON_INTERVAL_DEFAULT;
	slot0 = (bcnint >> 1);
	slot1 = (bcnint - slot0);

	if(sc->uc_scan_progress == 1) {
		slot0 = bcnint * 3 - IWN_SLOT_TIME_MIN;
		slot1 = IWN_SLOT_TIME_MIN;
	}
	cmd.slots[0].time = htole16(slot0);
	cmd.slots[1].time = htole16(slot1);

	error = iwn_cmd(sc, IWN_CMD_WIPAN_PARAMS, &cmd, sizeof(cmd), 0);
	if (error != 0) {
		device_printf(sc->sc_dev,
		    "%s: IWN_CMD_WIPAN_PARAMS command failed, error %d\n",
		    __func__, error);
		return error;
	}

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

	return 0;
}

static int
iwn_updateedca_pan(struct ieee80211com *ic)
{
#define IWN_EXP2(x)	((1 << (x)) - 1)	/* CWmin = 2^ECWmin - 1 */
	struct iwn_softc *sc = ic->ic_ifp->if_softc;
	struct iwn_edca_params cmd;
	int aci;

	memset(&cmd, 0, sizeof cmd);
	cmd.flags = htole32(IWN_EDCA_UPDATE);
	for (aci = 0; aci < WME_NUM_AC; aci++) {
		const struct wmeParams *ac =
		    &ic->ic_wme.wme_chanParams.cap_wmeParams[aci];
		cmd.ac[aci].aifsn = ac->wmep_aifsn;
		cmd.ac[aci].cwmin = htole16(IWN_EXP2(ac->wmep_logcwmin));
		cmd.ac[aci].cwmax = htole16(IWN_EXP2(ac->wmep_logcwmax));
		cmd.ac[aci].txoplimit =
		    htole16(IEEE80211_TXOP_TO_US(ac->wmep_txopLimit));
	}
	return iwn_cmd(sc, IWN_CMD_WIPAN_QOS_PARAM, &cmd, sizeof cmd, 1);
#undef IWN_EXP2
}

/*
 * Broadcast node is used to send group-addressed and management frames.
 */
static int
iwn_add_broadcast_node_pan(struct iwn_softc *sc, int async)
{
	struct iwn_ops *ops = &sc->ops;
	struct ifnet *ifp = sc->sc_ifp;
	struct ieee80211com *ic = ifp->if_l2com;
	struct iwn_node_info node;
	struct iwn_cmd_link_quality linkq;
	uint8_t txant;
	int i, error;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s begin\n", __func__);

	sc->rxon = &sc->rx_on[IWN_RXON_PAN_CTX];

	memset(&node, 0, sizeof node);
	IEEE80211_ADDR_COPY(node.macaddr, ifp->if_broadcastaddr);

	node.id = IWN_PAN_ID_BCAST;
	node.htflags |= htole32(IWN_STA_FLAG_PAN_STATION);
	DPRINTF(sc, IWN_DEBUG_RESET, "%s: adding broadcast node1\n", __func__);
	if ((error = ops->add_node(sc, &node, async)) != 0)
		return error;

	/* Use the first valid TX antenna. */
	txant = IWN_LSB(sc->txchainmask);

	memset(&linkq, 0, sizeof linkq);
	linkq.id = IWN_PAN_ID_BCAST;
	linkq.antmsk_1stream = txant;
	linkq.antmsk_2stream = IWN_ANT_AB;
	linkq.ampdu_max = 64;
	linkq.ampdu_threshold = 3;
	linkq.ampdu_limit = htole16(4000);	/* 4ms */

	/* Use lowest mandatory bit-rate. */
	if (IEEE80211_IS_CHAN_5GHZ(ic->ic_curchan))
		linkq.retry[0] = htole32(0xd);
	else
		linkq.retry[0] = htole32(10 | IWN_RFLAG_CCK);
	linkq.retry[0] |= htole32(IWN_RFLAG_ANT(txant));
	/* Use same bit-rate for all TX retries. */
	for (i = 1; i < IWN_MAX_TX_RETRIES; i++) {
		linkq.retry[i] = linkq.retry[0];
	}
	DPRINTF(sc, IWN_DEBUG_TRACE, "->%s end\n", __func__);

	return iwn_cmd(sc, IWN_CMD_LINK_QUALITY, &linkq, sizeof linkq, async);
}

