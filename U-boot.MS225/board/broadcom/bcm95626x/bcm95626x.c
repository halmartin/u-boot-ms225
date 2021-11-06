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

#include <common.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <config.h>
#include <asm/arch/iproc.h>
#include <asm/system.h>
#include "asm/iproc/reg_utils.h"
#include "asm/iproc/iproc_common.h"

DECLARE_GLOBAL_DATA_PTR;

extern void iproc_save_shmoo_values(void);
extern void l2cc_unlock(void);
extern void l2cc_invalidate(void);
extern uint32_t iproc_config_armpll(uint32_t clkmhz);
extern int bcmiproc_eth_register(u8 dev_num);

#define SABER2_DEVID_56268 0xb268
#define SABER2_A0_REV_ID      0x1
#define SOC_IS_A0_REV() ((reg32_read((volatile u32 *)CMIC_DEV_REV_ID) >> 16) == SABER2_A0_REV_ID)
#define SOC_IS_56268() ((reg32_read((volatile u32 *)CMIC_DEV_REV_ID) & 0xFFFF) == SABER2_DEVID_56268)

static
u32 cmicd_schan_read_top (u32 addr) {
    u32 read = 0x0;

    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE0, 0x2c680200);
    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE1, addr);

    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_CTRL, 0x1);

    while (read != 0x2) {
       read = reg32_read((volatile u32 *)CMIC_CMC0_SCHAN_CTRL);
    }
    read = reg32_read((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE1);
    return read;
}

static
u32 cmicd_schan_write_top (u32 addr, u32 val) {
    u32 read = 0x0;

    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE0, 0x34680200);
    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE1, addr);
    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_MESSAGE2, val);

    reg32_write((volatile u32 *)CMIC_CMC0_SCHAN_CTRL, 0x1);

    while (read != 0x2) {
       read = reg32_read((volatile u32 *)CMIC_CMC0_SCHAN_CTRL);
    }
    return read;
}

static
void cmicd_init_soc (void) {
    /* Configure SBUS Ring Map for TOP, block id = 13, ring number = 3 */
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_0_7, 0x66034000);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_8_15, 0x55312222);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_16_23, 0x03103775);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_24_31, 0x0);
}

/*****************************************
 * board_init -early hardware init
 *****************************************/
int board_init (void)
{
    gd->bd->bi_arch_number = CONFIG_MACH_TYPE;      /* board id for linux */
    gd->bd->bi_boot_params = LINUX_BOOT_PARAM_ADDR; /* adress of boot parameters */
    iproc_clk_enum();
    return 0;
}

/*****************************************************************
 * misc_init_r - miscellaneous platform dependent initializations
 ******************************************************************/
int misc_init_r (void)
{
    return(0);
}

/**********************************************
 * dram_init - sets uboots idea of sdram size
 **********************************************/
int dram_init (void)
{
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
#ifndef CONFIG_IPROC_NO_DDR
    ddr_init2();
#endif
#endif
    gd->ram_size = CONFIG_PHYS_SDRAM_1_SIZE - CONFIG_PHYS_SDRAM_RSVD_SIZE;

    return 0;
}
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
static
void board_early_fix(void)
{
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2e);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2e);
    
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x1fd00000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0xbffffdfe);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40100000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x80000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x1fd00000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0xbffffdfe);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40100000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40100000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x40000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x80000000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    
    return;
}
#endif

int board_early_init_f (void)
{
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
    u32 val;

    cmicd_init_soc();

    if (!SOC_IS_56268() && SOC_IS_A0_REV()) {
#ifndef CONFIG_NAND_IPROC_BOOT
        /* Fix boot failure that CCU access being blocked by TAP controller */
        board_early_fix();
#endif
    }

    if (SOC_IS_A0_REV()) {
        /* Enable JTAG, ENABLE[Bit 1] = 1 */
        val = cmicd_schan_read_top(TOP_UC_TAP_CONTROL);
        val |= (0x1 << 1);
        cmicd_schan_write_top(TOP_UC_TAP_CONTROL, val);
        /* Master LCPLL */
        cmicd_schan_write_top(TOP_XGXS0_PLL_CONTROL_3, 0x4a5000);
        /* Serdes LCPLL */
        cmicd_schan_write_top(TOP_XGXS1_PLL_CONTROL_3, 0x4a5000);
        /* BS0 LCPLL */
        cmicd_schan_write_top(TOP_BROAD_SYNC0_PLL_CTRL_REGISTER_3, 0x4a5000);
        /* BS1 LCPLL */
        cmicd_schan_write_top(TOP_BROAD_SYNC1_PLL_CTRL_REGISTER_3, 0x4a5000);
        /* CH3_MDIV[23:16] = 0x34 */
        val = cmicd_schan_read_top(TOP_CORE_PLL0_CTRL_REGISTER_5);
        val &= ~(0xff << 16);
        val |= (0x34 << 16);
        cmicd_schan_write_top(TOP_CORE_PLL0_CTRL_REGISTER_5, val);

        /* Stabilize IPROC DDR PLL */
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_1, 0x00004020);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_2, 0x00805004);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_6, 0x11a40022);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_3, 0x0d020d40);

        val = reg32_read((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0);
        val |= (0x1 << IPROC_DDR_PLL_SW_OVWR);
        val &= ~((0x1 << IPROC_DDR_PLL_RESETB) | (0x1 << IPROC_DDR_PLL_POST_RESETB));
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0, val);
        val |= (0x1 << IPROC_DDR_PLL_RESETB);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0, val);

        val = reg32_read((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_STATUS);
        /* Wait untill PLL is locked */
        while (1) {
            if (val & (0x1 << IPROC_DDR_PLL_LOCK)) {
                break;
            }
            val = reg32_read((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_STATUS);
        }

        val = reg32_read((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0);
        val |= (0x1 << IPROC_DDR_PLL_POST_RESETB);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0, val);

        val &= ~(0x1 << IPROC_DDR_PLL_SW_OVWR);
        reg32_write((volatile u32 *)IPROC_WRAP_IPROC_DDR_PLL_CTRL_0, val);

        val = reg32_read((volatile u32 *)PAXB_0_STRAP_STATUS);
        if ((val & (1 << PAXB_0_STRAP_STATUS__STRAP_IPROC_PCIE_USER_RC_MODE)) != 0) {
            /* PCIE in RC mode, select 100MHz clock from iProc DDR LCPLL */
            /* Selected by strap pin in SB2 B0 */
            val = reg32_read((volatile u32 *)IPROC_WRAP_PCIE_SERDES_CONTROL);
            val &= ~(0x7 << IPROC_WRAP_PCIE_SERDES_CONTROL_REFCLK_IN_SEL);
            reg32_write((volatile u32 *)IPROC_WRAP_PCIE_SERDES_CONTROL, val);
        }
    } /* SOC_IS_A0_REV */

    /* 5626x: CPU 1000MHz, AXI 400MHz, DDR 800MHz
     * AXI: 400/200 MHz for high/low sku controlled by otp
     */
    iproc_config_armpll(1000);

#ifndef CONFIG_SGMII_REFCLCK_SEL_EXT
    /* Select SGMII reference clock from Master LCPLL by default */
    val = reg32_read((volatile u32 *)IPROC_WRAP_MISC_CONTROL);
    if ((val & (0x7 << IPROC_WRAP_MISC_CONTROL__SGMII_REFCLK_SEL)) != 0) {
        val &= ~(0x7 << IPROC_WRAP_MISC_CONTROL__SGMII_REFCLK_SEL);
        reg32_write((volatile u32 *)IPROC_WRAP_MISC_CONTROL, val);
    }
#endif

#if defined(CONFIG_I2C_MULTI_BUS) && (CONFIG_SYS_MAX_I2C_BUS > 2)
    /* Enable CMICD I2C master mode */
    val = reg32_read((volatile uint32_t *)CMIC_OVERRIDE_STRAP);
    val |= ((0x1 << CMIC_OVERRIDE_STRAP__ENABLE_OVERRIDE_I2C_MASTER_SLAVE_MODE) |
            (0x1 << CMIC_OVERRIDE_STRAP__I2C_MASTER_SLAVE_MODE));
    reg32_write((volatile uint32_t *)CMIC_OVERRIDE_STRAP, val);
#endif

    val = cmicd_schan_read_top(TOP_SWITCH_FEATURE_ENABLE_3);
    if (!(val & (0x1 << USB_DEV_MODE_STRAP))) {
        /* Enable this bit to indicate usb in host mode for linux driver */
        val = reg32_read((volatile u32 *)IPROC_WRAP_IPROC_STRAP_CTRL);
        val |= (0x1 << IPROC_WRAP_IPROC_STRAP_CTRL__DISABLE_USB2D);
        reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_STRAP_CTRL, val);
    }

#ifndef CONFIG_IPROC_NO_DDR
    /* Initialize ATCM and BTCM for SHMOO (clear to avoid ECC error) */
    {
        int i;
        volatile int *p;
        p = (volatile int *)0x01000000;
        for(i=0; i<64*1024/4; i++, p++)
            *p = 0;
        p = (volatile int *)0x01080000;
        for(i=0; i<128*1024/4; i++, p++)
            *p = 0;
    }
#endif
#endif /* !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD) */
	return 0;
}

int board_late_init (void) 
{
	int status = 0;

#if !defined(CONFIG_IPROC_EMULATION)
#if defined(CONFIG_L2C_AS_RAM) && !defined(CONFIG_NO_CODE_RELOC)
    extern ulong mmu_table_addr;    /* MMU on flash fix: 16KB aligned */
    
    printf("Unlocking L2 Cache ...");
    l2cc_unlock();
    printf("Done\n");

    /* 
     * Relocate MMU table from flash to DDR since flash may not be always accessable.
     * eg. When QSPI controller is in MSPI mode.
     */
    asm volatile ("mcr p15, 0, %0, c2, c0, 0"::"r"(mmu_table_addr)); /* Update TTBR0 */
    asm volatile ("mcr p15, 0, r1, c8, c7, 0");  /* Invalidate TLB*/
    asm volatile ("mcr p15, 0, r1, c7, c10, 4"); /* DSB */
    asm volatile ("mcr p15, 0, r0, c7, c5, 4"); /* ISB */
    
    /* Invalidate L2 cache after MMU table relocated */
    l2cc_invalidate();
#endif

    disable_interrupts();

#ifdef STDK_BUILD
    enable_interrupts();
#endif /* STDK_BUILD */

#if !defined(CONFIG_IPROC_NO_DDR) && defined(CONFIG_SHMOO_AND28_REUSE)
    save_shmoo_to_flash();
#endif
#endif  /* !defined(CONFIG_IPROC_EMULATION) */

    if (SOC_IS_A0_REV()) {
        printf("TOP_XGXS0_PLL_CONTROL_3 = 0x%x\n", cmicd_schan_read_top(TOP_XGXS0_PLL_CONTROL_3));
        printf("TOP_UC_TAP_CONTROL = 0x%x\n", cmicd_schan_read_top(TOP_UC_TAP_CONTROL));
        printf("TOP_CORE_PLL0_CTRL_REGISTER_5 = 0x%x\n", cmicd_schan_read_top(TOP_CORE_PLL0_CTRL_REGISTER_5));
    }
    printf("TOP_SWITCH_FEATURE_ENABLE_3 = 0x%x\n", cmicd_schan_read_top(TOP_SWITCH_FEATURE_ENABLE_3));

    return status;
}

int board_eth_init(bd_t *bis)
{
	int rc = -1;
#ifdef CONFIG_BCMIPROC_ETH
	printf("Registering eth\n");
	rc = bcmiproc_eth_register(0);
#endif
	return rc;
}
