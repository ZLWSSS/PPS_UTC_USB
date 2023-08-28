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
# 1 "./codesets.c"
# 17 "./codesets.c"
#include "__SEGGER_RTL_Int.h"
#include "locale.h"
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "wchar.h"
# 31 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1250_to_unicode_map[] = {
             0x20AC, 0xDCFF, 0x201A, 0xDCFF, 0x201E, 0x2026, 0x2020, 0x2021,
             0xDCFF, 0x2030, 0x0160, 0x2039, 0x015A, 0x0164, 0x017D, 0x0179,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0xDCFF, 0x2122, 0x0161, 0x203A, 0x015B, 0x0165, 0x017E, 0x017A,
             0x00A0, 0x02C7, 0x02D8, 0x0141, 0x00A4, 0x0104, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x015E, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x017B,
             0x00B0, 0x00B1, 0x02DB, 0x0142, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x0105, 0x015F, 0x00BB, 0x013D, 0x02DD, 0x013E, 0x017C,
             0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7,
             0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
             0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7,
             0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
             0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7,
             0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
             0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7,
             0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1250_range_map[18] = {
  { 0x00A6, 0x00A9, 0x00A6 },
  { 0x00AB, 0x00AE, 0x00AB },
  { 0x00B0, 0x00B1, 0x00B0 },
  { 0x00B4, 0x00B8, 0x00B4 },
  { 0x00C1, 0x00C2, 0x00C1 },
  { 0x00CD, 0x00CE, 0x00CD },
  { 0x00D3, 0x00D4, 0x00D3 },
  { 0x00D6, 0x00D7, 0x00D6 },
  { 0x00DC, 0x00DD, 0x00DC },
  { 0x00E1, 0x00E2, 0x00E1 },
  { 0x00ED, 0x00EE, 0x00ED },
  { 0x00F3, 0x00F4, 0x00F3 },
  { 0x00F6, 0x00F7, 0x00F6 },
  { 0x00FC, 0x00FD, 0x00FC },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1250_singleton_map[80] = {
  { 0x00A0, 0x00A0 },
  { 0x00A4, 0x00A4 },
  { 0x00BB, 0x00BB },
  { 0x00C4, 0x00C4 },
  { 0x00C7, 0x00C7 },
  { 0x00C9, 0x00C9 },
  { 0x00CB, 0x00CB },
  { 0x00DA, 0x00DA },
  { 0x00DF, 0x00DF },
  { 0x00E4, 0x00E4 },
  { 0x00E7, 0x00E7 },
  { 0x00E9, 0x00E9 },
  { 0x00EB, 0x00EB },
  { 0x00FA, 0x00FA },
  { 0x0102, 0x00C3 },
  { 0x0103, 0x00E3 },
  { 0x0104, 0x00A5 },
  { 0x0105, 0x00B9 },
  { 0x0106, 0x00C6 },
  { 0x0107, 0x00E6 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x010E, 0x00CF },
  { 0x010F, 0x00EF },
  { 0x0110, 0x00D0 },
  { 0x0111, 0x00F0 },
  { 0x0118, 0x00CA },
  { 0x0119, 0x00EA },
  { 0x011A, 0x00CC },
  { 0x011B, 0x00EC },
  { 0x0139, 0x00C5 },
  { 0x013A, 0x00E5 },
  { 0x013D, 0x00BC },
  { 0x013E, 0x00BE },
  { 0x0141, 0x00A3 },
  { 0x0142, 0x00B3 },
  { 0x0143, 0x00D1 },
  { 0x0144, 0x00F1 },
  { 0x0147, 0x00D2 },
  { 0x0148, 0x00F2 },
  { 0x0150, 0x00D5 },
  { 0x0151, 0x00F5 },
  { 0x0154, 0x00C0 },
  { 0x0155, 0x00E0 },
  { 0x0158, 0x00D8 },
  { 0x0159, 0x00F8 },
  { 0x015A, 0x008C },
  { 0x015B, 0x009C },
  { 0x015E, 0x00AA },
  { 0x015F, 0x00BA },
  { 0x0160, 0x008A },
  { 0x0161, 0x009A },
  { 0x0162, 0x00DE },
  { 0x0163, 0x00FE },
  { 0x0164, 0x008D },
  { 0x0165, 0x009D },
  { 0x016E, 0x00D9 },
  { 0x016F, 0x00F9 },
  { 0x0170, 0x00DB },
  { 0x0171, 0x00FB },
  { 0x0179, 0x008F },
  { 0x017A, 0x009F },
  { 0x017B, 0x00AF },
  { 0x017C, 0x00BF },
  { 0x017D, 0x008E },
  { 0x017E, 0x009E },
  { 0x02C7, 0x00A1 },
  { 0x02D8, 0x00A2 },
  { 0x02D9, 0x00FF },
  { 0x02DB, 0x00B2 },
  { 0x02DD, 0x00BD },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 166 "./codesets.c"
static long __SEGGER_RTL_cp1250_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1250_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1250(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1250_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1250_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1250_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1250_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1250_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1250_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1250_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1250_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1250_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1250_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1250_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1250(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1250_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1250_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1250(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1250_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1250_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch;

  __SEGGER_RTL_USE_PARA(mbstate);

  nch = __SEGGER_RTL_unicode_to_cp1250(wc);
  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1250_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {
  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1250_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 267 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1250 = {
  __SEGGER_RTL_cp1250_isctype,
  __SEGGER_RTL_cp1250_toupper,
  __SEGGER_RTL_cp1250_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1250_wctomb,
  __SEGGER_RTL_cp1250_mbtowc
};
# 285 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1251_to_unicode_map[] = {
             0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
             0x20AC, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
             0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0xDCFF, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
             0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
             0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
             0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
             0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
             0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
             0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
             0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
             0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
             0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
             0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
             0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
             0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1251_range_map[10] = {
  { 0x00A6, 0x00A7, 0x00A6 },
  { 0x00AB, 0x00AE, 0x00AB },
  { 0x00B0, 0x00B1, 0x00B0 },
  { 0x00B5, 0x00B7, 0x00B5 },
  { 0x0402, 0x0403, 0x0080 },
  { 0x0410, 0x044F, 0x00C0 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1251_singleton_map[42] =
{
  { 0x00A0, 0x00A0 },
  { 0x00A4, 0x00A4 },
  { 0x00A9, 0x00A9 },
  { 0x00BB, 0x00BB },
  { 0x0401, 0x00A8 },
  { 0x0404, 0x00AA },
  { 0x0405, 0x00BD },
  { 0x0406, 0x00B2 },
  { 0x0407, 0x00AF },
  { 0x0408, 0x00A3 },
  { 0x0409, 0x008A },
  { 0x040A, 0x008C },
  { 0x040B, 0x008E },
  { 0x040C, 0x008D },
  { 0x040E, 0x00A1 },
  { 0x040F, 0x008F },
  { 0x0451, 0x00B8 },
  { 0x0452, 0x0090 },
  { 0x0453, 0x0083 },
  { 0x0454, 0x00BA },
  { 0x0455, 0x00BE },
  { 0x0456, 0x00B3 },
  { 0x0457, 0x00BF },
  { 0x0458, 0x00BC },
  { 0x0459, 0x009A },
  { 0x045A, 0x009C },
  { 0x045B, 0x009E },
  { 0x045C, 0x009D },
  { 0x045E, 0x00A2 },
  { 0x045F, 0x009F },
  { 0x0490, 0x00A5 },
  { 0x0491, 0x00B4 },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0088 },
  { 0x2116, 0x00B9 },
  { 0x2122, 0x0099 },
};
# 375 "./codesets.c"
static long __SEGGER_RTL_cp1251_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1251_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1251(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1251_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1251_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1251_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1251_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1251_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1251_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1251_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1251_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1251_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1251_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1251_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1251(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1251_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1251_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1251(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1251_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1251_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch;

  __SEGGER_RTL_USE_PARA(mbstate);

  nch = __SEGGER_RTL_unicode_to_cp1251(wc);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1251_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1251_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 478 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1251 = {
  __SEGGER_RTL_cp1251_isctype,
  __SEGGER_RTL_cp1251_toupper,
  __SEGGER_RTL_cp1251_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1251_wctomb,
  __SEGGER_RTL_cp1251_mbtowc
};
# 496 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1252_to_unicode_map[] = {
             0x20AC, 0xDCFF, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0xDCFF, 0x017D, 0xDCFF,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0xDCFF, 0x017E, 0x0178,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1252_range_map[5] = {
  { 0x00A0, 0x00FF, 0x00A0 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1252_singleton_map[19] = {
  { 0x0152, 0x008C },
  { 0x0153, 0x009C },
  { 0x0160, 0x008A },
  { 0x0161, 0x009A },
  { 0x0178, 0x009F },
  { 0x017D, 0x008E },
  { 0x017E, 0x009E },
  { 0x0192, 0x0083 },
  { 0x02C6, 0x0088 },
  { 0x02DC, 0x0098 },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 557 "./codesets.c"
static long __SEGGER_RTL_cp1252_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1252_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1252(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1252_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1252_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1252_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1252_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1252_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1252_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1252_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1252_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1252_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1252_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1252_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1252(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1252_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1252_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1252(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1252_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1252_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1252(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1252_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1252_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 658 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1252 = {
  __SEGGER_RTL_cp1252_isctype,
  __SEGGER_RTL_cp1252_toupper,
  __SEGGER_RTL_cp1252_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1252_wctomb,
  __SEGGER_RTL_cp1252_mbtowc
};

static const unsigned short __SEGGER_RTL_cp1253_to_unicode_map[] = {
             0x20AC, 0xDCFF, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0xDCFF, 0x2030, 0xDCFF, 0x2039, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0xDCFF, 0x2122, 0xDCFF, 0x203A, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0x00A0, 0x0385, 0x0386, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0xDCFF, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x2015,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x0384, 0x00B5, 0x00B6, 0x00B7,
             0x0388, 0x0389, 0x038A, 0x00BB, 0x038C, 0x00BD, 0x038E, 0x038F,
             0x0390, 0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397,
             0x0398, 0x0399, 0x039A, 0x039B, 0x039C, 0x039D, 0x039E, 0x039F,
             0x03A0, 0x03A1, 0xDCFF, 0x03A3, 0x03A4, 0x03A5, 0x03A6, 0x03A7,
             0x03A8, 0x03A9, 0x03AA, 0x03AB, 0x03AC, 0x03AD, 0x03AE, 0x03AF,
             0x03B0, 0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7,
             0x03B8, 0x03B9, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BE, 0x03BF,
             0x03C0, 0x03C1, 0x03C2, 0x03C3, 0x03C4, 0x03C5, 0x03C6, 0x03C7,
             0x03C8, 0x03C9, 0x03CA, 0x03CB, 0x03CC, 0x03CD, 0x03CE, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1253_range_map[12] = {
  { 0x00A3, 0x00A9, 0x00A3 },
  { 0x00AB, 0x00AE, 0x00AB },
  { 0x00B0, 0x00B3, 0x00B0 },
  { 0x00B5, 0x00B7, 0x00B5 },
  { 0x0385, 0x0386, 0x00A1 },
  { 0x0388, 0x038A, 0x00B8 },
  { 0x038E, 0x03A1, 0x00BE },
  { 0x03A3, 0x03CE, 0x00D3 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1253_singleton_map[16] = {
  { 0x00A0, 0x00A0 },
  { 0x00BB, 0x00BB },
  { 0x00BD, 0x00BD },
  { 0x0192, 0x0083 },
  { 0x0384, 0x00B4 },
  { 0x038C, 0x00BC },
  { 0x2015, 0x00AF },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 734 "./codesets.c"
static long __SEGGER_RTL_cp1253_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1253_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1253(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1253_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1253_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1253_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1253_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1253_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1253_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1253_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1253_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1253_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1253_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1253_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1253(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1253_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1253_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1253(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1253_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1253_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1253(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1253_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1253_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 835 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1253 = {
  __SEGGER_RTL_cp1253_isctype,
  __SEGGER_RTL_cp1253_toupper,
  __SEGGER_RTL_cp1253_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1253_wctomb,
  __SEGGER_RTL_cp1253_mbtowc
};
# 853 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1254_to_unicode_map[] =
{
             0x20AC, 0xDCFF, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0xDCFF, 0xDCFF, 0x0178,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x011E, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x0130, 0x015E, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x011F, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x0131, 0x015F, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1254_range_map[8] =
{
  { 0x00A0, 0x00CF, 0x00A0 },
  { 0x00D1, 0x00DC, 0x00D1 },
  { 0x00DF, 0x00EF, 0x00DF },
  { 0x00F1, 0x00FC, 0x00F1 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1254_singleton_map[24] =
{
  { 0x00FF, 0x00FF },
  { 0x011E, 0x00D0 },
  { 0x011F, 0x00F0 },
  { 0x0130, 0x00DD },
  { 0x0131, 0x00FD },
  { 0x0152, 0x008C },
  { 0x0153, 0x009C },
  { 0x015E, 0x00DE },
  { 0x015F, 0x00FE },
  { 0x0160, 0x008A },
  { 0x0161, 0x009A },
  { 0x0178, 0x009F },
  { 0x0192, 0x0083 },
  { 0x02C6, 0x0088 },
  { 0x02DC, 0x0098 },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 925 "./codesets.c"
static long __SEGGER_RTL_cp1254_to_unicode(int ch)
{
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1254_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1254(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1254_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1254_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1254_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1254_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1254_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1254_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1254_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1254_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1254_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1254_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1254_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1254(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1254_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1254_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1254(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1254_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1254_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1254(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1254_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1254_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 1027 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1254 = {
  __SEGGER_RTL_cp1254_isctype,
  __SEGGER_RTL_cp1254_toupper,
  __SEGGER_RTL_cp1254_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1254_wctomb,
  __SEGGER_RTL_cp1254_mbtowc
};
# 1045 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1255_to_unicode_map[] =
{
             0x20AC, 0xDCFF, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0x02C6, 0x2030, 0xDCFF, 0x2039, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0x02DC, 0x2122, 0xDCFF, 0x203A, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x20AA, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00D7, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00F7, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x05B0, 0x05B1, 0x05B2, 0x05B3, 0x05B4, 0x05B5, 0x05B6, 0x05B7,
             0x05B8, 0x05B9, 0xDCFF, 0x05BB, 0x05BC, 0x05BD, 0x05BE, 0x05BF,
             0x05C0, 0x05C1, 0x05C2, 0x05C3, 0x05F0, 0x05F1, 0x05F2, 0x05F3,
             0x05F4, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0x05D0, 0x05D1, 0x05D2, 0x05D3, 0x05D4, 0x05D5, 0x05D6, 0x05D7,
             0x05D8, 0x05D9, 0x05DA, 0x05DB, 0x05DC, 0x05DD, 0x05DE, 0x05DF,
             0x05E0, 0x05E1, 0x05E2, 0x05E3, 0x05E4, 0x05E5, 0x05E6, 0x05E7,
             0x05E8, 0x05E9, 0x05EA, 0xDCFF, 0xDCFF, 0x200E, 0x200F, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1255_range_map[13] =
{
  { 0x00A0, 0x00A3, 0x00A0 },
  { 0x00A5, 0x00A9, 0x00A5 },
  { 0x00AB, 0x00B9, 0x00AB },
  { 0x00BB, 0x00BF, 0x00BB },
  { 0x05B0, 0x05B9, 0x00C0 },
  { 0x05BB, 0x05C3, 0x00CB },
  { 0x05D0, 0x05EA, 0x00E0 },
  { 0x05F0, 0x05F4, 0x00D4 },
  { 0x200E, 0x200F, 0x00FD },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1255_singleton_map[15] =
{
  { 0x00D7, 0x00AA },
  { 0x00F7, 0x00BA },
  { 0x0192, 0x0083 },
  { 0x02C6, 0x0088 },
  { 0x02DC, 0x0098 },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AA, 0x00A4 },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 1113 "./codesets.c"
static long __SEGGER_RTL_cp1255_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1255_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1255(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1255_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1255_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1255_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1255_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1255_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1255_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1255_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1255_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1255_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1255_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1255_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1255(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1255_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1255_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1255(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1255_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1255_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1255(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1255_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1255_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 1214 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1255 = {
  __SEGGER_RTL_cp1255_isctype,
  __SEGGER_RTL_cp1255_toupper,
  __SEGGER_RTL_cp1255_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1255_wctomb,
  __SEGGER_RTL_cp1255_mbtowc
};
# 1232 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1256_to_unicode_map[] =
{
             0x20AC, 0x067E, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0x02C6, 0x2030, 0x0679, 0x2039, 0x0152, 0x0686, 0x0698, 0x0688,
             0x06AF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0x06A9, 0x2122, 0x0691, 0x203A, 0x0153, 0x200C, 0x200D, 0x06BA,
             0x00A0, 0x060C, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x06BE, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x061B, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x061F,
             0x06C1, 0x0621, 0x0622, 0x0623, 0x0624, 0x0625, 0x0626, 0x0627,
             0x0628, 0x0629, 0x062A, 0x062B, 0x062C, 0x062D, 0x062E, 0x062F,
             0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, 0x0636, 0x00D7,
             0x0637, 0x0638, 0x0639, 0x063A, 0x0640, 0x0641, 0x0642, 0x0643,
             0x00E0, 0x0644, 0x00E2, 0x0645, 0x0646, 0x0647, 0x0648, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x0649, 0x064A, 0x00EE, 0x00EF,
             0x064B, 0x064C, 0x064D, 0x064E, 0x00F4, 0x064F, 0x0650, 0x00F7,
             0x0651, 0x00F9, 0x0652, 0x00FB, 0x00FC, 0x200E, 0x200F, 0x06D2,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1256_range_map[19] =
{
  { 0x00A2, 0x00A9, 0x00A2 },
  { 0x00AB, 0x00B9, 0x00AB },
  { 0x00BB, 0x00BE, 0x00BB },
  { 0x00E7, 0x00EB, 0x00E7 },
  { 0x00EE, 0x00EF, 0x00EE },
  { 0x00FB, 0x00FC, 0x00FB },
  { 0x0621, 0x0636, 0x00C1 },
  { 0x0637, 0x063A, 0x00D8 },
  { 0x0640, 0x0643, 0x00DC },
  { 0x0645, 0x0648, 0x00E3 },
  { 0x0649, 0x064A, 0x00EC },
  { 0x064B, 0x064E, 0x00F0 },
  { 0x064F, 0x0650, 0x00F5 },
  { 0x200C, 0x200D, 0x009D },
  { 0x200E, 0x200F, 0x00FD },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1256_singleton_map[38] =
{
  { 0x00A0, 0x00A0 },
  { 0x00D7, 0x00D7 },
  { 0x00E0, 0x00E0 },
  { 0x00E2, 0x00E2 },
  { 0x00F4, 0x00F4 },
  { 0x00F7, 0x00F7 },
  { 0x00F9, 0x00F9 },
  { 0x0152, 0x008C },
  { 0x0153, 0x009C },
  { 0x0192, 0x0083 },
  { 0x02C6, 0x0088 },
  { 0x060C, 0x00A1 },
  { 0x061B, 0x00BA },
  { 0x061F, 0x00BF },
  { 0x0644, 0x00E1 },
  { 0x0651, 0x00F8 },
  { 0x0652, 0x00FA },
  { 0x0679, 0x008A },
  { 0x067E, 0x0081 },
  { 0x0686, 0x008D },
  { 0x0688, 0x008F },
  { 0x0691, 0x009A },
  { 0x0698, 0x008E },
  { 0x06A9, 0x0098 },
  { 0x06AF, 0x0090 },
  { 0x06BA, 0x009F },
  { 0x06BE, 0x00AA },
  { 0x06C1, 0x00C0 },
  { 0x06D2, 0x00FF },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 1329 "./codesets.c"
static long __SEGGER_RTL_cp1256_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1256_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1256(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1256_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1256_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1256_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1256_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1256_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1256_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1256_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1256_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1256_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1256_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1256_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1256(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1256_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1256_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1256(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1256_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1256_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1256(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1256_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1256_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 1430 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1256 = {
  __SEGGER_RTL_cp1256_isctype,
  __SEGGER_RTL_cp1256_toupper,
  __SEGGER_RTL_cp1256_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1256_wctomb,
  __SEGGER_RTL_cp1256_mbtowc
};
# 1448 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1257_to_unicode_map[] =
{
             0x20AC, 0xDCFF, 0x201A, 0xDCFF, 0x201E, 0x2026, 0x2020, 0x2021,
             0xDCFF, 0x2030, 0xDCFF, 0x2039, 0xDCFF, 0x00A8, 0x02C7, 0x00B8,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0xDCFF, 0x2122, 0xDCFF, 0x203A, 0xDCFF, 0x00AF, 0x02DB, 0xDCFF,
             0x00A0, 0xDCFF, 0x00A2, 0x00A3, 0x00A4, 0xDCFF, 0x00A6, 0x00A7,
             0x00D8, 0x00A9, 0x0156, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00C6,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00F8, 0x00B9, 0x0157, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00E6,
             0x0104, 0x012E, 0x0100, 0x0106, 0x00C4, 0x00C5, 0x0118, 0x0112,
             0x010C, 0x00C9, 0x0179, 0x0116, 0x0122, 0x0136, 0x012A, 0x013B,
             0x0160, 0x0143, 0x0145, 0x00D3, 0x014C, 0x00D5, 0x00D6, 0x00D7,
             0x0172, 0x0141, 0x015A, 0x016A, 0x00DC, 0x017B, 0x017D, 0x00DF,
             0x0105, 0x012F, 0x0101, 0x0107, 0x00E4, 0x00E5, 0x0119, 0x0113,
             0x010D, 0x00E9, 0x017A, 0x0117, 0x0123, 0x0137, 0x012B, 0x013C,
             0x0161, 0x0144, 0x0146, 0x00F3, 0x014D, 0x00F5, 0x00F6, 0x00F7,
             0x0173, 0x0142, 0x015B, 0x016B, 0x00FC, 0x017C, 0x017E, 0x02D9,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1257_range_map[13] =
{
  { 0x00A2, 0x00A4, 0x00A2 },
  { 0x00A6, 0x00A7, 0x00A6 },
  { 0x00AB, 0x00AE, 0x00AB },
  { 0x00B0, 0x00B7, 0x00B0 },
  { 0x00BB, 0x00BE, 0x00BB },
  { 0x00C4, 0x00C5, 0x00C4 },
  { 0x00D5, 0x00D7, 0x00D5 },
  { 0x00E4, 0x00E5, 0x00E4 },
  { 0x00F5, 0x00F7, 0x00F5 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1257_singleton_map[77] =
{
  { 0x00A0, 0x00A0 },
  { 0x00A8, 0x008D },
  { 0x00A9, 0x00A9 },
  { 0x00AF, 0x009D },
  { 0x00B8, 0x008F },
  { 0x00B9, 0x00B9 },
  { 0x00C6, 0x00AF },
  { 0x00C9, 0x00C9 },
  { 0x00D3, 0x00D3 },
  { 0x00D8, 0x00A8 },
  { 0x00DC, 0x00DC },
  { 0x00DF, 0x00DF },
  { 0x00E6, 0x00BF },
  { 0x00E9, 0x00E9 },
  { 0x00F3, 0x00F3 },
  { 0x00F8, 0x00B8 },
  { 0x00FC, 0x00FC },
  { 0x0100, 0x00C2 },
  { 0x0101, 0x00E2 },
  { 0x0104, 0x00C0 },
  { 0x0105, 0x00E0 },
  { 0x0106, 0x00C3 },
  { 0x0107, 0x00E3 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x0112, 0x00C7 },
  { 0x0113, 0x00E7 },
  { 0x0116, 0x00CB },
  { 0x0117, 0x00EB },
  { 0x0118, 0x00C6 },
  { 0x0119, 0x00E6 },
  { 0x0122, 0x00CC },
  { 0x0123, 0x00EC },
  { 0x012A, 0x00CE },
  { 0x012B, 0x00EE },
  { 0x012E, 0x00C1 },
  { 0x012F, 0x00E1 },
  { 0x0136, 0x00CD },
  { 0x0137, 0x00ED },
  { 0x013B, 0x00CF },
  { 0x013C, 0x00EF },
  { 0x0141, 0x00D9 },
  { 0x0142, 0x00F9 },
  { 0x0143, 0x00D1 },
  { 0x0144, 0x00F1 },
  { 0x0145, 0x00D2 },
  { 0x0146, 0x00F2 },
  { 0x014C, 0x00D4 },
  { 0x014D, 0x00F4 },
  { 0x0156, 0x00AA },
  { 0x0157, 0x00BA },
  { 0x015A, 0x00DA },
  { 0x015B, 0x00FA },
  { 0x0160, 0x00D0 },
  { 0x0161, 0x00F0 },
  { 0x016A, 0x00DB },
  { 0x016B, 0x00FB },
  { 0x0172, 0x00D8 },
  { 0x0173, 0x00F8 },
  { 0x0179, 0x00CA },
  { 0x017A, 0x00EA },
  { 0x017B, 0x00DD },
  { 0x017C, 0x00FD },
  { 0x017D, 0x00DE },
  { 0x017E, 0x00FE },
  { 0x02C7, 0x008E },
  { 0x02D9, 0x00FF },
  { 0x02DB, 0x009E },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 1578 "./codesets.c"
static long __SEGGER_RTL_cp1257_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1257_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1257(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1257_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1257_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1257_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1257_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1257_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1257_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1257_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1257_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1257_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1257_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1257_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1257(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1257_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1257_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1257(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1257_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1257_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1257(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1257_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1257_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 1679 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1257 = {
  __SEGGER_RTL_cp1257_isctype,
  __SEGGER_RTL_cp1257_toupper,
  __SEGGER_RTL_cp1257_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1257_wctomb,
  __SEGGER_RTL_cp1257_mbtowc
};
# 1697 "./codesets.c"
static const unsigned short __SEGGER_RTL_cp1258_to_unicode_map[] =
{
             0x20AC, 0xDCFF, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
             0x02C6, 0x2030, 0xDCFF, 0x2039, 0x0152, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
             0x02DC, 0x2122, 0xDCFF, 0x203A, 0x0153, 0xDCFF, 0xDCFF, 0x0178,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x0300, 0x00CD, 0x00CE, 0x00CF,
             0x0110, 0x00D1, 0x0309, 0x00D3, 0x00D4, 0x01A0, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x01AF, 0x0303, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x0301, 0x00ED, 0x00EE, 0x00EF,
             0x0111, 0x00F1, 0x0323, 0x00F3, 0x00F4, 0x01A1, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x01B0, 0x20AB, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_cp1258_range_map[14] =
{
  { 0x00A0, 0x00C2, 0x00A0 },
  { 0x00C4, 0x00CB, 0x00C4 },
  { 0x00CD, 0x00CF, 0x00CD },
  { 0x00D3, 0x00D4, 0x00D3 },
  { 0x00D6, 0x00DC, 0x00D6 },
  { 0x00DF, 0x00E2, 0x00DF },
  { 0x00E4, 0x00EB, 0x00E4 },
  { 0x00ED, 0x00EF, 0x00ED },
  { 0x00F3, 0x00F4, 0x00F3 },
  { 0x00F6, 0x00FC, 0x00F6 },
  { 0x2013, 0x2014, 0x0096 },
  { 0x2018, 0x2019, 0x0091 },
  { 0x201C, 0x201D, 0x0093 },
  { 0x2020, 0x2021, 0x0086 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_cp1258_singleton_map[32] =
{
  { 0x00D1, 0x00D1 },
  { 0x00F1, 0x00F1 },
  { 0x00FF, 0x00FF },
  { 0x0102, 0x00C3 },
  { 0x0103, 0x00E3 },
  { 0x0110, 0x00D0 },
  { 0x0111, 0x00F0 },
  { 0x0152, 0x008C },
  { 0x0153, 0x009C },
  { 0x0178, 0x009F },
  { 0x0192, 0x0083 },
  { 0x01A0, 0x00D5 },
  { 0x01A1, 0x00F5 },
  { 0x01AF, 0x00DD },
  { 0x01B0, 0x00FD },
  { 0x02C6, 0x0088 },
  { 0x02DC, 0x0098 },
  { 0x0300, 0x00CC },
  { 0x0301, 0x00EC },
  { 0x0303, 0x00DE },
  { 0x0309, 0x00D2 },
  { 0x0323, 0x00F2 },
  { 0x201A, 0x0082 },
  { 0x201E, 0x0084 },
  { 0x2022, 0x0095 },
  { 0x2026, 0x0085 },
  { 0x2030, 0x0089 },
  { 0x2039, 0x008B },
  { 0x203A, 0x009B },
  { 0x20AB, 0x00FE },
  { 0x20AC, 0x0080 },
  { 0x2122, 0x0099 },
};
# 1783 "./codesets.c"
static long __SEGGER_RTL_cp1258_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_cp1258_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_cp1258(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1258_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1258_range_map) / sizeof(__SEGGER_RTL_unicode_to_cp1258_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1258_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_cp1258_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_cp1258_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_cp1258_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_cp1258_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_cp1258_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_cp1258_to_unicode(ch), type);
}






static int __SEGGER_RTL_cp1258_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1258(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_cp1258_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1258_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_cp1258(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_cp1258_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_cp1258_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_cp1258(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_cp1258_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_cp1258_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 1884 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1258 = {
  __SEGGER_RTL_cp1258_isctype,
  __SEGGER_RTL_cp1258_toupper,
  __SEGGER_RTL_cp1258_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_cp1258_wctomb,
  __SEGGER_RTL_cp1258_mbtowc
};
# 1902 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_1_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_1_range_map[1] =
{
  { 0x0080, 0x00FF, 0x0080 },
};
# 1939 "./codesets.c"
static long __SEGGER_RTL_iso8859_1_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_1_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_1(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_1_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_1_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_1_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_1_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  return EOF;
}






static int __SEGGER_RTL_iso8859_1_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_1_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_1_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_1(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_1_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_1_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_1(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_1_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_1_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_1(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_1_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_1_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 2033 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_1 =
{
  __SEGGER_RTL_iso8859_1_isctype,
  __SEGGER_RTL_iso8859_1_toupper,
  __SEGGER_RTL_iso8859_1_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_1_wctomb,
  __SEGGER_RTL_iso8859_1_mbtowc
};
# 2052 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_10_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0104, 0x0112, 0x0122, 0x012A, 0x0128, 0x0136, 0x00A7,
             0x013B, 0x0110, 0x0160, 0x0166, 0x017D, 0x00AD, 0x016A, 0x014A,
             0x00B0, 0x0105, 0x0113, 0x0123, 0x012B, 0x0129, 0x0137, 0x00B7,
             0x013C, 0x0111, 0x0161, 0x0167, 0x017E, 0x2015, 0x016B, 0x014B,
             0x0100, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x012E,
             0x010C, 0x00C9, 0x0118, 0x00CB, 0x0116, 0x00CD, 0x00CE, 0x00CF,
             0x00D0, 0x0145, 0x014C, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x0168,
             0x00D8, 0x0172, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
             0x0101, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x012F,
             0x010D, 0x00E9, 0x0119, 0x00EB, 0x0117, 0x00ED, 0x00EE, 0x00EF,
             0x00F0, 0x0146, 0x014D, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x0169,
             0x00F8, 0x0173, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x0138,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_10_range_map[9] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00C1, 0x00C6, 0x00C1 },
  { 0x00CD, 0x00D0, 0x00CD },
  { 0x00D3, 0x00D6, 0x00D3 },
  { 0x00DA, 0x00DF, 0x00DA },
  { 0x00E1, 0x00E6, 0x00E1 },
  { 0x00ED, 0x00F0, 0x00ED },
  { 0x00F3, 0x00F6, 0x00F3 },
  { 0x00FA, 0x00FE, 0x00FA },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_10_singleton_map[56] =
{
  { 0x00A7, 0x00A7 },
  { 0x00AD, 0x00AD },
  { 0x00B0, 0x00B0 },
  { 0x00B7, 0x00B7 },
  { 0x00C9, 0x00C9 },
  { 0x00CB, 0x00CB },
  { 0x00D8, 0x00D8 },
  { 0x00E9, 0x00E9 },
  { 0x00EB, 0x00EB },
  { 0x00F8, 0x00F8 },
  { 0x0100, 0x00C0 },
  { 0x0101, 0x00E0 },
  { 0x0104, 0x00A1 },
  { 0x0105, 0x00B1 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x0110, 0x00A9 },
  { 0x0111, 0x00B9 },
  { 0x0112, 0x00A2 },
  { 0x0113, 0x00B2 },
  { 0x0116, 0x00CC },
  { 0x0117, 0x00EC },
  { 0x0118, 0x00CA },
  { 0x0119, 0x00EA },
  { 0x0122, 0x00A3 },
  { 0x0123, 0x00B3 },
  { 0x0128, 0x00A5 },
  { 0x0129, 0x00B5 },
  { 0x012A, 0x00A4 },
  { 0x012B, 0x00B4 },
  { 0x012E, 0x00C7 },
  { 0x012F, 0x00E7 },
  { 0x0136, 0x00A6 },
  { 0x0137, 0x00B6 },
  { 0x0138, 0x00FF },
  { 0x013B, 0x00A8 },
  { 0x013C, 0x00B8 },
  { 0x0145, 0x00D1 },
  { 0x0146, 0x00F1 },
  { 0x014A, 0x00AF },
  { 0x014B, 0x00BF },
  { 0x014C, 0x00D2 },
  { 0x014D, 0x00F2 },
  { 0x0160, 0x00AA },
  { 0x0161, 0x00BA },
  { 0x0166, 0x00AB },
  { 0x0167, 0x00BB },
  { 0x0168, 0x00D7 },
  { 0x0169, 0x00F7 },
  { 0x016A, 0x00AE },
  { 0x016B, 0x00BE },
  { 0x0172, 0x00D9 },
  { 0x0173, 0x00F9 },
  { 0x017D, 0x00AC },
  { 0x017E, 0x00BC },
  { 0x2015, 0x00BD },
};
# 2157 "./codesets.c"
static long __SEGGER_RTL_iso8859_10_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_10_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_10(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_10_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_10_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_10_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_10_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_10_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_10_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_10_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_10_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_10_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_10_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_10_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_10(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_10_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_10_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_10(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_10_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_10_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_10(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_10_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_10_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 2258 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_10 =
{
  __SEGGER_RTL_iso8859_10_isctype,
  __SEGGER_RTL_iso8859_10_toupper,
  __SEGGER_RTL_iso8859_10_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_10_wctomb,
  __SEGGER_RTL_iso8859_10_mbtowc
};
# 2277 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_11_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0E01, 0x0E02, 0x0E03, 0x0E04, 0x0E05, 0x0E06, 0x0E07,
             0x0E08, 0x0E09, 0x0E0A, 0x0E0B, 0x0E0C, 0x0E0D, 0x0E0E, 0x0E0F,
             0x0E10, 0x0E11, 0x0E12, 0x0E13, 0x0E14, 0x0E15, 0x0E16, 0x0E17,
             0x0E18, 0x0E19, 0x0E1A, 0x0E1B, 0x0E1C, 0x0E1D, 0x0E1E, 0x0E1F,
             0x0E20, 0x0E21, 0x0E22, 0x0E23, 0x0E24, 0x0E25, 0x0E26, 0x0E27,
             0x0E28, 0x0E29, 0x0E2A, 0x0E2B, 0x0E2C, 0x0E2D, 0x0E2E, 0x0E2F,
             0x0E30, 0x0E31, 0x0E32, 0x0E33, 0x0E34, 0x0E35, 0x0E36, 0x0E37,
             0x0E38, 0x0E39, 0x0E3A, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0x0E3F,
             0x0E40, 0x0E41, 0x0E42, 0x0E43, 0x0E44, 0x0E45, 0x0E46, 0x0E47,
             0x0E48, 0x0E49, 0x0E4A, 0x0E4B, 0x0E4C, 0x0E4D, 0x0E4E, 0x0E4F,
             0x0E50, 0x0E51, 0x0E52, 0x0E53, 0x0E54, 0x0E55, 0x0E56, 0x0E57,
             0x0E58, 0x0E59, 0x0E5A, 0x0E5B, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_11_range_map[3] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x0E01, 0x0E3A, 0x00A1 },
  { 0x0E3F, 0x0E5B, 0x00DF },
};
# 2316 "./codesets.c"
static long __SEGGER_RTL_iso8859_11_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_11_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_11(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_11_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_11_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_11_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_11_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  return EOF;
}






static int __SEGGER_RTL_iso8859_11_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_11_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_11_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_11(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_11_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_11_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_11(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_11_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_11_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_11(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_11_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_11_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 2410 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_11 =
{
  __SEGGER_RTL_iso8859_11_isctype,
  __SEGGER_RTL_iso8859_11_toupper,
  __SEGGER_RTL_iso8859_11_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_11_wctomb,
  __SEGGER_RTL_iso8859_11_mbtowc
};
# 2429 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_13_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x201D, 0x00A2, 0x00A3, 0x00A4, 0x201E, 0x00A6, 0x00A7,
             0x00D8, 0x00A9, 0x0156, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00C6,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x201C, 0x00B5, 0x00B6, 0x00B7,
             0x00F8, 0x00B9, 0x0157, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00E6,
             0x0104, 0x012E, 0x0100, 0x0106, 0x00C4, 0x00C5, 0x0118, 0x0112,
             0x010C, 0x00C9, 0x0179, 0x0116, 0x0122, 0x0136, 0x012A, 0x013B,
             0x0160, 0x0143, 0x0145, 0x00D3, 0x014C, 0x00D5, 0x00D6, 0x00D7,
             0x0172, 0x0141, 0x015A, 0x016A, 0x00DC, 0x017B, 0x017D, 0x00DF,
             0x0105, 0x012F, 0x0101, 0x0107, 0x00E4, 0x00E5, 0x0119, 0x0113,
             0x010D, 0x00E9, 0x017A, 0x0117, 0x0123, 0x0137, 0x012B, 0x013C,
             0x0161, 0x0144, 0x0146, 0x00F3, 0x014D, 0x00F5, 0x00F6, 0x00F7,
             0x0173, 0x0142, 0x015B, 0x016B, 0x00FC, 0x017C, 0x017E, 0x2019,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_13_range_map[11] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A2, 0x00A4, 0x00A2 },
  { 0x00A6, 0x00A7, 0x00A6 },
  { 0x00AB, 0x00AE, 0x00AB },
  { 0x00B0, 0x00B3, 0x00B0 },
  { 0x00B5, 0x00B7, 0x00B5 },
  { 0x00BB, 0x00BE, 0x00BB },
  { 0x00C4, 0x00C5, 0x00C4 },
  { 0x00D5, 0x00D7, 0x00D5 },
  { 0x00E4, 0x00E5, 0x00E4 },
  { 0x00F5, 0x00F7, 0x00F5 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_13_singleton_map[65] =
{
  { 0x00A9, 0x00A9 },
  { 0x00B9, 0x00B9 },
  { 0x00C6, 0x00AF },
  { 0x00C9, 0x00C9 },
  { 0x00D3, 0x00D3 },
  { 0x00D8, 0x00A8 },
  { 0x00DC, 0x00DC },
  { 0x00DF, 0x00DF },
  { 0x00E6, 0x00BF },
  { 0x00E9, 0x00E9 },
  { 0x00F3, 0x00F3 },
  { 0x00F8, 0x00B8 },
  { 0x00FC, 0x00FC },
  { 0x0100, 0x00C2 },
  { 0x0101, 0x00E2 },
  { 0x0104, 0x00C0 },
  { 0x0105, 0x00E0 },
  { 0x0106, 0x00C3 },
  { 0x0107, 0x00E3 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x0112, 0x00C7 },
  { 0x0113, 0x00E7 },
  { 0x0116, 0x00CB },
  { 0x0117, 0x00EB },
  { 0x0118, 0x00C6 },
  { 0x0119, 0x00E6 },
  { 0x0122, 0x00CC },
  { 0x0123, 0x00EC },
  { 0x012A, 0x00CE },
  { 0x012B, 0x00EE },
  { 0x012E, 0x00C1 },
  { 0x012F, 0x00E1 },
  { 0x0136, 0x00CD },
  { 0x0137, 0x00ED },
  { 0x013B, 0x00CF },
  { 0x013C, 0x00EF },
  { 0x0141, 0x00D9 },
  { 0x0142, 0x00F9 },
  { 0x0143, 0x00D1 },
  { 0x0144, 0x00F1 },
  { 0x0145, 0x00D2 },
  { 0x0146, 0x00F2 },
  { 0x014C, 0x00D4 },
  { 0x014D, 0x00F4 },
  { 0x0156, 0x00AA },
  { 0x0157, 0x00BA },
  { 0x015A, 0x00DA },
  { 0x015B, 0x00FA },
  { 0x0160, 0x00D0 },
  { 0x0161, 0x00F0 },
  { 0x016A, 0x00DB },
  { 0x016B, 0x00FB },
  { 0x0172, 0x00D8 },
  { 0x0173, 0x00F8 },
  { 0x0179, 0x00CA },
  { 0x017A, 0x00EA },
  { 0x017B, 0x00DD },
  { 0x017C, 0x00FD },
  { 0x017D, 0x00DE },
  { 0x017E, 0x00FE },
  { 0x2019, 0x00FF },
  { 0x201C, 0x00B4 },
  { 0x201D, 0x00A1 },
  { 0x201E, 0x00A5 },
};
# 2545 "./codesets.c"
static long __SEGGER_RTL_iso8859_13_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_13_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_13(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_13_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_13_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_13_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_13_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_13_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_13_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_13_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_13_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_13_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_13_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_13_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_13(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_13_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_13_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_13(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_13_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_13_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_13(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_13_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_13_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 2646 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_13 =
{
  __SEGGER_RTL_iso8859_13_isctype,
  __SEGGER_RTL_iso8859_13_toupper,
  __SEGGER_RTL_iso8859_13_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_13_wctomb,
  __SEGGER_RTL_iso8859_13_mbtowc
};
# 2665 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_14_to_unicode_map[] = {
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x1E02, 0x1E03, 0x00A3, 0x010A, 0x010B, 0x1E0A, 0x00A7,
             0x1E80, 0x00A9, 0x1E82, 0x1E0B, 0x1EF2, 0x00AD, 0x00AE, 0x0178,
             0x1E1E, 0x1E1F, 0x0120, 0x0121, 0x1E40, 0x1E41, 0x00B6, 0x1E56,
             0x1E81, 0x1E57, 0x1E83, 0x1E60, 0x1EF3, 0x1E84, 0x1E85, 0x1E61,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x0174, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x1E6A,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x0176, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x0175, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x1E6B,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x0177, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_14_range_map[14] = {
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00AD, 0x00AE, 0x00AD },
  { 0x00C0, 0x00CF, 0x00C0 },
  { 0x00D1, 0x00D6, 0x00D1 },
  { 0x00D8, 0x00DD, 0x00D8 },
  { 0x00DF, 0x00EF, 0x00DF },
  { 0x00F1, 0x00F6, 0x00F1 },
  { 0x00F8, 0x00FD, 0x00F8 },
  { 0x010A, 0x010B, 0x00A4 },
  { 0x0120, 0x0121, 0x00B2 },
  { 0x1E02, 0x1E03, 0x00A1 },
  { 0x1E1E, 0x1E1F, 0x00B0 },
  { 0x1E40, 0x1E41, 0x00B4 },
  { 0x1E84, 0x1E85, 0x00BD },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_14_singleton_map[24] =
{
  { 0x00A3, 0x00A3 },
  { 0x00A7, 0x00A7 },
  { 0x00A9, 0x00A9 },
  { 0x00B6, 0x00B6 },
  { 0x00FF, 0x00FF },
  { 0x0174, 0x00D0 },
  { 0x0175, 0x00F0 },
  { 0x0176, 0x00DE },
  { 0x0177, 0x00FE },
  { 0x0178, 0x00AF },
  { 0x1E0A, 0x00A6 },
  { 0x1E0B, 0x00AB },
  { 0x1E56, 0x00B7 },
  { 0x1E57, 0x00B9 },
  { 0x1E60, 0x00BB },
  { 0x1E61, 0x00BF },
  { 0x1E6A, 0x00D7 },
  { 0x1E6B, 0x00F7 },
  { 0x1E80, 0x00A8 },
  { 0x1E81, 0x00B8 },
  { 0x1E82, 0x00AA },
  { 0x1E83, 0x00BA },
  { 0x1EF2, 0x00AC },
  { 0x1EF3, 0x00BC },
};
# 2741 "./codesets.c"
static long __SEGGER_RTL_iso8859_14_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_14_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_14(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_14_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_14_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_14_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_14_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_14_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_14_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_14_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_14_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_14_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_14_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_14_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_14(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_14_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_14_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_14(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_14_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_14_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_14(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_14_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_14_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 2842 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_14 =
{
  __SEGGER_RTL_iso8859_14_isctype,
  __SEGGER_RTL_iso8859_14_toupper,
  __SEGGER_RTL_iso8859_14_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_14_wctomb,
  __SEGGER_RTL_iso8859_14_mbtowc
};
# 2861 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_15_to_unicode_map[] = {
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x20AC, 0x00A5, 0x0160, 0x00A7,
             0x0161, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x017D, 0x00B5, 0x00B6, 0x00B7,
             0x017E, 0x00B9, 0x00BA, 0x00BB, 0x0152, 0x0153, 0x0178, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_15_range_map[6] =
{
  { 0x0080, 0x00A3, 0x0080 },
  { 0x00A9, 0x00B3, 0x00A9 },
  { 0x00B5, 0x00B7, 0x00B5 },
  { 0x00B9, 0x00BB, 0x00B9 },
  { 0x00BF, 0x00FF, 0x00BF },
  { 0x0152, 0x0153, 0x00BC },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_15_singleton_map[8] =
{
  { 0x00A5, 0x00A5 },
  { 0x00A7, 0x00A7 },
  { 0x0160, 0x00A6 },
  { 0x0161, 0x00A8 },
  { 0x0178, 0x00BE },
  { 0x017D, 0x00B4 },
  { 0x017E, 0x00B8 },
  { 0x20AC, 0x00A4 },
};
# 2914 "./codesets.c"
static long __SEGGER_RTL_iso8859_15_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_15_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_15(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_15_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_15_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_15_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_15_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_15_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_15_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_15_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_15_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_15_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_15_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_15_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_15(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_15_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_15_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_15(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_15_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_15_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_15(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_15_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_15_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 3015 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_15 =
{
  __SEGGER_RTL_iso8859_15_isctype,
  __SEGGER_RTL_iso8859_15_toupper,
  __SEGGER_RTL_iso8859_15_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_15_wctomb,
  __SEGGER_RTL_iso8859_15_mbtowc
};
# 3034 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_16_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0104, 0x0105, 0x0141, 0x20AC, 0x201E, 0x0160, 0x00A7,
             0x0161, 0x00A9, 0x0218, 0x00AB, 0x0179, 0x00AD, 0x017A, 0x017B,
             0x00B0, 0x00B1, 0x010C, 0x0142, 0x017D, 0x201D, 0x00B6, 0x00B7,
             0x017E, 0x010D, 0x0219, 0x00BB, 0x0152, 0x0153, 0x0178, 0x017C,
             0x00C0, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0106, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x0110, 0x0143, 0x00D2, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x015A,
             0x0170, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x0118, 0x021A, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x0107, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x0111, 0x0144, 0x00F2, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x015B,
             0x0171, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x0119, 0x021B, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_16_range_map[14] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00B0, 0x00B1, 0x00B0 },
  { 0x00B6, 0x00B7, 0x00B6 },
  { 0x00C0, 0x00C2, 0x00C0 },
  { 0x00C6, 0x00CF, 0x00C6 },
  { 0x00D2, 0x00D4, 0x00D2 },
  { 0x00D9, 0x00DC, 0x00D9 },
  { 0x00DF, 0x00E2, 0x00DF },
  { 0x00E6, 0x00EF, 0x00E6 },
  { 0x00F2, 0x00F4, 0x00F2 },
  { 0x00F9, 0x00FC, 0x00F9 },
  { 0x0104, 0x0105, 0x00A1 },
  { 0x0152, 0x0153, 0x00BC },
  { 0x017A, 0x017B, 0x00AE },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_16_singleton_map[44] =
{
  { 0x00A7, 0x00A7 },
  { 0x00A9, 0x00A9 },
  { 0x00AB, 0x00AB },
  { 0x00AD, 0x00AD },
  { 0x00BB, 0x00BB },
  { 0x00C4, 0x00C4 },
  { 0x00D6, 0x00D6 },
  { 0x00E4, 0x00E4 },
  { 0x00F6, 0x00F6 },
  { 0x00FF, 0x00FF },
  { 0x0102, 0x00C3 },
  { 0x0103, 0x00E3 },
  { 0x0106, 0x00C5 },
  { 0x0107, 0x00E5 },
  { 0x010C, 0x00B2 },
  { 0x010D, 0x00B9 },
  { 0x0110, 0x00D0 },
  { 0x0111, 0x00F0 },
  { 0x0118, 0x00DD },
  { 0x0119, 0x00FD },
  { 0x0141, 0x00A3 },
  { 0x0142, 0x00B3 },
  { 0x0143, 0x00D1 },
  { 0x0144, 0x00F1 },
  { 0x0150, 0x00D5 },
  { 0x0151, 0x00F5 },
  { 0x015A, 0x00D7 },
  { 0x015B, 0x00F7 },
  { 0x0160, 0x00A6 },
  { 0x0161, 0x00A8 },
  { 0x0170, 0x00D8 },
  { 0x0171, 0x00F8 },
  { 0x0178, 0x00BE },
  { 0x0179, 0x00AC },
  { 0x017C, 0x00BF },
  { 0x017D, 0x00B4 },
  { 0x017E, 0x00B8 },
  { 0x0218, 0x00AA },
  { 0x0219, 0x00BA },
  { 0x021A, 0x00DE },
  { 0x021B, 0x00FE },
  { 0x201D, 0x00B5 },
  { 0x201E, 0x00A5 },
  { 0x20AC, 0x00A4 },
};
# 3132 "./codesets.c"
static long __SEGGER_RTL_iso8859_16_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_16_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_16(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_16_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_16_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_16_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_16_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_16_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_16_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_16_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_16_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_16_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_16_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_16_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_16(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_16_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_16_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_16(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_16_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_16_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_16(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_16_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_16_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 3233 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_16 =
{
  __SEGGER_RTL_iso8859_16_isctype,
  __SEGGER_RTL_iso8859_16_toupper,
  __SEGGER_RTL_iso8859_16_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_16_wctomb,
  __SEGGER_RTL_iso8859_16_mbtowc
};
# 3252 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_2_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0104, 0x02D8, 0x0141, 0x00A4, 0x013D, 0x015A, 0x00A7,
             0x00A8, 0x0160, 0x015E, 0x0164, 0x0179, 0x00AD, 0x017D, 0x017B,
             0x00B0, 0x0105, 0x02DB, 0x0142, 0x00B4, 0x013E, 0x015B, 0x02C7,
             0x00B8, 0x0161, 0x015F, 0x0165, 0x017A, 0x02DD, 0x017E, 0x017C,
             0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7,
             0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
             0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7,
             0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
             0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7,
             0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
             0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7,
             0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_2_range_map[12] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A7, 0x00A8, 0x00A7 },
  { 0x00C1, 0x00C2, 0x00C1 },
  { 0x00CD, 0x00CE, 0x00CD },
  { 0x00D3, 0x00D4, 0x00D3 },
  { 0x00D6, 0x00D7, 0x00D6 },
  { 0x00DC, 0x00DD, 0x00DC },
  { 0x00E1, 0x00E2, 0x00E1 },
  { 0x00ED, 0x00EE, 0x00ED },
  { 0x00F3, 0x00F4, 0x00F3 },
  { 0x00F6, 0x00F7, 0x00F6 },
  { 0x00FC, 0x00FD, 0x00FC },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_2_singleton_map[73] =
{
  { 0x00A4, 0x00A4 },
  { 0x00AD, 0x00AD },
  { 0x00B0, 0x00B0 },
  { 0x00B4, 0x00B4 },
  { 0x00B8, 0x00B8 },
  { 0x00C4, 0x00C4 },
  { 0x00C7, 0x00C7 },
  { 0x00C9, 0x00C9 },
  { 0x00CB, 0x00CB },
  { 0x00DA, 0x00DA },
  { 0x00DF, 0x00DF },
  { 0x00E4, 0x00E4 },
  { 0x00E7, 0x00E7 },
  { 0x00E9, 0x00E9 },
  { 0x00EB, 0x00EB },
  { 0x00FA, 0x00FA },
  { 0x0102, 0x00C3 },
  { 0x0103, 0x00E3 },
  { 0x0104, 0x00A1 },
  { 0x0105, 0x00B1 },
  { 0x0106, 0x00C6 },
  { 0x0107, 0x00E6 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x010E, 0x00CF },
  { 0x010F, 0x00EF },
  { 0x0110, 0x00D0 },
  { 0x0111, 0x00F0 },
  { 0x0118, 0x00CA },
  { 0x0119, 0x00EA },
  { 0x011A, 0x00CC },
  { 0x011B, 0x00EC },
  { 0x0139, 0x00C5 },
  { 0x013A, 0x00E5 },
  { 0x013D, 0x00A5 },
  { 0x013E, 0x00B5 },
  { 0x0141, 0x00A3 },
  { 0x0142, 0x00B3 },
  { 0x0143, 0x00D1 },
  { 0x0144, 0x00F1 },
  { 0x0147, 0x00D2 },
  { 0x0148, 0x00F2 },
  { 0x0150, 0x00D5 },
  { 0x0151, 0x00F5 },
  { 0x0154, 0x00C0 },
  { 0x0155, 0x00E0 },
  { 0x0158, 0x00D8 },
  { 0x0159, 0x00F8 },
  { 0x015A, 0x00A6 },
  { 0x015B, 0x00B6 },
  { 0x015E, 0x00AA },
  { 0x015F, 0x00BA },
  { 0x0160, 0x00A9 },
  { 0x0161, 0x00B9 },
  { 0x0162, 0x00DE },
  { 0x0163, 0x00FE },
  { 0x0164, 0x00AB },
  { 0x0165, 0x00BB },
  { 0x016E, 0x00D9 },
  { 0x016F, 0x00F9 },
  { 0x0170, 0x00DB },
  { 0x0171, 0x00FB },
  { 0x0179, 0x00AC },
  { 0x017A, 0x00BC },
  { 0x017B, 0x00AF },
  { 0x017C, 0x00BF },
  { 0x017D, 0x00AE },
  { 0x017E, 0x00BE },
  { 0x02C7, 0x00B7 },
  { 0x02D8, 0x00A2 },
  { 0x02D9, 0x00FF },
  { 0x02DB, 0x00B2 },
  { 0x02DD, 0x00BD },
};
# 3377 "./codesets.c"
static long __SEGGER_RTL_iso8859_2_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_2_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_2(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_2_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_2_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_2_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_2_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_2_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_2_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_2_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_2_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_2_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_2_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_2_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_2(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_2_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_2_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_2(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_2_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_2_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_2(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_2_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_2_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 3478 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_2 =
{
  __SEGGER_RTL_iso8859_2_isctype,
  __SEGGER_RTL_iso8859_2_toupper,
  __SEGGER_RTL_iso8859_2_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_2_wctomb,
  __SEGGER_RTL_iso8859_2_mbtowc
};
# 3497 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_3_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0126, 0x02D8, 0x00A3, 0x00A4, 0xDCFF, 0x0124, 0x00A7,
             0x00A8, 0x0130, 0x015E, 0x011E, 0x0134, 0x00AD, 0xDCFF, 0x017B,
             0x00B0, 0x0127, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x0125, 0x00B7,
             0x00B8, 0x0131, 0x015F, 0x011F, 0x0135, 0x00BD, 0xDCFF, 0x017C,
             0x00C0, 0x00C1, 0x00C2, 0xDCFF, 0x00C4, 0x010A, 0x0108, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0xDCFF, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x0120, 0x00D6, 0x00D7,
             0x011C, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x016C, 0x015C, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0xDCFF, 0x00E4, 0x010B, 0x0109, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0xDCFF, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x0121, 0x00F6, 0x00F7,
             0x011D, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x016D, 0x015D, 0x02D9,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_3_range_map[15] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A3, 0x00A4, 0x00A3 },
  { 0x00A7, 0x00A8, 0x00A7 },
  { 0x00B2, 0x00B5, 0x00B2 },
  { 0x00B7, 0x00B8, 0x00B7 },
  { 0x00C0, 0x00C2, 0x00C0 },
  { 0x00C7, 0x00CF, 0x00C7 },
  { 0x00D1, 0x00D4, 0x00D1 },
  { 0x00D6, 0x00D7, 0x00D6 },
  { 0x00D9, 0x00DC, 0x00D9 },
  { 0x00DF, 0x00E2, 0x00DF },
  { 0x00E7, 0x00EF, 0x00E7 },
  { 0x00F1, 0x00F4, 0x00F1 },
  { 0x00F6, 0x00F7, 0x00F6 },
  { 0x00F9, 0x00FC, 0x00F9 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_3_singleton_map[33] =
{
  { 0x00AD, 0x00AD },
  { 0x00B0, 0x00B0 },
  { 0x00BD, 0x00BD },
  { 0x00C4, 0x00C4 },
  { 0x00E4, 0x00E4 },
  { 0x0108, 0x00C6 },
  { 0x0109, 0x00E6 },
  { 0x010A, 0x00C5 },
  { 0x010B, 0x00E5 },
  { 0x011C, 0x00D8 },
  { 0x011D, 0x00F8 },
  { 0x011E, 0x00AB },
  { 0x011F, 0x00BB },
  { 0x0120, 0x00D5 },
  { 0x0121, 0x00F5 },
  { 0x0124, 0x00A6 },
  { 0x0125, 0x00B6 },
  { 0x0126, 0x00A1 },
  { 0x0127, 0x00B1 },
  { 0x0130, 0x00A9 },
  { 0x0131, 0x00B9 },
  { 0x0134, 0x00AC },
  { 0x0135, 0x00BC },
  { 0x015C, 0x00DE },
  { 0x015D, 0x00FE },
  { 0x015E, 0x00AA },
  { 0x015F, 0x00BA },
  { 0x016C, 0x00DD },
  { 0x016D, 0x00FD },
  { 0x017B, 0x00AF },
  { 0x017C, 0x00BF },
  { 0x02D8, 0x00A2 },
  { 0x02D9, 0x00FF },
};
# 3585 "./codesets.c"
static long __SEGGER_RTL_iso8859_3_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_3_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_3(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_3_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_3_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_3_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_3_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_3_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_3_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_3_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_3_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_3_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_3_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_3_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_3(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_3_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_3_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_3(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_3_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_3_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_3(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_3_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_3_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 3686 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_3 =
{
  __SEGGER_RTL_iso8859_3_isctype,
  __SEGGER_RTL_iso8859_3_toupper,
  __SEGGER_RTL_iso8859_3_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_3_wctomb,
  __SEGGER_RTL_iso8859_3_mbtowc
};
# 3705 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_4_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0104, 0x0138, 0x0156, 0x00A4, 0x0128, 0x013B, 0x00A7,
             0x00A8, 0x0160, 0x0112, 0x0122, 0x0166, 0x00AD, 0x017D, 0x00AF,
             0x00B0, 0x0105, 0x02DB, 0x0157, 0x00B4, 0x0129, 0x013C, 0x02C7,
             0x00B8, 0x0161, 0x0113, 0x0123, 0x0167, 0x014A, 0x017E, 0x014B,
             0x0100, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x012E,
             0x010C, 0x00C9, 0x0118, 0x00CB, 0x0116, 0x00CD, 0x00CE, 0x012A,
             0x0110, 0x0145, 0x014C, 0x0136, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x0172, 0x00DA, 0x00DB, 0x00DC, 0x0168, 0x016A, 0x00DF,
             0x0101, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x012F,
             0x010D, 0x00E9, 0x0119, 0x00EB, 0x0117, 0x00ED, 0x00EE, 0x012B,
             0x0111, 0x0146, 0x014D, 0x0137, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x0173, 0x00FA, 0x00FB, 0x00FC, 0x0169, 0x016B, 0x02D9,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_4_range_map[11] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A7, 0x00A8, 0x00A7 },
  { 0x00AF, 0x00B0, 0x00AF },
  { 0x00C1, 0x00C6, 0x00C1 },
  { 0x00CD, 0x00CE, 0x00CD },
  { 0x00D4, 0x00D8, 0x00D4 },
  { 0x00DA, 0x00DC, 0x00DA },
  { 0x00E1, 0x00E6, 0x00E1 },
  { 0x00ED, 0x00EE, 0x00ED },
  { 0x00F4, 0x00F8, 0x00F4 },
  { 0x00FA, 0x00FC, 0x00FA },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_4_singleton_map[59] =
{
  { 0x00A4, 0x00A4 },
  { 0x00AD, 0x00AD },
  { 0x00B4, 0x00B4 },
  { 0x00B8, 0x00B8 },
  { 0x00C9, 0x00C9 },
  { 0x00CB, 0x00CB },
  { 0x00DF, 0x00DF },
  { 0x00E9, 0x00E9 },
  { 0x00EB, 0x00EB },
  { 0x0100, 0x00C0 },
  { 0x0101, 0x00E0 },
  { 0x0104, 0x00A1 },
  { 0x0105, 0x00B1 },
  { 0x010C, 0x00C8 },
  { 0x010D, 0x00E8 },
  { 0x0110, 0x00D0 },
  { 0x0111, 0x00F0 },
  { 0x0112, 0x00AA },
  { 0x0113, 0x00BA },
  { 0x0116, 0x00CC },
  { 0x0117, 0x00EC },
  { 0x0118, 0x00CA },
  { 0x0119, 0x00EA },
  { 0x0122, 0x00AB },
  { 0x0123, 0x00BB },
  { 0x0128, 0x00A5 },
  { 0x0129, 0x00B5 },
  { 0x012A, 0x00CF },
  { 0x012B, 0x00EF },
  { 0x012E, 0x00C7 },
  { 0x012F, 0x00E7 },
  { 0x0136, 0x00D3 },
  { 0x0137, 0x00F3 },
  { 0x0138, 0x00A2 },
  { 0x013B, 0x00A6 },
  { 0x013C, 0x00B6 },
  { 0x0145, 0x00D1 },
  { 0x0146, 0x00F1 },
  { 0x014A, 0x00BD },
  { 0x014B, 0x00BF },
  { 0x014C, 0x00D2 },
  { 0x014D, 0x00F2 },
  { 0x0156, 0x00A3 },
  { 0x0157, 0x00B3 },
  { 0x0160, 0x00A9 },
  { 0x0161, 0x00B9 },
  { 0x0166, 0x00AC },
  { 0x0167, 0x00BC },
  { 0x0168, 0x00DD },
  { 0x0169, 0x00FD },
  { 0x016A, 0x00DE },
  { 0x016B, 0x00FE },
  { 0x0172, 0x00D9 },
  { 0x0173, 0x00F9 },
  { 0x017D, 0x00AE },
  { 0x017E, 0x00BE },
  { 0x02C7, 0x00B7 },
  { 0x02D9, 0x00FF },
  { 0x02DB, 0x00B2 },
};
# 3815 "./codesets.c"
static long __SEGGER_RTL_iso8859_4_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_4_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_4(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_4_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_4_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_4_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_4_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_4_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_4_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_4_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_4_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_4_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_4_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_4_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_4(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_4_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_4_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_4(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_4_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_4_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_4(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_4_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_4_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 3916 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_4 =
{
  __SEGGER_RTL_iso8859_4_isctype,
  __SEGGER_RTL_iso8859_4_toupper,
  __SEGGER_RTL_iso8859_4_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_4_wctomb,
  __SEGGER_RTL_iso8859_4_mbtowc
};
# 3935 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_5_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x0401, 0x0402, 0x0403, 0x0404, 0x0405, 0x0406, 0x0407,
             0x0408, 0x0409, 0x040A, 0x040B, 0x040C, 0x00AD, 0x040E, 0x040F,
             0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
             0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
             0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
             0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
             0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
             0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
             0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
             0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F,
             0x2116, 0x0451, 0x0452, 0x0453, 0x0454, 0x0455, 0x0456, 0x0457,
             0x0458, 0x0459, 0x045A, 0x045B, 0x045C, 0x00A7, 0x045E, 0x045F,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_5_range_map[5] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x0401, 0x040C, 0x00A1 },
  { 0x040E, 0x044F, 0x00AE },
  { 0x0451, 0x045C, 0x00F1 },
  { 0x045E, 0x045F, 0x00FE },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_5_singleton_map[3] =
{
  { 0x00A7, 0x00FD },
  { 0x00AD, 0x00AD },
  { 0x2116, 0x00F0 },
};
# 3983 "./codesets.c"
static long __SEGGER_RTL_iso8859_5_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_5_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_5(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_5_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_5_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_5_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_5_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_5_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_5_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_5_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_5_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_5_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_5_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_5_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_5(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_5_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_5_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_5(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_5_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_5_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_5(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_5_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_5_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 4084 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_5 =
{
  __SEGGER_RTL_iso8859_5_isctype,
  __SEGGER_RTL_iso8859_5_toupper,
  __SEGGER_RTL_iso8859_5_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_5_wctomb,
  __SEGGER_RTL_iso8859_5_mbtowc
};
# 4103 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_6_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0xDCFF, 0xDCFF, 0xDCFF, 0x00A4, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0x060C, 0x00AD, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0x061B, 0xDCFF, 0xDCFF, 0xDCFF, 0x061F,
             0xDCFF, 0x0621, 0x0622, 0x0623, 0x0624, 0x0625, 0x0626, 0x0627,
             0x0628, 0x0629, 0x062A, 0x062B, 0x062C, 0x062D, 0x062E, 0x062F,
             0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, 0x0636, 0x0637,
             0x0638, 0x0639, 0x063A, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0x0640, 0x0641, 0x0642, 0x0643, 0x0644, 0x0645, 0x0646, 0x0647,
             0x0648, 0x0649, 0x064A, 0x064B, 0x064C, 0x064D, 0x064E, 0x064F,
             0x0650, 0x0651, 0x0652, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_6_range_map[3] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x0621, 0x063A, 0x00C1 },
  { 0x0640, 0x0652, 0x00E0 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_6_singleton_map[5] =
{
  { 0x00A4, 0x00A4 },
  { 0x00AD, 0x00AD },
  { 0x060C, 0x00AC },
  { 0x061B, 0x00BB },
  { 0x061F, 0x00BF },
};
# 4151 "./codesets.c"
static long __SEGGER_RTL_iso8859_6_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_6_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_6(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_6_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_6_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_6_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_6_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_6_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_6_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_6_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_6_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_6_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_6_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_6_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_6(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_6_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_6_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_6(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_6_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_6_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_6(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_6_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_6_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 4252 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_6 =
{
  __SEGGER_RTL_iso8859_6_isctype,
  __SEGGER_RTL_iso8859_6_toupper,
  __SEGGER_RTL_iso8859_6_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_6_wctomb,
  __SEGGER_RTL_iso8859_6_mbtowc
};
# 4271 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_7_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x2018, 0x2019, 0x00A3, 0x20AC, 0x20AF, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x037A, 0x00AB, 0x00AC, 0x00AD, 0xDCFF, 0x2015,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x0384, 0x0385, 0x0386, 0x00B7,
             0x0388, 0x0389, 0x038A, 0x00BB, 0x038C, 0x00BD, 0x038E, 0x038F,
             0x0390, 0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397,
             0x0398, 0x0399, 0x039A, 0x039B, 0x039C, 0x039D, 0x039E, 0x039F,
             0x03A0, 0x03A1, 0xDCFF, 0x03A3, 0x03A4, 0x03A5, 0x03A6, 0x03A7,
             0x03A8, 0x03A9, 0x03AA, 0x03AB, 0x03AC, 0x03AD, 0x03AE, 0x03AF,
             0x03B0, 0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7,
             0x03B8, 0x03B9, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BE, 0x03BF,
             0x03C0, 0x03C1, 0x03C2, 0x03C3, 0x03C4, 0x03C5, 0x03C6, 0x03C7,
             0x03C8, 0x03C9, 0x03CA, 0x03CB, 0x03CC, 0x03CD, 0x03CE, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_7_range_map[9] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A6, 0x00A9, 0x00A6 },
  { 0x00AB, 0x00AD, 0x00AB },
  { 0x00B0, 0x00B3, 0x00B0 },
  { 0x0384, 0x0386, 0x00B4 },
  { 0x0388, 0x038A, 0x00B8 },
  { 0x038E, 0x03A1, 0x00BE },
  { 0x03A3, 0x03CE, 0x00D3 },
  { 0x2018, 0x2019, 0x00A1 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_7_singleton_map[9] =
{
  { 0x00A3, 0x00A3 },
  { 0x00B7, 0x00B7 },
  { 0x00BB, 0x00BB },
  { 0x00BD, 0x00BD },
  { 0x037A, 0x00AA },
  { 0x038C, 0x00BC },
  { 0x2015, 0x00AF },
  { 0x20AC, 0x00A4 },
  { 0x20AF, 0x00A5 },
};
# 4329 "./codesets.c"
static long __SEGGER_RTL_iso8859_7_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_7_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_7(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_7_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_7_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_7_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_7_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_7_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_7_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_7_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_7_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_7_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_7_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_7_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_7(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_7_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_7_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_7(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_7_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_7_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_7(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_7_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_7_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 4430 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_7 =
{
  __SEGGER_RTL_iso8859_7_isctype,
  __SEGGER_RTL_iso8859_7_toupper,
  __SEGGER_RTL_iso8859_7_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_7_wctomb,
  __SEGGER_RTL_iso8859_7_mbtowc
};
# 4449 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_8_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0xDCFF, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00D7, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00F7, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF,
             0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0xDCFF, 0x2017,
             0x05D0, 0x05D1, 0x05D2, 0x05D3, 0x05D4, 0x05D5, 0x05D6, 0x05D7,
             0x05D8, 0x05D9, 0x05DA, 0x05DB, 0x05DC, 0x05DD, 0x05DE, 0x05DF,
             0x05E0, 0x05E1, 0x05E2, 0x05E3, 0x05E4, 0x05E5, 0x05E6, 0x05E7,
             0x05E8, 0x05E9, 0x05EA, 0xDCFF, 0xDCFF, 0x200E, 0x200F, 0xDCFF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_8_range_map[6] =
{
  { 0x0080, 0x00A0, 0x0080 },
  { 0x00A2, 0x00A9, 0x00A2 },
  { 0x00AB, 0x00B9, 0x00AB },
  { 0x00BB, 0x00BE, 0x00BB },
  { 0x05D0, 0x05EA, 0x00E0 },
  { 0x200E, 0x200F, 0x00FD },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_8_singleton_map[3] =
{
  { 0x00D7, 0x00AA },
  { 0x00F7, 0x00BA },
  { 0x2017, 0x00DF },
};
# 4498 "./codesets.c"
static long __SEGGER_RTL_iso8859_8_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_8_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_8(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_8_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_8_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_8_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_8_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_8_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_8_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_8_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_8_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_8_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_8_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_8_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_8(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_8_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_8_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_8(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_8_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_8_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_8(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_8_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_8_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 4599 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_8 =
{
  __SEGGER_RTL_iso8859_8_isctype,
  __SEGGER_RTL_iso8859_8_toupper,
  __SEGGER_RTL_iso8859_8_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_8_wctomb,
  __SEGGER_RTL_iso8859_8_mbtowc
};
# 4618 "./codesets.c"
static const unsigned short __SEGGER_RTL_iso8859_9_to_unicode_map[] =
{
             0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
             0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
             0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097,
             0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
             0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
             0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
             0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
             0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
             0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
             0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
             0x011E, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
             0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x0130, 0x015E, 0x00DF,
             0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
             0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
             0x011F, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
             0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x0131, 0x015F, 0x00FF,
};

static const __SEGGER_RTL_unicode_map_bmp_range_t __SEGGER_RTL_unicode_to_iso8859_9_range_map[4] =
{
  { 0x0080, 0x00CF, 0x0080 },
  { 0x00D1, 0x00DC, 0x00D1 },
  { 0x00DF, 0x00EF, 0x00DF },
  { 0x00F1, 0x00FC, 0x00F1 },
};

static const __SEGGER_RTL_unicode_map_bmp_singleton_t __SEGGER_RTL_unicode_to_iso8859_9_singleton_map[7] =
{
  { 0x00FF, 0x00FF },
  { 0x011E, 0x00D0 },
  { 0x011F, 0x00F0 },
  { 0x0130, 0x00DD },
  { 0x0131, 0x00FD },
  { 0x015E, 0x00DE },
  { 0x015F, 0x00FE },
};
# 4669 "./codesets.c"
static long __SEGGER_RTL_iso8859_9_to_unicode(int ch) {
  if (ch == EOF) return WEOF;
  if ((unsigned)ch < 0x80) return ch;
  return __SEGGER_RTL_iso8859_9_to_unicode_map[(ch & 0xFF) - 0x80];
}






static int __SEGGER_RTL_unicode_to_iso8859_9(long ch) {
  const __SEGGER_RTL_unicode_map_bmp_range_t *cursor_0;
  const __SEGGER_RTL_unicode_map_bmp_singleton_t *cursor_1;

  if (ch == WEOF) return EOF;
  if ((unsigned long)ch <= 0x7F) return (int)ch;

  cursor_0 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_9_range_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_9_range_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_9_range_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_9_range_map[0]),
                     __SEGGER_RTL_unicode_map_range_search);
  if (cursor_0) return ch - cursor_0->min + cursor_0->map;

  cursor_1 = bsearch(&ch,
                     __SEGGER_RTL_unicode_to_iso8859_9_singleton_map,
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_9_singleton_map) / sizeof(__SEGGER_RTL_unicode_to_iso8859_9_singleton_map[0]),
                     sizeof(__SEGGER_RTL_unicode_to_iso8859_9_singleton_map[0]),
                     __SEGGER_RTL_unicode_map_singleton_search);
  if (cursor_1) return cursor_1->map;
  return EOF;
}






static int __SEGGER_RTL_iso8859_9_isctype(int ch, int type) {
  return __SEGGER_RTL_unicode_iswctype(__SEGGER_RTL_iso8859_9_to_unicode(ch), type);
}






static int __SEGGER_RTL_iso8859_9_toupper(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_9(__SEGGER_RTL_unicode_towupper(__SEGGER_RTL_iso8859_9_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_9_tolower(int ch) {
  long cp = __SEGGER_RTL_unicode_to_iso8859_9(__SEGGER_RTL_unicode_towlower(__SEGGER_RTL_iso8859_9_to_unicode(ch)));
  return cp == WEOF ? ch : cp;
}






static int __SEGGER_RTL_iso8859_9_wctomb(char *s, wchar_t wc, struct __mbstate_s *mbstate) {
  int nch = __SEGGER_RTL_unicode_to_iso8859_9(wc);

  __SEGGER_RTL_USE_PARA(mbstate);

  if (nch == EOF)
    return -EILSEQ;
  s[0] = (char)nch;
  return 1;
}






static int __SEGGER_RTL_iso8859_9_mbtowc(wchar_t *pwc, const char *s, size_t n, struct __mbstate_s *state) {

  __SEGGER_RTL_USE_PARA(state);

  if (n <= 0) return -2;
  pwc[0] = __SEGGER_RTL_iso8859_9_to_unicode(s[0]);
  if (pwc[0] == (wchar_t)0xDCFF) return -EILSEQ;
  return 1;
}
# 4770 "./codesets.c"
const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_9 =
{
  __SEGGER_RTL_iso8859_9_isctype,
  __SEGGER_RTL_iso8859_9_toupper,
  __SEGGER_RTL_iso8859_9_tolower,
  __SEGGER_RTL_unicode_iswctype,
  __SEGGER_RTL_unicode_towupper,
  __SEGGER_RTL_unicode_towlower,
  __SEGGER_RTL_iso8859_9_wctomb,
  __SEGGER_RTL_iso8859_9_mbtowc
};
