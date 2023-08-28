/*********************************************************************
*                   (c) SEGGER Microcontroller GmbH                  *
*                        The Embedded Experts                        *
*                           www.segger.com                           *
**********************************************************************

----------------------------------------------------------------------
Licensing information
For use with Embedded Studio only.
A valid license for Embedded Studio is required.
-------------------------- END-OF-HEADER -----------------------------
*/
# 1 "./fenvops.c"
# 17 "./fenvops.c"
#include "__SEGGER_RTL_Int.h"
#include "fenv.h"
# 27 "./fenvops.c"
const fenv_t __SEGGER_RTL_default_fenv;
# 36 "./fenvops.c"
#if __SEGGER_RTL_INCLUDE_C_API
# 63 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API feclearexcept(int excepts) {
  return excepts == 0 ? 0 : 1;
}
# 92 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API feraiseexcept(int excepts) {
  return excepts == 0 ? 0 : 1;
}
# 117 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API fetestexcept(int excepts) {
  __SEGGER_RTL_USE_PARA(excepts);
  return 0;
}
# 147 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API fegetexceptflag(fexcept_t *flagp, int excepts) {
  __SEGGER_RTL_USE_PARA(flagp);
  __SEGGER_RTL_USE_PARA(excepts);

  return 0;
}
# 182 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API fesetexceptflag(const fexcept_t *flagp, int excepts) {
  __SEGGER_RTL_USE_PARA(flagp);

  return excepts == 0 ? 0 : 1;
}
# 209 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API fegetround(void) {
  return FE_TONEAREST;
}
# 237 "./fenvops.c"
int __SEGGER_RTL_PUBLIC_API fesetround(int round) {
  return round == FE_TONEAREST ? 0 : 1;
}
# 270 "./fenvops.c"
int fegetenv(fenv_t *envp) {
  envp->__control = 0;
  return 0;
}
# 304 "./fenvops.c"
int fesetenv(const fenv_t *envp) {
  __SEGGER_RTL_USE_PARA(envp);

  return 0;
}
# 337 "./fenvops.c"
int feupdateenv(const fenv_t *envp) {
  __SEGGER_RTL_USE_PARA(envp);

  return 0;
}
# 367 "./fenvops.c"
int feholdexcept(fenv_t *envp) {
  __SEGGER_RTL_USE_PARA(envp);

  return 0;
}

#endif
