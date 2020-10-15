/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki         		    */
/*	 Date 				:    23rd of June 2020 			              		*/
/*	 Version 			:    1.0V 							 	                    */
/*	 Description 	:    Registers addresses                      */
/****************************************************************/

#ifndef  ADC_PRIVATE_H
#define  ADC_PRIVATE_H


// Multiplexing Register
#define   ADMUX   *((volatile u8 *) 0X27 ) 

// Control and Status Register
#define   ADCSRA  *((volatile u8 *) 0X26 ) 

// Analog Digital High Register
#define    ADCH   *((volatile u8 *) 0X25 ) 

// Analog Digital LOW Register
#define    ADCL   *((volatile u8 *) 0X24 )

// Special Function I/O Register
#define    SFIOR  *((volatile u8 *) 0X50 )

// Read ADCL + ADCH both together u8 + u8
#define    ADC_Register   *((volatile u16 *) 0X24 )

#endif
