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
# 1 "./heapops_basic.c"
# 17 "./heapops_basic.c"
#include "__SEGGER_RTL_Int.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
# 29 "./heapops_basic.c"
#if __SEGGER_RTL_TYPESET == 64
  #define HEAP_CHUNK_SIZE 16
#else
  #define HEAP_CHUNK_SIZE 8
#endif

#define ADDADR(x,n) ((void *)((unsigned char *)(x)+(n)))
# 44 "./heapops_basic.c"
typedef struct __SEGGER_RTL_BLOCK_t {
  struct __SEGGER_RTL_BLOCK_t * next;
  unsigned size;
} __SEGGER_RTL_BLOCK_t;

typedef struct {
  __SEGGER_RTL_BLOCK_t * pFreeList;
} HEAP;
# 60 "./heapops_basic.c"
static HEAP __SEGGER_RTL_heap_globals;
# 85 "./heapops_basic.c"
void * __SEGGER_RTL_alloc(size_t sz) {
  __SEGGER_RTL_BLOCK_t * p;
  __SEGGER_RTL_BLOCK_t * q;
  __SEGGER_RTL_BLOCK_t * best;
  unsigned best_size;



  sz = (sz + sizeof(unsigned) + HEAP_CHUNK_SIZE-1) & (unsigned)(-HEAP_CHUNK_SIZE);



  p = __SEGGER_RTL_heap_globals.pFreeList;
  q = NULL;



  best_size = ~0u;
  best = NULL;



  while (p) {



    if (p->size == sz) {



      if (q) {
        q->next = p->next;
      } else {
        __SEGGER_RTL_heap_globals.pFreeList = p->next;
      }



      *((unsigned *)p) = sz;
      return ((char *)p) + sizeof(unsigned);
    } else if (p->size > sz && p->size < best_size) {
      best = p;
      best_size = p->size;
    }



    q = p;
    p = p->next;
  }



  if (best) {
    best->size -= sz;
    p = (__SEGGER_RTL_BLOCK_t *)ADDADR(best, best_size - sz);
    *((unsigned *)p) = sz;
    return ((char *)p) + sizeof(unsigned);
  } else {
    return NULL;
  }
}
# 169 "./heapops_basic.c"
void * __SEGGER_RTL_aligned_alloc(size_t align, size_t sz) {



  __SEGGER_RTL_USE_PARA(align);
  __SEGGER_RTL_USE_PARA(sz);

  return NULL;
}
# 189 "./heapops_basic.c"
void __SEGGER_RTL_free(void *ptr) {
  __SEGGER_RTL_BLOCK_t * p;
  __SEGGER_RTL_BLOCK_t * rover;
  __SEGGER_RTL_BLOCK_t * prev;
  unsigned size;

  if (ptr == NULL) {
    return;
  }



  ptr = ((char *)ptr) - sizeof(unsigned);



  size = *((unsigned *)ptr);

  if (ptr) {



    if (__SEGGER_RTL_heap_globals.pFreeList == NULL) {



      __SEGGER_RTL_heap_globals.pFreeList = (__SEGGER_RTL_BLOCK_t *)ptr;
      __SEGGER_RTL_heap_globals.pFreeList->next = NULL;
      __SEGGER_RTL_heap_globals.pFreeList->size = size;
    } else {



      p = (__SEGGER_RTL_BLOCK_t *)ptr;
      rover = __SEGGER_RTL_heap_globals.pFreeList;
      prev = NULL;
      while (rover && rover < (__SEGGER_RTL_BLOCK_t *)ptr) {
        prev = rover; rover = rover->next;
      }



      p->next = rover;
      p->size = size;
      if (prev) {
        prev->next = p;
      } else {
        __SEGGER_RTL_heap_globals.pFreeList = p;
      }



      if (rover && (ADDADR(p, size) == rover)) {
        p->size += rover->size;
        p->next = rover->next;
      }



      if (prev && ADDADR(prev, prev->size) == p) {
        prev->size += p->size;
        prev->next = p->next;
      }
    }
  }
}
# 289 "./heapops_basic.c"
void * __SEGGER_RTL_realloc(void *ptr, size_t sz) {
  void *pp;



  pp = __SEGGER_RTL_alloc(sz);



  if (pp == NULL) {
    return pp;
  }



  if (ptr) {



    size_t existing_size = ((unsigned *)ptr)[-1];



    if (existing_size < sz) {
      sz = existing_size;
    }



    (memcpy)(pp, ptr, sz);



    __SEGGER_RTL_free(ptr);
  }



  return pp;
}
# 341 "./heapops_basic.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_init_heap(void *ptr, size_t size) {
  if (size >= HEAP_CHUNK_SIZE) {
    __SEGGER_RTL_heap_globals.pFreeList = ptr;
    __SEGGER_RTL_heap_globals.pFreeList->next = NULL;
    __SEGGER_RTL_heap_globals.pFreeList->size = size;
  }
}
