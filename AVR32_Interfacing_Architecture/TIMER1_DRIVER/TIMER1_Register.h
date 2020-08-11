/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    5th of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER1 Register Addresses                         */
/****************************************************************/

#ifndef TIMER1_REG_H
#define TIMER1_REG_H
 
/* ---------------------- Timer1/Counter1 Control Register ---------------------------- */

/* Timer1/Counter1 Control Register A */
#define  TCCR1A     *((volatile u8 *) 0X4F)

/* Timer1/Counter1 Control Register B */
#define  TCCR1B     *((volatile u8 *) 0X4E)

/* --------------------------- Output Compare Register 1 ------------------------------- */
/* Output Compare Register A HIGH */
#define  OCR1AH     *((volatile u8 *) 0X4B)

/* Output Compare Register A LOW */
#define  OCR1AL     *((volatile u8 *) 0X4A)

/* Output Compare Register B HIGH */
#define  OCR1BH     *((volatile u8 *) 0X49)

/* Output Compare Register B LOW */
#define  OCR1BL     *((volatile u8 *) 0X48)

// To write on both OCR1A registers together
#define  OCR1A     *((volatile u16 *) 0X4A)

// To write on both OCR1B registers together
#define  OCR1B     *((volatile u16 *) 0X48)

/* ------------------------- Timer1/Counter1 Data Register -------------------------------- */

/* Timer/Counter HIGH Register */
#define  TCNT1H     *((volatile u8 *) 0X4D)

/* Timer1/Counter1 LOW Register */
#define  TCNT1L     *((volatile u8 *) 0X4C)

// To read both registers "TCNT1H + TCNT1L" together 
#define  TCNT1     *((volatile u16 *) 0X4C)



/* ---------------------- Timer1/Counter1 Interrupt Mask Register ----------------------------- */

/* Timer1/Counter1 Interrupt Mask Register */
#define  TIMSK     *((volatile u8 *) 0X59)

/* Timer1/Counter1 Interrupt Flag Register */
#define  TIFR     *((volatile u8 *) 0X58)

#endif

