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
# 1 "./strasmops_arm.s"
# 17 "./strasmops_arm.s"
#if !defined(__aarch64__ )

@ gnu_syntax

#include "asmdefs_arm.ah"

#if __SEGGER_RTL_STRING_ASM
# 47 "./strasmops_arm.s"
#undef L
#define L(label) .Lstrcmp_ ##label

ARM_GLOBAL_FUNC strcmp

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

1:
        ldrb r2, [r0]
        adds r0, r0, #1
        ldrb r3, [r1]
        adds r1, r1, #1
        subs r2, r2, r3
        bne L(ret)
        cmp r3, #0
        bne 1b
L(ret):
        movs r0, r2
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < 0

1:
        ldrb r2, [r0], #1
        ldrb r3, [r1], #1
        subs r2, r2, r3
        bne L(ret)
        cmp r3, #0
        bne 1b
L(ret):
        mov r0, r2
        bx lr

#else

#if __SEGGER_RTL_ALIGN_REM(~0u) != 0
        orrs r3, r0, r1
        lsls r3, r3, #30
        bne L(unaligned)
#endif

#if __SEGGER_RTL_CORE_HAS_UQADD_UQSUB

        li ip, 0x01010101

L(wordstrcmp):
        ldr r2, [r0], #4
        ldr r3, [r1], #4
        cmp r2, r3
        bne L(bytestrcmp)
        uqsub8 r2, ip, r2
#if __SEGGER_RTL_OPTIMIZE >= 0
        CBNZx r2, L(bytestrcmp)

        ldr r2, [r0], #4
        ldr r3, [r1], #4
        cmp r2, r3
        bne L(bytestrcmp)
        uqsub8 r2, ip, r2
        CBNZx r2, L(bytestrcmp)

        ldr r2, [r0], #4
        ldr r3, [r1], #4
        cmp r2, r3
        bne L(bytestrcmp)
        uqsub8 r2, ip, r2
        CBNZx r2, L(bytestrcmp)

        ldr r2, [r0], #4
        ldr r3, [r1], #4
        cmp r2, r3
        bne L(bytestrcmp)
        uqsub8 r2, ip, r2
#endif
        cmp r2, #0
        beq L(wordstrcmp)

L(bytestrcmp):

#else

        push {r4-r6}

        li r6, 0x01010101
        lsls r3, r6, #7

L(wordstrcmp):
        ldr r4, [r0], #4
        ldr r5, [r1], #4
        cmp r4, r5
        bne L(bytestrcmp)


        subs r5, r4, r6
        bics r5, r5, r4
        ands r5, r5, r3
        beq L(wordstrcmp)


L(bytestrcmp):
        pop {r4-r6}

#endif

        subs r0, r0, #4
        subs r1, r1, #4

L(unaligned):
        ldrb r2, [r0], #1
        ldrb r3, [r1], #1
        subs r2, r2, r3
        bne L(ret)
        cmp r3, #0
        bne L(unaligned)

L(ret):
        mov r0, r2
        bx lr

#endif

END_FUNC strcmp
# 185 "./strasmops_arm.s"
#undef L
#define L(label) .Lstrcpy_ ##label

ARM_GLOBAL_FUNC strcpy

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16




        movs r2, #0
1:
        ldrb r3, [r1, r2]
        strb r3, [r0, r2]
        adds r2, r2, #1
        cmp r3, #0
        bne 1b
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < 0




        mov r2, r0
1:
        ldrb r3, [r1], #1
        strb r3, [r2], #1
        cmp r3, #0
        bne 1b
        bx lr

#else




        mov r2, r0

#if __SEGGER_RTL_ALIGN_REM(~0u) != 0
        orrs r3, r0, r1
        lsls r3, r3, #30
        bne L(unaligned)
#endif

        push {r4-r7}

        li r7, 0x01010101
        lsls r3, r7, #7

L(wordstrcpy):
        ldr r4, [r1], #4
        subs r5, r4, r7
        bics r5, r5, r4
        ands r5, r5, r3
        bne L(bytestrcpy)

        str r4, [r2], #4
        b L(wordstrcpy)

L(bytestrcpy):
        subs r1, r1, #4
        pop {r4-r7}
L(unaligned):
        ldrb r3, [r1], #1
        strb r3, [r2], #1
        cmp r3, #0
        bne L(unaligned)
        bx lr

#endif

END_FUNC strcpy

#undef L
#define L(label) .Lstrlen_ ##label

#if 0
# 279 "./strasmops_arm.s"
ARM_GLOBAL_FUNC strlen

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16




        adds r1, r0, #1
L(find_end):
        ldrb r2, [r0]
        adds r0, r0, #1
        cmp r2, #0
        bne L(find_end)
        subs r0, r0, r1
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < 0




        add r1, r0, #1
L(find_end):
        ldrb r2, [r0], #1
        cmp r2, #0
        bne L(find_end)
        subs r0, r0, r1
        bx lr

#else




        adds r1, r0, #1

        lsls r2, r0, #30
        beq L(aligned)

        ldrb r2, [r0], #1
        CBZx r2, L(done)

        lsls r2, r0, #30
        beq L(aligned)

        ldrb r2, [r0], #1
        CBZx r2, L(done)

        lsls r2, r0, #30
        beq L(aligned)

        ldrb r2, [r0], #1
        CBZx r2, L(done)

L(aligned):

#if __SEGGER_RTL_CORE_HAS_UQADD_UQSUB

        li ip, 0x01010101
L(wordstrlen):
        ldr r2, [r0], #4
        uqsub8 r3, ip, r2
        CBNZx r3, L(bytestrlen)
        ldr r2, [r0], #4
        uqsub8 r3, ip, r2
        CBNZx r3, L(bytestrlen)
        ldr r2, [r0], #4
        uqsub8 r3, ip, r2
        CBNZx r3, L(bytestrlen)
        ldr r2, [r0], #4
        uqsub8 r3, ip, r2
        cmp r3, #0
        beq L(wordstrlen)

L(bytestrlen):

#else

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32

L(wordstrlen):
        ldr r2, [r0], #4
#if __SEGGER_RTL_CORE_HAS_REV && (__SEGGER_RTL_BYTE_ORDER > 0)
        rev r2, r2
#endif
        subs r3, r2, #0x01010101
        bics r3, r3, r2
        ands r3, r3, #0x80808080
        beq L(wordstrlen)

#else

        li ip, 0x01010101
L(wordstrlen):
        ldr r2, [r0], #4
#if __SEGGER_RTL_CORE_HAS_REV && (__SEGGER_RTL_BYTE_ORDER > 0)
        rev r2, r2
#endif
        subs r3, r2, ip
        bics r3, r3, r2
        ands r3, r3, ip, lsl #7
        beq L(wordstrlen)

#endif

#if __SEGGER_RTL_CORE_HAS_CLZ && __SEGGER_RTL_CORE_HAS_REV
        rev r3, r3
#endif

#endif

#if __SEGGER_RTL_CORE_HAS_CLZ






        clz r3, r3
        add r0, r0, r3, lsr #3
        subs r0, r0, #4-1

#else

        subs r0, r0, #4

L(unaligned):
        ldrb r2, [r0], #1
        cmp r2, #0
        bne L(unaligned)

#endif

L(done):
        subs r0, r0, r1
        bx lr

#endif

END_FUNC strlen

#endif

#undef L
#define L(label) .Lstrchr_ ##label
# 445 "./strasmops_arm.s"
ARM_GLOBAL_FUNC strchr

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16




        UXTBs r1, r1
        subs r0, r0, #1
L(search):
        adds r0, r0, #1
        ldrb r2, [r0]
        cmp r2, r1
        beq L(found)
        cmp r2, #0
        bne L(search)
        movs r0, #0
L(found):
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < 0




        UXTBs r1, r1
        subs r0, r0, #1
L(search):
        adds r0, r0, #1
        ldrb r2, [r0]
        cmp r2, r1
        beq L(found)
        cmp r2, #0
        bne L(search)
        movs r0, #0
L(found):
        bx lr

#else




        UXTBs r1, r1
L(search):
        lsls r2, r0, #30
        beq L(aligned)
        ldrb r2, [r0], #1
        cmp r2, r1
        beq L(found)
        cmp r2, #0
        bne L(search)
        movs r0, #0
        bx lr
L(found):
        subs r0, r0, #1
        bx lr

#if __SEGGER_RTL_CORE_HAS_UQADD_UQSUB

L(aligned):

        li r2, 0x01010101
        muls r1, r1, r2

L(wordsearch):
        ldr ip, [r0], #4
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)
        eors ip, ip, r1
        uqsub8 r3, r2, ip
#if __SEGGER_RTL_OPTIMIZE > 0
        CBNZx r3, L(bytesearch)

        ldr ip, [r0], #4
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)
        eors ip, ip, r1
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)

        ldr ip, [r0], #4
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)
        eors ip, ip, r1
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)

        ldr ip, [r0], #4
        uqsub8 r3, r2, ip
        CBNZx r3, L(bytesearch)
        eors ip, ip, r1
        uqsub8 r3, r2, ip
#endif
        cmp r3, #0
        beq L(wordsearch)

L(bytesearch):

#else

L(aligned):

        push {r4-r6}

        li r2, 0x01010101
        lsls r3, r2, #7
        muls r1, r2, r1

L(wordsearch):
        ldr r4, [r0], #4
        subs r5, r4, r2
        bics r5, r5, r4
        eors r4, r4, r1
        subs r6, r4, r2
        bics r6, r6, r4
        orrs r6, r6, r5
        ands r6, r6, r3

#if __SEGGER_RTL_OPTIMIZE <= 0
        beq L(wordsearch)
#else
        bne L(bytesearch)
        ldr r4, [r0], #4
        subs r5, r4, r2
        bics r5, r5, r4
        eors r4, r4, r1
        subs r6, r4, r2
        bics r6, r6, r4
        orrs r6, r6, r5
        ands r6, r6, r3
        beq L(wordsearch)
#endif

L(bytesearch):
        pop {r4-r6}

#endif

        subs r0, r0, #4
        UXTBs r1, r1
L(tailsearch):
        ldrb r2, [r0], #1
        cmp r2, r1
        beq L(tailfound)
        cmp r2, #0
        bne L(tailsearch)
        movs r0, #0
        bx lr

L(tailfound):
        subs r0, r0, #1
        bx lr

#endif

END_FUNC strchr

#undef L
#define L(label) .Lmemcpy_ ##label

#if (__SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16) || (__SEGGER_RTL_OPTIMIZE < 0)

ARM_GLOBAL_FUNC memcpy
ALIAS_LABEL __aeabi_memcpy
ALIAS_LABEL __aeabi_memcpy4
ALIAS_LABEL __aeabi_memcpy8

        CBZx r2, L(memcpy_end)

L(memcpy_loop):
        subs r2, r2, #1
        ldrb r3, [r1, r2]
        strb r3, [r0, r2]
        bne L(memcpy_loop)

L(memcpy_end):
        bx lr

#else

ARM_GLOBAL_FUNC memcpy
ALIAS_LABEL __aeabi_memcpy

        CBZx r2, L(done)


        mov r12, r0


        eors r3, r0, r1
        lsls r3, r3, #30
        bne L(byte_copy_loop)


L(word_align_check):
        lsls r3, r0, #30
        beq L(aligned)
L(word_align):
        ldrb r3, [r1], #1
        strb r3, [r0], #1
        subs r2, r2, #1
        bne L(word_align_check)
        b L(memcpy_end)

ALIAS_LABEL __aeabi_memcpy4
ALIAS_LABEL __aeabi_memcpy8


        mov r12, r0


L(aligned):
        subs r2, #32
        bcc L(word_copy)


        push {r4-r10}
L(aligned_block_copy_loop):
        ldmia r1!, {r3-r10}
        stmia r0!, {r3-r10}
        subs r2, r2, #32
        bcs L(aligned_block_copy_loop)
        pop {r4-r10}


L(word_copy):

        adds r2, #28
        bmi L(byte_copy)

L(word_copy_loop):
        ldr r3, [r1], #4
        str r3, [r0], #4
        subs r2, r2, #4
        bhs L(word_copy_loop)


L(byte_copy):
        adds r2, #4
        beq L(memcpy_end)

L(byte_copy_loop):
        ldrb r3, [r1], #1
        strb r3, [r0], #1
        subs r2, r2, #1
        bne L(byte_copy_loop)

L(memcpy_end):

        mov r0, r12
L(done):
        bx lr
#endif

END_FUNC memcpy

#undef L
#define L(label) .L__aeabi_memset_ ##label

ARM_GLOBAL_FUNC __aeabi_memclr
ALIAS_LABEL __aeabi_memclr8
ALIAS_LABEL __aeabi_memclr4

        movs r2, #0

ALIAS_LABEL __aeabi_memset8
ALIAS_LABEL __aeabi_memset4
ALIAS_LABEL __aeabi_memset


        movs r3, r1
        movs r1, r2
        movs r2, r3

ALIAS_LABEL memset

#if (__SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16) || (__SEGGER_RTL_OPTIMIZE < 0)

        CBZx r2, L(memset_end)
L(memset_loop):
        subs r2, r2, #1
        strb r1, [r0, r2]
        bne L(memset_loop)

L(memset_end):
        bx lr

#else

        mov r12, r0
        CBZx r2, L(memset_end)

L(unaligned_byte_set_loop):
        lsls r3, r0, #30
        beq L(fast_set)

        strb r1, [r0], #1
        subs r2, r2, #1
        bne L(unaligned_byte_set_loop)
        b L(memset_end)

L(fast_set):
        UXTBs r1, r1
        orr r1, r1, r1, lsl #8
        orr r1, r1, r1, lsl #16
        cmp r2, #32
        blo L(word_set)
        subs r2, r2, #32
        push {r4-r9}
        mov r3, r1
        mov r4, r1
        mov r5, r1
        mov r6, r1
        mov r7, r1
        mov r8, r1
        mov r9, r1
L(fast_set_loop):
        stmia r0!, {r1, r3-r9}
        subs r2, r2, #32
        bhs L(fast_set_loop)
        pop {r4-r9}
        adds r2, r2, #32
        beq L(memset_end)

L(word_set):
        cmp r2, #4
        blo L(byte_set_loop)

L(word_set_loop):
        str r1, [r0], #4
        subs r2, r2, #4
        beq L(memset_end)
        cmp r2, #4
        bhs L(word_set_loop)

L(byte_set_loop):
        strb r1, [r0], #1
        subs r2, r2, #1
        bne L(byte_set_loop)

L(memset_end):
        mov r0, r12
        bx lr
#endif

END_FUNC __aeabi_memclr

#undef L
#define L(label) .L__aeabi_memmove_ ##label

ARM_GLOBAL_FUNC __aeabi_memmove
ALIAS_LABEL __aeabi_memmove4
ALIAS_LABEL __aeabi_memmove8


        CBZx r2, L(done)


        cmp r0, r1
#if __SEGGER_RTL_OPTIMIZE >= 0
        beq L(done)
#endif
        bcs L(copy_from_end)


        adds r0, r0, r2
        adds r1, r1, r2
        rsbs r2, r2, #0
L(copy_loop):
        ldrb r3, [r1, r2]
        strb r3, [r0, r2]
        adds r2, r2, #1
        bne L(copy_loop)
L(done):
        bx lr


L(copy_from_end):
        subs r2, r2, #1
        ldrb r3, [r1, r2]
        strb r3, [r0, r2]
        bne L(copy_from_end)
        bx lr

@ gnu_syntax

#endif

#endif

       .end
