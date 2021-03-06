/*
 * Copyright (C) 2013, Broadcom Corporation. All Rights Reserved.
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 
#ifndef __SOCREGS_H
#define __SOCREGS_H

#define ICFG_CHIP_ID_REG                                    0x18000000
#define ICFG_CHIP_REVISION_ID                               0x18000004
#define ICFG_PNOR_CONFIG_CS_0                               0x18000a50
#define ICFG_PNOR_CONFIG_CS_1                               0x18000a54
#define CMIC_DEV_REV_ID                                     0x03210224

#define DMU_PCU_IPROC_STRAPS_CAPTURED                       0x1800f028
#define DMU_PCU_IPROC_STRAPS_CAPTURED__strap_boot_dev_R     9
#define DMU_PCU_IPROC_STRAPS_CAPTURED__strap_nand_type_R    5
#define DMU_PCU_IPROC_STRAPS_CAPTURED__strap_nand_page_R    3

#define NAND_IDM_IDM_IO_CONTROL_DIRECT                      0xf8105408
#define NAND_nand_flash_INTFC_STATUS                        0x18046014
#define NAND_ro_ctlr_ready                                  0x18046f10
#define NAND_nand_flash_CMD_ADDRESS                         0x1804600c
#define NAND_nand_flash_CMD_EXT_ADDRESS                     0x18046008
#define NAND_nand_flash_INIT_STATUS                         0x18046144
#define NAND_nand_flash_FLASH_DEVICE_ID                     0x18046194
#define NAND_nand_flash_ONFI_STATUS                         0x18046148
#define NAND_nand_flash_CONFIG_CS1                          0x18046064
#define NAND_nand_flash_CONFIG_CS0                          0x18046054
#define NAND_nand_flash_ACC_CONTROL_CS1                     0x18046060
#define NAND_nand_flash_ACC_CONTROL_CS0                     0x18046050
#define NAND_nand_flash_FLASH_CACHE0                        0x18046400
#define NAND_nand_flash_ECC_UNC_ADDR                        0x18046118
#define NAND_nand_flash_CS_NAND_SELECT                      0x18046018
#define NAND_nand_flash_SPARE_AREA_READ_OFS_0               0x18046200
#define NAND_nand_flash_SPARE_AREA_WRITE_OFS_0              0x18046280
#define NAND_nand_flash_FLASH_DEVICE_ID_EXT                 0x18046198
#define NAND_nand_flash_CMD_START                           0x18046004
#define NAND_nand_flash_UNCORR_ERROR_COUNT                  0x180460fc
#define NAND_IDM_IDM_RESET_CONTROL                          0xf8105800

#define QSPI_bspi_registers_REVISION_ID                     0x18047000
#define CRU_control                                         0x1800e000

#define ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL                   0x18000c8c
#define ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL__iproc_pnor_sel            1
#define ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL__iproc_pnor_sel_sw_ovwr    0
#define ICFG_PNOR_STRAPS                                    0x18000a5c
#define ICFG_PNOR_STRAPS__PNOR_SRAM_MW_R                    0
#define PNOR_set_opmode                                     0x18045018
#define PNOR_set_opmode__set_mw_R                           0
#define PNOR_direct_cmd                                     0x18045010
#define PNOR_direct_cmd__cmd_type_R                         21

#define DMU_CRU_RESET                                       0x1800f200

#define DDR_S0_IDM_RESET_CONTROL                            0xf8101800
#define DDR_S1_IDM_IO_CONTROL_DIRECT                        0xf8102408
#define DDR_S1_IDM_IO_STATUS                                0xf8102500
#define DDR_S1_IDM_IO_STATUS__o_phy_ready                   2
#define DDR_S1_IDM_IO_STATUS__o_phy_pwrup_rsb               3
#define DDR_S1_IDM_RESET_CONTROL                            0xf8102800
#define DDR_S2_IDM_RESET_CONTROL                            0xf8103800
#define DDR_S2_IDM_IO_CONTROL_DIRECT                        0xf8103408
#define DDR_S2_IDM_IO_CONTROL_DIRECT__mode_32b              1
#define ROM_S0_IDM_IO_STATUS                                0xf8104500

#define DDR_BistConfig                                      0x18010c00
#define DDR_BistConfig__axi_port_sel                        1
#define DDR_BistGeneralConfigurations                       0x18010c08
#define DDR_BistConfigurations                              0x18010c0c
#define DDR_BistConfigurations__WriteWeight_R               0
#define DDR_BistConfigurations__ReadWeight_R                8
#define DDR_BistConfigurations__IndWrRdAddrMode             19
#define DDR_BistConfigurations__ConsAddr8Banks              21
#define DDR_BistConfigurations__BistEn                      25
#define DDR_BistNumberOfActions                             0x18010c10
#define DDR_BistStartAddress                                0x18010c14
#define DDR_BistEndAddress                                  0x18010c18
#define DDR_BistEndAddress__BistEndAddress_WIDTH            26
#define DDR_BistPatternWord7                                0x18010c20
#define DDR_BistPatternWord6                                0x18010c24
#define DDR_BistPatternWord5                                0x18010c28
#define DDR_BistPatternWord4                                0x18010c2c
#define DDR_BistPatternWord3                                0x18010c30
#define DDR_BistPatternWord2                                0x18010c34
#define DDR_BistPatternWord1                                0x18010c38
#define DDR_BistPatternWord0                                0x18010c3c
#define DDR_BistStatuses                                    0x18010c60
#define DDR_BistStatuses__BistFinished                      0
#define DDR_BistErrorOccurred                               0x18010c6c

#define DDR_DENALI_CTL_00                                   0x18010000
#define DDR_DENALI_CTL_146                                  0x18010248
#define DDR_DENALI_CTL_146__ECC_EN                          0
#define DDR_DENALI_CTL_148                                  0x18010250
#define DDR_DENALI_CTL_148__ECC_DISABLE_W_UC_ERR            0
#define DDR_DENALI_CTL_175                                  0x180102bc
#define DDR_DENALI_CTL_177                                  0x180102c4
#define DDR_DENALI_CTL_177_ECC_MASK                         0x78

#define CRU_ddrphy_pwr_ctrl                                 0x1800e024
#define CRU_ddrphy_pwr_ctrl__i_hw_reset_n                   5
#define CRU_ddrphy_pwr_ctrl__i_pwrokin_phy                  4
#define CRU_ddrphy_pwr_ctrl__i_pwronin_phy                  3
#define CRU_ddrphy_pwr_ctrl__i_iso_phy_dfi                  2
#define CRU_ddrphy_pwr_ctrl__i_iso_phy_regs                 1
#define CRU_ddrphy_pwr_ctrl__i_iso_phy_pll                  0

#define DDR_PHY_CONTROL_REGS_REVISION                       0x18011000
#define DDR_PHY_CONTROL_REGS_PLL_CONTROL1                   0x1801100C
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS                   0x18011018
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__MDIV_R           20
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__MDIV_WIDTH       8
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__PDIV_R           12
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__PDIV_WIDTH       4
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__NDIV_INT_R       0
#define DDR_PHY_CONTROL_REGS_PLL_DIVIDERS__NDIV_INT_WIDTH   10

#define DDR_PHY_BYTE_LANE_0_READ_CONTROL                    0x180114b0
#define DDR_PHY_BYTE_LANE_0_RD_EN_DLY_CYC                   0x180114a0
#define DDR_PHY_BYTE_LANE_0_READ_FIFO_STATUS                0x180114c0
#define DDR_PHY_BYTE_LANE_0_READ_FIFO_CLEAR                 0x180114c4
#define DDR_PHY_BYTE_LANE_0_ODT_CONTROL                     0x180114e0
#define DDR_PHY_BYTE_LANE_1_READ_CONTROL                    0x180116b0
#define DDR_PHY_BYTE_LANE_1_RD_EN_DLY_CYC                   0x180116a0
#define DDR_PHY_BYTE_LANE_1_READ_FIFO_STATUS                0x180116c0
#define DDR_PHY_BYTE_LANE_1_READ_FIFO_CLEAR                 0x180116c4
#define DDR_PHY_BYTE_LANE_1_ODT_CONTROL                     0x180116e0
#define DDR_PHY_BYTE_LANE_2_READ_CONTROL                    0x180118b0
#define DDR_PHY_BYTE_LANE_2_RD_EN_DLY_CYC                   0x180118a0
#define DDR_PHY_BYTE_LANE_2_READ_FIFO_STATUS                0x180118c0
#define DDR_PHY_BYTE_LANE_2_READ_FIFO_CLEAR                 0x180118c4
#define DDR_PHY_BYTE_LANE_2_ODT_CONTROL                     0x180118e0
#define DDR_PHY_BYTE_LANE_3_READ_CONTROL                    0x18011ab0
#define DDR_PHY_BYTE_LANE_3_RD_EN_DLY_CYC                   0x18011aa0
#define DDR_PHY_BYTE_LANE_3_READ_FIFO_STATUS                0x18011ac0
#define DDR_PHY_BYTE_LANE_3_READ_FIFO_CLEAR                 0x18011ac4
#define DDR_PHY_BYTE_LANE_3_ODT_CONTROL                     0x18011ae0

#define IPROC_WRAP_GEN_PLL_CTRL0                            0x1800fc00
#define IPROC_WRAP_GEN_PLL_CTRL0__FAST_LOCK                 25
#define IPROC_WRAP_GEN_PLL_CTRL1                            0x1800fc04
#define IPROC_WRAP_GEN_PLL_CTRL1__PDIV_R                    10
#define IPROC_WRAP_GEN_PLL_CTRL1__PDIV_WIDTH                4
#define IPROC_WRAP_GEN_PLL_CTRL1__NDIV_INT_R                0
#define IPROC_WRAP_GEN_PLL_CTRL1__NDIV_INT_WIDTH            10
#define IPROC_WRAP_GEN_PLL_CTRL2                            0x1800fc08
#define IPROC_WRAP_GEN_PLL_CTRL2__CH3_MDIV_R                8
#define IPROC_WRAP_GEN_PLL_CTRL2__CH3_MDIV_WIDTH            8
#define IPROC_WRAP_GEN_PLL_CTRL2__CH4_MDIV_R                16
#define IPROC_WRAP_GEN_PLL_CTRL3                            0x1800fc0c
#define IPROC_WRAP_GEN_PLL_CTRL3__LOAD_EN_CH_R              16
#define IPROC_WRAP_GEN_PLL_CTRL3__SW_TO_GEN_PLL_LOAD        28
#define IPROC_WRAP_GEN_PLL_STATUS                           0x1800fc18
#define IPROC_WRAP_GEN_PLL_STATUS__GEN_PLL_LOCK             0
#define IPROC_WRAP_IPROC_XGPLL_CTRL_1                       0x1800fc20
#define IPROC_WRAP_IPROC_XGPLL_CTRL_3                       0x1800fc28
#define IPROC_WRAP_IPROC_XGPLL_CTRL_5                       0x1800fc30
#define IPROC_WRAP_IPROC_XGPLL_CTRL_7                       0x1800fc38
#define IPROC_WRAP_IPROC_XGPLL_STATUS                       0x1800fc40
#define IPROC_WRAP_USBPHY_CTRL_0                            0x1800fc44
#define IPROC_WRAP_USBPHY_CTRL_0__PHY_IDDQ_R                26
#define IPROC_WRAP_USBPHY_CTRL_0__PLL_RESETB                25
#define IPROC_WRAP_USBPHY_CTRL_0__RESETB                    24
#define IPROC_WRAP_USBPHY_CTRL_2                            0x1800fc4c
#define IPROC_WRAP_USBPHY_CTRL_2__PHY_ISO                   17
#define IPROC_WRAP_USBPHY_CTRL_2__P1CTL_R                   0
#define IPROC_WRAP_USBPHY_CTRL_3                            0x1800fc50
#define IPROC_WRAP_USBPHY_CTRL_3__LDO_PWRDWN_B              24
#define IPROC_WRAP_USBPHY_CTRL_4                            0x1800fc54
#define IPROC_WRAP_USBPHY_CTRL_4__BG_PWRDWN_B               17
#define IPROC_WRAP_MISC_STATUS                              0x1800fc58
#define IPROC_WRAP_MISC_STATUS__USBPHY_LDO_ON_FLAG          2
#define IPROC_WRAP_MISC_STATUS__USBPHY_PLL_LOCK             1
#define IPROC_WRAP_TOP_STRAP_STATUS                         0x1800fca4
#define IPROC_WRAP_TOP_STRAP_STATUS_1                       0x1800fca8
#define USBH_Utmi_p0Ctl                                     0x18049510

#define IHOST_PROC_CLK_WR_ACCESS                            0x19000000
#define IHOST_PROC_CLK_POLICY_FREQ                          0x19000008
#define IHOST_PROC_CLK_POLICY_FREQ__policy0_freq_R          0
#define IHOST_PROC_CLK_POLICY_FREQ__policy1_freq_R          8
#define IHOST_PROC_CLK_POLICY_FREQ__policy2_freq_R          16
#define IHOST_PROC_CLK_POLICY_FREQ__policy3_freq_R          24
#define IHOST_PROC_CLK_POLICY_FREQ__priv_access_mode        31
#define IHOST_PROC_CLK_POLICY_CTL                           0x1900000c
#define IHOST_PROC_CLK_POLICY_CTL__GO                       0
#define IHOST_PROC_CLK_POLICY_CTL__GO_AC                    1
#define IHOST_PROC_CLK_PLLARMA                              0x19000c00
#define IHOST_PROC_CLK_PLLARMA__pllarm_soft_resetb          0
#define IHOST_PROC_CLK_PLLARMA__pllarm_soft_post_resetb     1
#define IHOST_PROC_CLK_PLLARMA__pllarm_ndiv_int_R           8
#define IHOST_PROC_CLK_PLLARMA__pllarm_pdiv_R               24
#define IHOST_PROC_CLK_PLLARMA__pllarm_lock                 28
#define IHOST_PROC_CLK_PLLARMB                              0x19000c04
#define IHOST_PROC_CLK_PLLARMB__pllarm_ndiv_frac_R          0
#define IHOST_PROC_CLK_PLLARMB__pllarm_ndiv_frac_WIDTH      20
#define IHOST_PROC_CLK_PLLARMC                              0x19000c08
#define IHOST_PROC_CLK_PLLARMCTRL5                          0x19000c20
#define IHOST_PROC_CLK_CORE0_CLKGATE                        0x19000200
#define IHOST_PROC_CLK_CORE1_CLKGATE                        0x19000204
#define IHOST_PROC_CLK_ARM_SWITCH_CLKGATE                   0x19000210
#define IHOST_PROC_CLK_ARM_PERIPH_CLKGATE                   0x19000300
#define IHOST_PROC_CLK_APB0_CLKGATE                         0x19000400

#define IHOST_SCU_INVALIDATE_ALL                            0x1902000c
#define IHOST_SCU_CONTROL                                   0x19020000
#define IHOST_L2C_CACHE_ID                                  0x19022000

#define GMAC0_DEVCONTROL                                    0x18042000

#define AMAC_IDM0_IO_CONTROL_DIRECT                         0x18110408
#define AMAC_IDM0_IO_CONTROL_DIRECT__CLK_250_SEL            6
#define AMAC_IDM0_IO_CONTROL_DIRECT__DIRECT_GMII_MODE       5
#define AMAC_IDM0_IO_CONTROL_DIRECT__DEST_SYNC_MODE_EN      3
#define AMAC_IDM0_IDM_RESET_CONTROL                         0x18110800

/* USB */
#define USB2_IDM_IDM_IO_CONTROL_DIRECT                      0x18115408
#define USB2_IDM_IDM_IO_CONTROL_DIRECT__Bypass_CT           29
#define USB2_IDM_IDM_IO_CONTROL_DIRECT__CT                  28
#define USB2_IDM_IDM_IO_CONTROL_DIRECT__arcache_R           6
#define USB2_IDM_IDM_IO_CONTROL_DIRECT__awcache_R           2
#define USB2_IDM_IDM_IO_CONTROL_DIRECT__clk_enable          0
#define USB2_IDM_IDM_RESET_CONTROL                          0x18115800
#define USB2_IDM_IDM_RESET_CONTROL__RESET                   0

#define USBH_HCCAPBASE                                      0x18048000
#define USBH_Phy_Ctrl_P0                                    0x18049200
#define USBH_Phy_Ctrl_P0__PHY_PLL_Power_Down_R              0
#define USBH_Phy_Ctrl_P0__PHY_Test_port_UTMI_Power_Down_R   2
#define USBH_Phy_Ctrl_P0__PHY_Test_port_Power_Down_R        4
#define USBH_Phy_Ctrl_P0__PHY_Soft_Reset_R                  6
#define USBH_Phy_Ctrl_P0__Core_Reset                        8
#define USBH_Phy_Ctrl_P0__Phy_Hard_Reset                    9


/* GPIO */
#define ChipcommonG_GP_DATA_OUT                             0x1800a004
#define ChipcommonG_GP_OUT_EN                               0x1800a008


/* SRAB */
#define ChipcommonG_SRAB_CMDSTAT                            0x1800702c
#define ChipcommonG_SRAB_WDH                                0x18007030
#define ChipcommonG_SRAB_WDL                                0x18007034
#define ChipcommonG_SRAB_RDH                                0x18007038
#define ChipcommonG_SRAB_RDL                                0x1800703c
#define ChipcommonG_SRAB_SW_IF                              0x18007040

#define CMIC_OVERRIDE_STRAP  0x3210234
#define CMIC_OVERRIDE_STRAP__ENABLE_OVERRIDE_I2C_MASTER_SLAVE_MODE 4
#define CMIC_OVERRIDE_STRAP__I2C_MASTER_SLAVE_MODE 1

#define TOP_UC_TAP_CONTROL                                  0x02075000
#define TOP_UC_TAP_WRITE_DATA                               0x02075400
#define TOP_MISC_CONTROL_3                                  0x02079a00

/* CMIC CMC2 */
#define CMIC_SBUS_RING_MAP_0_7                              0x03210098
#define CMIC_SBUS_RING_MAP_8_15                             0x0321009C
#define CMIC_SBUS_RING_MAP_16_23                            0x032100A0
#define CMIC_SBUS_RING_MAP_24_31                            0x032100A4
#define CMIC_CMC2_SCHAN_CTRL                                0x03233000
#define CMIC_CMC2_SCHAN_MESSAGE0                            0x0323300C
#define CMIC_CMC2_SCHAN_MESSAGE1                            0x03233010
#define CMIC_CMC2_SCHAN_MESSAGE2                            0x03233014

#define CMIC_CMC2_MIIM_PARAM 0x3233080
#define CMIC_CMC2_MIIM_PARAM_BASE 0x080
#define CMIC_CMC2_MIIM_PARAM__MIIM_CYCLE_L 31
#define CMIC_CMC2_MIIM_PARAM__MIIM_CYCLE_R 29
#define CMIC_CMC2_MIIM_PARAM__MIIM_CYCLE_WIDTH 3
#define CMIC_CMC2_MIIM_PARAM__MIIM_CYCLE_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_PARAM__INTERNAL_SEL 25
#define CMIC_CMC2_MIIM_PARAM__INTERNAL_SEL_WIDTH 1
#define CMIC_CMC2_MIIM_PARAM__INTERNAL_SEL_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_PARAM__BUS_ID_L 24
#define CMIC_CMC2_MIIM_PARAM__BUS_ID_R 22
#define CMIC_CMC2_MIIM_PARAM__BUS_ID_WIDTH 3
#define CMIC_CMC2_MIIM_PARAM__BUS_ID_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_PARAM__C45_SEL 21
#define CMIC_CMC2_MIIM_PARAM__C45_SEL_WIDTH 1
#define CMIC_CMC2_MIIM_PARAM__C45_SEL_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_PARAM__PHY_ID_L 20
#define CMIC_CMC2_MIIM_PARAM__PHY_ID_R 16
#define CMIC_CMC2_MIIM_PARAM__PHY_ID_WIDTH 5
#define CMIC_CMC2_MIIM_PARAM__PHY_ID_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_PARAM__PHY_DATA_L 15
#define CMIC_CMC2_MIIM_PARAM__PHY_DATA_R 0
#define CMIC_CMC2_MIIM_PARAM__PHY_DATA_WIDTH 16
#define CMIC_CMC2_MIIM_PARAM__PHY_DATA_RESETVALUE 0x0000
#define CMIC_CMC2_MIIM_PARAM__RESERVED_L 28
#define CMIC_CMC2_MIIM_PARAM__RESERVED_R 26
#define CMIC_CMC2_MIIM_PARAM_WIDTH 32
#define CMIC_CMC2_MIIM_PARAM__WIDTH 32
#define CMIC_CMC2_MIIM_PARAM_ALL_L 31
#define CMIC_CMC2_MIIM_PARAM_ALL_R 0
#define CMIC_CMC2_MIIM_PARAM__ALL_L 31
#define CMIC_CMC2_MIIM_PARAM__ALL_R 0
#define CMIC_CMC2_MIIM_PARAM_DATAMASK 0xe3ffffff
#define CMIC_CMC2_MIIM_PARAM_RDWRMASK 0x1c000000
#define CMIC_CMC2_MIIM_PARAM_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_READ_DATA 0x48033084
#define CMIC_CMC2_MIIM_READ_DATA_BASE 0x084
#define CMIC_CMC2_MIIM_READ_DATA__DATA_L 15
#define CMIC_CMC2_MIIM_READ_DATA__DATA_R 0
#define CMIC_CMC2_MIIM_READ_DATA__DATA_WIDTH 16
#define CMIC_CMC2_MIIM_READ_DATA__DATA_RESETVALUE 0x0000
#define CMIC_CMC2_MIIM_READ_DATA__RESERVED_L 31
#define CMIC_CMC2_MIIM_READ_DATA__RESERVED_R 16
#define CMIC_CMC2_MIIM_READ_DATA_WIDTH 16
#define CMIC_CMC2_MIIM_READ_DATA__WIDTH 16
#define CMIC_CMC2_MIIM_READ_DATA_ALL_L 15
#define CMIC_CMC2_MIIM_READ_DATA_ALL_R 0
#define CMIC_CMC2_MIIM_READ_DATA__ALL_L 15
#define CMIC_CMC2_MIIM_READ_DATA__ALL_R 0
#define CMIC_CMC2_MIIM_READ_DATA_DATAMASK 0x0000ffff
#define CMIC_CMC2_MIIM_READ_DATA_RDWRMASK 0xffff0000
#define CMIC_CMC2_MIIM_READ_DATA_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_ADDRESS 0x48033088
#define CMIC_CMC2_MIIM_ADDRESS_BASE 0x088
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_DTYPE_L 20
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_DTYPE_R 16
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_DTYPE_WIDTH 5
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_DTYPE_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_REGADR_L 15
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_REGADR_R 0
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_REGADR_WIDTH 16
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_45_REGADR_RESETVALUE 0x0000
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_22_REGADR_L 4
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_22_REGADR_R 0
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_22_REGADR_WIDTH 5
#define CMIC_CMC2_MIIM_ADDRESS__CLAUSE_22_REGADR_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_ADDRESS__RESERVED_L 31
#define CMIC_CMC2_MIIM_ADDRESS__RESERVED_R 21
#define CMIC_CMC2_MIIM_ADDRESS_WIDTH 21
#define CMIC_CMC2_MIIM_ADDRESS__WIDTH 21
#define CMIC_CMC2_MIIM_ADDRESS_ALL_L 20
#define CMIC_CMC2_MIIM_ADDRESS_ALL_R 0
#define CMIC_CMC2_MIIM_ADDRESS__ALL_L 20
#define CMIC_CMC2_MIIM_ADDRESS__ALL_R 0
#define CMIC_CMC2_MIIM_ADDRESS_DATAMASK 0x001fffff
#define CMIC_CMC2_MIIM_ADDRESS_RDWRMASK 0xffe00000
#define CMIC_CMC2_MIIM_ADDRESS_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_CTRL 0x4803308c
#define CMIC_CMC2_MIIM_CTRL_BASE 0x08c
#define CMIC_CMC2_MIIM_CTRL__MIIM_RD_START 1
#define CMIC_CMC2_MIIM_CTRL__MIIM_RD_START_WIDTH 1
#define CMIC_CMC2_MIIM_CTRL__MIIM_RD_START_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_CTRL__MIIM_WR_START 0
#define CMIC_CMC2_MIIM_CTRL__MIIM_WR_START_WIDTH 1
#define CMIC_CMC2_MIIM_CTRL__MIIM_WR_START_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_CTRL__RESERVED_L 31
#define CMIC_CMC2_MIIM_CTRL__RESERVED_R 2
#define CMIC_CMC2_MIIM_CTRL_WIDTH 2
#define CMIC_CMC2_MIIM_CTRL__WIDTH 2
#define CMIC_CMC2_MIIM_CTRL_ALL_L 1
#define CMIC_CMC2_MIIM_CTRL_ALL_R 0
#define CMIC_CMC2_MIIM_CTRL__ALL_L 1
#define CMIC_CMC2_MIIM_CTRL__ALL_R 0
#define CMIC_CMC2_MIIM_CTRL_DATAMASK 0x00000003
#define CMIC_CMC2_MIIM_CTRL_RDWRMASK 0xfffffffc
#define CMIC_CMC2_MIIM_CTRL_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_STAT 0x48033090
#define CMIC_CMC2_MIIM_STAT_BASE 0x090
#define CMIC_CMC2_MIIM_STAT__MIIM_OPN_DONE 0
#define CMIC_CMC2_MIIM_STAT__MIIM_OPN_DONE_WIDTH 1
#define CMIC_CMC2_MIIM_STAT__MIIM_OPN_DONE_RESETVALUE 0x0
#define CMIC_CMC2_MIIM_STAT__RESERVED_L 31
#define CMIC_CMC2_MIIM_STAT__RESERVED_R 1
#define CMIC_CMC2_MIIM_STAT_WIDTH 1
#define CMIC_CMC2_MIIM_STAT__WIDTH 1
#define CMIC_CMC2_MIIM_STAT_ALL_L 0
#define CMIC_CMC2_MIIM_STAT_ALL_R 0
#define CMIC_CMC2_MIIM_STAT__ALL_L 0
#define CMIC_CMC2_MIIM_STAT__ALL_R 0
#define CMIC_CMC2_MIIM_STAT_DATAMASK 0x00000001
#define CMIC_CMC2_MIIM_STAT_RDWRMASK 0xfffffffe
#define CMIC_CMC2_MIIM_STAT_RESETVALUE 0x0
 
#endif /* __SOCREGS_H */
