/*****************************************************************************
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
*
*****************************************************************************/


/**
*
* @file  chal_sd.c
*
* @brief sd CHAL c file
*
* @note
*
*******************************************************************************/
#include <config.h>

#include <asm/arch/csp/chal_types.h>
#include <asm/arch/csp/chal_common.h>
#include <asm/arch/csp/rdb/brcm_rdb_emmcsdxc.h>
#include <asm/arch/csp/chal_reg.h>
#include <asm/arch/csp/chal_sd.h>

#ifdef CHAL_SD_DEBUG
#define CHAL_DBG_LEVEL     CHAL_SD_DEBUG
#endif
#include <asm/arch/csp/chal_dbg.h>

/*
 * *****************************************************************************
 * 
 *  Function Name: int32_t chal_sd_reset(CHAL_HANDLE *sdHandle)
 * 
 *  Description:   The function does soft reset the host SD controller. After
 *                 the function call all host controller's register are reset
 *                 to default values;
 * 
 *  Parameters     handle, pointer to the valid host controll handler.
 * 
 *  Return         SD_OK if success, SD_RESET_ERROR otherwise.
 * 
 * 
 * *****************************************************************************
 */

int32_t chal_sd_reset(CHAL_HANDLE *sdHandle)
{
  uint32_t val;

  Sd_Device_t  *handle = (Sd_Device_t *)sdHandle;

  uint32_t sdReg   = (uint32_t)handle->ctrl.sdReg;

  val = CHAL_REG_READ32(sdReg + EMMCSDXC_CTRL1_OFFSET);

  if(val & EMMCSDXC_CTRL1_RST_MASK)
  {
    return (SD_RESET_ERROR); /* SD DRIVER: ERROR: Reset bit is set*/
  }
  else
  {
    /* use top level reset to do reset*/
	val = CHAL_REG_READ32(sdReg + EMMCSDXC_CORECTRL_OFFSET);
	val |= EMMCSDXC_CORECTRL_RESET_MASK;
    CHAL_REG_WRITE32(sdReg + EMMCSDXC_CORECTRL_OFFSET, val);

	chal_dbg_printf(CHAL_DBG_INFO, "reset the host controller, status 0x%0x\n", val);

	do
	{
	   val = CHAL_REG_READ32(sdReg + EMMCSDXC_CORECTRL_OFFSET);
	}while(0 == (val & EMMCSDXC_CORECTRL_RESET_MASK));

	/*out of reset*/
	val = CHAL_REG_READ32(sdReg + EMMCSDXC_CORECTRL_OFFSET);
	val &= ~EMMCSDXC_CORECTRL_RESET_MASK;
    CHAL_REG_WRITE32(sdReg + EMMCSDXC_CORECTRL_OFFSET, val);
  }
  return (SD_OK);
}

/*
 * *****************************************************************************
 * 
 *  Function Name: void chal_sd_enable_host(Sd_Device_t *handle)
 * 
 *  Description: The function sets the core host control to enable gating AHB
 *               clock and enable interrupt to the system.
 * 
 *  Parameters:  handle, pointer to the valid host controll handler.
 * 
 *  Return:      SD host controller's vendor number.
 * 
 * *****************************************************************************
 */
void chal_sd_enable_host(Sd_Device_t *handle)
{
   uint32_t val, sdReg;

   if (handle == NULL)
	  return;

   sdReg = (uint32_t)handle->ctrl.sdReg;

   val = CHAL_REG_READ32(sdReg + EMMCSDXC_CORECTRL_OFFSET);
   val |= EMMCSDXC_CORECTRL_EN_MASK;
   CHAL_REG_WRITE32(sdReg + EMMCSDXC_CORECTRL_OFFSET, val);
   CHAL_REG_WRITE32(sdReg + EMMCSDXC_COREIMR_OFFSET, EMMCSDXC_COREIMSR_IP_MASK);
}
