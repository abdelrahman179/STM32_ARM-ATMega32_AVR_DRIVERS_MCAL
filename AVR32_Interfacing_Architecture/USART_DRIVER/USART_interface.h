/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		        */
/*	 Date 			      	:    23rd of July 2020 			        		*/
/*	 Version 			      :    1.0V 							               	*/
/*	 Description 		    :  Public Accessing Mechanism Prototype */
/*                            and Sense Mode Definition         */
/****************************************************************/

/* Description   : Guard to protect this File from include more than one time .  */

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#define ASYNCRONOUS_MODE        0
#define SYNCRONOUS_MODE         1
#define ASY_NORMAL_SPEED_MODE   2 
#define ASY_DOUBLE_SPEED_MODE   3
/*#define BAUD_RATE_9600          4 
#define BAUD_RATE_4800          5 
#define BAUD_RATE_115200        6
#define DISABLE_PARITY          7
#define EVEN_PARITY             8 
#define ODD_PARITY              9
#define STOP_1_BIT              10 
#define STOP_2_BITS             11
#define CLOCK_POLARITY_RISING   12
#define CLOCK_POLARITY_FALLING  13
#define CHARACTER_SIZE_5_BITS   14
#define CHARACTER_SIZE_6_BITS   15
#define CHARACTER_SIZE_7_BITS   16
#define CHARACTER_SIZE_8_BITS   17
#define CHARACTER_SIZE_9_BITS   18

void USART_Init(void);

/* A Function used to send data. I/P : u8 Data
                                 return : void  
    i.e: must be used after USART Initialization */
void USART_Transmit(u8 Data);

/* A Function used to receive data. I/P : void
                                    return : u8 Data  
    i.e: must be used after USART Initialization */
u8 USART_Receive(void);


#endif
