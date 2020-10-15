/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki		              */
/*	 Date 				:    10th of July 2020 				              	*/
/*	 Version 			:    1.0V 							 	                    */
/*	 Description 	:    TIMER2 Registers Addresses               */
/****************************************************************/

#ifndef TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H

/* Timer2 Control Register */
#define  TCCR2     *((volatile u8 *) 0X45)

/* Output Compare Register */
#define  OCR2     *((volatile u8 *) 0X43)

/* Timer2 Register */
#define  TCNT2     *((volatile u8 *) 0X44)

/* Timer2 Interrupt Mask Register */
#define  TIMSK     *((volatile u8 *) 0X59)

/* Timer2 Interrupt Flag Register */
#define  TIFR     *((volatile u8 *) 0X58)

/* Timer2 Asynchronous Status Register
to be connected either with RTC "Real Time Clock" or 
to work as a timer  */
#define  ASSR     *((volatile u8 *) 0X42)

#endif

