/*********************************************************************
*                     SEGGER Microcontroller GmbH                    *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*       (c) 1995 - 2022 SEGGER Microcontroller GmbH                  *
*                                                                    *
*       Internet: segger.com  Support: support_embos@segger.com      *
*                                                                    *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------
File    : OS_Config.h
Purpose : Configuration settings for the OS build and embOSView
*/

#ifndef OS_CONFIG_H
#define OS_CONFIG_H
  //
  // In an application program, the compiler needs to know which embOS
  // kernel configuration was selected to ensure the application is
  // compiled using the exact same settings as the precompiled library.
  // To automate this with projects that were generated based on the
  // embOS CMSIS package, the auto-generated RTE_Components.h will hold
  // one of the following defines according to the selected kernel
  // configuration:
  //   OS_LIBMODE_XR - configuration intended for size-restrained release builds
  //   OS_LIBMODE_R  - configuration intended for release builds
  //   OS_LIBMODE_S  - configuration including stack check features
  //   OS_LIBMODE_SP - configuration including profiling and stack check
  //   OS_LIBMODE_D  - configuration including debug
  //   OS_LIBMODE_DP - configuration including debug, profiling and stack check
  //   OS_LIBMODE_DT - configuration including debug, profiling, stack check and trace
  //
  #include "RTE_Components.h"
#endif

/*************************** End of file ****************************/
