/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 26 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Systick Prototypes of Public Functions */
/*******************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


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

/*------------------------------ Functions Prototype ------------------------------*/

/* Configure Clock Type from configuration file 
    disable systick interrupt, systick itself */
void MSTK_voidInit(void);  // AHB or AHB/8


/* Synchronous function to stop the processor from 
    doing anything untill the timer finish counting "Polling" 
    MSTK_voidSetBusyWait -> Hold the processor for amount of time in ms or us 
  * i/p : Time in micro Seconds based on the system clock */
void MSTK_voidSetBusyWait(u32 Copy_u32Time);


/* Asynchronous function to let the timer start counting and 
    fire an interrupt and keep repeating "el le3b f el ISR" 
    MSTK_voidSetIntervalPeriodic -> Pass a periodic function to the SysTick ISR
  * i/p : i/p : Time in micro Seconds based on the system clock,
  *   Function that will be implemented as ISR  */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Time , void (*Copy_Func)(void));


/* Stop Function -> Stop timer and disable interrupt */
void MSTK_voidStopTimer(void);

/* Resume Function -> Start timer and Enable interrupt */
void MSTK_voidResumeTimer(void);

/* Return elapsed number of counts is been counted */
u32 MSTK_u32GetElapsedTime();

/* Return counts in value register */
u32 MSTK_u32GetRemainingTime();




#endif
