/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 03 September 2020                                                  */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Timer1 Register Defintions             */
/*******************************************************************************/


#ifndef _TIM1_PRIVATE_H_
#define _TIM1_PRIVATE_H_

/* Timer1 & Timer8 Registers */
typedef struct 
{
    volatile u32 TIM1_CR1;          /* TIM1 Control Register1  */
    volatile u32 TIM1_CR2;          /* TIM1 Control Register2  */
    volatile u32 TIM1_SMCR;         /* TIM1 Slave Mode Control Register */
    volatile u32 TIM1_DIER;         /* TIM1 DMA/Interrupt Enable Register */
    volatile u32 TIM1_SR;           /* TIM1 Status Register */
    volatile u32 TIM1_EGR;          /* TIM1 Event Generation Register  */
    volatile u32 TIM1_CCMR1;        /* TIM1 Capture Compare Mode Register1 > Channels 1 & 2 */
    volatile u32 TIM1_CCMR2;        /* TIM1 Capture Compare Mode Register2 > Channels 3 & 4 */
    volatile u32 TIM1_CCER;         /* TIM1 Capture Compare Enable Register */
    volatile u32 TIM1_CNT;          /* TIM1 Counter */
    volatile u32 TIM1_PSC;          /* TIM1 Prescaler */
    volatile u32 TIM1_ARR;          /* TIM1 Auto-Reload Register */
    volatile u32 TIM1_RCR;          /* TIM1 Repitition Counter Register */
    volatile u32 TIM1_CCR1;         /* TIM1 Capture Compare Register1 > Channel 1 */
    volatile u32 TIM1_CCR2;         /* TIM1 Capture Compare Register2 > Channel 2 */
    volatile u32 TIM1_CCR3;         /* TIM1 Capture Compare Register3 > Channel 3 */
    volatile u32 TIM1_CCR4;         /* TIM1 Capture Compare Register4 > Channel 4 */
    volatile u32 TIM1_BDTR;         /* TIM1 Break and Dead-Time Register */
    volatile u32 TIM1_DCR;          /* TIM1 DMA Control Register */
    volatile u32 TIM1_DMAR;         /* TIM1 DMA Address for Full Transfer */
}TIM1_Type;

/* Pointer to struct that points to the base address of TIM1
    and the first register offset noting that each step is by 32bits */
#define TIM1_Ptr        ((volatile TIM1_Type*) 0x40012C00)

#define UP_COUNTER   0
#define DOWN_COUNTER 1

#define EDGE_ALIGNED                 0
#define CNT_DOWN_OP_COM_INT_FLAG     1
#define CNT_UP_OP_COM_INT_FLAG       2
#define CNT_UP_DOWN_OP_COM_INT_FLAG  3


#define CH_1    0
#define CH_2    1
#define CH_3    2
#define CH_4    3

#define ACTIVE_LOW       0
#define ACTIVE_HIGH      1
#define FROZEN           3   


#endif
