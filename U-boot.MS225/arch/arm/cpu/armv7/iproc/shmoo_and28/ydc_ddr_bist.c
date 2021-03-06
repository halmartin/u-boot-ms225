/*
 * Copyright (C) 1999-2013, Broadcom Corporation
 * 
 *      Unless you and Broadcom execute a separate written software license
 * agreement governing use of this software, this software is licensed to you
 * under the terms of the GNU General Public License version 2 (the "GPL"),
 * available at http://www.broadcom.com/licenses/GPLv2.php, with the
 * following added to such license:
 * 
 *      As a special exception, the copyright holders of this software give you
 * permission to link this software with independent modules, and to copy and
 * distribute the resulting executable under terms of your choice, provided that
 * you also meet, for each linked independent module, the terms and conditions of
 * the license of that module.  An independent module is a module which is not
 * derived from this software.  The special exception does not apply to any
 * modifications of the software.
 * 
 *      Notwithstanding the above, under no circumstances may you combine this
 * software in any way with any other Broadcom software provided under a license
 * other than the GPL, without Broadcom's express prior written consent.
 * $Id: shmoo_and28.c,v 1.1.1.1 2014/05/05 07:55:34 Exp $
 * $Copyright: (c) 2013 Broadcom Corp.
 * All Rights Reserved.$
 *
 * Andover 28nm PHY Support by SJ DDR Team
 */

#include <config.h>
#include <common.h>
#include "asm/arch/socregs.h"
#include "asm/iproc/iproc_common.h"
#include "asm/iproc/reg_utils.h"

#define STATIC static

#define SOC_IF_ERROR_RETURN(x)      (x)
#define sal_alloc(x,y)              malloc(x)
#define sal_memset(x,y,z)           memset(x,y,z)
#define sal_free(x)                 free(x)
#define sal_usleep(x)               udelay(x)

#define TRUE                        (1)
#define FALSE                       (0)

/* BEGIN: TEMPORARY */
#ifndef BCM_AND28_SUPPORT
#define BCM_AND28_SUPPORT
#endif
/* END: TEMPORARY */

#ifdef BCM_AND28_SUPPORT
#include "ydc_ddr_bist.h"
#include "phy_reg_access.h"
#endif

/* BEGIN: HELPER FUNCTIONS */
STATIC uint32
_get_random28(void)
{
    static uint32 m_w = 6483;       /* must not be zero */
    static uint32 m_z = 31245;      /* must not be zero */
    
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;       /* 32-bit result */
}
/* END: HELPER FUNCTIONS */

int
soc_ydc_ddr_bist_config_set(int unit, int phy_ndx, ydc_ddr_bist_info_t *bist_info)
{
    uint32 data;

    READ_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, &data);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, WRITE_WEIGHT, (*bist_info).write_weight);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, READ_WEIGHT, (*bist_info).read_weight);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, PATTERN_BIT_MODE, 0);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, PRBS_MODE, (*bist_info).prbs_mode);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, CONS_ADDR_8_BANKS, 1);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, ADDRESS_SHIFT_MODE, 0);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, DATA_SHIFT_MODE, 0);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, DATA_ADDR_MODE, 0);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, IND_WR_RD_ADDR_MODE, 1);
    WRITE_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, data);
    
    if(!((*bist_info).prbs_mode))
    {
        if((*bist_info).mpr_mode)
        {
            if(YDC_DDR_BIST_PHY_BITWITDH_IS_32)
            {
                WRITE_YDC_DDR_BIST_PATTERN_WORD_0r(0, YDC_DDR_BIST_REG_BASE, 0xFFFFFFFF);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_1r(0, YDC_DDR_BIST_REG_BASE, 0x00000000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_2r(0, YDC_DDR_BIST_REG_BASE, 0xFFFFFFFF);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_3r(0, YDC_DDR_BIST_REG_BASE, 0x00000000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_4r(0, YDC_DDR_BIST_REG_BASE, 0xFFFFFFFF);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_5r(0, YDC_DDR_BIST_REG_BASE, 0x00000000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_6r(0, YDC_DDR_BIST_REG_BASE, 0xFFFFFFFF);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_7r(0, YDC_DDR_BIST_REG_BASE, 0x00000000);
            }
            else
            {
                WRITE_YDC_DDR_BIST_PATTERN_WORD_0r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_1r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_2r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_3r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_4r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_5r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_6r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
                WRITE_YDC_DDR_BIST_PATTERN_WORD_7r(0, YDC_DDR_BIST_REG_BASE, 0xFFFF0000);
            }
        }
        else
        {
            WRITE_YDC_DDR_BIST_PATTERN_WORD_0r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_1r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_2r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_3r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_4r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_5r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_6r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
            WRITE_YDC_DDR_BIST_PATTERN_WORD_7r(0, YDC_DDR_BIST_REG_BASE, _get_random28());
        }
    }
    
    READ_YDC_DDR_BIST_NUMBER_OF_ACTIONSr(0, YDC_DDR_BIST_REG_BASE, &data);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, NUMBER_OF_ACTIONS, BIST_NUM_ACTIONS, (*bist_info).bist_num_actions);
    WRITE_YDC_DDR_BIST_NUMBER_OF_ACTIONSr(0, YDC_DDR_BIST_REG_BASE, data);
    
    READ_YDC_DDR_BIST_START_ADDRESSr(0, YDC_DDR_BIST_REG_BASE, &data);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, START_ADDRESS, BIST_START_ADDRESS, (*bist_info).bist_start_address);
    WRITE_YDC_DDR_BIST_START_ADDRESSr(0, YDC_DDR_BIST_REG_BASE, data);

    READ_YDC_DDR_BIST_END_ADDRESSr(0, YDC_DDR_BIST_REG_BASE, &data);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, END_ADDRESS, BIST_END_ADDRESS, (*bist_info).bist_end_address);
    WRITE_YDC_DDR_BIST_END_ADDRESSr(0, YDC_DDR_BIST_REG_BASE, data);
    
    return SOC_E_NONE;
}

int
soc_ydc_ddr_bist_run(int unit, int phy_ndx, ydc_ddr_bist_err_cnt_t *error_count)
{
    uint32 data;
    uint32 poll_count;
    
    READ_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, &data);
    YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, BIST_EN, 1);
    WRITE_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, data);
    
    poll_count = 0;

    while(TRUE) 
    {
        READ_YDC_DDR_BIST_STATUSESr(0, YDC_DDR_BIST_REG_BASE, &data);

        if(YDC_DDR_BIST_GET_FIELD(data, YDC_DDR_BIST, STATUSES, BIST_FINISHED))
        {
            READ_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, &data);
            YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, BIST_EN, 0);
            WRITE_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, data);
            break;
        }

        if(poll_count > YDC_DDR_BIST_POLL_COUNT_LIMIT)
        {
            READ_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, &data);
            YDC_DDR_BIST_SET_FIELD(data, YDC_DDR_BIST, CONFIGURATIONS, BIST_EN, 0);
            WRITE_YDC_DDR_BIST_CONFIGURATIONSr(0, YDC_DDR_BIST_REG_BASE, data);
            
            printf("ERROR: YDC DDR BIST timeout!!!\n");
            return SOC_E_TIMEOUT;
        }
        
        poll_count++;
        sal_usleep(YDC_DDR_BIST_POLL_INTERVAL_US);
    }
    
    READ_YDC_DDR_BIST_ERROR_OCCURREDr(0, YDC_DDR_BIST_REG_BASE, &data);
    (*error_count).bist_err_occur = YDC_DDR_BIST_GET_FIELD(data, YDC_DDR_BIST, ERROR_OCCURRED, ERR_OCCURRED);
    
    READ_YDC_DDR_BIST_FULL_MASK_ERROR_COUNTERr(0, YDC_DDR_BIST_REG_BASE, &data);
    (*error_count).bist_full_err_cnt = YDC_DDR_BIST_GET_FIELD(data, YDC_DDR_BIST, FULL_MASK_ERROR_COUNTER, FULL_ERR_CNT);
    
    READ_YDC_DDR_BIST_SINGLE_BIT_MASK_ERROR_COUNTERr(0, YDC_DDR_BIST_REG_BASE, &data);
    (*error_count).bist_single_err_cnt = YDC_DDR_BIST_GET_FIELD(data, YDC_DDR_BIST, SINGLE_BIT_MASK_ERROR_COUNTER, SINGLE_ERR_CNT);
    
    READ_YDC_DDR_BIST_GLOBAL_ERROR_COUNTERr(0, YDC_DDR_BIST_REG_BASE, &data);
    (*error_count).bist_global_err_cnt = YDC_DDR_BIST_GET_FIELD(data, YDC_DDR_BIST, GLOBAL_ERROR_COUNTER, GLOBAL_ERR_CNT);
    
    return SOC_E_NONE;
}
