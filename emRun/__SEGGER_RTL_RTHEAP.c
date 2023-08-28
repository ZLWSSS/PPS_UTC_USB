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
# 1 "./__SEGGER_RTL_RTHEAP.c"
# 20 "./__SEGGER_RTL_RTHEAP.c"
#include "__SEGGER_RTL_RTHEAP.h"
# 29 "./__SEGGER_RTL_RTHEAP.c"
#define HEAP_FLAG_FREE (1 << 0u)
#define HEAP_ALIGNED(X,A) (__SEGGER_RTL_RTHEAP_AlignPtr(X, A) == (X))
#define HEAP_ISPOW2(X) (((X) & ((X)-1)) == 0)
#define HEAP_PTRDIFF(X,Y) ((const char *)(X) - (const char *)(Y))
#define HEAP_DATA_OFFSET offsetof(__SEGGER_RTL_RTHEAP_BLOCK, u.Used.aData)
#define HEAP_MAX_HEAP_SIZE (((__SEGGER_RTL_RTHEAP_SIZE)1 << __SEGGER_RTL_RTHEAP_L1_INDEX_MAX_BITS) - HEAP_DATA_OFFSET)
#define HEAP_IO(...) if (pIoFunc) pIoFunc(__VA_ARGS__)
#define HEAP_CK(X,...) if (!(X)) { ++TotalErrorCnt; ++LocalErrorCnt; if (pIoFunc) pIoFunc(__VA_ARGS__); }


#if __SEGGER_RTL_RTHEAP_DEBUG_LEVEL >= 1
  #define HEAP_API_CHECK(X) if (!(X)) __SEGGER_RTL_RTHEAP_PANIC();
#endif
#if __SEGGER_RTL_RTHEAP_DEBUG_LEVEL >= 2
  #define HEAP_INT_CHECK(X) if (!(X)) __SEGGER_RTL_RTHEAP_PANIC();
#endif
#if __SEGGER_RTL_RTHEAP_DEBUG_LEVEL >= 3
  #define HEAP_INT_SET(A, B, L) __SEGGER_RTL_RTHEAP_MEMSET(A, B, L)
#endif

#ifndef HEAP_API_CHECK
  #define HEAP_API_CHECK(X)
#endif
#ifndef HEAP_INT_CHECK
  #define HEAP_INT_CHECK(X)
#endif
#ifndef HEAP_INT_SET
  #define HEAP_INT_SET(A, B, L)
#endif
# 66 "./__SEGGER_RTL_RTHEAP.c"
typedef struct {
  int L1Index;
  int L2Index;
} __SEGGER_RTL_RTHEAP_INDEX;

struct __SEGGER_RTL_RTHEAP_BLOCK_HEADER_t {
  __SEGGER_RTL_RTHEAP_BLOCK * pBlockBefore;
  __SEGGER_RTL_RTHEAP_SIZE SizeAndFlags;
  union {
    struct {
      __SEGGER_RTL_RTHEAP_BLOCK * pNextFree;
      __SEGGER_RTL_RTHEAP_BLOCK * pPrevFree;
    } Free;
    struct {
      char aData[1];
    } Used;
  } u;
};
# 92 "./__SEGGER_RTL_RTHEAP.c"
#if defined(__SEGGER_RTL_RTHEAP_MEMSET_SYNTHESIZED)
# 105 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_MEMSET_func(void *pMem, unsigned Byte, __SEGGER_RTL_RTHEAP_SIZE Len) {
  __SEGGER_RTL_RTHEAP_ALIGNED_UNIT * pWord;
  __SEGGER_RTL_RTHEAP_ALIGNED_UNIT Word;
  __SEGGER_RTL_RTHEAP_SIZE n;

  Byte &= 0xFF;

  pWord = (__SEGGER_RTL_RTHEAP_ALIGNED_UNIT *)pMem;
  Word = __SEGGER_RTL_RTHEAP_ALIGNED_UNIT_REPL(Byte);

  for (n = Len / sizeof(__SEGGER_RTL_RTHEAP_ALIGNED_UNIT); n >= 8; n -= 8) {
    *pWord++ = Word; *pWord++ = Word; *pWord++ = Word; *pWord++ = Word;
    *pWord++ = Word; *pWord++ = Word; *pWord++ = Word; *pWord++ = Word;
  }
  while (n > 0) {
    *pWord++ = Word;
    n -= 1;
  }
}
#endif

#if defined(__SEGGER_RTL_RTHEAP_MEMMOVE_SYNTHESIZED)
# 145 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_MEMMOVE_func(__SEGGER_RTL_RTHEAP_ALIGNED_UNIT * pTo,
                                             __SEGGER_RTL_RTHEAP_ALIGNED_UNIT * pFrom,
                                             __SEGGER_RTL_RTHEAP_SIZE Len) {
  __SEGGER_RTL_RTHEAP_SIZE n;

  for (n = Len / sizeof(__SEGGER_RTL_RTHEAP_ALIGNED_UNIT); n >= 8; n -= 8) {
    *pTo++ = *pFrom++; *pTo++ = *pFrom++; *pTo++ = *pFrom++; *pTo++ = *pFrom++;
    *pTo++ = *pFrom++; *pTo++ = *pFrom++; *pTo++ = *pFrom++; *pTo++ = *pFrom++;
  }
  while (n > 0) {
    *pTo++ = *pFrom++;
    n -= 1;
  }
}
#endif

#if defined(__SEGGER_RTL_RTHEAP_FLS_SYNTHESIZED)
# 175 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_FLS_func(unsigned Word) {
  int n;

  HEAP_INT_CHECK(Word != 0);

  n = 31;
  if ((Word >> 16) == 0) { Word <<= 16; n -= 16; }
  if ((Word >> 24) == 0) { Word <<= 8; n -= 8; }
  if ((Word >> 28) == 0) { Word <<= 4; n -= 4; }
  if ((Word >> 30) == 0) { Word <<= 2; n -= 2; }
  if ((Word >> 31) == 0) { n -= 1; }

  return n;
}
#endif

#if defined(__SEGGER_RTL_RTHEAP_FFS_SYNTHESIZED)
# 205 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_FFS_func(unsigned Word) {
  return __SEGGER_RTL_RTHEAP_FLS(Word & (0u - Word));
}
#endif

#if defined(__SEGGER_RTL_RTHEAP_FLSL_SYNTHESIZED)
# 224 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_FLSL_func(__SEGGER_RTL_RTHEAP_SIZE Word) {
  unsigned Hi;

  Hi = (unsigned)(Word >> 32);
  if (Hi) {
    return 32 + __SEGGER_RTL_RTHEAP_FLS(Hi);
  } else {
    return __SEGGER_RTL_RTHEAP_FLS((unsigned)(Word & 0xFFFFFFFFu));
  }
}
#endif
# 251 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_SIZE __SEGGER_RTL_RTHEAP_AdjustUp(__SEGGER_RTL_RTHEAP_SIZE Size, __SEGGER_RTL_RTHEAP_SIZE Align) {
  return (Size + (Align - 1)) & (0u - Align);
}
# 270 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_SIZE __SEGGER_RTL_RTHEAP_AdjustDown(__SEGGER_RTL_RTHEAP_SIZE Size, __SEGGER_RTL_RTHEAP_SIZE Align) {
  return Size - (Size & (Align - 1));
}
# 289 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE void * __SEGGER_RTL_RTHEAP_AlignPtr(void *pVoid, __SEGGER_RTL_RTHEAP_SIZE Align) {
  return (void *)(((__SEGGER_RTL_RTHEAP_SIZE)pVoid + (Align - 1)) & (0u - Align));
}
# 307 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_SIZE __SEGGER_RTL_RTHEAP_ConstrainSize(__SEGGER_RTL_RTHEAP_SIZE Size, __SEGGER_RTL_RTHEAP_SIZE Align) {
  Size = __SEGGER_RTL_RTHEAP_AdjustUp(Size, Align);
  return Size < sizeof(__SEGGER_RTL_RTHEAP_BLOCK) ? sizeof(__SEGGER_RTL_RTHEAP_BLOCK) : Size;
}
# 328 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_BLOCK * __SEGGER_RTL_RTHEAP_ToBlock(void *pVoid) {
  return (__SEGGER_RTL_RTHEAP_BLOCK *)((char *)pVoid - HEAP_DATA_OFFSET);
}
# 345 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE void * __SEGGER_RTL_RTHEAP_ToData(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  return pBlock->u.Used.aData;
}
# 363 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_SIZE __SEGGER_RTL_RTHEAP_GetBlockSize(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  return pBlock->SizeAndFlags & ~HEAP_FLAG_FREE;
}
# 385 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_IsSentinelBlock(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  return pBlock->SizeAndFlags == 0;
}
# 403 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_IsBlockFree(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  return (int)(pBlock->SizeAndFlags & HEAP_FLAG_FREE);
}
# 417 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE void __SEGGER_RTL_RTHEAP_MarkFree(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  pBlock->SizeAndFlags |= HEAP_FLAG_FREE;
}
# 431 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE void __SEGGER_RTL_RTHEAP_MarkUsed(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  pBlock->SizeAndFlags &= ~HEAP_FLAG_FREE;
}
# 449 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_SkipBlock(__SEGGER_RTL_RTHEAP_BLOCK *pBlock, __SEGGER_RTL_RTHEAP_SIZE Size) {
  return (__SEGGER_RTL_RTHEAP_BLOCK *)((char *)pBlock + Size);
}
# 469 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_GetBlockAfter(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  HEAP_INT_CHECK(!__SEGGER_RTL_RTHEAP_IsSentinelBlock(pBlock));

  return __SEGGER_RTL_RTHEAP_SkipBlock(pBlock, __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock));
}
# 488 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_GetBlockBefore(__SEGGER_RTL_RTHEAP_BLOCK* pBlock) {
  return pBlock->pBlockBefore;
}
# 506 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE void __SEGGER_RTL_RTHEAP_FixBackinkTo(__SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  __SEGGER_RTL_RTHEAP_GetBlockAfter(pBlock)->pBlockBefore = pBlock;
}
# 524 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE __SEGGER_RTL_RTHEAP_INDEX __SEGGER_RTL_RTHEAP_MakeIndex(int L1Index, int L2Index) {
  __SEGGER_RTL_RTHEAP_INDEX Index;

  Index.L1Index = L1Index;
  Index.L2Index = L2Index;

  return Index;
}
# 546 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INDEX __SEGGER_RTL_RTHEAP_Map(__SEGGER_RTL_RTHEAP_SIZE Size) {
  int L1Index;
  int L2Index;

  if (Size < __SEGGER_RTL_RTHEAP_L2_MAX_SZ) {



    L1Index = 0;
    L2Index = (unsigned)Size / __SEGGER_RTL_RTHEAP_ALIGN_SZ;

  } else {



    L1Index = __SEGGER_RTL_RTHEAP_FLSL(Size);
    L2Index = (int)(Size >> (L1Index - __SEGGER_RTL_RTHEAP_L2_INDEX_BITS)) - (1 << __SEGGER_RTL_RTHEAP_L2_INDEX_BITS);
    L1Index -= __SEGGER_RTL_RTHEAP_L2_MAX_BITS - 1;
  }

  return __SEGGER_RTL_RTHEAP_MakeIndex(L1Index, L2Index);
}
# 585 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INDEX __SEGGER_RTL_RTHEAP_Pick(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                                          __SEGGER_RTL_RTHEAP_INDEX Index) {
  unsigned L1Map;
  unsigned L2Map;



  L2Map = pSelf->aL2Bitmap[Index.L1Index] & (~0u << Index.L2Index);
  if (L2Map == 0u) {



    L1Map = pSelf->L1Bitmap & (~0u << (Index.L1Index + 1));
    if (L1Map == 0u) {



      Index.L1Index = -1;
      return Index;
    }

    Index.L1Index = __SEGGER_RTL_RTHEAP_FFS(L1Map);
    L2Map = pSelf->aL2Bitmap[Index.L1Index];
  }

  HEAP_INT_CHECK(L2Map != 0);

  Index.L2Index = __SEGGER_RTL_RTHEAP_FFS(L2Map);
  return Index;
}
# 629 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_TakeBlockWithIndex(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                                   __SEGGER_RTL_RTHEAP_BLOCK * pBlock,
                                                   __SEGGER_RTL_RTHEAP_INDEX Index) {
  __SEGGER_RTL_RTHEAP_BLOCK *pPrev;
  __SEGGER_RTL_RTHEAP_BLOCK *pNext;

  pPrev = pBlock->u.Free.pPrevFree;
  pNext = pBlock->u.Free.pNextFree;



  if (pNext) { pNext->u.Free.pPrevFree = pPrev; }
  if (pPrev) { pPrev->u.Free.pNextFree = pNext; }



  if (pSelf->aBlocks[Index.L1Index][Index.L2Index] == pBlock) {
    pSelf->aBlocks[Index.L1Index][Index.L2Index] = pNext;



    if (pNext == NULL) {



      if ((pSelf->aL2Bitmap[Index.L1Index] &= ~(1u << Index.L2Index)) == 0) {
        pSelf->L1Bitmap &= ~(1u << Index.L1Index);
      }
    }
  }
}
# 673 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_TakeBlock(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                          __SEGGER_RTL_RTHEAP_BLOCK * pBlock) {
  __SEGGER_RTL_RTHEAP_TakeBlockWithIndex(pSelf,
                                         pBlock,
                                         __SEGGER_RTL_RTHEAP_Map(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock)));
}
# 692 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_GiveBlock(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, __SEGGER_RTL_RTHEAP_BLOCK *pBlock) {
  __SEGGER_RTL_RTHEAP_BLOCK * pHead;
  __SEGGER_RTL_RTHEAP_INDEX Index;

  HEAP_INT_CHECK(pBlock != NULL);
  HEAP_INT_CHECK(HEAP_ALIGNED(__SEGGER_RTL_RTHEAP_ToData(pBlock), __SEGGER_RTL_RTHEAP_ALIGN_SZ));



  Index = __SEGGER_RTL_RTHEAP_Map(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock));



  pHead = pSelf->aBlocks[Index.L1Index][Index.L2Index];
  pSelf->aBlocks[Index.L1Index][Index.L2Index] = pBlock;
  pBlock->u.Free.pNextFree = pHead;
  pBlock->u.Free.pPrevFree = NULL;
  if (pHead != NULL) { pHead->u.Free.pPrevFree = pBlock; }



  pSelf->L1Bitmap |= 1u << Index.L1Index;
  pSelf->aL2Bitmap[Index.L1Index] |= 1u << Index.L2Index;



  HEAP_INT_SET(pBlock+1,
               __SEGGER_RTL_RTHEAP_FILL_FREED,
               __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) - sizeof(__SEGGER_RTL_RTHEAP_BLOCK));
}
# 741 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_SplitBlock(__SEGGER_RTL_RTHEAP_BLOCK *pBlock, __SEGGER_RTL_RTHEAP_SIZE Size) {
  __SEGGER_RTL_RTHEAP_BLOCK * pTailBlock;
  __SEGGER_RTL_RTHEAP_SIZE TailSize;

  HEAP_INT_CHECK(Size % __SEGGER_RTL_RTHEAP_ALIGN_SZ == 0);





  if (__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) < Size + sizeof(__SEGGER_RTL_RTHEAP_BLOCK)) {
    return NULL;
  }



  TailSize = __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) - Size;




  pBlock->SizeAndFlags = Size | (pBlock->SizeAndFlags & HEAP_FLAG_FREE);



  pTailBlock = __SEGGER_RTL_RTHEAP_SkipBlock(pBlock, Size);
  pTailBlock->SizeAndFlags = TailSize | HEAP_FLAG_FREE;
  pTailBlock->pBlockBefore = pBlock;
  __SEGGER_RTL_RTHEAP_FixBackinkTo(pTailBlock);

  return pTailBlock;
}
# 785 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_JoinBlocks(__SEGGER_RTL_RTHEAP_BLOCK *pBlock,
                                           __SEGGER_RTL_RTHEAP_BLOCK *pAfter) {
  pBlock->SizeAndFlags += __SEGGER_RTL_RTHEAP_GetBlockSize(pAfter);
  __SEGGER_RTL_RTHEAP_FixBackinkTo(pBlock);
}
# 805 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_MergeWithBefore(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                                                      __SEGGER_RTL_RTHEAP_BLOCK * pBlock) {
  __SEGGER_RTL_RTHEAP_BLOCK *pBefore;

  pBefore = __SEGGER_RTL_RTHEAP_GetBlockBefore(pBlock);
  if (__SEGGER_RTL_RTHEAP_IsBlockFree(pBefore)) {
    __SEGGER_RTL_RTHEAP_TakeBlock(pSelf, pBefore);
    __SEGGER_RTL_RTHEAP_JoinBlocks(pBefore, pBlock);
    pBlock = pBefore;
  }

  return pBlock;
}
# 830 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_MergeWithAfter(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                               __SEGGER_RTL_RTHEAP_BLOCK * pBlock) {
  __SEGGER_RTL_RTHEAP_BLOCK *pAfter;

  pAfter = __SEGGER_RTL_RTHEAP_GetBlockAfter(pBlock);
  if (__SEGGER_RTL_RTHEAP_IsBlockFree(pAfter)) {
    __SEGGER_RTL_RTHEAP_TakeBlock(pSelf, pAfter);
    __SEGGER_RTL_RTHEAP_JoinBlocks(pBlock, pAfter);
  }
}
# 853 "./__SEGGER_RTL_RTHEAP.c"
static void __SEGGER_RTL_RTHEAP_TrimBlock(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                          __SEGGER_RTL_RTHEAP_BLOCK * pBlock,
                                          __SEGGER_RTL_RTHEAP_SIZE Size) {
  __SEGGER_RTL_RTHEAP_BLOCK *pExcess;

  if ((pExcess = __SEGGER_RTL_RTHEAP_SplitBlock(pBlock, Size)) != NULL) {
    __SEGGER_RTL_RTHEAP_MergeWithAfter(pSelf, pExcess);
    __SEGGER_RTL_RTHEAP_GiveBlock(pSelf, pExcess);
  }
}
# 879 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_BLOCK *__SEGGER_RTL_RTHEAP_TakeFreeBlock(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                                                    __SEGGER_RTL_RTHEAP_SIZE Size) {
  __SEGGER_RTL_RTHEAP_BLOCK * pBlock;
  __SEGGER_RTL_RTHEAP_INDEX Index;



  Index = __SEGGER_RTL_RTHEAP_Pick(pSelf, __SEGGER_RTL_RTHEAP_Map(Size));



  if (Index.L1Index >= 0) {



    pBlock = pSelf->aBlocks[Index.L1Index][Index.L2Index];
    __SEGGER_RTL_RTHEAP_TakeBlockWithIndex(pSelf, pBlock, Index);

  } else {



    pBlock = NULL;
  }

  return pBlock;
}
# 922 "./__SEGGER_RTL_RTHEAP.c"
static __SEGGER_RTL_RTHEAP_INLINE int __SEGGER_RTL_RTHEAP_WalkHeap(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, __SEGGER_RTL_RTHEAP_IO_FUNC *pIoFunc) {
  __SEGGER_RTL_RTHEAP_BLOCK * pBlock;
  __SEGGER_RTL_RTHEAP_SIZE Size;
  int LastUsed;
  int ThisUsed;
  int L1Index;
  int L2Index;
  int LocalErrorCnt;
  int TotalErrorCnt;

  HEAP_IO("\n*** HEAP BLOCK REPORT ***\n\n");

  TotalErrorCnt = 0;
  LocalErrorCnt = 0;
  LastUsed = 1;

  for (pBlock = pSelf->pOrigin; !__SEGGER_RTL_RTHEAP_IsSentinelBlock(pBlock); pBlock = __SEGGER_RTL_RTHEAP_GetBlockAfter(pBlock)) {
    Size = __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock);

    HEAP_IO("%s block at %06x-%06x  size=%u",
            __SEGGER_RTL_RTHEAP_IsBlockFree(pBlock) ? "Free" : "Used",
            (unsigned)HEAP_PTRDIFF(pBlock, pSelf->pOrigin),
            (unsigned)HEAP_PTRDIFF(pBlock, pSelf->pOrigin) + (unsigned)Size - 1,
            (unsigned)Size);

    if (pBlock == pSelf->pOrigin) {
      HEAP_CK(pBlock->pBlockBefore == NULL, " ...origin block should have null back-link");
    } else {
      HEAP_CK(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) % __SEGGER_RTL_RTHEAP_ALIGN_SZ == 0, " ...block is misaligned");
      HEAP_CK(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) >= sizeof(__SEGGER_RTL_RTHEAP_BLOCK), " ...block is too small");
      HEAP_CK(__SEGGER_RTL_RTHEAP_GetBlockAfter(pBlock)->pBlockBefore == pBlock, " ...successor block isn't back-linked to this block");
    }

    ThisUsed = !__SEGGER_RTL_RTHEAP_IsBlockFree(pBlock);
    if (pBlock != pSelf->pOrigin && !LastUsed) {
      HEAP_CK(ThisUsed, " ...predecessor and this block cannot both be free");
    }
    LastUsed = ThisUsed;

    HEAP_IO("\n");
  }

  Size = __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock);

  HEAP_IO("Mark block at %06x         size=%u\n",
          (unsigned)HEAP_PTRDIFF(pBlock, pSelf->pOrigin),
          (unsigned)Size);

  HEAP_IO(LocalErrorCnt == 0 ? "\nNo errors\n\n" : "\nErrors found ***\n\n");

  HEAP_IO("*** BITMAP ACCURACY REPORT ***\n");

  for (L1Index = 0; L1Index < __SEGGER_RTL_RTHEAP_L1_INDEX_BITS; ++L1Index) {
    for (L2Index = 0; L2Index < __SEGGER_RTL_RTHEAP_L2_INDEX_SZ; ++L2Index) {
      __SEGGER_RTL_RTHEAP_INDEX Index;
      int L1Map;
      int L2Map;
      int L2Bitmap;

      L1Map = pSelf->L1Bitmap & (1u << L1Index);
      L2Bitmap = pSelf->aL2Bitmap[L1Index];
      L2Map = L2Bitmap & (1u << L2Index);
      pBlock = pSelf->aBlocks[L1Index][L2Index];

      if (L1Map == 0) {
        HEAP_CK(L2Map == 0, "empty L1 map entry but corresponding L2 map is not empty\n");
      }
      if (L2Map == 0) {
        HEAP_CK(pBlock == NULL, "empty L2 map but free list is not empty\n");
      } else {



        HEAP_CK(pBlock != NULL, "map indicates nonempty list but corresponding free list is empty\n");



        for (; pBlock != NULL; pBlock = pBlock->u.Free.pNextFree) {
          Index = __SEGGER_RTL_RTHEAP_Map(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock));
          HEAP_CK(__SEGGER_RTL_RTHEAP_IsBlockFree(pBlock), "block is free list but not flagged as free\n");
          HEAP_CK(Index.L1Index == L1Index && Index.L2Index == L2Index, "block-size index error, block assigned to incorrect list\n");
        }
      }
    }
  }

  HEAP_IO(LocalErrorCnt == 0 ? "\nNo errors\n\n" : "\nErrors found ***\n\n");

  return TotalErrorCnt;
}
# 1037 "./__SEGGER_RTL_RTHEAP.c"
void __SEGGER_RTL_RTHEAP_Init(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, void *pMem, __SEGGER_RTL_RTHEAP_SIZE MemSize) {
  __SEGGER_RTL_RTHEAP_BLOCK * pBeginBlock;
  __SEGGER_RTL_RTHEAP_BLOCK * pHeapBlock;
  __SEGGER_RTL_RTHEAP_BLOCK * pEndBlock;
  __SEGGER_RTL_RTHEAP_SIZE HeapSize;




  HEAP_API_CHECK(HEAP_ALIGNED(pMem, __SEGGER_RTL_RTHEAP_ALIGN_SZ));
  HEAP_API_CHECK(MemSize >= 3*sizeof(__SEGGER_RTL_RTHEAP_BLOCK));




  if (MemSize > HEAP_MAX_HEAP_SIZE) {
    MemSize = HEAP_MAX_HEAP_SIZE;
  }



  __SEGGER_RTL_RTHEAP_MEMSET(pSelf, 0, sizeof(*pSelf));
  pSelf->pOrigin = pMem;

  HeapSize = __SEGGER_RTL_RTHEAP_AdjustDown(MemSize, sizeof(__SEGGER_RTL_RTHEAP_BLOCK));



  HEAP_INT_SET(pMem, __SEGGER_RTL_RTHEAP_FILL_UNTOUCHED, HeapSize);






  pBeginBlock = pMem;
  pBeginBlock->SizeAndFlags = sizeof(__SEGGER_RTL_RTHEAP_BLOCK);
  pBeginBlock->pBlockBefore = NULL;



  pHeapBlock = __SEGGER_RTL_RTHEAP_GetBlockAfter(pBeginBlock);
  pHeapBlock->SizeAndFlags = (HeapSize - 2*sizeof(__SEGGER_RTL_RTHEAP_BLOCK)) | HEAP_FLAG_FREE;
  pHeapBlock->pBlockBefore = pBeginBlock;



  pEndBlock = __SEGGER_RTL_RTHEAP_GetBlockAfter(pHeapBlock);
  pEndBlock->SizeAndFlags = 0;
  pEndBlock->pBlockBefore = pHeapBlock;



  __SEGGER_RTL_RTHEAP_GiveBlock(pSelf, pHeapBlock);
}
# 1108 "./__SEGGER_RTL_RTHEAP.c"
void * __SEGGER_RTL_RTHEAP_Alloc(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, __SEGGER_RTL_RTHEAP_SIZE Size) {
  __SEGGER_RTL_RTHEAP_BLOCK *pBlock;
  __SEGGER_RTL_RTHEAP_BLOCK *pExcess;






  if (Size == 0) {
    return NULL;
  } else if (Size >= HEAP_MAX_HEAP_SIZE) {
    return NULL;
  }



  Size = __SEGGER_RTL_RTHEAP_ConstrainSize(Size + HEAP_DATA_OFFSET, __SEGGER_RTL_RTHEAP_ALIGN_SZ);



  pBlock = __SEGGER_RTL_RTHEAP_TakeFreeBlock(pSelf, Size);

  if (pBlock == NULL) {



    return NULL;

  } else {





    if ((pExcess = __SEGGER_RTL_RTHEAP_SplitBlock(pBlock, Size)) != NULL) {
      __SEGGER_RTL_RTHEAP_GiveBlock(pSelf, pExcess);
    }



    __SEGGER_RTL_RTHEAP_MarkUsed(pBlock);



    HEAP_INT_SET(__SEGGER_RTL_RTHEAP_ToData(pBlock),
                 __SEGGER_RTL_RTHEAP_FILL_ALLOCATED,
                 Size - HEAP_DATA_OFFSET);



    return __SEGGER_RTL_RTHEAP_ToData(pBlock);
  }
}
# 1180 "./__SEGGER_RTL_RTHEAP.c"
void * __SEGGER_RTL_RTHEAP_AllocAligned(__SEGGER_RTL_RTHEAP_CONTEXT * pSelf,
                                        __SEGGER_RTL_RTHEAP_SIZE Size,
                                        __SEGGER_RTL_RTHEAP_SIZE Align) {
  __SEGGER_RTL_RTHEAP_BLOCK * pBlock;
  __SEGGER_RTL_RTHEAP_BLOCK * pRetain;
  __SEGGER_RTL_RTHEAP_SIZE SplitPos;



  HEAP_API_CHECK(HEAP_ISPOW2(Align));






  if (Size == 0) {
    return NULL;
  } else if (Size >= HEAP_MAX_HEAP_SIZE) {
    return NULL;
  }

  Size = __SEGGER_RTL_RTHEAP_ConstrainSize(Size, __SEGGER_RTL_RTHEAP_ALIGN_SZ);



  if (Align < __SEGGER_RTL_RTHEAP_ALIGN_SZ) {



    Align = __SEGGER_RTL_RTHEAP_ALIGN_SZ;
    pBlock = __SEGGER_RTL_RTHEAP_TakeFreeBlock(pSelf, Size);
    if (pBlock == NULL) {
      return NULL;
    }
  } else {



    pBlock = __SEGGER_RTL_RTHEAP_TakeFreeBlock(pSelf, Size + 2*sizeof(__SEGGER_RTL_RTHEAP_BLOCK) + Align);
    if (pBlock == NULL) {
      return NULL;
    }



    SplitPos = HEAP_PTRDIFF(__SEGGER_RTL_RTHEAP_ToBlock(__SEGGER_RTL_RTHEAP_AlignPtr(__SEGGER_RTL_RTHEAP_ToData(pBlock+1), Align)),
                            pBlock);



    pRetain = __SEGGER_RTL_RTHEAP_SplitBlock(pBlock, SplitPos);
    __SEGGER_RTL_RTHEAP_GiveBlock(pSelf, pBlock);
    pBlock = pRetain;



    Size += HEAP_DATA_OFFSET;
  }



  __SEGGER_RTL_RTHEAP_MarkUsed(pBlock);
  __SEGGER_RTL_RTHEAP_TrimBlock(pSelf, pBlock, Size);

  HEAP_INT_CHECK(HEAP_ALIGNED(__SEGGER_RTL_RTHEAP_ToData(pBlock), Align));
  HEAP_INT_CHECK(__SEGGER_RTL_RTHEAP_GetBlockSize(pBlock) >= Size);



  HEAP_INT_SET(__SEGGER_RTL_RTHEAP_ToData(pBlock),
               __SEGGER_RTL_RTHEAP_FILL_ALLOCATED,
               Size - HEAP_DATA_OFFSET);

  return __SEGGER_RTL_RTHEAP_ToData(pBlock);
}
# 1278 "./__SEGGER_RTL_RTHEAP.c"
void * __SEGGER_RTL_RTHEAP_Realloc(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, void *pMem, __SEGGER_RTL_RTHEAP_SIZE Size) {
  __SEGGER_RTL_RTHEAP_BLOCK * pBlock;
  __SEGGER_RTL_RTHEAP_BLOCK * pAdjunct;
  __SEGGER_RTL_RTHEAP_SIZE BlockSize;
  __SEGGER_RTL_RTHEAP_SIZE JoinedSize;
  void * pNew;

  if (pMem == NULL) {




    return Size == 0 ? NULL : __SEGGER_RTL_RTHEAP_Alloc(pSelf, Size);

  } else if (Size >= HEAP_MAX_HEAP_SIZE) {





    return NULL;

  } else {





    HEAP_API_CHECK(HEAP_ALIGNED(pMem, __SEGGER_RTL_RTHEAP_ALIGN_SZ));
    HEAP_API_CHECK(!__SEGGER_RTL_RTHEAP_IsBlockFree(__SEGGER_RTL_RTHEAP_ToBlock(pMem)));

    pBlock = __SEGGER_RTL_RTHEAP_ToBlock(pMem);
    BlockSize = __SEGGER_RTL_RTHEAP_GetBlockSize(pBlock);
    Size = __SEGGER_RTL_RTHEAP_ConstrainSize(Size + HEAP_DATA_OFFSET,
                                             __SEGGER_RTL_RTHEAP_ALIGN_SZ);



    if (Size <= BlockSize) {
      if (Size < BlockSize) {
        __SEGGER_RTL_RTHEAP_TrimBlock(pSelf, pBlock, Size);
      }
      return __SEGGER_RTL_RTHEAP_ToData(pBlock);
    }





    pAdjunct = __SEGGER_RTL_RTHEAP_GetBlockAfter(pBlock);
    if (__SEGGER_RTL_RTHEAP_IsBlockFree(pAdjunct)) {
      JoinedSize = BlockSize + __SEGGER_RTL_RTHEAP_GetBlockSize(pAdjunct);
      if (JoinedSize >= Size) {
        __SEGGER_RTL_RTHEAP_MergeWithAfter(pSelf, pBlock);
        __SEGGER_RTL_RTHEAP_TrimBlock(pSelf, pBlock, Size);
        return __SEGGER_RTL_RTHEAP_ToData(pBlock);
      }
    }





    pAdjunct = __SEGGER_RTL_RTHEAP_GetBlockBefore(pBlock);
    if (__SEGGER_RTL_RTHEAP_IsBlockFree(pAdjunct)) {
      JoinedSize = BlockSize + __SEGGER_RTL_RTHEAP_GetBlockSize(pAdjunct);
      if (JoinedSize >= Size) {
        __SEGGER_RTL_RTHEAP_MergeWithBefore(pSelf, pBlock);
        __SEGGER_RTL_RTHEAP_MarkUsed(pAdjunct);
        __SEGGER_RTL_RTHEAP_MEMMOVE(__SEGGER_RTL_RTHEAP_ToData(pAdjunct), __SEGGER_RTL_RTHEAP_ToData(pBlock), BlockSize);
        __SEGGER_RTL_RTHEAP_TrimBlock(pSelf, pAdjunct, Size);
        return __SEGGER_RTL_RTHEAP_ToData(pAdjunct);
      }
    }




    pNew = __SEGGER_RTL_RTHEAP_Alloc(pSelf, Size);
    if (pNew != NULL) {
      __SEGGER_RTL_RTHEAP_MEMMOVE(pNew, pMem, BlockSize - HEAP_DATA_OFFSET);
      __SEGGER_RTL_RTHEAP_Free(pSelf, pMem);
    }

    return pNew;
  }
}
# 1378 "./__SEGGER_RTL_RTHEAP.c"
void __SEGGER_RTL_RTHEAP_Free(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, void *pMem) {
  __SEGGER_RTL_RTHEAP_BLOCK *pBlock;



  if (pMem == NULL) {
    return;
  }




  HEAP_API_CHECK(HEAP_ALIGNED(pMem, __SEGGER_RTL_RTHEAP_ALIGN_SZ));
  HEAP_API_CHECK(!__SEGGER_RTL_RTHEAP_IsBlockFree(__SEGGER_RTL_RTHEAP_ToBlock(pMem)));



  pBlock = __SEGGER_RTL_RTHEAP_ToBlock(pMem);
  __SEGGER_RTL_RTHEAP_MarkFree(pBlock);
  __SEGGER_RTL_RTHEAP_MergeWithAfter(pSelf, pBlock);
  __SEGGER_RTL_RTHEAP_GiveBlock(pSelf, __SEGGER_RTL_RTHEAP_MergeWithBefore(pSelf, pBlock));
}
# 1415 "./__SEGGER_RTL_RTHEAP.c"
int __SEGGER_RTL_RTHEAP_IsEmptyHeap(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf) {
  return __SEGGER_RTL_RTHEAP_IsBlockFree(&pSelf->pOrigin[1]) &&
         __SEGGER_RTL_RTHEAP_GetBlockSize(__SEGGER_RTL_RTHEAP_GetBlockAfter(&pSelf->pOrigin[1])) == 0;
}
# 1434 "./__SEGGER_RTL_RTHEAP.c"
int __SEGGER_RTL_RTHEAP_CheckHeap(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf) {
  return __SEGGER_RTL_RTHEAP_WalkHeap(pSelf, NULL);
}
# 1453 "./__SEGGER_RTL_RTHEAP.c"
int __SEGGER_RTL_RTHEAP_DumpHeap(__SEGGER_RTL_RTHEAP_CONTEXT *pSelf, __SEGGER_RTL_RTHEAP_IO_FUNC *pIoFunc) {
  return __SEGGER_RTL_RTHEAP_WalkHeap(pSelf, pIoFunc);
}
# 1471 "./__SEGGER_RTL_RTHEAP.c"
int __SEGGER_RTL_RTHEAP_CheckConfig(__SEGGER_RTL_RTHEAP_IO_FUNC *pIoFunc) {
  __SEGGER_RTL_RTHEAP_INDEX Index;
  __SEGGER_RTL_RTHEAP_SIZE Size;
  int LocalErrorCnt;
  int TotalErrorCnt;

  LocalErrorCnt = 0;
  TotalErrorCnt = 0;

  if (pIoFunc) {
    pIoFunc("__SEGGER_RTL_RTHEAP_SMALL_BLOCK_SZ    = %u\n", __SEGGER_RTL_RTHEAP_L2_MAX_SZ);
    pIoFunc("__SEGGER_RTL_RTHEAP_L1_INDEX_MAX_BITS = %u\n", __SEGGER_RTL_RTHEAP_L1_INDEX_MAX_BITS);
    pIoFunc("__SEGGER_RTL_RTHEAP_ALIGN_BITS        = %u\n", __SEGGER_RTL_RTHEAP_ALIGN_BITS);
    pIoFunc("__SEGGER_RTL_RTHEAP_L2_MAX_BITS       = %u\n", __SEGGER_RTL_RTHEAP_L2_MAX_BITS);
    pIoFunc("__SEGGER_RTL_RTHEAP_L1_INDEX_BITS     = %u\n", __SEGGER_RTL_RTHEAP_L1_INDEX_BITS);
    pIoFunc("__SEGGER_RTL_RTHEAP_L2_INDEX_BITS     = %u\n", __SEGGER_RTL_RTHEAP_L2_INDEX_BITS);
  }

  Size = 0;
  Index = __SEGGER_RTL_RTHEAP_Map(Size);
  HEAP_CK(Index.L1Index < __SEGGER_RTL_RTHEAP_L1_INDEX_BITS, "expected L1 index within bounds");

  Size = HEAP_MAX_HEAP_SIZE;
  Index = __SEGGER_RTL_RTHEAP_Map(Size);
  HEAP_CK(Index.L1Index < __SEGGER_RTL_RTHEAP_L1_INDEX_BITS, "expected L1 index within bounds");

  Size = HEAP_MAX_HEAP_SIZE+HEAP_DATA_OFFSET-1;
  Index = __SEGGER_RTL_RTHEAP_Map(Size);
  HEAP_CK(Index.L1Index < __SEGGER_RTL_RTHEAP_L1_INDEX_BITS, "expected L1 index within bounds");

  Size = HEAP_MAX_HEAP_SIZE + HEAP_DATA_OFFSET;
  Index = __SEGGER_RTL_RTHEAP_Map(Size);
  HEAP_CK(Index.L1Index >= __SEGGER_RTL_RTHEAP_L1_INDEX_BITS, "expected L1 index out of bounds");

  __SEGGER_RTL_USE_PARA(LocalErrorCnt);

  return TotalErrorCnt;
}
