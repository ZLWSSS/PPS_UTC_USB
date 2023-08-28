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
# 1 "./timeops.c"
# 17 "./timeops.c"
#include "__SEGGER_RTL_Int.h"
#include "time.h"
#include "stdlib.h"
#include "wchar.h"
#include "limits.h"
#include "locale.h"
#include "string.h"
# 32 "./timeops.c"
#define SECSPERMIN 60L
#define MINSPERHOUR 60L
#define HOURSPERDAY 24L
#define SECSPERHOUR (SECSPERMIN * MINSPERHOUR)
#define SECSPERDAY (SECSPERHOUR * HOURSPERDAY)
#define DAYSPERWEEK 7
#define MONSPERYEAR 12

#define EPOCH_YEAR 1970
#define EPOCH_WDAY 4

#define ISLEAP(y) ((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0)

#define CHECKVALUE(N,U,V) \
  if (tp->U < 0 || tp->U > N-1) \
    { \
      div_t l = div(tp->U, N); \
      tp->U = l.rem; \
      tp->V += l.quot; \
      if (tp->U < 0) \
        { \
          tp->U += N; \
          tp->V--; \
        } \
    }
# 65 "./timeops.c"
static const unsigned char __SEGGER_RTL_mon_lengths[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static const short __SEGGER_RTL_year_lengths[2] = {
  365,
  366
};

static const char __SEGGER_RTL_unknown_string[] = "<?>";
# 84 "./timeops.c"
static char __SEGGER_RTL_asctime_buf[28];
static struct tm __SEGGER_RTL_tm;
# 99 "./timeops.c"
static void __SEGGER_RTL_checktm(struct tm *tp) {
  const unsigned char *ip;
  long year;
  CHECKVALUE(60, tm_sec, tm_min);
  CHECKVALUE(60, tm_min, tm_hour);
  CHECKVALUE(24, tm_hour, tm_mday);
  CHECKVALUE(12, tm_mon, tm_year);
  year = tp->tm_year + 1900;
  ip = __SEGGER_RTL_mon_lengths[ISLEAP(year)];
  if (tp->tm_mday <= 0)
  {
    while (tp->tm_mday <= 0)
    {
      if (tp->tm_mon == 0)
      {
        tp->tm_year--;
        year--;
        ip = __SEGGER_RTL_mon_lengths[ISLEAP(year)];
        tp->tm_mon = 11;
      }
      else
        tp->tm_mon--;
      tp->tm_mday += ip[tp->tm_mon];
    }
  }
  else
  {
    while (tp->tm_mday > ip[tp->tm_mon])
    {
      tp->tm_mday -= ip[tp->tm_mon];
      if (tp->tm_mon == 11)
      {
        tp->tm_year++;
        year++;
        ip = __SEGGER_RTL_mon_lengths[ISLEAP(year)];
        tp->tm_mon = 0;
      }
      else
        tp->tm_mon++;
    }
  }
}






static void __SEGGER_RTL_put_ch(__SEGGER_RTL_time_state_t *state, int i) {
  if (state->smax > 1) {
    state->smax--;
    state->buf[0] = i;
    state->buf++;
  } else {
    state->smax = 0;
  }
}






static void __SEGGER_RTL_put_str(__SEGGER_RTL_time_state_t *state, const char *str) {
  while (*str) {
    __SEGGER_RTL_put_ch(state, *str++);
  }
}






static void __SEGGER_RTL_put_digit(__SEGGER_RTL_time_state_t *state, unsigned i) {
  __SEGGER_RTL_put_ch(state, i%10 + '0');
}






static void __SEGGER_RTL_put_twodigit(__SEGGER_RTL_time_state_t *state, unsigned i) {
  __SEGGER_RTL_put_ch(state, i/10 + '0');
  __SEGGER_RTL_put_ch(state, i%10 + '0');
}






static void __SEGGER_RTL_put_twodigits_leading_blank(__SEGGER_RTL_time_state_t *state, unsigned i) {
  if (i < 10) {
    __SEGGER_RTL_put_ch(state, ' ');
    __SEGGER_RTL_put_ch(state, i + '0');
  } else {
    __SEGGER_RTL_put_twodigit(state, i);
  }
}






static void __SEGGER_RTL_put_twodigit_optional_zero_suppress(__SEGGER_RTL_time_state_t *state, int hash, unsigned i) {
  if (hash && i < 10) {
    __SEGGER_RTL_put_ch(state, i + '0');
  } else {
    __SEGGER_RTL_put_twodigit(state, i);
  }
}






static void __SEGGER_RTL_put_threedigit(__SEGGER_RTL_time_state_t *state, int hash, unsigned i) {
  if (hash && i < 10) {
    __SEGGER_RTL_put_ch(state, i + '0');
  } else if (hash && i < 100) {
    __SEGGER_RTL_put_twodigit(state, i);
  } else {
    __SEGGER_RTL_put_digit(state, i/100);
    __SEGGER_RTL_put_twodigit(state, i % 100);
  }
}






static int __SEGGER_RTL_put_wide_char(__SEGGER_RTL_time_state_t *state, int wc) {
  char buf[MB_LEN_MAX];
  int n;



  n = wctomb(buf, wc);




  if (n < 0 || (size_t)n > state->smax) {
    return 0;
  }



  (memcpy)(state->buf, buf, n);



  state->buf += n;
  state->smax -= n;



  return n;
}






static void __SEGGER_RTL_put_fourdigit(__SEGGER_RTL_time_state_t *state, unsigned i) {
  __SEGGER_RTL_put_twodigit(state, i / 100);
  __SEGGER_RTL_put_twodigit(state, i % 100);
}






static void __SEGGER_RTL_put_utf8_str(__SEGGER_RTL_time_state_t *state, const char *str) {
  mbstate_t utf8_mbstate;
  wchar_t wc;
  size_t len;





  __SEGGER_RTL_init_mbstate(&utf8_mbstate);
  len = (strlen)(str);



  while (len > 0) {



    int n = __SEGGER_RTL_utf8_mbtowc(&wc, str, len, &utf8_mbstate);




    if (n < 0) {
      return;
    }



    if (wc == 0) {
      return;
    }
    if (__SEGGER_RTL_put_wide_char(state, wc) == 0) {
      return;
    }



    str += n;
    len -= n;
  }
}






static void __SEGGER_RTL_put_formatted(__SEGGER_RTL_time_state_t *state, const char *fmt, const struct tm *tp, const __SEGGER_RTL_locale_t *locale) {
  int hash;
  wchar_t wc;
  int n;
  const char * end;



  end = fmt + (strlen)(fmt);

  while (state->smax && fmt < end) {



    n = locale->codeset->__mbtowc(&wc, fmt, end-fmt, &state->mbstate);
    if (n < 0) {






      n = 1; wc = 0;
    }



    fmt += n;



    if (wc != '%') {
      if (__SEGGER_RTL_put_wide_char(state, wc) == 0) {
        return;
      }
    } else {
      hash = 0;
      if (*fmt == 'E' || *fmt == 'O') {




        ++fmt;
      } else if (*fmt == '#') {
        hash = 1;
        ++fmt;
      }

      switch (*fmt++) {
      case 0:
        --fmt;
        break;

      case '%':
        __SEGGER_RTL_put_ch(state, '%');
        break;

      case 'a':
        __SEGGER_RTL_put_str(state, __SEGGER_RTL_string_list_decode(locale->data->abbrev_day_names, tp->tm_wday));
        break;

      case 'A':
        __SEGGER_RTL_put_str(state, __SEGGER_RTL_string_list_decode(locale->data->day_names, tp->tm_wday));
        break;

      case 'b':
      case 'h':
        __SEGGER_RTL_put_utf8_str(state, __SEGGER_RTL_string_list_decode(locale->data->abbrev_month_names, tp->tm_mon));
        break;

      case 'B':
        __SEGGER_RTL_put_str(state, __SEGGER_RTL_string_list_decode(locale->data->month_names, tp->tm_mon));
        break;

      case 'c':
        if (hash) {

          __SEGGER_RTL_put_formatted(state, "%A, %B %#d, %Y, %H:%M:%S", tp, locale);
        } else {
          __SEGGER_RTL_put_formatted(state, locale->data->date_time_format, tp, locale);
        }
        break;

      case 'C':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, (tp->tm_year+1900) / 1000);
        break;

      case 'd':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_mday);
        break;

      case 'D':
        __SEGGER_RTL_put_formatted(state, "%m/%d/%y", tp, &__SEGGER_RTL_c_locale);
        break;

      case 'e':
        __SEGGER_RTL_put_twodigits_leading_blank(state, tp->tm_mday);
        break;

      case 'F':
        __SEGGER_RTL_put_formatted(state, "%Y-%m-%d", tp, locale);
        break;

#if 0
      case 'g':
        break;
      case 'G':
        break;
#endif

      case 'H':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_hour);
        break;

      case 'I':
        {
          int h = tp->tm_hour;
          h %= 12;
          if (h == 0) {
            h = 12;
          }
          __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, h);
        }
        break;

      case 'j':
        __SEGGER_RTL_put_threedigit(state, hash, tp->tm_yday+1);
        break;

      case 'k':
        __SEGGER_RTL_put_twodigits_leading_blank(state, tp->tm_hour);
        break;

      case 'l':
        if (tp->tm_hour <= 12) {
          __SEGGER_RTL_put_twodigits_leading_blank(state, tp->tm_hour);
        } else {
          __SEGGER_RTL_put_twodigits_leading_blank(state, tp->tm_hour-12);
        }
        break;

      case 'm':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_mon+1);
        break;

      case 'M':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_min);
        break;

      case 'n':
        __SEGGER_RTL_put_ch(state, '\n');
        break;

      case 'p':
        __SEGGER_RTL_put_str(state, __SEGGER_RTL_string_list_decode(locale->data->am_pm_indicator, tp->tm_hour >= 12));
        break;

      case 'r':
        __SEGGER_RTL_put_formatted(state, "%I:%M:%s %p", tp, locale);
        break;

      case 'R':
        __SEGGER_RTL_put_formatted(state, "%H:%M", tp, locale);
        break;

      case 'S':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_sec);
        break;

      case 't':
        __SEGGER_RTL_put_ch(state, '\t');
        break;

      case 'T':
        __SEGGER_RTL_put_formatted(state, "%H:%M:%S", tp, locale);
        break;

      case 'U':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, (tp->tm_yday + 7 - tp->tm_wday) / 7);
        break;

#if 0
      case 'V':
        break;
#endif

      case 'w':
        __SEGGER_RTL_put_digit(state, tp->tm_wday);
        break;

      case 'W':
        {
          int w = (tp->tm_wday) ? tp->tm_wday - 1 : 6;
          __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, (tp->tm_yday + 7 - w) / 7);
        }
        break;

      case 'x':
        if (hash) {
          __SEGGER_RTL_put_formatted(state, "%A, %B %#d, %Y", tp, locale);
        } else {
          __SEGGER_RTL_put_formatted(state, locale->data->date_format, tp, locale);
        }
        break;

      case 'X':
        __SEGGER_RTL_put_formatted(state, locale->data->time_format, tp, locale);
        break;

      case 'y':
        __SEGGER_RTL_put_twodigit_optional_zero_suppress(state, hash, tp->tm_year % 100);
        break;

      case 'Y':
        __SEGGER_RTL_put_fourdigit(state, 1900 + tp->tm_year);
        break;

      case 'z':
      case 'Z':
        break;
      }
    }
  }
}






static char * __SEGGER_RTL_twodigit(char *b, unsigned i) {
  *b++ = (i/10)+'0';
  *b++ = (i%10)+'0';
  return b;
}
# 575 "./timeops.c"
int __SEGGER_RTL_string_list_encode(const char *list, const char *str) {
  int index;

  index = 0;
  for (;;) {
    size_t n;



    if ((strcmp)(list, str) == 0) {
      return index;
    }



    n = (strlen)(str);
    if (n == 0) {
      return -1;
    }



    str += n + 1;
    ++index;
  }
}






const char * __SEGGER_RTL_string_list_decode(const char *str, int index) {
  size_t n;

  for (;;) {
    if (index == 0) {
      return str;
    }
    n = (strlen)(str);
    if (n == 0 || index < 0) {
      return __SEGGER_RTL_unknown_string;
    }
    str += n + 1;
    --index;
  }
}






time_t __SEGGER_RTL_PUBLIC_API time(time_t *timer) {
  struct timeval tv;



  if (gettimeofday(&tv, 0) < 0) {



    tv.tv_sec = (time_t)(-1);
  }

  if (timer) {
    *timer = tv.tv_sec;
  }

  return tv.tv_sec;
}
# 670 "./timeops.c"
time_t __SEGGER_RTL_PUBLIC_API mktime(struct tm *tp) {
  time_t tim;
  long days, year;
  int i;
  const unsigned char *ip;

  __SEGGER_RTL_checktm(tp);

  year = tp->tm_year + 1900;
  ip = __SEGGER_RTL_mon_lengths[ISLEAP(year)];
  days = tp->tm_mday - 1;
  for (i = 0; i < tp->tm_mon; i++)
    days += ip[i];
  tp->tm_yday = days;

  if (year > EPOCH_YEAR) {
    for (i = EPOCH_YEAR; i < year; i++) {
      days += __SEGGER_RTL_year_lengths[ISLEAP(i)];
    }
  } else {
    for (i = EPOCH_YEAR-1; i >= year; i--) {
      days -= __SEGGER_RTL_year_lengths[ISLEAP(i)];
    }
  }

  tp->tm_wday = (EPOCH_WDAY + days) % DAYSPERWEEK;
  if (tp->tm_wday < 0) {
    tp->tm_wday += DAYSPERWEEK;
  }

  tim = tp->tm_sec + (tp->tm_min * SECSPERMIN) + (tp->tm_hour * SECSPERHOUR) + (days * SECSPERDAY);

  return tim;
}
# 722 "./timeops.c"
double __SEGGER_RTL_PUBLIC_API difftime(time_t time2, time_t time1) {
  return time1-time2;
}
# 747 "./timeops.c"
struct tm * __SEGGER_RTL_PUBLIC_API localtime_r(const time_t *tp, struct tm *tm) {
  const unsigned char * ip;
  ldiv_t l;
  long days, rem, year;
  int isleap;

  l = ldiv(*tp, SECSPERDAY);
  days = l.quot;
  rem = l.rem;
  if (rem < 0) {
    rem += SECSPERDAY;
    --days;
  }

  l = ldiv(rem, SECSPERHOUR);
  tm->tm_hour = l.quot;
  rem = l.rem;

  l = ldiv(rem, SECSPERMIN);
  tm->tm_min = l.quot;
  tm->tm_sec = l.rem;

  tm->tm_wday = (EPOCH_WDAY + days) % DAYSPERWEEK;
  if (tm->tm_wday < 0) {
    tm->tm_wday += DAYSPERWEEK;
  }

  year = EPOCH_YEAR;
  if (days >=0) {
    for (;;) {
      isleap = ISLEAP(year);
      if (days < __SEGGER_RTL_year_lengths[isleap])
        break;
      days -= __SEGGER_RTL_year_lengths[isleap];
      year++;
    }
  } else {
    do {
      year--;
      isleap = ISLEAP(year);
      days += __SEGGER_RTL_year_lengths[isleap];
    } while (days < 0);
  }
  tm->tm_year = year-1900;
  tm->tm_yday = days;

  ip = __SEGGER_RTL_mon_lengths[isleap];
  for (tm->tm_mon = 0; days >= ip[tm->tm_mon]; tm->tm_mon++) {
    days -= ip[tm->tm_mon];
  }

  tm->tm_mday = days + 1;
  return tm;
}
# 826 "./timeops.c"
struct tm * __SEGGER_RTL_PUBLIC_API localtime(const time_t *tp) {
  localtime_r(tp, &__SEGGER_RTL_tm);
  return &__SEGGER_RTL_tm;
}
# 851 "./timeops.c"
struct tm * __SEGGER_RTL_PUBLIC_API gmtime_r(const time_t *tp, struct tm *tm) {
  localtime_r(tp, tm);
  return tm;
}
# 879 "./timeops.c"
struct tm * __SEGGER_RTL_PUBLIC_API gmtime(const time_t *tp) {
  localtime_r(tp, &__SEGGER_RTL_tm);
  return &__SEGGER_RTL_tm;
}
# 910 "./timeops.c"
char * __SEGGER_RTL_PUBLIC_API ctime_r(const time_t *tp, char *buf) {
  struct tm _tm;

  localtime_r(tp, &_tm);
  return asctime_r(&_tm, buf);
}
# 940 "./timeops.c"
char * __SEGGER_RTL_PUBLIC_API ctime(const time_t *tp) {
  localtime_r(tp, &__SEGGER_RTL_tm);
  return asctime(&__SEGGER_RTL_tm);
}
# 969 "./timeops.c"
char * __SEGGER_RTL_PUBLIC_API asctime_r(const struct tm *tp, char *buf) {
  int year;
  char *b = buf;

  b = mempcpy(b, __SEGGER_RTL_string_list_decode(__SEGGER_RTL_c_locale_abbrev_day_names, tp->tm_wday), 3);
  *b++ = ' ';
  b = mempcpy(b, __SEGGER_RTL_string_list_decode(__SEGGER_RTL_c_locale_abbrev_month_names, tp->tm_mon), 3);
  *b++ = ' ';
  b = __SEGGER_RTL_twodigit(b, tp->tm_mday);
  *b++ = ' ';
  b = __SEGGER_RTL_twodigit(b, tp->tm_hour);
  *b++ = ':';
  b = __SEGGER_RTL_twodigit(b, tp->tm_min);
  *b++ = ':';
  b = __SEGGER_RTL_twodigit(b, tp->tm_sec);
  *b++ = ' ';
  year = 1900 + tp->tm_year;
  b = __SEGGER_RTL_twodigit(b, year / 100);
  b = __SEGGER_RTL_twodigit(b, year % 100);
  *b++ = '\n';
  *b = 0;

  return buf;
}
# 1019 "./timeops.c"
char * __SEGGER_RTL_PUBLIC_API asctime(const struct tm *tp) {
  return asctime_r(tp, __SEGGER_RTL_asctime_buf);
}
# 1054 "./timeops.c"
size_t __SEGGER_RTL_PUBLIC_API strftime_l(char *s, size_t smax, const char *fmt, const struct tm *tp, locale_t loc) {
  __SEGGER_RTL_time_state_t state;

  state.smax = smax;
  state.buf = s;
  __SEGGER_RTL_init_mbstate(&state.mbstate);
  __SEGGER_RTL_put_formatted(&state, fmt, tp, loc->__category[LC_TIME]);
  if (state.smax) {
    state.buf[0] = 0;
    return state.buf - s;
  } else {
    return 0;
  }
}
# 1148 "./timeops.c"
size_t __SEGGER_RTL_PUBLIC_API strftime(char *s, size_t smax, const char *fmt, const struct tm *tp) {
  return strftime_l(s, smax, fmt, tp, __SEGGER_RTL_current_locale());
}






int __SEGGER_RTL_PUBLIC_API gettimeofday(struct timeval *tp, void *tzp) {
  __SEGGER_RTL_USE_PARA(tzp);

  return __SEGGER_RTL_X_get_time_of_day(tp);
}






int __SEGGER_RTL_PUBLIC_API settimeofday(const struct timeval *tp, const void *tzp) {
  __SEGGER_RTL_USE_PARA(tzp);

  return __SEGGER_RTL_X_set_time_of_day(tp);
}
