/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 16 September 2020                                               */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 SPI1 program file                   */
/****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI1_interface.h"
#include "SPI1_private.h"
#include "SPI1_config.h"

/* MPSI1 CallBack */
void (*MSPI1_CallBack) (void);

/* SPI Initialization */
void MSPI1_voidInit(void)
{   
    /* Check whether the SPI is enabled */
    #if   MSPI1_STATUS == MSPI1_ENABLE
                /* Check the CLK mode "CLK Phase & Polarity" */
        #if	MSPI1_CLOCK_MODE == MSPI1_MODE0
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 0);  /* CLK Phase = 0 "Read first" */
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 1);  /* CLK Polarity = 0 "Capture on rising edge" */
        #elif	MSPI1_CLOCK_MODE == MSPI1_MODE1
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 0);  /* CLK Phase = 1 "Write first" */
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 1);  /* CLK Polarity = 0 "Capture on rising edge" */
        #elif	MSPI1_CLOCK_MODE == MSPI1_MODE2
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 0);  /* CLK Phase = 0 "Read first" */
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 1);  /* CLK Polarity = 1 "Capture on falling edge" */
        #elif	MSPI1_CLOCK_MODE == MSPI1_MODE3
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 0);  /* CLK Phase = 1 "Write first" */
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 1);  /* CLK Polarity = 1 "Capture on falling edge" */
        #endif

                /* Check whether the SPI configured as a Master or Slave */
        #if    MSPI1_MASTER_SLAVE == MSPI1_MASTER
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 2); /* Master Selection: Master configured */
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 8); /* Set SSI to 1 as a Master Mode */
        #elif  MSPI1_MASTER_SLAVE == MSPI1_SLAVE
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 2); /* Master Selection: Slave configured */
        #endif

                /* Check whether the data order configured as MSB/LSB first */
        #if   MSPI1_DATA_ORDER == MSPI1_MSB_FIRST
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 7); /* Frame Format : MSB transmitted first */
        #elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 7); /* Frame Format : LSB transmitted first */
        #endif

                /* SSM : Software Slave Management */
                /* Instead of connecting the slave select pin to GND to activate it perminantely, 
                with SSM STM feature, SS is connected to NSS master pin to be set automatically whenever
                the master is about to send data to slave and after the Tx/Rx operation it's set 
                automatically to 1 to cut of the connection temporary */
        #if   MSPI1_SS_MANAGE == HW_SLAVE_MANAGEMENT   
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 9); /* SSM disabled, configured by hardware, NSS Pin activated on A4 to activate slave */
        #elif MSPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 9); /* SSM enabled, configured by software */
        #endif

                /* Check whether the data frame format is 8bits or 16bit */
        #if   MSPI1_DATA_SIZE == MSPI1_8BIT_DATA
                CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 11); /* 8-bit data frame format is selected for transmission/reception */
        #elif MSPI1_DATA_SIZE == MSPI1_16BIT_DATA
                SET_BIT(MSPI1_Ptr -> SPI1_CR1, 11); /* 16-bit data frame format is selected for transmission/reception */
        #endif


                /* Tx/Rx Interrupt settings */
        #if   MSPI1_INT_STATUS == MSPI1_INT_DISABLE
                MSPI1_Ptr -> SPI1_CR2 = 0;  /* Disable all SPI1 interrupts */
        #elif MSPI1_INT_STATUS == MSPI1_TXE_INT_ENABLE
                SET_BIT(MSPI1_Ptr -> SPI1_CR2, 7); /* Generate an interrupt request when the TXE flag is set */
        #elif MSPI1_INT_STATUS == MSPI1_RXNE_INT_ENABLE
                SET_BIT(MSPI1_Ptr -> SPI1_CR2, 6); /* Generate an interrupt request when the RXNE flag is set */
        #endif

        /**/
        MSPI1_Ptr -> SPI1_CR1 &= 0xFFC7;

        /* SPI Prescaler Configuration */
        MSPI1_Ptr -> SPI1_CR1 |= (MSPI1_PRESCALLER << 3);

        /* Enable SPI Peripheral */
        SET_BIT(MSPI1_Ptr -> SPI1_CR1, 6);

    /* Check whether the SPI is disabled */
    #elif MSPI1_STATUS == MSPI1_DISABLE
        CLR_BIT(MSPI1_Ptr -> SPI1_CR1, 6);
    #endif

}

/* Send Data and return the received Data
    i/p: u8 Data to be sent in Data Register
    return: u8 Data received in Data Register as SPI is a full duplex protocol */
u8 MSPI1_voidSendDataU8(u8 Copy_u8DataToTransmit)
{
    /* Set the data to be sent to Data Register */
	MSPI1_Ptr -> SPI1_DR = Copy_u8DataToTransmit;
    /* Wait busy flag to finish */
	while (GET_BIT(MSPI1_Ptr -> SPI1_SR, 7) == 1);
    /* Return the received data in Data Register */
	return (u8) MSPI1_Ptr -> SPI1_DR;
}

/* Callback function to fire an interrupt once the data 
   is received and start implementing the function given as input  */
void MSPI1_voidSetCallBack(void (*ptr) (void))
{
	MSPI1_CallBack = ptr;
}

/* SPI1 IRQ Handler */
void SPI1_IRQHandler(void)
{
	MSPI1_CallBack();
}

/* Asynchronous function:
 > > Notes: 
 - Cannot return the received data as the function will be implemented before the SPI send/receive operation
 - The interrupt handler will get the received data
 - Function prototype as below will let the incomming interrupt send the received value to the 
    called where the callback will take u8 as i/p parameter "received data"
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit , void(*CallBack)(u8) ); 
 - IRQ Handler implementation as below: 
void SPI1_IRQHandler(void)
{
    CallBack(MSPI_Ptr -> SPI_DR);
}
*/

/* Send/Receive in one function as SPI is a full duplex protocole that 
   send/receive at the same time. 
   input: Copy_u8DataToTransmit > data to send, 
          Copy_u8DataToReceive > pointer of data received */
/* void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit , u8 *Copy_u8DataToReceive)
{
    // Clear for Slave Select Pin 
    // Assume that we have one slave, if we have multiple slaves, give
    //the function one more parameter of which slave to talk to 
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN , LOW);

    // Send Data 
    MSPI_Ptr -> SPI_DR = Copy_u8DataToTransmit;

    // Wait busy flag to finish 
    while (GET_BIT(MSPI_Ptr -> SPI_SR, 7) == 1);

    // Return to the received data from slave 
    // mmken a5ali el function t3mel return u8 lel data el fl DR 
    *Copy_u8DataToReceive = MSPI_Ptr -> SPI_DR;

    // Set Slave select pin "off" as it's active low pin 
    MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN , HIGH);
}*/
