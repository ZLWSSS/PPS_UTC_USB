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
# 1 "./wstrops.c"
# 17 "./wstrops.c"
#include "wchar.h"
#include "wctype.h"
#include "stdlib.h"
#include "string.h"
# 53 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsstr(const wchar_t *s1, const wchar_t *s2) {
  const wchar_t *p;

  if (*s2 == 0) {
    return (wchar_t *)s1;
  }

  for (p = s1; *p; ++p) {
    const wchar_t *ps1 = p;
    const wchar_t *ps2 = s2;

    while (*ps1 && *ps2 && *ps1 == *ps2) {
      ++ps1;
      ++ps2;
    }

    if (*ps2 == 0) {
      return (wchar_t *)p;
    }
  }

  return 0;
}
# 101 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcsspn(const wchar_t *s1, const wchar_t *s2) {
  const wchar_t *p;

  p = s1;
  while (*p && wcschr(s2, *p)) {
    p++;
  }
  return p - s1;
}
# 146 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcssep(wchar_t **stringp, const wchar_t *delim) {
  wchar_t *res;



  if (stringp == 0 || *stringp == 0 || **stringp == 0) {
    return 0;
  }



  res = *stringp;
  while (**stringp && !wcschr(delim, **stringp)) {
    ++(*stringp);
  }



  if (**stringp) {
    **stringp = 0;
    ++(*stringp);
  }



  return res;
}
# 198 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcscat(wchar_t *s1, const wchar_t *s2) {
  wchar_t *p = s1;



  while (*p)
    ++p;



  while ((*p++ = *s2++))
    ;

  return s1;
}
# 237 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcschr(const wchar_t *s, wchar_t c) {
  while (*s && *s != c) {
    s++;
  }

  return *s == c ? (wchar_t *)s : 0;
}
# 265 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wcscmp(const wchar_t *s1, const wchar_t *s2) {
  int ret;

  while ((ret = *s1 - *s2) == 0 && *s2) {
    ++s1;
    ++s2;
  }
  return ret;
}
# 295 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wcscoll(const wchar_t *s1, const wchar_t *s2) {
  return wcscmp(s1, s2);
}
# 319 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcsxfrm(wchar_t *s1, const wchar_t *s2, size_t n) {
  wcsncpy(s1, s2, n);
  if (n) {
    s1[n-1] = L'\0';
  }
  return n;
}
# 350 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcscpy(wchar_t *s1, const wchar_t *s2) {
  wchar_t *p = s1;



  while ((*p++ = *s2++) != 0) {

  }



  return s1;
}
# 387 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcscspn(const wchar_t *s1, const wchar_t *s2) {
  const wchar_t *p;

  p = s1;
  while (*p && wcschr(s2, *p) == 0) {
    ++p;
  }
  return p - s1;
}
# 423 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsdup(const wchar_t *s) {
  wchar_t *result;

  result = (wchar_t *)malloc((wcslen(s) + 1) * sizeof(wchar_t));
  if (result) {
    wcscpy(result, s);
  }
  return result;
}
# 464 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsndup(const wchar_t *s, size_t n) {
  size_t max;
  wchar_t * result;

  max = wcsnlen(s, n);
  result = (wchar_t *)malloc(max + 1);
  if (result) {
    (memcpy)(result, s, max);
    result[max] = 0;
  }
  return result;
}
# 495 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcslen(const wchar_t *s) {
  const wchar_t *sos;



  sos = s;
  while (*s) {
    ++s;
  }



  return s-sos;
}
# 539 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsnstr(const wchar_t *s1, const wchar_t *s2, size_t n) {
  size_t snippetLen;



  snippetLen = wcslen(s2);
  if (snippetLen == 0) {
    return (wchar_t *)s1;
  }



  while (n >= snippetLen) {



    wchar_t *fnd = wcsnchr(s1, n, s2[0]);
    if (fnd == 0) {
      return 0;
    }



    if (wcsncmp(s2, fnd, snippetLen) == 0) {
      return fnd;
    }



    n -= (fnd - s1) + 1;
    s1 = fnd + 1;
  }



  return 0;
}
# 599 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcspbrk(const wchar_t *s1, const wchar_t *s2) {
  const wchar_t *p;

  p = s1;
  while (*p && wcschr(s2, *p) == 0) {
    ++p;
  }
  return *p ? (wchar_t *)p : 0;
}
# 632 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsrchr(const wchar_t *s, wchar_t c) {
  const wchar_t *s0;



  s0 = s;



  while (*s++) {

  }



  while (--s != s0 && *s != c) {

  }



  return *s == c ? (wchar_t *)s : 0;
}
# 682 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsncat(wchar_t *s1, const wchar_t *s2, size_t n) {
  wchar_t *p = s1;



  while (*s1)
    s1++;



  while (n--)
    if ((*s1++ = *s2++) == 0)
      return p;



  *s1 = 0;
  return p;
}
# 726 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsnchr(const wchar_t *s, size_t n, wchar_t c) {
  while (n > 0 && *s && *s != c) {
    ++s;
  }

  return n > 0 && *s == c ? (wchar_t *)s : 0;
}
# 759 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wcsncmp(const wchar_t *s1, const wchar_t *s2, size_t n) {



  if (n == 0) {
    return 0;
  }



  while (--n && *s1 && *s1 == *s2) {
    ++s1;
    ++s2;
  }



  if (sizeof(wchar_t) == sizeof(int)) {
    if (*s1 < *s2) {
      return -1;
    } else if (*s1 == *s2) {
      return 0;
    } else {
      return +1;
    }
  } else {
    return *s1 - *s2;
  }
}
# 821 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcsncpy(wchar_t *s1, const wchar_t *s2, size_t n) {
  wchar_t *s0;



  s0 = s1;


  while (n && (*s1++ = *s2++)) {
    --n;
  }



  if (n) {
    while (--n) {
      *s1++ = 0;
    }
  }



  return s0;
}
# 868 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcsnlen(const wchar_t *s, size_t n) {
  const wchar_t *sos;



  sos = s;
  while (*s && n > 0) {
    ++s;
    --n;
  }



  return s-sos;
}
# 917 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmemccpy(wchar_t *s1, const wchar_t *s2, wchar_t c, size_t n) {
  while (n && (*s1++ = *s2++) != c) {
    --n;
  }

  return n ? s1 : 0;
}
# 950 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmemchr(const wchar_t *s, wchar_t c, size_t n) {
  while (n && *s != c) {
    ++s;
    --n;
  }

  return n ? (wchar_t *)s : 0;
}
# 986 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n) {
  if (n == 0) {
    return 0;
  }

  while (--n && *s1 == *s2) {
    ++s1;
    ++s2;
  }

  return *s1 - *s2;
}
# 1022 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmemcpy(wchar_t *s1, const wchar_t *s2, size_t n) {
  wchar_t *p = s1;

  while (n--) {
    *s1++ = *s2++;
  }

  return p;
}
# 1060 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmemmove(wchar_t *s1, const wchar_t *s2, size_t n) {
  wchar_t *ret;

  ret = s1;

  if (s2 < s1) {
    for (s2 += n, s1 += n; n; --n) {
      *--s1 = *--s2;
    }
  } else if (s2 != s1) {
    while (n--) {
      *s1++ = *s2++;
    }
  }

  return ret;
}
# 1105 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmempcpy(wchar_t *s1, const wchar_t *s2, size_t n) {
  wmemcpy(s1, s2, n);
  return s1 + n;
}
# 1132 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wmemset(wchar_t *s, wchar_t c, size_t n) {
  wchar_t *ret;

  ret = s;



  while (n--) {
    *s++ = c;
  }



  return ret;
}
# 1193 "./wstrops.c"
wchar_t * __SEGGER_RTL_PUBLIC_API wcstok(wchar_t *s1, const wchar_t *s2, wchar_t **ptr) {
  wchar_t *start;



  if (s1 == 0) {
    s1 = *ptr;
  }



  while (*s1 && wcschr(s2, *s1)) {
    s1++;
  }



  if (*s1 == 0) {
    return 0;
  }



  start = s1;



  while (*s1 && wcschr(s2, *s1) == 0) {
    s1++;
  }

  if (*s1) {



    *s1 = 0;



    *ptr = s1+1;
  } else {
    *ptr = s1;
  }



  return start;
}
# 1275 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcslcpy(wchar_t *s1, const wchar_t *s2, size_t n) {
  const wchar_t *s = s2;
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
# 1340 "./wstrops.c"
size_t __SEGGER_RTL_PUBLIC_API wcslcat(char *s1, const char *s2, size_t n) {
  char *d = s1;
  const char *s = s2;
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
      siz--;
    }
    s++;
  }
  *d = 0;



  return s - s2 + dlen;
}
# 1404 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wcscasecmp(const char *s1, const char *s2) {
  while (towlower(*s1) == towlower(*s2) && *s2) {
    ++s1;
    ++s2;
  }

  if (towlower(*s1) < towlower(*s2)) {
    return -1;
  } else if (towlower(*s1) > towlower(*s2)) {
    return +1;
  } else {
    return 0;
  }
}
# 1451 "./wstrops.c"
int __SEGGER_RTL_PUBLIC_API wcsncasecmp(const char *s1, const char *s2, size_t n) {



  if (n == 0) {
    return 0;
  }



  while (--n && *s1 && towlower(*s1) == towlower(*s2)) {
    ++s1;
    ++s2;
  }

  if (towlower(*s1) < towlower(*s2)) {
    return -1;
  } else if (towlower(*s1) > towlower(*s2)) {
    return +1;
  } else {
    return 0;
  }
}
