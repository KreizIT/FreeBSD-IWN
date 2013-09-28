/*-
 * Copyright (c) 2013 Cedric GROSS <cg@cgross.info>
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
 *
 * $FreeBSD$
 */

#ifndef	__IF_IWN_PAN_H__
#define	__IF_IWN_PAN_H__
/*
 * ADD / MODIFY STATION Command (Op Code 18) -  byte 76-18 -bit13
 * STA_FLAG_PAN_STATION bit:
 * This bit is set (1) for a station in PAN mode
 */
#define IWN_STA_FLAG_PAN_STATION		(1 << 13)

#define IWN_BEACON_INTERVAL_DEFAULT		200
#define IWN_SLOT_TIME_MIN		20

extern	int iwn_newstate_pan(struct ieee80211vap *, enum ieee80211_state,
    int);
extern	int iwn_set_pan_params(struct iwn_softc *);

#endif
