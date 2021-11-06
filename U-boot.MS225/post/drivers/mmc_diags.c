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
#include <post.h>
#include <mmc.h>

#include "asm/arch/socregs.h"

#if (defined(CONFIG_MMC) && defined(CONFIG_CMD_MMC))
#if CONFIG_POST & CONFIG_SYS_POST_MMC

#undef CONFIG_RAMDOM_CONTENT

/* Size in byte */
#define MMC_DATA_BUF_SIZE           8*1024

#define MMC_DATA_SRC_ADDR           0x02000000
#define MMC_DATA_SRC_ADDR_STR       "0x02000000"
#define MMC_DATA_DST_ADDR           0x02004000

#define SD_BLK_SIZE                 512
#define SD_START_BLK                10
#define SINGLE_TEST_BLK_CNT         (MMC_DATA_BUF_SIZE / SD_BLK_SIZE)
#define TOTAL_TEST_BLK_CNT          (20 * SINGLE_TEST_BLK_CNT)

extern int do_mmcinfo(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);
extern int do_mem_md(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[]);

static mmc_repeat_test(void)
{
    char argv_buf[7*10];
    char * cmd_argv[7];
    int  rep, idx, num;
    void *addr = (void *)MMC_DATA_SRC_ADDR;
    u32 blk = 0x10000;
    struct mmc *mmc;
    u32 val, ctrl = 0, delay = 0, success = 0, failed = 0;

#ifdef CONFIG_RAMDOM_CONTENT
    srand(get_timer(0));
#endif /* CONFIG_RAMDOM_CONTENT */

    memset(&argv_buf, 0, 7*10);
    for(idx = 0; idx < 7; idx++) {
        cmd_argv[idx] = &argv_buf[idx*10];
    }

    /* MMC Scan/Info */
    printf("\n\nMMC Info\n");
    strcpy(cmd_argv[0], "mmcinfo");
    strcpy(cmd_argv[1], "0");
    do_mmcinfo(0, 0, 2, cmd_argv);
    udelay(1000 * 200);

repeat:

    /* Memory Fill */
    for (rep = 0; rep < (TOTAL_TEST_BLK_CNT / SINGLE_TEST_BLK_CNT); rep++) {
        for(idx = 0; idx < (MMC_DATA_BUF_SIZE / 4); idx++) {
#ifdef CONFIG_RAMDOM_CONTENT
            *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4) = (u32)rand();
#else
            *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4) = (0x55555555 << (idx & 1));
#endif /* CONFIG_RAMDOM_CONTENT */
        }

        /* MMC write */
        mmc = find_mmc_device(0);
        if (!mmc) {
            goto failed;
        }
    
        mmc_init(mmc);
    
        addr = (void *)MMC_DATA_SRC_ADDR;
        blk = SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep);
        for(idx = 0; idx < SINGLE_TEST_BLK_CNT; idx++) {
            num = mmc->block_dev.block_write(0, blk, 1, addr);
            if(num < 1) {
                goto failed;
            }
            blk++;
            addr += SD_BLK_SIZE;
            udelay(10);
        }

        /* MMC read back */
        mmc_init(mmc);
        addr = (void *)MMC_DATA_DST_ADDR;
        blk = SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep);
        for(idx = 0; idx < SINGLE_TEST_BLK_CNT; idx++) {
            num = mmc->block_dev.block_read(0, blk, 1, addr);
            if(num < 1) {
                goto failed;
            }
            blk++;
            addr += SD_BLK_SIZE;
            udelay(10);
        }
    
        /* Compare result */
        for(idx = 0; idx < (MMC_DATA_BUF_SIZE / 4); idx++) {
            if(*(unsigned long *)(MMC_DATA_DST_ADDR + idx*4) != *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4)) {
                post_log("\n !! Compare failed at address <0x%08x> = 0x%08x\n",
                                MMC_DATA_DST_ADDR + idx*4, *(unsigned long *)(MMC_DATA_DST_ADDR + idx*4) );
            }
        }
    }
    if (delay) {
        failed++;
        post_log("\nMMC test done, adjustment: %.8x\n", val);
        delay = 0;
    } else {
        success++;
        post_log("\nMMC test done\n");
    }
    post_log("successful:%d, failed:%d\n", success, failed);
    goto repeat;
        
    return 0;

failed:
    delay++;
    if (delay > 40) {
        if (ctrl > 2) {
            return -1;
        }
        ctrl++;
        delay = 0;
    }

    val = readl((void *)0x18116408);
    val &= ~0x3FE;
    val |= ((ctrl << 8) | 0x80 | (delay << 1));
    writel(val, (void *)0x18116408);
    goto repeat;
        
    post_log("\n\nMMC test failed\n");
    return -1;
}

int mmc_post_test(int flags)
{
    char argv_buf[7*10];
    char * cmd_argv[7];
    int  rep, idx, num;
    void *addr = (void *)MMC_DATA_SRC_ADDR;
    u32 blk = 0x10000;
    struct mmc *mmc;

    if (0) {
        mmc_repeat_test();
    }
    
#ifdef CONFIG_RAMDOM_CONTENT
    srand(get_timer(0));
#endif /* CONFIG_RAMDOM_CONTENT */

    memset(&argv_buf, 0, 7*10);
    for(idx = 0; idx < 7; idx++) {
        cmd_argv[idx] = &argv_buf[idx*10];
    }

    /* MMC Scan/Info */
    printf("\n\nMMC Info\n");
    strcpy(cmd_argv[0], "mmcinfo");
    strcpy(cmd_argv[1], "0");
    do_mmcinfo(0, 0, 2, cmd_argv);
    udelay(1000 * 200);

    /* Memory Fill */
    for (rep = 0; rep < (TOTAL_TEST_BLK_CNT / SINGLE_TEST_BLK_CNT); rep++) {
        post_log("\n\nFill memory with incremental data\n");
        for(idx = 0; idx < (MMC_DATA_BUF_SIZE / 4); idx++) {
#ifdef CONFIG_RAMDOM_CONTENT
            *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4) = (u32)rand();
#else
            *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4) = (0x55555555 << (idx & 1));
#endif /* CONFIG_RAMDOM_CONTENT */
        }

        /* Memory Display */
        post_log("\n\n- Display filled memory\n");
        strcpy(cmd_argv[0], "md");
        strcpy(cmd_argv[1], MMC_DATA_SRC_ADDR_STR);
        do_mem_md(0, 0, 2, cmd_argv);

        /* MMC write */
        mmc = find_mmc_device(0);
        if (!mmc) {
            goto failed;
        }
    
        mmc_init(mmc);
    
        post_log("\n\nWrite data to SD card\n");
        post_log("mmc write 0 ddr_addr=0x%x, blk_addr=%d cnt=%d\n", 
                        MMC_DATA_SRC_ADDR, 
                        (SD_START_BLK + SINGLE_TEST_BLK_CNT * rep), 
                        SINGLE_TEST_BLK_CNT);
    
        addr = (void *)MMC_DATA_SRC_ADDR;
        blk = SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep);
        for(idx = 0; idx < SINGLE_TEST_BLK_CNT; idx++) {
            num = mmc->block_dev.block_write(0, blk, 1, addr);
            if(num < 1) {
                goto failed;
            }
            blk++;
            addr += SD_BLK_SIZE;
            udelay(10);
        }

        /* MMC read back */
        post_log("\n\nRead back from SD card and compare\n");
        post_log("mmc read 0 ddr_addr=0x%x, blk_addr=%d cnt=%d\n",
                        MMC_DATA_DST_ADDR, 
                        (SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep)), 
                        SINGLE_TEST_BLK_CNT);
    
        mmc_init(mmc);
        addr = (void *)MMC_DATA_DST_ADDR;
        blk = SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep);
        for(idx = 0; idx < SINGLE_TEST_BLK_CNT; idx++) {
            num = mmc->block_dev.block_read(0, blk, 1, addr);
            if(num < 1) {
                goto failed;
            }
            blk++;
            addr += SD_BLK_SIZE;
            udelay(10);
        }
    
        /* Compare result */
        for(idx = 0; idx < (MMC_DATA_BUF_SIZE / 4); idx++) {
            if(*(unsigned long *)(MMC_DATA_DST_ADDR + idx*4) != *(unsigned long *)(MMC_DATA_SRC_ADDR + idx*4)) {
                post_log("\n !! Compare failed at address <0x%08x> = 0x%08x\n",
                                MMC_DATA_DST_ADDR + idx*4, *(unsigned long *)(MMC_DATA_DST_ADDR + idx*4) );
                break;
            }
        }
    
        if(idx == (MMC_DATA_BUF_SIZE / 4)) {
            post_log("\n\nRead data back from block %d and compare OK\n", 
                                SD_START_BLK + (SINGLE_TEST_BLK_CNT * rep));
        }
    }
    post_log("\n\nMMC test done\n");
        
    return 0;

failed:
    post_log("\n\nMMC test failed\n");
    return -1;
}

#endif /* CONFIG_POST & CONFIG_SYS_POST_MMC */
#endif /* (defined (CONFIG_MMC) && defined(CONFIG_CMD_MMC)) */
