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
# 1 "./wprinops.c"
# 17 "./wprinops.c"
#include "__SEGGER_RTL_Int.h"
#include "limits.h"
#include "math.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "wchar.h"
#include "wctype.h"
# 37 "./wprinops.c"
#define MAX_FLOAT_DIGITS 16

#define isSHORT(flag) (sizeof(short) < sizeof(int) && ((flag) & FORMAT_SHORT))
#define isLONG(flag) (SUPPORT_LONG && sizeof(long) > sizeof(int) && ((flag) & FORMAT_LONG))
#define isLONGLONG(flag) (SUPPORT_LONG_LONG && sizeof(uint64_t) >= sizeof(int) && ((flag) & FORMAT_LONG_LONG))
#define isLONGDOUBLE(flag) (sizeof(double) != sizeof(long double) && ((flag) & FORMAT_LONG_LONG))

#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE
  typedef double xfloat_t;
  #define XFLOAT(X) X
#elif __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_FLOAT
  typedef float xfloat_t;
  #define XFLOAT(X) X##f
#endif

#if __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_LONG_LONG


  #define SUPPORT_LONG_LONG 1
  #define SUPPORT_LONG 1
  #define uvalue_t uint64_t
  #define value_t int64_t

#elif __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_LONG


  #define SUPPORT_LONG 1
  #define SUPPORT_LONG_LONG 0
  #define uvalue_t unsigned long
  #define value_t long

#elif __SEGGER_RTL_FORMAT_INT_WIDTH == __WIDTH_INT


  #define SUPPORT_LONG 0
  #define SUPPORT_LONG_LONG 0
  #define uvalue_t unsigned int
  #define value_t int

#else

#error "Need to define __SEGGER_RTL_FORMAT_INT_WIDTH correctly"

#endif
# 94 "./wprinops.c"
static void __SEGGER_RTL_print_wide_string_wchar(__SEGGER_RTL_prin_t *p, const wchar_t *wstr, unsigned max_bytes, locale_t loc) {
  mbstate_t state;
  char buf[MB_LEN_MAX];
  unsigned nbytes;
  int n;
  int i;



  __SEGGER_RTL_init_mbstate(&state);
  nbytes = 0;
  while (*wstr) {

    n = wctomb_l(buf, *wstr++, loc);
    if (nbytes + n > max_bytes) {
      break;
    }
    for (i = 0; i < n; ++i) {
      __SEGGER_RTL_putc(p, buf[i]);
    }
    nbytes += n;
  }
}






static int __SEGGER_RTL_prin_wchar(__SEGGER_RTL_prin_t *ctx, const wchar_t *fmt, ARGTYPE args) {
  wchar_t ch;
  int exp;
  char buff[(8*sizeof(value_t)+2)/3];

#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH > __WIDTH_NONE
  uint64_t u;
#endif
#if __SEGGER_RTL_FORMAT_WCHAR
  wchar_t wc[2];
#endif

  union {
      uvalue_t u;
      value_t i;
      const char *str;
      const wchar_t *wstr;
#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH != __WIDTH_NONE
    xfloat_t r;
#endif
    } v;



  ctx->charcount = 0;

  while ((ch = *fmt++) != 0) {
    if (ch != '%') {
      __SEGGER_RTL_putc(ctx, ch);
    } else {
      int len = 0;
      int flags = 0;
      unsigned prefix = 0;
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      int width = 0;
      int precision = 0;
#endif



      for (;;) {
        switch (ch = *fmt++) {
        case ' ': flags |= FORMAT_SPACE; continue;
        case '#': flags |= FORMAT_ALTERNATIVE; continue;
        case '\'': flags |= FORMAT_TICK; continue;
        case '^': flags |= FORMAT_ENGINEERING; continue;
        case '+': flags |= FORMAT_SIGNED; continue;
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
        case '-': flags |= FORMAT_LEFT_JUSTIFY; continue;
        case '0': flags |= FORMAT_ZERO_FILL; continue;
#endif
        }
        break;
      }



#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      if (ch == '*') {
        width = va_arg(args, int);
        if (width < 0) {
          width = -width;
          flags |= FORMAT_LEFT_JUSTIFY;
        }
        ch = *fmt++;
      } else {
        while ('0' <= ch && ch <= '9') {
          width = width*10 + (ch-'0');
          ch = *fmt++;
        }
      }
      if (width < 0) {
        width = 0;
      }



      if (ch == '.') {
        ch = *fmt++;
        if (ch == '*') {
          precision = va_arg(args, int);
          ch = *fmt++;
        } else {
          while ('0' <= ch && ch <= '9') {
            precision = precision*10 + (ch-'0');
            ch = *fmt++;
          }
        }
        if (precision >= 0) {
          flags |= FORMAT_HAVE_PRECISION;
        }
      }
#endif
      if (ch == 't' || ch == 'z') {





        ch = *fmt++;
      } else if (SUPPORT_LONG_LONG && ch == 'j') {




        flags |= FORMAT_LONG_LONG;
        ch = *fmt++;
      } else if ((SUPPORT_LONG || __SEGGER_RTL_FORMAT_WCHAR) && ch == 'l') {




        ch = *fmt++;
        if (SUPPORT_LONG_LONG && ch == 'l') {
          flags |= FORMAT_LONG_LONG;
          ch = *fmt++;
        } else {
          flags |= FORMAT_LONG;
        }
      } else if (__SEGGER_RTL_FORMAT_FLOAT_WIDTH > __WIDTH_FLOAT && ch == 'L') {



        flags |= FORMAT_LONG_LONG;
        ch = *fmt++;
      } else if (ch == 'h') {



        if ((ch = *fmt++) == 'h') {
          flags |= FORMAT_CHAR;
          ch = *fmt++;
        } else {
          flags |= FORMAT_SHORT;
        }
      }

      switch (ch) {
        default:
          continue;

        case 0:




          __SEGGER_RTL_prin_flush(ctx);
          return -1;

        case '%':
          __SEGGER_RTL_putc(ctx, ch);
          continue;

        case 'c':
#if __SEGGER_RTL_FORMAT_WCHAR
          if (flags & FORMAT_LONG) {



            wc[0] = va_arg(args, long);
            wc[1] = 0;
            flags &= ~FORMAT_HAVE_PRECISION;
            v.wstr = wc;
            goto sformat;
          } else {
            ch = va_arg(args, int);
          }
#else
          ch = va_arg(args, int);
#endif


#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
          --width;
          __SEGGER_RTL_pre_padding(ctx, flags, width);
#endif
          __SEGGER_RTL_putc(ctx, ch);
postpad:
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
          if (flags & FORMAT_LEFT_JUSTIFY) {
            __SEGGER_RTL_print_padding(ctx, ' ', width);
          }
#endif
          continue;

        case 'n':
          if (flags & FORMAT_CHAR) {
            ARGTYPE_setCharPtrArg(args, ctx->charcount);
          } else if (SUPPORT_LONG_LONG && isLONGLONG(flags)) {
            ARGTYPE_setLongLongPtrArg(args, ctx->charcount);
          } else if (SUPPORT_LONG && isLONG(flags)) {
            ARGTYPE_setLongPtrArg(args, ctx->charcount);
          } else {
            ARGTYPE_setIntPtrArg(args, ctx->charcount);
          }
          continue;

        case 's':



          v.str = va_arg(args, char *);

#if __SEGGER_RTL_FORMAT_WCHAR
sformat:
          if (v.str && (flags & FORMAT_LONG)) {
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION



            if (width == 0 && (flags & FORMAT_HAVE_PRECISION) == 0) {



              __SEGGER_RTL_compute_wide_metrics(v.wstr, INT_MAX, &len, ctx->locale);
            } else if (flags & FORMAT_HAVE_PRECISION) {



              __SEGGER_RTL_compute_wide_metrics(v.wstr, precision, &len, ctx->locale);
            } else {



              __SEGGER_RTL_compute_wide_metrics(v.wstr, width, &len, ctx->locale);
            }



            width -= len;
            __SEGGER_RTL_pre_padding(ctx, flags, width);
            __SEGGER_RTL_print_wide_string_wchar(ctx, v.wstr, len, ctx->locale);
#else
            __SEGGER_RTL_print_wide_string_wchar(ctx, v.wstr, INT_MAX);
#endif
            goto postpad;
          }
#endif


fmtstr:
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION

          if (v.str == 0) {
            v.str = "(null)";
          }



          flags &= ~FORMAT_ZERO_FILL;



          if (flags & FORMAT_HAVE_PRECISION) {




            len = strnlen(v.str, precision);
          } else {



            len = (strlen)(v.str);
          }

          width -= len;
          __SEGGER_RTL_pre_padding(ctx, flags, width);
          while (len--) {
            __SEGGER_RTL_putc(ctx, *v.str++);
          }
          goto postpad;
#else
          while (*v.str) {
            __SEGGER_RTL_putc(ctx, *v.str++);
          }
          continue;
#endif

        case 'p':
          v.u = (uvalue_t)(uintptr_t)va_arg(args, void *);
          if (flags & FORMAT_ALTERNATIVE) {
            prefix = '#';
          }
          flags |= FORMAT_HAVE_PRECISION;
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
          precision = sizeof(void *) * 2;
#endif
          break;

        case 'X':
          flags |= FORMAT_CAPITALS;

        case 'x':
          if (flags & FORMAT_ALTERNATIVE) {
            prefix = ch == 'x' ? ('0'*0x100+'x') : ('0'*0x100+'X');
          }
          if (__SEGGER_RTL_FORMAT_WIDTH_PRECISION && (flags & FORMAT_HAVE_PRECISION)) {
            flags &= ~FORMAT_ZERO_FILL;
          }
          goto fmtint;

        case 'o':
          if (flags & FORMAT_ALTERNATIVE) {
            prefix = '0';
          }
          if (__SEGGER_RTL_FORMAT_WIDTH_PRECISION && (flags & FORMAT_HAVE_PRECISION)) {
            flags &= ~FORMAT_ZERO_FILL;
          }
          goto fmtint;

        case 'u':
          if (__SEGGER_RTL_FORMAT_WIDTH_PRECISION && (flags & FORMAT_HAVE_PRECISION)) {
            flags &= ~FORMAT_ZERO_FILL;
          }
          goto fmtint;

        case 'i':
        case 'd':
          flags |= FORMAT_INPUT_SIGNED;
fmtint:

          if (flags & FORMAT_INPUT_SIGNED) {
            if (SUPPORT_LONG_LONG && isLONGLONG(flags)) {
              v.i = va_arg(args, long long);
            } else if (SUPPORT_LONG && isLONG(flags)) {
              v.i = va_arg(args, long);
            } else {
              v.i = va_arg(args, int);
            }

            if (isSHORT(flags)) {
              v.i = (short)v.i;
            } else if (flags & FORMAT_CHAR) {
              v.i = (char)v.i;
            }

            if (v.i < 0) {
              v.u = 0u - v.u;
              prefix = '-';
            } else {
              if (flags & FORMAT_SIGNED) {
                prefix = '+';
              } else if (flags & FORMAT_SPACE) {
                prefix = ' ';
              }
            }
          } else {
            if (SUPPORT_LONG_LONG && isLONGLONG(flags)) {
              v.u = va_arg(args, unsigned long long);
            } else if (SUPPORT_LONG && isLONG(flags)) {
              v.u = va_arg(args, unsigned long);
            } else {
              v.u = va_arg(args, unsigned);
            }
            if (isSHORT(flags)) {
              v.u = (unsigned short)v.u;
            } else if (flags & FORMAT_CHAR) {
              v.u = (unsigned char)v.u;
            }
          }

          if (__SEGGER_RTL_FORMAT_WIDTH_PRECISION && (flags & FORMAT_HAVE_PRECISION)) {
            flags &= ~FORMAT_ZERO_FILL;
          }
          break;

#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH > __WIDTH_NONE
        case 'E':
          flags |= FORMAT_CAPITALS;

        case 'e':
          flags |= FORMAT_FLOAT_E;
          goto fmtreal;

        case 'F':
          flags |= FORMAT_CAPITALS;

        case 'f':
          flags |= FORMAT_FLOAT_F;
          goto fmtreal;

        case 'G':
          flags |= FORMAT_CAPITALS;

        case 'g':
          flags |= FORMAT_FLOAT_G;
fmtreal:




          if (isLONGDOUBLE(flags)) {
            v.r = va_arg(args, long double);
          } else {
            v.r = va_arg(args, double);
          }



          if ((flags & FORMAT_HAVE_PRECISION) == 0) {
            precision = 6;
          }



          if (precision == 0 && (flags & FORMAT_FLOAT_G) == FORMAT_FLOAT_G) {
            precision = 1;
          }

          if (isinf(v.r)) {
            if (v.r < 0) {
              v.str = flags & FORMAT_CAPITALS ? "-INF" : "-inf";
            } else {
              v.str = flags & FORMAT_CAPITALS ? "+INF" : "+inf";
              if ((flags & FORMAT_SIGNED) == 0) {
                ++v.str;
              }
            }
            flags &= ~FORMAT_HAVE_PRECISION;
            goto fmtstr;

          } else if (isnan(v.r)) {
            v.str = flags & FORMAT_CAPITALS ? "NAN" : "nan";
            flags &= ~FORMAT_HAVE_PRECISION;
            goto fmtstr;
          }

          if (signbit(v.r)) {
            flags |= FORMAT_NEGATIVE;
            v.r = -v.r;
          }



          XFLOAT(frexp)(v.r, &exp);






          exp = exp * 3 / 10;



          if (v.r) {
            while (v.r > XFLOAT(__SEGGER_RTL_pow10)(exp+1)) {
              ++exp;
            }
            while (v.r < XFLOAT(__SEGGER_RTL_pow10)(exp)) {
              --exp;
            }
          }




          if ((flags & FORMAT_FLOAT_G) == FORMAT_FLOAT_E ||
              ((flags & FORMAT_FLOAT_G) == FORMAT_FLOAT_G && !(precision > exp && exp >= -4)))
            {



#if __SEGGER_RTL_FORMAT_FLOAT_WIDTH == __WIDTH_DOUBLE
              if (exp == 308) {
                v.r /= 1.e308;
              } else {
                v.r *= XFLOAT(__SEGGER_RTL_pow10)(-exp);
              }
#else
              if (exp == 38) {
                v.r /= 1.e38f;
              } else {
                v.r *= XFLOAT(__SEGGER_RTL_pow10)(-exp);
              }
#endif
              if (v.r) {
                if (isinf(v.r)) {
                  if (v.r < 0) {
                    v.str = flags & FORMAT_CAPITALS ? "-INF" : "-inf";
                  } else {
                    v.str = flags & FORMAT_CAPITALS ? "+INF" : "+inf";
                    if ((flags & FORMAT_SIGNED) == 0)
                      ++v.str;
                  }
                  flags &= ~FORMAT_HAVE_PRECISION;
                  goto fmtstr;
                }
                while (v.r >= 10.0) {
                  v.r /= 10.0;
                  ++exp;
                }
                while (v.r < 1.0) {
                  v.r *= 10.0;
                  --exp;
                }
              }



              if (precision && (flags & FORMAT_FLOAT_G) == FORMAT_FLOAT_G) {
                --precision;
              }



              v.r += XFLOAT(ldexp)(XFLOAT(__SEGGER_RTL_pow10)(-precision), -1);
              if (v.r >= 10.0) {
                ++exp;
                v.r /= 10.0;
              }



              if (precision && (flags & FORMAT_FLOAT_F) && (flags & FORMAT_ALTERNATIVE) == 0) {
                if (precision > MAX_FLOAT_DIGITS) {
                  precision = MAX_FLOAT_DIGITS;
                }
                u = (uint64_t)(v.r * XFLOAT(__SEGGER_RTL_pow10)(precision));
                if (u) {
                  while (precision && (u % 10 == 0)) {
                    --precision;
                    u /= 10;
                  }
                } else {
                  precision = 0;
                }
              }
              flags &= ~FORMAT_FLOAT_F;



              width -= (5 + precision);



              if (precision || (flags & FORMAT_ALTERNATIVE)) {
                --width;
              }



              if (flags & FORMAT_ENGINEERING) {
                switch (exp % 3) {
                case 0: len = 1; break;
                case -2: case 1: len = 2; v.r *= 10; exp -= 1; width -= 1; break;
                case -1: case 2: len = 3; v.r *= 100; exp -= 2; width -= 2; break;
                }
                if (precision < 0) {
                  precision = 0;
                }
              } else {
                len = 1;
              }



              if (flags & FORMAT_NEGATIVE) {
                --width;
              }



              if (abs(exp) >= 100) {
                --width;
              }
              u = (uint64_t)v.r;
              v.r -= (xfloat_t)u;
            }
          else {



            if (flags & FORMAT_FLOAT_E) {



              precision -= exp+1;
              if (precision > MAX_FLOAT_DIGITS) {
                precision = MAX_FLOAT_DIGITS;
              }

              if (exp >= 15) {



                precision = 0;
              } else if ((flags & FORMAT_ALTERNATIVE) == 0) {



                while (precision) {
                  xfloat_t d;

                  d = XFLOAT(floor)(v.r * XFLOAT(__SEGGER_RTL_pow10)(precision) + 0.5f);
                  if (XFLOAT(fmod)(d, 10) == 0) {
                    --precision;
                  } else {
                    break;
                  }
                }
              }
            }



            flags &= ~FORMAT_FLOAT_E;



            if (exp-MAX_FLOAT_DIGITS >= -precision) {
              v.r += XFLOAT(ldexp)(XFLOAT(__SEGGER_RTL_pow10)(exp-MAX_FLOAT_DIGITS), -1);
            } else {
              v.r += XFLOAT(ldexp)(XFLOAT(__SEGGER_RTL_pow10)(-precision), -1);
            }
            if (v.r > XFLOAT(__SEGGER_RTL_pow10)(exp+1)) {
              ++exp;
            }



            if (exp >= 0) {
              if (exp > MAX_FLOAT_DIGITS) {
                exp -= MAX_FLOAT_DIGITS;
                u = (uint64_t)(v.r * XFLOAT(__SEGGER_RTL_pow10)(-exp));
                v.r = 0;
              } else {
                exp = 0;
                u = (uint64_t)v.r;
                v.r -= (xfloat_t)u;
              }
            } else {
              u = 0;
              exp = 0;
            }



            len = 1;
            while (u >= __SEGGER_RTL_ipow10[len]) {
              ++len;
            }



            width -= precision + len + exp;



            if (precision || (flags & FORMAT_ALTERNATIVE)) {
              --width;
            }



            if (flags & FORMAT_NEGATIVE) {
              --width;
            }
          }



          if (width < 0) {
            width = 0;
          }



          if ((flags & (FORMAT_LEFT_JUSTIFY | FORMAT_ZERO_FILL)) == 0) {
            while (width) {
              --width;
              __SEGGER_RTL_putc(ctx, ' ');
            }
          }



          if (flags & FORMAT_SIGNED) {
            __SEGGER_RTL_putc(ctx, flags & FORMAT_SPACE ? '-' : '+');
          } else if (flags & FORMAT_SPACE) {
            __SEGGER_RTL_putc(ctx, ' ');
          }

          if ((flags & FORMAT_LEFT_JUSTIFY) == 0) {
            while (width) {
              --width, __SEGGER_RTL_putc(ctx, '0');
            }
          }



          do {
            --len;
            ch = '0';
            while (u >= __SEGGER_RTL_ipow10[len]) {
              ++ch;
              u -= __SEGGER_RTL_ipow10[len];
            }
            __SEGGER_RTL_putc(ctx, ch);
          } while (len);



          if (flags & FORMAT_FLOAT_F) {
            while (exp > 0) {
              --exp;
              __SEGGER_RTL_putc(ctx, '0');
            }
          }

          if (precision || flags & FORMAT_ALTERNATIVE) {
            __SEGGER_RTL_putc(ctx, '.');
            if (precision > 0) {
              if (precision > MAX_FLOAT_DIGITS) {
                len = MAX_FLOAT_DIGITS;
              } else {
                len = precision;
              }
            }



            precision -= len;
            if (flags & FORMAT_FLOAT_F) {
              u = (uint64_t)(v.r * XFLOAT(__SEGGER_RTL_pow10)(len-exp));
            } else {
              u = (uint64_t)(v.r * XFLOAT(__SEGGER_RTL_pow10)(len));
            }



            while (len) {
              --len;
              ch = '0';
              while (u >= __SEGGER_RTL_ipow10[len]) {
                ++ch, u -= __SEGGER_RTL_ipow10[len];
              }
              __SEGGER_RTL_putc(ctx, ch);
            }



            while (precision) {
              --precision, __SEGGER_RTL_putc(ctx, '0');
            }
          }

          if (flags & FORMAT_FLOAT_E) {



            __SEGGER_RTL_putc(ctx, flags & FORMAT_CAPITALS ? 'E' : 'e');
            if (exp < 0) {
              __SEGGER_RTL_putc(ctx, '-');
              exp = -exp;
            } else {
              __SEGGER_RTL_putc(ctx, '+');
            }

            if (exp >= 100) {
              __SEGGER_RTL_putc(ctx, (exp / 100 + '0'));
              exp %= 100;
            }
            __SEGGER_RTL_putc(ctx, exp / 10 + '0');
            __SEGGER_RTL_putc(ctx, exp % 10 + '0');
          }



          while (width) {
            --width;
            __SEGGER_RTL_putc(ctx, ' ');
          }
          continue;
#endif
      }

      len = 0;

#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      if ((flags & FORMAT_HAVE_PRECISION) == 0) {
        precision = 1;
      }
#endif

      switch (ch) {
      case 'p':
      case 'X':
      case 'x':
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION == 0
        if (v.u == 0) {
          buff[len++] = '0';
        }
#endif
        while (v.u) {
          if (flags & FORMAT_CAPITALS) {
            buff[len] = __SEGGER_RTL_hex_uc[v.u & 0xF];
          } else {
            buff[len] = __SEGGER_RTL_hex_lc[v.u & 0xF];
          }
          ++len;
          v.u >>= 4;
        }
        break;

      case 'o':
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION == 0
        if (v.u == 0) {
          buff[len++] = '0';
        }
#endif
        while (v.u) {
          buff[len] = '0' + ((unsigned)v.u & 7);
          ++len;
          v.u >>= 3;
        }
        break;

      case 'u':
      case 'i':
      case 'd':
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION == 0
        if (v.u == 0) {
          buff[len++] = '0';
        }
#endif
        while (v.u) {
          if (flags & FORMAT_TICK) {
            if ((len & 3) == 3) {
              buff[len] = ',';
              ++len;
            }
          }
          buff[len] = '0' + (unsigned)(v.u % 10u);
          ++len;
          v.u /= 10u;
        }
        break;
      }

#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      if ((precision -= len) < 0) {
        precision = 0;
      }



      width -= precision;
      width -= len;
      if (prefix >= 0x100) {
        --width;
      }
      if (prefix) {
        --width;
      }

      if ((flags & FORMAT_ZERO_FILL) == 0) {
        __SEGGER_RTL_pre_padding(ctx, flags, width);
        width = 0;
      }
#endif
      if (prefix >= 0x100) {
        __SEGGER_RTL_putc(ctx, prefix >> 8);
      }
      if (prefix) {
        __SEGGER_RTL_putc(ctx, prefix);
      }
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      __SEGGER_RTL_pre_padding(ctx, flags, width);
      __SEGGER_RTL_print_padding(ctx, '0', precision);
#endif
      while (--len >= 0) {
        __SEGGER_RTL_putc(ctx, buff[len]);
      }
#if __SEGGER_RTL_FORMAT_WIDTH_PRECISION
      if (flags & FORMAT_LEFT_JUSTIFY) {
        __SEGGER_RTL_print_padding(ctx, ' ', width);
      }
#endif
    }
  }



  if (ctx->string.wide && ctx->charcount < ctx->maxchars) {
    ctx->string.wide[ctx->charcount] = 0;
  }



  __SEGGER_RTL_prin_flush(ctx);

  return ctx->charcount;
}
# 1060 "./wprinops.c"
int __SEGGER_RTL_PUBLIC_API swprintf(wchar_t *s, size_t len, const wchar_t *format, ...) {
  __SEGGER_RTL_prin_t iod;
  va_list ap;
  int result;

  va_start(ap, format);
  __SEGGER_RTL_init_prin(&iod);
  iod.string.wide = s;
  iod.maxchars = len;
  result = __SEGGER_RTL_prin_wchar(&iod, format, ap);
  if (result >= (int)iod.maxchars) {
    result = -1;
  }
  return result;
}
# 1115 "./wprinops.c"
int __SEGGER_RTL_PUBLIC_API vswprintf(wchar_t *s, size_t len, const wchar_t *format, va_list arg) {
  __SEGGER_RTL_prin_t iod;
  int result;

  __SEGGER_RTL_init_prin(&iod);
  iod.string.wide = s;
  iod.maxchars = len;
  result = __SEGGER_RTL_prin_wchar(&iod, format, arg);
  if (result >= (int)iod.maxchars) {
    result = -1;
  }
  return result;
}
