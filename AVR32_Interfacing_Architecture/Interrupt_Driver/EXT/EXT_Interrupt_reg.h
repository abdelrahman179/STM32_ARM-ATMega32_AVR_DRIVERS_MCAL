/****************************************************************/
/*   Author          :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    25th of June 2020 				          	*/
/*	 Version 			:    1.0V 							                	*/
/*	 Description 		:  External Interrupt Registers Addresses */
/****************************************************************/
#ifndef  EXT_REG_H
#define  EXT_REG_H

/* General Interrupt Control Register
   setting BITs 5 > INT2 , 6 > INT0 , 7 > INT1 activates the Peripheral Interrupt  */

#define   GICR      *((volatile u8 *) 0X5B)

/* General Interrupt Flag Register
   INTF1 > BIT7 , INTF0 > BIT6 , INTF2 > BIT5 */
/* When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1
becomes set (one). If the I-bit in SREG and the INT1 bit in GICR are set (one), the MCU
will jump to the corresponding Interrupt Vector. The flag is cleared when the interrupt
routine is executed. Alternatively, the flag can be cleared by writing a logical one to it.
This flag is always cleared when INT1 is configured as a level interrupt. */

#define   GIFR      *((volatile u8 *) 0X5A)


/* The MCU Control Register contains control bits for interrupt sense
   control and general MCU functions of EXT0 & EXT1 */

/* BITs 0 & 1 dedicated to INT0  < while > BITs 2 & 3 dedicated to INT1  */
#define   MCUCR      *((volatile u8 *) 0X55)

/* MCU Control and Status Register of EXT2 */
/* setting BIT6 activates INT2 "INT2 is only an edge triggered interrupt" */
#define   MCUCSR      *((volatile u8 *) 0X54)

#endif
