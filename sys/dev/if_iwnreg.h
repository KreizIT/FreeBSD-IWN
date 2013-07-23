/*	$FreeBSD$	*/
/*	$OpenBSD: if_iwnreg.h,v 1.40 2010/05/05 19:41:57 damien Exp $	*/

/*-
 * Copyright (c) 2013 Cedric GROSS <c.gross@kreiz-it.fr>
 * Copyright (c) 2011 Intel Corporation
 * Copyright (c) 2007, 2008
 *	Damien Bergamini <damien.bergamini@free.fr>
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
 
#define IWN_CT_KILL_THRESHOLD              114             /* in Celsius */
#define IWN_CT_KILL_EXIT_THRESHOLD         95              /* in Celsius */

 
/* ============================================================================
 *							DEVICE ID BLOCK
 * ============================================================================ 
*/ 
/*
 * -----------------------------------------------------------------------------
 * Device ID for 2x30 series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_2x30_1 	0x0887 
#define IWN_DID_2x30_2 	0x0888 
/* SubDevice ID */
#define IWN_SDID_2x30_1		0x4062 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_2 	0x4262 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_3 	0x4462 // "2000 Series 2x2 BGN/BT"
#define IWN_SDID_2x30_4		0x4066 // "2000 Series 2x2 BG/BT"
#define IWN_SDID_2x30_5		0x4266 // "2000 Series 2x2 BG/BT"
#define IWN_SDID_2x30_6 	0x4466 // "2000 Series 2x2 BG/BT"
 
/*
 * -----------------------------------------------------------------------------
 * Device ID for 1000 series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_1000_1 0x0083
#define IWN_DID_1000_2 0x0084

/* SubDevice ID */
#define IWN_SDID_1000_1 0x1205 // iwl1000_bgn_cfg
#define IWN_SDID_1000_2 0x1305 //  iwl1000_bgn_cfg
#define IWN_SDID_1000_3 0x1225 //  iwl1000_bgn_cfg
#define IWN_SDID_1000_4 0x1325 //  iwl1000_bgn_cfg
#define IWN_SDID_1000_5 0x1215 //  iwl1000_bgn_cfg
#define IWN_SDID_1000_6 0x1315 //  iwl1000_bgn_cfg

#define IWN_SDID_1000_7 0x1206 // 	iwl1000_bg_cfg
#define IWN_SDID_1000_8 0x1306 //  iwl1000_bg_cfg
#define IWN_SDID_1000_9 0x1226 //  iwl1000_bg_cfg
#define IWN_SDID_1000_10 0x1326 //  iwl1000_bg_cfg
#define IWN_SDID_1000_11 0x1216 //  iwl1000_bg_cfg
#define IWN_SDID_1000_12 0x1316 //  iwl1000_bg_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 6x00 series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_6x00_1	0x422B
#define IWN_DID_6x00_2  0x422C
#define IWN_DID_6x00_3	0x4238
#define IWN_DID_6x00_4	0x4239
/* SubDevice ID */
#define IWN_SDID_6x00_1 0x1101 //  iwl6000_3agn_cfg
#define IWN_SDID_6x00_2 0x1121 //  iwl6000_3agn_cfg
#define IWN_SDID_6x00_3 0x1301 //  iwl6000i_2agn_cfg
#define IWN_SDID_6x00_4 0x1306 //  iwl6000i_2abg_cfg
#define IWN_SDID_6x00_5 0x1307 //  iwl6000i_2bg_cfg
#define IWN_SDID_6x00_6 0x1321 //  iwl6000i_2agn_cfg
#define IWN_SDID_6x00_7 0x1326 //  iwl6000i_2abg_cfg
#define IWN_SDID_6x00_8 0x1111 //  iwl6000_3agn_cfg
#define IWN_SDID_6x00_9 0x1311 //  iwl6000i_2agn_cfg
#define IWN_SDID_6x00_10 0x1316 //  iwl6000i_2abg_cfg
/*
 * -----------------------------------------------------------------------------
 * Device ID for 6x05 series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_6x05_1	0x0082
#define IWN_DID_6x05_2 	0x0085
/* SubDevice ID */
#define IWN_SDID_6x05_1 	0x1301 //iwl6005_2agn_cfg
#define IWN_SDID_6x05_2 	0x1306 //iwl6005_2abg_cfg
#define IWN_SDID_6x05_3 	0x1307 //iwl6005_2bg_cfg
#define IWN_SDID_6x05_4 	0x1321 //iwl6005_2agn_cfg
#define IWN_SDID_6x05_5 	0x1326 //iwl6005_2abg_cfg
#define IWN_SDID_6x05_6 	0x1311 //iwl6005_2agn_cfg
#define IWN_SDID_6x05_7 	0x1316 //iwl6005_2abg_cfg
#define IWN_SDID_6x05_8 	0xC020 //iwl6005_2agn_sff_cfg
#define IWN_SDID_6x05_9 	0xC220 //iwl6005_2agn_sff_cfg
#define IWN_SDID_6x05_10 	0x4820 //iwl6005_2agn_d_cfg
#define IWN_SDID_6x05_11 	0x1304 //iwl6005_2agn_mow1_cfg/* low 5GHz active */
#define IWN_SDID_6x05_12 	0x1305 //iwl6005_2agn_mow2_cfg/* high 5GHz active */

/*
 * -----------------------------------------------------------------------------
 * Device ID for 6050 WiFi/WiMax Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_6050_1 0x0087
#define IWN_DID_6050_2 0x0089

#define IWN_SDID_6050_1 0x1301 //iwl6050_2agn_cfg
#define IWN_SDID_6050_2 0x1306 //iwl6050_2abg_cfg
#define IWN_SDID_6050_3 0x1321 //iwl6050_2agn_cfg
#define IWN_SDID_6050_4 0x1326 //iwl6050_2abg_cfg
#define IWN_SDID_6050_5 0x1311 //iwl6050_2agn_cfg
#define IWN_SDID_6050_6 0x1316 //iwl6050_2abg_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 6150 Series 
 * -----------------------------------------------------------------------------
 */

#define IWN_DID_6150_1 	0x0885 
#define IWN_DID_6150_2 	0x0886

#define IWN_SDID_6150_1	0x1305 // iwl6150_bgn_cfg
#define IWN_SDID_6150_2	0x1307 // iwl6150_bg_cfg)
#define IWN_SDID_6150_3	0x1325 // iwl6150_bgn_cfg
#define IWN_SDID_6150_4	0x1327 // iwl6150_bg_cfg)
#define IWN_SDID_6150_5	0x1315 // iwl6150_bgn_cfg
#define IWN_SDID_6150_6	0x1317 // iwl6150_bg_cfg) 
 
/*
 * -----------------------------------------------------------------------------
 * Device ID for 6035 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_6035_1 	0x088E
#define IWN_DID_6035_2 	0x088F
 
#define IWN_SDID_6035_1 0x4060 // iwl6035_2agn_cfg
#define IWN_SDID_6035_2 0x4260 // iwl6035_2agn_cfg
#define IWN_SDID_6035_3 0x4460 // iwl6035_2agn_cfg
#define IWN_SDID_6035_4 0x4860 // iwl6035_2agn_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 1030 and 6030 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_x030_1 		0x008A 
#define IWN_DID_x030_2 		0x008B
#define IWN_DID_x030_3 		0x0090
#define IWN_DID_x030_4 		0x0091

#define IWN_SDID_x030_1 	0x5305 // iwl1030_bgn_cfg
#define IWN_SDID_x030_2 	0x5307 // iwl1030_bg_cfg
#define IWN_SDID_x030_3 	0x5325 // iwl1030_bgn_cfg
#define IWN_SDID_x030_4 	0x5327 // iwl1030_bg_cfg
#define IWN_SDID_x030_5 	0x5315 // iwl1030_bgn_cfg
#define IWN_SDID_x030_6 	0x5317 // iwl1030_bg_cfg
#define IWN_SDID_x030_7 	0x5211 // iwl6030_2agn_cfg
#define IWN_SDID_x030_8 	0x5215 // iwl6030_2bgn_cfg
#define IWN_SDID_x030_9 	0x5216 // iwl6030_2abg_cfg
#define IWN_SDID_x030_10 	0x5201 // iwl6030_2agn_cfg
#define IWN_SDID_x030_11 	0x5205 // iwl6030_2bgn_cfg
#define IWN_SDID_x030_12 	0x5206 // iwl6030_2abg_cfg
#define IWN_SDID_x030_13 	0x5207 // iwl6030_2bg_cfg)
#define IWN_SDID_x030_14 	0x5221 // iwl6030_2agn_cfg
#define IWN_SDID_x030_15 	0x5225 // iwl6030_2bgn_cfg
#define IWN_SDID_x030_16 	0x5226 // iwl6030_2abg_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 130 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_130_1 		0x0896
#define IWN_DID_130_2 		0x0897

#define IWN_SDID_130_1 		0x5005 //iwl130_bgn_cfg
#define IWN_SDID_130_2 		0x5007 //iwl130_bg_cfg
#define IWN_SDID_130_3 		0x5015 //iwl130_bgn_cfg
#define IWN_SDID_130_4 		0x5017 //iwl130_bg_cfg
#define IWN_SDID_130_5 		0x5025 //iwl130_bgn_cfg
#define IWN_SDID_130_6 		0x5027 //iwl130_bg_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 100 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_100_1 		0x08AE
#define IWN_DID_100_2 		0x08AF

#define IWN_SDID_100_1 		0x1005 //iwl100_bgn_cfg)
#define IWN_SDID_100_2 		0x1007 //iwl100_bg_cfg)}
#define IWN_SDID_100_3 		0x1015 //iwl100_bgn_cfg)
#define IWN_SDID_100_4 		0x1017 //iwl100_bg_cfg)}
#define IWN_SDID_100_5 		0x1025 //iwl100_bgn_cfg)
#define IWN_SDID_100_6 		0x1027 //iwl100_bg_cfg)}

/*
 * -----------------------------------------------------------------------------
 * Device ID for 5x00 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_5x00_1 		0x4232
#define IWN_DID_5x00_2 		0x4237
#define IWN_DID_5x00_3 		0x4235
#define IWN_DID_5x00_4 		0x4236

#define IWN_SDID_5x00_1 		0x1201 //iwl5100_agn_cfg
#define IWN_SDID_5x00_2 		0x1301 //iwl5100_agn_cfg
#define IWN_SDID_5x00_3 		0x1204 //iwl5100_agn_cfg
#define IWN_SDID_5x00_4 		0x1304 //iwl5100_agn_cfg
#define IWN_SDID_5x00_5 		0x1205 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_6 		0x1305 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_7 		0x1206 //iwl5100_abg_cfg
#define IWN_SDID_5x00_8 		0x1306 //iwl5100_abg_cfg
#define IWN_SDID_5x00_9 		0x1221 //iwl5100_agn_cfg
#define IWN_SDID_5x00_10 		0x1321 //iwl5100_agn_cfg
#define IWN_SDID_5x00_11		0x1224 //iwl5100_agn_cfg
#define IWN_SDID_5x00_12 		0x1324 //iwl5100_agn_cfg
#define IWN_SDID_5x00_13 		0x1225 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_14 		0x1325 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_15 		0x1226 //iwl5100_abg_cfg
#define IWN_SDID_5x00_16 		0x1326 //iwl5100_abg_cfg
#define IWN_SDID_5x00_17 		0x1211 //iwl5100_agn_cfg
#define IWN_SDID_5x00_18 		0x1311 //iwl5100_agn_cfg
#define IWN_SDID_5x00_19 		0x1214 //iwl5100_agn_cfg
#define IWN_SDID_5x00_20 		0x1314 //iwl5100_agn_cfg
#define IWN_SDID_5x00_21 		0x1215 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_22 		0x1315 //iwl5100_bgn_cfg
#define IWN_SDID_5x00_23 		0x1216 //iwl5100_abg_cfg
#define IWN_SDID_5x00_24 		0x1316 //iwl5100_abg_cfg
#define IWN_SDID_5x00_25 		0x1021 //iwl5300_agn_cfg
#define IWN_SDID_5x00_26 		0x1121 //iwl5300_agn_cfg
#define IWN_SDID_5x00_27 		0x1024 //iwl5300_agn_cfg
#define IWN_SDID_5x00_28 		0x1124 //iwl5300_agn_cfg
#define IWN_SDID_5x00_29 		0x1001 //iwl5300_agn_cfg
#define IWN_SDID_5x00_30 		0x1101 //iwl5300_agn_cfg
#define IWN_SDID_5x00_31 		0x1004 //iwl5300_agn_cfg
#define IWN_SDID_5x00_32 		0x1104 //iwl5300_agn_cfg
#define IWN_SDID_5x00_33 		0x1011 //iwl5300_agn_cfg
#define IWN_SDID_5x00_34 		0x1111 //iwl5300_agn_cfg
#define IWN_SDID_5x00_35 		0x1014 //iwl5300_agn_cfg
#define IWN_SDID_5x00_36 		0x1114 //iwl5300_agn_cfg

/*
 * -----------------------------------------------------------------------------
 * Device ID for 5x50 Series 
 * -----------------------------------------------------------------------------
 */
#define IWN_DID_5x50_1			0x423A
#define IWN_DID_5x50_2			0x423B
#define IWN_DID_5x50_3			0x423C
#define IWN_DID_5x50_4			0x423D

#define IWN_SDID_5x50_1 		0x1001 //iwl5350_agn_cfg
#define IWN_SDID_5x50_2 		0x1021 //iwl5350_agn_cfg
#define IWN_SDID_5x50_3 		0x1011 //iwl5350_agn_cfg
#define IWN_SDID_5x50_4 		0x1201 //iwl5150_agn_cfg
#define IWN_SDID_5x50_5 		0x1301 //iwl5150_agn_cfg
#define IWN_SDID_5x50_6 		0x1206 //iwl5150_abg_cfg
#define IWN_SDID_5x50_7 		0x1306 //iwl5150_abg_cfg
#define IWN_SDID_5x50_8 		0x1221 //iwl5150_agn_cfg
#define IWN_SDID_5x50_9 		0x1321 //iwl5150_agn_cfg
#define IWN_SDID_5x50_10 		0x1211 //iwl5150_agn_cfg
#define IWN_SDID_5x50_11 		0x1311 //iwl5150_agn_cfg
#define IWN_SDID_5x50_12 		0x1216 //iwl5150_abg_cfg
#define IWN_SDID_5x50_13 		0x1316 //iwl5150_abg_cfg


#define IWN_TX_RING_COUNT	256
#define IWN_TX_RING_LOMARK	192
#define IWN_TX_RING_HIMARK	224
#define IWN_RX_RING_COUNT_LOG	6
#define IWN_RX_RING_COUNT	(1 << IWN_RX_RING_COUNT_LOG)

#define IWN4965_NTXQUEUES	16
#define IWN5000_NTXQUEUES	20

#define IWN4965_FIRSTAGGQUEUE	7
#define IWN5000_FIRSTAGGQUEUE	10

#define IWN4965_NDMACHNLS	7
#define IWN5000_NDMACHNLS	8

#define IWN_SRVC_DMACHNL	9

#define IWN_ICT_SIZE		4096
#define IWN_ICT_COUNT		(IWN_ICT_SIZE / sizeof (uint32_t))

/* For cards with PAN command default is IWN_CMD_QUEUE_NUM */
#define	IWN_CMD_QUEUE_NUM		4
#define	IWN_PAN_CMD_QUEUE		9


/* Maximum number of DMA segments for TX. */
#define IWN_MAX_SCATTER	20

/* RX buffers must be large enough to hold a full 4K A-MPDU. */
#define IWN_RBUF_SIZE	(4 * 1024)

#if defined(__LP64__)
/* HW supports 36-bit DMA addresses. */
#define IWN_LOADDR(paddr)	((uint32_t)(paddr))
#define IWN_HIADDR(paddr)	(((paddr) >> 32) & 0xf)
#else
#define IWN_LOADDR(paddr)	(paddr)
#define IWN_HIADDR(paddr)	(0)
#endif

/*
 * Control and status registers.
 */
#define IWN_HW_IF_CONFIG	0x000
#define IWN_INT_COALESCING	0x004
#define IWN_INT_PERIODIC	0x005	/* use IWN_WRITE_1 */
#define IWN_INT			0x008
#define IWN_INT_MASK		0x00c
#define IWN_FH_INT		0x010
#define IWN_GPIO_IN			0x018 /* read external chip pins */
#define IWN_RESET		0x020
#define IWN_GP_CNTRL		0x024
#define IWN_HW_REV		0x028
#define IWN_EEPROM		0x02c
#define IWN_EEPROM_GP		0x030
#define IWN_OTP_GP		0x034
#define IWN_GIO			0x03c
#define IWN_GP_UCODE	0x048 
#define IWN_GP_DRIVER		0x050
#define IWN_UCODE_GP1		0x054
#define IWN_UCODE_GP1_SET   0x058
#define IWN_UCODE_GP1_CLR	0x05c
#define IWN_UCODE_GP2   	0x060 
#define IWN_LED			0x094
#define IWN_DRAM_INT_TBL	0x0a0
#define IWN_SHADOW_REG_CTRL	0x0a8
#define IWN_GIO_CHICKEN		0x100
#define IWN_ANA_PLL		0x20c
#define IWN_HW_REV_WA		0x22c
#define IWN_DBG_HPET_MEM	0x240
#define IWN_DBG_LINK_PWR_MGMT	0x250
// Need nic_lock for use above
#define IWN_MEM_RADDR		0x40c
#define IWN_MEM_WADDR		0x410
#define IWN_MEM_WDATA		0x418
#define IWN_MEM_RDATA		0x41c
#define IWN_TARG_MBX_C		0x430
#define IWN_PRPH_WADDR  	0x444
#define IWN_PRPH_RADDR   	0x448
#define IWN_PRPH_WDATA  	0x44c
#define IWN_PRPH_RDATA   	0x450
#define IWN_HBUS_TARG_WRPTR	0x460

/*
 * Flow-Handler registers.
 */
#define IWN_FH_TFBD_CTRL0(qid)		(0x1900 + (qid) * 8)
#define IWN_FH_TFBD_CTRL1(qid)		(0x1904 + (qid) * 8)
#define IWN_FH_KW_ADDR			0x197c
#define IWN_FH_SRAM_ADDR(qid)		(0x19a4 + (qid) * 4)
#define IWN_FH_CBBC_QUEUE(qid)		(0x19d0 + (qid) * 4)
#define IWN_FH_STATUS_WPTR		0x1bc0
#define IWN_FH_RX_BASE			0x1bc4
#define IWN_FH_RX_WPTR			0x1bc8
#define IWN_FH_RX_CONFIG		0x1c00
#define IWN_FH_RX_STATUS		0x1c44
#define IWN_FH_TX_CONFIG(qid)		(0x1d00 + (qid) * 32)
#define IWN_FH_TXBUF_STATUS(qid)	(0x1d08 + (qid) * 32)
#define IWN_FH_TX_CHICKEN		0x1e98
#define IWN_FH_TX_STATUS		0x1eb0

/*
 * TX scheduler registers.
 */
#define IWN_SCHED_BASE			0xa02c00
#define IWN_SCHED_SRAM_ADDR		(IWN_SCHED_BASE + 0x000)
#define IWN5000_SCHED_DRAM_ADDR		(IWN_SCHED_BASE + 0x008)
#define IWN4965_SCHED_DRAM_ADDR		(IWN_SCHED_BASE + 0x010)
#define IWN5000_SCHED_TXFACT		(IWN_SCHED_BASE + 0x010)
#define IWN4965_SCHED_TXFACT		(IWN_SCHED_BASE + 0x01c)
#define IWN4965_SCHED_QUEUE_RDPTR(qid)	(IWN_SCHED_BASE + 0x064 + (qid) * 4)
#define IWN5000_SCHED_QUEUE_RDPTR(qid)	(IWN_SCHED_BASE + 0x068 + (qid) * 4)
#define IWN4965_SCHED_QCHAIN_SEL	(IWN_SCHED_BASE + 0x0d0)
#define IWN4965_SCHED_INTR_MASK		(IWN_SCHED_BASE + 0x0e4)
#define IWN5000_SCHED_QCHAIN_SEL	(IWN_SCHED_BASE + 0x0e8)
#define IWN4965_SCHED_QUEUE_STATUS(qid)	(IWN_SCHED_BASE + 0x104 + (qid) * 4)
#define IWN5000_SCHED_INTR_MASK		(IWN_SCHED_BASE + 0x108)
#define IWN5000_SCHED_QUEUE_STATUS(qid)	(IWN_SCHED_BASE + 0x10c + (qid) * 4)
#define IWN5000_SCHED_AGGR_SEL		(IWN_SCHED_BASE + 0x248)

/*
 * Offsets in TX scheduler's SRAM.
 */
#define IWN4965_SCHED_CTX_OFF		0x380
#define IWN4965_SCHED_CTX_LEN		416
#define IWN4965_SCHED_QUEUE_OFFSET(qid)	(0x380 + (qid) * 8)
#define IWN4965_SCHED_TRANS_TBL(qid)	(0x500 + (qid) * 2)
#define IWN5000_SCHED_CTX_OFF		0x600
#define IWN5000_SCHED_CTX_LEN		520
#define IWN5000_SCHED_QUEUE_OFFSET(qid)	(0x600 + (qid) * 8)
#define IWN5000_SCHED_TRANS_TBL(qid)	(0x7e0 + (qid) * 2)

/*
 * NIC internal memory offsets.
 */
#define IWN_APMG_CLK_CTRL	0x3000
#define IWN_APMG_CLK_EN		0x3004
#define IWN_APMG_CLK_DIS	0x3008
#define IWN_APMG_PS		0x300c
#define IWN_APMG_DIGITAL_SVR	0x3058
#define IWN_APMG_ANALOG_SVR	0x306c
#define IWN_APMG_PCI_STT	0x3010
#define IWN_BSM_WR_CTRL		0x3400
#define IWN_BSM_WR_MEM_SRC	0x3404
#define IWN_BSM_WR_MEM_DST	0x3408
#define IWN_BSM_WR_DWCOUNT	0x340c
#define IWN_BSM_DRAM_TEXT_ADDR	0x3490
#define IWN_BSM_DRAM_TEXT_SIZE	0x3494
#define IWN_BSM_DRAM_DATA_ADDR	0x3498
#define IWN_BSM_DRAM_DATA_SIZE	0x349c
#define IWN_BSM_SRAM_BASE	0x3800

/* Possible flags for register IWN_HW_IF_CONFIG. */
#define IWN_HW_IF_CONFIG_4965_R		(1 <<  4)
#define IWN_HW_IF_CONFIG_MAC_SI		(1 <<  8)
#define IWN_HW_IF_CONFIG_RADIO_SI	(1 <<  9)
#define IWN_HW_IF_CONFIG_EEPROM_LOCKED	(1 << 21)
#define IWN_HW_IF_CONFIG_NIC_READY	(1 << 22)
#define IWN_HW_IF_CONFIG_HAP_WAKE_L1A	(1 << 23)
#define IWN_HW_IF_CONFIG_PREPARE_DONE	(1 << 25)
#define IWN_HW_IF_CONFIG_PREPARE	(1 << 27)

/* Possible values for register IWN_INT_PERIODIC. */
#define IWN_INT_PERIODIC_DIS	0x00
#define IWN_INT_PERIODIC_ENA	0xff

/* Possible flags for registers IWN_PRPH_RADDR/IWN_PRPH_WADDR. */
#define IWN_PRPH_DWORD	((sizeof (uint32_t) - 1) << 24)

/* Possible values for IWN_BSM_WR_MEM_DST. */
#define IWN_FW_TEXT_BASE	0x00000000
#define IWN_FW_DATA_BASE	0x00800000

/* Possible flags for register IWN_RESET. */
#define IWN_RESET_NEVO			(1 << 0)
#define IWN_RESET_SW			(1 << 7)
#define IWN_RESET_MASTER_DISABLED	(1 << 8)
#define IWN_RESET_STOP_MASTER		(1 << 9)
#define IWN_RESET_LINK_PWR_MGMT_DIS	(1 << 31)

/* Possible flags for register IWN_GP_CNTRL. */
/*
 * GP (general purpose) CONTROL REGISTER
 * Bit fields:
 *    27:  HW_RF_KILL_SW
 *         Indicates state of (platform's) hardware RF-Kill switch
 * 26-24:  POWER_SAVE_TYPE
 *         Indicates current power-saving mode:
 *         000 -- No power saving
 *         001 -- MAC power-down
 *         010 -- PHY (radio) power-down
 *         011 -- Error
 *   9-6:  SYS_CONFIG
 *         Indicates current system configuration, reflecting pins on chip
 *         as forced high/low by device circuit board.
 *     4:  GOING_TO_SLEEP
 *         Indicates MAC is entering a power-saving sleep power-down.
 *         Not a good time to access device-internal resources.
 *     3:  MAC_ACCESS_REQ
 *         Host sets this to request and maintain MAC wakeup, to allow host
 *         access to device-internal resources.  Host must wait for
 *         MAC_CLOCK_READY (and !GOING_TO_SLEEP) before accessing non-CSR
 *         device registers.
 *     2:  INIT_DONE
 *         Host sets this to put device into fully operational D0 power mode.
 *         Host resets this after SW_RESET to put device into low power mode.
 *     0:  MAC_CLOCK_READY
 *         Indicates MAC (ucode processor, etc.) is powered up and can run.
 *         Internal resources are accessible.
 *         NOTE:  This does not indicate that the processor is actually running.
 *         NOTE:  This does not indicate that device has completed
 *                init or post-power-down restore of internal SRAM memory.
 *                Use CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP as indication that
 *                SRAM is restored and uCode is in normal operation mode.
 *                Later devices (5xxx/6xxx/1xxx) use non-volatile SRAM, and
 *                do not need to save/restore it.
 *         NOTE:  After device reset, this bit remains "0" until host sets
 *                INIT_DONE
 */
#define IWN_GP_CNTRL_MAC_ACCESS_ENA	(1 << 0) 		//x00000001
#define IWN_GP_CNTRL_MAC_CLOCK_READY	(1 << 0)
#define IWN_GP_CNTRL_INIT_DONE		(1 << 2)		//x00000004
#define IWN_GP_CNTRL_MAC_ACCESS_REQ	(1 << 3)		//x00000008
#define IWN_GP_CNTRL_SLEEP		(1 << 4)			//x00000010
#define IWN_GP_CNTRL_RFKILL		(1 << 27)			//x08000000

/* Possible flags for register IWN_HW_REV. */
#define IWN_HW_REV_TYPE_SHIFT	4
#define IWN_HW_REV_TYPE_MASK	0x000000f0
#define IWN_HW_REV_TYPE_4965	0
#define IWN_HW_REV_TYPE_5300	2
#define IWN_HW_REV_TYPE_5350	3
#define IWN_HW_REV_TYPE_5150	4
#define IWN_HW_REV_TYPE_5100	5
#define IWN_HW_REV_TYPE_1000	6
#define IWN_HW_REV_TYPE_6000	7
#define IWN_HW_REV_TYPE_6050	8
#define IWN_HW_REV_TYPE_6005	11
#define IWN_HW_REV_TYPE_2230	12

/* Possible flags for register IWN_GIO_CHICKEN. */
#define IWN_GIO_CHICKEN_L1A_NO_L0S_RX	(1 << 23)
#define IWN_GIO_CHICKEN_DIS_L0S_TIMER	(1 << 29)

/* Possible flags for register IWN_GIO. */
#define IWN_GIO_L0S_ENA		(1 << 1)

/* Possible flags for register IWN_GP_DRIVER. */
#define IWN_GP_DRIVER_RADIO_3X3_HYB				(0 << 0)
#define IWN_GP_DRIVER_RADIO_2X2_HYB				(1 << 0)
#define IWN_GP_DRIVER_RADIO_2X2_IPA				(2 << 0)
#define IWN_GP_DRIVER_RADIO_MSK					(0x00000003)
#define IWN_GP_DRIVER_CALIB_VER6				(1 << 2)
#define IWN_GP_DRIVER_6050_1X2					(1 << 3)
#define IWN_GP_DRIVER_REG_BIT_RADIO_IQ_INVERT 	(0x00000080)


/* Possible flags for register IWN_UCODE_GP1_CLR. */
#define IWN_UCODE_GP1_RFKILL		(1 << 1)
#define IWN_UCODE_GP1_CMD_BLOCKED	(1 << 2)
#define IWN_UCODE_GP1_CTEMP_STOP_RF	(1 << 3)
#define IWN_UCODE_GP1_CFG_COMPLETE  (1 << 5)

/* Possible flags/values for register IWN_LED. */
#define IWN_LED_BSM_CTRL	(1 << 5)
#define IWN_LED_OFF		0x00000038
#define IWN_LED_ON		0x00000078

#define	IWN_MAX_BLINK_TBL	10
#define	IWN_LED_STATIC_ON	0
#define	IWN_LED_STATIC_OFF	1
#define	IWN_LED_SLOW_BLINK	2
#define	IWN_LED_INT_BLINK	3
#define	IWN_LED_UNIT		0x1388 /* 5 ms */

static const struct {
	uint16_t tpt;	/* Mb/s */
	uint8_t on_time;
	uint8_t off_time;
} blink_tbl[] =
{
	{300, 5,  5},
	{200, 8,  8},
	{100, 11, 11},
	{70,  13, 13},
	{50,  15, 15},
	{20,  17, 17},
	{10,  19, 19},
	{5,   22, 22},
	{1,   26, 26},
	{0,   33, 33},
	/* SOLID_ON */
};

/* Possible flags for register IWN_DRAM_INT_TBL. */
#define IWN_DRAM_INT_TBL_WRAP_CHECK	(1 << 27)
#define IWN_DRAM_INT_TBL_ENABLE		(1 << 31)

/* Possible values for register IWN_ANA_PLL. */
#define IWN_ANA_PLL_INIT	0x00880300

/* Possible flags for register IWN_FH_RX_STATUS. */
#define	IWN_FH_RX_STATUS_IDLE	(1 << 24)

/* Possible flags for register IWN_BSM_WR_CTRL. */
#define IWN_BSM_WR_CTRL_START_EN	(1 << 30)
#define IWN_BSM_WR_CTRL_START		(1 << 31)

/* Possible flags for register IWN_INT. */
#define IWN_INT_ALIVE		(1 <<  0) // x00000001
#define IWN_INT_WAKEUP		(1 <<  1) // x00000002
#define IWN_INT_SW_RX		(1 <<  3) // x00000008
#define IWN_INT_CT_REACHED	(1 <<  6) // x00000040
#define IWN_INT_RF_TOGGLED	(1 <<  7) // x00000080
#define IWN_INT_SW_ERR		(1 << 25) // x02000000
#define IWN_INT_SCHED		(1 << 26) // x04000000
#define IWN_INT_FH_TX		(1 << 27) // x08000000
#define IWN_INT_RX_PERIODIC	(1 << 28) // x10000000
#define IWN_INT_HW_ERR		(1 << 29) // x20000000
#define IWN_INT_FH_RX		(1 << 31) // x80000000


/* Shortcut. */
#define IWN_INT_MASK_DEF						\
	(IWN_INT_SW_ERR | IWN_INT_HW_ERR | IWN_INT_FH_TX |		\
	 IWN_INT_FH_RX | IWN_INT_ALIVE | IWN_INT_WAKEUP |		\
	 IWN_INT_SW_RX | IWN_INT_CT_REACHED | IWN_INT_RF_TOGGLED)

/* Possible flags for register IWN_FH_INT. */
#define IWN_FH_INT_TX_CHNL(x)	(1 << (x))
#define IWN_FH_INT_RX_CHNL(x)	(1 << ((x) + 16))
#define IWN_FH_INT_HI_PRIOR	(1 << 30)
/* Shortcuts for the above. */
#define IWN_FH_INT_TX							\
	(IWN_FH_INT_TX_CHNL(0) | IWN_FH_INT_TX_CHNL(1))
#define IWN_FH_INT_RX							\
	(IWN_FH_INT_RX_CHNL(0) | IWN_FH_INT_RX_CHNL(1) | IWN_FH_INT_HI_PRIOR)

/* Possible flags/values for register IWN_FH_TX_CONFIG. */
#define IWN_FH_TX_CONFIG_DMA_PAUSE		0
#define IWN_FH_TX_CONFIG_DMA_ENA		(1 << 31)
#define IWN_FH_TX_CONFIG_CIRQ_HOST_ENDTFD	(1 << 20)

/* Possible flags/values for register IWN_FH_TXBUF_STATUS. */
#define IWN_FH_TXBUF_STATUS_TBNUM(x)	((x) << 20)
#define IWN_FH_TXBUF_STATUS_TBIDX(x)	((x) << 12)
#define IWN_FH_TXBUF_STATUS_TFBD_VALID	3

/* Possible flags for register IWN_FH_TX_CHICKEN. */
#define IWN_FH_TX_CHICKEN_SCHED_RETRY	(1 << 1)

/* Possible flags for register IWN_FH_TX_STATUS. */
#define IWN_FH_TX_STATUS_IDLE(chnl)	(1 << ((chnl) + 16))

/* Possible flags for register IWN_FH_RX_CONFIG. */
#define IWN_FH_RX_CONFIG_ENA		(1 << 31)
#define IWN_FH_RX_CONFIG_NRBD(x)	((x) << 20)
#define IWN_FH_RX_CONFIG_RB_SIZE_8K	(1 << 16)
#define IWN_FH_RX_CONFIG_SINGLE_FRAME	(1 << 15)
#define IWN_FH_RX_CONFIG_IRQ_DST_HOST	(1 << 12)
#define IWN_FH_RX_CONFIG_RB_TIMEOUT(x)	((x) << 4)
#define IWN_FH_RX_CONFIG_IGN_RXF_EMPTY	(1 <<  2)

/* Possible flags for register IWN_FH_TX_CONFIG. */
#define IWN_FH_TX_CONFIG_DMA_ENA	(1 << 31)
#define IWN_FH_TX_CONFIG_DMA_CREDIT_ENA	(1 <<  3)

/* Possible flags for register IWN_EEPROM. */
#define IWN_EEPROM_READ_VALID	(1 << 0)
#define IWN_EEPROM_CMD		(1 << 1)

/* Possible flags for register IWN_EEPROM_GP. */
#define IWN_EEPROM_GP_IF_OWNER	0x00000180

/* Possible flags for register IWN_OTP_GP. */
#define IWN_OTP_GP_DEV_SEL_OTP		(1 << 16)
#define IWN_OTP_GP_RELATIVE_ACCESS	(1 << 17)
#define IWN_OTP_GP_ECC_CORR_STTS	(1 << 20)
#define IWN_OTP_GP_ECC_UNCORR_STTS	(1 << 21)

/* Possible flags for register IWN_SCHED_QUEUE_STATUS. */
#define IWN4965_TXQ_STATUS_ACTIVE	0x0007fc01
#define IWN4965_TXQ_STATUS_INACTIVE	0x0007fc00
#define IWN4965_TXQ_STATUS_AGGR_ENA	(1 << 5 | 1 << 8)
#define IWN4965_TXQ_STATUS_CHGACT	(1 << 10)
#define IWN5000_TXQ_STATUS_ACTIVE	0x00ff0018
#define IWN5000_TXQ_STATUS_INACTIVE	0x00ff0010
#define IWN5000_TXQ_STATUS_CHGACT	(1 << 19)

/* Possible flags for registers IWN_APMG_CLK_*. */
#define IWN_APMG_CLK_CTRL_DMA_CLK_RQT	(1 <<  9)
#define IWN_APMG_CLK_CTRL_BSM_CLK_RQT	(1 << 11)

/* Possible flags for register IWN_APMG_PS. */
#define IWN_APMG_PS_EARLY_PWROFF_DIS	(1 << 22)
#define IWN_APMG_PS_PWR_SRC(x)		((x) << 24)
#define IWN_APMG_PS_PWR_SRC_VMAIN	0
#define IWN_APMG_PS_PWR_SRC_VAUX	2
#define IWN_APMG_PS_PWR_SRC_MASK	IWN_APMG_PS_PWR_SRC(3)
#define IWN_APMG_PS_RESET_REQ		(1 << 26)

/* Possible flags for register IWN_APMG_DIGITAL_SVR. */
#define IWN_APMG_DIGITAL_SVR_VOLTAGE(x)		(((x) & 0xf) << 5)
#define IWN_APMG_DIGITAL_SVR_VOLTAGE_MASK	\
	IWN_APMG_DIGITAL_SVR_VOLTAGE(0xf)
#define IWN_APMG_DIGITAL_SVR_VOLTAGE_1_32	\
	IWN_APMG_DIGITAL_SVR_VOLTAGE(3)

/* Possible flags for IWN_APMG_PCI_STT. */
#define IWN_APMG_PCI_STT_L1A_DIS	(1 << 11)

/* Possible flags for register IWN_BSM_DRAM_TEXT_SIZE. */
#define IWN_FW_UPDATED	(1 << 31)

#define IWN_SCHED_WINSZ		64
#define IWN_SCHED_LIMIT		64
#define IWN4965_SCHED_COUNT	512
#define IWN5000_SCHED_COUNT	(IWN_TX_RING_COUNT + IWN_SCHED_WINSZ)
#define IWN4965_SCHEDSZ		(IWN4965_NTXQUEUES * IWN4965_SCHED_COUNT * 2)
#define IWN5000_SCHEDSZ		(IWN5000_NTXQUEUES * IWN5000_SCHED_COUNT * 2)

struct iwn_tx_desc {
	uint8_t		reserved1[3];
	uint8_t		nsegs;
	struct {
		uint32_t	addr;
		uint16_t	len;
	} __packed	segs[IWN_MAX_SCATTER];
	/* Pad to 128 bytes. */
	uint32_t	reserved2;
} __packed;

struct iwn_rx_status {
	uint16_t	closed_count;
	uint16_t	closed_rx_count;
	uint16_t	finished_count;
	uint16_t	finished_rx_count;
	uint32_t	reserved[2];
} __packed;

struct iwn_rx_desc {
	uint32_t	len;
	uint8_t		type;
#define IWN_UC_READY			  1
#define IWN_ADD_NODE_DONE		 24
#define IWN_TX_DONE			 28
#define IWN5000_CALIBRATION_RESULT	102
#define IWN5000_CALIBRATION_DONE	103
#define IWN_START_SCAN			130
#define IWN_STOP_SCAN			132
#define IWN_RX_STATISTICS		156
#define IWN_BEACON_STATISTICS		157
#define IWN_STATE_CHANGED		161
#define IWN_BEACON_MISSED		162
#define IWN_RX_PHY			192
#define IWN_MPDU_RX_DONE		193
#define IWN_RX_DONE			195
#define IWN_RX_COMPRESSED_BA		197

	uint8_t		flags;
	uint8_t		idx;
	uint8_t		qid;
} __packed;

/* CARD_STATE_NOTIFICATION */ 
#define IWN_STATE_CHANGE_HW_CARD_DISABLED               0x01
#define IWN_STATE_CHANGE_SW_CARD_DISABLED               0x02
#define IWN_STATE_CHANGE_CT_CARD_DISABLED               0x04
#define IWN_STATE_CHANGE_RXON_CARD_DISABLED             0x10

/* Possible RX status flags. */
#define IWN_RX_NO_CRC_ERR	(1 <<  0)
#define IWN_RX_NO_OVFL_ERR	(1 <<  1)
/* Shortcut for the above. */
#define IWN_RX_NOERROR	(IWN_RX_NO_CRC_ERR | IWN_RX_NO_OVFL_ERR)
#define IWN_RX_MPDU_MIC_OK	(1 <<  6)
#define IWN_RX_CIPHER_MASK	(7 <<  8)
#define IWN_RX_CIPHER_CCMP	(2 <<  8)
#define IWN_RX_MPDU_DEC		(1 << 11)
#define IWN_RX_DECRYPT_MASK	(3 << 11)
#define IWN_RX_DECRYPT_OK	(3 << 11)

struct iwn_tx_cmd {
	uint8_t	code;
#define IWN_CMD_RXON			 16
#define IWN_CMD_RXON_ASSOC		 17
#define IWN_CMD_EDCA_PARAMS		 19
#define IWN_CMD_TIMING			 20
#define IWN_CMD_ADD_NODE		 24
#define IWN_CMD_TX_DATA			 28
#define IWN_CMD_LINK_QUALITY		 78
#define IWN_CMD_SET_LED			 72
#define IWN5000_CMD_WIMAX_COEX		 90
#define IWN_TEMP_NOTIFICATION		98
#define IWN5000_CMD_CALIB_CONFIG	101 // CALIBRATION_CFG_CMD
#define IWN5000_CMD_CALIB_RESULT	102
#define IWN5000_CMD_CALIB_COMPLETE	103
#define IWN_CMD_SET_POWER_MODE		119
#define IWN_CMD_SCAN			128
#define IWN_CMD_SCAN_RESULTS		131
#define IWN_CMD_TXPOWER_DBM		149
#define IWN_CMD_TXPOWER			151
#define IWN5000_CMD_TX_ANT_CONFIG	152
#define IWN_CMD_BT_COEX			155
#define IWN_CMD_GET_STATISTICS		156
#define IWN_CMD_SET_CRITICAL_TEMP	164
#define IWN_CMD_SET_SENSITIVITY		168
#define IWN_CMD_PHY_CALIB		    176
#define IWN_CMD_BT_COEX_PRIOTABLE	204
#define IWN_CMD_BT_COEX_PROT		205
/* PAN commands */
#define IWN_CMD_WIPAN_PARAMS			0xb2
#define IWN_CMD_WIPAN_RXON			0xb3
#define IWN_CMD_WIPAN_RXON_TIMING		0xb4
#define IWN_CMD_WIPAN_RXON_ASSOC		0xb6
#define IWN_CMD_WIPAN_QOS_PARAM			0xb7
#define IWN_CMD_WIPAN_WEPKEY			0xb8
#define IWN_CMD_WIPAN_P2P_CHANNEL_SWITCH	0xb9
#define IWN_CMD_WIPAN_NOA_NOTIFICATION		0xbc
#define IWN_CMD_WIPAN_DEACTIVATION_COMPLETE	0xbd

	uint8_t	flags;
	uint8_t	idx;
	uint8_t	qid;
	uint8_t	data[136];
} __packed;

/*
 * Structure for IWN_CMD_GET_STATISTICS = (0x9c) 156
 * all devices identical.
 *
 * This command triggers an immediate response containing uCode statistics.
 * The response is in the same format as IWN_BEACON_STATISTICS (0x9d) 157.
 *
 * If the CLEAR_STATS configuration flag is set, uCode will clear its
 * internal copy of the statistics (counters) after issuing the response.
 * This flag does not affect IWN_BEACON_STATISTICS after beacons (see below).
 *
 * If the DISABLE_NOTIF configuration flag is set, uCode will not issue
 * IWN_BEACON_STATISTICS after received beacons.  This flag
 * does not affect the response to the IWN_CMD_GET_STATISTICS 0x9c itself.
 */
struct iwn_statistics_cmd {
	uint32_t configuration_flags;	/* IWN_STATS_CONF_* */
#define IWN_STATS_CONF_CLEAR_STATS htole32(0x1)	
#define IWN_STATS_CONF_DISABLE_NOTIF htole32(0x2)

} __packed;

/* Antenna flags, used in various commands. */
#define IWN_ANT_A	(1 << 0)
#define IWN_ANT_B	(1 << 1)
#define IWN_ANT_C	(1 << 2)
/* Shortcuts. */
#define IWN_ANT_AB	(IWN_ANT_A | IWN_ANT_B)
#define IWN_ANT_AC	(IWN_ANT_A | IWN_ANT_C)
#define IWN_ANT_BC	(IWN_ANT_B | IWN_ANT_C)
#define IWN_ANT_ABC	(IWN_ANT_A | IWN_ANT_B | IWN_ANT_C)

/* Structure for command IWN_CMD_RXON. */
struct iwn_rxon {
	uint8_t		myaddr[IEEE80211_ADDR_LEN];
	uint16_t	reserved1;
	uint8_t		bssid[IEEE80211_ADDR_LEN];
	uint16_t	reserved2;
	uint8_t		wlap[IEEE80211_ADDR_LEN];
	uint16_t	reserved3;
	uint8_t		mode;
#define IWN_MODE_HOSTAP		1
#define IWN_MODE_STA		3
#define IWN_MODE_IBSS		4
#define IWN_MODE_MONITOR	6
#define IWN_MODE_2STA		8
#define IWN_MODE_P2P		9

	uint8_t		air;
	uint16_t	rxchain;
#define IWN_RXCHAIN_DRIVER_FORCE	(1 << 0)
#define IWN_RXCHAIN_VALID(x)		(((x) & IWN_ANT_ABC) << 1)
#define IWN_RXCHAIN_FORCE_SEL(x)	(((x) & IWN_ANT_ABC) << 4)
#define IWN_RXCHAIN_FORCE_MIMO_SEL(x)	(((x) & IWN_ANT_ABC) << 7)
#define IWN_RXCHAIN_IDLE_COUNT(x)	((x) << 10)
#define IWN_RXCHAIN_MIMO_COUNT(x)	((x) << 12)
#define IWN_RXCHAIN_MIMO_FORCE		(1 << 14)

	uint8_t		ofdm_mask;
	uint8_t		cck_mask;
	uint16_t	associd;
	uint32_t	flags;
#define IWN_RXON_24GHZ		(1 <<  0)
#define IWN_RXON_CCK		(1 <<  1)
#define IWN_RXON_AUTO		(1 <<  2)
#define IWN_RXON_SHSLOT		(1 <<  4)
#define IWN_RXON_SHPREAMBLE	(1 <<  5)
#define IWN_RXON_NODIVERSITY	(1 <<  7)
#define IWN_RXON_ANTENNA_A	(1 <<  8)
#define IWN_RXON_ANTENNA_B	(1 <<  9)
#define IWN_RXON_TSF		(1 << 15)
#define IWN_RXON_HT_HT40MINUS	(1 << 22)
#define IWN_RXON_HT_PROTMODE(x)	(x << 23)
#define IWN_RXON_HT_MODEPURE40	(1 << 25)
#define IWN_RXON_HT_MODEMIXED	(2 << 25)
#define IWN_RXON_CTS_TO_SELF	(1 << 30)

	uint32_t	filter;
#define IWN_FILTER_PROMISC	(1 << 0)
#define IWN_FILTER_CTL		(1 << 1)
#define IWN_FILTER_MULTICAST	(1 << 2)
#define IWN_FILTER_NODECRYPT	(1 << 3)
#define IWN_FILTER_BSS		(1 << 5)
#define IWN_FILTER_BEACON	(1 << 6)

	uint8_t		chan;
	uint8_t		reserved4;
	uint8_t		ht_single_mask;
	uint8_t		ht_dual_mask;
	/* The following fields are for >=5000 Series only. */
	uint8_t		ht_triple_mask;
	uint8_t		reserved5;
	uint16_t	acquisition;
	uint16_t	reserved6;
} __packed;

#define IWN4965_RXONSZ	(sizeof (struct iwn_rxon) - 6)
#define IWN5000_RXONSZ	(sizeof (struct iwn_rxon))

/* Structure for command IWN_CMD_ASSOCIATE. */
struct iwn_assoc {
	uint32_t	flags;
	uint32_t	filter;
	uint8_t		ofdm_mask;
	uint8_t		cck_mask;
	uint16_t	reserved;
} __packed;

/* Structure for command IWN_CMD_EDCA_PARAMS. */
struct iwn_edca_params {
	uint32_t	flags;
#define IWN_EDCA_UPDATE	(1 << 0)
#define IWN_EDCA_TXOP	(1 << 4)

	struct {
		uint16_t	cwmin;
		uint16_t	cwmax;
		uint8_t		aifsn;
		uint8_t		reserved;
		uint16_t	txoplimit;
	} __packed	ac[WME_NUM_AC];
} __packed;

/* Structure for command IWN_CMD_TIMING. */
struct iwn_cmd_timing {
	uint64_t	tstamp;
	uint16_t	bintval;
	uint16_t	atim;
	uint32_t	binitval;
	uint16_t	lintval;
	uint8_t		dtim_period;
	uint8_t		delta_cp_bss_tbtts;
} __packed;

/* Structure for command IWN_CMD_ADD_NODE. */
struct iwn_node_info {
	uint8_t		control;
#define IWN_NODE_UPDATE		(1 << 0)

	uint8_t		reserved1[3];

	uint8_t		macaddr[IEEE80211_ADDR_LEN];
	uint16_t	reserved2;
	uint8_t		id;
#define IWN_ID_BSS		 0
#define IWN_STA_ID			1

#define	IWN_PAN_BCAST_ID		14
#define	IWN_BROADCAST_ID		15

#define IWN5000_ID_BROADCAST	15
#define IWN4965_ID_BROADCAST	31

	uint8_t		flags;
#define IWN_FLAG_SET_KEY		(1 << 0)
#define IWN_FLAG_SET_DISABLE_TID	(1 << 1)
#define IWN_FLAG_SET_TXRATE		(1 << 2)
#define IWN_FLAG_SET_ADDBA		(1 << 3)
#define IWN_FLAG_SET_DELBA		(1 << 4)

	uint16_t	reserved3;
	uint16_t	kflags;
#define IWN_KFLAG_CCMP		(1 <<  1)
#define IWN_KFLAG_MAP		(1 <<  3)
#define IWN_KFLAG_KID(kid)	((kid) << 8)
#define IWN_KFLAG_INVALID	(1 << 11)
#define IWN_KFLAG_GROUP		(1 << 14)

	uint8_t		tsc2;	/* TKIP TSC2 */
	uint8_t		reserved4;
	uint16_t	ttak[5];
	uint8_t		kid;
	uint8_t		reserved5;
	uint8_t		key[16];
	/* The following 3 fields are for 5000 Series only. */
	uint64_t	tsc;
	uint8_t		rxmic[8];
	uint8_t		txmic[8];

	uint32_t	htflags;
#define IWN_SMPS_MIMO_PROT		(1 << 17)
#define IWN_AMDPU_SIZE_FACTOR(x)	((x) << 19)
#define IWN_NODE_HT40			(1 << 21)
#define IWN_SMPS_MIMO_DIS		(1 << 22)
#define IWN_AMDPU_DENSITY(x)		((x) << 23)

	uint32_t	mask;
	uint16_t	disable_tid;
	uint16_t	reserved6;
	uint8_t		addba_tid;
	uint8_t		delba_tid;
	uint16_t	addba_ssn;
	uint32_t	reserved7;
} __packed;

struct iwn4965_node_info {
	uint8_t		control;
	uint8_t		reserved1[3];
	uint8_t		macaddr[IEEE80211_ADDR_LEN];
	uint16_t	reserved2;
	uint8_t		id;
	uint8_t		flags;
	uint16_t	reserved3;
	uint16_t	kflags;
	uint8_t		tsc2;	/* TKIP TSC2 */
	uint8_t		reserved4;
	uint16_t	ttak[5];
	uint8_t		kid;
	uint8_t		reserved5;
	uint8_t		key[16];
	uint32_t	htflags;
	uint32_t	mask;
	uint16_t	disable_tid;
	uint16_t	reserved6;
	uint8_t		addba_tid;
	uint8_t		delba_tid;
	uint16_t	addba_ssn;
	uint32_t	reserved7;
} __packed;

#define IWN_RFLAG_MCS		(1 << 8)
#define IWN_RFLAG_CCK		(1 << 9)
#define IWN_RFLAG_GREENFIELD	(1 << 10)
#define IWN_RFLAG_HT40		(1 << 11)
#define IWN_RFLAG_DUPLICATE	(1 << 12)
#define IWN_RFLAG_SGI		(1 << 13)
#define IWN_RFLAG_ANT(x)	((x) << 14)

/* Structure for command IWN_CMD_TX_DATA. */
struct iwn_cmd_data {
	uint16_t	len;
	uint16_t	lnext;
	uint32_t	flags;
#define IWN_TX_NEED_PROTECTION	(1 <<  0)	/* 5000 only */
#define IWN_TX_NEED_RTS		(1 <<  1)
#define IWN_TX_NEED_CTS		(1 <<  2)
#define IWN_TX_NEED_ACK		(1 <<  3)
#define IWN_TX_LINKQ		(1 <<  4)
#define IWN_TX_IMM_BA		(1 <<  6)
#define IWN_TX_FULL_TXOP	(1 <<  7)
#define IWN_TX_BT_DISABLE	(1 << 12)	/* bluetooth coexistence */
#define IWN_TX_AUTO_SEQ		(1 << 13)
#define IWN_TX_MORE_FRAG	(1 << 14)
#define IWN_TX_INSERT_TSTAMP	(1 << 16)
#define IWN_TX_NEED_PADDING	(1 << 20)

	uint32_t	scratch;
	uint32_t	rate;

	uint8_t		id;
	uint8_t		security;
#define IWN_CIPHER_WEP40	1
#define IWN_CIPHER_CCMP		2
#define IWN_CIPHER_TKIP		3
#define IWN_CIPHER_WEP104	9

	uint8_t		linkq;
	uint8_t		reserved2;
	uint8_t		key[16];
	uint16_t	fnext;
	uint16_t	reserved3;
	uint32_t	lifetime;
#define IWN_LIFETIME_INFINITE	0xffffffff

	uint32_t	loaddr;
	uint8_t		hiaddr;
	uint8_t		rts_ntries;
	uint8_t		data_ntries;
	uint8_t		tid;
	uint16_t	timeout;
	uint16_t	txop;
} __packed;

/* Structure for command IWN_CMD_LINK_QUALITY. */
#define IWN_MAX_TX_RETRIES	16
struct iwn_cmd_link_quality {
	uint8_t		id;
	uint8_t		reserved1;
	uint16_t	ctl;
	uint8_t		flags;
	uint8_t		mimo;
	uint8_t		antmsk_1stream;
	uint8_t		antmsk_2stream;
	uint8_t		ridx[WME_NUM_AC];
	uint16_t	ampdu_limit;
	uint8_t		ampdu_threshold;
	uint8_t		ampdu_max;
	uint32_t	reserved2;
	uint32_t	retry[IWN_MAX_TX_RETRIES];
	uint32_t	reserved3;
} __packed;

/* Structure for command IWN_CMD_SET_LED. */
struct iwn_cmd_led {
	uint32_t	unit;	/* multiplier (in usecs) */
	uint8_t		which;
#define IWN_LED_ACTIVITY	1
#define IWN_LED_LINK		2

	uint8_t		off;
	uint8_t		on;
	uint8_t		reserved;
} __packed;

/* Structure for command IWN5000_CMD_WIMAX_COEX. */
struct iwn5000_wimax_coex {
	uint32_t	flags;
#define IWN_WIMAX_COEX_STA_TABLE_VALID		(1 << 0)
#define IWN_WIMAX_COEX_UNASSOC_WA_UNMASK	(1 << 2)
#define IWN_WIMAX_COEX_ASSOC_WA_UNMASK		(1 << 3)
#define IWN_WIMAX_COEX_ENABLE			(1 << 7)

	struct iwn5000_wimax_event {
		uint8_t	request;
		uint8_t	window;
		uint8_t	reserved;
		uint8_t	flags;
	} __packed	events[16];
} __packed;

/* Structures for command IWN5000_CMD_CALIB_CONFIG. */
struct iwn5000_calib_elem {
	uint32_t	enable;
	uint32_t	start;
#define	IWN5000_CALIB_DC	(1 << 1)

	uint32_t	send;
	uint32_t	apply;
	uint32_t	reserved;
} __packed;

struct iwn5000_calib_status {
	struct iwn5000_calib_elem	once;
	struct iwn5000_calib_elem	perd;
	uint32_t			flags;
} __packed;

struct iwn5000_calib_config {
	struct iwn5000_calib_status	ucode;
	struct iwn5000_calib_status	driver;
	uint32_t			reserved;
} __packed;

/* Structure for command IWN_CMD_SET_POWER_MODE. */
struct iwn_pmgt_cmd {
	uint16_t	flags;
#define IWN_PS_ALLOW_SLEEP	(1 << 0)
#define IWN_PS_NOTIFY		(1 << 1)
#define IWN_PS_SLEEP_OVER_DTIM	(1 << 2)
#define IWN_PS_PCI_PMGT		(1 << 3)
#define IWN_PS_FAST_PD		(1 << 4)
#define IWN_PS_BEACON_FILTERING	(1 << 5)
#define IWN_PS_SHADOW_REG	(1 << 6)
#define IWN_PS_CT_KILL		(1 << 7)
#define IWN_PS_BT_SCD		(1 << 8)
#define IWN_PS_ADVANCED_PM	(1 << 9)


	uint8_t		keepalive;
	uint8_t		debug;
	uint32_t	rxtimeout;
	uint32_t	txtimeout;
	uint32_t	intval[5];
	uint32_t	beacons;
} __packed;

/* Structures for command IWN_CMD_SCAN. */
struct iwn_scan_essid {
	uint8_t	id;
	uint8_t	len;
	uint8_t	data[IEEE80211_NWID_LEN];
} __packed;

struct iwn_scan_hdr {
	uint16_t	len;
	uint8_t		reserved1;
	uint8_t		nchan;
	uint16_t	quiet_time;
	uint16_t	quiet_threshold;
	uint16_t	crc_threshold;
	uint16_t	rxchain;
	uint32_t	max_svc;	/* background scans */
	uint32_t	pause_svc;	/* background scans */
	uint32_t	flags;
	uint32_t	filter;

	/* Followed by a struct iwn_cmd_data. */
	/* Followed by an array of 20 structs iwn_scan_essid. */
	/* Followed by probe request body. */
	/* Followed by an array of ``nchan'' structs iwn_scan_chan. */
} __packed;

struct iwn_scan_chan {
	uint32_t	flags;
#define IWN_CHAN_PASSIVE	(0 << 0)
#define IWN_CHAN_ACTIVE		(1 << 0)
#define IWN_CHAN_NPBREQS(x)	(((1 << (x)) - 1) << 1)

	uint16_t	chan;
	uint8_t		rf_gain;
	uint8_t		dsp_gain;
	uint16_t	active;		/* msecs */
	uint16_t	passive;	/* msecs */
} __packed;

#define	IWN_SCAN_CRC_TH_DISABLED	0
#define	IWN_SCAN_CRC_TH_DEFAULT		htole16(1)
#define	IWN_SCAN_CRC_TH_NEVER		htole16(0xffff)


/* Maximum size of a scan command. */
#define IWN_SCAN_MAXSZ	(MCLBYTES - 4)

#define IWN_ACTIVE_DWELL_TIME_24	(30)	/* all times in msec */
#define IWN_ACTIVE_DWELL_TIME_52	(20)
#define IWN_ACTIVE_DWELL_FACTOR_24	(3)
#define IWN_ACTIVE_DWELL_FACTOR_52	(2)

#define IWN_PASSIVE_DWELL_TIME_24	(20)	/* all times in msec */
#define IWN_PASSIVE_DWELL_TIME_52	(10)
#define IWN_PASSIVE_DWELL_BASE		(100)
#define IWN_CHANNEL_TUNE_TIME		(5)

#define IWN_SCAN_CHAN_TIMEOUT		2

/* Structure for command IWN_CMD_TXPOWER (4965AGN only.) */
#define IWN_RIDX_MAX	32
struct iwn4965_cmd_txpower {
	uint8_t		band;
	uint8_t		reserved1;
	uint8_t		chan;
	uint8_t		reserved2;
	struct {
		uint8_t	rf_gain[2];
		uint8_t	dsp_gain[2];
	} __packed	power[IWN_RIDX_MAX + 1];
} __packed;

/* Structure for command IWN_CMD_TXPOWER_DBM (5000 Series only.) */
struct iwn5000_cmd_txpower {
	int8_t	global_limit;	/* in half-dBm */
#define IWN5000_TXPOWER_AUTO		0x7f
#define IWN5000_TXPOWER_MAX_DBM		16

	uint8_t	flags;
#define IWN5000_TXPOWER_NO_CLOSED	(1 << 6)

	int8_t	srv_limit;	/* in half-dBm */
	uint8_t	reserved;
} __packed;

/* Structures for command IWN_CMD_BLUETOOTH. */
struct iwn_bluetooth {
	uint8_t		flags;
#define IWN_BT_COEX_CHAN_ANN	(1 << 0)
#define IWN_BT_COEX_BT_PRIO	(1 << 1)
#define IWN_BT_COEX_2_WIRE	(1 << 2)

	uint8_t		lead_time;
#define IWN_BT_LEAD_TIME_DEF	30

	uint8_t		max_kill;
#define IWN_BT_MAX_KILL_DEF	5

	uint8_t		reserved;
	uint32_t	kill_ack;
	uint32_t	kill_cts;
} __packed;

/* Structures for enhanced command IWN_CMD_BLUETOOTH. */
struct iwn6000_btcoex_config {
	uint8_t		flags;
#define IWN_BT_FLAG_COEX6000_CHAN_INHIBITION	1
#define IWN_BT_FLAG_COEX6000_MODE_MASK			( (1 << 3) | (1 << 4) | (1 <<5 ))
#define IWN_BT_FLAG_COEX6000_MODE_SHIFT			3
#define IWN_BT_FLAG_COEX6000_MODE_DISABLED		0
#define IWN_BT_FLAG_COEX6000_MODE_LEGACY_2W		1
#define IWN_BT_FLAG_COEX6000_MODE_3W			2
#define IWN_BT_FLAG_COEX6000_MODE_4W			3

#define IWN_BT_FLAG_UCODE_DEFAULT		(1 << 6)
/* Disable Sync PSPoll on SCO/eSCO */
#define IWN_BT_FLAG_SYNC_2_BT_DISABLE	(1 << 7)
	uint8_t		lead_time;
	uint8_t		max_kill;
	uint8_t		bt3_t7_timer;
	uint32_t	kill_ack;
	uint32_t	kill_cts;
	uint8_t		sample_time;
	uint8_t		bt3_t2_timer;
	uint16_t	bt4_reaction;
	uint32_t	lookup_table[12];
	uint16_t	bt4_decision;
	uint16_t	valid;
	uint8_t		prio_boost;
	uint8_t		tx_prio_boost;
	uint16_t	rx_prio_boost;
} __packed;

/* Structures for enhanced command IWN_CMD_BLUETOOTH for 2000 Series. */
struct iwn2000_btcoex_config {
	uint8_t		flags; // Cf Flags in iwn6000_btcoex_config
	uint8_t		lead_time;
	uint8_t		max_kill;
	uint8_t		bt3_t7_timer;
	uint32_t	kill_ack;
	uint32_t	kill_cts;
	uint8_t		sample_time;
	uint8_t		bt3_t2_timer;
	uint16_t	bt4_reaction;
	uint32_t	lookup_table[12];
	uint16_t	bt4_decision;
	uint16_t	valid;
	
	uint32_t	prio_boost; // size change prior to iwn6000_btcoex_config
	uint8_t		reserved; // added prior to iwn6000_btcoex_config
	
	uint8_t		tx_prio_boost;
	uint16_t	rx_prio_boost;
} __packed;


struct iwn_btcoex_priotable {
	uint8_t		calib_init1;
	uint8_t		calib_init2;
	uint8_t		calib_periodic_low1;
	uint8_t		calib_periodic_low2;
	uint8_t		calib_periodic_high1;
	uint8_t		calib_periodic_high2;
	uint8_t		dtim;
	uint8_t		scan52;
	uint8_t		scan24;
	uint8_t		reserved[7];
} __packed;

struct iwn_btcoex_prot {
	uint8_t		open;
	uint8_t		type;
	uint8_t		reserved[2];
} __packed;

/* Structure for command IWN_CMD_SET_CRITICAL_TEMP. */
struct iwn_critical_temp {
	uint32_t	tempM;
	uint32_t	reserved;
	uint32_t	tempR;
/* degK <-> degC conversion macros. */
#define IWN_CTOK(c)	((c) + 273)
#define IWN_KTOC(k)	((k) - 273)
#define IWN_CTOMUK(c)	(((c) * 1000000) + 273150000)
} __packed;

/* Structures for command IWN_CMD_SET_SENSITIVITY. */
struct iwn_sensitivity_cmd {
	uint16_t	which;
#define IWN_SENSITIVITY_DEFAULTTBL	0
#define IWN_SENSITIVITY_WORKTBL		1

	uint16_t	energy_cck;
	uint16_t	energy_ofdm;
	uint16_t	corr_ofdm_x1;
	uint16_t	corr_ofdm_mrc_x1;
	uint16_t	corr_cck_mrc_x4;
	uint16_t	corr_ofdm_x4;
	uint16_t	corr_ofdm_mrc_x4;
	uint16_t	corr_barker;
	uint16_t	corr_barker_mrc;
	uint16_t	corr_cck_x4;
	uint16_t	energy_ofdm_th;
} __packed;

struct iwn_enhanced_sensitivity_cmd {
	uint16_t	which;
	uint16_t	energy_cck;
	uint16_t	energy_ofdm;
	uint16_t	corr_ofdm_x1;
	uint16_t	corr_ofdm_mrc_x1;
	uint16_t	corr_cck_mrc_x4;
	uint16_t	corr_ofdm_x4;
	uint16_t	corr_ofdm_mrc_x4;
	uint16_t	corr_barker;
	uint16_t	corr_barker_mrc;
	uint16_t	corr_cck_x4;
	uint16_t	energy_ofdm_th;
	/* "Enhanced" part. */
	uint16_t	ina_det_ofdm;
	uint16_t	ina_det_cck;
	uint16_t	corr_11_9_en;
	uint16_t	ofdm_det_slope_mrc;
	uint16_t	ofdm_det_icept_mrc;
	uint16_t	ofdm_det_slope;
	uint16_t	ofdm_det_icept;
	uint16_t	cck_det_slope_mrc;
	uint16_t	cck_det_icept_mrc;
	uint16_t	cck_det_slope;
	uint16_t	cck_det_icept;
	uint16_t	reserved;
} __packed;

/* Define maximal number of calib result send to runtime firmware 
PS: TEMP_OFFSET count for 2 (std and v2)
*/
#define IWN5000_PHY_CALIB_MAX_RESULT	8
/* Structures for command IWN_CMD_PHY_CALIB. */
struct iwn_phy_calib {
	uint8_t	code;
#define IWN4965_PHY_CALIB_DIFF_GAIN		 7
#define IWN5000_PHY_CALIB_DC			 8
#define IWN5000_PHY_CALIB_LO			 9
#define IWN5000_PHY_CALIB_TX_IQ			11
#define IWN5000_PHY_CALIB_CRYSTAL		15 //Linux = IWL_PHY_CALIBRATE_CRYSTAL_FRQ_CMD
#define IWN5000_PHY_CALIB_BASE_BAND		16
#define IWN5000_PHY_CALIB_TX_IQ_PERIODIC	17
#define IWN5000_PHY_CALIB_TEMP_OFFSET		18

#define IWN5000_PHY_CALIB_RESET_NOISE_GAIN	18
#define IWN5000_PHY_CALIB_NOISE_GAIN		19

	uint8_t	group;
	uint8_t	ngroups;
	uint8_t	isvalid;
} __packed;

#define IWN_BUF_IX_PHY_CALIB_DC				0
#define IWN_BUF_IX_PHY_CALIB_LO			 	1
#define IWN_BUF_IX_PHY_CALIB_TX_IQ			2
#define IWN_BUF_IX_PHY_CALIB_CRYSTAL		3
#define IWN_BUF_IX_PHY_CALIB_BASE_BAND		4
#define IWN_BUF_IX_PHY_CALIB_TX_IQ_PERIODIC	5
#define IWN_BUF_IX_PHY_CALIB_TEMP_OFFSET	6 
#define IWN_BUF_IX_PHY_CALIB_TEMP_OFFSETv2	7

struct iwn5000_phy_calib_crystal {
	uint8_t	code;
	uint8_t	group;
	uint8_t	ngroups;
	uint8_t	isvalid;

	uint8_t	cap_pin[2];
	uint8_t	reserved[2];
} __packed;

struct iwn5000_phy_calib_temp_offset {
	uint8_t		code;
	uint8_t		group;
	uint8_t		ngroups;
	uint8_t		isvalid;
	int16_t		offset;
#define IWN_DEFAULT_TEMP_OFFSET	2700

	uint16_t	reserved;
} __packed;

struct iwn5000_phy_calib_temp_offsetv2 {
	uint8_t		code;
	uint8_t		group;
	uint8_t		ngroups;
	uint8_t		isvalid;
	int16_t 	offset_high;
	int16_t		offset_low;
	int16_t		burntVoltageRef;
	int16_t		reserved;
} __packed;

struct iwn_phy_calib_gain {
	uint8_t	code;
	uint8_t	group;
	uint8_t	ngroups;
	uint8_t	isvalid;

	int8_t	gain[3];
	uint8_t	reserved;
} __packed;

/* Structure for command IWN_CMD_SPECTRUM_MEASUREMENT. */
struct iwn_spectrum_cmd {
	uint16_t	len;
	uint8_t		token;
	uint8_t		id;
	uint8_t		origin;
	uint8_t		periodic;
	uint16_t	timeout;
	uint32_t	start;
	uint32_t	reserved1;
	uint32_t	flags;
	uint32_t	filter;
	uint16_t	nchan;
	uint16_t	reserved2;
	struct {
		uint32_t	duration;
		uint8_t		chan;
		uint8_t		type;
#define IWN_MEASUREMENT_BASIC		(1 << 0)
#define IWN_MEASUREMENT_CCA		(1 << 1)
#define IWN_MEASUREMENT_RPI_HISTOGRAM	(1 << 2)
#define IWN_MEASUREMENT_NOISE_HISTOGRAM	(1 << 3)
#define IWN_MEASUREMENT_FRAME		(1 << 4)
#define IWN_MEASUREMENT_IDLE		(1 << 7)

		uint16_t	reserved;
	} __packed	chan[10];
} __packed;

/* Structure for IWN_UC_READY notification. */
#define IWN_NATTEN_GROUPS	5
struct iwn_ucode_info {
	uint8_t		minor;
	uint8_t		major;
	uint16_t	reserved1;
	uint8_t		revision[8];
	uint8_t		type;
	uint8_t		subtype;
#define IWN_UCODE_RUNTIME	0
#define IWN_UCODE_INIT		9

	uint16_t	reserved2;
	uint32_t	logptr;
	uint32_t	errptr;
	uint32_t	tstamp;
	uint32_t	valid;

	/* The following fields are for UCODE_INIT only. */
	int32_t		volt;
	struct {
		int32_t	chan20MHz;
		int32_t	chan40MHz;
	} __packed	temp[4];
	int32_t		atten[IWN_NATTEN_GROUPS][2];
} __packed;

/* Structures for IWN_TX_DONE notification. */
#define IWN_TX_SUCCESS			0x00
#define IWN_TX_FAIL			0x80	/* all failures have 0x80 set */
#define IWN_TX_FAIL_SHORT_LIMIT		0x82	/* too many RTS retries */
#define IWN_TX_FAIL_LONG_LIMIT		0x83	/* too many retries */
#define IWN_TX_FAIL_FIFO_UNDERRRUN	0x84	/* tx fifo not kept running */
#define IWN_TX_FAIL_DEST_IN_PS		0x88	/* sta found in power save */
#define IWN_TX_FAIL_TX_LOCKED		0x90	/* waiting to see traffic */

struct iwn4965_tx_stat {
	uint8_t		nframes;
	uint8_t		btkillcnt;
	uint8_t		rtsfailcnt;
	uint8_t		ackfailcnt;
	uint32_t	rate;
	uint16_t	duration;
	uint16_t	reserved;
	uint32_t	power[2];
	uint32_t	status;
} __packed;

struct iwn5000_tx_stat {
	uint8_t		nframes;
	uint8_t		btkillcnt;
	uint8_t		rtsfailcnt;
	uint8_t		ackfailcnt;
	uint32_t	rate;
	uint16_t	duration;
	uint16_t	reserved;
	uint32_t	power[2];
	uint32_t	info;
	uint16_t	seq;
	uint16_t	len;
	uint8_t		tlc;
	uint8_t		ratid;
	uint8_t		fc[2];
	uint16_t	status;
	uint16_t	sequence;
} __packed;

/* Structure for IWN_BEACON_MISSED notification. */
struct iwn_beacon_missed {
	uint32_t	consecutive;
	uint32_t	total;
	uint32_t	expected;
	uint32_t	received;
} __packed;

/* Structure for IWN_MPDU_RX_DONE notification. */
struct iwn_rx_mpdu {
	uint16_t	len;
	uint16_t	reserved;
} __packed;

/* Structures for IWN_RX_DONE and IWN_MPDU_RX_DONE notifications. */
struct iwn4965_rx_phystat {
	uint16_t	antenna;
	uint16_t	agc;
	uint8_t		rssi[6];
} __packed;

struct iwn5000_rx_phystat {
	uint32_t	reserved1;
	uint32_t	agc;
	uint16_t	rssi[3];
} __packed;

struct iwn_rx_stat {
	uint8_t		phy_len;
	uint8_t		cfg_phy_len;
#define IWN_STAT_MAXLEN	20

	uint8_t		id;
	uint8_t		reserved1;
	uint64_t	tstamp;
	uint32_t	beacon;
	uint16_t	flags;
#define IWN_STAT_FLAG_SHPREAMBLE	(1 << 2)

	uint16_t	chan;
	uint8_t		phybuf[32];
	uint32_t	rate;
	uint16_t	len;
	uint16_t	reserve3;
} __packed;

#define IWN_RSSI_TO_DBM	44

/* Structure for IWN_RX_COMPRESSED_BA notification. */
struct iwn_compressed_ba {
	uint8_t		macaddr[IEEE80211_ADDR_LEN];
	uint16_t	reserved;
	uint8_t		id;
	uint8_t		tid;
	uint16_t	seq;
	uint64_t	bitmap;
	uint16_t	qid;
	uint16_t	ssn;
} __packed;

/* Structure for IWN_START_SCAN notification. */
struct iwn_start_scan {
	uint64_t	tstamp;
	uint32_t	tbeacon;
	uint8_t		chan;
	uint8_t		band;
	uint16_t	reserved;
	uint32_t	status;
} __packed;

/* Structure for IWN_STOP_SCAN notification. */
struct iwn_stop_scan {
	uint8_t		nchan;
	uint8_t		status;
	uint8_t		reserved;
	uint8_t		chan;
	uint64_t	tsf;
} __packed;

/* Structure for IWN_SPECTRUM_MEASUREMENT notification. */
struct iwn_spectrum_notif {
	uint8_t		id;
	uint8_t		token;
	uint8_t		idx;
	uint8_t		state;
#define IWN_MEASUREMENT_START	0
#define IWN_MEASUREMENT_STOP	1

	uint32_t	start;
	uint8_t		band;
	uint8_t		chan;
	uint8_t		type;
	uint8_t		reserved1;
	uint32_t	cca_ofdm;
	uint32_t	cca_cck;
	uint32_t	cca_time;
	uint8_t		basic;
	uint8_t		reserved2[3];
	uint32_t	ofdm[8];
	uint32_t	cck[8];
	uint32_t	stop;
	uint32_t	status;
#define IWN_MEASUREMENT_OK		0
#define IWN_MEASUREMENT_CONCURRENT	1
#define IWN_MEASUREMENT_CSA_CONFLICT	2
#define IWN_MEASUREMENT_TGH_CONFLICT	3
#define IWN_MEASUREMENT_STOPPED		6
#define IWN_MEASUREMENT_TIMEOUT		7
#define IWN_MEASUREMENT_FAILED		8
} __packed;

/* Structures for IWN_{RX,BEACON}_STATISTICS notification. */
struct iwn_rx_phy_stats {
	uint32_t	ina;
	uint32_t	fina;
	uint32_t	bad_plcp;
	uint32_t	bad_crc32;
	uint32_t	overrun;
	uint32_t	eoverrun;
	uint32_t	good_crc32;
	uint32_t	fa;
	uint32_t	bad_fina_sync;
	uint32_t	sfd_timeout;
	uint32_t	fina_timeout;
	uint32_t	no_rts_ack;
	uint32_t	rxe_limit;
	uint32_t	ack;
	uint32_t	cts;
	uint32_t	ba_resp;
	uint32_t	dsp_kill;
	uint32_t	bad_mh;
	uint32_t	rssi_sum;
	uint32_t	reserved;
} __packed;

struct iwn_rx_general_stats {
	uint32_t	bad_cts;
	uint32_t	bad_ack;
	uint32_t	not_bss;
	uint32_t	filtered;
	uint32_t	bad_chan;
	uint32_t	beacons;
	uint32_t	missed_beacons;
	uint32_t	adc_saturated;	/* time in 0.8us */
	uint32_t	ina_searched;	/* time in 0.8us */
	uint32_t	noise[3];
	uint32_t	flags;
	uint32_t	load;
	uint32_t	fa;
	uint32_t	rssi[3];
	uint32_t	energy[3];
} __packed;

struct iwn_rx_ht_phy_stats {
	uint32_t	bad_plcp;
	uint32_t	overrun;
	uint32_t	eoverrun;
	uint32_t	good_crc32;
	uint32_t	bad_crc32;
	uint32_t	bad_mh;
	uint32_t	good_ampdu_crc32;
	uint32_t	ampdu;
	uint32_t	fragment;
	uint32_t	reserved;
} __packed;

struct iwn_rx_stats {
	struct iwn_rx_phy_stats		ofdm;
	struct iwn_rx_phy_stats		cck;
	struct iwn_rx_general_stats	general;
	struct iwn_rx_ht_phy_stats	ht;
} __packed;

struct iwn_tx_stats {
	uint32_t	preamble;
	uint32_t	rx_detected;
	uint32_t	bt_defer;
	uint32_t	bt_kill;
	uint32_t	short_len;
	uint32_t	cts_timeout;
	uint32_t	ack_timeout;
	uint32_t	exp_ack;
	uint32_t	ack;
	uint32_t	msdu;
	uint32_t	busrt_err1;
	uint32_t	burst_err2;
	uint32_t	cts_collision;
	uint32_t	ack_collision;
	uint32_t	ba_timeout;
	uint32_t	ba_resched;
	uint32_t	query_ampdu;
	uint32_t	query;
	uint32_t	query_ampdu_frag;
	uint32_t	query_mismatch;
	uint32_t	not_ready;
	uint32_t	underrun;
	uint32_t	bt_ht_kill;
	uint32_t	rx_ba_resp;
	uint32_t	reserved[2];
} __packed;

struct iwn_general_stats {
	uint32_t	temp;
	uint32_t	temp_m;
	uint32_t	burst_check;
	uint32_t	burst;
	uint32_t	reserved1[4];
	uint32_t	sleep;
	uint32_t	slot_out;
	uint32_t	slot_idle;
	uint32_t	ttl_tstamp;
	uint32_t	tx_ant_a;
	uint32_t	tx_ant_b;
	uint32_t	exec;
	uint32_t	probe;
	uint32_t	reserved2[2];
	uint32_t	rx_enabled;
	uint32_t	reserved3[3];
} __packed;

struct iwn_stats {
	uint32_t			flags;
	struct iwn_rx_stats		rx;
	struct iwn_tx_stats		tx;
	struct iwn_general_stats	general;
} __packed;


/* Firmware error dump. */
struct iwn_fw_dump {
	uint32_t	valid;
	uint32_t	id;
	uint32_t	pc;
	uint32_t	branch_link[2];
	uint32_t	interrupt_link[2];
	uint32_t	error_data[2];
	uint32_t	src_line;
	uint32_t	tsf;
	uint32_t	time[2];
} __packed;

/* TLV firmware header. */
struct iwn_fw_tlv_hdr {
	uint32_t	zero;	/* Always 0, to differentiate from legacy. */
	uint32_t	signature;
#define IWN_FW_SIGNATURE	0x0a4c5749	/* "IWL\n" */

	uint8_t		descr[64];
	uint32_t	rev;
#define IWN_FW_API(x)	(((x) >> 8) & 0xff)

	uint32_t	build;
	uint64_t	altmask;
} __packed;

/* TLV header. */
struct iwn_fw_tlv {
	uint16_t	type;
#define IWN_FW_TLV_MAIN_TEXT		1
#define IWN_FW_TLV_MAIN_DATA		2
#define IWN_FW_TLV_INIT_TEXT		3
#define IWN_FW_TLV_INIT_DATA		4
#define IWN_FW_TLV_BOOT_TEXT		5
#define IWN_FW_TLV_PBREQ_MAXLEN		6
#define IWN_FW_TLV_PAN				7
#define	IWN_FW_TLV_RUNT_EVTLOG_PTR	8
#define	IWN_FW_TLV_RUNT_EVTLOG_SIZE	9
#define	IWN_FW_TLV_RUNT_ERRLOG_PTR	10
#define	IWN_FW_TLV_INIT_EVTLOG_PTR	11
#define	IWN_FW_TLV_INIT_EVTLOG_SIZE	12
#define	IWN_FW_TLV_INIT_ERRLOG_PTR	13
#define IWN_FW_TLV_ENH_SENS			14
#define IWN_FW_TLV_PHY_CALIB		15
#define	IWN_FW_TLV_WOWLAN_INST		16
#define	IWN_FW_TLV_WOWLAN_DATA		17
#define	IWN_FW_TLV_FLAGS			18

	uint16_t	alt;
	uint32_t	len;
} __packed;

#define IWN_FW_TLV_FLAGS_NEW_SCAN_BITPOS 1

#define IWN4965_FW_TEXT_MAXSZ	( 96 * 1024)
#define IWN4965_FW_DATA_MAXSZ	( 40 * 1024)
#define IWN5000_FW_TEXT_MAXSZ	(256 * 1024)
#define IWN5000_FW_DATA_MAXSZ	( 80 * 1024)
#define IWN_FW_BOOT_TEXT_MAXSZ	1024
#define IWN4965_FWSZ		(IWN4965_FW_TEXT_MAXSZ + IWN4965_FW_DATA_MAXSZ)
#define IWN5000_FWSZ		IWN5000_FW_TEXT_MAXSZ

/*
 * Offsets into EEPROM.
 */
#define IWN_EEPROM_MAC		0x015
#define IWN_EEPROM_SKU_CAP	0x045
#define IWN_EEPROM_RFCFG	0x048
#define IWN4965_EEPROM_DOMAIN	0x060
#define IWN4965_EEPROM_BAND1	0x063
#define IWN5000_EEPROM_REG		0x066
#define IWN5000_EEPROM_CAL		0x067
#define IWN4965_EEPROM_BAND2	0x072
#define IWN4965_EEPROM_BAND3	0x080
#define IWN4965_EEPROM_BAND4	0x08d
#define IWN4965_EEPROM_BAND5	0x099
#define IWN4965_EEPROM_BAND6	0x0a0
#define IWN4965_EEPROM_BAND7	0x0a8
#define IWN4965_EEPROM_MAXPOW	0x0e8
#define IWN4965_EEPROM_VOLTAGE	0x0e9
#define IWN4965_EEPROM_BANDS	0x0ea
/* Indirect offsets. */
#define IWN5000_EEPROM_DOMAIN	0x001
#define IWN6000_EEPROM_ENHINFO	0x054
#define IWN5000_EEPROM_CRYSTAL	0x128 //XTAL in linux 3.2
#define IWN5000_EEPROM_TEMP		0x12a //KELVIN_TEMPERATURE in linux 3.2
#define IWN5000_EEPROM_VOLT		0x12b //RAW_TEMPERATURE  in linux 3.2

/* Possible flags for IWN_EEPROM_SKU_CAP. */
#define IWN_EEPROM_SKU_CAP_11N	(1 << 6)
#define IWN_EEPROM_SKU_CAP_AMT	(1 << 7)
#define IWN_EEPROM_SKU_CAP_IPAN	(1 << 8)

/* Possible flags for IWN_EEPROM_RFCFG. */
#define IWN_RFCFG_TYPE(x)	(((x) >>  0) & 0x3)
#define IWN_RFCFG_STEP(x)	(((x) >>  2) & 0x3)
#define IWN_RFCFG_DASH(x)	(((x) >>  4) & 0x3)
#define IWN_RFCFG_TXANTMSK(x)	(((x) >>  8) & 0xf)
#define IWN_RFCFG_RXANTMSK(x)	(((x) >> 12) & 0xf)

struct iwn_eeprom_chan {
	uint8_t	flags;
#define IWN_EEPROM_CHAN_VALID	(1 << 0)
#define IWN_EEPROM_CHAN_IBSS	(1 << 1)
#define IWN_EEPROM_CHAN_ACTIVE	(1 << 3)
#define IWN_EEPROM_CHAN_RADAR	(1 << 4)

	int8_t	maxpwr;
} __packed;

struct iwn_eeprom_enhinfo {
	uint8_t		flags;
#define IWN_ENHINFO_VALID	0x01
#define IWN_ENHINFO_5GHZ	0x02
#define IWN_ENHINFO_OFDM	0x04
#define IWN_ENHINFO_HT40	0x08
#define IWN_ENHINFO_HTAP	0x10
#define IWN_ENHINFO_RES1	0x20
#define IWN_ENHINFO_RES2	0x40
#define IWN_ENHINFO_COMMON	0x80

	uint8_t		chan;
	int8_t		chain[3];	/* max power in half-dBm */
	uint8_t		reserved;
	int8_t		mimo2;		/* max power in half-dBm */
	int8_t		mimo3;		/* max power in half-dBm */
} __packed;

struct iwn5000_eeprom_calib_hdr {
	uint8_t		version;
	uint8_t		pa_type;
	uint16_t	volt;
} __packed;

#define IWN_NSAMPLES	3
struct iwn4965_eeprom_chan_samples {
	uint8_t	num;
	struct {
		uint8_t temp;
		uint8_t	gain;
		uint8_t	power;
		int8_t	pa_det;
	}	samples[2][IWN_NSAMPLES];
} __packed;

#define IWN_NBANDS	8
struct iwn4965_eeprom_band {
	uint8_t	lo;	/* low channel number */
	uint8_t	hi;	/* high channel number */
	struct	iwn4965_eeprom_chan_samples chans[2];
} __packed;

/* ADD / MODIFY STATION Command (Op Code 18) -  byte 76-18 -bit13
	STA_FLAG_PAN_STATION bit:
	This bit is set (1) for a station in PAN mode */
#define IWN_STA_FLAG_PAN_STATION		(1 << 13)

#define IWN_BEACON_INTERVAL_DEFAULT		200
#define IWN_SLOT_TIME_MIN		20



/*
 * Offsets of channels descriptions in EEPROM.
 */
#define IWN5000_EEPROM_NO_HT40	0x000 //EEPROM_REGULATORY_BAND_NO_HT40
#define IWN5000_EEPROM_BAND1	0x004 //EEPROM_REG_BAND_1_CHANNELS
#define IWN5000_EEPROM_BAND2	0x013 //EEPROM_REG_BAND_2_CHANNELS
#define IWN5000_EEPROM_BAND3	0x021 //EEPROM_REG_BAND_3_CHANNELS
#define IWN5000_EEPROM_BAND4	0x02e //EEPROM_REG_BAND_4_CHANNELS
#define IWN5000_EEPROM_BAND5	0x03a //EEPROM_REG_BAND_5_CHANNELS
#define IWN5000_EEPROM_BAND6	0x041 //EEPROM_REG_BAND_24_HT40_CHANNELS
#define IWN6000_EEPROM_BAND6	0x040 //EEPROM_6000_REG_BAND_24_HT40_CHANNELS
#define IWN5000_EEPROM_BAND7	0x049 //EEPROM_REG_BAND_52_HT40_CHANNELS

static const uint32_t iwn4965_regulatory_bands[IWN_NBANDS] = {
	IWN4965_EEPROM_BAND1,
	IWN4965_EEPROM_BAND2,
	IWN4965_EEPROM_BAND3,
	IWN4965_EEPROM_BAND4,
	IWN4965_EEPROM_BAND5,
	IWN4965_EEPROM_BAND6,
	IWN4965_EEPROM_BAND7 // Should be IWN5000_EEPRON_NO_HT40
};

static const uint32_t iwn5000_regulatory_bands[IWN_NBANDS] = {
	IWN5000_EEPROM_BAND1,
	IWN5000_EEPROM_BAND2,
	IWN5000_EEPROM_BAND3,
	IWN5000_EEPROM_BAND4,
	IWN5000_EEPROM_BAND5,
	IWN5000_EEPROM_BAND6,
	IWN5000_EEPROM_BAND7
};

static const uint32_t iwn6000_regulatory_bands[IWN_NBANDS] = {
	IWN5000_EEPROM_BAND1,
	IWN5000_EEPROM_BAND2,
	IWN5000_EEPROM_BAND3,
	IWN5000_EEPROM_BAND4,
	IWN5000_EEPROM_BAND5,
	IWN6000_EEPROM_BAND6,
	IWN5000_EEPROM_BAND7
};

static const uint32_t iwn1000_regulatory_bands[IWN_NBANDS] = {
	IWN5000_EEPROM_BAND1,
	IWN5000_EEPROM_BAND2,
	IWN5000_EEPROM_BAND3,
	IWN5000_EEPROM_BAND4,
	IWN5000_EEPROM_BAND5,
	IWN5000_EEPROM_BAND6,
	IWN5000_EEPROM_NO_HT40,
};

#define IWN_CHAN_BANDS_COUNT	 7
#define IWN_MAX_CHAN_PER_BAND	14
static const struct iwn_chan_band {
	uint8_t	nchan;
	uint8_t	chan[IWN_MAX_CHAN_PER_BAND];
} iwn_bands[] = {
	/* 20MHz channels, 2GHz band. */
	{ 14, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 } },
	/* 20MHz channels, 5GHz band. */
	{ 13, { 183, 184, 185, 187, 188, 189, 192, 196, 7, 8, 11, 12, 16 } },
	{ 12, { 34, 36, 38, 40, 42, 44, 46, 48, 52, 56, 60, 64 } },
	{ 11, { 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140 } },
	{  6, { 145, 149, 153, 157, 161, 165 } },
	/* 40MHz channels (primary channels), 2GHz band. */
	{  7, { 1, 2, 3, 4, 5, 6, 7 } },
	/* 40MHz channels (primary channels), 5GHz band. */
	{ 11, { 36, 44, 52, 60, 100, 108, 116, 124, 132, 149, 157 } }
};

static const uint8_t iwn_bss_ac_to_queue[] = {
	2, 3, 1, 0,
};

static const uint8_t iwn_pan_ac_to_queue[] = {
	5, 4, 6, 7,
};


/* OTP */
/* lower blocks contain EEPROM image and calibration data */
#define OTP_LOW_IMAGE_SIZE		(2 * 512 * sizeof(int)) /* 2 KB */


#define IWN1000_OTP_NBLOCKS	3 
#define IWN6000_OTP_NBLOCKS	4 
#define IWN6050_OTP_NBLOCKS	7

/* HW rate indices. */
#define IWN_RIDX_CCK1	0
#define IWN_RIDX_OFDM6	4

#define IWN4965_MAX_PWR_INDEX	107

#define IWN_POWERSAVE_LVL_NONE 			0
#define IWN_POWERSAVE_LVL_VOIP_COMPATIBLE 	1
#define IWN_POWERSAVE_LVL_MAX 			5

#define IWN_POWERSAVE_LVL_DEFAULT IWN_POWERSAVE_LVL_NONE

/* DTIM value to pass in for IWN_POWERSAVE_LVL_VOIP_COMPATIBLE */
#define IWN_POWERSAVE_DTIM_VOIP_COMPATIBLE 2


/*
 * If IWN_DTIM_INDICATES_UNICAST_PENDING_AT_AP is defined, then power saving
 * (including the power saving done for unicast traffic) becomes proportional
 * to the DTIM period received from the AP. Otherwise the constant DTIM
 * period IWN_POWERSAVE_DTIM_VOIP_COMPATIBLE is used.
 *
 * Per the 802.11 spec DTIM value as applicable to power saving seems to be
 * relevant only for indicating the frequency at which broadcast/multicast
 * data is sent to the PS STAs.
 * However in practice some APs may also send the unicast traffic along with
 * the DTIM.
 */
#define IWN_DTIM_INDICATES_UNICAST_PENDING_AT_AP



/*
 * RF Tx gain values from highest to lowest power (values obtained from
 * the reference driver.)
 */
static const uint8_t iwn4965_rf_gain_2ghz[IWN4965_MAX_PWR_INDEX + 1] = {
	0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0x3d, 0x3d, 0x3d, 0x3c, 0x3c,
	0x3c, 0x3b, 0x3b, 0x3b, 0x3a, 0x3a, 0x3a, 0x39, 0x39, 0x39, 0x38,
	0x38, 0x38, 0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x35, 0x35, 0x35,
	0x34, 0x34, 0x34, 0x33, 0x33, 0x33, 0x32, 0x32, 0x32, 0x31, 0x31,
	0x31, 0x30, 0x30, 0x30, 0x06, 0x06, 0x06, 0x05, 0x05, 0x05, 0x04,
	0x04, 0x04, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t iwn4965_rf_gain_5ghz[IWN4965_MAX_PWR_INDEX + 1] = {
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0x3d, 0x3d, 0x3d,
	0x3c, 0x3c, 0x3c, 0x3b, 0x3b, 0x3b, 0x3a, 0x3a, 0x3a, 0x39, 0x39,
	0x39, 0x38, 0x38, 0x38, 0x37, 0x37, 0x37, 0x36, 0x36, 0x36, 0x35,
	0x35, 0x35, 0x34, 0x34, 0x34, 0x33, 0x33, 0x33, 0x32, 0x32, 0x32,
	0x31, 0x31, 0x31, 0x30, 0x30, 0x30, 0x25, 0x25, 0x25, 0x24, 0x24,
	0x24, 0x23, 0x23, 0x23, 0x22, 0x18, 0x18, 0x17, 0x17, 0x17, 0x16,
	0x16, 0x16, 0x15, 0x15, 0x15, 0x14, 0x14, 0x14, 0x13, 0x13, 0x13,
	0x12, 0x08, 0x08, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x05, 0x05,
	0x05, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x01,
	0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
 * DSP pre-DAC gain values from highest to lowest power (values obtained
 * from the reference driver.)
 */
static const uint8_t iwn4965_dsp_gain_2ghz[IWN4965_MAX_PWR_INDEX + 1] = {
	0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68,
	0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e,
	0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62,
	0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68,
	0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e,
	0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62,
	0x6e, 0x68, 0x62, 0x61, 0x60, 0x5f, 0x5e, 0x5d, 0x5c, 0x5b, 0x5a,
	0x59, 0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 0x50, 0x4f,
	0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48, 0x47, 0x46, 0x45, 0x44,
	0x43, 0x42, 0x41, 0x40, 0x3f, 0x3e, 0x3d, 0x3c, 0x3b
};

static const uint8_t iwn4965_dsp_gain_5ghz[IWN4965_MAX_PWR_INDEX + 1] = {
	0x7b, 0x75, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62,
	0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68,
	0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e,
	0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62,
	0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68,
	0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e,
	0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62,
	0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68,
	0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e, 0x68, 0x62, 0x6e,
	0x68, 0x62, 0x6e, 0x68, 0x62, 0x5d, 0x58, 0x53, 0x4e
};

/*
 * Power saving settings (values obtained from the reference driver.)
 */
#define IWN_NDTIMRANGES		3
#define IWN_NPOWERLEVELS	6
static const struct iwn_pmgt {
	uint32_t	rxtimeout;
	uint32_t	txtimeout;
	uint32_t	intval[5];
	int		skip_dtim;
} iwn_pmgt[IWN_NDTIMRANGES][IWN_NPOWERLEVELS] = {
	/* DTIM <= 2 */
	{
	{   0,   0, {  0,  0,  0,  0,  0 }, 0 },	/* CAM */
	{ 200, 500, {  1,  2,  2,  2, -1 }, 0 },	/* PS level 1 */
	{ 200, 300, {  1,  2,  2,  2, -1 }, 0 },	/* PS level 2 */
	{  50, 100, {  2,  2,  2,  2, -1 }, 0 },	/* PS level 3 */
	{  50,  25, {  2,  2,  4,  4, -1 }, 1 },	/* PS level 4 */
	{  25,  25, {  2,  2,  4,  6, -1 }, 2 }		/* PS level 5 */
	},
	/* 3 <= DTIM <= 10 */
	{
	{   0,   0, {  0,  0,  0,  0,  0 }, 0 },	/* CAM */
	{ 200, 500, {  1,  2,  3,  4,  4 }, 0 },	/* PS level 1 */
	{ 200, 300, {  1,  2,  3,  4,  7 }, 0 },	/* PS level 2 */
	{  50, 100, {  2,  4,  6,  7,  9 }, 0 },	/* PS level 3 */
	{  50,  25, {  2,  4,  6,  9, 10 }, 1 },	/* PS level 4 */
	{  25,  25, {  2,  4,  7, 10, 10 }, 2 }		/* PS level 5 */
	},
	/* DTIM >= 11 */
	{
	{   0,   0, {  0,  0,  0,  0,  0 }, 0 },	/* CAM */
	{ 200, 500, {  1,  2,  3,  4, -1 }, 0 },	/* PS level 1 */
	{ 200, 300, {  2,  4,  6,  7, -1 }, 0 },	/* PS level 2 */
	{  50, 100, {  2,  7,  9,  9, -1 }, 0 },	/* PS level 3 */
	{  50,  25, {  2,  7,  9,  9, -1 }, 0 },	/* PS level 4 */
	{  25,  25, {  4,  7, 10, 10, -1 }, 0 }		/* PS level 5 */
	}
};

struct iwn_sensitivity_limits {
	uint32_t	min_ofdm_x1;
	uint32_t	max_ofdm_x1;
	uint32_t	min_ofdm_mrc_x1;
	uint32_t	max_ofdm_mrc_x1;
	uint32_t	min_ofdm_x4;
	uint32_t	max_ofdm_x4;
	uint32_t	min_ofdm_mrc_x4;
	uint32_t	max_ofdm_mrc_x4;
	uint32_t	min_cck_x4;
	uint32_t	max_cck_x4;
	uint32_t	min_cck_mrc_x4;
	uint32_t	max_cck_mrc_x4;
	uint32_t	min_energy_cck;
	uint32_t	energy_cck;
	uint32_t	energy_ofdm;
	uint32_t	min_corr_barker_mrc;
};

/*
 * RX sensitivity limits (values obtained from the reference driver.)
 */
static const struct iwn_sensitivity_limits iwn4965_sensitivity_limits = {
	105, 140,
	220, 270,
	 85, 120,
	170, 210,
	125, 200,
	200, 400,
	 97,
	100,
	100,
	390
};

static const struct iwn_sensitivity_limits iwn5000_sensitivity_limits = {
	120, 120,	/* min = max for performance bug in DSP. */
	240, 240,	/* min = max for performance bug in DSP. */
	 90, 120,
	170, 210,
	125, 200,
	170, 400,
	 95,
	 95,
	 95,
	 390
};

static const struct iwn_sensitivity_limits iwn5150_sensitivity_limits = {
	105, 105,	/* min = max for performance bug in DSP. */
	220, 220,	/* min = max for performance bug in DSP. */
	 90, 120,
	170, 210,
	125, 200,
	170, 400,
	 95,
	 95,
	 95,
	 390
};

static const struct iwn_sensitivity_limits iwn1000_sensitivity_limits = {
	120, 155,
	240, 290,
	 90, 120,
	170, 210,
	125, 200,
	170, 400,
	 95,
	 95,
	 95,
	 390
};
min_ofdm_x1;  // auto_corr_min_ofdm_x1 , max_ofdm_x1; //auto_corr_max_ofdm_x1
min_ofdm_mrc_x1; //auto_corr_min_ofdm_mrc_x1, max_ofdm_mrc_x1; //auto_corr_max_ofdm_mrc
min_ofdm_x4; //auto_corr_min_ofdm, max_ofdm_x4; //auto_corr_max_ofdm 
min_ofdm_mrc_x4; //auto_corr_min_ofdm_mrc, max_ofdm_mrc_x4 //max_ofdm_mrc_x4
min_cck_x4; //auto_corr_min_cck, max_cck_x4:auto_corr_max_cck
min_cck_mrc_x4 : auto_corr_min_cck_mrc max_cck_mrc_x4: auto_corr_max_cck_mrc
min_energy_cck: min_nrg_cck
energy_cck:nrg_th_cck
energy_ofdm:nrg_th_ofdm
corr_barker_mrc :barker_corr_th_min_mrc

 /* Define several specific values for Intel 6000 series */
 static const struct iwn_sensitivity_limits iwn6000_sensitivity_limits = {
	105, 110,
	192, 232,
	 80, 145,
	128, 232,
	125, 175,
	160, 310,
	110,
	110,
	110,
	336
};


/* Map TID to TX scheduler's FIFO. */
static const uint8_t iwn_tid2fifo[] = {
	1, 0, 0, 1, 2, 2, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 3
};

/* WiFi/WiMAX coexist event priority table for 6050. */
static const struct iwn5000_wimax_event iwn6050_wimax_events[] = {
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x04, 0x03, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x04, 0x03, 0x00, 0x07 },
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x04, 0x03, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x06, 0x03, 0x00, 0x07 },
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x06, 0x06, 0x00, 0x03 },
	{ 0x04, 0x03, 0x00, 0x07 },
	{ 0x04, 0x03, 0x00, 0x00 },
	{ 0x04, 0x03, 0x00, 0x00 }
};

/* Firmware errors. */
static const char * const iwn_fw_errmsg[] = {
	"OK",
	"FAIL",
	"BAD_PARAM",
	"BAD_CHECKSUM",
	"NMI_INTERRUPT_WDG",
	"SYSASSERT",
	"FATAL_ERROR",
	"BAD_COMMAND",
	"HW_ERROR_TUNE_LOCK",
	"HW_ERROR_TEMPERATURE",
	"ILLEGAL_CHAN_FREQ",
	"VCC_NOT_STABLE",
	"FH_ERROR",
	"NMI_INTERRUPT_HOST",
	"NMI_INTERRUPT_ACTION_PT",
	"NMI_INTERRUPT_UNKNOWN",
	"UCODE_VERSION_MISMATCH",
	"HW_ERROR_ABS_LOCK",
	"HW_ERROR_CAL_LOCK_FAIL",
	"NMI_INTERRUPT_INST_ACTION_PT",
	"NMI_INTERRUPT_DATA_ACTION_PT",
	"NMI_TRM_HW_ER",
	"NMI_INTERRUPT_TRM",
	"NMI_INTERRUPT_BREAKPOINT"
	"DEBUG_0",
	"DEBUG_1",
	"DEBUG_2",
	"DEBUG_3",
	"ADVANCED_SYSASSERT"
};

/* Find least significant bit that is set. */
#define IWN_LSB(x)	((((x) - 1) & (x)) ^ (x))

#define IWN_READ(sc, reg)						\
	bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))

#define IWN_WRITE(sc, reg, val)						\
	bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))

#define IWN_WRITE_1(sc, reg, val)					\
	bus_space_write_1((sc)->sc_st, (sc)->sc_sh, (reg), (val))

#define IWN_SETBITS(sc, reg, mask)					\
	IWN_WRITE(sc, reg, IWN_READ(sc, reg) | (mask))

#define IWN_CLRBITS(sc, reg, mask)					\
	IWN_WRITE(sc, reg, IWN_READ(sc, reg) & ~(mask))

#define IWN_BARRIER_WRITE(sc)						\
	bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\
	    BUS_SPACE_BARRIER_WRITE)

#define IWN_BARRIER_READ_WRITE(sc)					\
	bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\
	    BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE)

		
static const uint32_t iwn2030_regulatory_bands[IWN_NBANDS] = {
	IWN5000_EEPROM_BAND1,
	IWN5000_EEPROM_BAND2,
	IWN5000_EEPROM_BAND3,
	IWN5000_EEPROM_BAND4,
	IWN5000_EEPROM_BAND5,
	IWN6000_EEPROM_BAND6,
	IWN5000_EEPROM_BAND7
};
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
		
		
/* =============================================================================
 *                                  NIC PARAMETERS
 *
 * =============================================================================
 */
 
/* Flags for managing calibration result. See calib_need in iwn_base_params struct */
#define IWN_FLG_NEED_PHY_CALIB_DC				(1<<0)
#define IWN_FLG_NEED_PHY_CALIB_LO				(1<<1)
#define IWN_FLG_NEED_PHY_CALIB_TX_IQ			(1<<2)
#define IWN_FLG_NEED_PHY_CALIB_CRYSTAL			(1<<3)
#define IWN_FLG_NEED_PHY_CALIB_BASE_BAND		(1<<4)
#define IWN_FLG_NEED_PHY_CALIB_TX_IQ_PERIODIC	(1<<5)
#define IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSET		(1<<6)
#define IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSETv2	(1<<7)

		
/* Define some parameters for managing different NIC.
 * Refer to linux specific file like iwl-xxxx.c to determine correct value for NIC
 *
 *
 * @max_ll_items: max number of OTP blocks
 * @shadow_ram_support: shadow support for OTP memory
 * @led_compensation: compensate on the led on/off time per HW according
 *	to the deviation to achieve the desired led frequency.
 *	The detail algorithm is described in iwl-led.c
 * @chain_noise_num_beacons: number of beacons used to compute chain noise
 * @adv_thermal_throttle: support advance thermal throttle
 * @support_ct_kill_exit: support ct kill exit condition
 * @support_wimax_coexist: support wimax/wifi co-exist
 * @plcp_delta_threshold: plcp error rate threshold used to trigger
 *	radio tuning when there is a high receiving plcp error rate
 * @chain_noise_scale: default chain noise scale used for gain computation
 * @wd_timeout: TX queues watchdog timeout
 * @max_event_log_size: size of event log buffer size for ucode event logging
 * @shadow_reg_enable: HW shadhow register bit
 * @no_idle_support: do not support idle mode
 * @hd_v2: v2 of enhanced sensitivity value, used for 2000 series and up
 * advanced_bt_coexist : Advanced BT management
 * bt_session_2 : NIC need a new struct for configure BT coexistence. Needed only if advanced_bt_coexist is true 
 * bt_sco_disable :
 * additional_nic_config: For 6005 series
 * iq_invert : ? But need it for N 2000 series
 * regulatory_bands :
 * enhanced_TX_power : EEPROM Has advanced TX power options. Set 'True' if update_enhanced_txpower = iwl_eeprom_enhanced_txpower 
 * need_temp_offset_calib : Need to compute some temp offset for calibration.
 * calib_need : Use IWN_FLG_NEED_PHY_CALIB_* flags to specify which calibration data ucode need. See calib_init_cfg in iwl-xxxx.c linux kernel file
 * additional_gp_drv_bit : Specific bit to defined during nic_config
 */
struct iwn_base_params {
	uint32_t pll_cfg_val;
	const uint16_t max_ll_items;
#define IWN_OTP_MAX_LL_ITEMS_1000		(3)	/* OTP blocks for 1000 */
#define IWN_OTP_MAX_LL_ITEMS_6x00		(4)	/* OTP blocks for 6x00 */
#define IWN_OTP_MAX_LL_ITEMS_6x50		(7)	/* OTP blocks for 6x50 */
#define IWN_OTP_MAX_LL_ITEMS_2x00		(4)	/* OTP blocks for 2x00 */
	const bool shadow_ram_support;
	uint16_t led_compensation;
	bool adv_thermal_throttle;
	bool support_ct_kill_exit;
	uint8_t plcp_delta_threshold;
	int chain_noise_scale;
	unsigned int wd_timeout;
	uint32_t max_event_log_size;
	const bool shadow_reg_enable;
	const bool hd_v2;
	const bool advanced_bt_coexist;
	const bool bt_session_2;
	const bool bt_sco_disable;
	const bool additional_nic_config;
	const uint32_t *regulatory_bands;
	const bool enhanced_TX_power; // See iwl-agn-devices.c file to determine that(enhanced_txpower). 
	const uint16_t calib_need;
	const bool no_crystal_calibration; // see no_xtal_calib in linux
	const bool support_hostap; //Define IEEE80211_C_HOSTAP for ic_caps
	const bool no_multi_vaps; // see iwn_vap_create
	uint8_t additional_gp_drv_bit; //
	
};

/* NOTA : Values with comments BEFORE are not yet used in driver */
static struct iwn_base_params iwn_default_base_params = {
	IWN_ANA_PLL_INIT, // pll_cfg_val
	4,  //max_ll_items
	true, // shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, // bt_session_2
	true, // bt_sco_disable
	false, //additional_nic_config
	iwn5000_regulatory_bands, //regulatory_bands
	false, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, // no_multi_vaps
	0, //additional_gp_drv_bit
};

static struct iwn_base_params iwn2030_base_params = {
	 0, //pll_cfg_val
	 IWN_OTP_MAX_LL_ITEMS_2x00, //max_ll_items
	 true, //shadow_ram_support
	/*.led_compensation = */ 57,
	/*.adv_thermal_throttle = */ true,
	/*.support_ct_kill_exit = */ true,
	/*.plcp_delta_threshold = */ 50,
	/*.chain_noise_scale = */ 1000,
	/*.wd_timeout = */ 2000,
	/*.max_event_log_size = */ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */ true,
	true, //advanced_bt_coexist
	true, //bt_session_2
	true, //bt_sco_disable
	false, //additional_nic_config
	iwn2030_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND | IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSETv2 ), //calib_need
	false, //no_crystal_calibration
	true, //support_hostap
	false, //no_multi_vaps
	IWN_GP_DRIVER_REG_BIT_RADIO_IQ_INVERT, // additional_gp_drv_bit
};


static struct iwn_base_params iwn_1000_base_params = {
	IWN_ANA_PLL_INIT, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_1000, //max_ll_items
	false, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, //advanced_bt_coexist
	false, //bt_session_2
	false, //bt_sco_disable
	false, //additional_nic_config
	iwn5000_regulatory_bands, //regulatory_bands
	false, //enhanced_TX_power
	( IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_6000_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x00, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, //bt_session_2
	false, //bt_sco_disable
	false, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_6000i_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x00, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, //bt_session_2
	true, //bt_sco_disable
	false, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_6000g2_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x00, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, //bt_session_2
	true, //bt_sco_disable
	false, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND|IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSET ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_6050_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x50, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, //bt_session_2
	true, //bt_sco_disable
	true, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND|IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSET ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_6150_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x50, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, //bt_session_2
	true, //bt_sco_disable
	true, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND|IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSET ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	IWN_GP_DRIVER_6050_1X2, //additional_gp_drv_bit
};
//IWL_DEVICE_6035 & IWL_DEVICE_6030
static struct iwn_base_params iwn_6000g2b_base_params = {
	0, //pll_cfg_val
	IWN_OTP_MAX_LL_ITEMS_6x00, // max_ll_items
	true, //shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	true, // advanced_bt_coexist
	false, //bt_session_2
	true, //bt_sco_disable
	false, //additional_nic_config
	iwn6000_regulatory_bands, //regulatory_bands
	true, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND|IWN_FLG_NEED_PHY_CALIB_TEMP_OFFSET ), //calib_need
	false, //no_crystal_calibration
	false, //support_hostap
	true, //no_multi_vaps
	0, //additional_gp_drv_bit
};
static struct iwn_base_params iwn_5x50_base_params = {
	IWN_ANA_PLL_INIT, // pll_cfg_val
	4,  //max_ll_items
	true, // shadow_ram_support
	/*.led_compensation = */57,
	/*.adv_thermal_throttle =*/ true,
	/*.support_ct_kill_exit = */true,
	/*.plcp_delta_threshold =*/ 50, /*IWL_MAX_PLCP_ERR_THRESHOLD_DEF,*/
	/*.chain_noise_scale =*/ 1000,
	/*.wd_timeout = */2000, /* IWL_LONG_WD_TIMEOUT,*/
	/*.max_event_log_size =*/ 512,
	false, //shadow_reg_enable
	/*.hd_v2 = */true,
	false, // advanced_bt_coexist
	false, // bt_session_2
	true, // bt_sco_disable
	false, //additional_nic_config
	iwn5000_regulatory_bands, //regulatory_bands
	false, //enhanced_TX_power
	(IWN_FLG_NEED_PHY_CALIB_DC | IWN_FLG_NEED_PHY_CALIB_LO | IWN_FLG_NEED_PHY_CALIB_TX_IQ | IWN_FLG_NEED_PHY_CALIB_BASE_BAND ), //calib_need
	true, //no_crystal_calibration
	false, //support_hostap
	true, // no_multi_vaps
	0, //additional_gp_drv_bit
};

