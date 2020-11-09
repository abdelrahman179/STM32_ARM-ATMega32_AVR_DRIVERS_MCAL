/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 19 August 2020                                                     */
/* Version: V02                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 NVIC Prototypes of Public Functions    */
/*******************************************************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_


#define NO_SUB_PRIORITY 0

#define PEND_SV        -6
#define SYSTICK        -5

#define SV_CALL        -4

#define MEMORY_MANAGE  -3
#define BUS_FAULT      -2
#define USAGE_FAULT    -1


/* GROUP 3
Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 ); */

/* u8 Priority   = ( Copy_u8SubPriority | (Copy_u8GroupPriority << 4) );
 0x100 Hex  ---> 256 Decimal */
#define GROUP3     0x05FA0300   //0 bit for sub & 4 bit For group   << 0
#define GROUP4     0x05FA0400   //1 bit for sub & 3 bit For group   << 1
#define GROUP5     0x05FA0500   //2 bit for sub & 2 bit For group   << 2
#define GROUP6     0x05FA0600   //3 bit for sub & 1 bit For group   << 3
#define GROUP7     0x05FA0700   //4 bit for sub & 0 bit For group   << 4


/* #define For Interrupt ID =  Position In Vector Table */
#define WWDG   0
#define EXT0   6
#define EXT1   7
#define DMA_ID 11


/* Function that enables peripheral external interrupts from 0 to 59  */
void MNVIC_voidEnablePeripheral(u8 Copy_u8IntId);

/* Function that disables external interrupts from 0 to 59  */
void MNVIC_voidDisablePeripheral(u8 Copy_u8IntId);

/* Function that enables the pending flag for debugging  */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntId); 

/* Function that disables the pending flag for debugging  */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntId);

/* Function that reads the interrupt activity status flag  */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntId);

/* Function that sets the group and sub-group priority for the input peripheral-ID */
void MNVIC_voicSWSetPriority(s8 Copy_u8IntId , u8 Copy_u8GroupPri , u8 Copy_u8SubPri , u32 Copy_u32Group);


#endif 
