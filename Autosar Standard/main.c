
/********************************************************************************************************
*  [FILE NAME]   :      <main.c>                                                                        *
*  [AUTHOR]      :      <David S. Alexander>                                                            *
*  [DATE CREATED]:      <July 26, 2023>                                                                 *
*  [Description} :      <Source file for the AVR Dio driver main app Autosar Standard>                  *
********************************************************************************************************/

#include "Std_Libraries/DEVICE_CONFIG.h"
#include "MCAL/Dio/Inc/Dio.h"
#include "MCAL/Dio/Inc/Dio_MemMap.h"

uint8 Port_Status = PORT_NOT_INITIALIZED;
void Port_Init(void);
int main(void)
{
    Port_Init();	
	Dio_LevelType SW1 = STD_HIGH;
	while (1)
	{
		SW1 = Dio_ReadChannel(DioConf_SW1_CHANNEL_ID_INDEX);
		Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX, SW1);
	}
}

void Port_Init()
{
	// Set direction for LED1 pin (PORTC, Pin 2) as output
	SET_BIT(DIO_DDRC, DioConf_LED1_CHANNEL_INDEX);

	// Set direction for SW1 pin (PORTD, Pin 2) as input
	CLEAR_BIT(DIO_DDRD, DioConf_SW1_CHANNEL_INDEX);
	
	Port_Status = PORT_INITIALIZED;
}
