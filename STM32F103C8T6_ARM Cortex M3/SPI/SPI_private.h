/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 16 September 2020                                               */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 SPI1 registers definitions          */
/****************************************************************************/


#ifndef SPI1_PRIVATE_H
#define SPI1_PRIVATE_H

/* SPI Registers Definition */
typedef struct 
{
    volatile u32  SPI1_CR1     ;  /* Control Register: Configuration */
    volatile u32  SPI1_CR2     ;  /* Control Register: Interrupt handler */  
    volatile u32  SPI1_SR      ;  /* Status Register : Status flags */   
    volatile u32  SPI1_DR      ;  /* Data Register   : Sent/Received data register */
    volatile u32  SPI1_CRCPR   ;  /* CRC Polynomial Register : Contains the polynomial for the CRC calculation */
    volatile u32  SPI1_RXCRCR  ;  /* RX CRC register : When CRC calculation is enabled, 
                                    the RxCRC[15:0] bits contain the computed CRC value of the subsequently received bytes.*/
    volatile u32  SPI1_TXCRCR  ;  /* TX CRC register : When CRC calculation is enabled, 
                                    the TxCRC[15:0] bits contain the computed CRC value of the subsequently transmitted bytes.*/
    volatile u32  SPI1_I2SCFGR ;  /* SPI_I2S configuration register : I2S configuration */
    volatile u32  SPI1_I2SPR   ;  /* SPI_I2S configuration register : I2S prescaler configuration */
}SPI1_Register;


#define MSPI1_Ptr    ((SPI1_Register*) 0x40013000)









#endif
