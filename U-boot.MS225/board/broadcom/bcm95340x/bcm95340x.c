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

static
u32 cmicd_schan_read_top (u32 addr) {
    u32 read = 0x0;

    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE0, 0x2c800200);
    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE1, addr);

    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_CTRL, 0x1);

    while (read != 0x2) {
       read = reg32_read((volatile u32 *)CMIC_CMC2_SCHAN_CTRL);
    }
    read = reg32_read((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE1);
    return read;
}

static
u32 cmicd_schan_write_top (u32 addr, u32 val) {
    u32 read = 0x0;

    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE0, 0x34800200);
    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE1, addr);
    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_MESSAGE2, val);

    reg32_write((volatile u32 *)CMIC_CMC2_SCHAN_CTRL, 0x1);

    while (read != 0x2) {
       read = reg32_read((volatile u32 *)CMIC_CMC2_SCHAN_CTRL);
    }
    return read;
}

static
void cmicd_init_soc (void) {
    /* Configure SBUS Ring Map for TOP, block id = 16, ring number = 4 */
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_0_7, 0x11112200);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_8_15, 0x430001);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_16_23, 0x5064);
    reg32_write((volatile u32 *)CMIC_SBUS_RING_MAP_24_31, 0x0);
}

/*****************************************
 * board_init -early hardware init
 *****************************************/
int board_init (void)
{

#if !defined(CONFIG_SYS_NO_FLASH) && !defined(CONFIG_NOR_IPROC_BOOT) && \
	!defined(CONFIG_NAND_IPROC_BOOT)
    
    /* If booting from PNOR, PNOR is already selected, no override required.
     * If booting from NAND, we shouldn't switch to PNOR.
     */
    *(volatile int *)ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL |= cpu_to_le32(
        (1 << ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL__iproc_pnor_sel) |
        (1 << ICFG_IPROC_IOPAD_SW_OVERRIDE_CTRL__iproc_pnor_sel_sw_ovwr));
        
    /* Configure controller memory width based on mw strap */
    if (*(volatile int *)ICFG_PNOR_STRAPS & 
        cpu_to_le32(1 << ICFG_PNOR_STRAPS__PNOR_SRAM_MW_R)) {
        /* 16-bit */
        *(volatile int *)PNOR_set_opmode |= 
                cpu_to_le32(1 << PNOR_set_opmode__set_mw_R);
    } else {
        /* 8-bit */
        *(volatile int *)PNOR_set_opmode &= 
                cpu_to_le32(~(1 << PNOR_set_opmode__set_mw_R));
    }
    *(volatile int *)PNOR_direct_cmd |= 
            cpu_to_le32(2 << PNOR_direct_cmd__cmd_type_R);
    
#endif /* !CONFIG_SYS_NO_FLASH && !CONFIG_NOR_IPROC_BOOT */

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
#if !defined(CONFIG_IPROC_NO_DDR) && !defined(CONFIG_NO_CODE_RELOC)
    uint32_t val;

    printf("Reset XGPLL\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x0060c000);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1060c000);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_3, 0x00000120);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_5, 0x005e0083);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_7, 0x00806204);
    __udelay(2000);
    printf("Release reset\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1460c000);
    printf("Polling\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_7, 0x00806204);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_7, 0x00806604);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_7, 0x00806204);

    val = reg32_read((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_STATUS);
    while(1) {
         if (val & (0x1 << 31)) {
             break;
         }
         val = reg32_read((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_STATUS);
    }
    printf("Locked\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1c60c000);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x0c60c000);

    ddr_init2();
#endif

    gd->ram_size = CONFIG_PHYS_SDRAM_1_SIZE - CONFIG_PHYS_SDRAM_RSVD_SIZE;

    return 0;
}

/*
 *  Clear ihost BISR content through top registers
 */
void board_early_fix (void)
{
    u32 val;

    cmicd_init_soc();
    /* Enable SW_TAP_DIS[Bit 7] = 0 */
    val = cmicd_schan_read_top(TOP_MISC_CONTROL_3);
    val &= ~(0x1 << 7);
    cmicd_schan_write_top(TOP_MISC_CONTROL_3, val);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2e);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2e);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x3ff7d000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0xbfbfffff);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x3ff7d000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0xbfbbffff);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0x3ff7d000);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    cmicd_schan_write_top(TOP_UC_TAP_WRITE_DATA, 0xbfbbffff);
    cmicd_schan_write_top(TOP_UC_TAP_CONTROL, 0x2f);
    val |= (0x1 << 7);
    cmicd_schan_write_top(TOP_MISC_CONTROL_3, val);
    return;
}

int board_early_init_f (void)
{
    uint32_t val;
    val = reg32_read((volatile uint32_t *)ICFG_CHIP_ID_REG);
    if ((val & 0xfff0) == 0xb060) {
        /* Ranger2 - 5606x: CPU 1250MHz, AXI 400MHz, DDR 800MHz */
        iproc_config_armpll(1250);
        iproc_config_genpll(0);
    } else {
        /* Greyhound - 5341x: CPU 600MHz, AXI 200MHz, DDR 667MHz */
        iproc_config_armpll(600);
        iproc_config_genpll(1);
    }

#if defined(CONFIG_I2C_MULTI_BUS) && (CONFIG_SYS_MAX_I2C_BUS > 2)
    /* Enable CMICD I2C master mode */
    val = reg32_read((volatile uint32_t *)CMIC_OVERRIDE_STRAP);
    val |= ((0x1 << CMIC_OVERRIDE_STRAP__ENABLE_OVERRIDE_I2C_MASTER_SLAVE_MODE) |
            (0x1 << CMIC_OVERRIDE_STRAP__I2C_MASTER_SLAVE_MODE));
    reg32_write((volatile uint32_t *)CMIC_OVERRIDE_STRAP, val);
#endif

    /* Assign two 64MB address regions for PNOR */
    val = 0xfce8;
    reg32_write((volatile uint32_t *)ICFG_PNOR_CONFIG_CS_0, val);
    val = 0xfcec;
    reg32_write((volatile uint32_t *)ICFG_PNOR_CONFIG_CS_1, val);

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

    return 0;
}

int board_late_init (void) 
{
    int status = 0;
    u32 val;
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

    val = cmicd_schan_read_top(TOP_UC_TAP_WRITE_DATA);
    printf("TOP_UC_TAP_WRITE_DATA = 0x%x\n", val);

#ifdef STDK_BUILD
    enable_interrupts();
#endif /* STDK_BUILD */

#if !defined(CONFIG_IPROC_NO_DDR) && defined(CONFIG_SHMOO_AND28_REUSE)
     save_shmoo_to_flash();
#endif

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
