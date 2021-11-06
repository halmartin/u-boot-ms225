/*
 * $Copyright Open Broadcom Corporation$ 
 */
 
#include <config.h>
 
#ifndef CONFIG_IPROC_NO_DDR
 
unsigned int ddr_init_tab[] = {
    0xffffffff
};


unsigned int mt40a512m8_093_1600[] = {
    0, 0x00000a00, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x0a START:RW:0:1:=0x00                                                                                                                        
    1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00                                                                              
    2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00                                      
    3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00                                           
    4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00                        
    5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00                         
    6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00                                 
    7, 0x00000800, // TINIT_F0:RW:8:24:=0x000008 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00                                                                                                                    
    8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000                                                                                                                                                                
    9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000                                                                                                                                                                
    10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000                                                                                                                                                               
    11, 0x00000008, // TINIT_F1:RW:0:24:=0x000008                                                                                                                                                                
    12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000                                                                                                                                                               
    13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000                                                                                                                                                               
    14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000                                                                                                                                
    15, 0x000000a0, // TRST_PWRON:RW:0:32:=0x00027100                                                                                                                                                            
    16, 0x00000190, // CKE_INACTIVE:RW:0:32:=0x00061a80                                                                                                                                                          
    17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00                                                                                                                                             
    18, 0x03000000, // TDLL:RW:16:16:=0x0300 TCPD_F1:RW:0:16:=0x0000                                                                                                                                             
    19, 0x00091600, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x09 CASLAT_LIN_F0:RW:8:6:=0x16 NO_CMD_INIT:RW:0:1:=0x00                                                                                  
    20, 0x0e1c1c04, // RESERVED:RW:24:8:=0x0e TMRD_PAR_F0:RW:16:5:=0x1c TMOD_PAR_F0:RW:8:8:=0x1c CA_PARITY_LAT_F0:RW:0:4:=0x04                                                                                   
    21, 0x0009168c, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x09 CASLAT_LIN_F1:RW:8:6:=0x16 TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x8c                                                                 
    22, 0x0e1c1c04, // RESERVED:RW:24:8:=0x0e TMRD_PAR_F1:RW:16:5:=0x1c TMOD_PAR_F1:RW:8:8:=0x1c CA_PARITY_LAT_F1:RW:0:4:=0x04                                                                                   
    23, 0x0604048c, // TCCD_L_F0:RW:24:5:=0x06 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x8c                                                                       
    24, 0x1b270504, // TRAS_MIN_F0:RW:24:8:=0x1b TRC_F0:RW:16:8:=0x27 TRRD_L_F0:RW:8:8:=0x05 TRRD_F0:RW:0:8:=0x04                                                                                                
    25, 0x110c0602, // TFAW_F0:RW:24:6:=0x11 TRP_F0:RW:16:5:=0x0c TWTR_L_F0:RW:8:6:=0x06 TWTR_F0:RW:0:6:=0x02                                                                                                    
    26, 0x27050406, // TRC_F1:RW:24:8:=0x27 TRRD_L_F1:RW:16:8:=0x05 TRRD_F1:RW:8:8:=0x04 TCCD_L_F1:RW:0:5:=0x06                                                                                                  
    27, 0x0c06021b, // TRP_F1:RW:24:5:=0x0c TWTR_L_F1:RW:16:6:=0x06 TWTR_F1:RW:8:6:=0x02 TRAS_MIN_F1:RW:0:8:=0x1b                                                                                                
    28, 0x08060611, // TMRD_F0:RW:24:5:=0x08 TRTP_AP_F0:RW:16:4:=0x06 TRTP_F0:RW:8:4:=0x06 TFAW_F1:RW:0:6:=0x11                                                                                                  
    29, 0x00db6018, // TRAS_MAX_F0:RW:8:20:=0x00db60 TMOD_F0:RW:0:8:=0x18                                                                                                                                        
    30, 0x06180904, // TRTP_F1:RW:24:4:=0x06 TWR_MPR_F0:RW:16:8:=0x18 TCKESR_F0:RW:8:8:=0x09 TCKE_F0:RW:0:4:=0x04                                                                                                
    31, 0x00180806, // TMOD_F1:RW:16:8:=0x18 TMRD_F1:RW:8:5:=0x08 TRTP_AP_F1:RW:0:4:=0x06                                                                                                                        
    32, 0x0400db60, // TCKE_F1:RW:24:4:=0x04 TRAS_MAX_F1:RW:0:20:=0x00db60                                                                                                                                       
    33, 0x0c001809, // TRCD_F0:RW:24:8:=0x0c WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x18 TCKESR_F1:RW:0:8:=0x09                                                                                            
    34, 0x000c0c0c, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x0c TRCD_F1:RW:8:8:=0x0c TWR_F0:RW:0:6:=0x0c                                                                                                          
    35, 0x01180078, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x18 TVREF:RW:0:16:=0x0078                                                                                                                          
    36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a                                                                                                        
    37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a                                                                                                          
    38, 0x18180101, // TDAL_F1:RW:24:6:=0x18 TDAL_F0:RW:16:6:=0x18 TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01                                                                                           
    39, 0x000d0d03, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x0d TRP_AB_F0:RW:8:5:=0x0d BSTLEN:RW_D:0:3:=0x03                                                                                        
    40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00                                                                                
    41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000                                                                                                                                                
    42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00                                                                                         
    43, 0x00d00100, // TRFC_F0:RW:16:10:=0x00d0 TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00                                                                                                                   
    44, 0x00001860, // TREF_F0:RW:0:20:=0x001860                                                                                                                                                                 
    45, 0x000000d0, // TRFC_F1:RW:0:10:=0x00d0                                                                                                                                                                   
    46, 0x00001860, // TREF_F1:RW:0:20:=0x001860                                                                                                                                                                 
    47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005                                                                                                                                                           
    48, 0x00050005, // TPDEX_F1:RW:16:16:=0x0005 TPDEX_F0:RW:0:16:=0x0005                                                                                                                                        
    49, 0x00140014, // TXPDLL_F1:RW:16:16:=0x0014 TXPDLL_F0:RW:0:16:=0x0014                                                                                                                                      
    50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000                                                                                                                                       
    51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000                                                                                                                                       
    52, 0x03000000, // TXSR_F0:RW:16:16:=0x0300 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00                                                                                                                      
    53, 0x030000d8, // TXSR_F1:RW:16:16:=0x0300 TXSNR_F0:RW:0:16:=0x00d8                                                                                                                                         
    54, 0x000000d8, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x00d8                                                                                         
    55, 0x0c000001, // CKSRE_F0:RW:24:8:=0x0c LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01                                                                    
    56, 0x00080c08, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x08 CKSRE_F1:RW:8:8:=0x0c CKSRX_F0:RW:0:8:=0x08                                                                                                   
    57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00                                                                              
    58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00                                                                                            
    59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00                                                             
    60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10                                                                                    
    61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400                                                                                   
    62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200                                                                                                                                                
    63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000                                                                                                                                             
    64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001                                                                                                                                             
    65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000                                                                                                                                                        
    66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00                                                                                                                                   
    67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000                                                                                                                                                   
    68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00                                                                                                                      
    69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000                                                                                                                                                        
    70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000                                                                                                                                                 
    71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00                                                                                                                                              
    72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000                                                                                                                                                           
    73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000                                                                                                                                                           
    74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00                                                                                                                                                                 
    75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000                                                                                                                                                           
    76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000                                                                                                                                                           
    77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00                                                                                                                                                                 
    78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000                                                                                                                                                           
    79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000                                                                                                                                                           
    80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00                                                                                                                                                                 
    81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000                                                                                                                                                           
    82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000                                                                                                                                                           
    83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00                                                                                                                                                                 
#if defined(CONFIG_IPROC_EMULATION)
#if defined(CONFIG_DDR32)
    84, 0x00000210, // MR0_DATA_F0_0:RW:0:17:=0x000210
#else
    84, 0x00000214, // (CAS delay = 12)                                                                                                                                                            
#endif
#else
    84, 0x00000210, // MR0_DATA_F0_0:RW:0:17:=0x000210
#endif /* CONFIG_MACH_IPROC_EMULATION */
    85, 0x00000201, // MR1_DATA_F0_0:RW:0:17:=0x000201                                                                                                                                                           
    86, 0x00000000, // MR2_DATA_F0_0:RW:0:17:=0x000000
#if defined(CONFIG_IPROC_EMULATION)
#if defined(CONFIG_DDR32)
    87, 0x00000210, // MR0_DATA_F0_0:RW:0:17:=0x000210
#else
    87, 0x00000214,  // (CAS delay = 12)  
#endif
#else
    87, 0x00000210, // MR0_DATA_F1_0:RW:0:17:=0x000210                                                                                                                                                                                                                                                                                                                      
#endif                                                                                                                                                           
    88, 0x00000201, // MR1_DATA_F1_0:RW:0:17:=0x000201                                                                                                                                                           
    89, 0x00000000, // MR2_DATA_F1_0:RW:0:17:=0x000000                                                                                                                                                           
    90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000                                                                                                                                                         
    92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000                                                                                                                                                              
    93, 0x00000481, // MR5_DATA_F0_0:RW:0:17:=0x000481                                                                                                                                                           
    94, 0x00000481, // MR5_DATA_F1_0:RW:0:17:=0x000481                                                                                                                                                           
    95, 0x00000400, // MR6_DATA_F0_0:RW:0:17:=0x000400                                                                                                                                                           
    96, 0x00000400, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000400                                                                                                                                  
    97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00                                                                                                               
    98, 0x00000210, // MR0_DATA_F0_1:RW:0:17:=0x000210                                                                                                                                                           
    99, 0x00000201, // MR1_DATA_F0_1:RW:0:17:=0x000201                                                                                                                                                           
    100, 0x00000000, // MR2_DATA_F0_1:RW:0:17:=0x000000                                                                                                                                                          
    101, 0x00000210, // MR0_DATA_F1_1:RW:0:17:=0x000210                                                                                                                                                          
    102, 0x00000201, // MR1_DATA_F1_1:RW:0:17:=0x000201                                                                                                                                                          
    103, 0x00000000, // MR2_DATA_F1_1:RW:0:17:=0x000000                                                                                                                                                          
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000                                                                                                                                                        
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000                                                                                                                                                             
    107, 0x00000481, // MR5_DATA_F0_1:RW:0:17:=0x000481                                                                                                                                                          
    108, 0x00000481, // MR5_DATA_F1_1:RW:0:17:=0x000481                                                                                                                                                          
    109, 0x00000400, // MR6_DATA_F0_1:RW:0:17:=0x000400                                                                                                                                                          
    110, 0x00000400, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000400                                                                                                                                 
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00                                                                                                              
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00                                                                                                                                                             
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00                                                                                     
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01                                                                                                                                                             
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000                                                                                                                                                   
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00                                                                                                                                                         
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000                                                                                                                                                       
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000                                                                                                                                                       
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01                                                                                                                                                     
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000                                                                                                                                                           
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00                                                                                                                                                        
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000                                                                                                                                                           
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00                                                                                                                                         
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000                                                                                                                                                           
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00                                                                                                                                         
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000                                                                                                                                                               
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000                                                                                                                                 
    157, 0x02000400, // ZQCL_F0:RW:16:12:=0x0200 ZQINIT_F0:RW_D:0:12:=0x0400                                                                                                                                     
    158, 0x04000080, // ZQINIT_F1:RW_D:16:12:=0x0400 ZQCS_F0:RW:0:12:=0x0080                                                                                                                                     
    159, 0x00800200, // ZQCS_F1:RW:16:12:=0x0080 ZQCL_F1:RW:0:12:=0x0200                                                                                                                                         
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00                                                                                                                                         
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040                                                                                                                                                          
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00                                                                                                                                   
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000                                                                                                            
    164, 0x0a020100, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x00                                                                                              
    165, 0x0101ffff, // RESERVED:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff                                                                                   
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01                                                                                  
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01                                                            
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03                                                           
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03                                                                                                                                        
#ifdef CONFIG_DDR32                                                                                                                                                                                              
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00                                                                                    
#else                                                                                                                                                                                                            
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01                                                                                    
#endif                                                                                                                                                                                                           
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00                                                                                                                                   
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00                                                                   
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00                                                                                               
    174, 0x01000000, // BG_ROTATE_EN:RW:24:1:=0x01 DFI_ERROR_INFO:RD:0:24:=0x000000                                                                                                                              
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000                                                                                                                                                           
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00                                                                                                                                                                 
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000                                                                                                                                                              
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00                                                                                                                                                                    
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000                                                                                                                                                             
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00                                                                                                                                                                   
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000                                                                                                                                                    
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00                                                                                         
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000                                                                                                                                                 
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000                                                                                                                                                       
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000                                                                                                                                                       
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000                                                                                                                                                       
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000                                                                                                                                                       
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000                                                                                                                                                      
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000                                                                                                                                                      
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000                                                                                                                                                      
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000                                                                                                                                                      
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000                                                                                                                                                       
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00                                                                                                                                                             
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000                                                                                                                                                  
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00                                                                                                                    
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00                                                                   
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02                                                                                                                                                              
    198, 0x06080800, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x08 TODTL_2CMD_F0:RW:8:5:=0x08                                                                                                            
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06                                                                                
    200, 0x02020000, // RD_TO_ODTH_F1:RW:24:6:=0x02 RD_TO_ODTH_F0:RW:16:6:=0x02 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00                                                                            
    201, 0x00000000, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x00 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x00 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x00                              
    202, 0x02020202, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x02 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x02                                                       
    203, 0x02000202, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x02 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02                                                               
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00                                                                          
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00                                                                
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00                                                                                 
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00                                                                               
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00                                                                                       
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d                                                                                                                           
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000                                                                                             
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00                                                                      
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03                                                                           
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00                                                                                                                                                                    
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000                                                                                                                                                          
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00                                                                                                                                                              
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000                                                                                                                                                          
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00                                                                                                                                                              
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000                                                                                                                                                          
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00                                                                                                                                                              
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000                                                                                                                                                          
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00                                                                   
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01                                                      
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00                                                                        
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00                                                                         
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00                                                                                                                                      
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955                                                                                                                                                         
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955                                                                                                                                                            
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa                                                                                                                                                         
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa                                                                                                                                                            
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955                                                                                                                                                         
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955                                                                                                                                                            
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa                                                                                                                              
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01                                                                 
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00                                                                                          
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00                                                                                                      
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67                                                                                                                               
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67                                                                                                                               
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67                                                                                                                               
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67                                                                                                                               
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67                                                                                                                               
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67                                                                                                                               
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67                                                                                                                               
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67                                                                                                                       
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00                                                                    
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01                                    
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01                                                    
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00                                                 
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00      
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03              
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064                                                        
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02                                                             
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064                                                        
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01                                                             
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064                                                                                                 
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000                                                                                                 
    260, 0x000e0e00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0e TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0e UPDATE_ERROR_STATUS:RD:0:7:=0x00                                                         
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00                                                                                                                              
    262, 0x000030c0, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x0030c0                                                                                                                                                    
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200                                                                                                               
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200                                                                                                               
    265, 0x000030c0, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x0030c0                                                                                                                                                    
    266, 0x0000f3c0, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x0000f3c0                                                                                                                                             
    267, 0x00000d0f, // WRLAT_ADJ_F0:RW:8:7:=0x0d RDLAT_ADJ_F0:RW:0:7:=0x0f                                                                                                                                      
    268, 0x000030c0, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x0030c0                                                                                                                                                    
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200                                                                                                               
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200                                                                                                               
    271, 0x000030c0, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x0030c0                                                                                                                                                    
    272, 0x0000f3c0, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x0000f3c0                                                                                                                                             
    273, 0x02020d0f, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x0d RDLAT_ADJ_F1:RW:0:7:=0x0f                                                                
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00                                                                                         
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a                                                                                                                                                            
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000                                                                                                                                                      
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000                                                                                                                                                       
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a                                                                                                                                 
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000                                                                                                                                                      
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00                                                                                                           
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000                                                                                                                                                       
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000                                                                                                                                                     
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000                                                                                                                      
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03                                                                                                                              
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003                                                                                                                  
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003                                                                                                                                                    
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000                                                                                                                                                      
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000                                                                                                                                                       
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00                                                                                                      
    290, 0x0a000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x0a TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000                                                                                               
    291, 0x00080a08, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x08 TDFI_RDCSLAT_F1:RW:8:4:=0x0a TDFI_WRCSLAT_F0:RW:0:4:=0x08                                                                     
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000                                                                                                                                                       
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000                                                                                                                                                       
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000                                                                                                                                                    
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000                                                                                                                                                    
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00                                                                                                                            
    297, 0x00000200, // MR3_DATA_F0_0:RW:0:17:=0x000200                                                                                                                                                          
    298, 0x00000200, // MR3_DATA_F1_0:RW:0:17:=0x000200                                                                                                                                                          
    299, 0x00000200, // MR3_DATA_F0_1:RW:0:17:=0x000200                                                                                                                                                          
    300, 0x00000200, // MR3_DATA_F1_1:RW:0:17:=0x000200                                                                                                                                                          
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000                                                                                                                                                           
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000                                                                                                                                                           
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000                                                                                                                                                           
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0, 0x00000a01,
    0xffffffff
};

unsigned int ddr3_init_tab_667[] = { 
      0, 0x00000600, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x06 START:RW:0:1:=0x00
      1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00
      2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00
      3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00
      4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00
      5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      7, 0x00000400, // TINIT_F0:RW:8:24:=0x000004 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00
      8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000
      9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000
     10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000
     11, 0x00000004, // TINIT_F1:RW:0:24:=0x000004
     12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000
     13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000
     14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000
     15, 0x00000043, // TRST_PWRON:RW:0:32:=0x00000043
     16, 0x000000a7, // CKE_INACTIVE:RW:0:32:=0x000000a7
     17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00
     18, 0x02000000, // TDLL:RW:16:16:=0x0200 TCPD_F1:RW:0:16:=0x0000
     19, 0x00050a00, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x05 CASLAT_LIN_F0:RW:8:6:=0x0a NO_CMD_INIT:RW:0:1:=0x00
     20, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F0:RW:16:5:=0x00 TMOD_PAR_F0:RW:8:8:=0x00 CA_PARITY_LAT_F0:RW:0:4:=0x00
     21, 0x00050a00, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x05 CASLAT_LIN_F1:RW:8:6:=0x0a TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x00
     22, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F1:RW:16:5:=0x00 TMOD_PAR_F1:RW:8:8:=0x00 CA_PARITY_LAT_F1:RW:0:4:=0x00
     23, 0x05040400, // TCCD_L_F0:RW:24:5:=0x05 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x00
     24, 0x0d120004, // TRAS_MIN_F0:RW:24:8:=0x0d TRC_F0:RW:16:8:=0x12 TRRD_L_F0:RW:8:8:=0x00 TRRD_F0:RW:0:8:=0x04
     25, 0x11050404, // TFAW_F0:RW:24:6:=0x11 TRP_F0:RW:16:5:=0x05 TWTR_L_F0:RW:8:6:=0x04 TWTR_F0:RW:0:6:=0x04
     26, 0x12000405, // TRC_F1:RW:24:8:=0x12 TRRD_L_F1:RW:16:8:=0x00 TRRD_F1:RW:8:8:=0x04 TCCD_L_F1:RW:0:5:=0x05
     27, 0x0504040d, // TRP_F1:RW:24:5:=0x05 TWTR_L_F1:RW:16:6:=0x04 TWTR_F1:RW:8:6:=0x04 TRAS_MIN_F1:RW:0:8:=0x0d
     28, 0x04040411, // TMRD_F0:RW:24:5:=0x04 TRTP_AP_F0:RW:16:4:=0x04 TRTP_F0:RW:8:4:=0x04 TFAW_F1:RW:0:6:=0x11
     29, 0x005b680c, // TRAS_MAX_F0:RW:8:20:=0x005b68 TMOD_F0:RW:0:8:=0x0c
     30, 0x040c0503, // TRTP_F1:RW:24:4:=0x04 TWR_MPR_F0:RW:16:8:=0x0c TCKESR_F0:RW:8:8:=0x05 TCKE_F0:RW:0:4:=0x03
     31, 0x000c0404, // TMOD_F1:RW:16:8:=0x0c TMRD_F1:RW:8:5:=0x04 TRTP_AP_F1:RW:0:4:=0x04
     32, 0x03005b68, // TCKE_F1:RW:24:4:=0x03 TRAS_MAX_F1:RW:0:20:=0x005b68
     33, 0x05000c05, // TRCD_F0:RW:24:8:=0x05 WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x0c TCKESR_F1:RW:0:8:=0x05
     34, 0x00050505, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x05 TRCD_F1:RW:8:8:=0x05 TWR_F0:RW:0:6:=0x05
     35, 0x010c0032, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x0c TVREF:RW:0:16:=0x0032
     36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a
     37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a
     38, 0x0a0a0101, // TDAL_F1:RW:24:6:=0x0a TDAL_F0:RW:16:6:=0x0a TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01
     39, 0x00050503, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x05 TRP_AB_F0:RW:8:5:=0x05 BSTLEN:RW_D:0:3:=0x03
     40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00
     41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000
     42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00
     43, 0x00750100, // TRFC_F0:RW:16:10:=0x0075 TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00
     44, 0x00000a20, // TREF_F0:RW:0:20:=0x000a20
     45, 0x00000075, // TRFC_F1:RW:0:10:=0x0075
     46, 0x00000a20, // TREF_F1:RW:0:20:=0x000a20
     47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005
     48, 0x00030003, // TPDEX_F1:RW:16:16:=0x0003 TPDEX_F0:RW:0:16:=0x0003
     49, 0x000a000a, // TXPDLL_F1:RW:16:16:=0x000a TXPDLL_F0:RW:0:16:=0x000a
     50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000
     51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000
     52, 0x02000000, // TXSR_F0:RW:16:16:=0x0200 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00
     53, 0x02000078, // TXSR_F1:RW:16:16:=0x0200 TXSNR_F0:RW:0:16:=0x0078
     54, 0x00000078, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x0078
     55, 0x05000001, // CKSRE_F0:RW:24:8:=0x05 LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01
     56, 0x00050505, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x05 CKSRE_F1:RW:8:8:=0x05 CKSRX_F0:RW:0:8:=0x05
     57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00
     58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00
     59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00
     60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10
     61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400
     62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200
     63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000
     64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001
     65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000
     66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00
     67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000
     68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00
     69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000
     70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000
     71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00
     72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00
     75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00
     78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00
     81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00
     84, 0x00000210, // MR0_DATA_F0_0:RW:0:17:=0x000210
     85, 0x00000046, // MR1_DATA_F0_0:RW:0:17:=0x000046
     86, 0x00000000, // MR2_DATA_F0_0:RW:0:17:=0x000000
     87, 0x00000210, // MR0_DATA_F1_0:RW:0:17:=0x000210
     88, 0x00000046, // MR1_DATA_F1_0:RW:0:17:=0x000046
     89, 0x00000000, // MR2_DATA_F1_0:RW:0:17:=0x000000
     90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000
     92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000
     93, 0x00000000, // MR5_DATA_F0_0:RW:0:17:=0x000000
     94, 0x00000000, // MR5_DATA_F1_0:RW:0:17:=0x000000
     95, 0x00000000, // MR6_DATA_F0_0:RW:0:17:=0x000000
     96, 0x00000000, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000000
     97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00
     98, 0x00000210, // MR0_DATA_F0_1:RW:0:17:=0x000210
     99, 0x00000046, // MR1_DATA_F0_1:RW:0:17:=0x000046
    100, 0x00000000, // MR2_DATA_F0_1:RW:0:17:=0x000000
    101, 0x00000210, // MR0_DATA_F1_1:RW:0:17:=0x000210
    102, 0x00000046, // MR1_DATA_F1_1:RW:0:17:=0x000046
    103, 0x00000000, // MR2_DATA_F1_1:RW:0:17:=0x000000
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000
    107, 0x00000000, // MR5_DATA_F0_1:RW:0:17:=0x000000
    108, 0x00000000, // MR5_DATA_F1_1:RW:0:17:=0x000000
    109, 0x00000000, // MR6_DATA_F0_1:RW:0:17:=0x000000
    110, 0x00000000, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000000
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
#ifdef CONFIG_IPROC_DDR_ECC
    146, 0x00000001, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01
#else
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x00
#endif
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000
    157, 0x01000200, // ZQCL_F0:RW:16:12:=0x0100 ZQINIT_F0:RW_D:0:12:=0x0200
    158, 0x02000040, // ZQINIT_F1:RW_D:16:12:=0x0200 ZQCS_F0:RW:0:12:=0x0040
    159, 0x00400100, // ZQCS_F1:RW:16:12:=0x0040 ZQCL_F1:RW:0:12:=0x0100
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000
    164, 0x0a020101, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x01
    165, 0x0101ffff, // ADDR_COLLISION_MPM_DIS:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03
#ifdef CONFIG_DDR32
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00
#else
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01
#endif
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00
    174, 0x00000000, // BG_ROTATE_EN:RW:24:1:=0x00 DFI_ERROR_INFO:RD:0:24:=0x000000
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02
    198, 0x06040400, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x04 TODTL_2CMD_F0:RW:8:5:=0x04
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06
    200, 0x00000000, // RD_TO_ODTH_F1:RW:24:6:=0x00 RD_TO_ODTH_F0:RW:16:6:=0x00 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00
    201, 0x02020002, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x02 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x02 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x02
    202, 0x02020101, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x01 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x01
    203, 0x02000102, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x01 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000
    260, 0x000d0d00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0d TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0d UPDATE_ERROR_STATUS:RD:0:7:=0x00
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00
    262, 0x00001440, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x001440
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200
    265, 0x00001440, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x001440
    266, 0x00006540, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x00006540
    267, 0x00000505, // WRLAT_ADJ_F0:RW:8:7:=0x05 RDLAT_ADJ_F0:RW:0:7:=0x05
    268, 0x00001440, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x001440
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200
    271, 0x00001440, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x001440
    272, 0x00006540, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x00006540
    273, 0x02020505, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x05 RDLAT_ADJ_F1:RW:0:7:=0x05
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00
    290, 0x04000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x04 TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000
    291, 0x00040404, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x04 TDFI_RDCSLAT_F1:RW:8:4:=0x04 TDFI_WRCSLAT_F0:RW:0:4:=0x04
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00
    297, 0x00000000, // MR3_DATA_F0_0:RW:0:17:=0x000000
    298, 0x00000000, // MR3_DATA_F1_0:RW:0:17:=0x000000
    299, 0x00000000, // MR3_DATA_F0_1:RW:0:17:=0x000000
    300, 0x00000000, // MR3_DATA_F1_1:RW:0:17:=0x000000
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0xffffffff
};

unsigned int ddr3_init_tab_800[] = { 
      0, 0x00000600, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x06 START:RW:0:1:=0x00
      1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00
      2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00
      3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00
      4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00
      5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      7, 0x00000400, // TINIT_F0:RW:8:24:=0x000004 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00
      8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000
      9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000
     10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000
     11, 0x00000004, // TINIT_F1:RW:0:24:=0x000004
     12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000
     13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000
     14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000
     15, 0x00000050, // TRST_PWRON:RW:0:32:=0x00000050
     16, 0x000000c8, // CKE_INACTIVE:RW:0:32:=0x000000c8
     17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00
     18, 0x02000000, // TDLL:RW:16:16:=0x0200 TCPD_F1:RW:0:16:=0x0000
     19, 0x00050c00, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x05 CASLAT_LIN_F0:RW:8:6:=0x0c NO_CMD_INIT:RW:0:1:=0x00
     20, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F0:RW:16:5:=0x00 TMOD_PAR_F0:RW:8:8:=0x00 CA_PARITY_LAT_F0:RW:0:4:=0x00
     21, 0x00050c00, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x05 CASLAT_LIN_F1:RW:8:6:=0x0c TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x00
     22, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F1:RW:16:5:=0x00 TMOD_PAR_F1:RW:8:8:=0x00 CA_PARITY_LAT_F1:RW:0:4:=0x00
     23, 0x05040400, // TCCD_L_F0:RW:24:5:=0x05 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x00
     24, 0x0f150004, // TRAS_MIN_F0:RW:24:8:=0x0f TRC_F0:RW:16:8:=0x15 TRRD_L_F0:RW:8:8:=0x00 TRRD_F0:RW:0:8:=0x04
     25, 0x15060404, // TFAW_F0:RW:24:6:=0x14 TRP_F0:RW:16:5:=0x06 TWTR_L_F0:RW:8:6:=0x04 TWTR_F0:RW:0:6:=0x04
     26, 0x15000405, // TRC_F1:RW:24:8:=0x15 TRRD_L_F1:RW:16:8:=0x00 TRRD_F1:RW:8:8:=0x04 TCCD_L_F1:RW:0:5:=0x05
     27, 0x0604040f, // TRP_F1:RW:24:5:=0x06 TWTR_L_F1:RW:16:6:=0x04 TWTR_F1:RW:8:6:=0x04 TRAS_MIN_F1:RW:0:8:=0x0f
     28, 0x04040415, // TMRD_F0:RW:24:5:=0x04 TRTP_AP_F0:RW:16:4:=0x04 TRTP_F0:RW:8:4:=0x04 TFAW_F1:RW:0:6:=0x14
     29, 0x006db00c, // TRAS_MAX_F0:RW:8:20:=0x006db0 TMOD_F0:RW:0:8:=0x0c
     30, 0x040c0503, // TRTP_F1:RW:24:4:=0x04 TWR_MPR_F0:RW:16:8:=0x0c TCKESR_F0:RW:8:8:=0x05 TCKE_F0:RW:0:4:=0x03
     31, 0x000c0404, // TMOD_F1:RW:16:8:=0x0c TMRD_F1:RW:8:5:=0x04 TRTP_AP_F1:RW:0:4:=0x04
     32, 0x03006db0, // TCKE_F1:RW:24:4:=0x03 TRAS_MAX_F1:RW:0:20:=0x006db0
     33, 0x06000c05, // TRCD_F0:RW:24:8:=0x06 WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x0c TCKESR_F1:RW:0:8:=0x05
     34, 0x00060606, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x06 TRCD_F1:RW:8:8:=0x06 TWR_F0:RW:0:6:=0x06
     35, 0x010c003c, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x0c TVREF:RW:0:16:=0x003c
     36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a
     37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a
     38, 0x0c0c0101, // TDAL_F1:RW:24:6:=0x0c TDAL_F0:RW:16:6:=0x0c TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01
     39, 0x01060603, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x06 TRP_AB_F0:RW:8:5:=0x06 BSTLEN:RW_D:0:3:=0x03
     40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00
     41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000
     42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00
     43, 0x008c0100, // TRFC_F0:RW:16:10:=0x008c TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00
     44, 0x00000c28, // TREF_F0:RW:0:20:=0x000c28
     45, 0x0000008c, // TRFC_F1:RW:0:10:=0x008c
     46, 0x00000c28, // TREF_F1:RW:0:20:=0x000c28
     47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005
     48, 0x00030003, // TPDEX_F1:RW:16:16:=0x0003 TPDEX_F0:RW:0:16:=0x0003
     49, 0x000a000a, // TXPDLL_F1:RW:16:16:=0x000a TXPDLL_F0:RW:0:16:=0x000a
     50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000
     51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000
     52, 0x02000000, // TXSR_F0:RW:16:16:=0x0200 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00
     53, 0x02000090, // TXSR_F1:RW:16:16:=0x0200 TXSNR_F0:RW:0:16:=0x0090
     54, 0x00000090, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x0090
     55, 0x05000001, // CKSRE_F0:RW:24:8:=0x05 LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01
     56, 0x00050505, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x05 CKSRE_F1:RW:8:8:=0x05 CKSRX_F0:RW:0:8:=0x05
     57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00
     58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00
     59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00
     60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10
     61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400
     62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200
     63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000
     64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001
     65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000
     66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00
     67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000
     68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00
     69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000
     70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000
     71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00
     72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00
     75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00
     78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00
     81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00
     84, 0x00000420, // MR0_DATA_F0_0:RW:0:17:=0x000420
     85, 0x00000046, // MR1_DATA_F0_0:RW:0:17:=0x000046
     86, 0x00000000, // MR2_DATA_F0_0:RW:0:17:=0x000000
     87, 0x00000420, // MR0_DATA_F1_0:RW:0:17:=0x000420
     88, 0x00000046, // MR1_DATA_F1_0:RW:0:17:=0x000046
     89, 0x00000000, // MR2_DATA_F1_0:RW:0:17:=0x000000
     90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000
     92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000
     93, 0x00000000, // MR5_DATA_F0_0:RW:0:17:=0x000000
     94, 0x00000000, // MR5_DATA_F1_0:RW:0:17:=0x000000
     95, 0x00000000, // MR6_DATA_F0_0:RW:0:17:=0x000000
     96, 0x00000000, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000000
     97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00
     98, 0x00000420, // MR0_DATA_F0_1:RW:0:17:=0x000420
     99, 0x00000046, // MR1_DATA_F0_1:RW:0:17:=0x000046
    100, 0x00000000, // MR2_DATA_F0_1:RW:0:17:=0x000000
    101, 0x00000420, // MR0_DATA_F1_1:RW:0:17:=0x000420
    102, 0x00000046, // MR1_DATA_F1_1:RW:0:17:=0x000046
    103, 0x00000000, // MR2_DATA_F1_1:RW:0:17:=0x000000
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000
    107, 0x00000000, // MR5_DATA_F0_1:RW:0:17:=0x000000
    108, 0x00000000, // MR5_DATA_F1_1:RW:0:17:=0x000000
    109, 0x00000000, // MR6_DATA_F0_1:RW:0:17:=0x000000
    110, 0x00000000, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000000
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
#ifdef CONFIG_IPROC_DDR_ECC
    146, 0x00000001, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01
#else
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x00
#endif
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000
    157, 0x01000200, // ZQCL_F0:RW:16:12:=0x0100 ZQINIT_F0:RW_D:0:12:=0x0200
    158, 0x02000040, // ZQINIT_F1:RW_D:16:12:=0x0200 ZQCS_F0:RW:0:12:=0x0040
    159, 0x00400100, // ZQCS_F1:RW:16:12:=0x0040 ZQCL_F1:RW:0:12:=0x0100
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000
    164, 0x0a020101, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x01
    165, 0x0101ffff, // ADDR_COLLISION_MPM_DIS:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03
#ifdef CONFIG_DDR32
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00
#else
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01
#endif
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00
    174, 0x00000000, // BG_ROTATE_EN:RW:24:1:=0x00 DFI_ERROR_INFO:RD:0:24:=0x000000
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02
    198, 0x06040400, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x04 TODTL_2CMD_F0:RW:8:5:=0x04
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06
    200, 0x01010000, // RD_TO_ODTH_F1:RW:24:6:=0x01 RD_TO_ODTH_F0:RW:16:6:=0x01 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00
    201, 0x02020002, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x02 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x02 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x02
    202, 0x02020101, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x01 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x01
    203, 0x02000102, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x01 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000
    260, 0x000d0d00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0d TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0d UPDATE_ERROR_STATUS:RD:0:7:=0x00
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00
    262, 0x00001850, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x001850
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200
    265, 0x00001850, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x001850
    266, 0x00007990, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x00007990
    267, 0x00000404, // WRLAT_ADJ_F0:RW:8:7:=0x04 RDLAT_ADJ_F0:RW:0:7:=0x04
    268, 0x00001850, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x001850
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200
    271, 0x00001850, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x001850
    272, 0x00007990, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x00007990
    273, 0x02020404, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x04 RDLAT_ADJ_F1:RW:0:7:=0x04
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00
    290, 0x05000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x05 TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000
    291, 0x00040504, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x04 TDFI_RDCSLAT_F1:RW:8:4:=0x05 TDFI_WRCSLAT_F0:RW:0:4:=0x04
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00
    297, 0x00000000, // MR3_DATA_F0_0:RW:0:17:=0x000000
    298, 0x00000000, // MR3_DATA_F1_0:RW:0:17:=0x000000
    299, 0x00000000, // MR3_DATA_F0_1:RW:0:17:=0x000000
    300, 0x00000000, // MR3_DATA_F1_1:RW:0:17:=0x000000
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0xffffffff
};

unsigned int ddr3_init_tab_933[] = {
    0xffffffff
};

unsigned int ddr3_init_tab_1066[] = { 
      0, 0x00000600, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x06 START:RW:0:1:=0x00
      1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00
      2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00
      3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00
      4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00
      5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      7, 0x00000600, // TINIT_F0:RW:8:24:=0x000006 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00
      8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000
      9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000
     10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000
     11, 0x00000006, // TINIT_F1:RW:0:24:=0x000006
     12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000
     13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000
     14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000
     15, 0x0000006b, // TRST_PWRON:RW:0:32:=0x0000006b
     16, 0x0000010a, // CKE_INACTIVE:RW:0:32:=0x0000010a
     17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00
     18, 0x02000000, // TDLL:RW:16:16:=0x0200 TCPD_F1:RW:0:16:=0x0000
     19, 0x00061000, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x06 CASLAT_LIN_F0:RW:8:6:=0x10 NO_CMD_INIT:RW:0:1:=0x00
     20, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F0:RW:16:5:=0x00 TMOD_PAR_F0:RW:8:8:=0x00 CA_PARITY_LAT_F0:RW:0:4:=0x00
     21, 0x00061000, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x06 CASLAT_LIN_F1:RW:8:6:=0x10 TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x00
     22, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F1:RW:16:5:=0x00 TMOD_PAR_F1:RW:8:8:=0x00 CA_PARITY_LAT_F1:RW:0:4:=0x00
     23, 0x05040400, // TCCD_L_F0:RW:24:5:=0x05 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x00
     24, 0x141c0006, // TRAS_MIN_F0:RW:24:8:=0x14 TRC_F0:RW:16:8:=0x1c TRRD_L_F0:RW:8:8:=0x00 TRRD_F0:RW:0:8:=0x06
     25, 0x1b080404, // TFAW_F0:RW:24:6:=0x1b TRP_F0:RW:16:5:=0x08 TWTR_L_F0:RW:8:6:=0x04 TWTR_F0:RW:0:6:=0x04
     26, 0x1c000605, // TRC_F1:RW:24:8:=0x1c TRRD_L_F1:RW:16:8:=0x00 TRRD_F1:RW:8:8:=0x06 TCCD_L_F1:RW:0:5:=0x05
     27, 0x08040414, // TRP_F1:RW:24:5:=0x08 TWTR_L_F1:RW:16:6:=0x04 TWTR_F1:RW:8:6:=0x04 TRAS_MIN_F1:RW:0:8:=0x14
     28, 0x0404041b, // TMRD_F0:RW:24:5:=0x04 TRTP_AP_F0:RW:16:4:=0x04 TRTP_F0:RW:8:4:=0x04 TFAW_F1:RW:0:6:=0x1b
     29, 0x0091dc0c, // TRAS_MAX_F0:RW:8:20:=0x0091dc TMOD_F0:RW:0:8:=0x0c
     30, 0x040c0503, // TRTP_F1:RW:24:4:=0x04 TWR_MPR_F0:RW:16:8:=0x0c TCKESR_F0:RW:8:8:=0x05 TCKE_F0:RW:0:4:=0x03
     31, 0x000c0404, // TMOD_F1:RW:16:8:=0x0c TMRD_F1:RW:8:5:=0x04 TRTP_AP_F1:RW:0:4:=0x04
     32, 0x030091dc, // TCKE_F1:RW:24:4:=0x03 TRAS_MAX_F1:RW:0:20:=0x0091dc
     33, 0x08000c05, // TRCD_F0:RW:24:8:=0x08 WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x0c TCKESR_F1:RW:0:8:=0x05
     34, 0x00080808, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x08 TRCD_F1:RW:8:8:=0x08 TWR_F0:RW:0:6:=0x08
     35, 0x010c0050, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x0c TVREF:RW:0:16:=0x0050
     36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a
     37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a
     38, 0x10100101, // TDAL_F1:RW:24:6:=0x10 TDAL_F0:RW:16:6:=0x10 TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01
     39, 0x00080803, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x08 TRP_AB_F0:RW:8:5:=0x08 BSTLEN:RW_D:0:3:=0x03
     40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00
     41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000
     42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00
     43, 0x00bb0100, // TRFC_F0:RW:16:10:=0x00bb TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00
     44, 0x0000102c, // TREF_F0:RW:0:20:=0x00102c
     45, 0x000000bb, // TRFC_F1:RW:0:10:=0x00bb
     46, 0x0000102c, // TREF_F1:RW:0:20:=0x00102c
     47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005
     48, 0x00040004, // TPDEX_F1:RW:16:16:=0x0004 TPDEX_F0:RW:0:16:=0x0004
     49, 0x000d000d, // TXPDLL_F1:RW:16:16:=0x000d TXPDLL_F0:RW:0:16:=0x000d
     50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000
     51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000
     52, 0x02000000, // TXSR_F0:RW:16:16:=0x0200 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00
     53, 0x020000c0, // TXSR_F1:RW:16:16:=0x0200 TXSNR_F0:RW:0:16:=0x00c0
     54, 0x000000c0, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x00c0
     55, 0x06000001, // CKSRE_F0:RW:24:8:=0x06 LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01
     56, 0x00060606, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x06 CKSRE_F1:RW:8:8:=0x06 CKSRX_F0:RW:0:8:=0x06
     57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00
     58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00
     59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00
     60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10
     61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400
     62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200
     63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000
     64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001
     65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000
     66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00
     67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000
     68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00
     69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000
     70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000
     71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00
     72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00
     75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00
     78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00
     81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00
     84, 0x00000840, // MR0_DATA_F0_0:RW:0:17:=0x000840
     85, 0x00000046, // MR1_DATA_F0_0:RW:0:17:=0x000046
     86, 0x00000008, // MR2_DATA_F0_0:RW:0:17:=0x000008
     87, 0x00000840, // MR0_DATA_F1_0:RW:0:17:=0x000840
     88, 0x00000046, // MR1_DATA_F1_0:RW:0:17:=0x000046
     89, 0x00000008, // MR2_DATA_F1_0:RW:0:17:=0x000008
     90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000
     92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000
     93, 0x00000000, // MR5_DATA_F0_0:RW:0:17:=0x000000
     94, 0x00000000, // MR5_DATA_F1_0:RW:0:17:=0x000000
     95, 0x00000000, // MR6_DATA_F0_0:RW:0:17:=0x000000
     96, 0x00000000, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000000
     97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00
     98, 0x00000840, // MR0_DATA_F0_1:RW:0:17:=0x000840
     99, 0x00000046, // MR1_DATA_F0_1:RW:0:17:=0x000046
    100, 0x00000008, // MR2_DATA_F0_1:RW:0:17:=0x000008
    101, 0x00000840, // MR0_DATA_F1_1:RW:0:17:=0x000840
    102, 0x00000046, // MR1_DATA_F1_1:RW:0:17:=0x000046
    103, 0x00000008, // MR2_DATA_F1_1:RW:0:17:=0x000008
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000
    107, 0x00000000, // MR5_DATA_F0_1:RW:0:17:=0x000000
    108, 0x00000000, // MR5_DATA_F1_1:RW:0:17:=0x000000
    109, 0x00000000, // MR6_DATA_F0_1:RW:0:17:=0x000000
    110, 0x00000000, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000000
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
#ifdef CONFIG_IPROC_DDR_ECC
    146, 0x00000001, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01
#else
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x00
#endif
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000
    157, 0x01000200, // ZQCL_F0:RW:16:12:=0x0100 ZQINIT_F0:RW_D:0:12:=0x0200
    158, 0x02000040, // ZQINIT_F1:RW_D:16:12:=0x0200 ZQCS_F0:RW:0:12:=0x0040
    159, 0x00400100, // ZQCS_F1:RW:16:12:=0x0040 ZQCL_F1:RW:0:12:=0x0100
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000
    164, 0x0a020101, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x01
    165, 0x0101ffff, // ADDR_COLLISION_MPM_DIS:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03
#ifdef CONFIG_DDR32
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00
#else
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01
#endif
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00
    174, 0x00000000, // BG_ROTATE_EN:RW:24:1:=0x00 DFI_ERROR_INFO:RD:0:24:=0x000000
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02
    198, 0x06050500, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x05 TODTL_2CMD_F0:RW:8:5:=0x05
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06
    200, 0x02020000, // RD_TO_ODTH_F1:RW:24:6:=0x02 RD_TO_ODTH_F0:RW:16:6:=0x02 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00
    201, 0x02020002, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x02 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x02 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x02
    202, 0x02020101, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x01 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x01
    203, 0x02000102, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x01 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000
    260, 0x000d0d00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0d TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0d UPDATE_ERROR_STATUS:RD:0:7:=0x00
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00
    262, 0x00002058, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x002058
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200
    265, 0x00002058, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x002058
    266, 0x0000a1b8, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x0000a1b8
    267, 0x00000607, // WRLAT_ADJ_F0:RW:8:7:=0x06 RDLAT_ADJ_F0:RW:0:7:=0x07
    268, 0x00002058, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x002058
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200
    271, 0x00002058, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x002058
    272, 0x0000a1b8, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x0000a1b8
    273, 0x02020607, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x06 RDLAT_ADJ_F1:RW:0:7:=0x07
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00
    290, 0x07000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x07 TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000
    291, 0x00050705, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x05 TDFI_RDCSLAT_F1:RW:8:4:=0x07 TDFI_WRCSLAT_F0:RW:0:4:=0x05
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00
    297, 0x00000000, // MR3_DATA_F0_0:RW:0:17:=0x000000
    298, 0x00000000, // MR3_DATA_F1_0:RW:0:17:=0x000000
    299, 0x00000000, // MR3_DATA_F0_1:RW:0:17:=0x000000
    300, 0x00000000, // MR3_DATA_F1_1:RW:0:17:=0x000000
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0xffffffff
};

unsigned int ddr3_init_tab_1333[] = { 
      0, 0x00000600, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x06 START:RW:0:1:=0x00
      1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00
      2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00
      3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00
      4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00
      5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      7, 0x00000700, // TINIT_F0:RW:8:24:=0x000007 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00
      8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000
      9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000
     10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000
     11, 0x00000007, // TINIT_F1:RW:0:24:=0x000007
     12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000
     13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000
     14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000
     15, 0x00000086, // TRST_PWRON:RW:0:32:=0x00000086
     16, 0x0000014e, // CKE_INACTIVE:RW:0:32:=0x0000014e
     17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00
     18, 0x02000000, // TDLL:RW:16:16:=0x0200 TCPD_F1:RW:0:16:=0x0000
     19, 0x00071200, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x07 CASLAT_LIN_F0:RW:8:6:=0x12 NO_CMD_INIT:RW:0:1:=0x00
     20, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F0:RW:16:5:=0x00 TMOD_PAR_F0:RW:8:8:=0x00 CA_PARITY_LAT_F0:RW:0:4:=0x00
     21, 0x00071200, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x07 CASLAT_LIN_F1:RW:8:6:=0x12 TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x00
     22, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F1:RW:16:5:=0x00 TMOD_PAR_F1:RW:8:8:=0x00 CA_PARITY_LAT_F1:RW:0:4:=0x00
     23, 0x05040400, // TCCD_L_F0:RW:24:5:=0x05 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x00
     24, 0x18210005, // TRAS_MIN_F0:RW:24:8:=0x18 TRC_F0:RW:16:8:=0x21 TRRD_L_F0:RW:8:8:=0x00 TRRD_F0:RW:0:8:=0x05
     25, 0x1e090505, // TFAW_F0:RW:24:6:=0x1e TRP_F0:RW:16:5:=0x09 TWTR_L_F0:RW:8:6:=0x05 TWTR_F0:RW:0:6:=0x05
     26, 0x21000505, // TRC_F1:RW:24:8:=0x21 TRRD_L_F1:RW:16:8:=0x00 TRRD_F1:RW:8:8:=0x05 TCCD_L_F1:RW:0:5:=0x05
     27, 0x09050518, // TRP_F1:RW:24:5:=0x09 TWTR_L_F1:RW:16:6:=0x05 TWTR_F1:RW:8:6:=0x05 TRAS_MIN_F1:RW:0:8:=0x18
     28, 0x0405051e, // TMRD_F0:RW:24:5:=0x04 TRTP_AP_F0:RW:16:4:=0x05 TRTP_F0:RW:8:4:=0x05 TFAW_F1:RW:0:6:=0x1e
     29, 0x00b6d00c, // TRAS_MAX_F0:RW:8:20:=0x00b6d0 TMOD_F0:RW:0:8:=0x0c
     30, 0x050c0504, // TRTP_F1:RW:24:4:=0x05 TWR_MPR_F0:RW:16:8:=0x0c TCKESR_F0:RW:8:8:=0x05 TCKE_F0:RW:0:4:=0x04
     31, 0x000c0405, // TMOD_F1:RW:16:8:=0x0c TMRD_F1:RW:8:5:=0x04 TRTP_AP_F1:RW:0:4:=0x05
     32, 0x0400b6d0, // TCKE_F1:RW:24:4:=0x04 TRAS_MAX_F1:RW:0:20:=0x00b6d0
     33, 0x09000c05, // TRCD_F0:RW:24:8:=0x09 WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x0c TCKESR_F1:RW:0:8:=0x05
     34, 0x000a090a, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x0a TRCD_F1:RW:8:8:=0x09 TWR_F0:RW:0:6:=0x0a
     35, 0x010c0064, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x0c TVREF:RW:0:16:=0x0064
     36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a
     37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a
     38, 0x13130101, // TDAL_F1:RW:24:6:=0x13 TDAL_F0:RW:16:6:=0x13 TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01
     39, 0x00090903, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x09 TRP_AB_F0:RW:8:5:=0x09 BSTLEN:RW_D:0:3:=0x03
     40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00
     41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000
     42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00
     43, 0x00ea0100, // TRFC_F0:RW:16:10:=0x00ea TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00
     44, 0x00001448, // TREF_F0:RW:0:20:=0x001448
     45, 0x000000ea, // TRFC_F1:RW:0:10:=0x00ea
     46, 0x00001448, // TREF_F1:RW:0:20:=0x001448
     47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005
     48, 0x00040004, // TPDEX_F1:RW:16:16:=0x0004 TPDEX_F0:RW:0:16:=0x0004
     49, 0x00100010, // TXPDLL_F1:RW:16:16:=0x0010 TXPDLL_F0:RW:0:16:=0x0010
     50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000
     51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000
     52, 0x02000000, // TXSR_F0:RW:16:16:=0x0200 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00
     53, 0x020000f0, // TXSR_F1:RW:16:16:=0x0200 TXSNR_F0:RW:0:16:=0x00f0
     54, 0x000000f0, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x00f0
     55, 0x07000001, // CKSRE_F0:RW:24:8:=0x07 LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01
     56, 0x00070707, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x07 CKSRE_F1:RW:8:8:=0x07 CKSRX_F0:RW:0:8:=0x07
     57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00
     58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00
     59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00
     60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10
     61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400
     62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200
     63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000
     64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001
     65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000
     66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00
     67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000
     68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00
     69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000
     70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000
     71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00
     72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00
     75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00
     78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00
     81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00
     84, 0x00000a50, // MR0_DATA_F0_0:RW:0:17:=0x000a50
     85, 0x00000046, // MR1_DATA_F0_0:RW:0:17:=0x000046
     86, 0x00000010, // MR2_DATA_F0_0:RW:0:17:=0x000010
     87, 0x00000a50, // MR0_DATA_F1_0:RW:0:17:=0x000a50
     88, 0x00000046, // MR1_DATA_F1_0:RW:0:17:=0x000046
     89, 0x00000010, // MR2_DATA_F1_0:RW:0:17:=0x000010
     90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000
     92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000
     93, 0x00000000, // MR5_DATA_F0_0:RW:0:17:=0x000000
     94, 0x00000000, // MR5_DATA_F1_0:RW:0:17:=0x000000
     95, 0x00000000, // MR6_DATA_F0_0:RW:0:17:=0x000000
     96, 0x00000000, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000000
     97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00
     98, 0x00000a50, // MR0_DATA_F0_1:RW:0:17:=0x000a50
     99, 0x00000046, // MR1_DATA_F0_1:RW:0:17:=0x000046
    100, 0x00000010, // MR2_DATA_F0_1:RW:0:17:=0x000010
    101, 0x00000a50, // MR0_DATA_F1_1:RW:0:17:=0x000a50
    102, 0x00000046, // MR1_DATA_F1_1:RW:0:17:=0x000046
    103, 0x00000010, // MR2_DATA_F1_1:RW:0:17:=0x000010
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000
    107, 0x00000000, // MR5_DATA_F0_1:RW:0:17:=0x000000
    108, 0x00000000, // MR5_DATA_F1_1:RW:0:17:=0x000000
    109, 0x00000000, // MR6_DATA_F0_1:RW:0:17:=0x000000
    110, 0x00000000, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000000
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
#ifdef CONFIG_IPROC_DDR_ECC
    146, 0x00000001, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01
#else
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x00
#endif
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000
    157, 0x01000200, // ZQCL_F0:RW:16:12:=0x0100 ZQINIT_F0:RW_D:0:12:=0x0200
    158, 0x02000040, // ZQINIT_F1:RW_D:16:12:=0x0200 ZQCS_F0:RW:0:12:=0x0040
    159, 0x00400100, // ZQCS_F1:RW:16:12:=0x0040 ZQCL_F1:RW:0:12:=0x0100
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000
    164, 0x0a020101, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x01
    165, 0x0101ffff, // ADDR_COLLISION_MPM_DIS:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03
#ifdef CONFIG_DDR32
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00
#else
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01
#endif
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00
    174, 0x00000000, // BG_ROTATE_EN:RW:24:1:=0x00 DFI_ERROR_INFO:RD:0:24:=0x000000
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02
    198, 0x06060600, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x06 TODTL_2CMD_F0:RW:8:5:=0x06
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06
    200, 0x02020000, // RD_TO_ODTH_F1:RW:24:6:=0x02 RD_TO_ODTH_F0:RW:16:6:=0x02 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00
    201, 0x02020002, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x02 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x02 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x02
    202, 0x02020101, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x01 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x01
    203, 0x02000102, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x01 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000
    260, 0x000e0e00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0e TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0e UPDATE_ERROR_STATUS:RD:0:7:=0x00
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00
    262, 0x00002890, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x002890
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200
    265, 0x00002890, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x002890
    266, 0x0000cad0, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x0000cad0
    267, 0x00000708, // WRLAT_ADJ_F0:RW:8:7:=0x07 RDLAT_ADJ_F0:RW:0:7:=0x08
    268, 0x00002890, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x002890
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200
    271, 0x00002890, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x002890
    272, 0x0000cad0, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x0000cad0
    273, 0x02020708, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x07 RDLAT_ADJ_F1:RW:0:7:=0x08
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00
    290, 0x08000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x08 TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000
    291, 0x00060806, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x06 TDFI_RDCSLAT_F1:RW:8:4:=0x08 TDFI_WRCSLAT_F0:RW:0:4:=0x06
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00
    297, 0x00000000, // MR3_DATA_F0_0:RW:0:17:=0x000000
    298, 0x00000000, // MR3_DATA_F1_0:RW:0:17:=0x000000
    299, 0x00000000, // MR3_DATA_F0_1:RW:0:17:=0x000000
    300, 0x00000000, // MR3_DATA_F1_1:RW:0:17:=0x000000
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0xffffffff
};

unsigned int ddr3_init_tab_1600[] = {
      0, 0x00000600, // VERSION:RD:16:16:=0x0000 DRAM_CLASS:RW:8:4:=0x06 START:RW:0:1:=0x00
      1, 0x00000000, // READ_DATA_FIFO_DEPTH:RD:24:8:=0x00 MAX_CS_REG:RD:16:2:=0x00 MAX_COL_REG:RD:8:4:=0x00 MAX_ROW_REG:RD:0:5:=0x00
      2, 0x00000000, // MEMCD_RMODW_FIFO_DEPTH:RD:24:8:=0x00 WRITE_DATA_FIFO_PTR_WIDTH:RD:16:8:=0x00 WRITE_DATA_FIFO_DEPTH:RD:8:8:=0x00 READ_DATA_FIFO_PTR_WIDTH:RD:0:8:=0x00
      3, 0x00000000, // AXI0_RDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_CMDFIFO_LOG2_DEPTH:RD:16:8:=0x00 ASYNC_CDC_STAGES:RD:8:8:=0x00 MEMCD_RMODW_FIFO_PTR_WIDTH:RD:0:8:=0x00
      4, 0x00000000, // AXI1_CMDFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI0_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI0_TRANS_WRFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI0_WR_ARRAY_LOG2_DEPTH:RD:0:8:=0x00
      5, 0x00000000, // AXI1_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI1_TRANS_WRFIFO_LOG2_DEPTH:RD:16:8:=0x00 AXI1_WR_ARRAY_LOG2_DEPTH:RD:8:8:=0x00 AXI1_RDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      6, 0x00000000, // AXI2_TRANS_WRFIFO_LOG2_DEPTH:RD:24:8:=0x00 AXI2_WR_ARRAY_LOG2_DEPTH:RD:16:8:=0x00 AXI2_RDFIFO_LOG2_DEPTH:RD:8:8:=0x00 AXI2_CMDFIFO_LOG2_DEPTH:RD:0:8:=0x00
      7, 0x00000800, // TINIT_F0:RW:8:24:=0x000008 AXI2_WRCMD_PROC_FIFO_LOG2_DEPTH:RD:0:8:=0x00
      8, 0x00000000, // TINIT3_F0:RW:0:24:=0x000000
      9, 0x00000000, // TINIT4_F0:RW:0:24:=0x000000
     10, 0x00000000, // TINIT5_F0:RW:0:24:=0x000000
     11, 0x00000008, // TINIT_F1:RW:0:24:=0x000008
     12, 0x00000000, // TINIT3_F1:RW:0:24:=0x000000
     13, 0x00000000, // TINIT4_F1:RW:0:24:=0x000000
     14, 0x01000000, // NO_AUTO_MRR_INIT:RW:24:1:=0x01 TINIT5_F1:RW:0:24:=0x000000
     15, 0x000000a0, // TRST_PWRON:RW:0:32:=0x000000a0
     16, 0x00000190, // CKE_INACTIVE:RW:0:32:=0x00000190
     17, 0x00000000, // TCPD_F0:RW:8:16:=0x0000 INITAREF:RW:0:4:=0x00
     18, 0x02000000, // TDLL:RW:16:16:=0x0200 TCPD_F1:RW:0:16:=0x0000
     19, 0x00081600, // ADDITIVE_LAT_F0:RW:24:5:=0x00 WRLAT_F0:RW:16:5:=0x08 CASLAT_LIN_F0:RW:8:6:=0x16 NO_CMD_INIT:RW:0:1:=0x00
     20, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F0:RW:16:5:=0x00 TMOD_PAR_F0:RW:8:8:=0x00 CA_PARITY_LAT_F0:RW:0:4:=0x00
     21, 0x00081600, // ADDITIVE_LAT_F1:RW:24:5:=0x00 WRLAT_F1:RW:16:5:=0x08 CASLAT_LIN_F1:RW:8:6:=0x16 TPARITY_ERROR_CMD_INHIBIT_F0:RW:0:8:=0x00
     22, 0x00000000, // RESERVED:RW:24:8:=0x00 TMRD_PAR_F1:RW:16:5:=0x00 TMOD_PAR_F1:RW:8:8:=0x00 CA_PARITY_LAT_F1:RW:0:4:=0x00
     23, 0x05040400, // TCCD_L_F0:RW:24:5:=0x05 TCCD:RW:16:5:=0x04 TBST_INT_INTERVAL:RW:8:3:=0x04 TPARITY_ERROR_CMD_INHIBIT_F1:RW:0:8:=0x00
     24, 0x1c270006, // TRAS_MIN_F0:RW:24:8:=0x1c TRC_F0:RW:16:8:=0x27 TRRD_L_F0:RW:8:8:=0x00 TRRD_F0:RW:0:8:=0x06
     25, 0x200b0607, // TFAW_F0:RW:24:6:=0x20 TRP_F0:RW:16:5:=0x0b TWTR_L_F0:RW:8:6:=0x06 TWTR_F0:RW:0:6:=0x06
     26, 0x27000605, // TRC_F1:RW:24:8:=0x27 TRRD_L_F1:RW:16:8:=0x00 TRRD_F1:RW:8:8:=0x06 TCCD_L_F1:RW:0:5:=0x05
     27, 0x0b06061c, // TRP_F1:RW:24:5:=0x0b TWTR_L_F1:RW:16:6:=0x06 TWTR_F1:RW:8:6:=0x06 TRAS_MIN_F1:RW:0:8:=0x1c
     28, 0x04060620, // TMRD_F0:RW:24:5:=0x04 TRTP_AP_F0:RW:16:4:=0x06 TRTP_F0:RW:8:4:=0x06 TFAW_F1:RW:0:6:=0x20
     29, 0x00db600c, // TRAS_MAX_F0:RW:8:20:=0x00db60 TMOD_F0:RW:0:8:=0x0c
     30, 0x060c0504, // TRTP_F1:RW:24:4:=0x06 TWR_MPR_F0:RW:16:8:=0x0c TCKESR_F0:RW:8:8:=0x05 TCKE_F0:RW:0:4:=0x04
     31, 0x000c0406, // TMOD_F1:RW:16:8:=0x0c TMRD_F1:RW:8:5:=0x04 TRTP_AP_F1:RW:0:4:=0x06
     32, 0x0400db60, // TCKE_F1:RW:24:4:=0x04 TRAS_MAX_F1:RW:0:20:=0x00db60
     33, 0x0b000c05, // TRCD_F0:RW:24:8:=0x0b WRITEINTERP:RW:16:1:=0x00 TWR_MPR_F1:RW:8:8:=0x0c TCKESR_F1:RW:0:8:=0x05
     34, 0x000c0b0c, // TMRR:RW:24:4:=0x00 TWR_F1:RW:16:6:=0x0c TRCD_F1:RW:8:8:=0x0b TWR_F0:RW:0:6:=0x0c
     35, 0x010c0078, // TMPRR:RW:24:4:=0x01 TMRD_PDA:RW:16:8:=0x0c TVREF:RW:0:16:=0x0078
     36, 0x0a140a0a, // TCAEXT:RW:24:5:=0x0a TCAMRD:RW:16:6:=0x14 TCAENT:RW:8:5:=0x0a TCACKEL:RW:0:5:=0x0a
     37, 0x0100000a, // AP:RW:24:1:=0x01 TMRZ_F1:RW:16:5:=0x00 TMRZ_F0:RW:8:5:=0x00 TCACKEH:RW:0:5:=0x0a
     38, 0x17170101, // TDAL_F1:RW:24:6:=0x17 TDAL_F0:RW:16:6:=0x17 TRAS_LOCKOUT:RW:8:1:=0x01 CONCURRENTAP:RW:0:1:=0x01
     39, 0x000b0b03, // REG_DIMM_ENABLE:RW:24:1:=0x00 TRP_AB_F1:RW:16:5:=0x0b TRP_AB_F0:RW:8:5:=0x0b BSTLEN:RW_D:0:3:=0x03
     40, 0x00010100, // RESERVED:RW:24:1:=0x00 RESERVED:RW:16:1:=0x01 OPTIMAL_RMODW_EN:RW:8:1:=0x01 ADDRESS_MIRRORING:RW:0:2:=0x00
     41, 0x00000000, // CA_PARITY_ERROR_INJECT:RW:0:25:=0x00000000
     42, 0x00000000, // AREFRESH:WR:24:1:=0x00 RESERVED:RW:16:3:=0x00 RESERVED:RW+:8:3:=0x00 CA_PARITY_ERROR:RD:0:1:=0x00
     43, 0x01180100, // TRFC_F0:RW:16:10:=0x0118 TREF_ENABLE:RW:8:1:=0x01 RESERVED:RW:0:1:=0x00
     44, 0x00001858, // TREF_F0:RW:0:20:=0x001858
     45, 0x00000118, // TRFC_F1:RW:0:10:=0x0118
     46, 0x00001858, // TREF_F1:RW:0:20:=0x001858
     47, 0x00000005, // TREF_INTERVAL:RW:0:20:=0x000005
     48, 0x00050005, // TPDEX_F1:RW:16:16:=0x0005 TPDEX_F0:RW:0:16:=0x0005
     49, 0x00140014, // TXPDLL_F1:RW:16:16:=0x0014 TXPDLL_F0:RW:0:16:=0x0014
     50, 0x00000000, // TXARDS_F0:RW:16:16:=0x0000 TXARD_F0:RW:0:16:=0x0000
     51, 0x00000000, // TXARDS_F1:RW:16:16:=0x0000 TXARD_F1:RW:0:16:=0x0000
     52, 0x02000000, // TXSR_F0:RW:16:16:=0x0200 TMRRI_F1:RW:8:8:=0x00 TMRRI_F0:RW:0:8:=0x00
     53, 0x02000120, // TXSR_F1:RW:16:16:=0x0200 TXSNR_F0:RW:0:16:=0x0120
     54, 0x00000120, // SREFRESH_EXIT_NO_REFRESH:RW:24:1:=0x00 PWRUP_SREFRESH_EXIT:RW:16:1:=0x00 TXSNR_F1:RW:0:16:=0x0120
     55, 0x08000001, // CKSRE_F0:RW:24:8:=0x08 LOWPOWER_REFRESH_ENABLE:RW:16:2:=0x00 CKE_DELAY:RW:8:3:=0x00 ENABLE_QUICK_SREFRESH:RW:0:1:=0x01
     56, 0x00080808, // LP_CMD:WR:24:8:=0x00 CKSRX_F1:RW:16:8:=0x08 CKSRE_F1:RW:8:8:=0x08 CKSRX_F0:RW:0:8:=0x08
     57, 0x00000000, // LP_AUTO_EXIT_EN:RW:24:3:=0x00 LP_AUTO_ENTRY_EN:RW:16:3:=0x00 LP_ARB_STATE:RD:8:4:=0x00 LP_STATE:RD:0:6:=0x00
     58, 0x00000000, // LP_AUTO_SR_IDLE:RW:24:8:=0x00 LP_AUTO_PD_IDLE:RW:8:12:=0x0000 LP_AUTO_MEM_GATE_EN:RW:0:2:=0x00
     59, 0x00010000, // FREQ_CHANGE_DLL_OFF:RW:24:2:=0x00 FREQ_CHANGE_ENABLE:RW:16:1:=0x01 RESERVED:RW:8:8:=0x00 LP_AUTO_SR_MC_GATE_IDLE:RW:0:8:=0x00
     60, 0x10040010, // TDFI_INIT_START_F1:RW:24:8:=0x10 TDFI_INIT_COMPLETE_F0:RW:8:16:=0x0400 TDFI_INIT_START_F0:RW:0:8:=0x10
     61, 0x00000400, // DFS_PHY_REG_WRITE_EN:RW:24:1:=0x00 CURRENT_REG_COPY:RD:16:1:=0x00 TDFI_INIT_COMPLETE_F1:RW:0:16:=0x0400
     62, 0x00000200, // DFS_PHY_REG_WRITE_ADDR:RW:0:32:=0x00000200
     63, 0x00000000, // DFS_PHY_REG_WRITE_DATA_F0:RW:0:32:=0x00000000
     64, 0x00000001, // DFS_PHY_REG_WRITE_DATA_F1:RW:0:32:=0x00000001
     65, 0x00000000, // WRITE_MODEREG:RW+:0:26:=0x00000000
     66, 0x00000000, // READ_MODEREG:RW+:8:17:=0x000000 MRW_STATUS:RD:0:8:=0x00
     67, 0x00000000, // PERIPHERAL_MRR_DATA:RD:0:40:=0x00000000
     68, 0x00000000, // AUTO_TEMPCHK_VAL_0:RD:8:16:=0x0000 PERIPHERAL_MRR_DATA:RD:0:40:=0x00
     69, 0x00000000, // AUTO_TEMPCHK_VAL_1:RD:0:16:=0x0000
     70, 0x00000000, // REFRESH_PER_AUTO_TEMPCHK:RW:16:16:=0x0000
     71, 0x00000000, // READ_MPR:RW+:8:4:=0x00 RESERVED:RW:0:1:=0x00
     72, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     73, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00000000
     74, 0x00000000, // MPRR_DATA_0:RD:0:72:=0x00
     75, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     76, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00000000
     77, 0x00000000, // MPRR_DATA_1:RD:0:72:=0x00
     78, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     79, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00000000
     80, 0x00000000, // MPRR_DATA_2:RD:0:72:=0x00
     81, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     82, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00000000
     83, 0x00000000, // MPRR_DATA_3:RD:0:72:=0x00
     84, 0x00000c70, // MR0_DATA_F0_0:RW:0:17:=0x000c70
     85, 0x00000046, // MR1_DATA_F0_0:RW:0:17:=0x000046
     86, 0x00000018, // MR2_DATA_F0_0:RW:0:17:=0x000018
     87, 0x00000c70, // MR0_DATA_F1_0:RW:0:17:=0x000c70
     88, 0x00000046, // MR1_DATA_F1_0:RW:0:17:=0x000046
     89, 0x00000018, // MR2_DATA_F1_0:RW:0:17:=0x000018
     90, 0x00000000, // MRSINGLE_DATA_0:RW:0:17:=0x000000
     92, 0x00000000, // MR4_DATA_0:RW:0:17:=0x000000
     93, 0x00000000, // MR5_DATA_F0_0:RW:0:17:=0x000000
     94, 0x00000000, // MR5_DATA_F1_0:RW:0:17:=0x000000
     95, 0x00000000, // MR6_DATA_F0_0:RW:0:17:=0x000000
     96, 0x00000000, // MR8_DATA_0:RD:24:8:=0x00 MR6_DATA_F1_0:RW:0:17:=0x000000
     97, 0x00000000, // MR17_DATA_0:RW:16:8:=0x00 MR16_DATA_0:RW:8:8:=0x00 MR11_DATA_0:RW:0:8:=0x00
     98, 0x00000c70, // MR0_DATA_F0_1:RW:0:17:=0x000c70
     99, 0x00000046, // MR1_DATA_F0_1:RW:0:17:=0x000046
    100, 0x00000018, // MR2_DATA_F0_1:RW:0:17:=0x000018
    101, 0x00000c70, // MR0_DATA_F1_1:RW:0:17:=0x000c70
    102, 0x00000046, // MR1_DATA_F1_1:RW:0:17:=0x000046
    103, 0x00000018, // MR2_DATA_F1_1:RW:0:17:=0x000018
    104, 0x00000000, // MRSINGLE_DATA_1:RW:0:17:=0x000000
    106, 0x00000000, // MR4_DATA_1:RW:0:17:=0x000000
    107, 0x00000000, // MR5_DATA_F0_1:RW:0:17:=0x000000
    108, 0x00000000, // MR5_DATA_F1_1:RW:0:17:=0x000000
    109, 0x00000000, // MR6_DATA_F0_1:RW:0:17:=0x000000
    110, 0x00000000, // MR8_DATA_1:RD:24:8:=0x00 MR6_DATA_F1_1:RW:0:17:=0x000000
    111, 0x00000000, // MR17_DATA_1:RW:16:8:=0x00 MR16_DATA_1:RW:8:8:=0x00 MR11_DATA_1:RW:0:8:=0x00
    139, 0x00000000, // RL3_SUPPORT_EN:RD:24:2:=0x00
    140, 0x01000000, // BIST_DATA_CHECK:RW:24:1:=0x01 ADDR_SPACE:RW:16:6:=0x00 BIST_RESULT:RD:8:2:=0x00 BIST_GO:WR:0:1:=0x00
    141, 0x00000001, // BIST_ADDR_CHECK:RW:0:1:=0x01
    142, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00000000
    143, 0x00000000, // BIST_START_ADDRESS:RW:0:35:=0x00
    144, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
    145, 0x00000000, // BIST_DATA_MASK:RW:0:64:=0x00000000
#ifdef CONFIG_IPROC_DDR_ECC
    146, 0x00000001, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x01
#else
    146, 0x00000000, // FWC:WR:8:1:=0x00 ECC_EN:RW:0:1:=0x00
#endif
    147, 0x00000000, // XOR_CHECK_BITS:RW:0:16:=0x0000
    148, 0x00000000, // ECC_DISABLE_W_UC_ERR:RW:0:1:=0x00
    149, 0x00000000, // ECC_U_ADDR:RD:0:35:=0x00000000
    150, 0x00000000, // ECC_U_SYND:RD:8:8:=0x00 ECC_U_ADDR:RD:0:35:=0x00
    152, 0x00000000, // ECC_C_ADDR:RD:0:35:=0x00000000
    153, 0x00000000, // ECC_C_SYND:RD:8:8:=0x00 ECC_C_ADDR:RD:0:35:=0x00
    155, 0x00000000, // ECC_U_ID:RD:0:22:=0x000000
    156, 0x00000000, // LONG_COUNT_MASK:RW:24:5:=0x00 ECC_C_ID:RD:0:22:=0x000000
    157, 0x01000200, // ZQCL_F0:RW:16:12:=0x0100 ZQINIT_F0:RW_D:0:12:=0x0200
    158, 0x02000040, // ZQINIT_F1:RW_D:16:12:=0x0200 ZQCS_F0:RW:0:12:=0x0040
    159, 0x00400100, // ZQCS_F1:RW:16:12:=0x0040 ZQCL_F1:RW:0:12:=0x0100
    160, 0x00000200, // ZQ_ON_SREF_EXIT:RW:8:4:=0x02 ZQ_REQ:WR:0:4:=0x00
    161, 0x00000040, // ZQ_INTERVAL:RW:0:32:=0x00000040
    162, 0x00000000, // ZQRESET_F0:RW:8:12:=0x0000 ZQ_IN_PROGRESS:RD:0:1:=0x00
    163, 0x01000000, // ZQCS_ROTATE:RW:24:1:=0x01 NO_ZQ_INIT:RW:16:1:=0x00 ZQRESET_F1:RW:0:12:=0x0000
    164, 0x0a020101, // APREBIT:RW_D:24:4:=0x0a COL_DIFF:RW:16:4:=0x02 ROW_DIFF:RW:8:3:=0x01 BANK_DIFF:RW:0:2:=0x01
    165, 0x0101ffff, // ADDR_COLLISION_MPM_DIS:RW:24:1:=0x01 ADDR_CMP_EN:RW:16:1:=0x01 COMMAND_AGE_COUNT:RW:8:8:=0xff AGE_COUNT:RW:0:8:=0xff
    166, 0x01010101, // RW_SAME_EN:RW:24:1:=0x01 PRIORITY_EN:RW:16:1:=0x01 PLACEMENT_EN:RW:8:1:=0x01 BANK_SPLIT_EN:RW:0:1:=0x01
    167, 0x01010101, // DISABLE_RW_GROUP_W_BNK_CONFLICT:RW:24:2:=0x01 W2R_SPLIT_EN:RW:16:1:=0x01 CS_SAME_EN:RW:8:1:=0x01 RW_SAME_PAGE_EN:RW:0:1:=0x01
    168, 0x00000103, // INHIBIT_DRAM_CMD:RW:24:2:=0x00 DISABLE_RD_INTERLEAVE:RW:16:1:=0x00 SWAP_EN:RW:8:1:=0x01 NUM_Q_ENTRIES_ACT_DISABLE:RW:0:3:=0x03
    169, 0x00000c03, // BURST_ON_FLY_BIT:RW:8:4:=0x0c CS_MAP:RW:0:2:=0x03
#ifdef CONFIG_DDR32
    170, 0x00000000, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x00
#else
    170, 0x00000001, // MEMDATA_RATIO_1:RW:24:3:=0x00 MEMDATA_RATIO_0:RW:16:3:=0x00 LPDDR2_S4:RW:8:1:=0x00 REDUC:RW:0:1:=0x01
#endif
    171, 0x00000000, // IN_ORDER_ACCEPT:RW:24:1:=0x00 Q_FULLNESS:RW:16:3:=0x00
    172, 0x01000000, // CTRLUPD_REQ_PER_AREF_EN:RW:24:1:=0x01 CTRLUPD_REQ:WR:16:1:=0x00 CONTROLLER_BUSY:RD:8:1:=0x00 WR_ORDER_REQ:RW:0:2:=0x00
    173, 0x00000100, // DFI_ERROR:RD:16:6:=0x00 RD_PREAMBLE_TRAINING_EN:RW:8:1:=0x01 PREAMBLE_SUPPORT:RW:0:2:=0x00
    174, 0x00000000, // BG_ROTATE_EN:RW:24:1:=0x00 DFI_ERROR_INFO:RD:0:24:=0x000000
    175, 0x00000000, // INT_STATUS:RD:0:36:=0x00000000
    176, 0x00000000, // INT_STATUS:RD:0:36:=0x00
    177, 0x00000000, // INT_ACK:WR:0:35:=0x00000000
    178, 0x00000000, // INT_ACK:WR:0:35:=0x00
    179, 0x00000000, // INT_MASK:RW:0:36:=0x00000000
    180, 0x00000000, // INT_MASK:RW:0:36:=0x00
    181, 0x00000000, // OUT_OF_RANGE_ADDR:RD:0:35:=0x00000000
    182, 0x00000000, // OUT_OF_RANGE_TYPE:RD:16:6:=0x00 OUT_OF_RANGE_LENGTH:RD:8:7:=0x00 OUT_OF_RANGE_ADDR:RD:0:35:=0x00
    183, 0x00000000, // OUT_OF_RANGE_SOURCE_ID:RD:0:22:=0x000000
    184, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    185, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    186, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    187, 0x00000000, // BIST_EXP_DATA:RD:0:128:=0x00000000
    188, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    189, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    190, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    191, 0x00000000, // BIST_FAIL_DATA:RD:0:128:=0x00000000
    192, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00000000
    193, 0x00000000, // BIST_FAIL_ADDR:RD:0:35:=0x00
    194, 0x00000000, // PORT_CMD_ERROR_ADDR:RD:0:35:=0x00000000
    195, 0x00000000, // PORT_CMD_ERROR_ID:RD:8:22:=0x000000 PORT_CMD_ERROR_ADDR:RD:0:35:=0x00
    196, 0x01010200, // ODT_RD_MAP_CS1:RW:24:2:=0x01 ODT_WR_MAP_CS0:RW:16:2:=0x01 ODT_RD_MAP_CS0:RW:8:2:=0x02 PORT_CMD_ERROR_TYPE:RD:0:2:=0x00
    197, 0x00000002, // ODT_WR_MAP_CS1:RW:0:2:=0x02
    198, 0x06070700, // TODTH_WR:RW:24:4:=0x06 TODTL_2CMD_F1:RW:16:5:=0x07 TODTL_2CMD_F0:RW:8:5:=0x07
    199, 0x00000106, // TODTOFF_MAX:RW:24:8:=0x00 EN_ODT_ASSERT_EXCEPT_RD:RW:16:1:=0x00 ODT_EN:RW:8:1:=0x01 TODTH_RD:RW:0:4:=0x06
    200, 0x03030000, // RD_TO_ODTH_F1:RW:24:6:=0x03 RD_TO_ODTH_F0:RW:16:6:=0x03 WR_TO_ODTH_F1:RW:8:6:=0x00 WR_TO_ODTH_F0:RW:0:6:=0x00
    201, 0x02020002, // ADD_ODT_CLK_SAMETYPE_DIFFCS:RW:24:4:=0x02 ADD_ODT_CLK_DIFFTYPE_DIFFCS:RW:16:6:=0x02 ADD_ODT_CLK_W2R_SAMECS:RW:8:4:=0x00 ADD_ODT_CLK_R2W_SAMECS:RW:0:4:=0x02
    202, 0x02020101, // W2R_DIFFCS_DLY_F0:RW_D:24:3:=0x02 R2W_DIFFCS_DLY:RW_D:16:3:=0x02 R2R_DIFFCS_DLY_F1:RW_D:8:3:=0x01 R2R_DIFFCS_DLY_F0:RW_D:0:3:=0x01
    203, 0x02000102, // R2W_SAMECS_DLY:RW_D:24:3:=0x02 R2R_SAMECS_DLY:RW:16:3:=0x00 W2W_DIFFCS_DLY:RW_D:8:3:=0x01 W2R_DIFFCS_DLY_F1:RW_D:0:3:=0x02
    204, 0x00000000, // TDQSCK_MIN_F0:RW:24:2:=0x00 TDQSCK_MAX_F0:RW:16:4:=0x00 W2W_SAMECS_DLY:RW:8:3:=0x00 W2R_SAMECS_DLY:RW:0:3:=0x00
    205, 0x00000000, // OCD_ADJUST_PUP_CS_0:RW:24:5:=0x00 OCD_ADJUST_PDN_CS_0:RW:16:5:=0x00 TDQSCK_MIN_F1:RW:8:2:=0x00 TDQSCK_MAX_F1:RW:0:4:=0x00
    206, 0x00000000, // SWLVL_EXIT:WR:24:1:=0x00 SWLVL_START:WR:16:1:=0x00 SWLVL_LOAD:WR:8:1:=0x00 SW_LEVELING_MODE:RW:0:2:=0x00
    207, 0x00000000, // SWLVL_RESP_2:RD:24:1:=0x00 SWLVL_RESP_1:RD:16:1:=0x00 SWLVL_RESP_0:RD:8:1:=0x00 SWLVL_OP_DONE:RD:0:1:=0x00
    208, 0x00000000, // WRLVL_CS:RW:24:1:=0x00 WRLVL_REQ:WR:16:1:=0x00 SWLVL_RESP_4:RD:8:1:=0x00 SWLVL_RESP_3:RD:0:1:=0x00
    209, 0x0000280d, // WRLVL_EN:RW:16:1:=0x00 WLMRD:RW:8:6:=0x28 WLDQSEN:RW:0:6:=0x0d
    210, 0x00010000, // WRLVL_PERIODIC:RW:24:1:=0x00 DFI_PHY_WRLVL_MODE:RW:16:1:=0x01 WRLVL_INTERVAL:RW:0:16:=0x0000
    211, 0x00010000, // WRLVL_ROTATE:RW:24:1:=0x00 WRLVL_AREF_EN:RW:16:1:=0x01 WRLVL_RESP_MASK:RW:8:5:=0x00 WRLVL_ON_SREF_EXIT:RW:0:1:=0x00
    212, 0x00000003, // RDLVL_GATE_REQ:WR:24:1:=0x00 RDLVL_REQ:WR:16:1:=0x00 WRLVL_ERROR_STATUS:RD:8:2:=0x00 WRLVL_CS_MAP:RW:0:2:=0x03
    213, 0x00000000, // RDLVL_CS:RW:0:1:=0x00
    214, 0x00000000, // RDLVL_PAT_0:RW:0:32:=0x00000000
    215, 0x00000000, // RDLVL_FORMAT_0:RW:0:2:=0x00
    216, 0x00000000, // RDLVL_PAT_1:RW:0:32:=0x00000000
    217, 0x00000000, // RDLVL_FORMAT_1:RW:0:2:=0x00
    218, 0x00000000, // RDLVL_PAT_2:RW:0:32:=0x00000000
    219, 0x00000000, // RDLVL_FORMAT_2:RW:0:2:=0x00
    220, 0x00000000, // RDLVL_PAT_3:RW:0:32:=0x00000000
    221, 0x01000000, // DFI_PHY_RDLVL_MODE:RW:24:1:=0x01 RDLVL_GATE_SEQ_EN:RW:16:4:=0x00 RDLVL_SEQ_EN:RW:8:4:=0x00 RDLVL_FORMAT_3:RW:0:2:=0x00
    222, 0x00000001, // RDLVL_GATE_PERIODIC:RW:24:1:=0x00 RDLVL_ON_SREF_EXIT:RW:16:1:=0x00 RDLVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_RDLVL_GATE_MODE:RW:0:1:=0x01
    223, 0x00000100, // RDLVL_ROTATE:RW:24:1:=0x00 RESERVED:RW:16:1:=0x00 RDLVL_AREF_EN:RW:8:1:=0x01 RDLVL_GATE_ON_SREF_EXIT:RW:0:1:=0x00
    224, 0x00030300, // CALVL_REQ:WR:24:1:=0x00 RDLVL_GATE_CS_MAP:RW:16:2:=0x03 RDLVL_CS_MAP:RW:8:2:=0x03 RDLVL_GATE_ROTATE:RW:0:1:=0x00
    225, 0x0556AA00, // CALVL_PAT_0:RW:8:20:=0x0556AA CALVL_CS:RW:0:1:=0x00
    226, 0x000aa955, // CALVL_BG_PAT_0:RW:0:20:=0x0aa955
    227, 0x000aa955, // CALVL_PAT_1:RW:0:20:=0x0aa955
    228, 0x000556aa, // CALVL_BG_PAT_1:RW:0:20:=0x0556aa
    229, 0x000556aa, // CALVL_PAT_2:RW:0:20:=0x0556aa
    230, 0x000aa955, // CALVL_BG_PAT_2:RW:0:20:=0x0aa955
    231, 0x000aa955, // CALVL_PAT_3:RW:0:20:=0x0aa955
    232, 0x030556aa, // CALVL_SEQ_EN:RW:24:2:=0x03 CALVL_BG_PAT_3:RW:0:20:=0x0556aa
    233, 0x01000001, // CALVL_AREF_EN:RW:24:1:=0x01 CALVL_ON_SREF_EXIT:RW:16:1:=0x00 CALVL_PERIODIC:RW:8:1:=0x00 DFI_PHY_CALVL_MODE:RW:0:1:=0x01
    234, 0x00010300, // VREF_EN:RW:24:1:=0x00 VREF_CS:RW:16:1:=0x01 CALVL_CS_MAP:RW:8:2:=0x03 CALVL_ROTATE:RW:0:1:=0x00
    235, 0x00676700, // VREF_VAL_DEV0_1:RW:16:7:=0x67 VREF_VAL_DEV0_0:RW:8:7:=0x67 VREF_PDA_EN:RW:0:1:=0x00
    236, 0x00676700, // VREF_VAL_DEV1_1:RW:16:7:=0x67 VREF_VAL_DEV1_0:RW:8:7:=0x67
    237, 0x00676700, // VREF_VAL_DEV2_1:RW:16:7:=0x67 VREF_VAL_DEV2_0:RW:8:7:=0x67
    238, 0x00676700, // VREF_VAL_DEV3_1:RW:16:7:=0x67 VREF_VAL_DEV3_0:RW:8:7:=0x67
    239, 0x00676700, // VREF_VAL_DEV4_1:RW:16:7:=0x67 VREF_VAL_DEV4_0:RW:8:7:=0x67
    240, 0x00676700, // VREF_VAL_DEV5_1:RW:16:7:=0x67 VREF_VAL_DEV5_0:RW:8:7:=0x67
    241, 0x00676700, // VREF_VAL_DEV6_1:RW:16:7:=0x67 VREF_VAL_DEV6_0:RW:8:7:=0x67
    242, 0x00676700, // VREF_VAL_DEV7_1:RW:16:7:=0x67 VREF_VAL_DEV7_0:RW:8:7:=0x67
    243, 0x00676700, // VREF_VAL_ECC_DEV0_1:RW:16:7:=0x67 VREF_VAL_ECC_DEV0_0:RW:8:7:=0x67
    245, 0x01000000, // AXI0_R_PRIORITY:RW:24:3:=0x01 AXI0_FIXED_PORT_PRIORITY_ENABLE:RW:16:1:=0x00 AXI0_ALL_STROBES_USED_ENABLE:RW:8:1:=0x00
    246, 0x00000001, // AXI1_FIXED_PORT_PRIORITY_ENABLE:RW:24:1:=0x00 AXI1_ALL_STROBES_USED_ENABLE:RW:16:1:=0x00 AXI0_FIFO_TYPE_REG:RW:8:2:=0x00 AXI0_W_PRIORITY:RW:0:3:=0x01
    247, 0x00000101, // AXI2_ALL_STROBES_USED_ENABLE:RW:24:1:=0x00 AXI1_FIFO_TYPE_REG:RW:16:2:=0x00 AXI1_W_PRIORITY:RW:8:3:=0x01 AXI1_R_PRIORITY:RW:0:3:=0x01
    248, 0x00010100, // AXI2_FIFO_TYPE_REG:RW:24:2:=0x00 AXI2_W_PRIORITY:RW:16:3:=0x01 AXI2_R_PRIORITY:RW:8:3:=0x01 AXI2_FIXED_PORT_PRIORITY_ENABLE:RW:0:1:=0x00
    249, 0x03000000, // AXI0_PRIORITY0_RELATIVE_PRIORITY:RW:24:4:=0x03 WRR_PARAM_VALUE_ERR:RD:16:4:=0x00 WEIGHTED_ROUND_ROBIN_WEIGHT_SHARING:RW:8:1:=0x00 WEIGHTED_ROUND_ROBIN_LATENCY_CONTROL:RW:0:1:=0x00
    250, 0x03030303, // AXI0_PRIORITY4_RELATIVE_PRIORITY:RW:24:4:=0x03 AXI0_PRIORITY3_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY2_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY1_RELATIVE_PRIORITY:RW:0:4:=0x03
    251, 0x00030303, // AXI0_PORT_ORDERING:RW:24:2:=0x00 AXI0_PRIORITY7_RELATIVE_PRIORITY:RW:16:4:=0x03 AXI0_PRIORITY6_RELATIVE_PRIORITY:RW:8:4:=0x03 AXI0_PRIORITY5_RELATIVE_PRIORITY:RW:0:4:=0x03
    252, 0x02020064, // AXI1_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI0_PRIORITY_RELAX:RW:0:10:=0x0064
    253, 0x02020202, // AXI1_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x02 AXI1_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x02 AXI1_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x02
    254, 0x00010202, // AXI1_PORT_ORDERING:RW:16:2:=0x01 AXI1_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x02 AXI1_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x02
    255, 0x01010064, // AXI2_PRIORITY1_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY0_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI1_PRIORITY_RELAX:RW:0:10:=0x0064
    256, 0x01010101, // AXI2_PRIORITY5_RELATIVE_PRIORITY:RW:24:4:=0x01 AXI2_PRIORITY4_RELATIVE_PRIORITY:RW:16:4:=0x01 AXI2_PRIORITY3_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY2_RELATIVE_PRIORITY:RW:0:4:=0x01
    257, 0x00020101, // AXI2_PORT_ORDERING:RW:16:2:=0x02 AXI2_PRIORITY7_RELATIVE_PRIORITY:RW:8:4:=0x01 AXI2_PRIORITY6_RELATIVE_PRIORITY:RW:0:4:=0x01
    258, 0x00000064, // MEM_RST_VALID:RD:24:1:=0x00 CKE_STATUS:RD:16:2:=0x00 AXI2_PRIORITY_RELAX:RW:0:10:=0x0064
    259, 0x00000000, // TDFI_PHY_WRLAT:RD:24:7:=0x00 DLL_RST_ADJ_DLY:RW:16:8:=0x00 DLL_RST_DELAY:RW:0:16:=0x0000
    260, 0x000e0e00, // TDFI_RDDATA_EN:RD:24:7:=0x00 TDFI_PHY_RDLAT_F1:RW_D:16:7:=0x0e TDFI_PHY_RDLAT_F0:RW_D:8:7:=0x0e UPDATE_ERROR_STATUS:RD:0:7:=0x00
    261, 0x00000000, // TDFI_CTRLUPD_MIN:RD:8:4:=0x00 DRAM_CLK_DISABLE:RW:0:2:=0x00
    262, 0x000030b0, // TDFI_CTRLUPD_MAX_F0:RW:0:20:=0x0030b0
    263, 0x02000200, // TDFI_PHYUPD_TYPE1_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F0:RW:0:16:=0x0200
    264, 0x02000200, // TDFI_PHYUPD_TYPE3_F0:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F0:RW:0:16:=0x0200
    265, 0x000030b0, // TDFI_PHYUPD_RESP_F0:RW:0:20:=0x0030b0
    266, 0x0000f370, // TDFI_CTRLUPD_INTERVAL_F0:RW:0:32:=0x0000f370
    267, 0x0000080a, // WRLAT_ADJ_F0:RW:8:7:=0x08 RDLAT_ADJ_F0:RW:0:7:=0x0a
    268, 0x000030b0, // TDFI_CTRLUPD_MAX_F1:RW:0:20:=0x0030b0
    269, 0x02000200, // TDFI_PHYUPD_TYPE1_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE0_F1:RW:0:16:=0x0200
    270, 0x02000200, // TDFI_PHYUPD_TYPE3_F1:RW:16:16:=0x0200 TDFI_PHYUPD_TYPE2_F1:RW:0:16:=0x0200
    271, 0x000030b0, // TDFI_PHYUPD_RESP_F1:RW:0:20:=0x0030b0
    272, 0x0000f370, // TDFI_CTRLUPD_INTERVAL_F1:RW:0:32:=0x0000f370
    273, 0x0202080a, // TDFI_CTRL_DELAY_F1:RW_D:24:4:=0x02 TDFI_CTRL_DELAY_F0:RW_D:16:4:=0x02 WRLAT_ADJ_F1:RW:8:7:=0x08 RDLAT_ADJ_F1:RW:0:7:=0x0a
    274, 0x000a0100, // TDFI_WRLVL_EN:RW:16:8:=0x0a TDFI_DRAM_CLK_ENABLE:RW:8:4:=0x01 TDFI_DRAM_CLK_DISABLE:RW:0:4:=0x00
    275, 0x0000000a, // TDFI_WRLVL_WW:RW:0:10:=0x000a
    276, 0x00000000, // TDFI_WRLVL_RESP:RW:0:32:=0x00000000
    277, 0x00000000, // TDFI_WRLVL_MAX:RW:0:32:=0x00000000
    278, 0x00000f0a, // TDFI_RDLVL_RR:RW:8:10:=0x000f TDFI_RDLVL_EN:RW:0:8:=0x0a
    279, 0x00000000, // TDFI_RDLVL_RESP:RW:0:32:=0x00000000
    280, 0x00000000, // RDLVL_GATE_EN:RW:16:1:=0x00 RDLVL_EN:RW:8:1:=0x00 RDLVL_RESP_MASK:RW:0:5:=0x00
    281, 0x00000000, // TDFI_RDLVL_MAX:RW:0:32:=0x00000000
    282, 0x00000000, // RDLVL_ERROR_STATUS:RD:0:22:=0x000000
    283, 0x00000000, // RDLVL_GATE_INTERVAL:RW:16:16:=0x0000 RDLVL_INTERVAL:RW:0:16:=0x0000
    284, 0x00000103, // TDFI_CALVL_CC_F0:RW:8:10:=0x0001 TDFI_CALVL_EN:RW:0:8:=0x03
    285, 0x00010003, // TDFI_CALVL_CC_F1:RW:16:10:=0x0001 TDFI_CALVL_CAPTURE_F0:RW:0:10:=0x0003
    286, 0x00000003, // TDFI_CALVL_CAPTURE_F1:RW:0:10:=0x0003
    287, 0x00000000, // TDFI_CALVL_RESP:RW:0:32:=0x00000000
    288, 0x00000000, // TDFI_CALVL_MAX:RW:0:32:=0x00000000
    289, 0x00000000, // CALVL_ERROR_STATUS:RD:16:2:=0x00 CALVL_EN:RW:8:1:=0x00 CALVL_RESP_MASK:RW:0:1:=0x00
    290, 0x0a000000, // TDFI_RDCSLAT_F0:RW:24:4:=0x0a TDFI_PHY_WRDATA:RW:16:3:=0x01 CALVL_INTERVAL:RW:0:16:=0x0000
    291, 0x00070a07, // TDFI_PARIN_LAT:RW:24:3:=0x00 TDFI_WRCSLAT_F1:RW:16:4:=0x07 TDFI_RDCSLAT_F1:RW:8:4:=0x0a TDFI_WRCSLAT_F0:RW:0:4:=0x07
    292, 0x00000000, // USER_DEF_REG_0:RW:0:32:=0x00000000
    293, 0x00000000, // USER_DEF_REG_1:RW:0:32:=0x00000000
    294, 0x00000000, // USER_DEF_REG_RO_0:RD:0:32:=0x00000000
    295, 0x00000000, // USER_DEF_REG_RO_1:RD:0:32:=0x00000000
    296, 0x00000000, // DFS_PHY_REG_WRITE_MASK:RW:8:4:=0x00 EN_1T_TIMING:RW:0:1:=0x00
    297, 0x00000000, // MR3_DATA_F0_0:RW:0:17:=0x000000
    298, 0x00000000, // MR3_DATA_F1_0:RW:0:17:=0x000000
    299, 0x00000000, // MR3_DATA_F0_1:RW:0:17:=0x000000
    300, 0x00000000, // MR3_DATA_F1_1:RW:0:17:=0x000000
    301, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    302, 0x00000000, // ECC_U_DATA:RD:0:64:=0x00000000
    303, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    304, 0x00000000, // ECC_C_DATA:RD:0:64:=0x00000000
    0xffffffff
};

/* Reference clock is fixed at 50MHz */
unsigned int ddr_clk_tab[] = {
    /*  clk,    ndiv,    MDIV
                         0    1    2    3    4    5 */
    0xffffffff
};

/* 
 * DDR2 not supported 
 */

unsigned int ddr2_init_tab[] = { 
    0xffffffff
};

unsigned int ddr2_init_tab_667[] = { 
    0xffffffff
};

unsigned int ddr2_init_tab_800[] = { 
    0xffffffff
};

unsigned int ddr2_init_tab_1066[] = { 
    0xffffffff
};

unsigned int ddr_phy_ctl_ovrd_tab[] = {
0xffffffff
};

unsigned int ddr_phy_wl0_tab[] = {
0xffffffff
};

#endif /* !CONFIG_IPROC_NO_DDR */
