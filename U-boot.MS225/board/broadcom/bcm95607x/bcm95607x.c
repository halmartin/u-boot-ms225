/*
 * $Copyright Open Broadcom Corporation$ 
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

/*****************************************
 * board_init -early hardware init
 *****************************************/
int board_init (void)
{
#if !defined(CONFIG_SYS_NO_FLASH) && \
    !defined(CONFIG_NOR_IPROC_BOOT) && \
    !defined(CONFIG_NAND_IPROC_BOOT)
    uint32_t sku;
    
    sku = reg32_read((volatile uint32_t *)ICFG_CHIP_ID_REG);
    if ((sku & 0xfff0) == 0xb070) {
        /* NOR/NAND are disabled on Ranger3 */
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
#if !defined(CONFIG_IPROC_NO_DDR) && !defined(CONFIG_NO_CODE_RELOC)
#if defined(CONFIG_IPROC_EMULATION)
    ddr_init3();
#else
    ddr_init2();
#endif
#endif

    gd->ram_size = CONFIG_PHYS_SDRAM_1_SIZE - CONFIG_PHYS_SDRAM_RSVD_SIZE;

    return 0;
}

int board_early_init_f (void)
{
    uint32_t sku;
    sku = reg32_read((volatile uint32_t *)ICFG_CHIP_ID_REG);
    if ((sku & 0xfff0) == 0xb070) {
        /* Greyhound2 - 5607x: CPU 625MHz, AXI 400MHz, DDR 800MHz */
        iproc_config_armpll(625);
        iproc_config_genpll(0);
    } else {
        /* Ranger3    - 5357x: CPU 1250MHz, AXI 200MHz, DDR 667MHz */
        iproc_config_armpll(1250);
        iproc_config_genpll(1);
    }
    
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
