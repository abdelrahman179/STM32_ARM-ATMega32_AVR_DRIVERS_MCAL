/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 19 September 2020                                                           */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 USART Communication Protocol user manual        */
/****************************************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/* System Clock */
#define F_CPU                    8000000UL

/* USART1_Configuration */
#define USART1_STATUS            USART1_ENABLE

/*  Baud Rate Configuration
     Options : - 4800
               - 9600 
               - 115200  */
#define USART1_BAUD_RATE         (u32)9600

/* Word Length 
    Options : - _8BIT_WORD_LENGTH
              - _9BIT_WORD_LENGTH  */
#define USART1_WORD_LENGTH       _8BIT_WORD_LENGTH

/* Parity Check Bit 
    Options: - PARITY_DISABLE
             - EVEN_PARITY
             - ODD_PARITY     */
#define USART1_PARITY            PARITY_DISABLE

/* USART1 Interrupt Configuration 
    Options : - INT_DISABLE
              - TXE_INT_ENABLE
              - TCE_INT_ENABLE
              - RXNE_INT_ENABLE    */
#define USART1_INTERRUPT         INT_DISABLE

/* Fire an interrupt on Transmission 
    Options : - TRANSMITTER_DISABLE 
              - TRANSMITTER_ENABLE         */
#define USART1_TRANSMITTER       TRANSMITTER_ENABLE

/* Fire an interrupt on Receiving 
    Options : - RECEIVER_DISABLE 
              - RECEIVER_ENABLE         */
#define USART1_RECEIVER          RECEIVER_ENABLE

/* Stop Bit Configurations 
    Options : - ONE_STOP_BIT
              - HALF_STOP_BIT 
              - TWO_STOP_BIT
              - ONE_AND_HALF_STOP_BIT    */
#define USART1_STOP_BITS         ONE_STOP_BIT






#endif
