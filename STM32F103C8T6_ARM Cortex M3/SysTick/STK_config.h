/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 26 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Systick User Manual                    */
/*******************************************************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H


/* Range:  - AHB_CLK_SRC 
           - AHB_CLK_SRC_Div_8    */
#define STK_CLOCK_SRC           AHB_CLK_SRC_Div_8


/*  Determine the AHB Clock   */
#define STK_AHB_CLK             8000000


#endif 
