/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    23rd of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:  Public Accessing Mechanism Prototype */
/*                            and Sense Mode Definition         */
/****************************************************************/

/* Description   : Guard to protect this File from include more than one time .  */

#ifndef  ADC_INTERFACE_H
#define  ADC_INTERFACE_H

#define  AVCC 		   5
#define  AREF 		   4
#define  INTERNAL	   2.56

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1


#define DIV_FAC_2				20
#define DIV_FAC_4				21
#define DIV_FAC_8				22
#define DIV_FAC_16				23
#define DIV_FAC_32				24
#define DIV_FAC_64				25
#define DIV_FAC_128			    26


// Analog Channel and Gain Selection MUX0:4

#define  	ADC0		                	0
#define 	ADC1			                1
#define     ADC2                        	2
#define     ADC3	                        3
#define   	ADC4	                        4
#define     ADC5	                        5
#define   	ADC6	                        6
#define     ADC7	                        7
#define     ADC1_pos_ADC0_neg_Gain_x10      8
#define     ADC1_pos_ADC0_neg_Gain_x200     9
#define     ADC3_pos_ADC2_neg_Gain_x10      10
#define     ADC3_pos_ADC2_neg_Gain_x200     11
#define     ADC0_pos_ADC1_neg_Gain_x1       12
#define     ADC2_pos_ADC1_neg_Gain_x1       13
#define     ADC3_pos_ADC1_neg_Gain_x1       14
#define     ADC4_pos_ADC1_neg_Gain_x1       15
#define     ADC5_pos_ADC1_neg_Gain_x1       16
#define     ADC6_pos_ADC1_neg_Gain_x1       17
#define     ADC7_pos_ADC1_neg_Gain_x1       18
#define     ADC0_pos_ADC2_neg_Gain_x1       19
#define     ADC1_pos_ADC2_neg_Gain_x1       20
#define     ADC3_pos_ADC2_neg_Gain_x1       21
#define     ADC4_pos_ADC2_neg_Gain_x1       22
#define     ADC5_pos_ADC2_neg_Gain_x1       23

// Trigger Mode

#define FREE_RUNNING_MODE 				30
#define ANALOG_COMPARATOR				31
#define EXT_INTERRUPT                 	32
#define TIMER_COUNTER0_COM_MATCH     	33
#define TIMER_COUNTER0_OVERFLOW  		34
#define TIMER_COUNTER0_COM_MATCH_B   	35
#define TIMER_COUNTER1_OVERFLOW  		36
#define TIMER_COUNTER1_CAP_EVENT    	37

#define POLLING            40
#define EN_INTERRUPT       41 

void ADC_Init(void);
void ADC_Enable(void);
void ADC_Start_Conv(void);
u16  ADC_Read(u8 channel);


#endif
