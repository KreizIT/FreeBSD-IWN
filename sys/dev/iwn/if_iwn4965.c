/*-
 * Copyright (c) 2013 Cedric GROSS <c.gross@kreiz-it.fr>
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

/*
 * Driver for Intel WiFi Link 4965 802.11 network adapters.
 */


__FBSDID("$FreeBSD$");

static int
iwn4965_attach(struct iwn_softc *sc, uint16_t pid)
{
	struct iwn_ops *ops = &sc->ops;

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_RESET, "->%s begin\n", __func__);

	ops->load_firmware = iwn4965_load_firmware;
	ops->read_eeprom = iwn4965_read_eeprom;
	ops->post_alive = iwn4965_post_alive;
	ops->nic_config = iwn4965_nic_config;
	ops->update_sched = iwn4965_update_sched;
	ops->get_temperature = iwn4965_get_temperature;
	ops->get_rssi = iwn4965_get_rssi;
	ops->set_txpower = iwn4965_set_txpower;
	ops->init_gains = iwn4965_init_gains;
	ops->set_gains = iwn4965_set_gains;
	ops->add_node = iwn4965_add_node;
	ops->tx_done = iwn4965_tx_done;
	ops->ampdu_tx_start = iwn4965_ampdu_tx_start;
	ops->ampdu_tx_stop = iwn4965_ampdu_tx_stop;
	sc->ntxqs = IWN4965_NTXQUEUES;
	sc->firstaggqueue = IWN4965_FIRSTAGGQUEUE;
	sc->ndmachnls = IWN4965_NDMACHNLS;
	sc->broadcast_id = IWN4965_ID_BROADCAST;
	sc->rxonsz = IWN4965_RXONSZ;
	sc->schedsz = IWN4965_SCHEDSZ;
	sc->fw_text_maxsz = IWN4965_FW_TEXT_MAXSZ;
	sc->fw_data_maxsz = IWN4965_FW_DATA_MAXSZ;
	sc->fwsz = IWN4965_FWSZ;
	sc->sched_txfact_addr = IWN4965_SCHED_TXFACT;
	sc->limits = &iwn4965_sensitivity_limits;
	sc->fwname = "iwn4965fw";
	/* Override chains masks, ROM is known to be broken. */
	sc->txchainmask = IWN_ANT_AB;
	sc->rxchainmask = IWN_ANT_ABC;
	sc->base_params = &iwn_default_base_params; /* !! TODO : Define something may be more specific */

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_RESET, "%s: end\n",__func__);
	
	return 0;
}

static void
iwn4965_read_eeprom(struct iwn_softc *sc)
{
	uint32_t addr;
	uint16_t val;
	int i;

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_RESET, "->%s begin\n", __func__);

	/* Read regulatory domain (4 ASCII characters). */
	iwn_read_prom_data(sc, IWN4965_EEPROM_DOMAIN, sc->eeprom_domain, 4);

	/* Read the list of authorized channels (20MHz ones only). */
	for (i = 0; i < 7; i++) {
		addr = iwn4965_regulatory_bands[i];
		iwn_read_eeprom_channels(sc, i, addr);
	}

	/* Read maximum allowed TX power for 2GHz and 5GHz bands. */
	iwn_read_prom_data(sc, IWN4965_EEPROM_MAXPOW, &val, 2);
	sc->maxpwr2GHz = val & 0xff;
	sc->maxpwr5GHz = val >> 8;
	/* Check that EEPROM values are within valid range. */
	if (sc->maxpwr5GHz < 20 || sc->maxpwr5GHz > 50)
		sc->maxpwr5GHz = 38;
	if (sc->maxpwr2GHz < 20 || sc->maxpwr2GHz > 50)
		sc->maxpwr2GHz = 38;
	DPRINTF(sc, IWN_DEBUG_RESET, "maxpwr 2GHz=%d 5GHz=%d\n",
	    sc->maxpwr2GHz, sc->maxpwr5GHz);

	/* Read samples for each TX power group. */
	iwn_read_prom_data(sc, IWN4965_EEPROM_BANDS, sc->bands,
	    sizeof sc->bands);

	/* Read voltage at which samples were taken. */
	iwn_read_prom_data(sc, IWN4965_EEPROM_VOLTAGE, &val, 2);
	sc->eeprom_voltage = (int16_t)le16toh(val);
	DPRINTF(sc, IWN_DEBUG_RESET, "voltage=%d (in 0.3V)\n",
	    sc->eeprom_voltage);

#ifdef IWN_DEBUG
	/* Print samples. */
	if (sc->sc_debug & IWN_DEBUG_ANY) {
		for (i = 0; i < IWN_NBANDS; i++)
			iwn4965_print_power_group(sc, i);
	}
#endif

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_RESET, "->%s end\n", __func__);
}

#ifdef IWN_DEBUG
static void
iwn4965_print_power_group(struct iwn_softc *sc, int i)
{
	struct iwn4965_eeprom_band *band = &sc->bands[i];
	struct iwn4965_eeprom_chan_samples *chans = band->chans;
	int j, c;

	printf("===band %d===\n", i);
	printf("chan lo=%d, chan hi=%d\n", band->lo, band->hi);
	printf("chan1 num=%d\n", chans[0].num);
	for (c = 0; c < 2; c++) {
		for (j = 0; j < IWN_NSAMPLES; j++) {
			printf("chain %d, sample %d: temp=%d gain=%d "
			    "power=%d pa_det=%d\n", c, j,
			    chans[0].samples[c][j].temp,
			    chans[0].samples[c][j].gain,
			    chans[0].samples[c][j].power,
			    chans[0].samples[c][j].pa_det);
		}
	}
	printf("chan2 num=%d\n", chans[1].num);
	for (c = 0; c < 2; c++) {
		for (j = 0; j < IWN_NSAMPLES; j++) {
			printf("chain %d, sample %d: temp=%d gain=%d "
			    "power=%d pa_det=%d\n", c, j,
			    chans[1].samples[c][j].temp,
			    chans[1].samples[c][j].gain,
			    chans[1].samples[c][j].power,
			    chans[1].samples[c][j].pa_det);
		}
	}
}
#endif

/*
 * Process a TX_DONE firmware notification.  Unfortunately, the 4965AGN
 * and 5000 adapters have different incompatible TX status formats.
 */
static void
iwn4965_tx_done(struct iwn_softc *sc, struct iwn_rx_desc *desc,
    struct iwn_rx_data *data)
{
	struct iwn4965_tx_stat *stat = (struct iwn4965_tx_stat *)(desc + 1);
	struct iwn_tx_ring *ring;
	int qid;

	qid = desc->qid & 0xf;
	ring = &sc->txq[qid];

	DPRINTF(sc, IWN_DEBUG_XMIT, "%s: "
	    "qid %d idx %d retries %d nkill %d rate %x duration %d status %x\n",
	    __func__, desc->qid, desc->idx, stat->ackfailcnt,
	    stat->btkillcnt, stat->rate, le16toh(stat->duration),
	    le32toh(stat->status));

	bus_dmamap_sync(ring->data_dmat, data->map, BUS_DMASYNC_POSTREAD);
	if (qid >= sc->firstaggqueue) {
		iwn_ampdu_tx_done(sc, qid, desc->idx, stat->nframes,
		    &stat->status);
	} else {
		iwn_tx_done(sc, desc, stat->ackfailcnt,
		    le32toh(stat->status) & 0xff);
	}
}

/*
 * Update TX scheduler ring when transmitting an 802.11 frame (4965AGN and
 * 5000 adapters use a slightly different format).
 */
static void
iwn4965_update_sched(struct iwn_softc *sc, int qid, int idx, uint8_t id,
    uint16_t len)
{
	uint16_t *w = &sc->sched[qid * IWN4965_SCHED_COUNT + idx];

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	*w = htole16(len + 8);
	bus_dmamap_sync(sc->sched_dma.tag, sc->sched_dma.map,
	    BUS_DMASYNC_PREWRITE);
	if (idx < IWN_SCHED_WINSZ) {
		*(w + IWN_TX_RING_COUNT) = *w;
		bus_dmamap_sync(sc->sched_dma.tag, sc->sched_dma.map,
		    BUS_DMASYNC_PREWRITE);
	}
}

static int
iwn4965_add_node(struct iwn_softc *sc, struct iwn_node_info *node, int async)
{
	struct iwn4965_node_info hnode;
	caddr_t src, dst;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	/*
	 * We use the node structure for 5000 Series internally (it is
	 * a superset of the one for 4965AGN). We thus copy the common
	 * fields before sending the command.
	 */
	src = (caddr_t)node;
	dst = (caddr_t)&hnode;
	memcpy(dst, src, 48);
	/* Skip TSC, RX MIC and TX MIC fields from ``src''. */
	memcpy(dst + 48, src + 72, 20);
	return iwn_cmd(sc, IWN_CMD_ADD_NODE, &hnode, sizeof hnode, async);
}

static void
iwn4965_power_calibration(struct iwn_softc *sc, int temp)
{
	struct ifnet *ifp = sc->sc_ifp;
	struct ieee80211com *ic = ifp->if_l2com;

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_CALIBRATE, "->Doing %s\n", __func__);

	/* Adjust TX power if need be (delta >= 3 degC). */
	DPRINTF(sc, IWN_DEBUG_CALIBRATE, "%s: temperature %d->%d\n",
	    __func__, sc->temp, temp);
	if (abs(temp - sc->temp) >= 3) {
		/* Record temperature of last calibration. */
		sc->temp = temp;
		(void)iwn4965_set_txpower(sc, ic->ic_bsschan, 1);
	}
}

/*
 * Set TX power for current channel (each rate has its own power settings).
 * This function takes into account the regulatory information from EEPROM,
 * the current temperature and the current voltage.
 */
static int
iwn4965_set_txpower(struct iwn_softc *sc, struct ieee80211_channel *ch,
    int async)
{
/* Fixed-point arithmetic division using a n-bit fractional part. */
#define fdivround(a, b, n)	\
	((((1 << n) * (a)) / (b) + (1 << n) / 2) / (1 << n))
/* Linear interpolation. */
#define interpolate(x, x1, y1, x2, y2, n)	\
	((y1) + fdivround(((int)(x) - (x1)) * ((y2) - (y1)), (x2) - (x1), n))

	static const int tdiv[IWN_NATTEN_GROUPS] = { 9, 8, 8, 8, 6 };
	struct iwn_ucode_info *uc = &sc->ucode_info;
	struct iwn4965_cmd_txpower cmd;
	struct iwn4965_eeprom_chan_samples *chans;
	const uint8_t *rf_gain, *dsp_gain;
	int32_t vdiff, tdiff;
	int i, c, grp, maxpwr;
	uint8_t chan;

	sc->rxon = &sc->rx_on[IWN_RXON_BSS_CTX];
	/* Retrieve current channel from last RXON. */
	chan = sc->rxon->chan;
	DPRINTF(sc, IWN_DEBUG_RESET, "setting TX power for channel %d\n",
	    chan);

	memset(&cmd, 0, sizeof cmd);
	cmd.band = IEEE80211_IS_CHAN_5GHZ(ch) ? 0 : 1;
	cmd.chan = chan;

	if (IEEE80211_IS_CHAN_5GHZ(ch)) {
		maxpwr   = sc->maxpwr5GHz;
		rf_gain  = iwn4965_rf_gain_5ghz;
		dsp_gain = iwn4965_dsp_gain_5ghz;
	} else {
		maxpwr   = sc->maxpwr2GHz;
		rf_gain  = iwn4965_rf_gain_2ghz;
		dsp_gain = iwn4965_dsp_gain_2ghz;
	}

	/* Compute voltage compensation. */
	vdiff = ((int32_t)le32toh(uc->volt) - sc->eeprom_voltage) / 7;
	if (vdiff > 0)
		vdiff *= 2;
	if (abs(vdiff) > 2)
		vdiff = 0;
	DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
	    "%s: voltage compensation=%d (UCODE=%d, EEPROM=%d)\n",
	    __func__, vdiff, le32toh(uc->volt), sc->eeprom_voltage);

	/* Get channel attenuation group. */
	if (chan <= 20)		/* 1-20 */
		grp = 4;
	else if (chan <= 43)	/* 34-43 */
		grp = 0;
	else if (chan <= 70)	/* 44-70 */
		grp = 1;
	else if (chan <= 124)	/* 71-124 */
		grp = 2;
	else			/* 125-200 */
		grp = 3;
	DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
	    "%s: chan %d, attenuation group=%d\n", __func__, chan, grp);

	/* Get channel sub-band. */
	for (i = 0; i < IWN_NBANDS; i++)
		if (sc->bands[i].lo != 0 &&
		    sc->bands[i].lo <= chan && chan <= sc->bands[i].hi)
			break;
	if (i == IWN_NBANDS)	/* Can't happen in real-life. */
		return EINVAL;
	chans = sc->bands[i].chans;
	DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
	    "%s: chan %d sub-band=%d\n", __func__, chan, i);

	for (c = 0; c < 2; c++) {
		uint8_t power, gain, temp;
		int maxchpwr, pwr, ridx, idx;

		power = interpolate(chan,
		    chans[0].num, chans[0].samples[c][1].power,
		    chans[1].num, chans[1].samples[c][1].power, 1);
		gain  = interpolate(chan,
		    chans[0].num, chans[0].samples[c][1].gain,
		    chans[1].num, chans[1].samples[c][1].gain, 1);
		temp  = interpolate(chan,
		    chans[0].num, chans[0].samples[c][1].temp,
		    chans[1].num, chans[1].samples[c][1].temp, 1);
		DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
		    "%s: Tx chain %d: power=%d gain=%d temp=%d\n",
		    __func__, c, power, gain, temp);

		/* Compute temperature compensation. */
		tdiff = ((sc->temp - temp) * 2) / tdiv[grp];
		DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
		    "%s: temperature compensation=%d (current=%d, EEPROM=%d)\n",
		    __func__, tdiff, sc->temp, temp);

		for (ridx = 0; ridx <= IWN_RIDX_MAX; ridx++) {
			/* Convert dBm to half-dBm. */
			maxchpwr = sc->maxpwr[chan] * 2;
			if ((ridx / 8) & 1)
				maxchpwr -= 6;	/* MIMO 2T: -3dB */

			pwr = maxpwr;

			/* Adjust TX power based on rate. */
			if ((ridx % 8) == 5)
				pwr -= 15;	/* OFDM48: -7.5dB */
			else if ((ridx % 8) == 6)
				pwr -= 17;	/* OFDM54: -8.5dB */
			else if ((ridx % 8) == 7)
				pwr -= 20;	/* OFDM60: -10dB */
			else
				pwr -= 10;	/* Others: -5dB */

			/* Do not exceed channel max TX power. */
			if (pwr > maxchpwr)
				pwr = maxchpwr;

			idx = gain - (pwr - power) - tdiff - vdiff;
			if ((ridx / 8) & 1)	/* MIMO */
				idx += (int32_t)le32toh(uc->atten[grp][c]);

			if (cmd.band == 0)
				idx += 9;	/* 5GHz */
			if (ridx == IWN_RIDX_MAX)
				idx += 5;	/* CCK */

			/* Make sure idx stays in a valid range. */
			if (idx < 0)
				idx = 0;
			else if (idx > IWN4965_MAX_PWR_INDEX)
				idx = IWN4965_MAX_PWR_INDEX;

			DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
			    "%s: Tx chain %d, rate idx %d: power=%d\n",
			    __func__, c, ridx, idx);
			cmd.power[ridx].rf_gain[c] = rf_gain[idx];
			cmd.power[ridx].dsp_gain[c] = dsp_gain[idx];
		}
	}

	DPRINTF(sc, IWN_DEBUG_CALIBRATE | IWN_DEBUG_TXPOW,
	    "%s: set tx power for chan %d\n", __func__, chan);
	return iwn_cmd(sc, IWN_CMD_TXPOWER, &cmd, sizeof cmd, async);

#undef interpolate
#undef fdivround
}

static int
iwn4965_get_rssi(struct iwn_softc *sc, struct iwn_rx_stat *stat)
{
	struct iwn4965_rx_phystat *phy = (void *)stat->phybuf;
	uint8_t mask, agc;
	int rssi;

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_RECV, "->Doing %s\n", __func__);

	mask = (le16toh(phy->antenna) >> 4) & IWN_ANT_ABC;
	agc  = (le16toh(phy->agc) >> 7) & 0x7f;

	rssi = 0;
	if (mask & IWN_ANT_A)
		rssi = MAX(rssi, phy->rssi[0]);
	if (mask & IWN_ANT_B)
		rssi = MAX(rssi, phy->rssi[2]);
	if (mask & IWN_ANT_C)
		rssi = MAX(rssi, phy->rssi[4]);

	DPRINTF(sc, IWN_DEBUG_RECV,
	    "%s: agc %d mask 0x%x rssi %d %d %d result %d\n", __func__, agc,
	    mask, phy->rssi[0], phy->rssi[2], phy->rssi[4],
	    rssi - agc - IWN_RSSI_TO_DBM);
	return rssi - agc - IWN_RSSI_TO_DBM;
}

/*
 * Compute temperature (in degC) from last received statistics.
 */
static int
iwn4965_get_temperature(struct iwn_softc *sc)
{
	struct iwn_ucode_info *uc = &sc->ucode_info;
	int32_t r1, r2, r3, r4, temp;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	r1 = le32toh(uc->temp[0].chan20MHz);
	r2 = le32toh(uc->temp[1].chan20MHz);
	r3 = le32toh(uc->temp[2].chan20MHz);
	r4 = le32toh(sc->rawtemp);

	if (r1 == r3)	/* Prevents division by 0 (should not happen). */
		return 0;

	/* Sign-extend 23-bit R4 value to 32-bit. */
	r4 = ((r4 & 0xffffff) ^ 0x800000) - 0x800000;
	/* Compute temperature in Kelvin. */
	temp = (259 * (r4 - r2)) / (r3 - r1);
	temp = (temp * 97) / 100 + 8;

	DPRINTF(sc, IWN_DEBUG_ANY, "temperature %dK/%dC\n", temp,
	    IWN_KTOC(temp));
	return IWN_KTOC(temp);
}

static int
iwn4965_init_gains(struct iwn_softc *sc)
{
	struct iwn_phy_calib_gain cmd;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	memset(&cmd, 0, sizeof cmd);
	cmd.code = IWN4965_PHY_CALIB_DIFF_GAIN;
	/* Differential gains initially set to 0 for all 3 antennas. */
	DPRINTF(sc, IWN_DEBUG_CALIBRATE,
	    "%s: setting initial differential gains\n", __func__);
	return iwn_cmd(sc, IWN_CMD_PHY_CALIB, &cmd, sizeof cmd, 1);
}

static int
iwn4965_set_gains(struct iwn_softc *sc)
{
	struct iwn_calib_state *calib = &sc->calib;
	struct iwn_phy_calib_gain cmd;
	int i, delta, noise;

	DPRINTF(sc, IWN_DEBUG_TRACE | IWN_DEBUG_CALIBRATE, "->Doing %s\n", __func__);

	/* Get minimal noise among connected antennas. */
	noise = INT_MAX;	/* NB: There's at least one antenna. */
	for (i = 0; i < 3; i++)
		if (sc->chainmask & (1 << i))
			noise = MIN(calib->noise[i], noise);

	memset(&cmd, 0, sizeof cmd);
	cmd.code = IWN4965_PHY_CALIB_DIFF_GAIN;
	/* Set differential gains for connected antennas. */
	for (i = 0; i < 3; i++) {
		if (sc->chainmask & (1 << i)) {
			/* Compute attenuation (in unit of 1.5dB). */
			delta = (noise - (int32_t)calib->noise[i]) / 30;
			/* NB: delta <= 0 */
			/* Limit to [-4.5dB,0]. */
			cmd.gain[i] = MIN(abs(delta), 3);
			if (delta < 0)
				cmd.gain[i] |= 1 << 2;	/* sign bit */
		}
	}
	DPRINTF(sc, IWN_DEBUG_CALIBRATE,
	    "setting differential gains Ant A/B/C: %x/%x/%x (%x)\n",
	    cmd.gain[0], cmd.gain[1], cmd.gain[2], sc->chainmask);
	return iwn_cmd(sc, IWN_CMD_PHY_CALIB, &cmd, sizeof cmd, 1);
}

static void
iwn4965_ampdu_tx_start(struct iwn_softc *sc, struct ieee80211_node *ni,
    int qid, uint8_t tid, uint16_t ssn)
{
	struct iwn_node *wn = (void *)ni;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	/* Stop TX scheduler while we're changing its configuration. */
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_STATUS(qid),
	    IWN4965_TXQ_STATUS_CHGACT);

	/* Assign RA/TID translation to the queue. */
	iwn_mem_write_2(sc, sc->sched_base + IWN4965_SCHED_TRANS_TBL(qid),
	    wn->id << 4 | tid);

	/* Enable chain-building mode for the queue. */
	iwn_prph_setbits(sc, IWN4965_SCHED_QCHAIN_SEL, 1 << qid);

	/* Set starting sequence number from the ADDBA request. */
	sc->txq[qid].cur = sc->txq[qid].read = (ssn & 0xff);
	IWN_WRITE(sc, IWN_HBUS_TARG_WRPTR, qid << 8 | (ssn & 0xff));
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_RDPTR(qid), ssn);

	/* Set scheduler window size. */
	iwn_mem_write(sc, sc->sched_base + IWN4965_SCHED_QUEUE_OFFSET(qid),
	    IWN_SCHED_WINSZ);
	/* Set scheduler frame limit. */
	iwn_mem_write(sc, sc->sched_base + IWN4965_SCHED_QUEUE_OFFSET(qid) + 4,
	    IWN_SCHED_LIMIT << 16);

	/* Enable interrupts for the queue. */
	iwn_prph_setbits(sc, IWN4965_SCHED_INTR_MASK, 1 << qid);

	/* Mark the queue as active. */
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_STATUS(qid),
	    IWN4965_TXQ_STATUS_ACTIVE | IWN4965_TXQ_STATUS_AGGR_ENA |
	    iwn_tid2fifo[tid] << 1);
}

static void
iwn4965_ampdu_tx_stop(struct iwn_softc *sc, int qid, uint8_t tid, uint16_t ssn)
{
	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	/* Stop TX scheduler while we're changing its configuration. */
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_STATUS(qid),
	    IWN4965_TXQ_STATUS_CHGACT);

	/* Set starting sequence number from the ADDBA request. */
	IWN_WRITE(sc, IWN_HBUS_TARG_WRPTR, qid << 8 | (ssn & 0xff));
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_RDPTR(qid), ssn);

	/* Disable interrupts for the queue. */
	iwn_prph_clrbits(sc, IWN4965_SCHED_INTR_MASK, 1 << qid);

	/* Mark the queue as inactive. */
	iwn_prph_write(sc, IWN4965_SCHED_QUEUE_STATUS(qid),
	    IWN4965_TXQ_STATUS_INACTIVE | iwn_tid2fifo[tid] << 1);
}

/*
 * This function is called after the runtime firmware notifies us of its
 * readiness (called in a process context).
 */
static int
iwn4965_post_alive(struct iwn_softc *sc)
{
	int error, qid;

	if ((error = iwn_nic_lock(sc)) != 0)
		return error;

	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	/* Clear TX scheduler state in SRAM. */
	sc->sched_base = iwn_prph_read(sc, IWN_SCHED_SRAM_ADDR);
	iwn_mem_set_region_4(sc, sc->sched_base + IWN4965_SCHED_CTX_OFF, 0,
	    IWN4965_SCHED_CTX_LEN / sizeof (uint32_t));

	/* Set physical address of TX scheduler rings (1KB aligned). */
	iwn_prph_write(sc, IWN4965_SCHED_DRAM_ADDR, sc->sched_dma.paddr >> 10);

	IWN_SETBITS(sc, IWN_FH_TX_CHICKEN, IWN_FH_TX_CHICKEN_SCHED_RETRY);

	/* Disable chain mode for all our 16 queues. */
	iwn_prph_write(sc, IWN4965_SCHED_QCHAIN_SEL, 0);

	for (qid = 0; qid < IWN4965_NTXQUEUES; qid++) {
		iwn_prph_write(sc, IWN4965_SCHED_QUEUE_RDPTR(qid), 0);
		IWN_WRITE(sc, IWN_HBUS_TARG_WRPTR, qid << 8 | 0);

		/* Set scheduler window size. */
		iwn_mem_write(sc, sc->sched_base +
		    IWN4965_SCHED_QUEUE_OFFSET(qid), IWN_SCHED_WINSZ);
		/* Set scheduler frame limit. */
		iwn_mem_write(sc, sc->sched_base +
		    IWN4965_SCHED_QUEUE_OFFSET(qid) + 4,
		    IWN_SCHED_LIMIT << 16);
	}

	/* Enable interrupts for all our 16 queues. */
	iwn_prph_write(sc, IWN4965_SCHED_INTR_MASK, 0xffff);
	/* Identify TX FIFO rings (0-7). */
	iwn_prph_write(sc, IWN4965_SCHED_TXFACT, 0xff);

	/* Mark TX rings (4 EDCA + cmd + 2 HCCA) as active. */
	for (qid = 0; qid < 7; qid++) {
		static uint8_t qid2fifo[] = { 3, 2, 1, 0, 4, 5, 6 };
		iwn_prph_write(sc, IWN4965_SCHED_QUEUE_STATUS(qid),
		    IWN4965_TXQ_STATUS_ACTIVE | qid2fifo[qid] << 1);
	}
	iwn_nic_unlock(sc);
	return 0;
}

static int
iwn4965_load_bootcode(struct iwn_softc *sc, const uint8_t *ucode, int size)
{
	int error, ntries;

	size /= sizeof (uint32_t);

	if ((error = iwn_nic_lock(sc)) != 0)
		return error;

	/* Copy microcode image into NIC memory. */
	iwn_prph_write_region_4(sc, IWN_BSM_SRAM_BASE,
	    (const uint32_t *)ucode, size);

	iwn_prph_write(sc, IWN_BSM_WR_MEM_SRC, 0);
	iwn_prph_write(sc, IWN_BSM_WR_MEM_DST, IWN_FW_TEXT_BASE);
	iwn_prph_write(sc, IWN_BSM_WR_DWCOUNT, size);

	/* Start boot load now. */
	iwn_prph_write(sc, IWN_BSM_WR_CTRL, IWN_BSM_WR_CTRL_START);

	/* Wait for transfer to complete. */
	for (ntries = 0; ntries < 1000; ntries++) {
		if (!(iwn_prph_read(sc, IWN_BSM_WR_CTRL) &
		    IWN_BSM_WR_CTRL_START))
			break;
		DELAY(10);
	}
	if (ntries == 1000) {
		device_printf(sc->sc_dev, "%s: could not load boot firmware\n",
		    __func__);
		iwn_nic_unlock(sc);
		return ETIMEDOUT;
	}

	/* Enable boot after power up. */
	iwn_prph_write(sc, IWN_BSM_WR_CTRL, IWN_BSM_WR_CTRL_START_EN);

	iwn_nic_unlock(sc);
	return 0;
}

static int
iwn4965_load_firmware(struct iwn_softc *sc)
{
	struct iwn_fw_info *fw = &sc->fw;
	struct iwn_dma_info *dma = &sc->fw_dma;
	int error;

	/* Copy initialization sections into pre-allocated DMA-safe memory. */
	memcpy(dma->vaddr, fw->init.data, fw->init.datasz);
	bus_dmamap_sync(dma->tag, dma->map, BUS_DMASYNC_PREWRITE);
	memcpy(dma->vaddr + IWN4965_FW_DATA_MAXSZ,
	    fw->init.text, fw->init.textsz);
	bus_dmamap_sync(dma->tag, dma->map, BUS_DMASYNC_PREWRITE);

	/* Tell adapter where to find initialization sections. */
	if ((error = iwn_nic_lock(sc)) != 0)
		return error;
	iwn_prph_write(sc, IWN_BSM_DRAM_DATA_ADDR, dma->paddr >> 4);
	iwn_prph_write(sc, IWN_BSM_DRAM_DATA_SIZE, fw->init.datasz);
	iwn_prph_write(sc, IWN_BSM_DRAM_TEXT_ADDR,
	    (dma->paddr + IWN4965_FW_DATA_MAXSZ) >> 4);
	iwn_prph_write(sc, IWN_BSM_DRAM_TEXT_SIZE, fw->init.textsz);
	iwn_nic_unlock(sc);

	/* Load firmware boot code. */
	error = iwn4965_load_bootcode(sc, fw->boot.text, fw->boot.textsz);
	if (error != 0) {
		device_printf(sc->sc_dev, "%s: could not load boot firmware\n",
		    __func__);
		return error;
	}
	/* Now press "execute". */
	IWN_WRITE(sc, IWN_RESET, 0);

	/* Wait at most one second for first alive notification. */
	if ((error = msleep(sc, &sc->sc_mtx, PCATCH, "iwninit", hz)) != 0) {
		device_printf(sc->sc_dev,
		    "%s: timeout waiting for adapter to initialize, error %d\n",
		    __func__, error);
		return error;
	}

	/* Retrieve current temperature for initial TX power calibration. */
	sc->rawtemp = sc->ucode_info.temp[3].chan20MHz;
	sc->temp = iwn4965_get_temperature(sc);

	/* Copy runtime sections into pre-allocated DMA-safe memory. */
	memcpy(dma->vaddr, fw->main.data, fw->main.datasz);
	bus_dmamap_sync(dma->tag, dma->map, BUS_DMASYNC_PREWRITE);
	memcpy(dma->vaddr + IWN4965_FW_DATA_MAXSZ,
	    fw->main.text, fw->main.textsz);
	bus_dmamap_sync(dma->tag, dma->map, BUS_DMASYNC_PREWRITE);

	/* Tell adapter where to find runtime sections. */
	if ((error = iwn_nic_lock(sc)) != 0)
		return error;
	iwn_prph_write(sc, IWN_BSM_DRAM_DATA_ADDR, dma->paddr >> 4);
	iwn_prph_write(sc, IWN_BSM_DRAM_DATA_SIZE, fw->main.datasz);
	iwn_prph_write(sc, IWN_BSM_DRAM_TEXT_ADDR,
	    (dma->paddr + IWN4965_FW_DATA_MAXSZ) >> 4);
	iwn_prph_write(sc, IWN_BSM_DRAM_TEXT_SIZE,
	    IWN_FW_UPDATED | fw->main.textsz);
	iwn_nic_unlock(sc);

	return 0;
}

static int
iwn4965_nic_config(struct iwn_softc *sc)
{
	DPRINTF(sc, IWN_DEBUG_TRACE, "->Doing %s\n", __func__);

	if (IWN_RFCFG_TYPE(sc->rfcfg) == 1) {
		/*
		 * I don't believe this to be correct but this is what the
		 * vendor driver is doing. Probably the bits should not be
		 * shifted in IWN_RFCFG_*.
		 */
		IWN_SETBITS(sc, IWN_HW_IF_CONFIG,
		    IWN_RFCFG_TYPE(sc->rfcfg) |
		    IWN_RFCFG_STEP(sc->rfcfg) |
		    IWN_RFCFG_DASH(sc->rfcfg));
	}
	IWN_SETBITS(sc, IWN_HW_IF_CONFIG,
	    IWN_HW_IF_CONFIG_RADIO_SI | IWN_HW_IF_CONFIG_MAC_SI);
	return 0;
}

