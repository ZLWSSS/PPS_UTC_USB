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
# 1 "./sortops.c"
# 17 "./sortops.c"
#include "stdlib.h"
#include "__SEGGER_RTL_Int.h"
# 28 "./sortops.c"
#define STACKSIZE 32
#define SUBDIVISION_LIMIT 10

static __SEGGER_RTL_ALWAYS_INLINE void exchange(char *p1, char *p2, size_t size) {
  do {
    char temp = *p1;
    *p1++ = *p2;
    *p2++ = temp;
    size--;
  }
  while (size != 0);
}
# 53 "./sortops.c"
static void __SEGGER_RTL_partition_sort(void *base, size_t nmemb, size_t size,
                                        int (*compar)(const void *, const void *)) {
  char * l;
  char * r;
  char * pivot;
  int s1, s2;
  int stackpointer = 1;
  void * basestack[STACKSIZE];
  int sizestack[STACKSIZE];

  basestack[0] = base;
  sizestack[0] = nmemb;

  while (stackpointer) {
    char *b = (char *) basestack[--stackpointer];
    int n = sizestack[stackpointer];



    for (;;) {
      int halfn = (n >> 1) * size;
      char *bmid = b + halfn;
      char *btop;
      if ((n & 1) == 0) {
        halfn -= size;
      }
      btop = bmid + halfn;



      if (compar(b, bmid) > 0) {
        exchange(b, bmid, size);
      }
      if (compar(bmid, btop) > 0) {
        if (compar(b, btop) > 0) {
          exchange(b, btop, size);
        }
        exchange(bmid, btop, size);
      }



      r = btop - size;
      exchange(bmid, r, size);
      l = b;
      pivot = r;


      for (;;) {
        do {
          l += size;
        } while (compar(l, pivot) < 0);
        do {
          r -= size;
        } while (compar(r, pivot) > 0);
        if (r <= l) {
          break;
        }
        exchange(l, r, size);
      }



      exchange(l, pivot, size);



      s1 = ((l - b) / size) - 1;
      s2 = n - s1 - 1;



      if (s1 > s2) {
        if (s2 > SUBDIVISION_LIMIT) {
          basestack[stackpointer] = b;
          sizestack[stackpointer++] = s1;
          b = l;
          n = s2;
        } else if (s1 > SUBDIVISION_LIMIT) {
          n = s1;
        } else {
          break;
        }
      } else {
        if (s1 > SUBDIVISION_LIMIT) {
          basestack[stackpointer] = l;
          sizestack[stackpointer++] = s2;
          n = s1;
        } else if (s2 > SUBDIVISION_LIMIT) {
          b = l;
          n = s2;
        } else {
          break;
        }
      }
    }
  }
}
# 183 "./sortops.c"
void __SEGGER_RTL_PUBLIC_API qsort(void *base, size_t nmemb, size_t sz,
                                   int (*compare)(const void *elem1, const void *elem2)) {
  char * b;
  char * endp;
  size_t j;



  if (sz == 0) {
    return;
  }



  if (nmemb > SUBDIVISION_LIMIT) {
    __SEGGER_RTL_partition_sort(base, nmemb, sz, compare);
  }



  b = (char *)base;
  endp = b + (nmemb-1)*sz;
  while (b < endp) {
    char *b1 = b;
    b += sz;



    while (b1 >= (char *)base && compare(b1, b) > 0) {
      b1 -= sz;
    }
    b1 += sz;



    for (j = 0; j < sz; ++j) {
      char *by;
      char *bx = b + j;
      char save = *bx;
      for (by = bx - sz; by >= b1; by -= sz) {
        by[sz] = *by;
      }
      by[sz] = save;
    }
  }
}
# 262 "./sortops.c"
void * __SEGGER_RTL_PUBLIC_API bsearch(const void *key, const void *base,
                                       size_t nmemb, size_t sz,
                                       int (*compare)(const void *elem1, const void *elem2)) {
  void * midp;
  int midn;
  int c;

  for (;;) {
    if (nmemb == 0) {
      return NULL;
    } else if (nmemb == 1) {




      if (compare(key, base) == 0) {
        return (void *)base;
      } else {
        return NULL;
      }
    } else {



      midn = nmemb >> 1;



      midp = (char *)base + midn*sz;



      c = compare(key, midp);
      if (c == 0) {



        return midp;
      } else if (c < 0) {



        nmemb = midn;
      } else {



        base = (char *)midp + sz;
        nmemb = nmemb - midn - 1;
      }
    }
  }
}
