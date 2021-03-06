/*
** Copyright (C) 1999-2013, Broadcom Corporation
** 
**      Unless you and Broadcom execute a separate written software license
** agreement governing use of this software, this software is licensed to you
** under the terms of the GNU General Public License version 2 (the "GPL"),
** available at http://www.broadcom.com/licenses/GPLv2.php, with the
** following added to such license:
** 
**      As a special exception, the copyright holders of this software give you
** permission to link this software with independent modules, and to copy and
** distribute the resulting executable under terms of your choice, provided that
** you also meet, for each linked independent module, the terms and conditions of
** the license of that module.  An independent module is a module which is not
** derived from this software.  The special exception does not apply to any
** modifications of the software.
** 
**      Notwithstanding the above, under no circumstances may you combine this
** software in any way with any other Broadcom software provided under a license
** other than the GPL, without Broadcom's express prior written consent.
**
**   Broadcom Corporation
**   16215 Alton Parkway
**   P.O. Box 57013
**   Irvine, CA  92619-7013
**
** ----------------------------------------------------------
**
**
**  $Id:: ddr_bist.h      $:
**  $Rev::file =  : Global SVN Revision = 1780                    $:
**
*/

#ifndef DDR_BIST_H__
#define DDR_BIST_H__

#include <config.h>
#include "asm/arch/socregs.h"

#define SOC_E_NONE (0)
#define SOC_E_FAIL (-1)
#define SOC_E_INTERNAL (-2)
#define SOC_E_TIMEOUT (-3)
#define SOC_E_PARAM   (-4)
#define SOC_E_MEMORY  (-5)
#define SOC_E_UNAVAIL (-6)
#define SOC_E_CONFIG (-7)
extern uint32_t iproc_get_ddr3_clock_mhz(uint32_t unit);
#define SOC_DDR3_CLOCK_MHZ(unit)	iproc_get_ddr3_clock_mhz(unit)

#if (defined(CONFIG_HELIX4) || defined(CONFIG_KATANA2))
#define DDR_SHMOO_PARAM_MEM_PTR		(0x1b040000) /*size ~0x300 */
#define DDR_SHMOO_VREFW_MEM_PTR		(0x1b041000) /* size ~0x30000 */
#elif defined(CONFIG_HURRICANE2)
#define DDR_SHMOO_PARAM_MEM_PTR		(0x1b000000)
#define DDR_SHMOO_VREFW_MEM_PTR		(0x50000000)
#elif defined(CONFIG_GREYHOUND) || defined(CONFIG_SABER2) || defined(CONFIG_HURRICANE3) \
	|| defined(CONFIG_GREYHOUND2)
#define DDR_SHMOO_PARAM_MEM_PTR   (0x02000000)
#define DDR_SHMOO_VREFW_MEM_PTR   (0x50000000)
#else 
#error "DDR SHMOO memory allocation pointers are not set"
#endif

#if (defined(CONFIG_HELIX4) || defined(CONFIG_KATANA2))
#define SOC_DDR3_NUM_MEMORIES		(2)
#elif defined(CONFIG_HURRICANE2)
#define SOC_DDR3_NUM_MEMORIES		(1)
#elif defined(CONFIG_GREYHOUND) || defined(CONFIG_SABER2) || defined(CONFIG_HURRICANE3) \
	|| defined(CONFIG_GREYHOUND2)
#define SOC_DDR3_NUM_MEMORIES   (1)
#else
#error "Number of DRAM memory chips must be defined"
#endif

/* Convenience Macros - Arad Memory Controller - Recheck when MemC files change */
enum drc_reg_set {
	DRC_BIST_CONFIGr = 0,
	DRC_BIST_CONFIG2r,
	DRC_BIST_GENERAL_CONFIGURATIONSr,
    DRC_BIST_CONFIGURATIONSr,
    DRC_BIST_NUMBER_OF_ACTIONSr,
    DRC_BIST_START_ADDRESSr,
    DRC_BIST_END_ADDRESSr,
    DRC_BIST_SINGLE_BIT_MASKr,
    DRC_BIST_PATTERN_WORD_7r,
    DRC_BIST_PATTERN_WORD_6r,
	DRC_BIST_PATTERN_WORD_5r,
    DRC_BIST_PATTERN_WORD_4r,
    DRC_BIST_PATTERN_WORD_3r,
    DRC_BIST_PATTERN_WORD_2r,
    DRC_BIST_PATTERN_WORD_1r,
	DRC_BIST_PATTERN_WORD_0r,
    DRC_BIST_FULL_MASK_WORD_7r,
    DRC_BIST_FULL_MASK_WORD_6r,
    DRC_BIST_FULL_MASK_WORD_5r,
    DRC_BIST_FULL_MASK_WORD_4r,
    DRC_BIST_FULL_MASK_WORD_3r,
	DRC_BIST_FULL_MASK_WORD_2r,
    DRC_BIST_FULL_MASK_WORD_1r,
	DRC_BIST_FULL_MASK_WORD_0r,
    DRC_BIST_STATUSESr,
    DRC_BIST_FULL_MASK_ERROR_COUNTERr,
    DRC_BIST_SINGLE_BIT_MASK_ERROR_COUNTERr,
	DRC_BIST_ERROR_OCCURREDr,
    DRC_BIST_GLOBAL_ERROR_COUNTERr,
    DRC_BIST_LAST_ADDR_ERRr,
    DRC_BIST_LAST_DATA_ERR_WORD_7r,
	DRC_BIST_LAST_DATA_ERR_WORD_6r,
	DRC_BIST_LAST_DATA_ERR_WORD_5r,
	DRC_BIST_LAST_DATA_ERR_WORD_4r,
	DRC_BIST_LAST_DATA_ERR_WORD_3r,
	DRC_BIST_LAST_DATA_ERR_WORD_2r,
	DRC_BIST_LAST_DATA_ERR_WORD_1r,
	DRC_BIST_LAST_DATA_ERR_WORD_0r
};



#define DRCA     DDR_BistConfig
#define DRCB     DDR_BistConfig
#define DRCC     DDR_BistConfig
#define DRCD     DDR_BistConfig
#define DRCE     DDR_BistConfig
#define DRCF     DDR_BistConfig
#define DRCG     DDR_BistConfig
#define DRCH     DDR_BistConfig
#define DRCALL   DDR_BistConfig

#define DRCA_BIST_CONFIGURATIONSr_RESERVEDf_SHIFT 26
#define DRCA_BIST_CONFIGURATIONSr_RESERVEDf_WIDTH 6
#define DRCA_BIST_CONFIGURATIONSr_BIST_ENf_SHIFT 25
#define DRCA_BIST_CONFIGURATIONSr_BIST_ENf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_DATA_ADDR_MODEf_SHIFT 24
#define DRCA_BIST_CONFIGURATIONSr_DATA_ADDR_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_DATA_SHIFT_MODEf_SHIFT 23
#define DRCA_BIST_CONFIGURATIONSr_DATA_SHIFT_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_ADDRESS_SHIFT_MODEf_SHIFT 22
#define DRCA_BIST_CONFIGURATIONSr_ADDRESS_SHIFT_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_CONS_ADDR_8_BANKSf_SHIFT 21
#define DRCA_BIST_CONFIGURATIONSr_CONS_ADDR_8_BANKSf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_CONS_ADDR_4_BANKSf_SHIFT 20
#define DRCA_BIST_CONFIGURATIONSr_CONS_ADDR_4_BANKSf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_IND_WR_RD_ADDR_MODEf_SHIFT 19
#define DRCA_BIST_CONFIGURATIONSr_IND_WR_RD_ADDR_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_PRBS_MODEf_SHIFT 18
#define DRCA_BIST_CONFIGURATIONSr_PRBS_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_TWO_ADDR_MODEf_SHIFT 17
#define DRCA_BIST_CONFIGURATIONSr_TWO_ADDR_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_PATTERN_BIT_MODEf_SHIFT 16
#define DRCA_BIST_CONFIGURATIONSr_PATTERN_BIT_MODEf_WIDTH 1
#define DRCA_BIST_CONFIGURATIONSr_READ_WEIGHTf_SHIFT 8
#define DRCA_BIST_CONFIGURATIONSr_READ_WEIGHTf_WIDTH 8
#define DRCA_BIST_CONFIGURATIONSr_WRITE_WEIGHTf_SHIFT 0
#define DRCA_BIST_CONFIGURATIONSr_WRITE_WEIGHTf_WIDTH 8

#define DRCA_BIST_NUMBER_OF_ACTIONSr_BIST_NUM_ACTIONSf_SHIFT 0
#define DRCA_BIST_NUMBER_OF_ACTIONSr_BIST_NUM_ACTIONSf_WIDTH 32


#define DRCA_BIST_START_ADDRESSr_BIST_START_ADDRESSf_SHIFT 0
#define DRCA_BIST_START_ADDRESSr_BIST_START_ADDRESSf_WIDTH 26
#define DRCA_BIST_START_ADDRESSr_RESERVED_SHIFT 26
#define DRCA_BIST_START_ADDRESSr_RESERVED_WIDTH 6

#define DRCA_BIST_END_ADDRESSr_BIST_END_ADDRESSf_SHIFT 0
#define DRCA_BIST_END_ADDRESSr_BIST_END_ADDRESSf_WIDTH 26
#define DRCA_BIST_END_ADDRESSr_RESERVED_SHIFT 26
#define DRCA_BIST_END_ADDRESSr_RESERVED_WIDTH 6

#define DRCA_BIST_STATUSESr_RESERVED_SHIFT 4
#define DRCA_BIST_STATUSESr_RESERVED_WIDTH 28
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_RADDRf_SHIFT 3
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_RADDRf_WIDTH 1
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_CMDf_SHIFT 2
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_CMDf_WIDTH 1
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_WDATAf_SHIFT 1
#define DRCA_BIST_STATUSESr_OVERFLOW_FIFO_WDATAf_WIDTH 1
#define DRCA_BIST_STATUSESr_BIST_FINISHEDf_SHIFT 0
#define DRCA_BIST_STATUSESr_BIST_FINISHEDf_WIDTH 1

#define DRCA_BIST_ERROR_OCCURREDr_ERR_OCCURREDf_SHIFT 0
#define DRCA_BIST_ERROR_OCCURREDr_ERR_OCCURREDf_WIDTH 32


#define soc_reg_field_set(unit, r, m, f, data) \
	*(m) = ((*(m) & ~(((1 << r##_##f##_WIDTH) -1) << r##_##f##_SHIFT)) | ((data & ((1 << r##_##f##_WIDTH) -1)) << r##_##f##_SHIFT))


#define soc_reg_field_get(unit, r, m, f) \
		((m >> r##_##f##_SHIFT) & ((1 << r##_##f##_WIDTH) -1))


#define DRC_REG_READ(unit, channel, reg, rvp) \
	soc_reg32_get((volatile uint32 *)(channel + 4 * reg), rvp)

#define DRC_REG_WRITE(unit, channel, reg, rv) \
	soc_reg32_set((volatile uint32 *)(channel + 4 * reg), rv)

#endif /* #ifndef DDR_BIST_H__*/

/* End of File */
