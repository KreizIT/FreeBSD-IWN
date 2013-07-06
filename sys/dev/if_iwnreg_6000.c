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
 
 /* Define several specific values for Intel 6000 series */
 static const struct iwn_sensitivity_limits iwn6000_sensitivity_limits = {
	105, 110,
	192, 232,
	 80, 145,
	128, 232,
	125, 175,
	160, 310,
	 97,
	 97,
	100
};
/* 6x00 Specific */
#define EEPROM_6000_TX_POWER_VERSION    (4)
#define EEPROM_6000_EEPROM_VERSION	(0x423)

/* 6x50 Specific */
#define EEPROM_6050_TX_POWER_VERSION    (4)
#define EEPROM_6050_EEPROM_VERSION	(0x532)

/* 6150 Specific */
#define EEPROM_6150_TX_POWER_VERSION    (6)
#define EEPROM_6150_EEPROM_VERSION	(0x553)

/* 6x05 Specific */
#define EEPROM_6005_TX_POWER_VERSION    (6)
#define EEPROM_6005_EEPROM_VERSION	(0x709)

/* 6x30 Specific */
#define EEPROM_6030_TX_POWER_VERSION    (6)
#define EEPROM_6030_EEPROM_VERSION	(0x709)

/* 6x35 Specific */
#define EEPROM_6035_TX_POWER_VERSION    (6)
#define EEPROM_6035_EEPROM_VERSION	(0x753)



/* OTP */
#define OTP_MAX_LL_ITEMS_6x00		(4)	/* OTP blocks for 6x00 */
#define OTP_MAX_LL_ITEMS_6x50		(7)	/* OTP blocks for 6x50 */


#define IWL_MAX_PLCP_ERR_THRESHOLD_DEF	(50)

#define IWL_LONG_WD_TIMEOUT	(10000)
/*static struct iwl_bt_params iwl6000_bt_params = {
	 Due to bluetooth, we transmit 2.4 GHz probes only on antenna A 
	.advanced_bt_coexist = true,
	.agg_time_limit = BT_AGG_THRESHOLD_DEF,
	.bt_init_traffic_load = IWL_BT_COEX_TRAFFIC_LOAD_NONE,
	.bt_prio_boost = IWLAGN_BT_PRIO_BOOST_DEFAULT,
	.bt_sco_disable = true,
};
*/


// static struct iwn_base_params iwn6005_base_params = {
	// /* eeprom_size */ OTP_LOW_IMAGE_SIZE, 
	// /* pll_cfg_val */ 0, 
	// /*.max_ll_items */ OTP_MAX_LL_ITEMS_6x00, 
	// /*.shadow_ram_support*/  true, 
	// /*.led_compensation = */ 51,
	// /*.adv_thermal_throttle = */ true,
	// /*.support_ct_kill_exit = */ true,
	// /*.plcp_delta_threshold = */ IWL_MAX_PLCP_ERR_THRESHOLD_DEF,
	// /*.chain_noise_scale = */ 1000,
	// /*.wd_timeout = */ IWL_LONG_WD_TIMEOUT,
	// /*.max_event_log_size = */ 512,
	// /*.shadow_reg_enable = */ false, 
	// /*.hd_v2 = */ false,
	// /* advanced_bt_coexist */ true,
// };

/*#define IWL_DEVICE_6030						\
	.fw_name_pre = IWL6030_FW_PRE,				\
	.ucode_api_max = IWL6000G2_UCODE_API_MAX,		\
	.ucode_api_ok = IWL6000G2B_UCODE_API_OK,		\
	.ucode_api_min = IWL6000G2_UCODE_API_MIN,		\
	.eeprom_ver = EEPROM_6030_EEPROM_VERSION,		\
	.eeprom_calib_ver = EEPROM_6030_TX_POWER_VERSION,	\
	.lib = &iwl6030_lib,					\
	.base_params = &iwl6000_g2_base_params,			\
	.bt_params = &iwl6000_bt_params,			\
	.need_dc_calib = true,					\
	.need_temp_offset_calib = true,				\
	.led_mode = IWL_LED_RF_STATE,				\
	.adv_pm = true						\
	
#define IWL_DEVICE_6035						\
	.fw_name_pre = IWL6030_FW_PRE,				\
	.ucode_api_max = IWL6035_UCODE_API_MAX,			\
	.ucode_api_ok = IWL6035_UCODE_API_OK,			\
	.ucode_api_min = IWL6035_UCODE_API_MIN,			\
	.eeprom_ver = EEPROM_6030_EEPROM_VERSION,		\
	.eeprom_calib_ver = EEPROM_6030_TX_POWER_VERSION,	\
	.lib = &iwl6030_lib,					\
	.base_params = &iwl6000_g2_base_params,			\
	.bt_params = &iwl6000_bt_params,			\
	.need_dc_calib = true,					\
	.need_temp_offset_calib = true,				\
	.led_mode = IWL_LED_RF_STATE,				\
	.adv_pm = true
*/


