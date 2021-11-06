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
#include "asm/arch/socregs.h" 
#include "config.h"

#define PRIMARY_CPU  0
 
.globl _start
_start:
    /*
	 * set the cpu to SVC32 mode
	 */
	mrs	r0, cpsr
	bic	r0, r0, #0x1f
	orr	r0, r0, #0xd3
	msr	cpsr,r0
    MRC     p15, 0, r0, c0, c0, 5      /* Identify current CPU */
    AND     r0, r0, #0xf
    CMP     r0, #PRIMARY_CPU
    BEQ     core0_init		
    WFE
    B       core0_init_done		
core0_init:
	/* Disable interrupts */
	mrs	r0, cpsr
	orr	r0, r0, #0xc0
	msr	cpsr,r0
	mov r1, #0
	/* Initialize cp15 registers */
    MCR	p15,0,r1,c5,c0,0   /* DFSR */
    MCR	p15,0,r1,c5,c0,1   /* IFSR */
    MCR	p15,0,r1,c6,c0,0   /* DFAR */
    MCR	p15,0,r1,c6,c0,2   /* IFAR */
	
	@ Disable MMU
	MRC p15, 0, r1, c1, c0, 0 @ Read Control Register configuration data
	BIC r1, r1, #0x1
	MCR p15, 0, r1, c1, c0, 0 @ Write Control Register configuration data
	@ Disable L1 Caches
	MRC p15, 0, r1, c1, c0, 0 @ Read Control Register configuration data
	BIC r1, r1, #(0x1 << 12) @ Disable I Cache
	BIC r1, r1, #(0x1 << 2) @ Disable D Cache
	MCR p15, 0, r1, c1, c0, 0 @ Write Control Register configuration data
	@ Invalidate L1 Caches
	@ Invalidate Instruction cache
	MOV r1, #0
	MCR p15, 0, r1, c7, c5, 0

    @ Invalidate BTAC
	MCR p15, 0, r0, c7, c5, 6 	
    mcr p15, 0, r1, c7, c10, 4 /* DSB */
    mcr p15, 0, r0, c7, c5, 4 /* ISB */ 

    @ Enable I cache
    MRC     p15, 0, r0, c1, c0, 0   @ Read Control Register configuration data
    ORR     r0, r0, #(0x3 << 11)    @ Enable I Cache and Branch prediction
    MCR     p15, 0, r0, c1, c0, 0   @ Write Control Register configuration data

    @  Invalidate Data cache
    @ To make the code general purpose, we calculate the cache size first and loop through each set + way
    MOV  r0, #0                  
    MCR  p15 ,2, r0, c0, c0, 0
    mcr p15, 0, r0, c7, c5, 4 /* ISB */ 
    MRC  p15, 1, r0, c0, c0, 0   @  Read Cache Size ID
    LDR  r4, =0x1ff
    AND  r4, r4, r0, LSR #3      @
    ADD  r4, r4, #1              @  r4 = no: of ways
    LDR  r3, =0x7fff
    AND  r0, r3, r0, LSR #13     @  r0 = no. of sets/lines - 1
    ADD  r0, r0, #1              @  r0 = no: of ways
    MOV  r1, #0                  @  r1 = way counter way_loop
way_loop:
    MOV  r3, #0                  @  r3 = set counter set_loop
set_loop:
    MOV  r2, r1, LSL #30 
    ORR  r2, r3, LSL #5          @  r2 = set/way cache operation format
    MCR  p15, 0, r2, c7, c6, 2   @  Invalidate line described by r2
    ADD  r3, r3, #1              @  Increment set counter
    CMP  r0, r3                  @  Last set reached yet?
    BNE  set_loop                @  if not, iterate set_loop
    ADD  r1, r1, #1              @  else, next
    CMP  r1, r4                  @  Last way reached yet?
    BNE  way_loop                @  if not, iterate way_loop

	@ Enable D Cache
    MCR  p15, 0, r1, c7, c10, 4 /* DSB */
    MRC  p15, 0, r0, c1, c0, 0  @ read CP15 register 1 into r0
    ORR  r0, r0, #0x4           @ enable D Cache
    MCR  p15, 0, r0, c1, c0, 0  @ write CP15 register 1
    MCR  p15, 0, r0, c7, c5, 4 /* ISB */ 

	@ Invalidate TLB
	MCR p15, 0, r1, c8, c7, 0	

/* Setup CCA UART clock divider to 2*/
    LDR     r1, =ChipcommonA_ClkDiv
    LDR     r2, [r1]
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    AND     r2, r2, #0xFFFFFF00
    ORR     r2, r2, #0x2 
#else
    AND     r2, r2, #0x00FFFFFF
    ORR     r2, r2, #0x02000000
#endif
    STR     r2, [r1]

core0_init_done:
/* Copy u-boot-spl image from FLASH to sram */
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
    .byte 0x00,0x02,0x01,0xF1   /* setend be */
#endif
    ldr     r0, =(CONFIG_SPL_UBOOT_START)
    ldr     r1, =(CONFIG_SPL_TEXT_BASE)
    ldr     r2, =(CONFIG_SPL_UBOOT_END)
relocate_spl_loop:
	ldmia   r0!, {r3-r10}           /* copy from source address [r0]    */
    stmia   r1!, {r3-r10}           /* copy to   target address [r1]    */
    cmp     r0, r2                  /* until source end address [r2]    */
    beq     jump_to_spl
    b       relocate_spl_loop
/* Jump to u-boot-spl image entry point */
jump_to_spl:
    ldr     pc, =(CONFIG_SPL_TEXT_BASE)
