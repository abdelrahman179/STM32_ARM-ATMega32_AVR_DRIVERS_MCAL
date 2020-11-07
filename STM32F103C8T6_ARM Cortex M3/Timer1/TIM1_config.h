/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 03 September 2020                                                  */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Timer1 User Manual                     */
/*******************************************************************************/

#ifndef _TIM1_CONFIG_H_
#define _TIM1_CONFIG_H_

/*  PWM Freq = Fclk / PSC / ARR 
    PWM Duty = CCRx / ARR      */

/* Prescaler Selection  
   Note: PSC is skipping oscillators from the Mic ClK to control the frequency
   - Range:  1 - 65536   
*/
#define TIM1_PRE_SC_VAL        1000

/*  Timer1 Direction Configuration 
  - Range: - UP_COUNTER
           - DOWN_COUNTER    */
#define TIM1_DIR        UP_COUNTER

/*  Center Aligned Mode Selection 
  - Range: - EDGE_ALIGNED                    Count up/down depending on the direction Bit
           - CNT_DOWN_OP_COM_INT_FLAG        Center aligned mode 1 
           - CNT_UP_OP_COM_INT_FLAG          Center aligned mode 2 
           - CNT_UP_DOWN_OP_COM_INT_FLAG     Center aligned mode 3   */
#define TIM1_CMS        EDGE_ALIGNED


/* Set Number of Counts either counting up or down 
   - Range:  1 - 65536   
*/
#define TIM1_SET_COUNT        1000


/* We can have 4 different PWM Pins "4 channels" 
 - Range :  - CH_1
            - CH_2
            - CH_3
            - CH_4  */
#define TIM1_PWM_OP_CHANNEL             CH_1

/* - PWM Capture Compare : To help us set the duty cycle 
   Ex: ARR_val = 1000 & CCR_val = 500. Then, Duty Cycle = 50%

   - Range : CCR_val <= ARR_val  */
#define TIM1_CAP_COM_VAL                0


/* - Mode 1 : Activa Low    TIMx_CNT > TIMx_CCR1 
   - Mode 2 : Activa High   TIMx_CNT < TIMx_CCR1  
   - Range : - FROZEN      "Generate a Timing Base" 
             - ACTIVE_HIGH 
             - ACTIVE_LOW          */
#define TIM1_PWM_MODE      ACTIVE_HIGH



#endif
