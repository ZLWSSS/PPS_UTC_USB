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
# 1 "./atomicops.c"
# 17 "./atomicops.c"
#include "__SEGGER_RTL_Int.h"
#include "string.h"
#include "stdint.h"
# 33 "./atomicops.c"
#if defined(__clang__) || defined(__SEGGER_CC__)

  #pragma redefine_extname __sync_synchronize_c __sync_synchronize
  #define __sync_synchronize __sync_synchronize_c

  #pragma redefine_extname __sync_fetch_and_add_1_c __sync_fetch_and_add_1
  #pragma redefine_extname __sync_fetch_and_add_2_c __sync_fetch_and_add_2
  #pragma redefine_extname __sync_fetch_and_add_4_c __sync_fetch_and_add_4
  #pragma redefine_extname __sync_fetch_and_add_8_c __sync_fetch_and_add_8
  #pragma redefine_extname __sync_fetch_and_add_16_c __sync_fetch_and_add_16
  #define __sync_fetch_and_add_1 __sync_fetch_and_add_1_c
  #define __sync_fetch_and_add_2 __sync_fetch_and_add_2_c
  #define __sync_fetch_and_add_4 __sync_fetch_and_add_4_c
  #define __sync_fetch_and_add_8 __sync_fetch_and_add_8_c
  #define __sync_fetch_and_add_16 __sync_fetch_and_add_16_c

  #pragma redefine_extname __sync_fetch_and_sub_1_c __sync_fetch_and_sub_1
  #pragma redefine_extname __sync_fetch_and_sub_2_c __sync_fetch_and_sub_2
  #pragma redefine_extname __sync_fetch_and_sub_4_c __sync_fetch_and_sub_4
  #pragma redefine_extname __sync_fetch_and_sub_8_c __sync_fetch_and_sub_8
  #pragma redefine_extname __sync_fetch_and_sub_16_c __sync_fetch_and_sub_16
  #define __sync_fetch_and_sub_1 __sync_fetch_and_sub_1_c
  #define __sync_fetch_and_sub_2 __sync_fetch_and_sub_2_c
  #define __sync_fetch_and_sub_4 __sync_fetch_and_sub_4_c
  #define __sync_fetch_and_sub_8 __sync_fetch_and_sub_8_c
  #define __sync_fetch_and_sub_16 __sync_fetch_and_sub_16_c

  #pragma redefine_extname __sync_fetch_and_and_1_c __sync_fetch_and_and_1
  #pragma redefine_extname __sync_fetch_and_and_2_c __sync_fetch_and_and_2
  #pragma redefine_extname __sync_fetch_and_and_4_c __sync_fetch_and_and_4
  #pragma redefine_extname __sync_fetch_and_and_8_c __sync_fetch_and_and_8
  #pragma redefine_extname __sync_fetch_and_and_16_c __sync_fetch_and_and_16
  #define __sync_fetch_and_and_1 __sync_fetch_and_and_1_c
  #define __sync_fetch_and_and_2 __sync_fetch_and_and_2_c
  #define __sync_fetch_and_and_4 __sync_fetch_and_and_4_c
  #define __sync_fetch_and_and_8 __sync_fetch_and_and_8_c
  #define __sync_fetch_and_and_16 __sync_fetch_and_and_16_c

  #pragma redefine_extname __sync_fetch_and_or_1_c __sync_fetch_and_or_1
  #pragma redefine_extname __sync_fetch_and_or_2_c __sync_fetch_and_or_2
  #pragma redefine_extname __sync_fetch_and_or_4_c __sync_fetch_and_or_4
  #pragma redefine_extname __sync_fetch_and_or_8_c __sync_fetch_and_or_8
  #pragma redefine_extname __sync_fetch_and_or_16_c __sync_fetch_and_or_16
  #define __sync_fetch_and_or_1 __sync_fetch_and_or_1_c
  #define __sync_fetch_and_or_2 __sync_fetch_and_or_2_c
  #define __sync_fetch_and_or_4 __sync_fetch_and_or_4_c
  #define __sync_fetch_and_or_8 __sync_fetch_and_or_8_c
  #define __sync_fetch_and_or_16 __sync_fetch_and_or_16_c

  #pragma redefine_extname __sync_fetch_and_xor_1_c __sync_fetch_and_xor_1
  #pragma redefine_extname __sync_fetch_and_xor_2_c __sync_fetch_and_xor_2
  #pragma redefine_extname __sync_fetch_and_xor_4_c __sync_fetch_and_xor_4
  #pragma redefine_extname __sync_fetch_and_xor_8_c __sync_fetch_and_xor_8
  #pragma redefine_extname __sync_fetch_and_xor_16_c __sync_fetch_and_xor_16
  #define __sync_fetch_and_xor_1 __sync_fetch_and_xor_1_c
  #define __sync_fetch_and_xor_2 __sync_fetch_and_xor_2_c
  #define __sync_fetch_and_xor_4 __sync_fetch_and_xor_4_c
  #define __sync_fetch_and_xor_8 __sync_fetch_and_xor_8_c
  #define __sync_fetch_and_xor_16 __sync_fetch_and_xor_16_c

  #pragma redefine_extname __sync_fetch_and_nand_1_c __sync_fetch_and_nand_1
  #pragma redefine_extname __sync_fetch_and_nand_2_c __sync_fetch_and_nand_2
  #pragma redefine_extname __sync_fetch_and_nand_4_c __sync_fetch_and_nand_4
  #pragma redefine_extname __sync_fetch_and_nand_8_c __sync_fetch_and_nand_8
  #pragma redefine_extname __sync_fetch_and_nand_16_c __sync_fetch_and_nand_16
  #define __sync_fetch_and_nand_1 __sync_fetch_and_nand_1_c
  #define __sync_fetch_and_nand_2 __sync_fetch_and_nand_2_c
  #define __sync_fetch_and_nand_4 __sync_fetch_and_nand_4_c
  #define __sync_fetch_and_nand_8 __sync_fetch_and_nand_8_c
  #define __sync_fetch_and_nand_16 __sync_fetch_and_nand_16_c

  #pragma redefine_extname __sync_add_and_fetch_1_c __sync_add_and_fetch_1
  #pragma redefine_extname __sync_add_and_fetch_2_c __sync_add_and_fetch_2
  #pragma redefine_extname __sync_add_and_fetch_4_c __sync_add_and_fetch_4
  #pragma redefine_extname __sync_add_and_fetch_8_c __sync_add_and_fetch_8
  #pragma redefine_extname __sync_add_and_fetch_16_c __sync_add_and_fetch_16
  #define __sync_add_and_fetch_1 __sync_add_and_fetch_1_c
  #define __sync_add_and_fetch_2 __sync_add_and_fetch_2_c
  #define __sync_add_and_fetch_4 __sync_add_and_fetch_4_c
  #define __sync_add_and_fetch_8 __sync_add_and_fetch_8_c
  #define __sync_add_and_fetch_16 __sync_add_and_fetch_16_c

  #pragma redefine_extname __sync_sub_and_fetch_1_c __sync_sub_and_fetch_1
  #pragma redefine_extname __sync_sub_and_fetch_2_c __sync_sub_and_fetch_2
  #pragma redefine_extname __sync_sub_and_fetch_4_c __sync_sub_and_fetch_4
  #pragma redefine_extname __sync_sub_and_fetch_8_c __sync_sub_and_fetch_8
  #pragma redefine_extname __sync_sub_and_fetch_16_c __sync_sub_and_fetch_16
  #define __sync_sub_and_fetch_1 __sync_sub_and_fetch_1_c
  #define __sync_sub_and_fetch_2 __sync_sub_and_fetch_2_c
  #define __sync_sub_and_fetch_4 __sync_sub_and_fetch_4_c
  #define __sync_sub_and_fetch_8 __sync_sub_and_fetch_8_c
  #define __sync_sub_and_fetch_16 __sync_sub_and_fetch_16_c

  #pragma redefine_extname __sync_and_and_fetch_1_c __sync_and_and_fetch_1
  #pragma redefine_extname __sync_and_and_fetch_2_c __sync_and_and_fetch_2
  #pragma redefine_extname __sync_and_and_fetch_4_c __sync_and_and_fetch_4
  #pragma redefine_extname __sync_and_and_fetch_8_c __sync_and_and_fetch_8
  #pragma redefine_extname __sync_and_and_fetch_16_c __sync_and_and_fetch_16
  #define __sync_and_and_fetch_1 __sync_and_and_fetch_1_c
  #define __sync_and_and_fetch_2 __sync_and_and_fetch_2_c
  #define __sync_and_and_fetch_4 __sync_and_and_fetch_4_c
  #define __sync_and_and_fetch_8 __sync_and_and_fetch_8_c
  #define __sync_and_and_fetch_16 __sync_and_and_fetch_16_c

  #pragma redefine_extname __sync_or_and_fetch_1_c __sync_or_and_fetch_1
  #pragma redefine_extname __sync_or_and_fetch_2_c __sync_or_and_fetch_2
  #pragma redefine_extname __sync_or_and_fetch_4_c __sync_or_and_fetch_4
  #pragma redefine_extname __sync_or_and_fetch_8_c __sync_or_and_fetch_8
  #pragma redefine_extname __sync_or_and_fetch_16_c __sync_or_and_fetch_16
  #define __sync_or_and_fetch_1 __sync_or_and_fetch_1_c
  #define __sync_or_and_fetch_2 __sync_or_and_fetch_2_c
  #define __sync_or_and_fetch_4 __sync_or_and_fetch_4_c
  #define __sync_or_and_fetch_8 __sync_or_and_fetch_8_c
  #define __sync_or_and_fetch_16 __sync_or_and_fetch_16_c

  #pragma redefine_extname __sync_xor_and_fetch_1_c __sync_xor_and_fetch_1
  #pragma redefine_extname __sync_xor_and_fetch_2_c __sync_xor_and_fetch_2
  #pragma redefine_extname __sync_xor_and_fetch_4_c __sync_xor_and_fetch_4
  #pragma redefine_extname __sync_xor_and_fetch_8_c __sync_xor_and_fetch_8
  #pragma redefine_extname __sync_xor_and_fetch_16_c __sync_xor_and_fetch_16
  #define __sync_xor_and_fetch_1 __sync_xor_and_fetch_1_c
  #define __sync_xor_and_fetch_2 __sync_xor_and_fetch_2_c
  #define __sync_xor_and_fetch_4 __sync_xor_and_fetch_4_c
  #define __sync_xor_and_fetch_8 __sync_xor_and_fetch_8_c
  #define __sync_xor_and_fetch_16 __sync_xor_and_fetch_16_c

  #pragma redefine_extname __sync_nand_and_fetch_1_c __sync_nand_and_fetch_1
  #pragma redefine_extname __sync_nand_and_fetch_2_c __sync_nand_and_fetch_2
  #pragma redefine_extname __sync_nand_and_fetch_4_c __sync_nand_and_fetch_4
  #pragma redefine_extname __sync_nand_and_fetch_8_c __sync_nand_and_fetch_8
  #pragma redefine_extname __sync_nand_and_fetch_16_c __sync_nand_and_fetch_16
  #define __sync_nand_and_fetch_1 __sync_nand_and_fetch_1_c
  #define __sync_nand_and_fetch_2 __sync_nand_and_fetch_2_c
  #define __sync_nand_and_fetch_4 __sync_nand_and_fetch_4_c
  #define __sync_nand_and_fetch_8 __sync_nand_and_fetch_8_c
  #define __sync_nand_and_fetch_16 __sync_nand_and_fetch_16_c

  #pragma redefine_extname __sync_bool_compare_and_swap_1_c __sync_bool_compare_and_swap_1
  #pragma redefine_extname __sync_bool_compare_and_swap_2_c __sync_bool_compare_and_swap_2
  #pragma redefine_extname __sync_bool_compare_and_swap_4_c __sync_bool_compare_and_swap_4
  #pragma redefine_extname __sync_bool_compare_and_swap_8_c __sync_bool_compare_and_swap_8
  #pragma redefine_extname __sync_bool_compare_and_swap_16_c __sync_bool_compare_and_swap_16
  #define __sync_bool_compare_and_swap_1 __sync_bool_compare_and_swap_1_c
  #define __sync_bool_compare_and_swap_2 __sync_bool_compare_and_swap_2_c
  #define __sync_bool_compare_and_swap_4 __sync_bool_compare_and_swap_4_c
  #define __sync_bool_compare_and_swap_8 __sync_bool_compare_and_swap_8_c
  #define __sync_bool_compare_and_swap_16 __sync_bool_compare_and_swap_16_c

  #pragma redefine_extname __sync_val_compare_and_swap_1_c __sync_val_compare_and_swap_1
  #pragma redefine_extname __sync_val_compare_and_swap_2_c __sync_val_compare_and_swap_2
  #pragma redefine_extname __sync_val_compare_and_swap_4_c __sync_val_compare_and_swap_4
  #pragma redefine_extname __sync_val_compare_and_swap_8_c __sync_val_compare_and_swap_8
  #pragma redefine_extname __sync_val_compare_and_swap_16_c __sync_val_compare_and_swap_16
  #define __sync_val_compare_and_swap_1 __sync_val_compare_and_swap_1_c
  #define __sync_val_compare_and_swap_2 __sync_val_compare_and_swap_2_c
  #define __sync_val_compare_and_swap_4 __sync_val_compare_and_swap_4_c
  #define __sync_val_compare_and_swap_8 __sync_val_compare_and_swap_8_c
  #define __sync_val_compare_and_swap_16 __sync_val_compare_and_swap_16_c

  #pragma redefine_extname __sync_lock_test_and_set_1_c __sync_lock_test_and_set_1
  #pragma redefine_extname __sync_lock_test_and_set_2_c __sync_lock_test_and_set_2
  #pragma redefine_extname __sync_lock_test_and_set_4_c __sync_lock_test_and_set_4
  #pragma redefine_extname __sync_lock_test_and_set_8_c __sync_lock_test_and_set_8
  #pragma redefine_extname __sync_lock_test_and_set_16_c __sync_lock_test_and_set_16
  #define __sync_lock_test_and_set_1 __sync_lock_test_and_set_1_c
  #define __sync_lock_test_and_set_2 __sync_lock_test_and_set_2_c
  #define __sync_lock_test_and_set_4 __sync_lock_test_and_set_4_c
  #define __sync_lock_test_and_set_8 __sync_lock_test_and_set_8_c
  #define __sync_lock_test_and_set_16 __sync_lock_test_and_set_16_c

  #pragma redefine_extname __sync_lock_release_1_c __sync_lock_release_1
  #pragma redefine_extname __sync_lock_release_2_c __sync_lock_release_2
  #pragma redefine_extname __sync_lock_release_4_c __sync_lock_release_4
  #pragma redefine_extname __sync_lock_release_8_c __sync_lock_release_8
  #pragma redefine_extname __sync_lock_release_16_c __sync_lock_release_16
  #define __sync_lock_release_1 __sync_lock_release_1_c
  #define __sync_lock_release_2 __sync_lock_release_2_c
  #define __sync_lock_release_4 __sync_lock_release_4_c
  #define __sync_lock_release_8 __sync_lock_release_8_c
  #define __sync_lock_release_16 __sync_lock_release_16_c

  #pragma redefine_extname __atomic_load_c __atomic_load
  #define __atomic_load __atomic_load_c

  #pragma redefine_extname __atomic_store_c __atomic_store
  #define __atomic_store __atomic_store_c

  #pragma redefine_extname __atomic_is_lock_free_c __atomic_is_lock_free
  #define __atomic_is_lock_free __atomic_is_lock_free_c

  #pragma redefine_extname __atomic_load_1_c __atomic_load_1
  #pragma redefine_extname __atomic_load_2_c __atomic_load_2
  #pragma redefine_extname __atomic_load_4_c __atomic_load_4
  #pragma redefine_extname __atomic_load_8_c __atomic_load_8
  #pragma redefine_extname __atomic_load_16_c __atomic_load_16
  #define __atomic_load_1 __atomic_load_1_c
  #define __atomic_load_2 __atomic_load_2_c
  #define __atomic_load_4 __atomic_load_4_c
  #define __atomic_load_8 __atomic_load_8_c
  #define __atomic_load_16 __atomic_load_16_c

  #pragma redefine_extname __atomic_store_1_c __atomic_store_1
  #pragma redefine_extname __atomic_store_2_c __atomic_store_2
  #pragma redefine_extname __atomic_store_4_c __atomic_store_4
  #pragma redefine_extname __atomic_store_8_c __atomic_store_8
  #pragma redefine_extname __atomic_store_16_c __atomic_store_16
  #define __atomic_store_1 __atomic_store_1_c
  #define __atomic_store_2 __atomic_store_2_c
  #define __atomic_store_4 __atomic_store_4_c
  #define __atomic_store_8 __atomic_store_8_c
  #define __atomic_store_16 __atomic_store_16_c

#endif

#define SYNC_FETCH_AND_OP(PTR,VAL,TYPE,OP) \
  TYPE ret; \
  int en; \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  *(volatile TYPE *)(PTR) = OP; \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define SYNC_OP_AND_FETCH(PTR,VAL,TYPE,OP) \
  TYPE ret; \
  int en; \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  ret = (TYPE)(OP); \
  *(volatile TYPE *)(PTR) = ret; \
  ret = *(volatile TYPE *)(PTR); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define SYNC_BOOL_COMPARE_AND_SWAP(PTR,OLDVAL,NEWVAL,TYPE) \
  __SEGGER_RTL_BOOL ret; \
  int en; \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  if (*(volatile TYPE *)ptr == (OLDVAL)) { \
    *(volatile TYPE *)ptr = (NEWVAL); \
    ret = 1; \
  } else { \
    ret = 0; \
  } \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define SYNC_VAL_COMPARE_AND_SWAP(PTR,OLDVAL,NEWVAL,TYPE) \
  int en; \
  TYPE ret; \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  if (ret == (OLDVAL)) { \
    *(volatile TYPE *)(PTR) = (NEWVAL); \
  } \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define SYNC_LOCK_TEST_AND_SET(PTR,VAL,TYPE) \
  int en; \
  TYPE ret; \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  *(volatile TYPE *)(PTR) = (VAL); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define SYNC_LOCK_RELEASE(PTR,TYPE) \
  *(volatile TYPE *)(PTR) = 0;

#define ATOMIC_LOAD(PTR,MEMORDER,TYPE) \
  int en; \
  TYPE ret; \
  __SEGGER_RTL_USE_PARA(MEMORDER); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define ATOMIC_STORE(PTR,VAL,MEMORDER,TYPE) \
  int en; \
  __SEGGER_RTL_USE_PARA(MEMORDER); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  *(volatile TYPE *)(PTR) = (VAL); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en);

#define ATOMIC_OP_FETCH(PTR,VAL,MEMORDER,TYPE,OP) \
  TYPE ret; \
  int en; \
  __SEGGER_RTL_USE_PARA(MEMORDER); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  ret = OP; \
  *(volatile TYPE *)(PTR) = ret; \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define ATOMIC_FETCH_AND_OP(PTR,VAL,MEMORDER,TYPE,OP) \
  TYPE ret; \
  int en; \
  __SEGGER_RTL_USE_PARA(MEMORDER); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  *(volatile TYPE *)(PTR) = (TYPE)(OP); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define ATOMIC_EXCHANGE(PTR,VAL,MEMORDER,TYPE) \
  TYPE ret; \
  int en; \
  __SEGGER_RTL_USE_PARA(MEMORDER); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  ret = *(volatile TYPE *)(PTR); \
  *(volatile TYPE *)(PTR) = (VAL); \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;

#define ATOMIC_COMPARE_EXCHANGE(PTR,EXPECTED,DESIRED,WEAK,SUCC,FAIL,TYPE) \
  __SEGGER_RTL_BOOL ret; \
  int en; \
  TYPE act; \
  __SEGGER_RTL_USE_PARA(SUCC); \
  __SEGGER_RTL_USE_PARA(FAIL); \
  __SEGGER_RTL_USE_PARA(WEAK); \
  en = __SEGGER_RTL_ATOMIC_LOCK(); \
  act = *(volatile TYPE *)(PTR); \
  if (act == *(TYPE *)(EXPECTED)) { \
    *(volatile TYPE *)(PTR) = (DESIRED); \
    ret = 1; \
  } else { \
    *(TYPE *)(EXPECTED) = act; \
    ret = 0; \
  } \
  __SEGGER_RTL_ATOMIC_UNLOCK(en); \
  return ret;
# 383 "./atomicops.c"
void __sync_synchronize(void) {
  __SEGGER_RTL_ATOMIC_SYNCHRONIZE();
}
# 401 "./atomicops.c"
__SEGGER_RTL_U8 __sync_fetch_and_add_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ret + value)
}
# 419 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_add_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ret + value)
}
# 437 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_add_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret + value)
}
# 455 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_add_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ret + value)
}

#if defined(__SEGGER_RTL_U128)
# 474 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_add_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ret + value)
}
#endif
# 493 "./atomicops.c"
__SEGGER_RTL_U8 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_sub_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ret - value)
}
# 511 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_sub_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ret - value)
}
# 529 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_sub_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret - value)
}
# 547 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_sub_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ret - value)
}

#if defined(__SEGGER_RTL_U128)
# 566 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_sub_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ret - value)
}
#endif
# 585 "./atomicops.c"
__SEGGER_RTL_U8 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_and_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ret & value)
}
# 603 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_and_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ret & value)
}
# 621 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_and_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret & value)
}
# 639 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_and_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ret & value)
}

#if defined(__SEGGER_RTL_U128)
# 658 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_and_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ret & value)
}
#endif
# 677 "./atomicops.c"
__SEGGER_RTL_U8 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_or_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ret | value)
}
# 695 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_or_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ret | value)
}
# 713 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_or_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret | value)
}
# 731 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_or_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ret | value)
}

#if defined(__SEGGER_RTL_U128)
# 750 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_or_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ret | value)
}
#endif
# 769 "./atomicops.c"
__SEGGER_RTL_U8 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_xor_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ret ^ value)
}
# 787 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_xor_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ret ^ value)
}
# 805 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_xor_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret ^ value)
}
# 823 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_xor_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ret ^ value)
}

#if defined(__SEGGER_RTL_U128)
# 842 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_xor_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ret ^ value)
}
#endif
# 861 "./atomicops.c"
__SEGGER_RTL_U8 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_nand_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U8, ~(ret & value))
}
# 879 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_nand_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U16, ~(ret & value))
}
# 897 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_nand_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_ATOMIC_U32, ~(ret & value))
}
# 915 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_nand_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U64, ~(ret & value))
}

#if defined(__SEGGER_RTL_U128)
# 934 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_fetch_and_nand_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_FETCH_AND_OP(ptr, value, __SEGGER_RTL_U128, ~(ret & value))
}
#endif
# 953 "./atomicops.c"
__SEGGER_RTL_U8 __sync_add_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret + value)
}
# 971 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_add_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ret + value)
}
# 989 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_add_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret + value)
}
# 1007 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_add_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ret + value)
}

#if defined(__SEGGER_RTL_U128)
# 1026 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_add_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U128, ret + value)
}
#endif
# 1045 "./atomicops.c"
__SEGGER_RTL_U8 __sync_sub_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret - value)
}
# 1063 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_sub_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ret - value)
}
# 1081 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_sub_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret - value)
}
# 1099 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_sub_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ret - value)
}

#if defined(__SEGGER_RTL_U128)
# 1118 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_sub_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ret - value)
}
#endif
# 1137 "./atomicops.c"
__SEGGER_RTL_U8 __sync_and_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret & value)
}
# 1155 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_and_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret & value)
}
# 1173 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_and_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret & value)
}
# 1191 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_and_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ret & value)
}

#if defined(__SEGGER_RTL_U128)
# 1210 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_and_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U128, ret & value)
}
#endif
# 1229 "./atomicops.c"
__SEGGER_RTL_U8 __sync_or_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret | value)
}
# 1247 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_or_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ret | value)
}
# 1265 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_or_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret | value)
}
# 1283 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_or_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ret | value)
}

#if defined(__SEGGER_RTL_U128)
# 1302 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_or_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U128, ret | value)
}
#endif
# 1321 "./atomicops.c"
__SEGGER_RTL_U8 __sync_xor_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ret ^ value)
}
# 1339 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_xor_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ret ^ value)
}
# 1357 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_xor_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ret ^ value)
}
# 1375 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_xor_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ret ^ value)
}

#if defined(__SEGGER_RTL_U128)
# 1394 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_xor_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U128, ret ^ value)
}
#endif
# 1413 "./atomicops.c"
__SEGGER_RTL_U8 __sync_nand_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U8, ~(ret & value))
}
# 1431 "./atomicops.c"
__SEGGER_RTL_U16 __SEGGER_RTL_PUBLIC_API __sync_nand_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U16, ~(ret & value))
}
# 1449 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __SEGGER_RTL_PUBLIC_API __sync_nand_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_ATOMIC_U32, ~(ret & value))
}
# 1467 "./atomicops.c"
__SEGGER_RTL_U64 __SEGGER_RTL_PUBLIC_API __sync_nand_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U64, ~(ret & value))
}

#if defined(__SEGGER_RTL_U128)
# 1486 "./atomicops.c"
__SEGGER_RTL_U128 __SEGGER_RTL_PUBLIC_API __sync_nand_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_OP_AND_FETCH(ptr, value, __SEGGER_RTL_U128, ~(ret & value))
}
#endif
# 1507 "./atomicops.c"
__SEGGER_RTL_BOOL __sync_bool_compare_and_swap_1(volatile void *ptr, __SEGGER_RTL_U8 oldval, __SEGGER_RTL_U8 newval) {
  SYNC_BOOL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U8)
}
# 1527 "./atomicops.c"
__SEGGER_RTL_BOOL __sync_bool_compare_and_swap_2(volatile void *ptr, __SEGGER_RTL_U16 oldval, __SEGGER_RTL_U16 newval) {
  SYNC_BOOL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U16)
}
# 1547 "./atomicops.c"
__SEGGER_RTL_BOOL __sync_bool_compare_and_swap_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 oldval, __SEGGER_RTL_ATOMIC_U32 newval) {
  SYNC_BOOL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_ATOMIC_U32)
}
# 1567 "./atomicops.c"
__SEGGER_RTL_BOOL __sync_bool_compare_and_swap_8(volatile void *ptr, __SEGGER_RTL_U64 oldval, __SEGGER_RTL_U64 newval) {
  SYNC_BOOL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 1588 "./atomicops.c"
__SEGGER_RTL_BOOL __sync_bool_compare_and_swap_16(volatile void *ptr, __SEGGER_RTL_U128 oldval, __SEGGER_RTL_U128 newval) {
  SYNC_BOOL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U128)
}
#endif
# 1609 "./atomicops.c"
__SEGGER_RTL_U8 __sync_val_compare_and_swap_1(volatile void *ptr, __SEGGER_RTL_U8 oldval, __SEGGER_RTL_U8 newval) {
  SYNC_VAL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U8)
}
# 1629 "./atomicops.c"
__SEGGER_RTL_U16 __sync_val_compare_and_swap_2(volatile void *ptr, __SEGGER_RTL_U16 oldval, __SEGGER_RTL_U16 newval) {
  SYNC_VAL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U16)
}
# 1649 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __sync_val_compare_and_swap_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 oldval, __SEGGER_RTL_ATOMIC_U32 newval) {
  SYNC_VAL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_ATOMIC_U32)
}
# 1669 "./atomicops.c"
__SEGGER_RTL_U64 __sync_val_compare_and_swap_8(volatile void *ptr, __SEGGER_RTL_U64 oldval, __SEGGER_RTL_U64 newval) {
  SYNC_VAL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 1690 "./atomicops.c"
__SEGGER_RTL_U128 __sync_val_compare_and_swap_16(volatile void *ptr, __SEGGER_RTL_U128 oldval, __SEGGER_RTL_U128 newval) {
  SYNC_VAL_COMPARE_AND_SWAP(ptr, oldval, newval, __SEGGER_RTL_U128)
}
#endif
# 1709 "./atomicops.c"
__SEGGER_RTL_U8 __sync_lock_test_and_set_1(volatile void *ptr, __SEGGER_RTL_U8 value) {
  SYNC_LOCK_TEST_AND_SET(ptr, value, __SEGGER_RTL_U8)
}
# 1727 "./atomicops.c"
__SEGGER_RTL_U16 __sync_lock_test_and_set_2(volatile void *ptr, __SEGGER_RTL_U16 value) {
  SYNC_LOCK_TEST_AND_SET(ptr, value, __SEGGER_RTL_U16)
}
# 1745 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __sync_lock_test_and_set_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value) {
  SYNC_LOCK_TEST_AND_SET(ptr, value, __SEGGER_RTL_ATOMIC_U32)
}
# 1763 "./atomicops.c"
__SEGGER_RTL_U64 __sync_lock_test_and_set_8(volatile void *ptr, __SEGGER_RTL_U64 value) {
  SYNC_LOCK_TEST_AND_SET(ptr, value, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 1782 "./atomicops.c"
__SEGGER_RTL_U128 __sync_lock_test_and_set_16(volatile void *ptr, __SEGGER_RTL_U128 value) {
  SYNC_LOCK_TEST_AND_SET(ptr, value, __SEGGER_RTL_U128)
}
#endif
# 1797 "./atomicops.c"
void __sync_lock_release_1(volatile void *ptr) {
  SYNC_LOCK_RELEASE(ptr, __SEGGER_RTL_U8)
}
# 1811 "./atomicops.c"
void __sync_lock_release_2(volatile void *ptr) {
  SYNC_LOCK_RELEASE(ptr, __SEGGER_RTL_U16)
}
# 1825 "./atomicops.c"
void __sync_lock_release_4(volatile void *ptr) {
  SYNC_LOCK_RELEASE(ptr, __SEGGER_RTL_ATOMIC_U32)
}
# 1839 "./atomicops.c"
void __sync_lock_release_8(volatile void *ptr) {
  SYNC_LOCK_RELEASE(ptr, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 1854 "./atomicops.c"
void __sync_lock_release_16(volatile void *ptr) {
  SYNC_LOCK_RELEASE(ptr, __SEGGER_RTL_U128)
}
#endif
# 1873 "./atomicops.c"
void __SEGGER_RTL_PUBLIC_API __atomic_load(size_t size, const volatile void *ptr, void *ret, int memorder) {
  int en;

  __SEGGER_RTL_USE_PARA(memorder);

  en = __SEGGER_RTL_ATOMIC_LOCK();
  (memcpy)(ret, (const void *)ptr, size);
  __SEGGER_RTL_ATOMIC_UNLOCK(en);
}
# 1896 "./atomicops.c"
void __SEGGER_RTL_PUBLIC_API __atomic_store(size_t size, volatile void *ptr, void *val, int memorder) {
  int en;

  __SEGGER_RTL_USE_PARA(memorder);

  en = __SEGGER_RTL_ATOMIC_LOCK();
  (memcpy)((void *)ptr, val, size);
  __SEGGER_RTL_ATOMIC_UNLOCK(en);
}
# 1926 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_is_lock_free(size_t size, const volatile void *ptr) {
  return __SEGGER_RTL_ATOMIC_IS_LOCK_FREE(size, ptr);
}
# 1944 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_load_1(const volatile void *ptr, int memorder) {
  ATOMIC_LOAD(ptr, memorder, __SEGGER_RTL_U8)
}
# 1962 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_load_2(const volatile void *ptr, int memorder) {
  ATOMIC_LOAD(ptr, memorder, __SEGGER_RTL_U16)
}
# 1980 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_load_4(const volatile void *ptr, int memorder) {
  ATOMIC_LOAD(ptr, memorder, __SEGGER_RTL_ATOMIC_U32)
}
# 1998 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_load_8(const volatile void *ptr, int memorder) {
  ATOMIC_LOAD(ptr, memorder, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 2017 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_load_16(const volatile void *ptr, int memorder) {
  ATOMIC_LOAD(ptr, memorder, __SEGGER_RTL_U128)
}
#endif
# 2036 "./atomicops.c"
void __atomic_store_1(volatile void *ptr, __SEGGER_RTL_U8 val, int memorder) {
  ATOMIC_STORE(ptr, val, memorder, __SEGGER_RTL_U8)
}
# 2054 "./atomicops.c"
void __atomic_store_2(volatile void *ptr, __SEGGER_RTL_U16 val, int memorder) {
  ATOMIC_STORE(ptr, val, memorder, __SEGGER_RTL_U16)
}
# 2072 "./atomicops.c"
void __atomic_store_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 val, int memorder) {
  ATOMIC_STORE(ptr, val, memorder, __SEGGER_RTL_ATOMIC_U32)
}
# 2090 "./atomicops.c"
void __atomic_store_8(volatile void *ptr, __SEGGER_RTL_U64 val, int memorder) {
  ATOMIC_STORE(ptr, val, memorder, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 2109 "./atomicops.c"
void __atomic_store_16(volatile void *ptr, __SEGGER_RTL_U128 val, int memorder) {
  ATOMIC_STORE(ptr, val, memorder, __SEGGER_RTL_U128)
}
#endif
# 2129 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_add_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret + value)
}
# 2148 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_add_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret + value)
}
# 2167 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_add_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret + value)
}
# 2186 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_add_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret + value)
}

#if defined(__SEGGER_RTL_U128)
# 2206 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_add_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret + value)
}
#endif
# 2226 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_sub_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret - value)
}
# 2245 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_sub_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret - value)
}
# 2264 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_sub_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret - value)
}
# 2283 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_sub_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret - value)
}

#if defined(__SEGGER_RTL_U128)
# 2303 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_sub_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret - value)
}
#endif
# 2323 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_and_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret & value)
}
# 2342 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_and_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret & value)
}
# 2361 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_and_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret & value)
}
# 2380 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_and_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret & value)
}

#if defined(__SEGGER_RTL_U128)
# 2400 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_and_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret & value)
}
#endif
# 2420 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_or_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret | value)
}
# 2439 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_or_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret | value)
}
# 2458 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_or_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret | value)
}
# 2477 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_or_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret | value)
}

#if defined(__SEGGER_RTL_U128)
# 2497 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_or_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret | value)
}
#endif
# 2517 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_xor_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret ^ value)
}
# 2536 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_xor_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret ^ value)
}
# 2555 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_xor_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret ^ value)
}
# 2574 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_xor_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret ^ value)
}

#if defined(__SEGGER_RTL_U128)
# 2594 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_xor_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret ^ value)
}
#endif
# 2614 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_nand_fetch_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ~(ret & value))
}
# 2633 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_nand_fetch_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ~(ret & value))
}
# 2652 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_nand_fetch_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ~(ret & value))
}
# 2671 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_nand_fetch_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ~(ret & value))
}

#if defined(__SEGGER_RTL_U128)
# 2691 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_nand_fetch_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ~(ret & value))
}
#endif
# 2711 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_add_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret + value)
}
# 2730 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_add_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret + value)
}
# 2749 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_add_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret + value)
}
# 2768 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_add_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret + value)
}

#if defined(__SEGGER_RTL_U128)
# 2788 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_add_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret + value)
}
#endif
# 2808 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_sub_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret - value)
}
# 2827 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_sub_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret - value)
}
# 2846 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_sub_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret - value)
}
# 2865 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_sub_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret - value)
}

#if defined(__SEGGER_RTL_U128)
# 2885 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_sub_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret - value)
}
#endif
# 2905 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_and_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret & value)
}
# 2924 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_and_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret & value)
}
# 2943 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_and_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret & value)
}
# 2962 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_and_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret & value)
}

#if defined(__SEGGER_RTL_U128)
# 2982 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_and_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret & value)
}
#endif
# 3002 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_or_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret | value)
}
# 3021 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_or_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret | value)
}
# 3040 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_or_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret | value)
}
# 3059 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_or_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret | value)
}

#if defined(__SEGGER_RTL_U128)
# 3079 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_or_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret | value)
}
#endif
# 3099 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_xor_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ret ^ value)
}
# 3118 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_xor_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ret ^ value)
}
# 3137 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_xor_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ret ^ value)
}
# 3156 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_xor_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ret ^ value)
}

#if defined(__SEGGER_RTL_U128)
# 3176 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_xor_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ret ^ value)
}
#endif
# 3196 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_fetch_nand_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U8, ~(ret & value))
}
# 3215 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_fetch_nand_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U16, ~(ret & value))
}
# 3234 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_fetch_nand_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32, ~(ret & value))
}
# 3253 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_fetch_nand_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U64, ~(ret & value))
}

#if defined(__SEGGER_RTL_U128)
# 3273 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_fetch_nand_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_OP_FETCH(ptr, value, memorder, __SEGGER_RTL_U128, ~(ret & value))
}
#endif
# 3293 "./atomicops.c"
__SEGGER_RTL_U8 __atomic_exchange_1(volatile void *ptr, __SEGGER_RTL_U8 value, int memorder) {
  ATOMIC_EXCHANGE(ptr, value, memorder, __SEGGER_RTL_U8)
}
# 3312 "./atomicops.c"
__SEGGER_RTL_U16 __atomic_exchange_2(volatile void *ptr, __SEGGER_RTL_U16 value, int memorder) {
  ATOMIC_EXCHANGE(ptr, value, memorder, __SEGGER_RTL_U16)
}
# 3331 "./atomicops.c"
__SEGGER_RTL_ATOMIC_U32 __atomic_exchange_4(volatile void *ptr, __SEGGER_RTL_ATOMIC_U32 value, int memorder) {
  ATOMIC_EXCHANGE(ptr, value, memorder, __SEGGER_RTL_ATOMIC_U32)
}
# 3350 "./atomicops.c"
__SEGGER_RTL_U64 __atomic_exchange_8(volatile void *ptr, __SEGGER_RTL_U64 value, int memorder) {
  ATOMIC_EXCHANGE(ptr, value, memorder, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 3370 "./atomicops.c"
__SEGGER_RTL_U128 __atomic_exchange_16(volatile void *ptr, __SEGGER_RTL_U128 value, int memorder) {
  ATOMIC_EXCHANGE(ptr, value, memorder, __SEGGER_RTL_U128)
}
#endif
# 3399 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_compare_exchange_1(volatile void *ptr, void *expected, __SEGGER_RTL_U8 desired, __SEGGER_RTL_BOOL weak, int success_memorder, int failure_memorder) {
  ATOMIC_COMPARE_EXCHANGE(ptr, expected, desired, weak, success_memorder, failure_memorder, __SEGGER_RTL_U8)
}
# 3427 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_compare_exchange_2(volatile void *ptr, void *expected, __SEGGER_RTL_U16 desired, __SEGGER_RTL_BOOL weak, int success_memorder, int failure_memorder) {
  ATOMIC_COMPARE_EXCHANGE(ptr, expected, desired, weak, success_memorder, failure_memorder, __SEGGER_RTL_U16)
}
# 3455 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_compare_exchange_4(volatile void *ptr, void *expected, __SEGGER_RTL_ATOMIC_U32 desired, __SEGGER_RTL_BOOL weak, int success_memorder, int failure_memorder) {
  ATOMIC_COMPARE_EXCHANGE(ptr, expected, desired, weak, success_memorder, failure_memorder, __SEGGER_RTL_ATOMIC_U32)
}
# 3483 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_compare_exchange_8(volatile void *ptr, void *expected, __SEGGER_RTL_U64 desired, __SEGGER_RTL_BOOL weak, int success_memorder, int failure_memorder) {
  ATOMIC_COMPARE_EXCHANGE(ptr, expected, desired, weak, success_memorder, failure_memorder, __SEGGER_RTL_U64)
}

#if defined(__SEGGER_RTL_U128)
# 3512 "./atomicops.c"
__SEGGER_RTL_BOOL __atomic_compare_exchange_16(volatile void *ptr, void *expected, __SEGGER_RTL_U128 desired, __SEGGER_RTL_BOOL weak, int success_memorder, int failure_memorder) {
  ATOMIC_COMPARE_EXCHANGE(ptr, expected, desired, weak, success_memorder, failure_memorder, __SEGGER_RTL_U128)
}
#endif
