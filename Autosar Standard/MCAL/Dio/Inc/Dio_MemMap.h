
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Dio_MemMap.h>                                                                  *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Header file for Dio Registers>                                                 *
 *********************************************************************************************************/  


#ifndef DIO_REGS_H_
#define DIO_REGS_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/

#include "../../../Std_Libraries/Std_Types.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

/* Port D */
#define DIO_PIND    SFR_IO8(0x10)
#define DIO_DDRD    SFR_IO8(0x11)
#define DIO_PORTD   SFR_IO8(0x12)

/* Port C */
#define DIO_PINC    SFR_IO8(0x13)
#define DIO_DDRC    SFR_IO8(0x14)
#define DIO_PORTC   SFR_IO8(0x15)

/* Port B */
#define DIO_PINB    SFR_IO8(0x16)
#define DIO_DDRB    SFR_IO8(0x17)
#define DIO_PORTB   SFR_IO8(0x18)

/* Port A */
#define DIO_PINA    SFR_IO8(0x19)
#define DIO_DDRA    SFR_IO8(0x1A)
#define DIO_PORTA   SFR_IO8(0x1B)


/* Target Ports & Channels index "ATmega32/16" */
#define DIO_PORTA_INDEX                ((Dio_PortType)0U)
#define DIO_PORTB_INDEX                ((Dio_PortType)1U)
#define DIO_PORTC_INDEX                ((Dio_PortType)2U)
#define DIO_PORTD_INDEX                ((Dio_PortType)3U)
#define DIO_PORTS_MAX_NUM              (uint8)(4U)
#define DIO_PORTS_BASE_ID              (uint8)(0U)

#define DIO_CHANNEL_0                  ((Dio_ChannelType)0U)
#define DIO_CHANNEL_1                  ((Dio_ChannelType)1U)
#define DIO_CHANNEL_2                  ((Dio_ChannelType)2U)
#define DIO_CHANNEL_3                  ((Dio_ChannelType)3U)
#define DIO_CHANNEL_4                  ((Dio_ChannelType)4U)
#define DIO_CHANNEL_5                  ((Dio_ChannelType)5U)
#define DIO_CHANNEL_6                  ((Dio_ChannelType)6U)
#define DIO_CHANNEL_7                  ((Dio_ChannelType)7U)
#define DIO_CHANNELS_MAX_NUM           (uint8)(8U)

#endif /* DIO_REGS_H_ */