/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    25th of June 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    General Interrupt Registers Addresses      */
/****************************************************************/

#ifndef  GIE_PRIVATE_H
#define  GIE_PRIVATE_H

/* Status Register Setting BIT7 activates the Global Interrupt */
#define   SREG      *((volatile u8 *) 0X5F)

#endif
