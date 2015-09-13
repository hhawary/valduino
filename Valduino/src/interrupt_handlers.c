/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  Valduino                               */
/*      FILE         :  interrupt_handlers.c                   */
/*      DESCRIPTION  :  Interrupt Handler                      */
/*      CPU SERIES   :  RL78 - F14                             */
/*      CPU TYPE     :  R5F10PPJ                               */
/*                                                             */
/*      This file is generated by e2 studio.                   */
/*                                                             */
/***************************************************************/                            
                                                                                   
/************************************************************************/
/* Header file generated from device file:                              */
/*    DR5F10PPJ.DVF                                                     */
/*    V1.10 (2014/08/05)                                                */
/*    Copyright(C) 2014 Renesas                                         */
/* Tool Version: 3.1.1                                                  */
/* Date Generated: 2015/02/20                                           */
/************************************************************************/
#include "interrupt_handlers.h"

/*
 * INT_SRO/INT_WDTI (0x4)
 */
void INT_WDTI (void) { }
//void INT_SRO (void) { }

/*
 * INT_LVI (0x6)
 */
void INT_LVI (void) { }

/*
 * INT_P0 (0x8)
 */
void INT_P0 (void) { }

/*
 * INT_P1 (0xA)
 */
void INT_P1 (void) { }

/*
 * INT_P2 (0xC)
 */
void INT_P2 (void) { }

/*
 * INT_P3 (0xE)
 */
void INT_P3 (void) { }

/*
 * INT_P4/INT_SPM (0x10)
 */
void INT_SPM (void) { }
//void INT_P4 (void) { }

/*
 * INT_CMP0/INT_P5 (0x12)
 */
void INT_P5 (void) { }
//void INT_CMP0 (void) { }

/*
 * INT_CLM/INT_P13 (0x14)
 */
void INT_P13 (void) { }
//void INT_CLM (void) { }

/*
 * INT_CSI00/INT_IIC00/INT_ST0 (0x16)
 */
void INT_ST0 (void) { }
//void INT_CSI00 (void) { }
//void INT_IIC00 (void) { }

/*
 * INT_CSI01/INT_IIC01/INT_SR0 (0x18)
 */
void INT_SR0 (void) { }
//void INT_CSI01 (void) { }
//void INT_IIC01 (void) { }

/*
 * INT_TRD0 (0x1A)
 */
void INT_TRD0 (void) { }

/*
 * INT_TRD1 (0x1C)
 */
void INT_TRD1 (void) { }

/*
 * INT_TRJ0 (0x1E)
 */
void INT_TRJ0 (void) { }

/*
 * INT_RAM (0x20)
 */
void INT_RAM (void) { }

/*
 * INT_LIN0TRM (0x22)
 */
void INT_LIN0TRM (void) { }

/*
 * INT_LIN0RVC (0x24)
 */
void INT_LIN0RVC (void) { }

/*
 * INT_LIN0/INT_LIN0STA (0x26)
 */
void INT_LIN0STA (void) { }
//void INT_LIN0 (void) { }

/*
 * INT_IICA0 (0x28)
 */
void INT_IICA0 (void) { }

/*
 * INT_P8/INT_RTC (0x2A)
 */
void INT_RTC (void) { }
//void INT_P8 (void) { }

/*
 * INT_TM00 (0x2C)
 */
void INT_TM00 (void) { }

/*
 * INT_TM01 (0x2E)
 */
void INT_TM01 (void) { }

/*
 * INT_TM02 (0x30)
 */
void INT_TM02 (void) { }

/*
 * INT_TM03 (0x32)
 */
void INT_TM03 (void) { }

/*
 * INT_AD (0x34)
 */
void INT_AD (void) { }

/*
 * INT_P6/INT_TM11H (0x36)
 */
void INT_TM11H (void) { }
//void INT_P6 (void) { }

/*
 * INT_P7/INT_TM13H (0x38)
 */
void INT_TM13H (void) { }
//void INT_P7 (void) { }

/*
 * INT_P9/INT_TM01H (0x3A)
 */
void INT_TM01H (void) { }
//void INT_P9 (void) { }

/*
 * INT_P10/INT_TM03H (0x3C)
 */
void INT_TM03H (void) { }
//void INT_P10 (void) { }

/*
 * INT_CSI10/INT_IIC10/INT_ST1 (0x3E)
 */
void INT_ST1 (void) { }
//void INT_CSI10 (void) { }
//void INT_IIC10 (void) { }

/*
 * INT_CSI11/INT_IIC11/INT_SR1 (0x40)
 */
void INT_SR1 (void) { }
//void INT_CSI11 (void) { }
//void INT_IIC11 (void) { }

/*
 * INT_TM04 (0x42)
 */
void INT_TM04 (void) { }

/*
 * INT_TM05 (0x44)
 */
void INT_TM05 (void) { }

/*
 * INT_TM06 (0x46)
 */
void INT_TM06 (void) { }

/*
 * INT_TM07 (0x48)
 */
void INT_TM07 (void) { }

/*
 * INT_LIN0WUP/INT_P11 (0x4A)
 */
void INT_P11 (void) { }
//void INT_LIN0WUP (void) { }

/*
 * INT_KR (0x4C)
 */
void INT_KR (void) { }

/*
 * INT_CAN0ERR (0x4E)
 */
void INT_CAN0ERR (void) { }

/*
 * INT_CAN0WUP (0x50)
 */
void INT_CAN0WUP (void) { }

/*
 * INT_CAN0CFR (0x52)
 */
void INT_CAN0CFR (void) { }

/*
 * INT_CAN0TRM (0x54)
 */
void INT_CAN0TRM (void) { }

/*
 * INT_CANGRFR (0x56)
 */
void INT_CANGRFR (void) { }

/*
 * INT_CANGERR (0x58)
 */
void INT_CANGERR (void) { }

/*
 * INT_TM10 (0x5A)
 */
void INT_TM10 (void) { }

/*
 * INT_TM11 (0x5C)
 */
void INT_TM11 (void) { }

/*
 * INT_TM12 (0x5E)
 */
void INT_TM12 (void) { }

/*
 * INT_TM13 (0x60)
 */
void INT_TM13 (void) { }

/*
 * INT_FL (0x62)
 */
void INT_FL (void) { }

/*
 * INT_LIN1WUP/INT_P12 (0x64)
 */
void INT_P12 (void) { }
//void INT_LIN1WUP (void) { }

/*
 * INT_LIN1TRM (0x66)
 */
void INT_LIN1TRM (void) { }

/*
 * INT_LIN1RVC (0x68)
 */
void INT_LIN1RVC (void) { }

/*
 * INT_LIN1/INT_LIN1STA (0x6A)
 */
void INT_LIN1STA (void) { }
//void INT_LIN1 (void) { }

/*
 * INT_TM14 (0x6C)
 */
void INT_TM14 (void) { }

/*
 * INT_TM15 (0x6E)
 */
void INT_TM15 (void) { }

/*
 * INT_TM16 (0x70)
 */
void INT_TM16 (void) { }

/*
 * INT_TM17 (0x72)
 */
void INT_TM17 (void) { }

/*
 * INT_BRK_I (0x7E)
 */
void INT_BRK_I (void) { }