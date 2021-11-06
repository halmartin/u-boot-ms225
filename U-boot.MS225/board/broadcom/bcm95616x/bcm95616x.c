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

extern void l2cc_unlock(void);
extern void l2cc_invalidate(void);
extern uint32_t iproc_config_genpll(uint32_t mode);
extern int bcmiproc_eth_register(u8 dev_num);

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
    uint32_t sku;
    sku = reg32_read((volatile uint32_t *)ICFG_CHIP_ID_REG);
    if ((sku & 0xf) != 0x4) {
        /* NOR/NAND are disabled on Wolfhound2 */
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
    }
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
    uint32_t val;

    printf("Reset XGPLL\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1060c000);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_3, 0x00000120);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_5, 0x005e0083);
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_7, 0xC0806204);
    __udelay(2000);
    printf("Release reset\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1460c000);
    printf("Polling\n");

    val = reg32_read((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_STATUS);
    while(1) {
         if (val & (0x1 << 31)) {
             break;
         }
         val = reg32_read((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_STATUS);
    }
    printf("Locked\n");
    reg32_write((volatile uint32_t *)IPROC_WRAP_IPROC_XGPLL_CTRL_1, 0x1c60c000);

#if !defined(CONFIG_IPROC_NO_DDR)
    ddr_init2();
#endif

    gd->ram_size = CONFIG_PHYS_SDRAM_1_SIZE - CONFIG_PHYS_SDRAM_RSVD_SIZE;

    return 0;
}

int board_early_init_f (void)
{
    uint32_t val;
    val = reg32_read((volatile uint32_t *)ICFG_CHIP_ID_REG);
    val &= 0xffff;
    if ((val >= 0xb163) && (val <= 0xb166)) {
        /* Hurricane3-lite - 56163/4/6: CPU 600MHz, AXI 200MHz, DDR 667MHz */
        iproc_config_armpll(600);
        iproc_config_genpll(1);
    } else {
        /* Hurricane3/Buckhound - 56160/2,53440/2/3: CPU 1250MHz, AXI 400MHz, DDR 800MHz */
        iproc_config_armpll(1250);
        iproc_config_genpll(0);
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
    return 0;
}

int board_late_init (void) 
{
    int status = 0;

    disable_interrupts();

#if !defined(CONFIG_IPROC_NO_DDR) && defined(CONFIG_SHMOO_AND28_REUSE)
     save_shmoo_to_flash();
#endif

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

#ifdef STDK_BUILD
    enable_interrupts();
#endif /* STDK_BUILD */

    return status;
}

int board_eth_init(bd_t *bis)
{
	int rc = -1;

#ifdef CONFIG_BCMIPROC_ETH
    int idx;
    
    for (idx = 0; idx < CONFIG_GMAC_NUM; idx++) {
    	printf("Registering eth%d\n", idx);
	    rc = bcmiproc_eth_register(idx);
	    if (rc != 0) {
	        return rc;
	    }
	}
#endif

	return rc;
}

void board_sdio_init(void)
{
    u32 val;

    cmicd_init_soc();

    /* Enable SDIO 8 bit mode */
    val = cmicd_schan_read_top(TOP_SDIO_MISC_CONTROL);
    val |= (0x1 << TOP_SDIO_MISC_CONTROL__TOP_SDIO_8B_INF);
    val |= (0xf << TOP_SDIO_MISC_CONTROL__TOP_SDIO_GPIO_INF_SEL_R);
    cmicd_schan_write_top(TOP_SDIO_MISC_CONTROL, val);
}
