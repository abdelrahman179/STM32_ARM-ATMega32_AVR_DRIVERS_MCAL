/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki		              */
/*	 Date 				:    1st of July 2020 				              	*/
/*	 Version 			:    1.0V 							                     	*/
/*	 Description  :    TIMER0 Registers Addresses               */
/****************************************************************/

#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/* Timer/Counter Control Register */
#define  TCCR0     *((volatile u8 *) 0X53)

/* Output Compare Register */
#define  OCR0     *((volatile u8 *) 0X5C)

/* Timer/Counter Register */
#define  TCNT0     *((volatile u8 *) 0X52)

/* Timer/Counter Interrupt Mask Register */
#define  TIMSK     *((volatile u8 *) 0X59)

/* Timer/Counter Interrupt Flag Register */
#define  TIFR     *((volatile u8 *) 0X58)

#endif

