
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Platform_Types.h>                                                              *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <June 10, 2023>                                                                 *
 *  [Description} :      <Common - Platform Types Abstraction>                                           *
 *********************************************************************************************************/


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


/*******************************************************************************
 *                         Macros Declaration                                  *
 *******************************************************************************/ 

#define PLATFORM_VENDOR_ID          7u   /* Valeo */

#define PLATFORM_SW_MAJOR_VERSION   1u
#define PLATFORM_SW_MINOR_VERSION   0u
#define PLATFORM_SW_PATCH_VERSION   0u

#define PLATFORM_AR_MAJOR_VERSION   4u
#define PLATFORM_AR_MINOR_VERSION   0u
#define PLATFORM_AR_PATCH_VERSION   3u

#define CPU_TYPE_8                  8u
#define CPU_TYPE_16                 16u
#define CPU_TYPE_32                 32u

#define MSB_FIRST                   0u
#define LSB_FIRST                   1u

#define HIGH_BYTE_FIRST             0u
#define LOW_BYTE_FIRST              1u

#define CPU_TYPE                    CPU_TYPE_8

#define CPU_BIT_ORDER               LSB_FIRST
#define CPU_BYTE_ORDER              LOW_BYTE_FIRST

#ifndef FALSE
#define FALSE                       0u
#endif

#ifndef TRUE
#define TRUE                        1u
#endif

#define LOGIC_HIGH                  1u
#define LOGIC_LOW                   0u

/*******************************************************************************
 *                         Data Types Declaration                              *
 *******************************************************************************/ 

typedef unsigned char         uint8;         
typedef signed char           sint8;        
typedef unsigned short        uint16;        
typedef signed short          sint16;        
typedef unsigned long         uint32;     
typedef signed long           sint32;       
typedef unsigned long long    uint64;         
typedef signed long long      sint64;         
typedef float                 float32;
typedef double                float64;
typedef unsigned char         boolean;



#endif /* PLATFORM_TYPES_H_ */