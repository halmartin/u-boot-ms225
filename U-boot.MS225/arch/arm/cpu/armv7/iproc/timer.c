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
#include <config.h>
#include <asm/arch/iproc_regs.h>
#include <asm/iproc/reg_utils.h>
#include <asm/iproc/iproc_common.h>
#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

iproc_clk_struct iproc_clk;

/* Use enumerated clock after properly initialized */
#define SET_PERIPH_CLOCK(x,y)  \
do {                           \
if ((gd->flags & GD_FLG_RELOC) && x.arm_periph_clk) \
y = x.arm_periph_clk; \
else \
y = IPROC_ARM_CLK/2;\
} while(0)

void iproc_clk_enum(void)
{

  uint32_t arm_refclk = CONFIG_SYS_REF_CLK;
  
#if defined(CONFIG_HELIX4_EMULATION) || defined(CONFIG_HURRICANE2_EMULATION) || \
	defined(CONFIG_KATANA2_EMULATION) || defined(CONFIG_IPROC_EMULATION)
    iproc_clk.arm_clk = IPROC_ARM_CLK;
    iproc_clk.axi_clk = IPROC_AXI_CLK;
    iproc_clk.apb_clk = IPROC_APB_CLK;
#else
	uint32_t pll_arma, pll_armb, ndiv_int,pdiv, freq_id, mdiv;
	unsigned long long vco_freq;
	
#if defined(CONFIG_GREYHOUND)
  if (reg32_read((volatile uint32_t *)IPROC_WRAP_TOP_STRAP_STATUS_1) & 0x01)  /* 50 MHz */
 	  arm_refclk = 50000000;
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	pll_arma = *((uint32_t *)IHOST_PROC_CLK_PLLARMA);
	pll_armb = *((uint32_t *)IHOST_PROC_CLK_PLLARMB);
#else
	pll_arma = swap_u32(*((uint32_t *)IHOST_PROC_CLK_PLLARMA));
	pll_armb = swap_u32(*((uint32_t *)IHOST_PROC_CLK_PLLARMB));
#endif
	ndiv_int = (pll_arma >> 8) & 0x3FF;
	if(!ndiv_int) 
		ndiv_int = 512;
	pdiv = (pll_arma >> IHOST_PROC_CLK_PLLARMA__pllarm_pdiv_R) & 0x07;
	if(!pdiv)
		pdiv = 0x0F;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	freq_id = (*((uint32_t *)IHOST_PROC_CLK_POLICY_FREQ)) & 0x07;
#else
	freq_id = swap_u32((*((uint32_t *)IHOST_PROC_CLK_POLICY_FREQ))) & 0x07;
#endif
	vco_freq = (ndiv_int << 20) + (pll_armb & 0xFFFFF);
	vco_freq = ((vco_freq * arm_refclk) >> 20) / pdiv;
	//printf("ndiv=%d, pdiv=%d, refclk=%d, vco=%d\n", ndiv_int, pdiv, arm_refclk ,vco_freq); 
	if(freq_id == 0) {
		iproc_clk.arm_clk = arm_refclk;
		iproc_clk.axi_clk = arm_refclk;
		iproc_clk.apb_clk = arm_refclk;
	}
	else if(freq_id == 2) {
		iproc_clk.arm_clk = CONFIG_SYS_REF2_CLK / 2;
		iproc_clk.axi_clk = CONFIG_SYS_REF2_CLK / 2;
		iproc_clk.apb_clk = CONFIG_SYS_REF2_CLK / 4;
	}
	else if(freq_id == 6) {
		iproc_clk.arm_clk = vco_freq / 4;
		iproc_clk.axi_clk = iproc_clk.arm_clk / 2;
		iproc_clk.apb_clk = iproc_clk.arm_clk / 4;
	}
	else if(freq_id == 7) {
		/* For freq_id 7, h_mdiv is the divider */
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		mdiv = *((volatile uint32_t *)IHOST_PROC_CLK_PLLARMCTRL5) & 0xff;
#else
		mdiv = swap_u32(*((volatile uint32_t *)IHOST_PROC_CLK_PLLARMCTRL5)) & 0xff;
#endif
		iproc_clk.arm_clk = vco_freq / mdiv;
		iproc_clk.axi_clk = iproc_clk.arm_clk / 2;
		iproc_clk.apb_clk = iproc_clk.arm_clk / 4;
	}
	else {
		/* TO BE REVIEWED */
		iproc_clk.arm_clk = vco_freq / 2;
		iproc_clk.axi_clk = iproc_clk.arm_clk / 2;
		iproc_clk.apb_clk = iproc_clk.arm_clk / 4;
	}
#endif

#if (defined(CONFIG_HELIX4) || defined(CONFIG_HURRICANE2) || defined(CONFIG_KATANA2) || \
	defined(CONFIG_GREYHOUND) || defined(CONFIG_HURRICANE3) || defined(CONFIG_GREYHOUND2))
	iproc_clk.axi_clk = iproc_get_axi_clk(arm_refclk);
	iproc_clk.apb_clk = iproc_clk.axi_clk / 4;
#endif
#if defined(CONFIG_SABER2)
	iproc_clk.axi_clk = iproc_get_axi_clk(CONFIG_IPROC_PLL_REF_CLK);
	iproc_clk.apb_clk = iproc_clk.axi_clk / 4;
#endif
	iproc_clk.arm_periph_clk = iproc_clk.arm_clk / 2;
	if(iproc_clk.apb_clk < 1000000 || iproc_clk.arm_periph_clk < 1000000) {
		printf("arm_clk=%dHz, axi_clk=%dHz, apb_clk=%dHz, arm_periph_clk=%dHz\n", 
		iproc_clk.arm_clk, iproc_clk.axi_clk, 
		iproc_clk.apb_clk, iproc_clk.arm_periph_clk);
	}
	else {
		printf("arm_clk=%dMHz, axi_clk=%dMHz, apb_clk=%dMHz, arm_periph_clk=%dMHz\n", 
		iproc_clk.arm_clk/1000000, iproc_clk.axi_clk/1000000, 
		iproc_clk.apb_clk/1000000, iproc_clk.arm_periph_clk/1000000);
	}
}

void glb_tim_init(void)
{
	glb_tim_reg_struct_ptr glb_tim_ptr = (glb_tim_reg_struct_ptr)IPROC_PERIPH_GLB_TIM_REG_BASE;

	glb_tim_ptr->control = 0; /* Disable counter, interrupts and comparators */
	glb_tim_ptr->counter_l = 0;
	glb_tim_ptr->counter_h = 0;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	glb_tim_ptr->control |= IPROC_GLB_TIM_CTRL_TIM_EN;
#else
	glb_tim_ptr->control |= swap_u32(IPROC_GLB_TIM_CTRL_TIM_EN);
#endif
}

int timer_init(void)
{
    glb_tim_init();
    return 0;
}

unsigned long get_timer(unsigned long base)
{
	uint32_t count_l;
	uint32_t count_h;
	uint64_t count;
	uint64_t ret;
	uint32_t periph_clk;
	glb_tim_reg_struct_ptr glb_tim_ptr = (glb_tim_reg_struct_ptr)IPROC_PERIPH_GLB_TIM_REG_BASE;

	do {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		count_h = glb_tim_ptr->counter_h;
		count_l = glb_tim_ptr->counter_l;
		count = glb_tim_ptr->counter_h;
#else
		count_h = swap_u32(glb_tim_ptr->counter_h);
		count_l = swap_u32(glb_tim_ptr->counter_l);
		count = swap_u32(glb_tim_ptr->counter_h);
#endif
	} while(count != count_h);
	count = (count << 32) + count_l;

    SET_PERIPH_CLOCK(iproc_clk, periph_clk);

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    ret = (count/(periph_clk/(((glb_tim_ptr->control&IPROC_GLB_TIM_CTRL_PRESC_MASK) >> 8) + 1)/1000)); /* returns msec */
#else
    ret = (count/(periph_clk/(((swap_u32(glb_tim_ptr->control)&IPROC_GLB_TIM_CTRL_PRESC_MASK) >> 8) + 1)/1000)); /* returns msec */
#endif
	return ret - base;
}

void __udelay(unsigned long usec)
{
	unsigned long long curTick, endTick;
	uint32_t count_l;
	uint32_t count_h;
	uint32_t tim_clk;
	uint32_t periph_clk;

    glb_tim_reg_struct_ptr glb_tim_ptr = (glb_tim_reg_struct_ptr)IPROC_PERIPH_GLB_TIM_REG_BASE;
    SET_PERIPH_CLOCK(iproc_clk, periph_clk);

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	tim_clk = (periph_clk/(((glb_tim_ptr->control&IPROC_GLB_TIM_CTRL_PRESC_MASK) >> 8) + 1));
#else
	tim_clk = (periph_clk/(((swap_u32(glb_tim_ptr->control)&IPROC_GLB_TIM_CTRL_PRESC_MASK) >> 8) + 1));
#endif

	do {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
		count_h = glb_tim_ptr->counter_h;
		count_l = glb_tim_ptr->counter_l;
		curTick = glb_tim_ptr->counter_h;
#else
		count_h = swap_u32(glb_tim_ptr->counter_h);
		count_l = swap_u32(glb_tim_ptr->counter_l);
		curTick = swap_u32(glb_tim_ptr->counter_h);
#endif
	} while(curTick != count_h);

	curTick = (curTick << 32) + count_l;

	if(tim_clk >= 1000000) {
		endTick = (tim_clk/1000000);
		endTick *= usec;
		endTick += curTick;
	}
	else {
		endTick = usec;
		endTick = (((endTick * tim_clk) / 1000000) + 1);
		endTick += curTick;
	}

	do {
		do {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
			count_h = glb_tim_ptr->counter_h;
			count_l = glb_tim_ptr->counter_l;
			curTick = glb_tim_ptr->counter_h;
#else
			count_h = swap_u32(glb_tim_ptr->counter_h);
			count_l = swap_u32(glb_tim_ptr->counter_l);
			curTick = swap_u32(glb_tim_ptr->counter_h);
#endif
		} while(curTick != count_h);
	} while (((curTick << 32) + count_l) < endTick);
}

void iproc_systick_init(uint32_t tick_ms)
{
	pvt_tim_reg_struct_ptr tim_ptr = (pvt_tim_reg_struct_ptr)IPROC_PERIPH_PVT_TIM_REG_BASE;

	/* Disable timer and clear interrupt status*/
	tim_ptr->control = 0; 
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	tim_ptr->intstatus = IPROC_PVT_TIM_INT_STATUS_SET;
	tim_ptr->load = (iproc_clk.arm_periph_clk/1000) * tick_ms;
	tim_ptr->control = IPROC_PVT_TIM_CTRL_INT_EN | 
					   IPROC_PVT_TIM_CTRL_AUTO_RELD |
					   IPROC_PVT_TIM_CTRL_TIM_EN;
#else
	tim_ptr->intstatus = swap_u32(IPROC_PVT_TIM_INT_STATUS_SET);
	tim_ptr->load = swap_u32((iproc_clk.arm_periph_clk/1000) * tick_ms);
	tim_ptr->control = swap_u32(IPROC_PVT_TIM_CTRL_INT_EN | 
					   IPROC_PVT_TIM_CTRL_AUTO_RELD |
					   IPROC_PVT_TIM_CTRL_TIM_EN);
#endif
}

void systick_isr(void *data)
{
	pvt_tim_reg_struct_ptr tim_ptr = (pvt_tim_reg_struct_ptr)IPROC_PERIPH_PVT_TIM_REG_BASE;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	tim_ptr->intstatus = IPROC_PVT_TIM_INT_STATUS_SET;
#else
	tim_ptr->intstatus = swap_u32(IPROC_PVT_TIM_INT_STATUS_SET);
#endif
/*	printf("systick_isr: Entered\n"); */
}
/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value in msec.
 */
unsigned long long get_ticks(void)
{
        return get_timer(0);
}

/*
 * This is used in conjuction with get_ticks, which returns msec as ticks.
 * Here we just return ticks/sec = msec/sec = 1000
 */

ulong get_tbclk (void)
{
	
        return 1000;
}
