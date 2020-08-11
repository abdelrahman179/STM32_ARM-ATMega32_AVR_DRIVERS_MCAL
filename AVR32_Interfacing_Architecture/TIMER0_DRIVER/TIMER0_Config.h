/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    1st of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER0 User Manual                        */
/****************************************************************/

#ifndef     TIMER0_CONFIG_H
#define     TIMER0_CONFIG_H

// TIMER0 Waveform Generation Modes | COUNTER0 
/*  
RANGE : - TIMER0_NORMAL
        - TIMER0_CTC
        - TIMER0_FAST_PWM
        - TIMER0_PHASE_PWM
*/ 
#define TIMER0_MODE             TIMER0_NORMAL

// Prescaler Division Factor
/*  
RANGE : - TIMER0_DIV_FAC_1
        - TIMER0_DIV_FAC_8
        - TIMER0_DIV_FAC_64
        - TIMER0_DIV_FAC_256
        - TIMER0_DIV_FAC_1024
        - TIMER0_FALLING_COUNTER0
        - TIMER0_RISING_COUNTER0
*/ 
#define TIMER0_PRESCALER        TIMER0_DIV_FAC_8

// TIMER0 Compare Events "Compare Match Output Mode" 
/* In case of TIMER0 in NON_PWM MODE
RANGE : - TIMER0_NON_PWM_NO_ACTION       > Normal port operation, OC0 disconnected.
        - TIMER0_NON_PWM_SET             > Set OC0 on compare match
        - TIMER0_NON_PWM_TOGGLE          > Toggle OC0 on compare match
        - TIMER0_NON_PWM_CLEAR           > Clear OC0 on compare match

  In case of TIMER0 in Fast-PWM MODE
RANGE : - TIMER0_FAST_PWM_NO_ACTION      > Normal port operation, OC0 disconnected.
        - TIMER0_FAST_PWM_SET            > Set OC0 on compare match, clear OC0 at TOP
        - TIMER0_FAST_PWM_CLEAR          > Clear OC0 on compare match, set OC0 at TOP
 
  In case of TIMER0 in Phase Correct PWM MODE
RANGE : - TIMER0_PHCor_PWM_NO_ACTION     > Normal port operation, OC0 disconnected.
        - TIMER0_PHCor_PWM_SET           > Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
        - TIMER0_PHCor_PWM_CLEAR         > Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
*/ 
#define TIMER0_COM_EVENT        TIMER0_NON_PWM_NO_ACTION
     


#endif
