
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Dio_Cfg.h>                                                                     *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Header file for Dio Configuration Driver>                                      *
 *********************************************************************************************************/


#ifndef DIO_CFG_H
#define DIO_CFG_H

#define DIO_CFG_SW_MAJOR_VERSION      1u
#define DIO_CFG_SW_MINOR_VERSION      0u
#define DIO_CFG_SW_PATCH_VERSION      0u

#define DIO_CFG_AR_MAJOR_VERSION      4u
#define DIO_CFG_AR_MINOR_VERSION      3u
#define DIO_CFG_AR_PATCH_VERSION      1u

#define DIO_DEV_ERROR_DETECT          STD_ON
#define DIO_VERSION_INFO_API          STD_ON
#define DIO_FLIP_CHANNEL_API          STD_ON

#define DIO_CONFIGURED_CHANNLES       4u

#define DioConf_LED1_CHANNEL_ID_INDEX (uint8)(0x00)
#define DioConf_LED2_CHANNEL_ID_INDEX (uint8)(0x01)
#define DioConf_SW1_CHANNEL_ID_INDEX  (uint8)(0x02)
#define DioConf_SW2_CHANNEL_ID_INDEX  (uint8)(0x03)

#define DioConf_LED1_PORT_INDEX       (Dio_PortType)2    /* PORTC */
#define DioConf_LED2_PORT_INDEX       (Dio_PortType)2    /* PORTC */
#define DioConf_SW1_PORT_INDEX        (Dio_PortType)3    /* PORTD */
#define DioConf_SW2_PORT_INDEX        (Dio_PortType)3    /* PORTD */

#define DioConf_LED1_CHANNEL_INDEX    (Dio_ChannelType)3 /* Pin 3 in PORTC */
#define DioConf_LED2_CHANNEL_INDEX    (Dio_ChannelType)4 /* Pin 4 in PORTC */
#define DioConf_SW1_CHANNEL_INDEX     (Dio_ChannelType)2 /* Pin 2 in PORTD */
#define DioConf_SW2_CHANNEL_INDEX     (Dio_ChannelType)3 /* Pin 3 in PORTD */


#endif /* DIO_CFG_H */