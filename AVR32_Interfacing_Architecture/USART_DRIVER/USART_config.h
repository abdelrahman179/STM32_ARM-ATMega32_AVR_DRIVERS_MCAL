/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki	        */
/*   Date 		:    20th of July 2020 			*/
/*   Version 		:    1.0V 				*/
/*   Description 	:   USART User Manual                   */
/****************************************************************/

/* Description   : Guard to protect this File from include more than one time .  */

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* Insertion of F_CPU Speed that affects the Baud Rate */ 
#define F_CPU				8000000

/* USART Selection Mode of Operation 
Range : - ASYNCRONOUS_MODE   UCSRC Reg > Bit 6 : URSEL > 0
        - SYNCRONOUS_MODE    UCSRC Reg > Bit 6 : URSEL > 1*/ 
#define MODE_OF_OPERATION            ASYNCRONOUS_MODE

/* USART Speed Selection Mode in case of ASYNCRONOUS_MODE 
Range : - ASY_NORMAL_SPEED_MODE    UCSRA Reg > Bit 1 : U2X > 0
        - ASY_DOUBLE_SPEED_MODE    UCSRA Reg > Bit 1 : U2X > 1 

           "Double the speed reducing the divisor of the Baud Rate
           divider from 16 to 8 effectively doubling the transfer 
           rate for the Asynchronous Communication"  */ 
#define ASYNC_SPEED_MODE             ASY_DOUBLE_SPEED_MODE

/*/* USART Parity Mode Selection 
Range : - DISABLE_PARITY   UCSRC Reg > Bit 5:4 UPM1 > 0  & UPM0 > 0
        - EVEN_PARITY      UCSRC Reg > Bit 5:4 UPM1 > 1  & UPM0 > 0
        - ODD_PARITY       UCSRC Reg > Bit 5:4 UPM1 > 1  & UPM0 > 1
        
        "If enabled the transmitter will automatically generate and 
        send the parity of the transmitted data bits within each frame
        The receiver will generate a parity value for the incoming data 
        and compare it to the UPM0 setting. 
        If a mismatch is detected the PE Flag in UCSRA will be set" */ 
#define PARITY_MODE                  EVEN_PARITY


/* USART Stop Bits Selection Mode
Range : - STOP_1_BIT     UCSRC Reg > Bit 3 : USBS > 0
        - STOP_2_BITS    UCSRC Reg > Bit 3 : USBS > 1 
        
        "Selection of the number of stop bits to be inserted by the Transmitter.
        Receiver ignores this setting." */
#define STOP_0_OR_1_BITS              STOP_2_BITS

/* USART Clock Polarity Selection Mode
Range : - CLOCK_POLARITY_RISIN      UCSRC Reg > Bit 0 : UCPOL > 0
        - CLOCK_POLARITY_FALLING    UCSRC Reg > Bit 0 : UCPOL > 1
        
        "This bit is used for Synchronous mode ONLY. 
        Cleared when Asynchronous mode is used"*/ 
#define CLOCK_POLARITY_SELECTION_MODE    CLOCK_POLARITY_RISIN


/* USART Character Bits Size Selection 
Range : - CHARACTER_SIZE_5_BITS     
                UCSRB Reg > Bit2 : UCSZ2 > 0  &&  UCSRC Reg > Bit2 : UCSZ1 > 0 & Bit1 : UCSZ0 > 0
        - CHARACTER_SIZE_6_BITS     
                UCSRB Reg > Bit2 : UCSZ2 > 0  &&  UCSRC Reg > Bit2 : UCSZ1 > 0 & Bit1 : UCSZ0 > 1
        - CHARACTER_SIZE_7_BITS     
                UCSRB Reg > Bit2 : UCSZ2 > 0  &&  UCSRC Reg > Bit2 : UCSZ1 > 1 & Bit1 : UCSZ0 > 0
        - CHARACTER_SIZE_8_BITS     
                UCSRB Reg > Bit2 : UCSZ2 > 0  &&  UCSRC Reg > Bit2 : UCSZ1 > 1 & Bit1 : UCSZ0 > 1
        - CHARACTER_SIZE_9_BITS     
                UCSRB Reg > Bit2 : UCSZ2 > 1  &&  UCSRC Reg > Bit2 : UCSZ1 > 1 & Bit1 : UCSZ0 > 1
        
        "Combining UCSRB Register Bit2:UCSZ2 along with UCSRC Register Bits1,0:UCSZ1,UCSZ0
        sets the number of data bits (Character Size) in the frame that Receiver and Transmitter use "*/ 
#define CHARACTER_SIZE          CHARACTER_SIZE_8_BITS

/* USART Baud Rate "Bits per seconds"
Range : - 9600      
        - 4800      
        - 115200

        " Most common Baud Rates are mentioned above " */ 
#define BAUD_RATE_bps           9600

#endif
