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
# 1 "./heapops.c"
# 17 "./heapops.c"
#include "__SEGGER_RTL_Int.h"
#include "stdlib.h"
#include "string.h"
# 28 "./heapops.c"
#ifdef __DISABLE_INTERRUPTS_LOCKING
#include "heapops_atomic_locking.c"
#else

#define __SEGGER_RTL_X_heap_lock __heap_lock
#define __SEGGER_RTL_X_heap_unlock __heap_unlock
# 49 "./heapops.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_X_heap_lock(void) {

}
# 66 "./heapops.c"
void __SEGGER_RTL_PUBLIC_API __SEGGER_RTL_X_heap_unlock(void) {

}
#endif
# 92 "./heapops.c"
void * __SEGGER_RTL_PUBLIC_API malloc(size_t sz) {
  void *ptr;

  __SEGGER_RTL_X_heap_lock();
  ptr = __SEGGER_RTL_alloc(sz);
  __SEGGER_RTL_X_heap_unlock();

  return ptr;
}
# 126 "./heapops.c"
void * __SEGGER_RTL_PUBLIC_API aligned_alloc(size_t align, size_t sz) {
  void *ptr;

  __SEGGER_RTL_X_heap_lock();
  ptr = __SEGGER_RTL_aligned_alloc(align, sz);
  __SEGGER_RTL_X_heap_unlock();

  return ptr;
}
# 158 "./heapops.c"
void __SEGGER_RTL_PUBLIC_API free(void *ptr) {
  __SEGGER_RTL_X_heap_lock();
  __SEGGER_RTL_free(ptr);
  __SEGGER_RTL_X_heap_unlock();
}
# 200 "./heapops.c"
void * __SEGGER_RTL_PUBLIC_API realloc(void *ptr, size_t sz) {
  __SEGGER_RTL_X_heap_lock();
  ptr = __SEGGER_RTL_realloc(ptr, sz);
  __SEGGER_RTL_X_heap_unlock();
  return ptr;
}
# 231 "./heapops.c"
void * __SEGGER_RTL_PUBLIC_API calloc(size_t nobj, size_t sz) {
  void * m;
  size_t arrsize;

  arrsize = nobj * sz;

  if (arrsize < nobj || arrsize < sz) {
    return NULL;
  }

  __SEGGER_RTL_X_heap_lock();
  m = __SEGGER_RTL_alloc(arrsize);
  __SEGGER_RTL_X_heap_unlock();
  if (m && arrsize > 0) {
    (memset)(m, 0, arrsize);
  }

  return m;
}
