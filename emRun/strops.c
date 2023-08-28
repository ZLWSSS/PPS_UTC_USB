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
# 1 "./strops.c"
# 17 "./strops.c"
#include "__SEGGER_RTL_Int.h"
#include "ctype.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
# 31 "./strops.c"
typedef __SEGGER_RTL_UNALIGNED_ATTR __SEGGER_RTL_WORD __SEGGER_RTL_UNALIGNED_WORD;
# 40 "./strops.c"
static __SEGGER_RTL_STATE_THREAD char *__SEGGER_RTL_strtok_state;
# 49 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE int __SEGGER_RTL_Overlaps(const void *s1, const void *s2, size_t n) {
  intptr_t i1;
  intptr_t i2;

  if (n == 0) {
    return 0;
  }

  i1 = (intptr_t)s1;
  i2 = (intptr_t)s2;
  if (i1 < i2) {
    return i1+(intptr_t)n <= i2;
  } else {
    return i2+(intptr_t)n <= i1;
  }
}
# 86 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE void __SEGGER_RTL_memcpy_forward(void *s1, const void *s2, size_t n) {

#if __SEGGER_RTL_OPTIMIZE >= 0

  char * b1 = s1;
  const char * b2 = s2;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;



  if (__SEGGER_RTL_ALIGN_REM(b1) == __SEGGER_RTL_ALIGN_REM(b2)) {



    while (__SEGGER_RTL_ALIGN_REM(b1) != 0 && n > 0) {
      *b1++ = *b2++;
      --n;
    }



    w1 = ( __SEGGER_RTL_WORD *)b1;
    w2 = (const __SEGGER_RTL_WORD *)b2;



#if __SEGGER_RTL_OPTIMIZE >= 2
    while (n >= 4*sizeof(Word)) {
      *w1++ = *w2++;
      *w1++ = *w2++;
      *w1++ = *w2++;
      *w1++ = *w2++;
      n -= 4*sizeof(Word);
    }
#endif
    while (n >= sizeof(Word)) {
      *w1++ = *w2++;
      n -= sizeof(Word);
    }

    b1 = (char *)w1;
    b2 = (const char *)w2;

    while (n--) {
      *b1++ = *b2++;
    }
  } else {



    while (n > 0 && __SEGGER_RTL_ALIGN_REM(b2) != 0) {
      *b1++ = *b2++;
      --n;
    }



    w2 = (const __SEGGER_RTL_WORD *)b2;



#if __SEGGER_RTL_OPTIMIZE >= 2
    while (n >= 4*sizeof(Word)) {
      __SEGGER_RTL_WR_WORD(b1, *w2++); b1 += sizeof(Word);
      __SEGGER_RTL_WR_WORD(b1, *w2++); b1 += sizeof(Word);
      __SEGGER_RTL_WR_WORD(b1, *w2++); b1 += sizeof(Word);
      __SEGGER_RTL_WR_WORD(b1, *w2++); b1 += sizeof(Word);
      n -= 4*sizeof(Word);
    }
#endif
    while (n >= sizeof(Word)) {
      __SEGGER_RTL_WR_WORD(b1, *w2++); b1 += sizeof(Word);
      n -= sizeof(Word);
    }

    b2 = (const char *)w2;

    while (n--) {
      *b1++ = *b2++;
    }
  }

#else

  unsigned char *b1 = s1;
  const unsigned char *b2 = s2;

  while (n--) {
    *b1++ = *b2++;
  }

#endif
}
# 205 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE void __SEGGER_RTL_memcpy_backward(void *s1, const void *s2, size_t n) {

#if __SEGGER_RTL_OPTIMIZE >= 0

  char * b1 = s1;
  const char * b2 = s2;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;



  if (__SEGGER_RTL_ALIGN_REM(b1) == __SEGGER_RTL_ALIGN_REM(b2)) {



    while (__SEGGER_RTL_ALIGN_REM(b1) != 0 && n > 0) {
      *--b1 = *--b2;
      --n;
    }



    w1 = ( __SEGGER_RTL_WORD *)b1;
    w2 = (const __SEGGER_RTL_WORD *)b2;



#if __SEGGER_RTL_OPTIMIZE >= 2
    while (n >= 4*sizeof(Word)) {
      *--w1 = *--w2;
      *--w1 = *--w2;
      *--w1 = *--w2;
      *--w1 = *--w2;
      n -= 4*sizeof(Word);
    }
#endif
    while (n >= sizeof(Word)) {
      *--w1 = *--w2;
      n -= sizeof(Word);
    }

    b1 = (char *)w1;
    b2 = (const char *)w2;

    while (n--) {
      *--b1 = *--b2;
    }
  } else {



    while (n > 0 && __SEGGER_RTL_ALIGN_REM(b2) != 0) {
      *--b1 = *--b2;
      --n;
    }



    w2 = (const __SEGGER_RTL_WORD *)b2;



#if __SEGGER_RTL_OPTIMIZE >= 2
    while (n >= 4*sizeof(Word)) {
      b1 -= sizeof(Word); __SEGGER_RTL_WR_WORD(b1, *--w2);
      b1 -= sizeof(Word); __SEGGER_RTL_WR_WORD(b1, *--w2);
      b1 -= sizeof(Word); __SEGGER_RTL_WR_WORD(b1, *--w2);
      b1 -= sizeof(Word); __SEGGER_RTL_WR_WORD(b1, *--w2);
      n -= 4*sizeof(Word);
    }
#endif
    while (n >= sizeof(Word)) {
      b1 -= sizeof(Word); __SEGGER_RTL_WR_WORD(b1, *--w2);
      n -= sizeof(Word);
    }

    b2 = (const char *)w2;

    while (n--) {
      *--b1 = *--b2;
    }
  }

#else

  unsigned char *b1 = s1;
  const unsigned char *b2 = s2;

  while (n--) {
    *--b1 = *--b2;
  }

#endif
}
# 324 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE __SEGGER_RTL_NO_BUILTIN void * __SEGGER_RTL_memcpy_inline(void *s1, const void *s2, size_t n) {
  __SEGGER_RTL_memcpy_forward(s1, s2, n);
  return s1;
}
# 351 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE __SEGGER_RTL_NO_BUILTIN void * __SEGGER_RTL_memmove_inline(void *s1, const void *s2, size_t n) {
  if (s1 < s2) {
    __SEGGER_RTL_memcpy_forward(s1, s2, n);
  } else if (s1 > s2) {
    __SEGGER_RTL_memcpy_backward((char *)s1 + n, (const char *)s2 + n, n);
  }
  return s1;
}
# 376 "./strops.c"
static __SEGGER_RTL_ALWAYS_INLINE __SEGGER_RTL_NO_BUILTIN void * __SEGGER_RTL_memset_inline(void *s, int c, size_t n) {

#if __SEGGER_RTL_OPTIMIZE >= 0

  char * uc;
  __SEGGER_RTL_UNALIGNED_WORD * w1;
  __SEGGER_RTL_WORD Word;
  unsigned Lead;



  if (n == 0) {
    return s;
  }

  uc = (char *)s;
  Word = __SEGGER_RTL_BYTE_PATTERN((unsigned char)c);



  if (__SEGGER_RTL_ALIGN_REM(uc) != 0) {
    Lead = sizeof(Word) - __SEGGER_RTL_ALIGN_REM(uc);
    if (Lead > n) {
      Lead = n;
    }
    __SEGGER_RTL_WR_PARTIAL_WORD(uc, Word, Lead);
    uc += Lead;
    n -= Lead;
  }



  w1 = (__SEGGER_RTL_UNALIGNED_WORD *)uc;
#if __SEGGER_RTL_OPTIMIZE >= 2
  while (n >= 4*sizeof(Word)) {
    *w1++ = Word;
    *w1++ = Word;
    *w1++ = Word;
    *w1++ = Word;
    n -= 4*sizeof(Word);
  }
#endif
  while (n >= sizeof(Word)) {
    *w1++ = Word;
    n -= sizeof(Word);
  }



  if (n > 0) {
    __SEGGER_RTL_WR_PARTIAL_WORD((char *)w1, Word, n);
  }

#else

  unsigned char *ucdst = s;



  while (n--) {
    *ucdst++ = (unsigned char)c;
  }

#endif



  return s;
}
# 480 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API memmove(void *s1, const void *s2, size_t n) {
  return __SEGGER_RTL_memmove_inline(s1, s2, n);
}
# 528 "./strops.c"
errno_t __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN memmove_s(void *s1, size_t s1max, const void *s2, size_t n) {
  const char *msg;



  if (s1 == NULL) { msg = "memmove_s(s1, s1max, s2, n) with s1=NULL"; }
  else if (s2 == NULL) { msg = "memmove_s(s1, s1max, s2, n) with s2=NULL"; }
  else if (s1max > RSIZE_MAX) { msg = "memmove_s(s1, s1max, s2, n) with s1max > RSIZE_MAX"; }
  else if (n > s1max) { msg = "memmove_s(s1, s1max, s2, n) with n > s1max"; }
  else { msg = NULL; }

  if (msg == NULL) {
    (memmove)(s1, s2, n);
    return 0;
  } else {
    if (s1 != NULL && s1max <= RSIZE_MAX) {
      (memset)(s1, 0, s1max);
    }
    __SEGGER_RTL_constraint_violation(msg, NULL, EINVAL);
    return EINVAL;
  }
}
# 578 "./strops.c"
int __SEGGER_RTL_PUBLIC_API memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char * u1;
  const unsigned char * u2;
#if __SEGGER_RTL_OPTIMIZE >= 0
  unsigned DiffIndex;
#endif

  u1 = (const unsigned char *)s1;
  u2 = (const unsigned char *)s2;

#if __SEGGER_RTL_OPTIMIZE >= 0

  const __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;



  if (__SEGGER_RTL_ALIGN_REM(u1) == __SEGGER_RTL_ALIGN_REM(u2)) {



    for (;;) {
      if (__SEGGER_RTL_ALIGN_REM(u1) == 0) { break; }
      if (n == 0) { return 0; }
      if (*u1 != *u2) { return *u1 - *u2; }
      ++u1;
      ++u2;
      --n;
    }

    w1 = (const __SEGGER_RTL_WORD *)u1;
    w2 = (const __SEGGER_RTL_WORD *)u2;

#if __SEGGER_RTL_OPTIMIZE >= 2

    while (n >= 4*sizeof(__SEGGER_RTL_WORD)) {
      if (__SEGGER_RTL_UNLIKELY(w1[0] != w2[0])) { break; }
      if (__SEGGER_RTL_UNLIKELY(w1[1] != w2[1])) { w1 += 1; w2 += 1; n -= 1*sizeof(__SEGGER_RTL_WORD); break; }
      if (__SEGGER_RTL_UNLIKELY(w1[2] != w2[2])) { w1 += 2; w2 += 2; n -= 2*sizeof(__SEGGER_RTL_WORD); break; }
      if (__SEGGER_RTL_UNLIKELY(w1[3] != w2[3])) { w1 += 3; w2 += 3; n -= 3*sizeof(__SEGGER_RTL_WORD); break; }
      w1 += 4;
      w2 += 4;
      n -= 4*sizeof(__SEGGER_RTL_WORD);
    }

#endif

    while (n >= sizeof(__SEGGER_RTL_WORD) && *w1 == *w2) {
      ++w1;
      ++w2;
      n -= sizeof(__SEGGER_RTL_WORD);
    }





    if (n == 0) {
      return 0;
    }

    DiffIndex = __SEGGER_RTL_DIFF_INDEX(*w1, *w2);
    if (DiffIndex >= n) {
      return 0;
    }
    return __SEGGER_RTL_DIFF_BYTE(*w1, DiffIndex) - __SEGGER_RTL_DIFF_BYTE(*w2, DiffIndex);

  } else {



    for (;;) {
      if (__SEGGER_RTL_ALIGN_REM(u1) == 0) { break; }
      if (n == 0) { return 0; }
      if (*u1 != *u2) { return *u1 - *u2; }
      ++u1;
      ++u2;
      --n;
    }



    w1 = (const __SEGGER_RTL_WORD *)u1;

    while (n >= sizeof(__SEGGER_RTL_WORD) && *w1 == __SEGGER_RTL_RD_WORD(u2)) {
      w1 += 1;
      u2 += sizeof(__SEGGER_RTL_WORD);
      n -= sizeof(__SEGGER_RTL_WORD);
    }

    if (n == 0) {
      return 0;
    }

    u1 = (const unsigned char *)w1;
  }

  while (--n && *u1 == *u2) {
    ++u1;
    ++u2;
  }



  return *u1 - *u2;

#else



  if (n == 0) {
    return 0;
  }



  while (--n && *u1 == *u2) {
    ++u1;
    ++u2;
  }



  return *u1 - *u2;

#endif
}
# 726 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API memlcp(const void *s1, const void *s2, size_t n) {
  const unsigned char * u1;
  const unsigned char * u2;
  const unsigned char * origin;

  origin = (const unsigned char *)s1;
  u1 = (const unsigned char *)s1;
  u2 = (const unsigned char *)s2;

#if __SEGGER_RTL_OPTIMIZE >= 0

  const __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;



  if (__SEGGER_RTL_ALIGN_REM(u1) == __SEGGER_RTL_ALIGN_REM(u2)) {



    while (__SEGGER_RTL_ALIGN_REM(u1) != 0 && n > 0 && *u1 == *u2) {
      ++u1;
      ++u2;
      --n;
    }

    if (n == 0) {
      return u1 - origin;
    }

    w1 = (const __SEGGER_RTL_WORD *)u1;
    w2 = (const __SEGGER_RTL_WORD *)u2;

    for (;;) {
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
#if __SEGGER_RTL_OPTIMIZE >= 2
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
#endif
    }

    u1 = (const unsigned char *)w1;
    u2 = (const unsigned char *)w2;

    if (n == 0) {
      return u1 - origin;
    }

  } else {



    while (__SEGGER_RTL_ALIGN_REM(u1) != 0 && n > 0 && *u1 == *u2) {
      ++u1;
      ++u2;
      --n;
    }

    if (n == 0) {
      return u1 - origin;
    }



    w1 = (const __SEGGER_RTL_WORD *)u1;

    while (n >= sizeof(__SEGGER_RTL_WORD) && *w1 == __SEGGER_RTL_RD_WORD(u2)) {
      ++w1;
      u2 += sizeof(__SEGGER_RTL_WORD);
      n -= sizeof(__SEGGER_RTL_WORD);
    }

    u1 = (const unsigned char *)w1;

    if (n == 0) {
      return u1 - origin;
    }
  }

  while (--n && *u1 == *u2) {
    ++u1;
    ++u2;
  }



  return u1 - origin;

#else



  if (n == 0) {
    return 0;
  }



  while (--n && *u1 == *u2) {
    ++u1;
    ++u2;
  }



  return u1 - origin;

#endif
}
# 863 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API memchr(const void *s, int c, size_t n) {
  const unsigned char * s0;

  c &= 0xFF;

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)



  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD Pattern;
  unsigned Index;



  if (n == 0) {
    return NULL;
  }

  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  n += __SEGGER_RTL_ALIGN_REM(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, c^1);
  Pattern = __SEGGER_RTL_BYTE_PATTERN(c);



#if __SEGGER_RTL_OPTIMIZE >= 2
  while (n >= 4 * sizeof(Word)) {
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0)) { Word = *++pWord; } else { break; }
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0)) { Word = *++pWord; } else { n -= 1*sizeof(Word); break; }
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0)) { Word = *++pWord; } else { n -= 2*sizeof(Word); break; }
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0)) { Word = *++pWord; } else { n -= 3*sizeof(Word); break; }
    n -= 4*sizeof(Word);
  }
#endif
  for (;;) {
    if (__SEGGER_RTL_LIKELY(n >= sizeof(Word) && __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0)) { Word = *++pWord; n -= sizeof(Word); } else { break; }
  }




  Index = __SEGGER_RTL_ZBYTE_INDEX(Word ^ Pattern);



  return __SEGGER_RTL_LIKELY(Index < n) ? (char *)pWord + Index : NULL;

#endif

  s0 = s;
#if __SEGGER_RTL_OPTIMIZE >= 0
  while (n >= 4) {
    if (s0[0] == c) return (char *)s0;
    if (s0[1] == c) return (char *)s0+1;
    if (s0[2] == c) return (char *)s0+2;
    if (s0[3] == c) return (char *)s0+3;
    s0 += 4;
    n -= 4;
  }
#endif
  while (n && *s0 != c) {
    ++s0;
    --n;
  }

  return n ? (void *)s0 : NULL;
}
# 959 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API memrchr(const void *s, int c, size_t n) {
  const char *us;



  us = s;
  us += n;
  while (--us != s && *us != (char)c) {

  }



  return *us == (char)c ? (char *)us : 0;
}
# 998 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN memcpy(void *s1, const void *s2, size_t n) {
  __SEGGER_RTL_memcpy_forward(s1, s2, n);
  return s1;
}
# 1043 "./strops.c"
errno_t __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN memcpy_s(void *s1, size_t s1max, const void *s2, size_t n) {
  const char *msg;



  if (s1 == NULL) { msg = "memcpy_s(s1, s1max, s2, n) with s1=NULL"; }
  else if (s2 == NULL) { msg = "memcpy_s(s1, s1max, s2, n) with s2=NULL"; }
  else if (s1max > RSIZE_MAX) { msg = "memcpy_s(s1, s1max, s2, n) with s1max > RSIZE_MAX"; }
  else if (n > RSIZE_MAX) { msg = "memcpy_s(s1, s1max, s2, n) with n > RSIZE_MAX"; }
  else if (n > s1max) { msg = "memcpy_s(s1, s1max, s2, n) with n > s1max"; }
  else if (__SEGGER_RTL_Overlaps(s1, s2, n)) { msg = "memcpy_s(s1, s1max, s2, n) with s1 overlapping s2"; }
  else { msg = NULL; }

  if (msg == NULL) {
    (memcpy)(s1, s2, n);
    return 0;
  } else {
    if (s1 != NULL && s1max <= RSIZE_MAX) {
      (memset)(s1, 0, s1max);
    }
    __SEGGER_RTL_constraint_violation(msg, NULL, EINVAL);
    return EINVAL;
  }
}
# 1095 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API mempcpy(void *s1, const void *s2, size_t n) {
  return (char *)(memcpy)(s1, s2, n) + n;
}
# 1126 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API memmem(const void *s1, size_t n1, const void *s2, size_t n2) {
  const char * begin;
  const char * extent;
  int c;



  if (n2 == 0) {
    return (void *)s1;
  } else if (n1 < n2) {
    return 0;
  }

  extent = (const char *)s1 + n1 - n2;
  c = *(const char *)s2;

  for (begin = s1; begin <= extent; ++begin) {
    if (*begin == c && memcmp(begin, s2, n2) == 0) {
      return (void *)begin;
    }
  }

  return 0;
}
# 1183 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API memccpy(void *s1, const void *s2, int c, size_t n) {
  unsigned char *ucdst;
  const unsigned char *ucsrc;

  ucdst = s1;
  ucsrc = s2;
  while (n && (*ucdst++ = *ucsrc++) != (unsigned char)c) {
    --n;
  }

  return n ? ucdst : 0;
}
# 1218 "./strops.c"
void * __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN memset(void *s, int c, size_t n) {
  __SEGGER_RTL_memset_inline(s, c, n);
  return s;
}
# 1263 "./strops.c"
errno_t __SEGGER_RTL_PUBLIC_API memset_s(void *s, size_t smax, int c, size_t n) {
  char *msg;



  if (s == NULL) { msg = "memset(s, smax, c, n) with s=NULL"; }
  else if (smax > RSIZE_MAX) { msg = "memset(s, smax, c, n) with smax > RSIZE_MAX"; }
  else if (n > RSIZE_MAX) { msg = "memset(s, smax, c, n) with n > RSIZE_MAX"; }
  else if (n > smax) { msg = "memset(s, smax, c, n) with n > smax"; }
  else { msg = NULL; }

  if (msg == NULL) {
    (memset)(s, c, n);
    return 0;
  } else {
    if (s != NULL && smax <= RSIZE_MAX) {
      (memset)(s, c, smax);
    }
    __SEGGER_RTL_constraint_violation(msg, NULL, EINVAL);
    return EINVAL;
  }
}
# 1316 "./strops.c"
int __SEGGER_RTL_PUBLIC_API strcasecmp(const char *s1, const char *s2) {
  int ret;

  while ((ret = tolower(*s1) - tolower(*s2)) == 0 && *s2) {
    ++s1;
    ++s2;
  }

  return ret;
}
# 1359 "./strops.c"
int __SEGGER_RTL_PUBLIC_API strncasecmp(const char *s1, const char *s2, size_t n) {



  if (n == 0) {
    return 0;
  }



  while (--n && *s1 && tolower(*s1) == tolower(*s2)) {
    ++s1;
    ++s2;
  }



  return tolower(*s1) - tolower(*s2);
}
# 1406 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strcasestr(const char *s1, const char *s2) {
  const char *p = s1;

  if (*s2 == 0) {
    return (char *)p;
  }

  while (*p) {
    const char *xs1 = p;
    const char *xs2 = s2;

    while (*xs1 && *xs2 && toupper(*xs1) == toupper(*xs2)) {
      ++xs1, ++xs2;
    }

    if (*xs2 == 0) {
      return (char *)p;
    }
    ++p;
  }

  return 0;
}
# 1459 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strncasestr(const char *s1, const char *s2, size_t n) {
  char c, sc;
  size_t len;

  c = tolower(*s2++);
  if (c) {
    len = (strlen)(s2);
    do {
      do {
        if (n-- < 1 || (sc = *s1++) == '\0') {
          return 0;
        }
      } while (tolower(sc) != c);
      if (len > n) {
        return 0;
      }
    } while (strncasecmp(s1, s2, len) != 0);
    --s1;
  }

  return (char *)s1;
}
# 1505 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strchr(const char *s, int c) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)



  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD Pattern;
  unsigned ZeroIndex;
  unsigned MatchIndex;

  c &= 0xFF;
  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, c^1);
  Pattern = __SEGGER_RTL_BYTE_PATTERN(c);



  for (;;) {
    if ((__SEGGER_RTL_ZBYTE_CHECK(Word) | __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern)) != 0) break; else Word = *++pWord;
#if __SEGGER_RTL_OPTIMIZE >= 2
    if ((__SEGGER_RTL_ZBYTE_CHECK(Word) | __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern)) != 0) break; else Word = *++pWord;
    if ((__SEGGER_RTL_ZBYTE_CHECK(Word) | __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern)) != 0) break; else Word = *++pWord;
    if ((__SEGGER_RTL_ZBYTE_CHECK(Word) | __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern)) != 0) break; else Word = *++pWord;
#endif
  }

  ZeroIndex = __SEGGER_RTL_ZBYTE_INDEX(Word);
  MatchIndex = __SEGGER_RTL_ZBYTE_INDEX(Word ^ Pattern);

  if (c == 0) {
    return (char *)pWord + ZeroIndex;
  } else if (MatchIndex < ZeroIndex) {
    return (char *)pWord + MatchIndex;
  } else {
    return NULL;
  }

#else

  while (*s && *s != (char)c) {
    ++s;
  }

  return *s == (char)c ? (char *)s : NULL;

#endif
}
# 1577 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strcpy(char *s1, const char *s2) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)

  char * res = s1;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;
  unsigned n;



  if (__SEGGER_RTL_ALIGN_REM(s1) == __SEGGER_RTL_ALIGN_REM(s2)) {



    while (__SEGGER_RTL_ALIGN_REM(s1) != 0) {
      if ((*s1++ = *s2++) == 0) {
        return res;
      }
    }



    w1 = ( __SEGGER_RTL_WORD *)s1;
    w2 = (const __SEGGER_RTL_WORD *)s2;



#if __SEGGER_RTL_OPTIMIZE >= 2
    for (;;) {
      if (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) { *w1++ = *w2++; } else { break; }
      if (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) { *w1++ = *w2++; } else { break; }
      if (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) { *w1++ = *w2++; } else { break; }
      if (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) { *w1++ = *w2++; } else { break; }
    }
#else
    while (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) {
      *w1++ = *w2++;
    }
#endif




    n = __SEGGER_RTL_ZBYTE_INDEX(*w2) + 1;



    __SEGGER_RTL_WR_PARTIAL_WORD((char *)w1, *w2, n);

  } else {



    while (__SEGGER_RTL_ALIGN_REM(s2) != 0) {
      if ((*s1++ = *s2++) == 0) {
        return res;
      }
    }



    w2 = (const __SEGGER_RTL_WORD *)s2;



    while (__SEGGER_RTL_ZBYTE_CHECK(*w2) == 0) {
      __SEGGER_RTL_WR_WORD(s1, *w2++);
      s1 += sizeof(Word);
    }




    n = __SEGGER_RTL_ZBYTE_INDEX(*w2) + 1;



    __SEGGER_RTL_WR_PARTIAL_WORD(s1, *w2, n);
  }

  return res;

#elif __SEGGER_RTL_OPTIMIZE < 0

  return (memcpy)(s1, s2, (strlen)(s2)+1);

#else

  char *res = s1;

  while ((*s1++ = *s2++) != 0) {

  }

  return res;

#endif
}
# 1717 "./strops.c"
errno_t __SEGGER_RTL_PUBLIC_API strcpy_s(char *s1, size_t s1max, const char *s2) {
  const char *msg;
  size_t s2len;



  s2len = strnlen_s(s2, s1max);

  if (s1 == NULL) { msg = "strcpy_s(s1, s1max, s2) with s1=NULL"; }
  else if (s2 == NULL) { msg = "strcpy_s(s1, s1max, s2) with s2=NULL"; }
  else if (s1max > RSIZE_MAX) { msg = "strcpy_s(s1, s1max, s2) with s1max > RSIZE_MAX"; }
  else if (s1max <= s2len) { msg = "strcpy_s(s1, s1max, s2) with s1max <= strnlen_s(s2, s1max)"; }
  else if (__SEGGER_RTL_Overlaps(s1, s2, s2len)) { msg = "strcpy_s(s1, s1max, s2) with s1 overlapping s2"; }
  else { msg = NULL; }

  if (msg == NULL) {
    (strcpy)(s1, s2);
    return 0;
  } else {
    if (s1 != NULL && 0 < s1max && s1max <= RSIZE_MAX) {
      s1[0] = 0;
    }
    __SEGGER_RTL_constraint_violation(msg, NULL, EINVAL);
    return EINVAL;
  }
}
# 1767 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API stpcpy(char *s1, const char *s2) {
  while ((*s1++ = *s2++) != 0) {

  }

  return s1 - 1;
}
# 1793 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strlen(const char *s) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)



  const char * s0;
  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;



  if (*s == 0) {
    return 0;
  }

  s0 = s;
  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, 0xFF);



  for (;;) {
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word) == 0)) Word = *++pWord; else break;
#if __SEGGER_RTL_OPTIMIZE >= 2
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word) == 0)) Word = *++pWord; else break;
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word) == 0)) Word = *++pWord; else break;
    if (__SEGGER_RTL_LIKELY(__SEGGER_RTL_ZBYTE_CHECK(Word) == 0)) Word = *++pWord; else break;
#endif
  }



  s = (char *)pWord + __SEGGER_RTL_ZBYTE_INDEX(Word);

#else



  const char * s0 = s;

#if __SEGGER_RTL_OPTIMIZE >= 0
  for (;;) {
    if (*s++ == 0) break;
    if (*s++ == 0) break;
    if (*s++ == 0) break;
    if (*s++ == 0) break;
  }
  --s;
#else
  while (*s) {
    ++s;
  }
#endif
#endif

  return s - s0;
}
# 1876 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strcat(char *s1, const char *s2) {
#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)

  (strcpy)(s1 + (strlen)(s1), s2);
  return s1;

#else

  char *res = s1;

  while (*s1) {
    ++s1;
  }



  while ((*s1++ = *s2++) != 0) {

  }

  return res;

#endif
}
# 1920 "./strops.c"
int __SEGGER_RTL_PUBLIC_API strcmp(const char *s1, const char *s2) {
  int ret;

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)

  const __SEGGER_RTL_WORD *w1;
  const __SEGGER_RTL_WORD *w2;



  if (__SEGGER_RTL_ALIGN_REM(s1) == __SEGGER_RTL_ALIGN_REM(s2)) {

    int DiffIndex;
    int NullIndex;



    while (__SEGGER_RTL_ALIGN_REM(s1) != 0) {
      if (*s1 != *s2 || *s1 == 0) {
        return (unsigned char)*s1 - (unsigned char)*s2;
      }
      ++s1;
      ++s2;
    }

    w1 = (const __SEGGER_RTL_WORD *)s1;
    w2 = (const __SEGGER_RTL_WORD *)s2;

    for (;;) {
      if (__SEGGER_RTL_UNLIKELY(*w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; ++w2; }
#if __SEGGER_RTL_OPTIMIZE >= 2
      if (__SEGGER_RTL_UNLIKELY(*w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; ++w2; }
      if (__SEGGER_RTL_UNLIKELY(*w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; ++w2; }
      if (__SEGGER_RTL_UNLIKELY(*w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; ++w2; }
#endif
    }



    DiffIndex = __SEGGER_RTL_DIFF_INDEX(*w1, *w2);
    NullIndex = __SEGGER_RTL_ZBYTE_INDEX(*w1);




    if (NullIndex < DiffIndex) {
      return 0;
    }



    return __SEGGER_RTL_DIFF_BYTE(*w1, DiffIndex) - __SEGGER_RTL_DIFF_BYTE(*w2, DiffIndex);

#if __SEGGER_RTL_OPTIMIZE >= 1

  } else {



    while (__SEGGER_RTL_ALIGN_REM(s1)) {
      if (*s1 != *s2 || *s1 == 0) {
        return (unsigned char)*s1 - (unsigned char)*s2;
      }
      ++s1;
      ++s2;
    }



    w1 = (const __SEGGER_RTL_WORD *)s1;

    for (;;) {
      if (__SEGGER_RTL_UNLIKELY(*w1 != __SEGGER_RTL_RD_WORD(s2) || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; s2 += sizeof(__SEGGER_RTL_WORD); }
#if __SEGGER_RTL_OPTIMIZE >= 2
      if (__SEGGER_RTL_UNLIKELY(*w1 != __SEGGER_RTL_RD_WORD(s2) || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; s2 += sizeof(__SEGGER_RTL_WORD); }
      if (__SEGGER_RTL_UNLIKELY(*w1 != __SEGGER_RTL_RD_WORD(s2) || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; s2 += sizeof(__SEGGER_RTL_WORD); }
      if (__SEGGER_RTL_UNLIKELY(*w1 != __SEGGER_RTL_RD_WORD(s2) || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0)) { break; } else { ++w1; s2 += sizeof(__SEGGER_RTL_WORD); }
#endif
    }

    s1 = (const char *)w1;
#endif
  }

  while ((ret = (unsigned char)*s1 - (unsigned char)*s2) == 0 && *s2) {
    ++s1;
    ++s2;
  }

  return ret;

#else

  while ((ret = (unsigned char)*s1 - (unsigned char)*s2) == 0 && *s2) {
    ++s1;
    ++s2;
  }

  return ret;

#endif
}
# 2042 "./strops.c"
int __SEGGER_RTL_PUBLIC_API strcoll(const char *s1, const char *s2) {
  return (strcmp)(s1, s2);
}
# 2066 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strxfrm(char *s1, const char *s2, size_t n) {
  strncpy(s1, s2, n);
  if (n > 0) {
    s1[n-1] = '\0';
  }
  return n;
}
# 2097 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strcspn(const char *s1, const char *s2) {
  const char *p;

  p = s1;
  while (*p && (strchr)(s2, *p) == NULL) {
    ++p;
  }

  return p - s1;
}
# 2134 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strdup(const char *s1) {
  char * pCopy;
  size_t len;

  len = (strlen)(s1) + 1;
  pCopy = (char *)malloc(len);

  if (pCopy) {
    (memcpy)(pCopy, s1, len);
  }

  return pCopy;
}
# 2183 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strlcat(char *s1, const char *s2, size_t n) {
  char * d = s1;
  const char * s = s2;
  size_t siz = n;
  size_t dlen;



  while (siz-- && *d) {
    ++d;
  }
  dlen = d - s1;
  siz = n - dlen;



  if (siz == 0) {
    return (strlen)(s) + dlen;
  }

  while (*s) {
    if (siz != 1) {
      *d++ = *s;
      --siz;
    }
    ++s;
  }
  *d = 0;



  return s - s2 + dlen;
}
# 2250 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strlcpy(char *s1, const char *s2, size_t n) {
  const char *s = s2;
  size_t siz = n;



  if (siz) {
    while (--siz) {
      if ((*s1++ = *s++) == 0) {
        break;
      }
    }
  }



  if (siz == 0) {
    if (n) {
      *s1 = 0;
    }
    while (*s++) {

    }
  }



  return s - s2 - 1;
}
# 2308 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strncat(char *s1, const char *s2, size_t n) {
  char *p = s1;



  while (*s1) {
    ++s1;
  }



  while (n--) {
    if ((*s1++ = *s2++) == 0) {
      return p;
    }
  }



  *s1 = '\0';
  return p;
}
# 2355 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strnchr(const char *s, size_t n, int c) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)



  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD Pattern;
  unsigned ZeroIndex;
  unsigned MatchIndex;



  if (n == 0) {
    return NULL;
  }

  c &= 0xFF;


  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  n += __SEGGER_RTL_ALIGN_REM(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, c^1);
  Pattern = __SEGGER_RTL_BYTE_PATTERN(c);



  for (;;) {
    if (n >= sizeof(Word) && __SEGGER_RTL_ZBYTE_CHECK(Word) == 0 && __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0) { Word = *++pWord; n -= sizeof(Word); } else { break; }
#if (__SEGGER_RTL_OPTIMIZE >= 2)
    if (n >= sizeof(Word) && __SEGGER_RTL_ZBYTE_CHECK(Word) == 0 && __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0) { Word = *++pWord; n -= sizeof(Word); } else { break; }
    if (n >= sizeof(Word) && __SEGGER_RTL_ZBYTE_CHECK(Word) == 0 && __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0) { Word = *++pWord; n -= sizeof(Word); } else { break; }
    if (n >= sizeof(Word) && __SEGGER_RTL_ZBYTE_CHECK(Word) == 0 && __SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) == 0) { Word = *++pWord; n -= sizeof(Word); } else { break; }
#endif
  }

  if (n == 0) {
    return 0;
  }




  ZeroIndex = __SEGGER_RTL_ZBYTE_INDEX(Word);
  MatchIndex = __SEGGER_RTL_ZBYTE_INDEX(Word ^ Pattern);



  return MatchIndex <= ZeroIndex && MatchIndex < n ? (char *)pWord + MatchIndex : NULL;

#else

  while (n > 0 && *s && *s != (char)c) {
    ++s;
    --n;
  }

  return n > 0 && *s == (char)c ? (char *)s : 0;

#endif
}
# 2443 "./strops.c"
int __SEGGER_RTL_PUBLIC_API strncmp(const char *s1, const char *s2, size_t n) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)

  const __SEGGER_RTL_WORD * w1;
  const __SEGGER_RTL_WORD * w2;



  if (n == 0) {
    return 0;
  } else if (*s1 != *s2) {
    return (unsigned char)*s1 - (unsigned char)*s2;
  } else if (*s1 == 0) {
    return 0;
  }



  if (__SEGGER_RTL_ALIGN_REM(s1) == __SEGGER_RTL_ALIGN_REM(s2)) {



    while (__SEGGER_RTL_ALIGN_REM(s1) != 0 && n > 0 && *s1 == *s2 && *s1 != 0) {
      ++s1;
      ++s2;
      --n;
    }

    if (n == 0) {
      return 0;
    }

    w1 = (const __SEGGER_RTL_WORD *)s1;
    w2 = (const __SEGGER_RTL_WORD *)s2;

    for (;;) {
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
#if __SEGGER_RTL_OPTIMIZE >= 2
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
      if (n < sizeof(__SEGGER_RTL_WORD) || *w1 != *w2 || __SEGGER_RTL_ZBYTE_CHECK(*w1) != 0) { break; } else { ++w1; ++w2; n -= sizeof(__SEGGER_RTL_WORD); }
#endif
    }

    if (n == 0) {
      return 0;
    }

    s1 = (const char *)w1;
    s2 = (const char *)w2;

  } else {



    while (__SEGGER_RTL_ALIGN_REM(s1) != 0 && n > 0 && *s1 == *s2 && *s1 != 0) {
      ++s1;
      ++s2;
      --n;
    }

    if (n == 0) {
      return 0;
    }



    w1 = (const __SEGGER_RTL_WORD *)s1;

    while (n >= sizeof(__SEGGER_RTL_WORD) && *w1 == __SEGGER_RTL_RD_WORD(s2) && __SEGGER_RTL_ZBYTE_CHECK(*w1) == 0) {
      ++w1;
      s2 += sizeof(__SEGGER_RTL_WORD);
      n -= sizeof(__SEGGER_RTL_WORD);
    }

    if (n == 0) {
      return 0;
    }

    s1 = (const char *)w1;
  }

  while (--n && *s1 && *s1 == *s2) {
    ++s1;
    ++s2;
  }



  return (unsigned char)*s1 - (unsigned char)*s2;

#else



  if (n == 0) {
    return 0;
  }



  while (--n && *s1 && *s1 == *s2) {
    ++s1;
    ++s2;
  }



  return (unsigned char)*s1 - (unsigned char)*s2;

#endif
}
# 2589 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strncpy(char *s1, const char *s2, size_t n) {
  char *s0;



  s0 = s1;
  while (n && (*s1++ = *s2++)) {
    --n;
  }



  if (n) {
    while (--n) {
      *s1++ = '\0';
    }
  }



  return s0;
}
# 2645 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API stpncpy(char *s1, const char *s2, size_t n) {
  size_t size;

  size = (strnlen)(s2, n);
  (memcpy)(s1, s2, size);
  s1 += size;
  if (size == n) {
    return s1;
  }
  return (memset)(s1, '\0', n-size);
}
# 2688 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strndup(const char *s, size_t n) {
  size_t max;
  char * result;

  max = (strnlen)(s, n);
  result = (char *)malloc(max + 1);
  if (result) {
    (memcpy)(result, s, max);
    result[max] = 0;
  }
  return result;
}
# 2723 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strnlen(const char *s, size_t n) {

#if (__SEGGER_RTL_OPTIMIZE >= 0) && defined(__SEGGER_RTL_ZBYTE_CHECK)



  const char * s0;
  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;
  unsigned Index;



  if (n == 0 || *s == 0) {
    return 0;
  }

  s0 = s;
  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  n += __SEGGER_RTL_ALIGN_REM(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, 0xFF);



  for (;;) {
    if (n < sizeof(Word) || __SEGGER_RTL_ZBYTE_CHECK(Word) != 0) { break; } else { Word = *++pWord; n -= sizeof(Word); }
#if __SEGGER_RTL_OPTIMIZE >= 2
    if (n < sizeof(Word) || __SEGGER_RTL_ZBYTE_CHECK(Word) != 0) { break; } else { Word = *++pWord; n -= sizeof(Word); }
    if (n < sizeof(Word) || __SEGGER_RTL_ZBYTE_CHECK(Word) != 0) { break; } else { Word = *++pWord; n -= sizeof(Word); }
    if (n < sizeof(Word) || __SEGGER_RTL_ZBYTE_CHECK(Word) != 0) { break; } else { Word = *++pWord; n -= sizeof(Word); }
#endif
  }



  Index = __SEGGER_RTL_ZBYTE_INDEX(Word);
  if (Index > n) {
    Index = n;
  }
  return (char *)pWord - s0 + Index;

#else

  const char *s0;



  s0 = s;
  while (*s && n > 0) {
    ++s;
    --n;
  }



  return s - s0;

#endif
}
# 2809 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strnlen_s(const char *s, size_t n) {
  if (s == NULL) {
    return 0;
  } else {
    return (strnlen)(s, n);
  }
}
# 2845 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strnstr(const char *s1, const char *s2, size_t n) {
  size_t snippetLen;



  snippetLen = (strlen)(s2);
  if (snippetLen == 0) {
    return (char *)s1;
  }



  while (n >= snippetLen) {



    char *fnd = strnchr(s1, n, s2[0]);
    if (fnd == 0) {
      return 0;
    }



    if (strncmp(s2, fnd, snippetLen) == 0) {
      return fnd;
    }



    n -= (fnd - s1) + 1;
    s1 = fnd + 1;
  }



  return 0;
}
# 2906 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strrchr(const char *s, int c) {

#if (__SEGGER_RTL_OPTIMIZE >= 2) && defined(__SEGGER_RTL_ZBYTE_CHECK)
  const __SEGGER_RTL_WORD * pWord;
  __SEGGER_RTL_WORD Word;
  __SEGGER_RTL_WORD Pattern;
  __SEGGER_RTL_WORD MatchWord;
  char * MatchStr;
  unsigned n;



  c &= 0xFF;

  pWord = __SEGGER_RTL_ALIGN_PTR(s);
  Word = __SEGGER_RTL_FILL_HEAD(s, *pWord, c^1);
  Pattern = __SEGGER_RTL_BYTE_PATTERN(c);



  MatchStr = NULL;
  for (;;) {



    if (__SEGGER_RTL_ZBYTE_CHECK(Word ^ Pattern) != 0) {
      MatchWord = Word;
      MatchStr = (char *)pWord;
    }



    if (__SEGGER_RTL_ZBYTE_CHECK(Word) != 0) {
      break;
    }



    Word = *++pWord;
  }



  if (MatchStr == NULL) {
    return NULL;
  }




  n = __SEGGER_RTL_ZBYTE_INDEX(MatchWord);
  if (n > sizeof(__SEGGER_RTL_WORD)-1) {
    n = sizeof(__SEGGER_RTL_WORD)-1;
  }
  for (MatchStr += n; *MatchStr != c; --MatchStr) {

  }
  return MatchStr;

#elif __SEGGER_RTL_OPTIMIZE >= 0

  const char *s0;

  if (c == 0) {
    return (strchr)(s, c);
  }

  s0 = s = (strchr)(s, c);
  while (s != NULL) {
    s0 = s;
    s = (strchr)(s+1, c);
  }

  return (char *)s0;

#else

  const char *last = NULL;

  for (;;) {
    if (*s == c) {
      last = s;
    }
    if (*s == 0) {
      return (char *)last;
    }
    ++s;
  }

#endif
}
# 3033 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strsep(char **stringp, const char *delim) {
  char *res;



  if (stringp == NULL || *stringp == NULL || **stringp == 0) {
    return 0;
  }



  res = *stringp;



  while (**stringp && (strchr)(delim, **stringp) == NULL) {
    ++(*stringp);
  }



  if (**stringp) {
    **stringp = 0;
    ++(*stringp);
  }



  return res;
}
# 3088 "./strops.c"
size_t __SEGGER_RTL_PUBLIC_API strspn(const char *s1, const char *s2) {
  const char *p;

  p = s1;
  while (*p && (strchr)(s2, *p) != NULL) {
    ++p;
  }
  return p - s1;
}
# 3122 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strstr(const char *s1, const char *s2) {
  const char *p;

  if (*s2 == 0) {
    return (char *)s1;
  }

  for (p = s1; *p; ++p) {
    const char *xs1 = p;
    const char *xs2 = s2;

    while (*xs1 && *xs2 && *xs1 == *xs2) {
      ++xs1;
      ++xs2;
    }

    if (*xs2 == 0) {
      return (char *)p;
    }
  }

  return 0;
}
# 3168 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strpbrk(const char *s1, const char *s2) {
  const char *p;

  p = s1;
  while (*p && (strchr)(s2, *p) == NULL) {
    ++p;
  }
  return *p ? (char *)p : NULL;
}
# 3222 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strtok(char *s1, const char *s2) {
  char *start;



  if (!s1) {
    s1 = __SEGGER_RTL_strtok_state;
  }



  while (*s1 && (strchr)(s2, *s1) != NULL) {
    ++s1;
  }



  if (*s1 == '\0') {
    return 0;
  }



  start = s1;



  while (*s1 && (strchr)(s2, *s1) == NULL) {
    ++s1;
  }

  if (*s1) {



    *s1++ = '\0';
  }



  __SEGGER_RTL_strtok_state = s1;



  return start;
}
# 3298 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strtok_r(char *s1, const char *s2, char **lasts) {
  char *start;



  if (!s1) {
    s1 = *lasts;
  }



  while (*s1 && (strchr)(s2, *s1) != NULL) {
    s1++;
  }



  if (*s1 == '\0') {
    return 0;
  }



  start = s1;



  while (*s1 && (strchr)(s2, *s1) == NULL) {
    s1++;
  }

  if (*s1) {



    *s1 = '\0';



    *lasts = s1+1;
  } else {
    *lasts = s1;
  }



  return start;
}
# 3370 "./strops.c"
char * __SEGGER_RTL_PUBLIC_API strerror(int num){
  const char *s;




  if (num == 0) { s = "success"; }
  else if (num == EDOM) { s = "domain error"; }
  else if (num == EILSEQ) { s = "illegal sequence error"; }
  else if (num == ERANGE) { s = "range error"; }
  else if (num == EHEAP) { s = "corrupt heap"; }
  else if (num == ENOMEM) { s = "no memory"; }
  else if (num == EINVAL) { s = "invalid argument"; }
  else { s = "unknown error"; }

  return (char *)s;
}

#if __SEGGER_RTL_INCLUDE_AEABI_API && !__SEGGER_RTL_STRING_ASM
# 3410 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memcpy(void *s1, const void *s2, size_t n) {
  __SEGGER_RTL_memcpy_inline(s1, s2, n);
}
# 3434 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memcpy4(void *s1, const void *s2, size_t n) {
  __aeabi_memcpy(s1, s2, n);
}
# 3458 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memcpy8(void *s1, const void *s2, size_t n) {
  __aeabi_memcpy(s1, s2, n);
}
# 3484 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memmove(void *s1, const void *s2, size_t n) {
  __SEGGER_RTL_memmove_inline(s1, s2, n);
}
# 3510 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memmove4(void *s1, const void *s2, size_t n) {
  __aeabi_memmove(s1, s2, n);
}
# 3536 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memmove8(void *s1, const void *s2, size_t n) {
  __aeabi_memmove(s1, s2, n);
}
# 3559 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN __aeabi_memset(void *s, size_t n, int c) {
  __SEGGER_RTL_memset_inline(s, c, n);
}
# 3582 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN __aeabi_memset4(void *s, size_t n, int c) {
  __aeabi_memset(s, n, c);
}
# 3605 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_NO_BUILTIN __aeabi_memset8(void *s, size_t n, int c) {
  __aeabi_memset(s, n, c);
}
# 3627 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memclr(void *s, size_t n) {
  __aeabi_memset(s, n, 0);
}
# 3649 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memclr4(void *s, size_t n) {
  __aeabi_memset(s, n, 0);
}
# 3671 "./strops.c"
void __SEGGER_RTL_PUBLIC_API __aeabi_memclr8(void *s, size_t n) {
  __aeabi_memset(s, n, 0);
}

#endif
