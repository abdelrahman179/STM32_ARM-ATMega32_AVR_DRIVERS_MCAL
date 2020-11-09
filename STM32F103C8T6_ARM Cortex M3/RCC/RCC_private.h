/**************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                        */
/* Date   : 8 August 2020                                                             */
/* Version: V02                                                                       */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 RCC Registers Definitions/Private Functions   */
/**************************************************************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

/* ---------------------- Register Definitions ---------------------- */
typedef struct 
{
   volatile u32 CR;             /* Clock Control Register                   */
   volatile u32 CFGR;           /* Clock Configuration Register             */
   volatile u32 CIR;            /* Clock Interrupt Register                 */
   volatile u32 APB2RSTR;       /* APB2 Peripheral Reset Register           */
   volatile u32 APB1RSTR;       /* APB1 Peripheral Reset Register           */
   volatile u32 AHBENR;         /* AHB Perihperal Clock Enable Register     */
   volatile u32 APB2ENR;        /* APB2 Perihperal Clock Enable Register    */
   volatile u32 APB1ENR;        /* APB1 Perihperal Clock Enable Register    */
   volatile u32 BDCR;           /* Backup Domain Control Register           */
   volatile u32 CSR;            /* Control/Status Register                  */
}RCC;

#define MRCC_Ptr ((volatile RCC*) 0x40021000)



#endif
