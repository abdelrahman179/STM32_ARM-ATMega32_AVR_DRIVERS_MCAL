/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 19 September 2020                                                           */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 USART Communication Protocol public             */
/*              functions prototype                                                     */
/****************************************************************************************/


#ifndef  USART_INTERFACE_H
#define  USART_INTERFACE_H

#define USART1_DISABLE          0
#define USART1_ENABLE           1

#define BAUD_9600               0
#define BAUD_115200             1

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define PARITY_ENABLE           1

#define USART1_PARITY_EVEN      0
#define USART1_PARITY_ODD       1

#define USART_PE_DISABLED       0
#define USART_PE_ENABLED        1

#define INT_DISABLE             0
#define TXE_INT_ENABLE          1       /* Transmit Data Register is empty */
#define TCE_INT_ENABLE          3       /* Transmittion Complemte Interrupt */
#define RXNE_INT_ENABLE         5       /* Data Register not empty interrupt */

#define TRANSMITTER_DISABLE     0
#define TRANSMITTER_ENABLE      1

#define RECEIVER_DISABLE        0
#define RECEIVER_ENABLE         1

#define ONE_STOP_BIT            0
#define HALF_STOP_BIT           1
#define TWO_STOP_BIT            2
#define ONE_AND_HALF_STOP_BIT   3

/* Initialize USART */
void MUSART1_voidInit(void);

/* USART_1 Transmit a word
    i/p:  Array of Characters */
void MUSART1_voidTransmit(char* Word);

/* USART_1 Receive Data
    i/p: Threshold value not to wait the sender infinite time to send the data 
    o/p: The received data from the sender */
u8 MUSART1_u8Receive(u32 Copy_u32TimeOut);



#endif
