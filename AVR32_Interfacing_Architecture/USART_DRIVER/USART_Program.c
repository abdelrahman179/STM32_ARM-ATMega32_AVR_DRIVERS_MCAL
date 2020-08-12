/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    23rd of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    USART Program                      */
/****************************************************************/

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "USART_Config.h"
#include  "USART_Reg.h"

/* Description : USART Initialization Function 
                    I/P : void
                    O/P : void */

void USART_Init(void)
{
    u16 LOC_baudEquation = 0 ;
    u8  UCSRC_LOC_TEMP = 0;

        /* ---------------- Operation Mode Selection ------------------ */ 
    #if (MODE_OF_OPERATION == ASYNCRONOUS_MODE)
        CLR_BIT(UCSRC_LOC_TEMP , 6);

    #elif (MODE_OF_OPERATION == SYNCRONOUS_MODE)
        SET_BIT(UCSRC_LOC_TEMP , 6);
    
    #else 

        #error "Wrong Operation Mode Selection"

    #endif    


        /* ---------------- Speed Mode Selection ------------------ */ 
    #if (MODE_OF_OPERATION == ASYNCRONOUS_MODE)

         if (ASYNC_SPEED_MODE == ASY_DOUBLE_SPEED_MODE)
             SET_BIT(UCSRA , 1);
         else if (ASYNC_SPEED_MODE == ASY_NORMAL_SPEED_MODE)   
             CLR_BIT(UCSRA , 1);

    #elif (MODE_OF_OPERATION == SYNCRONOUS_MODE)
         CLR_BIT(UCSRA , 1);
    
    #else 

        #error "Wrong Speed Mode Selection"

    #endif  


        /* ---------------- Parity Mode ------------------ */ 
    #if (PARITY_MODE == DISABLE_PARITY)
         CLR_BIT(UCSRC_LOC_TEMP , 4); 
         CLR_BIT(UCSRC_LOC_TEMP , 5);

    #elif (PARITY_MODE == EVEN_PARITY)
         CLR_BIT(UCSRC_LOC_TEMP , 4); 
         SET_BIT(UCSRC_LOC_TEMP , 5);
    
    #elif (PARITY_MODE == ODD_PARITY)
         SET_BIT(UCSRC_LOC_TEMP , 4); 
         SET_BIT(UCSRC_LOC_TEMP , 5);

    #else 

        #error "Wrong Parity Mode Selection"

    #endif  

       /* ---------------- Baud Rate Equation ------------------ */
	#if MODE_OF_OPERATION == ASYNCRONOUS_MODE
			if (GET_BIT(UCSRA, 1) == 0) 
			// Asynchronous Normal Mode 
			LOC_baudEquation = ((F_CPU / (16 * BAUD_RATE_bps)) - 1 );
	
			else if (GET_BIT(UCSRA, 1) == 1)
			// Asynchronous Double Speed Mode 
			LOC_baudEquation = ((F_CPU / (8 * BAUD_RATE_bps)) - 1 );

	#elif MODE_OF_OPERATION == SYNCRONOUS_MODE
			/* Synchronous Master Mode				*/
			LOC_baudEquation = ((F_CPU / (2 * BAUD_RATE_bps)) - 1 );
	
	#endif

    /* Set Baud Rate */
	UBRRH = (u8)(LOC_baudEquation>>8);
	UBRRL = (u8)LOC_baudEquation;

    /* Enable Receiver and Transmitter */
	SET_BIT(UCSRB , 3);
	SET_BIT(UCSRB , 4);


    /* ---------------- Character Size ------------------ */ 
    #if (CHARACTER_SIZE == CHARACTER_SIZE_5_BITS)
         CLR_BIT(UCSRB , 2); 
         CLR_BIT(UCSRC_LOC_TEMP , 1);
         CLR_BIT(UCSRC_LOC_TEMP , 2);

    #elif (CHARACTER_SIZE == CHARACTER_SIZE_6_BITS)
         CLR_BIT(UCSRB , 2); 
         SET_BIT(UCSRC_LOC_TEMP , 1);
         CLR_BIT(UCSRC_LOC_TEMP , 2);
    
    #elif (CHARACTER_SIZE == CHARACTER_SIZE_7_BITS)
         CLR_BIT(UCSRB , 2); 
         CLR_BIT(UCSRC_LOC_TEMP , 1);
         SET_BIT(UCSRC_LOC_TEMP , 2);

    #elif (CHARACTER_SIZE == CHARACTER_SIZE_8_BITS)
         CLR_BIT(UCSRB , 2); 
         SET_BIT(UCSRC_LOC_TEMP , 1);
         SET_BIT(UCSRC_LOC_TEMP , 2);

    #elif (CHARACTER_SIZE == CHARACTER_SIZE_9_BITS)
         SET_BIT(UCSRB , 2); 
         SET_BIT(UCSRC_LOC_TEMP , 1);
         SET_BIT(UCSRC_LOC_TEMP , 2);
    
    #else 

        #error "Wrong Character Size Selection"

    #endif  

    /* ---------------- Stop Number of Bits ------------------ */ 
    #if (STOP_0_OR_1_BITS == STOP_1_BIT)
         CLR_BIT(UCSRC_LOC_TEMP , 3); 

    #elif (STOP_0_OR_1_BITS == STOP_2_BITS)
         SET_BIT(UCSRC_LOC_TEMP , 3); 

    #else 

        #error "Wrong No of Stop Bits Selection"

    #endif  


    /* ---------------- Clock Polarity Selection ------------------ */ 
    #if (CLOCK_POLARITY_SELECTION_MODE == CLOCK_POLARITY_RISIN)
         CLR_BIT(UCSRC_LOC_TEMP , 0); 

    #elif (CLOCK_POLARITY_SELECTION_MODE == CLOCK_POLARITY_FALLING)
         SET_BIT(UCSRC_LOC_TEMP , 0); 

    #else 

        #error "Wrong Clock Polarity Selection"

    #endif 

    /* URSEL: Register Select					
        	"This bit selects between accessing the UCSRC or UBRRH Register.					
            It is read as one when reading UCSRC.			
			The URSEL must be one when writing the UCSRC. */
    SET_BIT(UCSRC_LOC_TEMP , 7); 

   /* UCSRC  : USART control and status Register 
               Force Acesses to UCSRC Register because sharing
               the	same I/O location with UBBRH.*/
    UCSRC = UCSRC_LOC_TEMP;
}


/* ---------------- Transmitting Data Function ------------------ */ 
void USART_Transmit(u8 Data)
{
    /* Wait for empty transmit buffer */
	while(GET_BIT(UCSRA,5) == 0);
	
	/*	while ( !( UCSRA & (1<<UDRE)) );	*/
	
	/* Insert data into buffer, sends the data */
	UDR = data;
}


/* ---------------- Receiving Data Function ------------------ */ 
u8 USART_Receive(void)
{
    /* Wait for data to be received */
	while(GET_BIT(UCSRA , 7) == 0);
	/* clear the flag by writing logical one on it */
	CLR_BIT(UCSRA , 7);
	
	/* while ( !(UCSRA & (1<<RXC)) );				*/
	
	/* Get and return received data from buffer 	*/
	return UDR;
}
