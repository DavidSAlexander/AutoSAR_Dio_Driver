
/********************************************************************************************************
 *  [FILE NAME]   :      <Dio.h>                                                                        *
 *  [AUTHOR]      :      <David S. Alexander>                                                           *
 *  [DATE CREATED]:      <July 26, 2023>                                                               *
 *  [Description} :      <Header file for the AVR Dio driver Autosar based>                             *
 ********************************************************************************************************/
 
#ifndef DIO_H
#define	DIO_H

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/


#include "../../../Std_Libraries/Std_Types.h"
#include "../../../Std_Libraries/Common_Macros.h"
#include "../Inc/Dio_Cfg.h"

/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

#define DIO_VENDOR_ID                  7u      /* Valeo */
#define DIO_MODULE_ID                  120u

/* Module Version 1.0.0 */
#define DIO_SW_MAJOR_VERSION           1u
#define DIO_SW_MINOR_VERSION           0u
#define DIO_SW_PATCH_VERSION           0u

/* AUTOSAR Version 4.3.1 */
#define DIO_AR_MAJOR_VERSION           4u
#define DIO_AR_MINOR_VERSION           3u
#define DIO_AR_PATCH_VERSION           1u 

/* Dio status */
#define PORT_INITIALIZED               1u
#define PORT_NOT_INITIALIZED           0u

/* Service Ids */
#define DIO_READ_CHANNEL_SID           (uint8)(0x00)
#define DIO_WRITE_CHANNEL_SID          (uint8)(0x01)
#define DIO_READ_PORT_SID              (uint8)(0x02)
#define DIO_WRITE_PORT_SID             (uint8)(0x03)
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)(0x04)
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)(0x05)
#define DIO_GET_VERSION_INFO_SID       (uint8)(0x12)
#define DIO_INIT_SID                   (uint8)(0x10)
#define DIO_FLIP_CHANNEL_SID           (uint8)(0x11)

/* DET Error Ids  */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)(0x0A)
#define DIO_E_PARAM_CONFIG             (uint8)(0x10)
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)(0x14)
#define DIO_E_PARAM_INVALID_GROUP      (uint8)(0x1F)
#define DIO_E_PARAM_POINTER            (uint8)(0x20)
#define DIO_E_UNINIT                   (uint8)0xF0

/* Checking between Std Types and Autosar Dio Module */
#if ((STD_TYPES_AR_MAJOR_VERSION != DIO_AR_MAJOR_VERSION) || (STD_TYPES_AR_MINOR_VERSION != DIO_AR_MINOR_VERSION) || (STD_TYPES_AR_PATCH_VERSION != DIO_AR_PATCH_VERSION))
#error "AUTOSAR version mismatch between Std_Types.h and Dio.h"
#endif

/* Autosar Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_MAJOR_VERSION != DIO_AR_MAJOR_VERSION) || (DIO_CFG_AR_MINOR_VERSION != DIO_AR_MINOR_VERSION) || (DIO_CFG_AR_PATCH_VERSION != DIO_AR_PATCH_VERSION))
#error "AUTOSAR version mismatch between Dio_Cfg.h and Dio.h"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION) || (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION) || (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "Software version mismatch between Dio_Cfg.h and Dio.h"
#endif

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/

typedef uint8 Dio_PortType;
typedef uint8 Dio_ChannelType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;
typedef uint8 Dio_DirectionType;

/* Dio_ChannelGroupType structure to represent a channel group */
typedef struct
{
	Dio_ChannelType   ChannelsMask;
	Dio_ChannelType   ChannelOffset;
	Dio_PortType      PortIndex;
} Dio_ChannelGroupType;

typedef struct
{
	Dio_ChannelType   ChannelIndex;
	Dio_PortType      PortIndex;
} Dio_ConfigChannel;

typedef struct
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;
		
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const Dio_ConfigType Dio_Configuration;
extern uint8 Port_Status;

		
/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/

void Dio_WritePort(Dio_PortType PortIndex, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortIndex);

void Dio_WriteChannel(Dio_ChannelType ChannelIndex, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelIndex);

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for Dio flip channel */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelIndex);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

#endif	/* DIO_H */
