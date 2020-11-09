/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 10 August 2020                                                              */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO Register addresses and private functions   */
/****************************************************************************************/

#ifndef _GDIO_PRIVATE_H_
#define _GDIO_PRIVATE_H_



typedef struct 
{
    volatile u32 CRL; // Port configuration register low Pins  0 - 15
    volatile u32 CRH; // Port configuration register high Pins 16 - 31
    volatile u32 IDR; // Port input data register
    volatile u32 ODR; // Port output data register
    volatile u32 BSR; // Port bit set/reset register 
    volatile u32 BRR; // Port bit reset register
    volatile u32 LCK; // Port configuration lock register
}GPIO;

/* Pointer of struct that points to base address of each port */
#define MGPIOA ((volatile GPIO*) 0x40010800)
#define MGPIOB ((volatile GPIO*) 0x40010C00)
#define MGPIOC ((volatile GPIO*) 0x40011000)





#endif
