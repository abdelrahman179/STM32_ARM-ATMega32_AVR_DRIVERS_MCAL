/**************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                        */
/* Date   : 19 August 2020                                                            */
/* Version: V02                                                                       */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 NVIC Register addresses and private functions */
/**************************************************************************************/

#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

        /* ------------------------ NVIC Registers Defintion ------------------------ */


                /* Base address of NVIC 0xE000E100 */ 
/* Noting that it's memory mapped as it's a core peripheral with no address */ 
typedef struct 
{
    /* Interrupt Set-Enable Reg1, Enable external interrupts from 0 to 31 && 
         Interrupt Set-Enable Reg2, Enable external interrupts from 32 to 63  */ 
    volatile u32 ISER     [32]; 
    /* Interrupt Clear-Enable Reg 1, Disable external interrupts from 32 to 63 &&
        Interrupt Clear-Enable Reg 2, Disable external interrupts from 32 to 63  */   
    volatile u32 ICER     [32];
    /* Interrupt Set Pending Reg 1, Enable pending flag from 0 to 31  &&  
        Interrupt Set Pending Reg 2, Enable pending flag from 32 to 63  */
    volatile u32 ISPR     [32];
    /* Interrupt Clear Pending Reg 1, Enable pending flag from 0 to 31  &&  
        Interrupt Clear Pending Reg 2, Enable pending flag from 32 to 63   */
    volatile u32 ICPR     [32];
    /* Interrupt Active Bit Reg 1, Reads active flag status 0 to 32  && 
         Interrupt Active Bit Reg 2, Reads active flag status 32 to 63  */
    volatile u32 IAPR     [32];
     
    volatile u32 RESERVED [32];
    /* It will not be de referenced as NVIC_IPR will be considered as a pointer
    points to the external interrupts registers,  NVIC_IPR[n] or *(NVIC_IPR+n) = value */
	volatile u8 IPR       [128];
}NVIC;

#define MNVIC_Ptr   ((volatile NVIC *) 0xE000E100)

#define MNVIC_STIR  ((volatile u32  *) 0xE000EF00)




        /* ------------------------ SCB Registers Defintion ------------------------ */

/* - System Control Block Core periphral which has Application interrupt and reset control register SCB_AIRCR
    that identify the partitioning the IPR register into groups and sub-groups
   - Application interrupt and reset control register (SCB_AIRCR)
   - Reset value 0xFA05 0000
   - bit 0: Vect Reset / bit 1: Vect Clear Active / bit 2: Sys Reset Req / bit 15 for ENDIANESS
   - From bit 3 to 7  & 12 to 14: Reserved for future use 
   - From bit 16 to bit 31 : Vect Key 0x05FA
   - Priority Group Setting bits 8,9,10 (11 is 0 as default)     */

typedef struct
{
	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;
}SCB;

#define MSCB_Ptr ((volatile SCB *) 0xE000ED00)




#endif 
