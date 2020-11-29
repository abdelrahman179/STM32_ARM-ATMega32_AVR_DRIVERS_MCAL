/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 19 September 2020                                                           */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 USART Communication Protocol user manual        */
/****************************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* USART1_Configuration */

/*  USART_1 Setting
     Options : - USART1_ENABLE
               - USART1_DISABLE  */
#define USART1_STATUS            USART1_ENABLE

/* Fire an interrupt on Transmission 
    Options : - TRANSMITTER_DISABLE 
              - TRANSMITTER_ENABLE         */
#define USART1_TRANSMITTER       TRANSMITTER_ENABLE

/* Fire an interrupt on Receiving 
    Options : - RECEIVER_DISABLE 
              - RECEIVER_ENABLE         */
#define USART1_RECEIVER          RECEIVER_ENABLE

/*  Baud Rate Configuration
     Options : - BAUD_9600 
               - BAUD_115200  */
#define USART1_BAUD_RATE         BAUD_115200

/* Word Length 
    Options : - _8BIT_WORD_LENGTH
              - _9BIT_WORD_LENGTH  */
#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH

/* Parity Check Bit Setting
    Options: - PARITY_DISABLE
             - PARITY_ENABLE  */
#define USART1_PARITY        PARITY_DISABLE

/* Parity Check Bit Configuration
    Options: - USART1_PARITY_EVEN
             - USART1_PARITY_ODD  */
#define USART1_PARITY_TYPE       USART1_PARITY_EVEN      

/* Parity Error Check flag Interrupt
    Options: - USART_PE_DISABLED
             - USART_PE_ENABLED  */
#define PARITY_ERROR_INTERRUPT     USART_PE_DISABLED

/* USART1 Interrupt Configuration 
    Options : - INT_DISABLE
              - TXE_INT_ENABLE
              - TCE_INT_ENABLE
              - RXNE_INT_ENABLE    */
#define USART1_INTERRUPT         INT_DISABLE

/* Stop Bit Configurations 
    Options : - ONE_STOP_BIT
              - HALF_STOP_BIT 
              - TWO_STOP_BIT
              - ONE_AND_HALF_STOP_BIT    */
#define USART1_STOP_BITS         ONE_STOP_BIT






#endif
