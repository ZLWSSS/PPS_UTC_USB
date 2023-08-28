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
# 1 "./convops.c"
# 17 "./convops.c"
#include "__SEGGER_RTL_Int.h"
#include "ctype.h"
#include "stdlib.h"
#include "stddef.h"
#include "errno.h"
#include "math.h"
#include "limits.h"
# 32 "./convops.c"
#define FLAG_DOTSEEN (1<<0)
#define FLAG_NUMOK (1<<1)
#define FLAG_NUMNEG (1<<2)
#define FLAG_EXPNEG (1<<3)
# 60 "./convops.c"
static char * __SEGGER_RTL_xtoa(unsigned val, char *buf, unsigned radix, int neg) {
  char *p, *q;

  p = buf;
  if (neg) {
    *p++ = '-';
    val = ~val + 1;
  }
  q = p;



  do {
    unsigned digit = (unsigned)(val % radix);
    val /= radix;
    *p++ = digit > 9 ? (digit - 10 + 'a') : (digit + '0');
  } while (val > 0);



  *p-- = '\0';
  do {
    char temp = *p;
    *p-- = *q;
    *q++ = temp;
  } while (q < p);

  return buf;
}
# 106 "./convops.c"
static char * __SEGGER_RTL_xltoa(unsigned long val, char *buf, unsigned radix, int neg) {
  char *p, *q;

  p = buf;
  if (neg) {
    *p++ = '-';
    val = ~val + 1;
  }
  q = p;



  do {
    unsigned digit = (unsigned)(val % radix);
    val /= radix;
    *p++ = digit > 9 ? (digit - 10 + 'a') : (digit + '0');
  }
  while (val > 0);



  *p-- = '\0';
  do {
    char temp = *p;
    *p-- = *q;
    *q++ = temp;
  } while (q < p);

  return buf;
}
# 153 "./convops.c"
static char * __SEGGER_RTL_xlltoa(unsigned long long val, char *buf, unsigned radix, int neg) {
  char *p, *q;

  p = buf;
  if (neg) {
    *p++ = '-';
    val = ~val + 1;
  }
  q = p;



  do {
    unsigned digit = (unsigned)(val % radix);
    val /= radix;
    *p++ = digit > 9 ? (digit - 10 + 'a') : (digit + '0');
  } while (val > 0);



  *p-- = '\0';
  do {
    char temp = *p;
    *p-- = *q;
    *q++ = temp;
  } while (q < p);

  return buf;
}
# 203 "./convops.c"
static unsigned long __SEGGER_RTL_strtoul(const char *nsptr, char **endptr, int base) {
  const unsigned char *nptr = (const unsigned char *)nsptr;
  int c, ok, overflowed, digit;
  unsigned long dhigh, dlow;



  ok = 0;
  overflowed = 0;



  while ((c = *nptr++) != 0 && (isspace)(c)) {

  }



  if (c == '0') {



    ok = 1;
    c = *nptr++;
    if (c == 'x' || c == 'X') {



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
  while ((digit = __SEGGER_RTL_digit(c, base)) >= 0) {



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
    *endptr = ok ? (char *)nptr-1 : (char *)nsptr;
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
# 317 "./convops.c"
static unsigned long long __SEGGER_RTL_strtoull(const char *nsptr, char **endptr, int base) {
  const unsigned char *nptr = (const unsigned char *)nsptr;
  int c, ok, overflowed, digit;
  unsigned long long dhigh, dlow;



  ok = 0;
  overflowed = 0;



  while ((c = *nptr++) != 0 && (isspace)(c)) {

  }



  if (c == '0') {



    ok = 1;
    c = *nptr++;
    if (c == 'x' || c == 'X') {



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
  while ((digit = __SEGGER_RTL_digit(c, base)) >= 0) {



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
    *endptr = ok ? (char *)nptr-1 : (char *)nsptr;
  }

  if (overflowed) {
    errno = ERANGE;
    return ULLONG_MAX;
  } else {
    return (dhigh << 32) | dlow;
  }
}
# 433 "./convops.c"
double __SEGGER_RTL_PUBLIC_API atof(const char *nptr) {
  double val = 0;
  int exp = 0;
  unsigned sign = 0;

  while ((isspace)(*nptr)) {
    ++nptr;
  }

  if (*nptr == '-') {
    ++nptr;
    sign = 1;
  } else if (*nptr == '+') {
    ++nptr;
  }

  while ((isdigit)(*nptr)) {
    val = val * 10 + (*nptr++ - '0');
  }

  if (*nptr == '.') {
    while ((isdigit)(*++nptr)) {
      val = val * 10 + (*nptr - '0');
      --exp;
    }
  }

  if (*nptr == 'e' || *nptr == 'E') {
    exp += atoi(++nptr);
  }

  while (exp < 0) {
    val /= 10;
    ++exp;
  }
  while (exp > 0) {
    val *= 10;
    --exp;
  }

  return sign ? -val : val;
}
# 506 "./convops.c"
int __SEGGER_RTL_PUBLIC_API atoi(const char *nptr) {



  int save_errno = errno;
  int res = (int)strtol(nptr, (char **)NULL, 10);
  errno = save_errno;
  return res;
}
# 546 "./convops.c"
long int __SEGGER_RTL_PUBLIC_API atol(const char *nptr) {



  int save_errno = errno;
  long int res = strtol(nptr, (char **)NULL, 10);
  errno = save_errno;
  return res;
}
# 586 "./convops.c"
long long int __SEGGER_RTL_PUBLIC_API atoll(const char *nptr) {



  int save_errno = errno;
  long long int res = strtoll(nptr, (char **)NULL, 10);
  errno = save_errno;
  return res;
}
# 650 "./convops.c"
float __SEGGER_RTL_PUBLIC_API strtof(const char *nptr, char **endptr) {
  const char *p = nptr;
  int ch, x = 0;
  float l = 0.0;
  int flag = 0;

  while ((isspace)(ch = *p++)) {

  }

  switch (ch) {
  case '-':
    flag |= FLAG_NUMNEG;

  case '+':
    ch = *p++;
  }

  for (;;) {
    if (ch == '.' && (flag & FLAG_DOTSEEN) == 0) {
      flag |= FLAG_DOTSEEN;
    } else if ((isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      l = l*10 + (ch - '0');
      if (flag & FLAG_DOTSEEN) {
        --x;
      }
    } else {
      break;
    }
    ch = *p++;
  }



  if ((ch == 'e' || ch == 'E') && (flag & FLAG_NUMOK)) {
    int x2 = 0;
    flag &= ~FLAG_NUMOK;
    switch (ch = *p++) {
    case '-':
      flag |= FLAG_EXPNEG;

    case '+':
      ch = *p++;
    }
    while ((isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      x2 = (x2 > 1000) ? 10000 : 10*x2 + (ch - '0');
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
      *endptr = (char *)p-1;
    }
    return l;
  } else {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
}
# 792 "./convops.c"
double __SEGGER_RTL_PUBLIC_API strtod(const char *nptr, char **endptr) {
  const char *p = nptr;
  int ch, x = 0;
  double l = 0.0;
  int flag = 0;

  while ((isspace)(ch = *p++)) {

  }

  switch (ch) {
  case '-':
    flag |= FLAG_NUMNEG;

  case '+':
    ch = *p++;
  }

  for (;;) {
    if (ch == '.' && (flag & FLAG_DOTSEEN) == 0) {
      flag |= FLAG_DOTSEEN;
    } else if ((isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      l = l*10 + (ch - '0');
      if (flag & FLAG_DOTSEEN) {
        --x;
      }
    } else {
      break;
    }
    ch = *p++;
  }



  if ((ch == 'e' || ch == 'E') && (flag & FLAG_NUMOK)) {
    int x2 = 0;
    flag &= ~FLAG_NUMOK;
    switch (ch = *p++) {
    case '-':
      flag |= FLAG_EXPNEG;

    case '+':
      ch = *p++;
    }
    while ((isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      x2 = (x2 > 1000) ? 10000 : 10*x2 + (ch - '0');
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
      *endptr = (char *)p-1;
    }
    return l;
  } else {
    if (endptr) {
      *endptr = (char *)nptr;
    }
    return 0;
  }
}
# 935 "./convops.c"
long double __SEGGER_RTL_PUBLIC_API strtold(const char *nptr, char **endptr) {
  return (long double)(strtod(nptr, endptr));
}
# 1010 "./convops.c"
long __SEGGER_RTL_PUBLIC_API strtol(const char *nptr, char **endptr, int base) {
  const unsigned char *unptr = (const unsigned char *)nptr;
  char *endp;
  unsigned long ud;
  int neg;
  int c;

  while ((c = *unptr++) != 0 && (isspace)(c)) {

  }
  neg = 0;
  switch (c) {
  case '-':
    neg = 1;
  case '+':
    break;
  default:
    --unptr;
    break;
  }

  ud = __SEGGER_RTL_strtoul((char *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (char *)unptr ? (char *)nptr : endp;
  }
  if (neg) {
    if (ud == (unsigned long)LONG_MAX+1) {
      return LONG_MIN;
    } else if (ud <= LONG_MAX) {
      return -(long)ud;
    } else {
      errno = ERANGE;
      return LONG_MIN;
    }
  } else {
    if (ud <= LONG_MAX) {
      return (long)ud;
    } else {
      errno = ERANGE;
      return LONG_MAX;
    }
  }
}
# 1125 "./convops.c"
long long __SEGGER_RTL_PUBLIC_API strtoll(const char *nptr, char **endptr, int base) {
  const unsigned char *unptr = (const unsigned char *)nptr;
  char *endp;
  unsigned long long ud;

  int neg = 0, c;
  while ((c = *unptr++) != 0 && (isspace)(c))
    ;
  switch (c) {
  case '-':
    neg = 1;
  case '+':
    break;
  default:
    --unptr;
    break;
  }

  ud = __SEGGER_RTL_strtoull((char *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (char *)unptr ? (char *)nptr : endp;
  }
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
# 1236 "./convops.c"
unsigned long __SEGGER_RTL_PUBLIC_API strtoul(const char *nptr, char **endptr, int base) {
  const unsigned char *unptr = (const unsigned char *)nptr;
  unsigned long ud;
  char *endp;
  int neg = 0, c;
  int saved_errno = errno;

  while ((c = *unptr++) != 0 && (isspace)(c)) {

  }
  switch (c) {
  case '-':
    neg = 1;
  case '+':
    break;
  default:
    --unptr;
    break;
  }

  errno = 0;
  ud = __SEGGER_RTL_strtoul((char *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (char *)unptr ? (char *)nptr : endp;
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
# 1349 "./convops.c"
unsigned long long __SEGGER_RTL_PUBLIC_API strtoull(const char *nptr, char **endptr, int base) {
  const unsigned char *unptr = (const unsigned char *)nptr;
  unsigned long long ud;
  char *endp;
  int neg = 0, c;
  int errno_saved = errno;

  while ((c = *unptr++) != 0 && (isspace)(c)) {

  }

  switch (c) {
  case '-':
    neg = 1;
  case '+':
    break;
  default:
    --unptr;
    break;
  }

  errno = 0;
  ud = __SEGGER_RTL_strtoull((char *)unptr, &endp, base);
  if (endptr) {
    *endptr = endp == (char *)unptr ? (char *)nptr : endp;
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
# 1429 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API itoa(int val, char *buf, int radix) {
  if (radix == 10 && val < 0) {
    return __SEGGER_RTL_xtoa((unsigned)val, buf, radix, 1);
  } else {
    return __SEGGER_RTL_xtoa((unsigned)val, buf, radix, 0);
  }
}
# 1473 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API ltoa(long val, char *buf, int radix) {
  return __SEGGER_RTL_xltoa((unsigned long)val, buf, radix, (radix == 10 && val < 0));
}
# 1513 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API lltoa(long long val, char *buf, int radix) {
  return __SEGGER_RTL_xlltoa((unsigned long long)val, buf, radix, (radix == 10 && val < 0));
}
# 1549 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API utoa(unsigned val, char *buf, int radix) {
  return __SEGGER_RTL_xtoa(val, buf, radix, 0);
}
# 1585 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API ultoa(unsigned long val, char *buf, int radix) {
  return __SEGGER_RTL_xltoa(val, buf, radix, 0);
}
# 1621 "./convops.c"
char * __SEGGER_RTL_PUBLIC_API ulltoa(unsigned long long val, char *buf, int radix) {
  return __SEGGER_RTL_xlltoa(val, buf, radix, 0);
}
