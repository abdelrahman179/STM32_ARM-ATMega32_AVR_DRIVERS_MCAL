/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 16 September 2020                                               */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 SPI1 user manual                    */
/****************************************************************************/

#ifndef SPI1_CONFIG_H
#define SPI1_CONFIG_H


/* Options:  - Enable SPI1  > MSPI1_ENABLE 
             - Disable SPI1 > MSPI1_DISABLE    */
#define MSPI1_STATUS          MSPI1_ENABLE

/* Clock Configuration
   Options:   - MSPI1_MODE0 > Read 1st, Capture on Rising Edge 
              - MSPI1_MODE1 > Write 1st, Capture on Rising Edge
              - MSPI1_MODE2 > Read 1st, Capture on Falling Edge 
              - MSPI1_MODE3 > Write 1st, Capture on Falling Edge    */
#define MSPI1_CLOCK_MODE     MSPI1_MODE3

/* Options:  - MSPI1_MASTER > SPI1 set as a Master
             - MSPI1_SLAVE  > SPI1 set as a Slave   */
#define MSPI1_MASTER_SLAVE   MSPI1_MASTER

/* Prescaler Configuration
   Options:  - MSPI1_FPCLK_DIVIDED_BY_2    > Bus CLK Divided by 2
             - MSPI1_FPCLK_DIVIDED_BY_4    > Bus CLK Divided by 4
             - MSPI1_FPCLK_DIVIDED_BY_8    > Bus CLK Divided by 8
             - MSPI1_FPCLK_DIVIDED_BY_16   > Bus CLK Divided by 16
             - MSPI1_FPCLK_DIVIDED_BY_32   > Bus CLK Divided by 32
             - MSPI1_FPCLK_DIVIDED_BY_64   > Bus CLK Divided by 64
             - MSPI1_FPCLK_DIVIDED_BY_128  > Bus CLK Divided by 128
             - MSPI1_FPCLK_DIVIDED_BY_256  > Bus CLK Divided by 256    */
#define MSPI1_PRESCALLER     MSPI1_FPCLK_DIVIDED_BY_2

/* Frame Format 
   Options:  - MSPI1_MSB_FIRST  > Most Significant is sent first
             - MSPI1_LSB_FIRST  > Least Significant is sent first   */
#define MSPI1_DATA_ORDER     MSPI1_MSB_FIRST

/* Software Slave Management Configuration 
   Instead of connecting the slave select pin to GND to activate it perminantely, 
                with SSM STM feature, SS is connected to NSS master pin to be set automatically whenever
                the master is about to send data to slave and after the Tx/Rx operation it's set 
                automatically to 1 to cut of the connection temporary 
   Options:  - HW_SLAVE_MANAGEMENT > SSM disabled, configured by hardware
             - SW_SLAVE_MANAGEMENT > SSM enabled, configured by software  */
#define MSPI1_SS_MANAGE      SW_SLAVE_MANAGEMENT


/* Data Frame Format Configuration
  Options: - MSPI1_8BIT_DATA  > 8-bit data frame format is selected for transmission/reception
           - MSPI1_16BIT_DATA > 16-bit data frame format is selected for transmission/reception  */
#define MSPI1_DATA_SIZE      MSPI1_8BIT_DATA

/* SPI Interrupt Settings 
  Options: - MSPI1_INT_DISABLE     > Disable Interrupt 
           - MSPI1_TXE_INT_ENABLE  > Generate an interrupt request when the TXE flag is set 
           - MSPI1_RXNE_INT_ENABLE > Generate an interrupt request when the RXNE flag is set */
#define MSPI1_INT_STATUS     MSPI1_INT_DISABLE





#endif
