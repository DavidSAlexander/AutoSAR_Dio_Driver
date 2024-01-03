
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Dio_Lcfg.c>                                                                    *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Source file for Dio Link-Time Configuration Driver>                            *
 *********************************************************************************************************/ 

#include "../Inc/Dio.h"

#define DIO_LCFG_SW_MAJOR_VERSION  1u
#define DIO_LCFG_SW_MINOR_VERSION  0u
#define DIO_LCFG_SW_PATCH_VERSION  0u

#define DIO_LCFG_AR_MAJOR_VERSION  4u
#define DIO_LCFG_AR_MINOR_VERSION  3u
#define DIO_LCFG_AR_PATCH_VERSION  1u

#if ((DIO_LCFG_AR_MAJOR_VERSION != DIO_AR_MAJOR_VERSION) || (DIO_LCFG_AR_MINOR_VERSION != DIO_AR_MINOR_VERSION) || (DIO_LCFG_AR_PATCH_VERSION != DIO_AR_PATCH_VERSION))
#error "AUTOSAR version mismatch between Dio_Lcfg.c and Dio.h"
#endif

#if ((DIO_LCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION) || (DIO_LCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION) || (DIO_LCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "Software version mismatch between Dio_Lcfg.c and Dio.h"
#endif

const Dio_ConfigType Dio_Configuration =
{
	.Channels[DioConf_LED1_CHANNEL_ID_INDEX].ChannelIndex = DioConf_LED1_CHANNEL_INDEX,
	.Channels[DioConf_LED1_CHANNEL_ID_INDEX].PortIndex    = DioConf_LED1_PORT_INDEX,
	
	.Channels[DioConf_LED2_CHANNEL_ID_INDEX].ChannelIndex = DioConf_LED2_CHANNEL_INDEX,
	.Channels[DioConf_LED2_CHANNEL_ID_INDEX].PortIndex    = DioConf_LED2_PORT_INDEX,
	
	.Channels[DioConf_SW1_CHANNEL_ID_INDEX].ChannelIndex  = DioConf_SW1_CHANNEL_INDEX,
	.Channels[DioConf_SW1_CHANNEL_ID_INDEX].PortIndex     = DioConf_SW1_PORT_INDEX,
	
	.Channels[DioConf_SW2_CHANNEL_ID_INDEX].ChannelIndex  = DioConf_SW2_CHANNEL_INDEX,
	.Channels[DioConf_SW2_CHANNEL_ID_INDEX].PortIndex     = DioConf_SW2_PORT_INDEX
};