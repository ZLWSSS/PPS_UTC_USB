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
# 1 "./jumpasmops_arm.s"
# 10 "./jumpasmops_arm.s"
#include "asmdefs_arm.ah"

#if !defined(__aarch64__ )

@ gnu_syntax

ARM_GLOBAL_FUNC setjmp

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        str r4, [r0, #0*4]
        str r5, [r0, #1*4]
        str r6, [r0, #2*4]
        str r7, [r0, #3*4]
        mov r1, r8
        str r1, [r0, #4*4]
        mov r1, r9
        str r1, [r0, #5*4]
        mov r1, r10
        str r1, [r0, #6*4]
        mov r1, r11
        str r1, [r0, #7*4]
        mov r1, r12
        str r1, [r0, #8*4]
        mov r1, r13
        str r1, [r0, #9*4]
        mov r1, r14
        str r1, [r0, #10*4]

#else

        mov r2, sp
        stmia r0!, {r2, r4-r12, r14}


#if __SEGGER_RTL_FP_HW > 0
        vstmia r0, {d8-d15}
#endif

#endif

        movs r0, #0
        bx lr

END_FUNC setjmp

ARM_GLOBAL_FUNC longjmp

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        ldr r4, [r0, #0*4]
        ldr r5, [r0, #1*4]
        ldr r6, [r0, #2*4]
        ldr r7, [r0, #3*4]
        ldr r2, [r0, #4*4]
        mov r8, r2
        ldr r2, [r0, #5*4]
        mov r9, r2
        ldr r2, [r0, #6*4]
        mov r10, r2
        ldr r2, [r0, #7*4]
        mov r11, r2
        ldr r2, [r0, #8*4]
        mov r12, r2
        ldr r2, [r0, #9*4]
        mov r13, r2
        ldr r2, [r0, #10*4]
        mov r14, r2


        movs r0, r1
        bne 1f
        movs r0, #1
1:
        bx lr

#else

        ldmia r0!, {r2, r4-r12, r14}
        mov sp, r2


#if __SEGGER_RTL_FP_HW > 0
        vldmia r0, {d8-d15}
#endif


        movs r0, r1
        it eq
        moveq r0, #1
        bx lr

#endif

END_FUNC longjmp

#endif

       .end
