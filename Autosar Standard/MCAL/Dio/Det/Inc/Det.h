
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Det.h>                                                                         *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Error detection header file>                                                   *
 *********************************************************************************************************/


#ifndef DET_H_
#define DET_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/

#include "../../../../Std_Libraries/Std_Types.h"


/*******************************************************************************
 *                             Macro Declarations                              *
 *******************************************************************************/

#define DET_VENDOR_ID          7u   /* Valeo */

#define DET_MODULE_ID          17u


#define DET_SW_MAJOR_VERSION   1u
#define DET_SW_MINOR_VERSION   0u
#define DET_SW_PATCH_VERSION   0u

#define DET_AR_MAJOR_VERSION   4u
#define DET_AR_MINOR_VERSION   3u
#define DET_AR_PATCH_VERSION   1u

#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION) || (DET_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION) || (DET_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
#error "The AUTOSAR version of Det.h and Std_Types.h are different"
#endif


/*******************************************************************************
 *                            Functions Declaration                            *
 *******************************************************************************/

void Det_ReportError(uint16 ModuleId, uint8 ApiId, uint8 ErrorId);

#endif /* DET_H_ */