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
# 1 "./intasmops_arm.s"
# 46 "./intasmops_arm.s"
#if !defined(__aarch64__ )

@ gnu_syntax
# 57 "./intasmops_arm.s"
#define __SEGGER_RTL_ASSEMBLER_INCLUDE 
#include "asmdefs_arm.ah"
#include "__SEGGER_RTL_ConfDefaults.h"
# 69 "./intasmops_arm.s"
LOCAL_RODATA __SEGGER_RTL_inverse_lut, 1
       .byte 0xFC, 0xF8, 0xF4, 0xF0, 0xED, 0xEA, 0xE6, 0xE3
       .byte 0xE0, 0xDD, 0xDA, 0xD7, 0xD4, 0xD2, 0xCF, 0xCC
       .byte 0xCA, 0xC7, 0xC5, 0xC3, 0xC0, 0xBE, 0xBC, 0xBA
       .byte 0xB8, 0xB6, 0xB4, 0xB2, 0xB0, 0xAE, 0xAC, 0xAA
       .byte 0xA8, 0xA7, 0xA5, 0xA3, 0xA2, 0xA0, 0x9F, 0x9D
       .byte 0x9C, 0x9A, 0x99, 0x97, 0x96, 0x94, 0x93, 0x92
       .byte 0x90, 0x8F, 0x8E, 0x8D, 0x8C, 0x8A, 0x89, 0x88
       .byte 0x87, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x80
END_RODATA __SEGGER_RTL_inverse_lut
# 87 "./intasmops_arm.s"
       .macro IDIV0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        push {r4, lr}
        bl __aeabi_idiv0
        RET1 r4
#else
        b __aeabi_idiv0
#endif
       .endm

       .macro LDIV0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        push {r4, lr}
        bl __aeabi_ldiv0
        RET1_r3 r4
#else
        b __aeabi_ldiv0
#endif
       .endm
# 134 "./intasmops_arm.s"
#undef L
#define L(label) .L__aeabi_lcmp ##label

ARM_GLOBAL_FUNC __aeabi_lcmp

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        cmp xh, yh
        bgt L(greater)
        blt L(less)
        cmp xl, yl
        bhi L(greater)
        sbcs r0, r0, r0
        bx lr
L(greater):
        movs r0, #1
        bx lr
L(less):
        movs r0, #0
        subs r0, r0, #1
        bx lr

#else

        cmp xh, yh
        bgt L(greater)
        blt L(less)
        cmp xl, yl
        ite hi
        movhi r0, #1
        sbcls r0, r0, r0
        bx lr
L(greater):
        movs r0, #1
        bx lr
L(less):
        movs r0, #-1
        bx lr

#endif

END_FUNC __aeabi_lcmp
# 197 "./intasmops_arm.s"
#undef L
#define L(label) .L__aeabi_ulcmp_ ##label

ARM_GLOBAL_FUNC __aeabi_ulcmp

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        cmp xh, yh
        bhi L(greater)
        bcc L(less)
        cmp xl, yl
        bhi L(greater)
L(less):
        sbcs r0, r0, r0
        bx lr
L(greater):
        movs r0, #1
        bx lr

#else

        cmp xh, yh
        it eq
        cmpeq xl, yl
        ite hi
        movhi r0, #1
        sbcls r0, r0, r0
        bx lr

#endif

END_FUNC __aeabi_ulcmp
# 248 "./intasmops_arm.s"
#undef L
#define L(label) .L__int64_lsl_ ##label

ARM_GLOBAL_FUNC __aeabi_llsl

#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL

        llsl xl, xh, r2
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        cmp r2, #32
        bcs L(LongShift)


        movs r3, xl
        lsls xl, xl, r2
        lsls xh, xh, r2
        negs r2, r2
        adds r2, r2, #32
        lsrs r3, r3, r2
        orrs xh, xh, r3
        bx lr


L(LongShift):
        subs r2, r2, #32
        movs xh, xl
        lsls xh, xh, r2
        movs xl, #0
        bx lr

#else

        subs r3, r2, #32
        bcs L(LongShift)
        rsb r3, r2, #32
        lsls xh, xh, r2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orr xh, xh, xl, lsr r3
#else
        lsrs r3, xl, r3
        orrs xh, xh, r3
#endif
        lsls xl, xl, r2
        bx lr

L(LongShift):
        lsl xh, xl, r3
        movs xl, #0
        bx lr
#endif

END_FUNC __aeabi_llsl

#undef L
#define L(label) .L__int64_lsr_ ##label
# 326 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_llsr

#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL

        llsr xl, xh, r2
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        cmp r2, #32
        bcs L(LongShift)


        lsrs xl, xl, r2
        movs r3, xh
        lsrs xh, xh, r2
        negs r2, r2
        adds r2, r2, #32
        lsls r3, r3, r2
        orrs xl, xl, r3
        bx lr


L(LongShift):
        subs r2, r2, #32
        movs xl, xh
        lsrs xl, xl, r2
        movs xh, #0
        bx lr

#else

        subs r3, r2, #32
        bcs L(LongShift)
        rsb r3, r2, #32
        lsrs xl, xl, r2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orr xl, xl, xh, lsl r3
#else
        lsl r3, xh, r3
        orrs xl, xl, r3
#endif
        lsrs xh, xh, r2
        bx lr
L(LongShift):
        lsr xl, xh, r3
        movs xh, #0
        bx lr
#endif

END_FUNC __aeabi_llsr
# 397 "./intasmops_arm.s"
#undef L
#define L(label) .L__int64_asr_ ##label

ARM_GLOBAL_FUNC __aeabi_lasr

#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL

        lasr xl, xh, r2
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        cmp r2, #32
        bcs L(LongShift)


        lsrs xl, xl, r2
        movs r3, xh
        asrs xh, xh, r2
        negs r2, r2
        adds r2, r2, #32
        lsls r3, r3, r2
        orrs xl, xl, r3
        bx lr


L(LongShift):
        subs r2, r2, #32
        movs xl, xh
        asrs xl, xl, r2
        asrs xh, xh, #31
        bx lr

#else

        subs r3, r2, #32
        bcs L(LongShift)
        rsb r3, r2, #32
        lsrs xl, xl, r2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orr xl, xl, xh, lsl r3
#else
        lsl r3, xh, r3
        orrs xl, xl, r3
#endif
        asrs xh, xh, r2
        bx lr
L(LongShift):
        asrs xl, xh, r3
        asrs xh, xh, #31
        bx lr

#endif

END_FUNC __aeabi_lasr

#undef L
#define L(label) .L__aeabi_lmul_ ##label
# 475 "./intasmops_arm.s"
#undef L
#define L(label) .L__SEGGER_lmul_ ##label

ARM_GLOBAL_FUNC __aeabi_lmul

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16




        push {r4-r5, lr}



        muls xh, xh, yl
        muls yh, xl, yh
        adds r4, yh, xh
# 506 "./intasmops_arm.s"
        lsrs xh, xl, #16
        lsrs yh, yl, #16


        movs r5, xh
        muls r5, yh, r5
        adds r4, r4, r5


        UXTHs yl, yl
        muls xh, yl, xh


        UXTHs xl, xl
        muls yl, xl, yl


        lsrs r5, xh, #16
        lsls xh, xh, #16
        adds yl, yl, xh
        adcs r5, r5, r4


        muls xl, yh, xl



        lsrs xh, xl, #16
        lsls xl, xl, #16
        adds xl, xl, yl
        adcs xh, xh, r5


        RET2 r4, r5

#else

        mul ip, xl, yh
        mla ip, xh, yl, ip
        umull xl, xh, yl, xl
        add xh, xh, ip
        bx lr

#endif

END_FUNC __aeabi_lmul
# 571 "./intasmops_arm.s"
#undef L
#define L(label) .L__SEGGER_idiv_ ##label

ARM_GLOBAL_FUNC __aeabi_idiv

#if __SEGGER_RTL_CORE_HAS_IDIV

        sdiv r0, r0, r1
        bx lr

#elif __SEGGER_RTL_CORE_HAS_IDIV_X

        BASE_X r2
        IDIV_X r0, r0, r1, r2, r3
        bx lr

#elif __SEGGER_RTL_FP_HW >= 2 && __SEGGER_RTL_USE_FPU_FOR_IDIV

        vmov s0, r0
        vcvt.f64.s32 d16, s0
        vmov s1, r1
        vcvt.f64.s32 d17, s1
        vdiv.f64 d16, d16, d17
        vcvt.s32.f64 s0, d16
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        asrs r2, r1, #31
        eors r1, r1, r2
        subs r3, r1, r2


        beq L(divide_by_zero)


        asrs r1, r0, #31
        eors r2, r2, r1
        mov ip, r2
        eors r0, r0, r1
        subs r1, r0, r1


        lsrs r0, r1, #1
        movs r2, r3
        b L(justifying)
L(justify):
        lsls r2, r2, #1
L(justifying):
        cmp r2, r0
        bls L(justify)


        movs r0, #0
        b L(dividing)
L(divide):
        lsrs r2, r2, #1


L(dividing):
        cmp r1, r2
        bcc L(cant_subtract)


        subs r1, r1, r2


L(cant_subtract):
        adcs r0, r0, r0


        cmp r2, r3
        bne L(divide)


        mov r2, ip


        eors r0, r0, r2
        subs r0, r0, r2


        bx lr


L(divide_by_zero):
        IDIV0

#elif __SEGGER_RTL_OPTIMIZE < 0





        ands r3, r1, #0x80000000
        it mi
        negmi r1, r1
        eors ip, r3, r0, asr #32
        it cs
        negcs r0, r0


        movs r2, r1
        beq L(divide_by_zero)



L(justify):
        cmp r2, r0, lsr #1
        it ls
        lslls r2, r2, #1
        blo L(justify)


L(divide):
        cmp r0, r2
        it cs
        subcs r0, r0, r2
        adcs r3, r3, r3


        cmp r2, r1
        lsr r2, r2, #1
        bne L(divide)


        eors r0, r3, ip, asr #31
        subs r0, r0, ip, asr #31


        bx lr


L(divide_by_zero):
        IDIV0

#else






.macro i32_divstep bit, op
        cmp r1, ip, lsr #\bit
        itt ls
        subls ip, ip, r1, lsl #\bit
        \op r0, r0, #1 << \bit
.endm


        teq r0, r1
        bmi L(opposite_signs)



        tst r0, r0
        itt mi
        negmi r0, r0
        negmi r1, r1



        cmp r1, r0, lsr #7
        it ls
        rsbsls r2, r1, #5
        bhi L(positive_small_quotent)


        NORM32 r3, r1, r2


        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        ldrb ip, [ip, r3, lsr #25]
#else
        lsrs r3, r3, #25
        ldrb ip, [ip, r3]
#endif




        subs r2, r2, #7
        lsl ip, ip, r2
        mul r1, ip, r1
        umull r2, r0, ip, r0
        negs r1, r1



        movs r3, #0
        umlal r2, r3, r1, r0
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        cmn r2, r1
        adc r0, r0, r3
        bx lr



L(positive_small_quotent):


        cmp r1, #4
        bls L(positive_special_cases)


        mov ip, r0
        movs r0, #0


        cmp r1, ip, lsr #2
        bhi L(positive_extremely_small_quotient)


        i32_divstep 7, addls
        i32_divstep 6, addls
        i32_divstep 5, addls
        i32_divstep 4, addls
        i32_divstep 3, addls
        i32_divstep 2, addls



L(positive_extremely_small_quotient):
        i32_divstep 1, addls


        cmp r1, ip
        it ls
        addls r0, r0, #1
        bx lr


L(positive_special_cases):

#if __SEGGER_RTL_CORE_HAS_TBB_TBH

        tbb [pc, r1]
L(positive_base):
       .byte (L(positive_divide_by_0)-L(positive_base)) / 2
       .byte (L(positive_divide_by_1)-L(positive_base)) / 2
       .byte (L(positive_divide_by_2)-L(positive_base)) / 2
       .byte (L(positive_divide_by_3)-L(positive_base)) / 2
       .byte (L(positive_divide_by_4)-L(positive_base)) / 2
        INSN_ALIGN
#else
        cmp r1, #3
        bhi L(positive_divide_by_4)
        beq L(positive_divide_by_3)
        cmp r1, #1
        bhi L(positive_divide_by_2)
        beq L(positive_divide_by_1)
#endif

L(positive_divide_by_0):
        IDIV0

L(positive_divide_by_4):
        lsrs r0, r0, #2
        bx lr

L(positive_divide_by_3):
        li r2, 0xaaaaaaab
        umull r3, r0, r2, r0
L(positive_divide_by_2):
        lsrs r0, r0, #1
L(positive_divide_by_1):
        bx lr


L(opposite_signs):


        tst r1, r1
        itt mi
        negsmi r0, r0
        negsmi r1, r1



        cmn r1, r0, asr #7
        it ls
        rsbsls r2, r1, #5
        bhi L(negative_small_quotent)


        NORM32 r3, r1, r2


        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        ldrb ip, [ip, r3, lsr #25]
#else
        lsrs r3, r3, #25
        ldrb ip, [ip, r3]
#endif





        negs r0, r0
        subs r2, r2, #7
        lsl ip, ip, r2
        mul r1, ip, r1
        umull r2, r0, ip, r0
        negs r1, r1



        movs r3, #0
        umlal r2, r3, r1, r0
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        cmn r2, r1
        adc r0, r0, r3
        negs r0, r0
        bx lr



L(negative_small_quotent):


        cmp r1, #4
        bls L(negative_special_cases)


        negs ip, r0
        movs r0, #0


        cmp r1, ip, lsr #2
        bhi L(negative_extremely_small_quotient)


        i32_divstep 7, subls
        i32_divstep 6, subls
        i32_divstep 5, subls
        i32_divstep 4, subls
        i32_divstep 3, subls
        i32_divstep 2, subls



L(negative_extremely_small_quotient):
        i32_divstep 1, subls


        cmp r1, ip
        it ls
        subls r0, r0, #1
        bx lr


L(negative_special_cases):

#if __SEGGER_RTL_CORE_HAS_TBB_TBH

        tbb [pc, r1]
L(negative_base):
       .byte (L(negative_divide_by_0)-L(negative_base)) / 2
       .byte (L(negative_divide_by_1)-L(negative_base)) / 2
       .byte (L(negative_divide_by_2)-L(negative_base)) / 2
       .byte (L(negative_divide_by_3)-L(negative_base)) / 2
       .byte (L(negative_divide_by_4)-L(negative_base)) / 2
        INSN_ALIGN
#else
        cmp r1, #3
        bhi L(negative_divide_by_4)
        beq L(negative_divide_by_3)
        cmp r1, #1
        bhi L(negative_divide_by_2)
        beq L(negative_divide_by_1)
#endif

L(negative_divide_by_0):
        IDIV0

L(negative_divide_by_2):
        adds r0, r0, #1
        asrs r0, r0, #1
L(negative_divide_by_1):
        bx lr

L(negative_divide_by_3):
        li r2, 0xaaaaaaab
        negs r0, r0
        umull r3, r0, r2, r0
        lsrs r0, r0, #1
        negs r0, r0
        bx lr

L(negative_divide_by_4):
        adds r0, r0, #3
        asrs r0, r0, #2
        bx lr

#endif

END_FUNC __aeabi_idiv
# 1032 "./intasmops_arm.s"
#undef L
#define L(label) .L__aeabi_idivmod_ ##label

ARM_GLOBAL_FUNC __aeabi_idivmod

#if __SEGGER_RTL_CORE_HAS_IDIV

        sdiv r2, r0, r1
#if __SEGGER_RTL_CORE_HAS_MLS
        mls r1, r2, r1, r0
#else
        muls r1, r1, r2
        subs r1, r0, r1
#endif
        movs r0, r2
        bx lr

#elif __SEGGER_RTL_CORE_HAS_UDIV_X

        BASE_X r2
        UDIVM_X r0, r1, r0, r1, r2, r3
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        push {r0, r1, r2, lr}
        bl __aeabi_idiv
        pop {r1, r2, r3}


#if __SEGGER_RTL_CORE_HAS_MLS
        mls r1, r0, r2, r1
#else
        muls r2, r0, r2
        subs r1, r1, r2
#endif
        pop {pc}

#else


        push {r0, r1, r2, lr}
        bl __aeabi_idiv
        pop {r1, r2, r3, lr}


#if __SEGGER_RTL_CORE_HAS_MLS
        mls r1, r0, r2, r1
#else
        muls r2, r0, r2
        subs r1, r1, r2
#endif
        bx lr

#endif

END_FUNC __aeabi_idivmod
# 1109 "./intasmops_arm.s"
#undef L
#define L(label) .L__SEGGER_uidiv_ ##label

ARM_GLOBAL_FUNC __aeabi_uidiv

#if __SEGGER_RTL_CORE_HAS_IDIV

        udiv r0, r0, r1
        bx lr

#elif __SEGGER_RTL_CORE_HAS_UDIV_X

        BASE_X r2
        UDIV_X r0, r0, r1, r2, r3
        bx lr

#elif __SEGGER_RTL_FP_HW >= 2 && __SEGGER_RTL_USE_FPU_FOR_IDIV

        vmov s0, r0
        vcvt.f64.u32 d16, s0
        vmov s1, r1
        vcvt.f64.u32 d17, s1
        vdiv.f64 d16, d16, d17
        vcvt.u32.f64 s0, d16
        vmov r0, s0
        bx lr

#elif 0 && (__SEGGER_RTL_TARGET_ISA != __SEGGER_RTL_ISA_T16)




        movs r2, r0
        movs r0, #0
       .set bit, 31
       .rept 31
        cmp r1, r2, lsr #bit
        itt ls
        subls r2, r2, r1, lsl #bit
        addls r0, r0, #1<<bit
       .set bit, bit-1
       .endr
        cmp r1, r2
        it ls
        addls r0, r0, #1
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        movs r2, r1
        beq L(divide_by_zero)


        movs r3, r0
        lsrs r0, r0, #1
        b L(justifying)
L(justify):
        lsls r2, r2, #1
L(justifying):
        cmp r2, r0
        bls L(justify)


        movs r0, #0
        b L(dividing)


L(shift_subtract):
        lsrs r2, r2, #1
L(dividing):
        subs r3, r3, r2
        bcc L(cant_subtract)
L(cant_add):
        adcs r0, r0, r0
        cmp r2, r1
        bne L(shift_subtract)
        bx lr

L(shift_add):
        lsrs r2, r2, #1
        adds r3, r3, r2
        bcs L(cant_add)
L(cant_subtract):
        adds r0, r0, r0
        cmp r2, r1
        bne L(shift_add)
        bx lr


L(divide_by_zero):
        IDIV0




#elif 0 && __SEGGER_RTL_OPTIMIZE == 0 && __SEGGER_RTL_CORE_HAS_CLZ


        cmp r0, #0
        beq L(divide_by_zero)


        mov ip, r0
        movs r0, #0


        clz r2, ip
        clz r3, r1


        subs r3, r3, r2
        it mi
        bxmi lr




#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        rsbs r3, r3, #31
        add r3, r3, r3, lsl #1
        add pc, pc, r3, lsl #2
        nop
#else
        rsbs r3, r3, #31
        tbb [pc, r3]
L(base):
       .set bit, 0
       .rept 32
       .byte (L(target)-L(base)+14*bit) / 2
       .set bit, bit+1
       .endr
        INSN_ALIGN
#endif


L(target):
       .set bit, 31
       .rept 31
        cmp r1, ip, lsr #bit
        itt ls
        subls ip, ip, r1, lsl #bit
        addls.w r0, r0, #1<<bit
       .set bit, bit-1
       .endr


        cmp r1, ip
        it ls
        addls r0, r0, #1
        bx lr

L(divide_by_zero):
        IDIV0

#elif __SEGGER_RTL_OPTIMIZE < 0




        movs r2, r1
        beq L(divide_by_zero)


L(justify):
        cmp r2, r0, lsr #1
        it ls
        movls r2, r2, lsl #1
        blo L(justify)


        movs r3, #0


L(divide):
        cmp r0, r2
        it cs
        subcs r0, r0, r2
        adcs r3, r3, r3


        cmp r2, r1
        lsr r2, r2, #1
        bne L(divide)


        movs r0, r3


        bx lr

L(divide_by_zero):
        IDIV0

#else






.macro u32_divstep bit, op
        cmp r1, ip, lsr #\bit
        itt ls
        subls ip, ip, r1, lsl #\bit
        addls r0, r0, #1<<\bit
.endm




        cmp r1, r0, lsr #7
        it ls
        rsbsls r3, r1, #5
        bhi L(small_quotent)


        NORM32 r3, r1, r2


        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        ldrb ip, [ip, r3, lsr #25]
#else
        lsrs r3, r3, #25
        ldrb ip, [ip, r3]
#endif




        subs r2, r2, #7
        lsl ip, ip, r2
        mul r1, ip, r1
        umull r2, r0, ip, r0
        negs r1, r1



        movs r3, #0
        umlal r2, r3, r1, r0
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        add r0, r0, r3


        movs ip, #0
        umlal r2, ip, r1, r3
        add r0, r0, ip


        movs r3, #0
        umlal r2, r3, r1, ip
        cmn r2, r1
        adcs r0, r0, r3
        bx lr


L(small_quotent):


        cmp r1, #4
        bls L(special_cases)


        mov ip, r0
        movs r0, #0

#if __SEGGER_RTL_CORE_HAS_CLZ && __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM




        clz r3, ip
        clz r2, r1
        subs r2, r2, r3
        bmi L(divide_by_1)
        rsbs r2, r2, #7
        adds r2, r2, r2, lsl #1
        add pc, pc, r2, lsl #2
        nop
        u32_divstep 7
        u32_divstep 6
        u32_divstep 5
        u32_divstep 4
        u32_divstep 3
        u32_divstep 2
        u32_divstep 1
        cmp r1, ip
        it ls
        addls r0, r0, #1
        bx lr

#else


        u32_divstep 7
        u32_divstep 6
        u32_divstep 5
        u32_divstep 4
        u32_divstep 3
        u32_divstep 2
        u32_divstep 1


        cmp r1, ip
        it ls
        addls r0, r0, #1
        bx lr

#endif


L(special_cases):

#if __SEGGER_RTL_CORE_HAS_TBB_TBH

        tbb [pc, r1]
L(base):
       .byte (L(divide_by_0)-L(base)) / 2
       .byte (L(divide_by_1)-L(base)) / 2
       .byte (L(divide_by_2)-L(base)) / 2
       .byte (L(divide_by_3)-L(base)) / 2
       .byte (L(divide_by_4)-L(base)) / 2
        INSN_ALIGN
#else
        cmp r1, #3
        bhi L(divide_by_4)
        beq L(divide_by_3)
        cmp r1, #1
        bhi L(divide_by_2)
        beq L(divide_by_1)
#endif

L(divide_by_0):
        IDIV0

L(divide_by_4):
        lsrs r0, r0, #2
        bx lr

L(divide_by_3):
        li r2, 0xaaaaaaab
        umull r3, r0, r2, r0
L(divide_by_2):
        lsrs r0, r0, #1
L(divide_by_1):
        bx lr

#endif

END_FUNC __aeabi_uidiv
# 1489 "./intasmops_arm.s"
#undef L
#define L(label) .L__int32_udivmod_ ##label

ARM_GLOBAL_FUNC __aeabi_uidivmod

#if __SEGGER_RTL_CORE_HAS_IDIV

        udiv r2, r0, r1
#if __SEGGER_RTL_CORE_HAS_MLS
        mls r1, r2, r1, r0
#else
        muls r1, r1, r2
        subs r1, r0, r1
#endif
        movs r0, r2
        bx lr

#elif __SEGGER_RTL_CORE_HAS_UDIVM_X

        BASE_X r2
        UDIVM_X r0, r1, r0, r1, r2, r3
        bx lr

#elif __SEGGER_RTL_FP_HW >= 2 && __SEGGER_RTL_USE_FPU_FOR_IDIV

        vmov s0, r0
        vcvt.f64.u32 d16, s0
        vmov s1, r1
        vcvt.f64.u32 d17, s1
        vdiv.f64 d16, d16, d17
        vcvt.u32.f64 s0, d16
        vmov r2, s0
        mls r1, r0, r2, r1
        mov r0, r2
        bx lr

#else

        push {r3, r4, r5, lr}


        movs r4, r0
        negs r5, r1


        bl __aeabi_uidiv


#if __SEGGER_RTL_CORE_HAS_MLA
        mla r1, r0, r5, r4
#else
        muls r5, r5, r0
        adds r1, r4, r5
#endif
        RET3 r3, r4, r5

#endif

END_FUNC __aeabi_uidivmod

#undef L
#define L(label) .L__aeabi_ldivmod_ ##label
# 1571 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_ldivmod

#if __SEGGER_RTL_FP_HW >= 2 && __SEGGER_RTL_USE_FPU_FOR_IDIV


        cmp xh, xl, asr #31
        cmpne yh, yl, asr #31
        bne L(x_big_or_y_big)


        vmov s0, xl
        vcvt.f64.s32 d16, s0
        vmov s1, yl
        vcvt.f64.s32 d17, s1
        vdiv.f64 d16, d16, d17
        vcvt.s32.f64 s0, d16
        vmov ip, s0
        mls yl, ip, yl, xl
        mov xl, ip
        bx lr


L(x_big_or_y_big):

#endif

        push {r4, r5, r6, lr}


        asrs r4, xh, 31
        eors xl, xl, r4
        eors xh, xh, r4
        subs xl, xl, r4
        sbcs xh, xh, r4


        asrs r5, yh, 31
        eors yl, yl, r5
        eors yh, yh, r5
        subs yl, yl, r5
        sbcs yh, yh, r5


        bl __aeabi_uldivmod


        eors yl, yl, r4
        eors yh, yh, r4
        subs yl, yl, r4
        sbcs yh, yh, r4


        eors r4, r4, r5
        eors xl, xl, r4
        eors xh, xh, r4
        subs xl, xl, r4
        sbcs xh, xh, r4
        RET3_r3 r4, r5, r6

END_FUNC __aeabi_ldivmod
# 1651 "./intasmops_arm.s"
#undef L
#define L(label) .L__int64_udivmod_ ##label

ARM_GLOBAL_FUNC __aeabi_uldivmod

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#if __SEGGER_RTL_CORE_HAS_IDIV && __SEGGER_RTL_OPTIMIZE >= 0




        CBNZx yh, L(y_big)
        CBNZx xh, L(x_big_y_small)


        udiv xh, xl, yl


        movs yh, yl
        muls yh, yh, xh
        negs yh, yh
        adds yl, yh, xl


        movs xl, xh
        movs xh, #0
        movs yh, #0
        bx lr



L(x_big_y_small):
        CBZx yl, L(divide_by_zero)
        lsrs yh, yl, #16
        bne L(x_big_y_medium)


        push {r4, r5}


        movs r4, xh
        udiv xh, xh, yl


        movs yh, yl
        muls yh, yh, xh
        subs yh, r4, yh


        lsls yh, yh, #16
        lsrs r5, xl, #16
        orrs yh, yh, r5


        udiv r4, yh, yl


        movs r5, yl
        muls r5, r5, r4
        subs yh, yh, r5


        UXTHs xl, xl
        lsls yh, yh, #16
        orrs yh, yh, xl


        udiv xl, yh, yl
        muls yl, yl, xl
        subs yl, yh, yl


        lsls r4, r4, #16
        orrs xl, xl, r4
        movs yh, #0
        pop {r4, r5}
        bx lr

L(divide_by_zero):
        IDIV0


L(x_big_y_medium):
        movs yh, #0

#elif __SEGGER_RTL_OPTIMIZE >= 0


        CBNZx yh, L(y_big)
        CBNZx xh, L(y_big)


        push {r4, lr}
#if __SEGGER_RTL_BYTE_ORDER < 0
        movs r1, r2
        bl __aeabi_uidivmod
        movs r2, r1
        movs r1, #0
        movs r3, #0
#else
        movs r0, r1
        movs r1, r3
        bl __aeabi_uidivmod
        movs r3, r1
        movs r2, #0
        movs r1, r0
        movs r0, #0
#endif
        RET1_r3 r4

#endif



L(y_big):
        push {r4, r5, r6}




        movs r4, #0
        movs r5, #1
        lsls r5, r5, #31


        CBNZx yh, L(clockwork_normalization)
        CBZx xh, L(clockwork_normalization)
        cmp yh, xl
        bcs L(clockwork_normalization)


        movs yh, yl
        movs yl, #0
        movs r4, r5
        movs r5, #0


L(clockwork_normalization):
        movs r6, #0
L(normalize):
        adds r4, r4, r6
        cmp xh, yh
        bne L(flags_valid)
        cmp xl, yl
L(flags_valid):
        bls L(divide)
L(normal_shift):
        adds yl, yl, yl
        adcs yh, yh, yh
        bcs L(over_normalized)
        lsls r6, r5, #31
        lsrs r5, r5, #1
        lsrs r4, r4, #1
        b L(normalize)



L(over_normalized):
        lsls r6, yh, #31
        lsrs yh, yh, #1
        lsrs yl, yl, #1
        adds yl, yl, r6
        movs r6, #1
        lsls r6, r6, #31
        adds yh, yh, r6
        b L(divide)






L(shift_subtract):
        lsls r6, yh, #31
        lsrs yh, yh, #1
        lsrs yl, yl, #1
        adds yl, yl, r6


L(divide):
        subs xl, xl, yl
        sbcs xh, xh, yh
        bcc L(cant_subtract)
        adcs r4, r4, r4
        adcs r5, r5, r5
        bcc L(shift_subtract)
        b L(done)

L(cant_subtract):
        adds r4, r4, r4
        adcs r5, r5, r5
        bcs L(correct_remainder)


        lsls r6, yh, #31
        lsrs yh, yh, #1
        lsrs yl, yl, #1
        adds yl, yl, r6
        adds xl, xl, yl
        adcs xh, xh, yh
        bcc L(cant_subtract)
        adcs r4, r4, r4
        adcs r5, r5, r5
        bcc L(shift_subtract)
        b L(done)


L(correct_remainder):
        adds xl, xl, yl
        adcs xh, xh, yh


L(done):
        movs yl, xl
        movs yh, xh


        movs xl, r4
        movs xh, r5


        pop {r4, r5, r6}
        bx lr

#elif __SEGGER_RTL_CORE_HAS_IDIV && __SEGGER_RTL_CORE_HAS_CLZ

.macro MDIV u1, u0, d, r


        lsrs r4, \d, 22


#if __SEGGER_RTL_CORE_HAS_MOVW_MOVT
        movw r5, 0xFFC2
        lsls r5, r5, #8
#else
        li r5, 0xFFC200
#endif
        udiv r4, r5, r4


        lsrs r6, \d, 11
        adds r6, r6, #1


        mul r5, r4, r4
        umull r5, r6, r5, r6
        mvns r6, r6
        add r6, r6, r4, lsl #4


        lsrs r5, \d, #1



        itee cc
        movcc r7, #0
        lsrcs r7, r6, #1
        addcs r5, r5, #1
        mls r7, r5, r6, r7


        umull r4, r7, r6, r7
        lsrs r7, r7, #1
        add r7, r7, r6, lsl #15




        movs r4, \d
        movs r5, \d
        umlal r4, r5, r7, \d
        subs r7, r7, r5


        adds r5, \u1, #1
        movs r4, \u0
        umlal r4, r5, r7, \u1


        mls r6, r5, \d, \u0


        cmp r6, r4
        itt hi
        subhi r5, r5, #1
        addhi r6, r6, \d


        cmp r6, \d
        itt cs
        addcs r5, r5, #1
        subcs r6, r6, \d



.endm


        cmp yh, #0
        bne L(y_big)


        CBNZx xh, L(x_big_y_small)


        udiv ip, xl, yl
        mls yl, ip, yl, xl
        mov xl, ip
        bx lr


L(x_big_y_small):

#if __SEGGER_RTL_OPTIMIZE > 0
        lsrs yh, yl, #16
        bne L(x_big_y_medium)


        mov ip, xh
        udiv xh, xh, yl
        mls yh, yl, xh, ip
        lsls yh, yh, #16
        orr yh, yh, xl, lsr #16
        udiv ip, yh, yl
        mls yh, yl, ip, yh
#if __SEGGER_RTL_CORE_HAS_PKHTB_PKHBT
        pkhbt yh, xl, yh, lsl #16
#else
        UXTHs xl, xl
        orr yh, xl, yh, lsl #16
#endif
        udiv xl, yh, yl
        mls yl, yl, xl, yh
        orr xl, xl, ip, lsl #16
        movs yh, #0
        bx lr
#endif


L(x_big_y_medium):
        cmp xh, yl
        bcs L(will_overflow)


        push {r4-r8, lr}
        clz yh, yl
        lsls yl, yl, yh
        lsls xh, xh, yh
        rsbs ip, yh, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs xh, xh, xl, lsr ip
#else
        lsrs ip, xl, ip
        orrs xh, xh, ip
#endif
        lsls xl, xl, yh


#if __SEGGER_RTL_OPTIMIZE > 0
        MDIV xh, xl, yl
#else
        bl L(mdiv)
#endif
        movs xl, r5
        lsrs yl, r6, yh
#if __SEGGER_RTL_CORE_HAS_CLRM
        clrm {xh, yh}
#else
        movs xh, #0
        movs yh, #0
#endif
        pop {r4-r8, pc}




L(will_overflow):
        push {r4-r7, lr}
        udiv ip, xh, yl
        mls xh, ip, yl, xh


        clz yh, yl
        lsls yl, yl, yh
        lsls xh, xh, yh
        rsbs r6, yh, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs xh, xh, xl, lsr r6
#else
        lsrs r6, xl, r6
        orrs xh, xh, r6
#endif
        lsls xl, xl, yh


#if __SEGGER_RTL_OPTIMIZE > 0
        MDIV xh, xl, yl
#else
        bl L(mdiv)
#endif
        mov xh, ip
        movs xl, r5
        movs yl, r6
        lsrs yl, yl, yh
        movs yh, #0
        pop {r4-r7, pc}




L(y_big):
        push {r0, r1, r4-r7, lr}


        clz ip, yh


        lsrs xh, xh, #1
        rrxs xl, xl


        lsls yh, yh, ip
        rsbs r4, ip, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs yh, yh, yl, lsr r4
#else
        lsrs r4, yl, r4
        orrs yh, yh, r4
#endif


#if __SEGGER_RTL_OPTIMIZE > 0
        MDIV xh, xl, yh
#else
        push {r2, r3}
        movs yl, yh
        bl L(mdiv)
        pop {r2, r3}
#endif


        lsrs yh, yh, ip


        rsbs ip, ip, #31
        lsrs r5, r5, ip


        it ne
        subne r5, r5, #1


        pop {r0, r1}
        umull r6, r7, r5, yl
        mla r7, r5, yh, r7
        subs xl, xl, r6
        sbcs xh, xh, r7


        cmp xl, yl
        sbcs ip, xh, yh
        bcc L(no_correction)


        subs yl, xl, yl
        sbcs yh, xh, yh
        adds xl, r5, #1
        movs xh, 0
        pop {r4-r7, pc}


L(no_correction):
        movs yl, xl
        movs yh, xh
        movs xl, r5
        movs xh, 0


        pop {r4-r7, pc}

#if __SEGGER_RTL_OPTIMIZE <= 0
L(mdiv):
       .type L(mdiv), function
        MDIV xh, xl, yl
        bx lr
#endif

#elif __SEGGER_RTL_OPTIMIZE > 0


#if __SEGGER_RTL_FP_HW >= 2 && __SEGGER_RTL_USE_FPU_FOR_IDIV

        orrs ip, xh, yh
        bne L(x_big_or_y_big)


        vmov s0, xl
        vcvt.f64.u32 d16, s0
        vmov s1, yl
        vcvt.f64.u32 d17, s1
        vdiv.f64 d16, d16, d17
        vcvt.u32.f64 s0, d16
        vmov ip, s0
        mls yl, ip, yl, xl
        mov xl, ip
        bx lr

L(x_big_or_y_big):

#endif



        push {r4-r10}


        rsbs r4, yh, #1
        it ls
        cmpls yh, xh, lsr #7
        bhi L(small_y_or_q)


        NORM32 r6, yh, r4
        rsbs r5, r4, #32


        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        lsrs r7, yl, r5
        orrs r6, r6, r7
        lsrs r6, r6, #25
        ldrb ip, [ip, r6]
#else
        orr r6, r6, yl, lsr r5
        ldrb ip, [ip, r6, lsr #25]
#endif
        subs r4, r4, #7
        lsls ip, ip, r4




        umull r8, r5, ip, yl
        mla r9, ip, yh, r5
        umull r7, r6, ip, xl
        movs r10, #0
        umlal r6, r10, ip, xh
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        negs r9, r9
        negs r8, r8
        sbcs r9, r9, #0
#else
        rsbs r8, r8, #0
        rsc r9, r9, #0
#endif



.macro divstep w, m
        movs r4, #0
        umlal r7, r4, r8, \m
        movs \w, #0
        adds r6, r6, r4
        adcs \w, \w, \w
        umlal r6, \w, r9, \m
        add r10, r10, \w
.endm

        divstep ip, r10
        divstep r5, ip
        CBZx r5, L(mult_complete)
        divstep ip, r5
        cmp ip, #0
        beq L(mult_complete)
        divstep r5, ip
        divstep ip, r5
        divstep r5, ip


L(mult_complete):
        adds r7, r7, r8
        adcs r6, r6, r9
        adcs r10, r10, #0


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        negs yh, yh
        negs yl, yl
        sbcs yh, yh, #0
#else
        rsbs yl, yl, #0
        rsc yh, yh, #0
#endif
        umlal xl, xh, yl, r10
        movs yl, xl
        mla yh, r10, yh, xh
        movs xh, #0
        movs xl, r10
        pop {r4-r10}
        bx lr


L(small_y_or_q):
        cmp yh, #0
        bne L(small_q_or_large_y)



        cmp yl, #5
        bcc L(very_small_y)


        cmp yl, #0x02000000
        bcs L(medium_y)


        cmp xh, #0
        beq L(small_x)



        NORM32 yh, yl, r4

        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        lsrs yh, yh, #25
        ldrb ip, [ip, yh]
#else
        ldrb ip, [ip, yh, lsr #25]
#endif
        sub r4, r4, #7
        lsl ip, ip, r4
        mul r10, ip, yl
        rsb r10, r10, #0
        umull r4, r8, ip, xl
        movs r9, #0
        umlal r8, r9, ip, xh

.macro divstp1 l, h, x, y, exit
        movs \l, #0
        umlal r4, \l, \x, r10
        movs \h, #0
        umlal \l, \h, \y, r10
       .ifnc \exit,
        orrs \exit, \x, \y
        beq L(round)
       .endif
        adds r8, r8, \l
        adc r9, r9, \h
.endm

.macro divstp2 l, i
        movs \l, #0
        umlal r4, \l, r10, \i
        adds r8, r8, \l
        adcs r9, r9, #0
.endm


        divstp1 yh, r6, r8, r9
        divstp1 ip, r7, yh, r6
        divstp1 yh, r6, ip, r7, r7
        divstp1 ip, r7, yh, r6, r6
        divstp1 yh, r6, ip, r7, r7


        CBZx yh, L(round)
        divstp2 r5, yh
        CBZx r5, L(round)
        divstp2 yh, r5
        CBZx r3, L(round)
        divstp2 r5, yh
        divstp2 yh, r5
        divstp2 r5, yh
        divstp2 yh, r5


L(round):
        cmn r10, r4
        adcs r8, r8, #0
        adcs r9, r9, #0


#if __SEGGER_RTL_CORE_HAS_MLS
        mls yl, r8, yl, xl
#else
        negs yl, yl
        mla yl, r8, yl, xl
#endif
        movs yh, #0
        mov xh, r9
        mov xl, r8
        pop {r4-r10}
        bx lr

L(medium_y):

.macro medstp1 n
        cmp yl, xh, lsr #\n
        itt ls
        subls xh, xh, yl, lsl #\n
        orrls r6, r6, #1<<\n
.endm
.macro medstp2 n
        subs r8, xl, yl, lsl #\n
        sbcs r9, xh, yl, lsr #32-\n
        ittt cs
        movcs xl, r8
        movcs xh, r9
        orrcs ip, ip, #1<<\n
.endm


        movs r6, #0
        medstp1 6
        medstp1 5
        medstp1 4
        medstp1 3
        medstp1 2
        medstp1 1
        cmp yl, xh
        itt ls
        subls xh, xh, yl
        orrls r6, r6, #1


        mov ip, #0
        medstp2 31
        medstp2 30
        medstp2 29
        medstp2 28
        medstp2 27
        medstp2 26
        medstp2 25
        medstp2 24
        medstp2 23
        medstp2 22
        medstp2 21
        medstp2 20
        medstp2 19
        medstp2 18
        medstp2 17
        medstp2 16
        medstp2 15
        medstp2 14
        medstp2 13
        medstp2 12
        medstp2 11
        medstp2 10
        medstp2 9
        medstp2 8
        medstp2 7
        medstp2 6
        medstp2 5
        medstp2 4
        medstp2 3
        medstp2 2
        medstp2 1
        medstp2 0


        movs yh, xh
        movs yl, xl
        movs xh, r6
        mov xl, ip
        pop {r4-r10}
        bx lr

L(small_q_or_large_y):
        movs r5, #0
        movs r7, #0

.macro large_y_divstep x
        subs r6, xl, yl, lsl #\x
        sbcs r4, xh, yl, lsr #32-\x
        itt cs
        subscs r4, r4, yh, lsl #\x
        cmpcs r7, yh, lsr #32-\x
        ittt cs
        orrcs r5, r5, #1<<\x
        movcs xh, r4
        movcs xl, r6
.endm


        large_y_divstep 6
        large_y_divstep 5
        large_y_divstep 4
        large_y_divstep 3
        large_y_divstep 2
        large_y_divstep 1
        subs r6, xl, yl
        sbcs r4, xh, yh
        ittt cs
        orrcs r5, r5, #1
        movcs xl, r6
        movcs xh, r4


        movs yh, xh
        movs yl, xl
        movs xh, #0
        movs xl, r5
        pop {r4-r10}
        bx lr

L(small_x):
        NORM32 r7, yl, r4

        la ip, __SEGGER_RTL_inverse_lut-64
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        lsrs r7, r7, #25
        ldrb ip, [ip, r7]
#else
        ldrb ip, [ip, r7, lsr #25]
#endif


        cmp yl, xl, lsr #7
        bhi L(short_qotient)

.macro small_x_divstep o, i
        movs \o, #0
        umlal r5, \o, r9, \i
        add r8, r8, \o
.endm


        subs r4, r4, #7
        lsls ip, ip, r4
        mul r9, ip, yl
        negs r9, r9
        umull r5, r8, ip, xl
        small_x_divstep r7, r8
        small_x_divstep ip, r7
        small_x_divstep r7, ip
        small_x_divstep ip, r7
        umlal r5, r8, r9, ip
        cmn r5, r9
        adc r8, r8, #0


#if __SEGGER_RTL_CORE_HAS_MLS
        mls yl, r8, yl, xl
#else
        negs yl, yl
        mla yl, r8, yl, xl
#endif


        mov xl, r8
        pop {r4-r10}
        bx lr

L(short_qotient):
        mov ip, xl
        movs xl, #0

.macro sdivstp n
       .if \n
        cmp yl, ip, lsr #\n
        itt ls
        subls ip, ip, yl, lsl #\n
       .else
        cmp yl, ip
        itt ls
        subls ip, ip, yl
       .endif
        orrls xl, xl, #1<<\n
.endm


        sdivstp 6
        sdivstp 5
        sdivstp 4
        sdivstp 3
        sdivstp 2
        sdivstp 1
        sdivstp 0


        mov yl, ip
        pop {r4-r10}
        bx lr

L(very_small_y):
#if __SEGGER_RTL_CORE_HAS_TBB_TBH

        tbb [pc, yl]
L(base):
       .byte (L(y_is_0)-L(base)) / 2
       .byte (L(y_is_1)-L(base)) / 2
       .byte (L(y_is_2)-L(base)) / 2
       .byte (L(y_is_3)-L(base)) / 2
       .byte (L(y_is_4)-L(base)) / 2
        INSN_ALIGN
#else
        cmp yl, #3
        bhi L(y_is_4)
        beq L(y_is_3)
        cmp yl, #1
        bhi L(y_is_2)
        bcc L(y_is_0)
#endif


L(y_is_1):
        pop {r4-r10}
        movs yl, #0
        bx lr


L(y_is_0):
        pop {r4-r10}
        LDIV0


L(y_is_2):
        pop {r4-r10}
        ands yl, xl, #1
        lsrs xl, xl, #1
        orr xl, xl, xh, lsl #31
        lsrs xh, xh, #1
        bx lr


L(y_is_3):
        li yl, 0x55555555
        movs yh, #0
        umull r7, r4, yl, xl
        umull r6, r5, yl, xh
        adds r4, r4, r6
        adcs r5, r5, yh
        adds r7, r7, r4
        adcs r6, r5, yh
        cmp xl, xl
        adcs r7, r7, r6
        adcs r4, r4, r6
        adcs r5, r5, yh


        subs yl, xl, r4, lsl #1
        subs yl, yl, r4
        movs xl, r4
        movs xh, r5
        pop {r4-r10}
        bx lr


L(y_is_4):
        and yl, xl, #3
        lsrs xl, xl, #2
        orr xl, xl, xh, lsl #30
        lsrs xh, xh, #2
        pop {r4-r10}
        bx lr

#elif !__SEGGER_RTL_CORE_HAS_CLZ || __SEGGER_RTL_OPTIMIZE <= -2

#if __SEGGER_RTL_OPTIMIZE >= 0
        orrs ip, xh, yh
        bne L(x_big_y_big)


        push {r4, r5, r6, lr}


        movs r4, xl
        negs r5, yl


#if __SEGGER_RTL_BYTE_ORDER > 0
        movs r0, xl
#endif
        movs r1, yl
        bl __aeabi_uidiv


        mla yl, r0, r5, r4


#if __SEGGER_RTL_BYTE_ORDER > 0
        movs xl, r0
#endif
        movs xh, #0
        movs yh, #0


        RET3_r3 r4, r5, r6

#endif


L(x_big_y_big):


        push {r4, r5}




        movs r4, #0
        movs r5, #0x80000000


L(normalize):
        cmp xh, yh
        it eq
        cmpeq xl, yl
        bls L(divide)
        adds yl, yl, yl
        adcs yh, yh, yh
        bcs L(over_normalized)
        lsrs r5, r5, #1
        rrxs r4, r4
        bls L(normalize)
L(over_normalized):
        rrxs yh, yh
        rrx yl, yl
        b L(divide)


L(shift_subtract):
        lsrs yh, yh, #1
        rrxs yl, yl


L(divide):
        cmp xl, yl
        sbcs ip, xh, yh
        itt cs
        subcs xl, xl, yl
        movcs xh, ip
        adcs r4, r4, r4
        adcs r5, r5, r5
        bcc L(shift_subtract)


        movs yl, xl
        movs yh, xh


        movs xl, r4
        movs xh, r5


        pop {r4, r5}
        bx lr

#else


        CBNZx yh, L(y_big)
        CBNZx xh, L(x_big_y_small)


        push {r4, r5, r6, lr}


        movs r4, xl
        negs r5, yl


#if __SEGGER_RTL_BYTE_ORDER > 0
        movs r0, xl
#endif
        movs r1, yl
        bl __aeabi_uidiv


        mla yl, r0, r5, r4


#if __SEGGER_RTL_BYTE_ORDER > 0
        movs xl, r0
#endif
        movs xh, #0
        movs yh, #0


        RET3_r3 r4, r5, r6


L(x_big_y_small):



        push {r4, r5}


        clz r4, yl
        clz r5, xh
        subs r4, r4, r5
        bpl L(shift_left)


        negs r4, r4
        lsrs yh, yl, r4
        rsbs r5, r4, #32
        lsls yl, yl, r5


        cmp xh, yh
        it eq
        cmpeq xl, yl
        bhs L(setup_0)
        lsrs yh, yh, #1
        rrxs yl, yl
        subs r5, r5, #1




L(setup_0):
        movs r4, #0x80000000
        lsrs r5, r4, r5
        movs r4, #0
        b L(divide)


L(shift_left):
        lsls yh, yl, r4
        movs yl, #0


        cmp xh, yh
        it eq
        cmpeq xl, yl
        bhs L(setup_2)
        lsrs yh, yh, #1
        rrxs yl, yl
        subs r4, r4, #1




L(setup_2):
        tst r4, r4
        itttt mi
        addmi r4, r4, #32
        movmi r5, #0x80000000
        lsrmi r5, r5, r4
        movmi r4, #0
        ittt pl
        movpl r5, #0x80000000
        lsrpl r4, r5, r4
        movpl r5, #0
        b L(divide)


L(y_big):


        cmp xl, yl
        sbcs ip, xh, yh
        bcc L(early_out)



        push {r4, r5}


        clz r4, yh
        clz r5, xh
        subs r4, r4, r5


        rsbs r5, r4, #32
        lsls yh, yh, r4
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs yh, yh, yl, lsr r5
#else
        lsrs r5, yl, r5
        orrs yh, yh, r5
#endif
        lsls yl, yl, r4


        cmp xh, yh
        it eq
        cmpeq xl, yl
        bhs L(setup)
        lsrs yh, yh, #1
        rrxs yl, yl
        subs r4, r4, #1




L(setup):
        movs r5, #0x80000000
        lsrs r5, r5, r4
        movs r4, #0
        b L(divide)


L(shift_subtract):
        lsrs yh, yh, #1
        rrxs yl, yl


L(divide):
        cmp xl, yl
        sbcs ip, xh, yh
        itt cs
        subcs xl, xl, yl
        movcs xh, ip
        adcs r4, r4, r4
        adcs r5, r5, r5
        bcc L(shift_subtract)


        movs yl, xl
        movs yh, xh


        movs xl, r4
        movs xh, r5


        pop {r4, r5}
        bx lr


L(early_out):
        movs yl, xl
        movs yh, xh
        movs xl, #0
        movs xh, #0
        bx lr

#endif

END_FUNC __aeabi_uldivmod

#undef L
#define L(label) .L__SEGGER_clzsi2_ ##label

ARM_GLOBAL_FUNC __clzsi2

#if __SEGGER_RTL_CORE_HAS_CLZ

        clz r0, r0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA != __SEGGER_RTL_ISA_T16

        NORM32 r0, r0, r2
        movs r0, r2
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < -1
        movs r3, #0

L(count):
        adds r3, r3, #1
        lsls r0, r0, #1
        bcc L(count)
L(done):
        subs r0, r3, #1
        bx lr

#else

        movs r3, #0
        lsrs r2, r0, #16
        bne L(1)
        lsls r0, r0, #16
        adds r3, r3, #16
L(1):
        lsrs r2, r0, #24
        bne L(2)
        lsls r0, r0, #8
        adds r3, r3, #8
L(2):
        lsrs r2, r0, #28
        bne L(3)
        lsls r0, r0, #4
        adds r3, r3, #4
L(3):
        lsrs r2, r0, #30
        bne L(4)
        lsls r0, r0, #2
        adds r3, r3, #2
L(4):
        mvns r0, r0
        lsrs r0, r0, #31
        adds r0, r0, r3
        bx lr

#endif

END_FUNC __clzsi2

#undef L
#define L(label) .L__SEGGER_clzdi2_ ##label

ARM_GLOBAL_FUNC __clzdi2

#if __SEGGER_RTL_CORE_HAS_CLZ && (__SEGGER_RTL_TARGET_ISA != __SEGGER_RTL_ISA_T16)

        cmp xh, #0
        itee ne
        clzne r0, xh
        clzeq r0, xl
        addeq r0, r0, #32
        bx lr

#else

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16




        movs r3, #32
        CBZx xh, L(high_zero)
        movs r3, #0
        movs xl, xh
L(high_zero):

#else




        movs r3, #32
        cmp xh, #0
        itt ne
        movne r3, #0
        movne xl, xh

#endif

#if __SEGGER_RTL_TARGET_ISA != __SEGGER_RTL_ISA_T16

        lsrs r2, xl, #16
        lsleq xl, xl, #16
        addeq r3, r3, #16
        lsrs r2, xl, #24
        lsleq xl, xl, #8
        addeq r3, r3, #8
        lsrs r2, xl, #28
        lsleq xl, xl, #4
        addeq r3, r3, #4
        lsrs r2, xl, #30
        lsleq xl, xl, #2
        addeq r3, r3, #2
        mvns xl, xl
        lsrs xl, xl, #31
        adds r3, r3, xl
        movs r0, r3
        bx lr

#elif __SEGGER_RTL_OPTIMIZE < -1

L(count):
        adds r3, r3, #1
        lsls xl, xl, #1
        bcc L(count)
L(done):
        subs r0, r3, #1
        bx lr

#else
        lsrs r2, xl, #16
        bne L(1)
        lsls xl, xl, #16
        adds r3, r3, #16
L(1):
        lsrs r2, xl, #24
        bne L(2)
        lsls xl, xl, #8
        adds r3, r3, #8
L(2):
        lsrs r2, xl, #28
        bne L(3)
        lsls xl, xl, #4
        adds r3, r3, #4
L(3):
        lsrs r2, xl, #30
        bne L(4)
        lsls xl, xl, #2
        adds r3, r3, #2
L(4):
        mvns xl, xl
        lsrs r0, xl, #31
        adds r0, r0, r3
        bx lr
#endif

#endif

END_FUNC __clzdi2

#undef L
#define L(label) .L__SEGGER_clzdi2_ ##label
# 3072 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_imod

       push {r3, lr}
       bl __aeabi_idivmod
       movs r0, r1
       RET1 r3

END_FUNC __aeabi_imod
# 3102 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_uimod

       push {r3, lr}
       bl __aeabi_uidivmod
       movs r0, r1
       RET1 r3

END_FUNC __aeabi_uimod
# 3132 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_lmod

        push {r3, lr}
        bl __aeabi_ldivmod
        movs r0, r2
        movs r1, r3
        RET1 r3

END_FUNC __aeabi_lmod
# 3163 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_ulmod

        push {r3, lr}
        bl __aeabi_uldivmod
        movs r0, r2
        movs r1, r3
        RET1 r3

END_FUNC __aeabi_ulmod
# 3190 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_idiv0

        movs r0, #0
        movs r1, #0
        bx lr

END_FUNC __aeabi_idiv0
# 3216 "./intasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_ldiv0

        movs xl, #0
        movs xh, #0
        movs yl, #0
        movs yh, #0
        bx lr

END_FUNC __aeabi_ldiv0

#endif

       .end
