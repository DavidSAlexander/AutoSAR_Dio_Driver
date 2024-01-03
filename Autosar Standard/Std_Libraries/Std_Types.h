
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Std_Types.h>                                                                   *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Common - Std Types Abstraction>                                                *
 *********************************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/

#include "Platform_Types.h"
#include "Compiler.h"


/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

#define STD_TYPES_VENDOR_ID         7u      /* Valeo */       

#define STD_TYPES_SW_MAJOR_VERSION  1u      
#define STD_TYPES_SW_MINOR_VERSION  0u     
#define STD_TYPES_SW_PATCH_VERSION  0u      

#define STD_TYPES_AR_MAJOR_VERSION  4u      
#define STD_TYPES_AR_MINOR_VERSION  3u      
#define STD_TYPES_AR_PATCH_VERSION  1u      

#define STD_HIGH                    1u 
#define STD_LOW                     0u 
#define STD_ACTIVE                  1u 
#define STD_IDLE                    0u 
#define STD_ON                      1u
#define STD_OFF                     0u
#define E_OK                        0u
#define E_NOT_OK                    1u   

#define PORT_INPUT                  0x00U
#define PORT_OUTPUT                 0xFFU
#define PIN_INPUT                   0x00U
#define PIN_OUTPUT                  0x01U
#define PORT_HIGH                   0xFFU
#define PORT_LOW                    0x00U

#define ZERO_INIT                   0x00U

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/ 

typedef uint8 Std_ReturnType;

typedef struct 
{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
} Std_VersionInfoType;

#endif /* STD_TYPE_H_ */
