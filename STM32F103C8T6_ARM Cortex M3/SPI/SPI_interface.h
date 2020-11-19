/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 16 September 2020                                               */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 SPI1 public functions prototypes    */
/****************************************************************************/


#ifndef SPI1_INTERFACE_H
#define SPI1_INTERFACE_H


#define MSPI1_DISABLE                 0
#define MSPI1_ENABLE                  1

#define MSPI1_MODE0                   0
#define MSPI1_MODE1                   1
#define MSPI1_MODE2                   2
#define MSPI1_MODE3                   3

#define MSPI1_MASTER                  0
#define MSPI1_SLAVE                   1

#define MSPI1_FPCLK_DIVIDED_BY_2      0b000
#define MSPI1_FPCLK_DIVIDED_BY_4      0b001
#define MSPI1_FPCLK_DIVIDED_BY_8      0b010
#define MSPI1_FPCLK_DIVIDED_BY_16     0b011
#define MSPI1_FPCLK_DIVIDED_BY_32     0b100
#define MSPI1_FPCLK_DIVIDED_BY_64     0b101
#define MSPI1_FPCLK_DIVIDED_BY_128    0b110
#define MSPI1_FPCLK_DIVIDED_BY_256    0b111

#define MSPI1_MSB_FIRST               0
#define MSPI1_LSB_FIRST 			  1

#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

#define MSPI1_8BIT_DATA              0
#define MSPI1_16BIT_DATA              1

#define MSPI1_INT_DISABLE             0
#define MSPI1_TXE_INT_ENABLE          1
#define MSPI1_RXNE_INT_ENABLE         2



/* SPI Initialization */
void MSPI1_voidInit(void);

/* Function to send/receive the SPI data */
u8 MSPI1_voidSendDataU8(u8 Copy_u8DataToTransmit); 

/* SPI interrupt callback function */
void MSPI1_voidSetCallBack(void (*ptr) (void));





#endif
