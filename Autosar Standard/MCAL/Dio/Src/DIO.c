
/********************************************************************************************************
*  [FILE NAME]   :      <Dio.c>                                                                         *
*  [AUTHOR]      :      <David S. Alexander>                                                            *
*  [DATE CREATED]:      <July 26, 2023>                                                                 *
*  [Description} :      <Source file for the AVR Dio driver Autosar based>                              *
********************************************************************************************************/

#include "../Inc/Dio.h"
#include "../Inc/Dio_MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "../Det/Inc/Det.h"

#if ((DET_AR_MAJOR_VERSION != DIO_AR_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != DIO_AR_MINOR_VERSION) || (DET_AR_PATCH_VERSION != DIO_AR_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif


void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile Dio_PortLevelType *Port_Ptr = NULL;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PORT_INITIALIZED != Port_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_CONFIG);
	}
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	#endif
	if (PORT_INITIALIZED == Port_Status)
	{
		switch(Dio_Configuration.Channels[ChannelId].PortIndex)
		{
			case 0:
			Port_Ptr = &DIO_PORTA;
			break;
			case 1:
			Port_Ptr = &DIO_PORTB;
			break;
			case 2:
			Port_Ptr = &DIO_PORTC;
			break;
			case 3:
			Port_Ptr = &DIO_PORTD;
			break;
			default:
			break;
		}
		if(Level == STD_HIGH)
		{
			SET_BIT(*Port_Ptr,Dio_Configuration.Channels[ChannelId].ChannelIndex);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(*Port_Ptr,Dio_Configuration.Channels[ChannelId].ChannelIndex);
		}
	}
}
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile Dio_PortLevelType *PIN_Ptr = NULL;
	Dio_LevelType ChannelLevel = STD_LOW;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PORT_INITIALIZED != Port_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_READ_CHANNEL_SID, DIO_E_PARAM_CONFIG);
	}
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	#endif
	if (PORT_INITIALIZED == Port_Status)
	{
		switch(Dio_Configuration.Channels[ChannelId].PortIndex)
		{
			case 0:
			PIN_Ptr = &DIO_PINA;
			break;
			case 1:
			PIN_Ptr = &DIO_PINB;
			break;
			case 2:
			PIN_Ptr = &DIO_PINC;
			break;
			case 3:
			PIN_Ptr = &DIO_PIND;
			break;
		}
		ChannelLevel = READ_BIT(*PIN_Ptr,Dio_Configuration.Channels[ChannelId].ChannelIndex);
	}
	return ChannelLevel ;
}

/* Dio_WriteChannelGroup: Write to the specified channel group */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	Dio_PortLevelType Level = ZERO_INIT;
	if (PORT_INITIALIZED == Port_Status)
	{
		if(NULL != ChannelGroupIdPtr)
		{
			volatile Dio_PortLevelType *Port_Ptr = NULL;
			switch(Dio_Configuration.Channels[ChannelGroupIdPtr->PortIndex].PortIndex)
			{
				case 0:
				Port_Ptr = &DIO_PORTA;
				break;
				case 1:
				Port_Ptr = &DIO_PORTB;
				break;
				case 2:
				Port_Ptr = &DIO_PORTC;
				break;
				case 3:
				Port_Ptr = &DIO_PORTD;
				break;
				default:
				break;
			}
			Level = (Dio_ReadChannel(*Port_Ptr) & (ChannelGroupIdPtr->ChannelsMask)) >> (ChannelGroupIdPtr->ChannelOffset);
		}
	}

	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PORT_INITIALIZED != Port_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_CONFIG);
	}
	if(NULL == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
	}
	#endif
	
	return Level;
}

/* Dio_WriteChannelGroup: Read the specified channel group */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PORT_INITIALIZED != Port_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_CONFIG);
	}
	if(NULL == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_POINTER);
	}
	#endif
	if (PORT_INITIALIZED == Port_Status)
	{
		if(NULL != ChannelGroupIdPtr)
		{
			volatile Dio_PortLevelType *Port_Ptr = NULL;
			switch(Dio_Configuration.Channels[ChannelGroupIdPtr->PortIndex].PortIndex)
			{
				case 0:
				Port_Ptr = &DIO_PORTA;
				break;
				case 1:
				Port_Ptr = &DIO_PORTB;
				break;
				case 2:
				Port_Ptr = &DIO_PORTC;
				break;
				case 3:
				Port_Ptr = &DIO_PORTD;
				break;
				default:
				break;
			}
			Dio_WriteChannel((*Port_Ptr & (ChannelGroupIdPtr->ChannelsMask)) >> ChannelGroupIdPtr->ChannelOffset, Level);
		}
	}
}

#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile Dio_PortLevelType *Port_Ptr = NULL;
	Dio_LevelType Level = STD_LOW;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PORT_INITIALIZED != Port_Status)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_CONFIG);
	}
	if (DIO_CONFIGURED_CHANNLES <= ChannelId)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	#endif
	if (PORT_INITIALIZED == Port_Status)
	{
		switch(Dio_Configuration.Channels[ChannelId].PortIndex)
		{
			case 0:
			Port_Ptr = &DIO_PORTA;
			break;
			case 1:
			Port_Ptr = &DIO_PORTB;
			break;
			case 2:
			Port_Ptr = &DIO_PORTC;
			break;
			case 3:
			Port_Ptr = &DIO_PORTD;
			break;
			default:
			break;
		}
		Level = TOGGLE_BIT(*Port_Ptr, Dio_Configuration.Channels[ChannelId].ChannelIndex);
	}
	return Level;
}
#endif

#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if(NULL == versioninfo)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
	}
	else
	#endif
	{
		versioninfo->vendorID         = DIO_VENDOR_ID;
		versioninfo->moduleID         = DIO_MODULE_ID;
		versioninfo->sw_major_version = DIO_SW_MAJOR_VERSION;
		versioninfo->sw_minor_version = DIO_SW_MINOR_VERSION;
		versioninfo->sw_patch_version = DIO_SW_PATCH_VERSION;
	}
}
#endif