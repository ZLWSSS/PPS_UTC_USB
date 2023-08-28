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
# 1 "./scanops.c"
# 17 "./scanops.c"
#include "__SEGGER_RTL_Int.h"
#include "ctype.h"
#include "errno.h"
#include "limits.h"
#include "math.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "wchar.h"
# 40 "./scanops.c"
#ifndef isSHORT
#define isSHORT(flag) (sizeof(short) != sizeof(int) && ((flag) & FLAG_SHORT))
#endif
#ifndef isLONG
#define isLONG(flag) (SUPPORT_LONG && sizeof(int) != sizeof(long) && ((flag) & FLAG_LONG))
#endif
#ifndef isLONGLONG
#define isLONGLONG(flag) (SUPPORT_LONG_LONG && sizeof(int64_t) != sizeof(long) && ((flag) & FLAG_LONG_LONG))
#endif
#ifndef isLONGDOUBLE
#define isLONGDOUBLE(flag) (__SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE && ((flag) & FLAG_LONGDOUBLE))
#endif

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

#ifndef XFLOAT
#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE
  typedef double xfloat_t;
  #define XFLOAT(X) X
#elif __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_FLOAT
  typedef float xfloat_t;
  #define XFLOAT(X) X##f
#endif
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

#define countgetc(p) (++charcount, __SEGGER_RTL_scan_getc(p))

#define CVTEOF (-1)
#define CVTFAIL (-2)

typedef struct {
  __SEGGER_RTL_scan_t base;
  FILE * stream;
} __SEGGER_RTL_scan_stream_t;







#if defined(WITH_SCANF)






void __SEGGER_RTL_init_scan(__SEGGER_RTL_scan_t *iod) {
  __SEGGER_RTL_init_scan_l(iod, __SEGGER_RTL_current_locale());
}






void __SEGGER_RTL_init_scan_l(__SEGGER_RTL_scan_t *iod, locale_t loc) {
  (memset)(iod, 0, sizeof(*iod));
  iod->locale = loc;
}






static int __SEGGER_RTL_stdin_getc_adapter(__SEGGER_RTL_scan_t *p) {
  char c;
  int r;

  __SEGGER_RTL_USE_PARA(p);

  r = __SEGGER_RTL_X_file_read(stdin, &c, 1);
  if (r >= 0) {
    return c;
  } else {
    return r;
  }
}






static int __SEGGER_RTL_stdin_ungetc_adapter(__SEGGER_RTL_scan_t *p, int c) {

  __SEGGER_RTL_USE_PARA(p);

  return __SEGGER_RTL_X_file_unget(stdin, c);
}
#endif

#if !defined(WITH_PUBLICS) && !defined(WITH_SCANF)





static int __SEGGER_RTL_scan_getc(__SEGGER_RTL_scan_t *p) {
  if (p->narrow) {
    if (*p->narrow) {
      return *p->narrow++;
    } else {
      return EOF;
    }
  } else {
    return p->getc_fn(p);
  }
}






static int __SEGGER_RTL_scan_ungetc(int c, __SEGGER_RTL_scan_t *p) {
  if (p->narrow) {
    if (c != EOF) {
      --p->narrow;
    }
  } else {
    p->ungetc_fn(p, c);
  }
  return c;
}






static charcount_t __SEGGER_RTL_scan_int(__SEGGER_RTL_scan_t *p, ARGTYPE *ap, int flag, int radix, int field) {
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
  if (field > 0 && ch == '0') {
    flag |= FLAG_NUMOK;
    --field;
    ch = countgetc(p);
    if (field > 0 && (ch == 'x' || ch == 'X') && (radix == 0 || radix == 16)) {
      flag &= ~FLAG_NUMOK;
      --field;
      ch = countgetc(p);
      radix = 16;
    } else if (radix == 0) {
      radix = 8;
    }
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
  __SEGGER_RTL_scan_ungetc(ch, p);
  if ((flag & FLAG_NUMOK) == 0) {
    return CVTFAIL;
  }
  if ((flag & FLAG_NOSTORE) == 0) {
    ARGTYPE_PtrArg p = va_arg(*ap, void *);
    if ((flag & (FLAG_ALLOWSIGN | FLAG_NUMNEG)) == (FLAG_ALLOWSIGN | FLAG_NUMNEG)) {
      n = -(value_t)n;
    }
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






static charcount_t __SEGGER_RTL_scan_string(__SEGGER_RTL_scan_t *p, ARGTYPE *ap, int flag, int field) {
  charcount_t charcount = -1;
  int ch;
  ARGTYPE_CharPtrArg s = ARGTYPE_PtrArg_NULL;



  while ((isspace)(ch = countgetc(p))) {

  }



  if (ch == EOF) {
    return CVTEOF;
  }



  if ((flag & FLAG_NOSTORE) == 0) {
    s = va_arg(*ap, void *);
  }



  while (field > 0 && ch != EOF && !(isspace)(ch)) {
    --field;
    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_writePtrArgChar(*ap, s, (char)ch);
      s++;
    }
    ch = countgetc(p);
  }



  __SEGGER_RTL_scan_ungetc(ch, p);



  if ((flag & FLAG_NOSTORE) == 0) {
    ARGTYPE_writePtrArgChar(*ap, s, 0);
  }
  return charcount;
}






#if __SEGGER_RTL_FORMAT_CHAR_CLASS
static charcount_t __SEGGER_RTL_scan_string_map(__SEGGER_RTL_scan_t *p, ARGTYPE *ap, int flag, int field, unsigned char *charmap) {
  charcount_t charcount = -1;
  int ch;
  char *s = NULL;



  if ((flag & FLAG_NOSTORE) == 0) {
    s = va_arg(*ap, void *);
  }
  ch = countgetc(p);
  if (ch == EOF) {
    return CVTEOF;
  }
  while (field > 0 &&
         (unsigned)ch < CHARLIMIT &&
         (charmap[(unsigned)ch/8] & (1 << ((unsigned)ch % 8)))) {
    --field;
    if ((flag & FLAG_NOSTORE) == 0) {
      ARGTYPE_writePtrArgChar(*ap, s, ch);
      ++s;
    }
    ch = countgetc(p);
  }
  __SEGGER_RTL_scan_ungetc(ch, p);
  if ((flag & FLAG_NOSTORE) == 0) {
    ARGTYPE_writePtrArgChar(*ap, s, 0);
  }
  return charcount;
}
#endif






static charcount_t __SEGGER_RTL_scan_real(__SEGGER_RTL_scan_t *p, ARGTYPE *ap, int flag, int field) {
#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_NONE

  __SEGGER_RTL_USE_PARA(p);
  __SEGGER_RTL_USE_PARA(ap);
  __SEGGER_RTL_USE_PARA(flag);
  __SEGGER_RTL_USE_PARA(field);

  return -1;

#else

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

  while (field > 0) {
    if (ch == '.' && (flag & FLAG_DOTSEEN) == 0) {
      flag |= FLAG_DOTSEEN;
      --field;
    } else if ((isdigit)(ch)) {
      flag |= FLAG_NUMOK;
      --field;
      l = l*10 + (ch - '0');
      if (flag & FLAG_DOTSEEN)
        x -= 1;
    } else {
      break;
    }
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



  __SEGGER_RTL_scan_ungetc(ch, p);



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
  if ((flag & FLAG_LONG) && (__SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE)) {
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

#endif
}






int __SEGGER_RTL_scan(__SEGGER_RTL_scan_t *p, const unsigned char *fmt, ARGTYPE argv) {
  int ch;
  int field, flag;
  int cnt = 0;
  charcount_t charcount = 0;
  charcount_t worked;
  ARGTYPE_CharPtrArg cp;

  for (;;) {
    int fch;
    switch (fch = *fmt++) {
    case 0:

      return cnt;

    default:
      if ((isspace_l)(fch, p->locale)) {
        while ((isspace_l)(fch = *fmt++, p->locale)) {

        }
        --fmt;
        while ((isspace_l)(ch = __SEGGER_RTL_scan_getc(p), p->locale)) {
          ++charcount;
        }
        __SEGGER_RTL_scan_ungetc(ch, p);
        continue;
      } else if ((ch = __SEGGER_RTL_scan_getc(p)) == fch) {
        ++charcount;
        continue;
      }



      __SEGGER_RTL_scan_ungetc(ch, p);
      if (ch == EOF && cnt == 0) {
        return EOF;
      }



      return cnt;

    case '%':
      field = 0, flag = 0;
      if (*fmt == '*') {
        ++fmt;
        flag |= FLAG_NOSTORE;
      }
      while ((isdigit)(fch = *fmt++)) {
        field = field*10 + (fch - '0');
        flag |= FLAG_FIELDGIVEN;
      }
      if ((flag & FLAG_FIELDGIVEN) == 0) {
        field = INT_MAX;
      }
      if (SUPPORT_LONG && fch == 'l') {
        fch = *fmt++;
        if (SUPPORT_LONG_LONG && fch == 'l') {
          flag |= FLAG_LONG_LONG;
          fch = *fmt++;
        } else {
          flag |= FLAG_LONG;
        }
      } else if (fch == 'L') {
        fch = *fmt++;
        flag |= FLAG_LONGDOUBLE;
      } else if (fch == 'h') {
        fch = *fmt++;
        if (fch == 'h') {
          flag |= FLAG_CHAR;
          fch = *fmt++;
        } else {
          flag |= FLAG_SHORT;
        }
      }

      switch (fch) {
      default:

        return cnt;

      case '%':
        ch = __SEGGER_RTL_scan_getc(p);
        if (ch == '%') {
          ++charcount;
          continue;
        }
        __SEGGER_RTL_scan_ungetc(ch, p);
        return (ch == EOF && cnt == 0) ? EOF : cnt;

      case 'c':
        if ((flag & FLAG_FIELDGIVEN) == 0) {
          field = 1;
        }
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
        worked = __SEGGER_RTL_scan_int(p, &argv, flag | FLAG_ALLOWSIGN, 10, field);
        break;

      case 'e':
      case 'E':
      case 'f':
      case 'g':
      case 'G':
        worked = __SEGGER_RTL_scan_real(p, &argv, flag, field);
        break;

      case 'i':
        worked = __SEGGER_RTL_scan_int(p, &argv, flag | FLAG_ALLOWSIGN, 0, field);
        break;

      case 'n':
        if ((flag & FLAG_NOSTORE) == 0) {
          ARGTYPE_PtrArg p = va_arg(argv, void *);
          if (flag & FLAG_CHAR) {
            ARGTYPE_writePtrArgChar(argv, p, (char)charcount);
          } else if (isSHORT(flag)) {
            ARGTYPE_writePtrArgShort(argv, p, (short)charcount);
          } else if (isLONG(flag)) {
            ARGTYPE_writePtrArgLong(argv, p, (long)charcount);
          } else if (isLONGLONG(flag)) {
            ARGTYPE_writePtrArgLongLong(argv, p, (int64_t)charcount);
          } else {
            ARGTYPE_writePtrArgInt(argv, p, (int)charcount);
          }
        }
        continue;

      case 'o':
        worked = __SEGGER_RTL_scan_int(p, &argv, flag | FLAG_ALLOWSIGN, 8, field);
        break;

      case 'p':
        worked = __SEGGER_RTL_scan_int(p, &argv, flag & ~(FLAG_LONG | FLAG_SHORT | FLAG_CHAR | FLAG_LONG_LONG), 16, field);
        break;

      case 's':
        worked = __SEGGER_RTL_scan_string(p, &argv, flag, field);
        break;

      case 'u':
        worked = __SEGGER_RTL_scan_int(p, &argv, flag | FLAG_ALLOWSIGN, 10, field);
        break;

      case 'x':
      case 'X':
        worked = __SEGGER_RTL_scan_int(p, &argv, flag | FLAG_ALLOWSIGN, 16, field);
        break;

#if __SEGGER_RTL_FORMAT_CHAR_CLASS
      case '[':
        {
          int negated = 0, i;
          unsigned char charmap[CHARLIMIT/8];

          if ((fch = *fmt++) == '^') {
            negated = 1;
            fch = *fmt++;
          }
          (memset)(charmap, 0, sizeof(charmap));
          do {
            if (fch == 0) {
              return cnt;
            }
            if ((unsigned)fch < CHARLIMIT) {
              charmap[fch/8] |= 1 << (fch % 8);
            }
          } while ((fch = *fmt++) != ']');

          if (negated) {
            for (i = 0; i < (int)(CHARLIMIT/8); ++i) {
              charmap[i] = ~charmap[i];
            }
          }
          worked = __SEGGER_RTL_scan_string_map(p, &argv, flag, field, charmap);
        }
        break;
#endif
      }

      if (worked < 0) {



        return worked == CVTEOF && cnt == 0 ? EOF : cnt;
      }

      if ((flag & FLAG_NOSTORE) == 0) {
        ++cnt;
      }
      charcount += worked;
      continue;
    }
  }
}
#endif
#ifdef WITH_PUBLICS
# 763 "./scanops.c"
int __SEGGER_RTL_stream_getc(__SEGGER_RTL_scan_t *ctx) {
  __SEGGER_RTL_scan_stream_t *pBuf;

  pBuf = (__SEGGER_RTL_scan_stream_t *)ctx;
  return fgetc(pBuf->stream);
}
# 785 "./scanops.c"
int __SEGGER_RTL_stream_ungetc(__SEGGER_RTL_scan_t *ctx, int ch) {
  __SEGGER_RTL_scan_stream_t *pBuf;

  pBuf = (__SEGGER_RTL_scan_stream_t *)ctx;
  return ungetc(ch, pBuf->stream);
}
# 829 "./scanops.c"
int sscanf(const char *s, const char *format, ...) {
  __SEGGER_RTL_scan_t iod;
  va_list a;
  int n;

  va_start(a, format);
  __SEGGER_RTL_init_scan(&iod);
  iod.narrow = s;
  n = __SEGGER_RTL_scan(&iod, (const unsigned char *)format, a);
  va_end(a);

  return n;
}
# 874 "./scanops.c"
int sscanf_l(const char *s, locale_t loc, const char *format, ...) {
  __SEGGER_RTL_scan_t iod;
  va_list a;
  int n;

  va_start(a, format);
  __SEGGER_RTL_init_scan_l(&iod, loc);
  iod.narrow = s;
  n = __SEGGER_RTL_scan(&iod, (const unsigned char *)format, a);
  va_end(a);

  return n;
}
# 921 "./scanops.c"
int vsscanf(const char *s, const char *format, va_list arg) {
  return vsscanf_l(s, __SEGGER_RTL_current_locale(), format, arg);
}
# 959 "./scanops.c"
int vsscanf_l(const char *s, locale_t loc, const char *format, va_list arg) {
  __SEGGER_RTL_scan_t iod;

  __SEGGER_RTL_init_scan_l(&iod, loc);
  iod.narrow = s;

  return __SEGGER_RTL_scan(&iod, (const unsigned char *)format, arg);
}
#endif
#ifdef WITH_SCANF
# 1001 "./scanops.c"
int vscanf(const char *format, va_list arg) {
  return vscanf_l(__SEGGER_RTL_current_locale(), format, arg);
}
# 1038 "./scanops.c"
int vscanf_l(locale_t loc, const char *format, va_list arg) {
  __SEGGER_RTL_scan_t iod;

  __SEGGER_RTL_init_scan_l(&iod, loc);
  iod.getc_fn = __SEGGER_RTL_stdin_getc_adapter;
  iod.ungetc_fn = __SEGGER_RTL_stdin_ungetc_adapter;

  return __SEGGER_RTL_scan(&iod, (const unsigned char *)format, arg);
}
# 1077 "./scanops.c"
int scanf(const char *format, ...) {
  __SEGGER_RTL_scan_t iod;
  va_list a;
  int n;

  va_start(a, format);
  __SEGGER_RTL_init_scan(&iod);
  iod.getc_fn = __SEGGER_RTL_stdin_getc_adapter;
  iod.ungetc_fn = __SEGGER_RTL_stdin_ungetc_adapter;
  n = __SEGGER_RTL_scan(&iod, (const unsigned char *)format, a);
  va_end(a);

  return n;
}
# 1122 "./scanops.c"
int scanf_l(locale_t loc, const char *format, ...) {
  __SEGGER_RTL_scan_t iod;
  va_list a;
  int n;

  va_start(a, format);
  __SEGGER_RTL_init_scan_l(&iod, loc);
  iod.getc_fn = __SEGGER_RTL_stdin_getc_adapter;
  iod.ungetc_fn = __SEGGER_RTL_stdin_ungetc_adapter;
  n = __SEGGER_RTL_scan(&iod, (const unsigned char *)format, a);
  va_end(a);

  return n;
}
# 1167 "./scanops.c"
int fscanf(FILE *stream, const char *format, ...) {
  va_list ap;
  int n;

  va_start(ap, format);
  n = vfscanf(stream, format, ap);
  va_end(ap);

  return n;
}
# 1209 "./scanops.c"
int fscanf_l(FILE *stream, locale_t loc, const char *format, ...) {
  va_list ap;
  int n;

  va_start(ap, format);
  n = vfscanf_l(stream, loc, format, ap);
  va_end(ap);

  return n;
}
# 1251 "./scanops.c"
int vfscanf(FILE *stream, const char *format, va_list arg) {
  return vfscanf_l(stream, __SEGGER_RTL_current_locale(), format, arg);
}
# 1287 "./scanops.c"
int vfscanf_l(FILE *stream, locale_t loc, const char *format, va_list arg) {
  __SEGGER_RTL_scan_stream_t iod;

  __SEGGER_RTL_init_scan_l(&iod.base, loc);
  iod.base.getc_fn = __SEGGER_RTL_stream_getc;
  iod.base.ungetc_fn = __SEGGER_RTL_stream_ungetc;
  iod.stream = stream;
  return __SEGGER_RTL_scan(&iod.base, (const unsigned char *)format, arg);
}
#endif
