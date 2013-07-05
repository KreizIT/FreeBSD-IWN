/*	$FreeBSD$	*/

/*-
 * Copyright (c) 2013
 *	Cedric GROSS <cg@cgross.info>
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
 
 /* Define several specific values for Intel 2000 series */
 /* Get value from linux kernel 3.2.+ in Drivers/net/wireless/iwlwifi/iwl-2000.c*/
static const struct iwn_sensitivity_limits iwn2030_sensitivity_limits = {
    105,110,
    128,232,
	80,145,
	128,232,
	125,175,
	160,310,
	97,
	97,
	110
};
/* 2x00 Specific */
#define EEPROM_2000_TX_POWER_VERSION    (6)
#define EEPROM_2000_EEPROM_VERSION	(0x805)

/* OTP */
#define OTP_MAX_LL_ITEMS_2x00		(4)	/* OTP blocks for 2x00 */

#define IWL_MAX_PLCP_ERR_THRESHOLD_DEF	(50)

#define IWL_LONG_WD_TIMEOUT	(10000)


static struct iwn_base_params iwn2030_base_params = {
	/* eeprom_size */ OTP_LOW_IMAGE_SIZE, 
	/* pll_cfg_val */ 0, 
	/*.max_ll_items */ OTP_MAX_LL_ITEMS_2x00, 
	/*.shadow_ram_support*/  true, 
	/*.led_compensation = */ 57,
	/*.adv_thermal_throttle = */ true,
	/*.support_ct_kill_exit = */ true,
	/*.plcp_delta_threshold = */ IWL_MAX_PLCP_ERR_THRESHOLD_DEF,
	/*.chain_noise_scale = */ 1000,
	/*.wd_timeout = */ IWL_LONG_WD_TIMEOUT,
	/*.max_event_log_size = */ 512,
	/*.shadow_reg_enable = */ false, 
	/*.hd_v2 = */ true,
};
