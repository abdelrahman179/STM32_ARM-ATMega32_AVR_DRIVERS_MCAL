/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki		        */
/*   Date         :    10th of July 2020 		        */
/*   Version      :    1.0V 					*/
/*   Description  :    TIMER2 User Manual                       */
/****************************************************************/

#ifndef     TIMER2_CONFIG_H
#define     TIMER2_CONFIG_H

// TIMER2 Waveform Generation Modes | COUNTER0 
/*  
RANGE : - TIMER2_NORMAL
        - TIMER2_CTC
        - TIMER2_FAST_PWM
        - TIMER2_PHASE_PWM
*/ 
#define TIMER2_MODE             TIMER2_NORMAL

// Prescaler Division Factor
/*  
RANGE : - TIMER2_DIV_FAC_1
        - TIMER2_DIV_FAC_8
        - TIMER2_DIV_FAC_32
        - TIMER2_DIV_FAC_64
        - TIMER2_DIV_FAC_128
        - TIMER2_DIV_FAC_256
        - TIMER2_DIV_FAC_1024
*/ 
#define TIMER2_PRESCALER        TIMER2_DIV_FAC_8

// TIMER2 Compare Events "Compare Match Output Mode" 
/* In case of TIMER2 in NON_PWM MODE
RANGE : - TIMER2_NON_PWM_NO_ACTION       > Normal port operation, OC2 disconnected.
        - TIMER2_NON_PWM_SET             > Set OC2 on compare match
        - TIMER2_NON_PWM_TOGGLE          > Toggle OC2 on compare match
        - TIMER2_NON_PWM_CLEAR           > Clear OC2 on compare match

  In case of TIMER2 in Fast-PWM MODE
RANGE : - TIMER2_FAST_PWM_NO_ACTION      > Normal port operation, OC2 disconnected.
        - TIMER2_FAST_PWM_SET            > Set OC2 on compare match, clear OC2 at TOP
        - TIMER2_FAST_PWM_CLEAR          > Clear OC2 on compare match, set OC2 at TOP
 
  In case of TIMER2 in Phase Correct PWM MODE
RANGE : - TIMER2_PHCor_PWM_NO_ACTION     > Normal port operation, OC2 disconnected.
        - TIMER2_PHCor_PWM_SET           > Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting.
        - TIMER2_PHCor_PWM_CLEAR         > Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting.
*/ 
#define TIMER2_COM_EVENT        TIMER2_NON_PWM_NO_ACTION

/* TIMER2 Asynchronous Operation Mode */
/* Range : - TIMER2_INTERNAL_CK        > TIMER2 internal clock 
           - TIMER2_EXTERNAL_CK        > External Clock Oscillator such as RTC */
#define TIMER2_ASYNCH_MODE        TIMER2_INTERNAL_CK
     


#endif
