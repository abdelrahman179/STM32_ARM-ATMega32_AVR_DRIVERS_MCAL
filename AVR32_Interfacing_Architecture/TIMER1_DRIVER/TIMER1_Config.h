/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    5th of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER1 User Manual                        */
/****************************************************************/

#ifndef     TIMER1_CONFIG_H
#define     TIMER1_CONFIG_H

// TIMER1 Waveform Generation Modes
/*  
RANGE : - TIMER1_NORMAL
        - TIMER1_PWM_PHASE_CORRECT_8_BIT
        - TIMER1_PWM_PHASE_CORRECT_9_BIT
        - TIMER1_PWM_PHASE_CORRECT_10_BIT
        - TIMER1_CTC_OCR1A_TOP
        - TIMER1_FAST_PWM_8_BIT
        - TIMER1_FAST_PWM_9_BIT
        - TIMER1_FAST_PWM_10_BIT
        - TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_TOP
        - TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_TOP
        - TIMER1_PWM_PHASE_CORRECT_ICR1_TOP
        - TIMER1_PWM_PHASE_CORRECT_OCR1A_TOP
        - TIMER1_CTC_ICR1_TOP
        - TIMER1_FAST_PWM_ICR1_TOP
        - TIMER1_FAST_PWM_OCR1A_TOP
*/  
#define TIMER1_MODE             TIMER1_NORMAL

// Prescaler Division Factor
/*  
RANGE : - TIMER1_DIV_FAC_1
        - TIMER1_DIV_FAC_8 
        - TIMER1_DIV_FAC_64 
        - TIMER1_DIV_FAC_256
        - TIMER1_DIV_FAC_1024
        - TIMER1_FALLING_COUNTER1
        - TIMER1_RISING_COUNTER1
*/ 
#define TIMER1_PRESCALER        TIMER0_DIV_FAC_8


/* 
RANGE : // TIMER1 Channel A Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> 
        // In case of TIMER1 Channel A in NON PWM MODE
        - TIMER1_CHA_NON_PWM_NO_ACTION         >Normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHA_NON_PWM_SET               >Set OC1A/OC1B on compare match (Set output to high level)
        - TIMER1_CHA_NON_PWM_TOGGLE            >Toggle OC1A/OC1B on compare match
        - TIMER1_CHA_NON_PWM_CLEAR             >Clear OC1A/OC1B on compare match (Set output to low level)

        // In case of TIMER1 Channel A in FAST PWM MODE
        - TIMER1_CHA_FAST_PWM_NO_ACTION       >Normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHA_FAST_PWM_SET             >Set OC1A/OC1B on compare match, clear OC1A/OC1B at TOP
        - TIMER1_CHA_FAST_PWM_TOGGLE          >WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
                                               For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHA_FAST_PWM_CLEAR           >Clear OC1A/OC1B on compare match, set OC1A/OC1B at TOP

        // In case of TIMER1 Channel A in PHASE-CORRECT PWM MODE
        - TIMER1_CHA_PHCor_PWM_NO_ACTION      >Normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHA_PHCor_PWM_SET            >Set OC1A/OC1B on compare match when up-counting. Clear OC1A/OC1B on compare 
                                               match when downcounting.
        - TIMER1_CHA_PHCor_PWM_TOGGLE         >WGM13:0 = 9 or 14: Toggle OC1A on 
                                               Compare Match, OC1B disconnected (normal port operation).
                                               For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHA_PHCor_PWM_CLEAR          >Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare 
                                                match when downcounting.
 
*/ 
#define TIMER1_CHA_COM_EVENT        TIMER1_CHA_NON_PWM_NO_ACTION

/*   
RANGE : // TIMER1 Channel B Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode>
        // In case of TIMER1 Channel B in NON PWM MODE
        - TIMER1_CHB_NON_PWM_NO_ACTION       >Normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHB_NON_PWM_SET             >Set OC1B on compare match (Set output to high level)
        - TIMER1_CHB_NON_PWM_TOGGLE          >Toggle OC1B on compare match"
        - TIMER1_CHB_NON_PWM_CLEAR           >Clear OC1A/OC1B on compare match (Set output to low level)

        // In case of TIMER1 Channel A in FAST PWM MODE
        - TIMER1_CHB_FAST_PWM_NO_ACTION       >Normal port operation, OC1B disconnected.
        - TIMER1_CHB_FAST_PWM_SET             >Set OC1A/OC1B on compare match, clear OC1B at TOP
        - TIMER1_CHB_FAST_PWM_TOGGLE          >WGM13:0 = 15: Toggle OC1A on Compare 
                                               Match, OC1B disconnected (normal port operation).
                                               For all other WGM13:0 settings, normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHB_FAST_PWM_CLEAR           >Clear OC1A/OC1B on compare match, set OC1B at TOP

        // In case of TIMER1 Channel A in PHASE-CORRECT PWM MODE
        - TIMER1_CHB_PHCor_PWM_NO_ACTION       >Normal port operation, OC1A/OC1B disconnected.
        - TIMER1_CHB_PHCor_PWM_SET             >Set OC1A/OC1B on compare match when up-counting. Clear OC1A/OC1B on compare 
                                                match when downcounting.
        - TIMER1_CHB_PHCor_PWM_TOGGLE          >WGM13:0 = 9 or 14: Toggle OC1A on 
                                                Compare Match, OC1B disconnected (normal port operation).
                                                For all other WGM13:0 settings, normal port 
                                                operation, OC1A/OC1B disconnected.
        - TIMER1_CHB_PHCor_PWM_CLEAR           >Clear OC1A/OC1B on compare match when up-counting. Set OC1A/OC1B on compare 
                                                match when downcounting.
*/

#define TIMER1_CHB_COM_EVENT        TIMER1_CHB_NON_PWM_NO_ACTION


#endif
