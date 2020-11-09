/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 26 August 2020                                                        */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Systick Registers Defintions              */
/**********************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
    /* Control and status register: Enable/Disable STK , STK Interrupt , define the CLK SRC , Read Flag */
    volatile u32 STK_CTRL;
    /* Systick reload value register */
    volatile u32 STK_LOAD;
    /* Systick current value register */
    volatile u32 STK_VAL;
    /* SysTick calibration value register */
    volatile u32 STK_CALIB;
}MSTK_Type;

#define MSTK_Ptr    ((MSTK_Type *) 0xE000E010) // Pointer to struct



#endif
