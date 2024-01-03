
  /*******************************************************************************************************
 *  [FILE NAME]   :      <Compiler.h>                                                                    *
 *  [AUTHOR]      :      <David S. Alexander>                                                            *
 *  [DATE CREATED]:      <July 26, 2023>                                                                 *
 *  [Description} :      <Header file for compiler abstraction>                                          *
 *********************************************************************************************************/


#ifndef COMPILER_H_
#define COMPILER_H_

/*******************************************************************************
 *                         Macros Declaration                                  *
 *******************************************************************************/ 

#define COMPILER_VENDOR_ID         7u   /* Valeo */

#define COMPILER_SW_MAJOR_VERSION  1u
#define COMPILER_SW_MINOR_VERSION  0u
#define COMPILER_SW_PATCH_VERSION  0u

#define COMPILER_AR_MAJOR_VERSION  4u
#define COMPILER_AR_MINOR_VERSION  3u
#define COMPILER_AR_PATCH_VERSION  1u

#define STATIC                     static
#define INLINE                     inline
#define LOCAL_INLINE               static inline
#ifndef NULL
#define NULL                       ((void *)0)
#endif


#endif /* COMPILER_H_ */