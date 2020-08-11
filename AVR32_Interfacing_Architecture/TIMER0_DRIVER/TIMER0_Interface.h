/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    1st of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER0 Interface File                        */
/****************************************************************/

#ifndef TIMER0_INT_H
#define TIMER0_INT_H

// TIMER0 Waveform Generation Modes
#define TIMER0_NORMAL                    1 
#define TIMER0_CTC                       2 
#define TIMER0_FAST_PWM                  3
#define TIMER0_PHASE_PWM                 4  


// TIMER0 Prescaler Division Factor 
#define TIMER0_DIV_FAC_1                5  
#define TIMER0_DIV_FAC_8                6  
#define TIMER0_DIV_FAC_64               7  
#define TIMER0_DIV_FAC_256              8  
#define TIMER0_DIV_FAC_1024             9
// TIMER0 as a COUNTER0
#define TIMER0_FALLING_COUNTER0         10
#define TIMER0_RISING_COUNTER0          11

// Compare Match Output Mode Non-PWM
#define TIMER0_NON_PWM_NO_ACTION                 15
#define TIMER0_NON_PWM_SET                       25
#define TIMER0_NON_PWM_TOGGLE                    35
#define TIMER0_NON_PWM_CLEAR                     45

// Compare Match Output Mode Fast-PWM
#define TIMER0_FAST_PWM_NO_ACTION                 55
// Set OC0 on compare match, clear OC0 at TOP
#define TIMER0_FAST_PWM_SET                       56
// Clear OC0 on compare match, set OC0 at TOP
#define TIMER0_FAST_PWM_CLEAR                     57

// Compare Match Output Mode Phase Correct-PWM
#define TIMER0_PHCor_PWM_NO_ACTION                 58
/* Set OC0 on compare match when up-counting. Clear OC0 on compare 
match when downcounting. */
#define TIMER0_PHCor_PWM_SET                       59
/* Clear OC0 on compare match when up-counting. Set OC0 on compare 
match when downcounting. */
#define TIMER0_PHCor_PWM_CLEAR                     60



// Timer0 Initialization configureation 
void TIMER0_Init(void);

// To write a value into TCNT0 Register
void TIMER0_SetTimerReg(u8 copy_uint8val);  

// OC Register compare value 
void TIMER0_SetCompareVal(u8 copy_unit8val);

// Enable Overflow interrupt
void TIMER0_EnableOVInt(void);

// Disable Overflow interrupt
void TIMER0_DisableOVInt(void);

// Enable CTC Clear timer Compare Match interrupt
void TIMER0_EnableCTVInt(void);

// Disable CTC Clear timer Compare Match interrupt
void TIMER0_DisableCTCInt(void);

// To call OV ISR function from Application Layer
void TIMER0_voidSetOVCallBack(void (*Copy_ptr) (void));

// To call CTC ISR function from Application Layer
void TIMER0_voidSetCTCCallBack(void (*Copy_ptr) (void));

#endif 
