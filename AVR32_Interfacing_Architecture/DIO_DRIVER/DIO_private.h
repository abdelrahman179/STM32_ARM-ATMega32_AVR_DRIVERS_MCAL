/*************************************************************/
/*  AUTHOR     : AbdElrahman Ibrahim Zaki                    */
/*  DATE       : 10th of June 2020										 */
/*  VERSION	   : V0.1										             */
/*  DESCRIPTION: DIO Registers Addresses                                  */
/*                                                           */
/*************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// insert registers names and addresses

		// PORTA Registers
#define DDRA_REG  *((volatile u8 *) 0X3A)

#define PORTA_REG *((volatile u8 *) 0X3B)

#define PINA_REG  *((volatile u8 *) 0X39)

		// PORTB Registers
#define DDRB_REG  *((volatile u8 *) 0X37)

#define PORTB_REG *((volatile u8 *) 0X38)

#define PINB_REG  *((volatile u8 *) 0X36)

		// PORTC Registers
#define DDRC_REG  *((volatile u8 *) 0X34)

#define PORTC_REG *((volatile u8 *) 0X35)

#define PINC_REG  *((volatile u8 *) 0X33)

		// PORTD Registers
#define DDRD_REG  *((volatile u8 *) 0X31)

#define PORTD_REG *((volatile u8 *) 0X32)

#define PIND_REG  *((volatile u8 *) 0X30)



#endif
