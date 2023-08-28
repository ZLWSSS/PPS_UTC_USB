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
# 1 "./wscanops.c"
# 17 "./wscanops.c"
#include "__SEGGER_RTL_Int.h"
#include "stdio.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdint.h"
#include "ctype.h"
#include "wchar.h"
#include "errno.h"
#include "math.h"
#include "string.h"
# 38 "./wscanops.c"
#define isSHORT(flag) (sizeof(short) != sizeof(int) && ((flag) & FLAG_SHORT))
#define isLONG(flag) (SUPPORT_LONG && sizeof(int) != sizeof(long) && ((flag) & FLAG_LONG))
#define isLONGLONG(flag) (SUPPORT_LONG_LONG && sizeof(int64_t) != sizeof(long) && ((flag) & FLAG_LONG_LONG))
#define isLONGDOUBLE(flag) (__SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE && ((flag) & FLAG_LONGDOUBLE))

#if __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_LONG_LONG

#define SUPPORT_LONG_LONG 1
#define SUPPORT_LONG 1
#define SUPPORT_INT 1
#undef uvalue_t
#define uvalue_t uint64_t
#undef value_t
#define value_t int64_t

#elif __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_LONG

#define SUPPORT_LONG_LONG 0
#define SUPPORT_LONG 1
#define SUPPORT_INT 1
#undef uvalue_t
#define uvalue_t unsigned long
#undef value_t
#define value_t long

#elif __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_INT

#define SUPPORT_LONG_LONG 0
#define SUPPORT_LONG 0
#define SUPPORT_INT 1
#undef uvalue_t
#define uvalue_t unsigned int
#undef value_t
#define value_t int

#else

#error "Need to define __SEGGER_RTL_FORMAT_INT_WIDTH properly"

#endif

#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE
  typedef double xfloat_t;
  #define XFLOAT(X) X
#elif __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_FLOAT
  typedef float xfloat_t;
  #define XFLOAT(X) X##f
#endif


#define CHARLIMIT 256

#define FLAG_NOSTORE (1<<0)
#define FLAG_LONG_LONG (1<<1)
#define FLAG_LONG (1<<2)
#define FLAG_SHORT (1<<3)
#define FLAG_CHAR (1<<4)
#define FLAG_FIELDGIVEN (1<<5)
#define FLAG_LONGDOUBLE (1<<6)
#define FLAG_ALLOWSIGN (1<<7)
#define FLAG_DOTSEEN (1<<8)
#define FLAG_NUMOK (1<<9)
#define FLAG_NUMNEG (1<<10)
#define FLAG_EXPNEG (1<<11)

#define countgetc(p) (++charcount, __SEGGER_RTL_wscan_getc(p))

#define CVTEOF (-1)
#define CVTFAIL (-2)
# 120 "./wscanops.c"
static int __SEGGER_RTL_wscan_getc(__SEGGER_RTL_wscan_t *p) {
  if (p->wide) {
    if (*p->wide) {
      return *p->wide++;
    } else {
      return EOF;
    }
  } else {
    return p->getc_fn(p);
  }
}






static int __SEGGER_RTL_wscan_ungetc(int c, __SEGGER_RTL_wscan_t *p) {
  if (p->wide) {
    if (c != EOF) {
      --p->wide;
    }
  } else {
    p->ungetc_fn(p, c);
  }
  return c;
}






static charcount_t __SEGGER_RTL_wscan_int(__SEGGER_RTL_wscan_t *p, ARGTYPE *ap, int flag, int radix, int field) {
  charcount_t charcount = -1;
  uvalue_t n = 0;
  int ch, digit;


  while ((isspace)(ch = countgetc(p))) {

  }

  if (ch == EOF) {
    return CVTEOF;
  }

  flag &= ~(FLAG_NUMOK | FLAG_NUMNEG);
  if (field > 0 && (flag & FLAG_ALLOWSIGN)) {
    switch (ch) {
    case '-':
      flag |= FLAG_NUMNEG;

    case '+':
      ch = countgetc(p);
      --field;
    }
  }

  if (field > 0 && ch == '0')
    {
      flag |= FLAG_NUMOK;
      --field;
      ch = countgetc(p);
      if (field > 0 && (ch == 'x' || ch == 'X') && (radix == 0 || radix == 16))
        {
          flag &= ~FLAG_NUMOK;
          --field;
          ch = countgetc(p);
          radix = 16;
        }
      else if (radix == 0)
        radix = 8;
    }
  if (radix == 0) {
    radix = 10;
  }
  while (field > 0 && (digit = __SEGGER_RTL_digit(ch, radix)) >= 0) {
    flag |= FLAG_NUMOK;
    --field;
    n = n * radix + digit;
    ch = countgetc(p);
  }
  __SEGGER_RTL_wscan_ungetc(ch, p);
  if ((flag & FLAG_NUMOK) == 0) {
    return CVTFAIL;
  }
  if ((flag & FLAG_NOSTORE) == 0) {
    ARGTYPE_PtrArg p = va_arg(*ap, void *);
    if ((flag & (FLAG_ALLOWSIGN | FLAG_NUMNEG)) == (FLAG_ALLOWSIGN | FLAG_NUMNEG))
      n = -(value_t)n;
    if (flag & FLAG_CHAR) {
      ARGTYPE_writePtrArgUnsignedChar(*ap, p, (unsigned char)n);
    } else if (isSHORT(flag)) {
      ARGTYPE_writePtrArgUnsignedShort(*ap, p, (unsigned short)n);
    } else if (isLONG(flag)) {
      ARGTYPE_writePtrArgUnsignedLong(*ap, p, (unsigned long)n);
    } else if (isLONGLONG(flag)) {
      ARGTYPE_writePtrArgUnsignedLongLong(*ap, p, (uint64_t)n);
    } else {
      ARGTYPE_writePtrArgUnsignedInt(*ap, p, (unsigned int)n);
    }
  }
  return charcount;
}






static charcount_t __SEGGER_RTL_wscan_string(__SEGGER_RTL_wscan_t *p, ARGTYPE *ap, int flag, int field) {
  charcount_t charcount = -1;
  int ch;
  ARGTYPE_CharPtrArg s = ARGTYPE_PtrArg_NULL;


  while ((isspace)(ch = countgetc(p)))
    ;


  if (ch == EOF)
    return CVTEOF;


  if ((flag & FLAG_NOSTORE) == 0)
    s = va_arg(*ap, void *);


  while (field > 0 && ch != EOF && !(isspace)(ch))
    {
      --field;
      if ((flag & FLAG_NOSTORE) == 0)
        {
          ARGTYPE_writePtrArgChar(*ap, s, (char)ch);
          s++;
        }
      ch = countgetc(p);
    }


  __SEGGER_RTL_wscan_ungetc(ch, p);


  if ((flag & FLAG_NOSTORE) == 0)
    ARGTYPE_writePtrArgChar(*ap, s, 0);
  return charcount;
}






#if __SEGGER_RTL_FORMAT_CHAR_CLASS
static charcount_t __SEGGER_RTL_wscan_string_map(__SEGGER_RTL_wscan_t *p, ARGTYPE *ap, int flag, int field, unsigned char *charmap) {
  charcount_t charcount = -1;
  int ch;
  char *s = NULL;


  if ((flag & FLAG_NOSTORE) == 0) {
    s = va_arg(*ap, void *);
  }
  ch = countgetc(p);
  if (ch == EOF)
    return CVTEOF;
  while (field > 0 &&
         (unsigned)ch < CHARLIMIT &&
         (charmap[(unsigned)ch/8] & (1 << ((unsigned)ch % 8)))) {
    --field;
    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_writePtrArgChar(*ap, s, ch);
      s++;
    }
    ch = countgetc(p);
  }
  __SEGGER_RTL_wscan_ungetc(ch, p);
  if ((flag & FLAG_NOSTORE) == 0) {
    ARGTYPE_writePtrArgChar(*ap, s, 0);
  }

  return charcount;
}
#endif






#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH > __WIDTH_NONE
static charcount_t __SEGGER_RTL_wscan_real(__SEGGER_RTL_wscan_t *p, ARGTYPE *ap, int flag, int field) {
  charcount_t charcount = -1;
  int ch, x = 0;
  xfloat_t l = 0;



  while ((isspace)(ch = countgetc(p))) {

  }
  if (ch == EOF) {
    return CVTEOF;
  }
  flag &= ~(FLAG_NUMOK | FLAG_DOTSEEN | FLAG_NUMNEG);
  if (field > 0) {
    switch (ch) {
    case '-':
      flag |= FLAG_NUMNEG;

    case '+':
      ch = countgetc(p);
      --field;
    }
  }

  while (field > 0)
    {
      if (ch == '.' && (flag & FLAG_DOTSEEN) == 0)
        {
          flag |= FLAG_DOTSEEN;
          --field;
        }
      else if ((isdigit)(ch))
        {
          flag |= FLAG_NUMOK;
          --field;
          l = l*10 + (ch - '0');
          if (flag & FLAG_DOTSEEN)
            x -= 1;
        }
      else
        break;
      ch = countgetc(p);
    }


  if (field > 0 && (ch == 'e' || ch == 'E') && (flag & FLAG_NUMOK)) {
    int x2 = 0;
    flag &= ~(FLAG_NUMOK | FLAG_EXPNEG);
    --field;
    switch (ch = countgetc(p)) {
    case '-':
      flag |= FLAG_EXPNEG;

    case '+':
      ch = countgetc(p);
      --field;
    }
    while (field > 0 && (isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      --field;
      x2 = (x2 > 1000) ? 10000 : 10*x2 + (ch - '0');
      ch = countgetc(p);
    }
    if (flag & FLAG_EXPNEG) {
      x -= x2;
    } else {
      x += x2;
    }
  }



  __SEGGER_RTL_wscan_ungetc(ch, p);



  if (x) {
    l *= XFLOAT(__SEGGER_RTL_pow10)(x);
  }

  if (isinf(l)) {
    errno = ERANGE;
  }
  if (flag & FLAG_NUMNEG) {
    l = -l;
  }

  if ((flag & FLAG_NUMOK) == 0) {
    return CVTFAIL;
  }
  if ((flag & FLAG_LONG) && (__SEGGER_RTL_FORMAT_FLOAT_WIDTH >= __WIDTH_DOUBLE)) {
    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_PtrArg p = va_arg(*ap, void *);
      ARGTYPE_writePtrArgDouble(*ap, p, l);
    }
  } else if (isLONGDOUBLE(flag)) {
    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_PtrArg p = va_arg(*ap, void *);
      ARGTYPE_writePtrArgLongDouble(*ap, p, l);
    }
  } else {



    float f = (float)l;
    if (isinf(f)) {
      errno = ERANGE;
    }



    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_PtrArg p = va_arg(*ap, void *);
      ARGTYPE_writePtrArgFloat(*ap, p, f);
    }
  }
  return charcount;
}
#endif






static int __SEGGER_RTL_wvfscanf(__SEGGER_RTL_wscan_t *p, const wchar_t *fmt, ARGTYPE argv) {
  int ch;
  int field, flag;
  int cnt = 0;
  charcount_t charcount = 0;
  charcount_t worked;
  ARGTYPE_CharPtrArg cp;

  for (;;)
    {
      int fch;
      switch (fch = *fmt++)
        {
        case 0:

          return cnt;

        default:
          if ((isspace)(fch))
            {
              while ((isspace)(fch = *fmt++))
                ;
              --fmt;
              while ((isspace)(ch = __SEGGER_RTL_wscan_getc(p)))
                ++charcount;
              __SEGGER_RTL_wscan_ungetc(ch, p);
              continue;
            }
          else if ((ch = __SEGGER_RTL_wscan_getc(p)) == fch)
            {
              ++charcount;
              continue;
            }


          __SEGGER_RTL_wscan_ungetc(ch, p);
          if (ch == EOF && cnt == 0)
            return EOF;


          return cnt;

        case '%':
          field = 0, flag = 0;
          if (*fmt == '*')
            {
              ++fmt;
              flag |= FLAG_NOSTORE;
            }
          while ((isdigit)(fch = *fmt++))
            {
              field = field*10 + (fch - '0');
              flag |= FLAG_FIELDGIVEN;
            }
          if ((flag & FLAG_FIELDGIVEN) == 0)
            field = INT_MAX;
          if (SUPPORT_LONG && fch == 'l')
            {
              fch = *fmt++;
              if (SUPPORT_LONG_LONG && fch == 'l')
                {
                  flag |= FLAG_LONG_LONG;
                  fch = *fmt++;
                }
              else
                flag |= FLAG_LONG;
            }
          else if (fch == 'L')
            {
              fch = *fmt++;
              flag |= FLAG_LONGDOUBLE;
            }
          else if (fch == 'h')
            {
              fch = *fmt++;
              if (fch == 'h')
                {
                  flag |= FLAG_CHAR;
                  fch = *fmt++;
                }
              else
                flag |= FLAG_SHORT;
            }

          switch (fch)
            {
            default:

              return cnt;

            case '%':
              ch = __SEGGER_RTL_wscan_getc(p);
              if (ch == '%')
                {
                  ++charcount;
                  continue;
                }
              __SEGGER_RTL_wscan_ungetc(ch, p);
              return (ch == EOF && cnt == 0) ? EOF : cnt;

            case 'c':
              if ((flag & FLAG_FIELDGIVEN) == 0)
                field = 1;
              cp = ARGTYPE_PtrArg_NULL;
              if ((flag & FLAG_NOSTORE) == 0) {
                cp = va_arg(argv, void *);
              }

              if (field == 0) {
                return cnt;
              }
              for (; field > 0; --field) {
                if ((ch = countgetc(p)) == EOF) {
                  return cnt == 0 ? EOF : cnt;
                }
                if ((flag & FLAG_NOSTORE) == 0) {
                  ARGTYPE_writePtrArgChar(argv, cp, (char)ch);
                  cp++;
                }
              }
              if ((flag & FLAG_NOSTORE) == 0) {
                ++cnt;
              }
              continue;

            case 'd':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag | FLAG_ALLOWSIGN, 10, field);
              break;

#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH > __WIDTH_NONE
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
              worked = __SEGGER_RTL_wscan_real(p, &argv, flag, field);
              break;
#endif

            case 'i':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag | FLAG_ALLOWSIGN, 0, field);
              break;

            case 'n':
              if ((flag & FLAG_NOSTORE) == 0)
                {
                  ARGTYPE_PtrArg p = va_arg(argv, void *);
                  if (flag & FLAG_CHAR)
                    ARGTYPE_writePtrArgChar(argv, p, (char)charcount);
                  else if (isSHORT(flag))
                    ARGTYPE_writePtrArgShort(argv, p, (short)charcount);
                  else if (isLONG(flag))
                    ARGTYPE_writePtrArgLong(argv, p, (long)charcount);
                  else if (isLONGLONG(flag))
                    ARGTYPE_writePtrArgLongLong(argv, p, (int64_t)charcount);
                  else
                    ARGTYPE_writePtrArgInt(argv, p, (int)charcount);
                }
              continue;

            case 'o':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag | FLAG_ALLOWSIGN, 8, field);
              break;

            case 'p':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag & ~(FLAG_LONG | FLAG_SHORT | FLAG_CHAR | FLAG_LONG_LONG), 16, field);
              break;

            case 's':
              worked = __SEGGER_RTL_wscan_string(p, &argv, flag, field);
              break;

            case 'u':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag | FLAG_ALLOWSIGN, 10, field);
              break;

            case 'x':
            case 'X':
              worked = __SEGGER_RTL_wscan_int(p, &argv, flag | FLAG_ALLOWSIGN, 16, field);
              break;

#if __SEGGER_RTL_FORMAT_CHAR_CLASS
            case '[':
              {
                int negated = 0, i;
                unsigned char charmap[CHARLIMIT/8];
                if ((fch = *fmt++) == '^')
                  {
                    negated = 1;
                    fch = *fmt++;
                  }
                (memset)(charmap, 0, sizeof(charmap));
                do
                  {
                    if (fch == 0)
                      return cnt;
                    if ((unsigned)fch < CHARLIMIT)
                      charmap[fch/8] |= 1 << (fch % 8);
                  }
                while ((fch = *fmt++) != ']');

                if (negated)
                  for (i = 0; i < (int)(CHARLIMIT/8); ++i)
                    charmap[i] = ~charmap[i];
                worked = __SEGGER_RTL_wscan_string_map(p, &argv, flag, field, charmap);
              }
              break;
#endif
            }

          if (worked < 0)
            {

              return worked == CVTEOF && cnt == 0 ? EOF : cnt;
            }

          if ((flag & FLAG_NOSTORE) == 0)
            ++cnt;
          charcount += worked;
          continue;
        }
    }
}
# 696 "./wscanops.c"
int __SEGGER_RTL_PUBLIC_API swscanf(const wchar_t *s, const wchar_t *format, ...) {
  __SEGGER_RTL_wscan_t iod;
  va_list a;
  int n;

  va_start(a, format);
  iod.wide = s;
  n = __SEGGER_RTL_wvfscanf(&iod, format, a);
  va_end(a);
  return n;
}
# 738 "./wscanops.c"
int __SEGGER_RTL_PUBLIC_API vswscanf(const wchar_t *s, const wchar_t *format, va_list arg) {
  __SEGGER_RTL_wscan_t iod;
  iod.wide = s;
  return __SEGGER_RTL_wvfscanf(&iod, format, arg);
}
