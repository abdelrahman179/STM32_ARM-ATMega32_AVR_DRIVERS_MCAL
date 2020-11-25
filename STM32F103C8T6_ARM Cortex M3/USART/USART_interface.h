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

#define _8BIT_WORD_LENGTH       0
#define _9BIT_WORD_LENGTH       1

#define PARITY_DISABLE          0
#define EVEN_PARITY             1
#define ODD_PARITY              2

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
void MUSART_voidInit(void);

/* USART_1 Send Character Synchronous */
void MUSART1_voidSendCharSync(u8 Copy_u8Char);

/* USART_1 Send String Synchronous */
void MUSART1_voidSendStringSynch(u8 * Copy_ptrString);

/* USART_1 Receive Character Synchronous */
u8   MUSART1_u8RecCharSynch(void);

/* USART_1 Receive String Synchronous */
u8 * MUSART1_PtrReadStringSynch(void);

/* USART_1 Call back on Transmittion/Receiving */
void MUSART1_voidSetCallBack(void (*ptr) (void));



#endif
