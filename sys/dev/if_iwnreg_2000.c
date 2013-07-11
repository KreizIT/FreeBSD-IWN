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
/* Device ID for 2x30 series */
#define IWN_DID_2x30_1 	0x0887 
#define IWN_DID_2x30_2 	0x0888 
/* SubDevice ID */
#define IWN_SDID_2x30_1		0x4062 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_2 	0x4262 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_3 	0x4462 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_4		0x4066 // "2000 Series 2x2 BG/BT"
#define IWN_SDID_2x30_5		0x4266 // "2000 Series 2x2 BG/BT"
#define IWN_SDID_2x30_6 	0x4466 // "2000 Series 2x2 BG/BT"
 
/* #define IWL_DEVICE_2030						\
	.fw_name_pre = IWL2030_FW_PRE,				\
	.ucode_api_max = IWL2030_UCODE_API_MAX,			\
	.ucode_api_ok = IWL2030_UCODE_API_OK,			\
	.ucode_api_min = IWL2030_UCODE_API_MIN,			\
	.eeprom_ver = EEPROM_2000_EEPROM_VERSION,		\
	.eeprom_calib_ver = EEPROM_2000_TX_POWER_VERSION,	\
	.lib = &iwl2030_lib,					\
	.base_params = &iwl2030_base_params,			\
	.bt_params = &iwl2030_bt_params,			\
	.need_dc_calib = true,					\
	.need_temp_offset_calib = true,				\
	.temp_offset_v2 = true,					\
	.led_mode = IWL_LED_RF_STATE,				\
	.adv_pm = true,						\
	.iq_invert = true					\

static struct iwl_ht_params iwl2000_ht_params = {
	.ht_greenfield_support = true,
	.use_rts_for_aggregation = true, // use rts/cts protection 
};	
	
struct iwl_cfg iwl2030_2bgn_cfg = {
	.name = "2000 Series 2x2 BGN/BT",
	IWL_DEVICE_2030,
	.ht_params = &iwl2000_ht_params,
};

struct iwl_cfg iwl2030_2bg_cfg = {
	.name = "2000 Series 2x2 BG/BT",
	IWL_DEVICE_2030,
};
static struct iwl_bt_params iwl2030_bt_params = {
	// Due to bluetooth, we transmit 2.4 GHz probes only on antenna A 
	.advanced_bt_coexist = true,
	.agg_time_limit = BT_AGG_THRESHOLD_DEF,
	.bt_init_traffic_load = IWL_BT_COEX_TRAFFIC_LOAD_NONE,
	.bt_prio_boost = IWLAGN_BT_PRIO_BOOST_DEFAULT,
	.bt_sco_disable = true,
	.bt_session_2 = true,

};

*/

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
#define IWN_OTP_MAX_LL_ITEMS_2x00		(4)	/* OTP blocks for 2x00 */

#define IWN_MAX_PLCP_ERR_THRESHOLD_DEF	(50)

#define IWN_LONG_WD_TIMEOUT	(10000)

static const uint32_t iwn2030_regulatory_bands[IWN_NBANDS] = {
	IWN5000_EEPROM_BAND1,
	IWN5000_EEPROM_BAND2,
	IWN5000_EEPROM_BAND3,
	IWN5000_EEPROM_BAND4,
	IWN5000_EEPROM_BAND5,
	IWN6000_EEPROM_BAND6,
	IWN5000_EEPROM_BAND7
};


static struct iwn_base_params iwn2030_base_params = {
	/* eeprom_size */ OTP_LOW_IMAGE_SIZE, 
	/* pll_cfg_val */ 0, 
	/*.max_ll_items */ IWN_OTP_MAX_LL_ITEMS_2x00, 
	/*.shadow_ram_support*/  true, 
	/*.led_compensation = */ 57,
	/*.adv_thermal_throttle = */ true,
	/*.support_ct_kill_exit = */ true,
	/*.plcp_delta_threshold = */ IWN_MAX_PLCP_ERR_THRESHOLD_DEF,
	/*.chain_noise_scale = */ 1000,
	/*.wd_timeout = */ IWN_LONG_WD_TIMEOUT,
	/*.max_event_log_size = */ 512,
	/*.shadow_reg_enable = */ false, 
	/*.hd_v2 = */ true,
	/* advanced_bt_coexist */ true,
	/* bt_session_2 */ true,
	/* bt_sco_disable */ true,
	/* additional_nic_config */ false,
	/* iq_invert */ true,
	/* regulatory_bands */ iwn2030_regulatory_bands,
	/* enhanced_TX_power */ true, 
	/* need_temp_offset_calib */ true,
	/* calib_need */ (IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //| IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSETv2 ),
	/* running_post_alive_calib */ true,

};
