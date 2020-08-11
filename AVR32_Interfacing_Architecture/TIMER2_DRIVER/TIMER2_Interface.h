/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    10th of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER2 Interface File                        */
/****************************************************************/

#ifndef TIMER2_INT_H
#define TIMER2_INT_H

// TIMER2 Waveform Generation Modes
#define TIMER2_NORMAL                    1 
#define TIMER2_CTC                       2 
#define TIMER2_FAST_PWM                  3
#define TIMER2_PHASE_PWM                 4  


// TIMER2 Prescaler Division Factor 
#define TIMER2_DIV_FAC_1                5  
#define TIMER2_DIV_FAC_8                6 
#define TIMER2_DIV_FAC_32               7  
#define TIMER2_DIV_FAC_64               8  
#define TIMER2_DIV_FAC_128              9 
#define TIMER2_DIV_FAC_256              10  
#define TIMER2_DIV_FAC_1024             11


// Compare Match Output Mode Non-PWM
#define TIMER2_NON_PWM_NO_ACTION                 15
#define TIMER2_NON_PWM_SET                       25
#define TIMER2_NON_PWM_TOGGLE                    35
#define TIMER2_NON_PWM_CLEAR                     45

// Compare Match Output Mode Fast-PWM
#define TIMER2_FAST_PWM_NO_ACTION                 55
// Set OC2 on compare match, clear OC2 at TOP
#define TIMER2_FAST_PWM_SET                       56
// Clear OC2 on compare match, set OC2 at TOP
#define TIMER2_FAST_PWM_CLEAR                     57

// Compare Match Output Mode Phase Correct-PWM
#define TIMER2_PHCor_PWM_NO_ACTION                 58
/* Set OC2 on compare match when up-counting. Clear OC2 on compare 
match when downcounting. */
#define TIMER2_PHCor_PWM_SET                       59
/* Clear OC2 on compare match when up-counting. Set OC2 on compare 
match when downcounting. */
#define TIMER2_PHCor_PWM_CLEAR                     60

// Asynchronous Operation of Timer2
#define TIMER2_EXTERNAL_CK               65
#define TIMER2_INTERNAL_CK               70



// Timer2 Initialization configureation 
void TIMER2_Init(void);

// To write a value into TCNT0 Register
void TIMER2_SetTimerReg(u8 copy_uint8val2);  

// OC Register compare value 
void TIMER2_SetCompareVal(u8 copy_unit8val2);

// Enable Overflow interrupt
void TIMER2_EnableOVInt(void);

// Disable Overflow interrupt
void TIMER2_DisableOVInt(void);

// Enable CTC Clear timer Compare Match interrupt
void TIMER2_EnableCTCInt(void);

// Disable CTC Clear timer Compare Match interrupt
void TIMER2_DisableCTCInt(void);

// To call OV ISR function from Application Layer
void TIMER2_voidSetOVCallBack(void (*Copy_ptr2) (void));

// To call CTC ISR function from Application Layer
void TIMER2_voidSetCTCCallBack(void (*Copy_ptr2) (void));

#endif 
