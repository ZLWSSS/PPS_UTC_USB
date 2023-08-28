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
# 1 "./wconvops.c"
# 17 "./wconvops.c"
#include "__SEGGER_RTL_Int.h"
#include "wctype.h"
#include "stdlib.h"
#include "stddef.h"
#include "errno.h"
#include "math.h"
#include "limits.h"
# 32 "./wconvops.c"
#define FLAG_DOTSEEN (1<<0)
#define FLAG_NUMOK (1<<1)
#define FLAG_NUMNEG (1<<2)
#define FLAG_EXPNEG (1<<3)
# 64 "./wconvops.c"
static unsigned long __SEGGER_RTL_wcstoul(const wchar_t *nsptr, wchar_t **endptr, int base) {
  const wchar_t *nptr = nsptr;
  wchar_t c;
  int ok, overflowed, digit;
  unsigned long dhigh, dlow;



  ok = 0;
  overflowed = 0;



  while ((c = *nptr++) != 0 && (iswspace)(c)) {

  }



  if (c == L'0') {



    ok = 1;
    c = *nptr++;
    if (c == L'x' || c == L'X') {



      if (base == 0 || base == 16) {



        ok = 0;
        base = 16;
        c = *nptr++;
      }
    } else if (base == 0) {
      base = 8;
    }
  }




  if (base == 0) {
    base = 10;
  }



  dhigh = 0;
  dlow = 0;
  while ((digit = __SEGGER_RTL_wdigit(c, base)) >= 0) {



    ok = 1;

#if __SEGGER_RTL_SIZEOF_LONG == 4
    dlow = base * dlow + digit;
    dhigh = base * dhigh + (dlow >> 16);
    dlow &= 0xFFFFu;
    if (dhigh >= 0x10000u) {
      overflowed = 1;
    }
#elif __SEGGER_RTL_SIZEOF_LONG == 8
    dlow = base * dlow + digit;
    dhigh = base * dhigh + (dlow >> 32);
    dlow &= 0xFFFFFFFFuL;
    if (dhigh >= 0x100000000uL) {
      overflowed = 1;
    }
#else
  #error case not covered
#endif
    c = *nptr++;
  }

  if (endptr) {
    *endptr = ok ? (wchar_t *)nptr-1 : (wchar_t *)nsptr;
  }

  if (overflowed) {
    errno = ERANGE;
    return ULONG_MAX;
  } else {
#if __SEGGER_RTL_SIZEOF_LONG == 4
    return (dhigh << 16) | dlow;
#else
    return (dhigh << 32) | dlow;
#endif
  }
}
# 179 "./wconvops.c"
static unsigned long long __SEGGER_RTL_wcstoull(const wchar_t *nsptr, wchar_t **endptr, int base) {
  const wchar_t *nptr = nsptr;
  wchar_t c;
  int ok, overflowed, digit;
  unsigned long long dhigh, dlow;



  ok = 0;
  overflowed = 0;



  while ((c = *nptr++) != 0 && (iswspace)(c)) {

  }



  if (c == L'0') {



    ok = 1;
    c = *nptr++;
    if (c == L'x' || c == L'X') {



      if (base == 0 || base == 16) {



        ok = 0;
        base = 16;
        c = *nptr++;
      }
    } else if (base == 0) {
      base = 8;
    }
  }




  if (base == 0) {
    base = 10;
  }



  dhigh = 0;
  dlow = 0;
  while ((digit = __SEGGER_RTL_wdigit(c, base)) >= 0) {



    ok = 1;

    dlow = base * dlow + digit;
    dhigh = base * dhigh + (dlow >> 32);
    dlow &= 0xFFFFFFFFuLL;
    if (dhigh >= 0x100000000uLL) {
      overflowed = 1;
    }
    c = *nptr++;
  }

  if (endptr) {
    *endptr = ok ? (wchar_t *)nptr-1 : (wchar_t *)nsptr;
  }

  if (overflowed) {
    errno = ERANGE;
    return ULLONG_MAX;
  } else {
    return (dhigh << 32) | dlow;
  }
}
# 320 "./wconvops.c"
float __SEGGER_RTL_PUBLIC_API wcstof(const wchar_t *nptr, wchar_t **endptr) {
  const wchar_t *p = nptr;
  wchar_t ch;
  int x = 0;
  float l = 0.0;
  int flag = 0;

  while ((iswspace)(ch = *p++)) {

  }

  switch (ch) {
  case L'-':
    flag |= FLAG_NUMNEG;

  case L'+':
    ch = *p++;
  }

  for (;;) {
    if (ch == L'.' && (flag & FLAG_DOTSEEN) == 0) {
      flag |= FLAG_DOTSEEN;
    } else if ((iswdigit)(ch)) {
      flag |= FLAG_NUMOK;
      l = l*10 + (ch - L'0');
      if (flag & FLAG_DOTSEEN) {
        --x;
      }
    } else {
      break;
    }
    ch = *p++;
  }



  if ((ch == L'e' || ch == L'E') && (flag & FLAG_NUMOK)) {
    int x2 = 0;
    flag &= ~FLAG_NUMOK;
    switch (ch = *p++) {
    case L'-':
      flag |= FLAG_EXPNEG;

    case L'+':
      ch = *p++;
    }
    while ((iswdigit)(ch)) {
      flag |= FLAG_NUMOK;
      x2 = (x2 > 1000) ? 10000 : 10*x2 + (ch - L'0');
      ch = *p++;
    }
    if (flag & FLAG_EXPNEG) {
      x -= x2;
    } else {
      x += x2;
    }
  }



  while (x > 0) {
    l *= 10;
    --x;
  }
  while (x < 0) {
    l /= 10;
    ++x;
  }

  if (isinf(l)) {
    errno = ERANGE;
    l = HUGE_VALF;
  }
  if (flag & FLAG_NUMNEG) {
    l = -l;
  }
  if (flag & FLAG_NUMOK) {
    if (endptr) {
      *endptr = (wchar_t *)p-1;
    }
    return l;
  } else {
    if (endptr) {
      *endptr = (wchar_t *)nptr;
    }
    return 0;
  }
}
# 463 "./wconvops.c"
double __SEGGER_RTL_PUBLIC_API wcstod(const wchar_t *nptr, wchar_t **endptr) {
  const wchar_t *p = nptr;
  wchar_t ch;
  int x = 0;
  double l = 0.0;
  int flag = 0;

  while ((iswspace)(ch = *p++)) {

  }

  switch (ch) {
  case L'-':
    flag |= FLAG_NUMNEG;

  case L'+':
    ch = *p++;
  }

  for (;;) {
    if (ch == L'.' && (flag & FLAG_DOTSEEN) == 0) {
      flag |= FLAG_DOTSEEN;
    } else if ((iswdigit)(ch)) {
      flag |= FLAG_NUMOK;
      l = l*10 + (ch - L'0');
      if (flag & FLAG_DOTSEEN) {
        --x;
      }
    } else {
      break;
    }
    ch = *p++;
  }



  if ((ch == L'e' || ch == L'E') && (flag & FLAG_NUMOK)) {
    int x2 = 0;
    flag &= ~FLAG_NUMOK;
    switch (ch = *p++) {
    case L'-':
      flag |= FLAG_EXPNEG;

    case L'+':
      ch = *p++;
    }
    while ((iswdigit)(ch)) {
      flag |= FLAG_NUMOK;
      x2 = (x2 > 1000) ? 10000 : 10*x2 + (ch - L'0');
      ch = *p++;
    }
    if (flag & FLAG_EXPNEG) {
      x -= x2;
    } else {
      x += x2;
    }
  }



  while (x > 0) {
    l *= 10;
    --x;
  }
  while (x < 0) {
    l /= 10;
    ++x;
  }

  if (isinf(l)) {
    errno = ERANGE;
    l = HUGE_VAL;
  }
  if (flag & FLAG_NUMNEG) {
    l = -l;
  }

  if (flag & FLAG_NUMOK) {
    if (endptr) {
      *endptr = (wchar_t *)p-1;
    }
    return l;
  } else {
    if (endptr) {
      *endptr = (wchar_t *)nptr;
    }
    return 0;
  }
}
# 607 "./wconvops.c"
long double __SEGGER_RTL_PUBLIC_API wcstold(const wchar_t *nptr, wchar_t **endptr) {
  return (long double)(wcstod(nptr, endptr));
}
# 682 "./wconvops.c"
long __SEGGER_RTL_PUBLIC_API wcstol(const wchar_t *nptr, wchar_t **endptr, int base) {
  const wchar_t *unptr = nptr;
  wchar_t *endp;
  unsigned long ud;
  int neg = 0;
  wchar_t c;

  while ((c = *unptr++) != 0 && (iswspace)(c)) {

  }
  switch (c) {
  case L'-':
    neg = 1;
  case L'+':
    break;
  default:
    --unptr;
    break;
  }

  ud = __SEGGER_RTL_wcstoul((wchar_t *)unptr, &endp, base);
  if (endptr)
    *endptr = endp == (wchar_t *)unptr ? (wchar_t *)nptr : endp;
  if (neg)
    if (ud == (unsigned long)LONG_MAX+1) {
      return LONG_MIN;
    } else if (ud <= LONG_MAX) {
      return -(long)ud;
    } else {
      errno = ERANGE;
      return LONG_MIN;
    }
  else {
    if (ud <= LONG_MAX) {
      return (long)ud;
    } else {
      errno = ERANGE;
      return LONG_MAX;
    }
  }
}
# 795 "./wconvops.c"
long long __SEGGER_RTL_PUBLIC_API wcstoll(const wchar_t *nptr, wchar_t **endptr, int base) {
  const wchar_t *unptr = nptr;
  wchar_t *endp;
  unsigned long long ud;

  int neg = 0, c;
  while ((c = *unptr++) != 0 && (iswspace)(c))
    ;
  switch (c) {
  case L'-':
    neg = 1;
  case L'+':
    break;
  default:
    --unptr;
    break;
  }

  ud = __SEGGER_RTL_wcstoull((wchar_t *)unptr, &endp, base);
  if (endptr)
    *endptr = endp == (wchar_t *)unptr ? (wchar_t *)nptr : endp;
  if (neg) {
    if (ud == (unsigned long long)LLONG_MAX+1) {
      return LLONG_MIN;
    } else if (ud <= LLONG_MAX) {
      return -(long long)ud;
    } else {
      errno = ERANGE;
      return LLONG_MIN;
    }
  } else {
    if (ud <= LLONG_MAX) {
      return (long long)ud;
    } else {
      errno = ERANGE;
      return LLONG_MAX;
    }
  }
}
# 905 "./wconvops.c"
unsigned long __SEGGER_RTL_PUBLIC_API wcstoul(const wchar_t *nptr, wchar_t **endptr, int base) {
  const wchar_t *unptr = nptr;
  unsigned long ud;
  wchar_t *endp;
  int neg = 0;
  wchar_t c;
  int saved_errno = errno;

  while ((c = *unptr++) != 0 && (iswspace)(c)) {

  }
  switch (c) {
  case L'-':
    neg = 1;
  case L'+':
    break;
  default:
    --unptr;
    break;
  }

  errno = 0;
  ud = __SEGGER_RTL_wcstoul((wchar_t *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (wchar_t *)unptr ? (wchar_t *)nptr : endp;
  }
  if (errno == ERANGE) {
    return ud;
  }
  errno = saved_errno;
  if (neg) {
    if (ud == (unsigned)LONG_MAX+1) {
      return LONG_MIN;
    } else if (ud <= LONG_MAX) {
      return -(long)ud;
    } else {
      errno = ERANGE;
      return ULONG_MAX;
    }
  } else {
    return ud;
  }
}
# 1019 "./wconvops.c"
unsigned long long __SEGGER_RTL_PUBLIC_API wcstoull(const wchar_t *nptr, wchar_t **endptr, int base) {
  const wchar_t *unptr = nptr;
  unsigned long long ud;
  wchar_t *endp;
  int neg = 0;
  wchar_t c;
  int errno_saved = errno;

  while ((c = *unptr++) != 0 && (iswspace)(c)) {

  }

  switch (c) {
  case L'-':
    neg = 1;
  case L'+':
    break;
  default:
    --unptr;
    break;
  }

  errno = 0;
  ud = __SEGGER_RTL_wcstoull((wchar_t *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (wchar_t *)unptr ? (wchar_t *)nptr : endp;
  }
  if (errno == ERANGE) {
    return ud;
  }
  errno = errno_saved;
  if (neg) {
    if (ud == (unsigned long long)LLONG_MAX+1) {
      return (unsigned long long)LLONG_MIN;
    } else if (ud <= LLONG_MAX) {
      return -(long long)ud;
    } else {
      errno = ERANGE;
      return ULLONG_MAX;
    }
  } else {
    return ud;
  }
}
