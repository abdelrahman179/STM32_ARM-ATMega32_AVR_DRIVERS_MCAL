/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 8 August 2020                                                   */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 RCC Prototypes of Public Functions  */
/****************************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_

           /* ---------------------- Configuratuin Parameters ---------------------- */

#define ENABLE   1
#define DISABLE  0

/* ------ Clock system options ------ */
#define RCC_HSI 	    	  1         /* Internal RC 8MHz */
#define RCC_HSE_CRYSTAL   2         /* CLK  4 -> 16 MHz */
#define RCC_HSE_RC        3         /* CLK up to 25 MHz */
#define RCC_PLL           4         /* CLK up to 72 MHz */

/* ------ PLL options ------ */
/* Division option exist just in case we couldn't reach 72 MHz.
    ex: Cry 16MHz, req PLL at 72MHz, prescaler ?? 
        We shall try HSE/2 = 16/2 = 8, multiply by 9 = 72MHz */
#define RCC_PLL_HSI_BY2   5         /**/
#define RCC_PLL_HSE       6
#define RCC_PLL_HSE_BY2   7

/* ------ ClK factor of PLL */
#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110

/* Clock Security System :
    > Enabled : - Set HSI by H.W. when there are failure in HSI 
                - Set HSI by H.W. when leaving stop or standby
    > Disable : - The above feature will be disable            */
#define DISABLE_CLOCK_SECURITY_SYSTEM              0
#define ENABLE_CLOCK_SECURITY_SYSTEM               1

/* ----- AHB Peripheral ClK "3,5,7,9 reserved"----- */
#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10

/* ----- APB2 Peripheral ClK "1,16,17,18 reserved"----- */
#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21

/* ----- APB1 Peripheral ClK "9,10,12,13,16,24,26 reserved"----- */
#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29

/* ------ MCO PIN Options ------ */
/* Is used to generate an output CLK on it for error measurement 
    - For Diagnostics   - For CLK Cascading */
#define NO_CLOCK      0     
#define HSI_CLOCK     1
#define HSE_CLOCK     2
#define PLL_CLOCK     3
#define SYSTEM_CLOCK  4

/* ---- System Buses ---- */
#define AHB_BUS       0
#define APB1_BUS      1
#define APB2_BUS      2

/* 
  * RCC_voidInitSysClock - > Intialize the clock for the system
*/
void MRCC_voidInitSysClock(void);

/* 
  * RCC_voidEnableClock - > Enable a periheral clock
  * i/p : Bus id (AHB - APB1 - APB2) / Peripheral id 0:31
*/
void MRCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId);

/* 
  * RCC_voidDisableClock - > Disable a periheral clock
  * i/p : Bus id (AHP - APB1 - APB2) / Peripheral id 0:31
*/
void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);



#endif
