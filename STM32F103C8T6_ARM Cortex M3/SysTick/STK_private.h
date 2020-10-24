/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 26 August 2020                                                        */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Systick Prototypes of private Functions   */
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
}MSTK_Type;

#define MSTK_Ptr    ((MSTK_Type *) 0xE000E010) // Pointer to struct

/* -------- CLK Options -------- */
#define AHB_CLK_SRC           0
#define AHB_CLK_SRC_Div_8     1    

/* -------- Interrupt Options -------- */
#define ENABLE           1
#define DISABLE          0

/* -------- Bits -------- */
#define STK_CTRL_ENABLE       0
#define STK_CTRL_TICKINT      1
#define STK_CTRL_CLKSOURCE    2
#define STK_CTRL_COUNTFLAG    16




#endif
