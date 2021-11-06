/******************************************************************************/
/*                                                                            */
/*  Copyright 2015  Broadcom Corporation                                      */
/*                                                                            */
/*     Unless you and Broadcom execute a separate written software license    */
/*     agreement governing  use of this software, this software is licensed   */
/*     to you under the terms of the GNU General Public License version 2     */
/*     (the GPL), available at                                                */
/*                                                                            */
/*          http://www.broadcom.com/licenses/GPLv2.php                        */
/*                                                                            */
/*     with the following added to such license:                              */
/*                                                                            */
/*     As a special exception, the copyright holders of this software give    */
/*     you permission to link this software with independent modules, and to  */
/*     copy and distribute the resulting executable under terms of your       */
/*     choice, provided that you also meet, for each linked independent       */
/*     module, the terms and conditions of the license of that module.        */
/*     An independent module is a module which is not derived from this       */
/*     software.  The special exception does not apply to any modifications   */
/*     of the software.                                                       */
/*     Notwithstanding the above, under no circumstances may you combine      */
/*     this software in any way with any other Broadcom software provided     */
/*     under a license other than the GPL, without Broadcom's express prior   */
/*     written consent.                                                       */
/*                                                                            */

#ifndef __SABER2_H
#define __SABER2_H

#include <asm/sizes.h>

/* Flatten Device Tree support */
#define CONFIG_OF_LIBFDT
/* Flatten Image Tree support */
#define CONFIG_FIT

#define CONFIG_EXTRA_ENV_SETTINGS \
	"loadaddr=0x64000000\0" \
	"fdt_high=0xffffffff\0"

#define BOARD_LATE_INIT

/* Architecture, CPU, etc */
#define CONFIG_ARMV7
#define CONFIG_IPROC                        0
#define CONFIG_IPROC_P7                     1
#define CONFIG_SABER2                       1
/* #define CONFIG_IPROC_EMULATION              1 */

/* SPL Features */
#ifdef CONFIG_IPROC_SPL
#define CONFIG_IPROC_NAND_SPL_MAX_SIZE 4096

#define CONFIG_SPL
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_TEXT_BASE            0x2020000
#define CONFIG_SPL_MAX_SIZE             126976       /* 1 Sector Size - NAND_SPL Max Size = (128KB - 4KB) */
#define CONFIG_SPL_STACK                CONFIG_SYS_INIT_SP_ADDR

/*
 * SPL resides in sram
 */
#define CONFIG_SPL_BSS_START_ADDR       0x2071000
#define CONFIG_SPL_BSS_MAX_SIZE         0xEFFF       /* 0x1b071000 - 0x1b07FFFF */
#define CONFIG_SYS_SPL_MALLOC_START     0x64100000
#define CONFIG_SYS_SPL_MALLOC_SIZE      0x100000        /* 1 MB */


#define CONFIG_SPL_LIBCOMMON_SUPPORT

#ifdef CONFIG_NAND_IPROC_BOOT
#define CONFIG_IPROC_NAND_SPL_SYS_TEXT_BASE 0xE0000000
#define CONFIG_SPL_NAND_SUPPORT
#define CONFIG_SPL_NAND_SIMPLE       
#define CONFIG_SYS_NAND_U_BOOT_OFFS     0x20000
#define CONFIG_SYS_NAND_PAGE_SIZE       4096
#define CONFIG_SPL_NAND_SIMPLE_BBT       
#define CONFIG_SPL_UBOOT_START          (0xE0000000 + CONFIG_IPROC_NAND_SPL_MAX_SIZE) /* First 4K has NAND_SPL */
#else
#define CONFIG_IPROC_NAND_SPL_SYS_TEXT_BASE 0xF0000000
#define CONFIG_SPL_SPI_SUPPORT
#define CONFIG_SPL_SPI_FLASH_SUPPORT
#define CONFIG_SPL_SPI_LOAD
#define CONFIG_SPL_SPI_BUS 0
#define CONFIG_SPL_SPI_CS 0
#define CONFIG_SYS_SPI_U_BOOT_OFFS       0x20000
#define CONFIG_SYS_SPI_U_BOOT_SIZE       0xD0000
#define CONFIG_SPL_UBOOT_START           (0xF0000000 + CONFIG_IPROC_NAND_SPL_MAX_SIZE)
#endif /* CONFIG_NAND_IPROC_BOOT */

#define CONFIG_SPL_UBOOT_END            (CONFIG_SPL_UBOOT_START + CONFIG_SPL_MAX_SIZE)

#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT
#define CONFIG_SPL_ETH_SUPPORT
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define CONFIG_SPL_LDSCRIPT "$(CPUDIR)/iproc/u-boot-spl.lds"
#else
#define CONFIG_SPL_LDSCRIPT "$(CPUDIR)/iproc/u-boot-spl-be.lds"
#endif
#endif /* CONFIG_IPROC_SPL */

#define CONFIG_IPROC_MMU                    1
#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH   1
#define CONFIG_MACH_TYPE                    4735
#define CONFIG_BOARD_EARLY_INIT_F           1
#define CONFIG_BOARD_LATE_INIT              1

/* Interrupt configuration */
#ifdef CONFIG_STDK_BUILD
#define STDK_BUILD
#define CONFIG_USE_IRQ                      1
#define CONFIG_STACKSIZE_IRQ                (1024)
#define CONFIG_STACKSIZE_FIQ                (1024)
#endif

/* SRAM configuration */
#ifdef CONFIG_L2C_AS_RAM
#define CONFIG_IPROC_SRAM_BASE              (0x50000000)
#define CONFIG_IPROC_SRAM_SIZE              (0x20000)
#else /* !CONFIG_L2C_AS_RAM */
#define CONFIG_IPROC_SRAM_BASE              (0x02000000)
#define CONFIG_IPROC_SRAM_SIZE              (0x80000)
#endif /* !CONFIG_L2C_AS_RAM */

/* Memory Info */
#if defined(CONFIG_IPROC_NO_DDR)
#ifndef CONFIG_NO_CODE_RELOC
#define CONFIG_NO_CODE_RELOC
#endif /* !CONFIG_NO_CODE_RELOC */
#define CONFIG_SYS_MALLOC_LEN               0x4000
#define CONFIG_PHYS_SDRAM_0                 CONFIG_IPROC_SRAM_BASE
#define CONFIG_PHYS_SDRAM_1                 CONFIG_IPROC_SRAM_BASE
#define CONFIG_PHYS_SDRAM_1_SIZE            CONFIG_IPROC_SRAM_SIZE
#define CONFIG_PHYS_SDRAM_RSVD_SIZE         0x0 /* bytes reserved from CONFIG_PHYS_SDRAM_1 for custom use */
#define CONFIG_SYS_INIT_SP_ADDR             (CONFIG_PHYS_SDRAM_0 + CONFIG_IPROC_SRAM_SIZE - CONFIG_SYS_MALLOC_LEN - CONFIG_ENV_SIZE - 0x200)
#else /* !CONFIG_IPROC_NO_DDR */
#if (defined(CONFIG_DDR32) && defined(CONFIG_IPROC_DDR_ECC))
#error "Saber2 doesn't support 32-bit DDR with ECC."
#endif
/* MT41K512M8RH-125E */
#define CONFIG_DDR_ROW_BITS                 16
#define CONFIG_DDR_COL_BITS                 10
#define CONFIG_DDR_BANK_BITS                3

#define CONFIG_DDR_TOTAL_COLS               ((1 << CONFIG_DDR_ROW_BITS) * (1 << CONFIG_DDR_COL_BITS) * (1 << CONFIG_DDR_BANK_BITS))
#ifdef CONFIG_DDR32
#define CONFIG_DDR_BYTES_PER_COL            4
#else
#define CONFIG_DDR_BYTES_PER_COL            2
#endif
#if defined(CONFIG_NO_CODE_RELOC)
/* Can only use SRAM */
#define CONFIG_SYS_MALLOC_LEN               0x4000
#define CONFIG_PHYS_SDRAM_0                 CONFIG_IPROC_SRAM_BASE
#define CONFIG_PHYS_SDRAM_1                 CONFIG_IPROC_SRAM_BASE
#define CONFIG_PHYS_SDRAM_1_SIZE            CONFIG_IPROC_SRAM_SIZE
#define CONFIG_PHYS_SDRAM_RSVD_SIZE         0x0 /* bytes reserved from CONFIG_PHYS_SDRAM_1 for custom use */
#define CONFIG_SYS_INIT_SP_ADDR             (CONFIG_PHYS_SDRAM_0 + CONFIG_IPROC_SRAM_SIZE - CONFIG_SYS_MALLOC_LEN - CONFIG_ENV_SIZE - 0x200)
#else
#define CONFIG_SYS_MALLOC_LEN               0x40000
#define CONFIG_PHYS_SDRAM_0                 CONFIG_IPROC_SRAM_BASE
#define CONFIG_PHYS_SDRAM_1                 0x60000000
#define CONFIG_PHYS_SDRAM_1_SIZE            (CONFIG_DDR_TOTAL_COLS * CONFIG_DDR_BYTES_PER_COL)
#define CONFIG_PHYS_SDRAM_RSVD_SIZE         0x0 /* bytes reserved from CONFIG_PHYS_SDRAM_1 for custom use */
#define CONFIG_SYS_STACK_SIZE               0x00002000
#define CONFIG_SYS_INIT_SP_ADDR             (CONFIG_PHYS_SDRAM_0 + CONFIG_SYS_STACK_SIZE - 16)
#endif /* defined(CONFIG_NO_CODE_RELOC) */
#endif /* defined(CONFIG_IPROC_NO_DDR) */

#define CONFIG_SYS_MEMTEST_START            CONFIG_PHYS_SDRAM_1
#define CONFIG_SYS_MEMTEST_END              (CONFIG_PHYS_SDRAM_1 + CONFIG_PHYS_SDRAM_1_SIZE)
#define CONFIG_NR_DRAM_BANKS                1
#define CONFIG_SYS_SDRAM_BASE               (CONFIG_PHYS_SDRAM_1 + CONFIG_PHYS_SDRAM_RSVD_SIZE)
#define CONFIG_SYS_LOAD_ADDR                0x70000000
#define LINUX_BOOT_PARAM_ADDR               0x60200000

/* Clocks */
#define CONFIG_SYS_REF_CLK                  (25000000)
#define CONFIG_IPROC_PLL_REF_CLK            (50000000)
#define CONFIG_SYS_REF2_CLK                 (200000000)
#ifdef CONFIG_IPROC_EMULATION
#define IPROC_ARM_CLK                       (310000)
#define IPROC_AXI_CLK                       (56625*4)
#define IPROC_APB_CLK                       (56625)
#else
#define IPROC_ARM_CLK                       (1000000000)
#define IPROC_AXI_CLK                       (400000000)
#define IPROC_APB_CLK                       (100000000)
#endif

#ifdef CONFIG_IPROC_BOARD_DIAGS
#define IPROC_BOARD_DIAGS 	/* Enabling this fails booting on HR board */
#endif /* CONFIG_IPROC_BOARD_DIAGS */

#ifdef IPROC_BOARD_DIAGS
//POST related defines
#define CONFIG_HAS_POST
//define post to support diags available, this is a ORed list
//See bitmask definition in post.h
#define CONFIG_POST       (CONFIG_SYS_POST_MEMORY | CONFIG_SYS_POST_NAND | CONFIG_SYS_POST_QSPI | \
                           CONFIG_SYS_POST_UART | CONFIG_SYS_POST_ETHER | CONFIG_SYS_POST_RGMII)

                           /* CONFIG_SYS_POST_USB20 | CONFIG_SYS_POST_I2C 
                            | CONFIG_SYS_POST_GPIO | CONFIG_SYS_POST_PCIE | CONFIG_SYS_POST_GSIO_SPI) */
                         /* (CONFIG_SYS_POST_PWM | CONFIG_SYS_POST_QSPI|CONFIG_SYS_POST_NAND|\
                          CONFIG_SYS_POST_UART |CONFIG_SYS_POST_MEMORY|CONFIG_SYS_POST_GPIO|\
                          CONFIG_SYS_POST_GSIO_SPI | CONFIG_SYS_POST_USB20 | CONFIG_SYS_POST_PCIE |\
                          CONFIG_SYS_POST_I2C | CONFIG_SYS_POST_MMC | CONFIG_SYS_POST_I2S | CONFIG_SYS_POST_USB30|\
                          CONFIG_SYS_POST_I2S_W8955 | CONFIG_SYS_POST_SPDIF | CONFIG_SYS_POST_RGMII |\
                          CONFIG_SYS_POST_SATA | CONFIG_SYS_POST_EMMC | CONFIG_SYS_POST_VOIP | CONFIG_SYS_POST_SGMII |\
                          CONFIG_SYS_POST_PVTMON ) */

#define CONFIG_CMD_DIAG
//#define CONFIG_SWANG_DEBUG_BUILD
/* #ifdef CONFIG_SWANG_DEBUG_BUILD
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_SYS_INIT_SP_ADDR         (0x10000- 16)
#endif */


//#define CONFIG_DIAGS_MEMTEST_START                0x61000000//offset by 16 MB if not running from L2
//#define CONFIG_DIAGS_MEMTEST_END                  0xA0000000
#ifdef CONFIG_NO_CODE_RELOC
#define CONFIG_DIAGS_MEMTEST_START                0x60000000
#else
#define CONFIG_DIAGS_MEMTEST_START                0x61000000
#endif

#define CONFIG_DIAGS_MEMTEST_END                  0xF0000000


//Chip Common G UART 0
//#define CONFIG_SYS_NS16550_COM1                       (0x18000300)
#ifndef CONFIG_NO_COM2
//Chip Common G UART 1
#define CONFIG_SYS_NS16550_COM2                 (0x18021000)
#endif
#ifndef CONFIG_NO_COM3
//Chip Common G UART 2
#define CONFIG_SYS_NS16550_COM3                 (0x18022000)
#endif

#ifndef CONFIG_NO_COM4
//Chip Common G UART 3
#define CONFIG_SYS_NS16550_COM4                 (0x18023000)
#endif

#define  CONFIG_UART0_INDEX              1
#define  CONFIG_UART1_INDEX              2
#define  CONFIG_UART2_INDEX              3
#define  CONFIG_UART3_INDEX              4

#endif /* IPROC_BOARD_DIAGS */

/* Serial Info */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_CONS_INDEX                   1
#define CONFIG_SYS_NS16550_COM1             (0x18020000)
#define CONFIG_SYS_NS16550_REG_SIZE         (-4)    /* Post pad 3 bytes after each reg addr */
#define CONFIG_SYS_NS16550_CLK              iproc_get_uart_clk(0)
#define CONFIG_BAUDRATE                     115200
#define CONFIG_SYS_BAUDRATE_TABLE           {9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600} 

#define CONFIG_SYS_NO_FLASH                 /* Not using PNOR flash */

#ifdef CONFIG_IPROC_MIN_FEATURES

#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE                     0x1000 /* 4K */

#else /* !CONFIG_IPROC_MIN_FEATURES */

/* Enable generic u-boot SPI flash drivers and commands */
#define CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_STMICRO_NS
#define CONFIG_SPI_FLASH_MACRONIX_NS
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_SPI_FLASH_SST
#define CONFIG_SPI_FLASH_WINBOND
#define CONFIG_SPI_FLASH_ATMEL

/* SPI flash configurations */
#define CONFIG_IPROC_QSPI
#define CONFIG_IPROC_QSPI_BUS                   0
#define CONFIG_IPROC_QSPI_CS                    0

/* SPI flash configuration - flash specific */
#define CONFIG_IPROC_BSPI_DATA_LANES            1
#define CONFIG_IPROC_BSPI_ADDR_LANES            1
#define CONFIG_IPROC_BSPI_READ_CMD              0x0b
#define CONFIG_IPROC_BSPI_READ_DUMMY_CYCLES     8
#define CONFIG_SF_DEFAULT_SPEED                 50000000
#define CONFIG_SF_DEFAULT_MODE                  SPI_MODE_3

/* NAND flash configurations */
#define CONFIG_CMD_NAND 
#define CONFIG_IPROC_NAND 
#define CONFIG_SYS_MAX_NAND_DEVICE			1
#define CONFIG_SYS_NAND_BASE		        0xdeadbeef
#define CONFIG_SYS_NAND_ONFI_DETECTION

/* Board independent required settings */

/* Environment variables */
#ifdef CONFIG_NAND_IPROC_BOOT
#define CONFIG_ENV_IS_IN_NAND                   1
#define CONFIG_ENV_OFFSET                       0x200000
#define CONFIG_ENV_RANGE                        0x200000
#elif defined(CONFIG_SPI_FLASH)
#define CONFIG_ENV_IS_IN_SPI_FLASH              1
#define CONFIG_ENV_OFFSET                       0xc0000
#define CONFIG_ENV_SPI_MAX_HZ                   10000000
#define CONFIG_ENV_SPI_MODE                     SPI_MODE_3
#define CONFIG_ENV_SPI_BUS                      CONFIG_IPROC_QSPI_BUS
#define CONFIG_ENV_SPI_CS                       CONFIG_IPROC_QSPI_CS
#define CONFIG_ENV_SECT_SIZE                    0x10000     /* 64KB */
#else /* No flash defined */
#define CONFIG_ENV_IS_NOWHERE
#endif
#if defined(CONFIG_IPROC_NO_DDR) || defined(CONFIG_NO_CODE_RELOC)
#define CONFIG_ENV_SIZE                         0x400       /* 1KB */
#else
#if CONFIG_IPROC_EMULATION
#define CONFIG_ENV_SIZE                         0x1000      /* 4KB */
#else
#define CONFIG_ENV_SIZE                         0x10000     /* 64KB */
#endif
#endif

#ifndef CONFIG_ENV_IS_NOWHERE
#define CONFIG_CMD_SAVEENV 
#endif 


/* Ethernet configuration */
#define CONFIG_BCMIPROC_ETH
#define CONFIG_CMD_NET
#define CONFIG_CMD_TFTPPUT
#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_GMAC_NUM             1
#define IPROC_ETH_MALLOC_BASE       0xD00000

/* u-boot rich features */
#define CONFIG_CMD_RUN
#define CONFIG_CMD_BOOT
#define CONFIG_CMD_LICENSE
#define CONFIG_CMD_ECHO
#define CONFIG_CMD_ITEST
#define CONFIG_CMD_MISC
#define CONFIG_CMD_SOURCE
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define MTDIDS_DEFAULT      "nand0=nand_iproc.0"
#define MTDPARTS_DEFAULT    "mtdparts=mtdparts=nand_iproc.0:1024k(nboot),1024k(nenv),8192k(nsystem),1038336k(ndata)"
#define CONFIG_SYS_HUSH_PARSER

/* USB */
#define CONFIG_CMD_USB
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_IPROC
#define CONFIG_USB_STORAGE
#define CONFIG_CMD_FAT
#define CONFIG_CMD_EXT2
#define CONFIG_DOS_PARTITION
#define CONFIG_LEGACY_USB_INIT_SEQ
#endif

/* I2C */
#define CONFIG_CMD_I2C
#define CONFIG_IPROC_I2C
#define CONFIG_SYS_I2C_SPEED    100000  /* Default on 100KHz */
#define CONFIG_SYS_I2C_SLAVE    0xff    /* No slave address */
#define CONFIG_I2C_MULTI_BUS
#define CONFIG_SYS_MAX_I2C_BUS  3

#endif /* !CONFIG_IPROC_MIN_FEATURES */


#if !defined(CONFIG_IPROC_NO_DDR)
/* 
 * SHMOO and28 needs about 64K storage for calibration process 
 * The buffter will be released after trace calibration is done
 * and final config saved into flash 
 * For Saber2, we use the second BTCM as this buffer
 */
#define CONFIG_SHMOO_SRAM_BUF                   0x01080000
#if !defined(CONFIG_ENV_IS_NOWHERE)
/* SHMOO values reuse */
#define CONFIG_SHMOO_AND28_REUSE                1
#endif
/* Memory test address to verify stored SHMOO values */
#define CONFIG_SHMOO_REUSE_MEMTEST_START        0x61000000
/* Memory test address to verify stored SHMOO values */
#define CONFIG_SHMOO_REUSE_MEMTEST_LENGTH       0x1000
/* Offset of SPI flash to save Shmoo values */
#define CONFIG_SHMOO_REUSE_QSPI_OFFSET          0x000E0000
/* Offset of NOR flash to save Shmoo values */
#define CONFIG_SHMOO_REUSE_NOR_OFFSET           0x000E0000
/* Offset of NAND flash to save Shmoo values */
#define CONFIG_SHMOO_REUSE_NAND_OFFSET          0x00400000
/* Range for the partition to support NAND bad blocks replacement */
#define CONFIG_SHMOO_REUSE_NAND_RANGE           0x00200000
/* Delay to wait for the magic character to force Shmoo; 0 to disable delay */
#define CONFIG_SHMOO_REUSE_DELAY_MSECS          50
#endif /* !CONFIG_IPROC_NO_DDR */

/* General U-Boot configuration */
#define CONFIG_SYS_CBSIZE                   1024    /* Console buffer size */
#define CONFIG_SYS_PBSIZE                   (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16) /* Printbuffer size */
#define CONFIG_SYS_MAXARGS                  16
#define CONFIG_SYS_BARGSIZE                 CONFIG_SYS_CBSIZE
#define CONFIG_SYS_PROMPT                    "u-boot> "  
#define CONFIG_CMD_CONSOLE
#define CONFIG_CMD_MEMORY
#define CONFIG_CMDLINE_EDITING
#define CONFIG_SYS_LONGHELP
#define CONFIG_BOOTDELAY                    3
#define CONFIG_BOOTCOMMAND                  ""

#define CONFIG_SYS_HZ                       1000

/* For booting Linux */
#define CONFIG_CMDLINE_TAG              /* ATAG_CMDLINE setup */
#define CONFIG_SETUP_MEMORY_TAGS        /* ATAG_MEM setup */
 
/* Undefine config_defaults.h */
#undef CONFIG_CMD_NFS
#undef CONFIG_GENERIC_MMC
#undef CONFIG_BOOTM_NETBSD
#undef CONFIG_BOOTM_OSE
#undef CONFIG_BOOTM_RTEMS

/* Reduce memory usage further if using SRAM only */
#if (defined(CONFIG_IPROC_NO_DDR) || defined(CONFIG_NO_CODE_RELOC)) && \
	!defined(CONFIG_L2C_AS_RAM)
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_ICACHE_OFF
#undef CONFIG_ENV_SIZE
#define CONFIG_ENV_SIZE                     512
#endif

#endif /* __SABER2_H */
