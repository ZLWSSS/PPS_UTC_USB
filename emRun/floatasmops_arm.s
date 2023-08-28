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
# 1 "./floatasmops_arm.s"
# 86 "./floatasmops_arm.s"
#if !defined(__aarch64__ )

@ gnu_syntax

#include "asmdefs_arm.ah"
# 99 "./floatasmops_arm.s"
#if __SEGGER_RTL_INCLUDE_AEABI_API == 2
# 110 "./floatasmops_arm.s"
#if __SEGGER_RTL_OPTIMIZE >= 2

LOCAL_RODATA __aeabi_fdiv_reciprocal_table, 4


       .word 0x820fe040, 0x860fa233, 0x890f6604, 0x8d0f2b9d
       .word 0x900ef2eb, 0x930ebbdb, 0x970e865b, 0x990e525a
       .word 0x9c0e1fc8, 0x9f0dee96, 0xa20dbeb6, 0xa40d901b
       .word 0xa60d62b8, 0xa90d3681, 0xab0d0b6a, 0xad0ce169
       .word 0xaf0cb872, 0xb10c907e, 0xb30c6981, 0xb50c4373
       .word 0xb70c1e4c, 0xb80bfa03, 0xba0bd691, 0xbc0bb3ee
       .word 0xbd0b9214, 0xbf0b70fc, 0xc00b509e, 0xc10b30f6
       .word 0xc30b11fd, 0xc40af3ae, 0xc50ad603, 0xc70ab8f7
       .word 0xc80a9c85, 0xc90a80a8, 0xca0a655c, 0xcb0a4a9d
       .word 0xcc0a3066, 0xcd0a16b3, 0xce09fd81, 0xcf09e4cb
       .word 0xd009cc8e, 0xd109b4c7, 0xd2099d72, 0xd309868d
       .word 0xd3097013, 0xd4095a02, 0xd5094458, 0xd6092f11
       .word 0xd7091a2b, 0xd70905a4, 0xd808f178, 0xd908dda5
       .word 0xd908ca2a, 0xda08b703, 0xdb08a430, 0xdb0891ac
       .word 0xdc087f78, 0xdc086d90, 0xdd085bf3, 0xde084aa0
       .word 0xde083993, 0xdf0828cc, 0xdf081849, 0xe0080808

END_RODATA __aeabi_fdiv_reciprocal_table

#endif



LOCAL_RODATA __aeabi_ddiv_reciprocal_table, 2


       .hword 0xfe00, 0xfc0c, 0xfa20, 0xf83c, 0xf660, 0xf488, 0xf2b8, 0xf0f0
       .hword 0xef2c, 0xed70, 0xebbc, 0xea0c, 0xe864, 0xe6c0, 0xe524, 0xe38c
       .hword 0xe1fc, 0xe070, 0xdee8, 0xdd64, 0xdbe8, 0xda74, 0xd900, 0xd794
       .hword 0xd628, 0xd4c4, 0xd368, 0xd20c, 0xd0b4, 0xcf64, 0xce14, 0xcccc
       .hword 0xcb84, 0xca44, 0xc904, 0xc7cc, 0xc698, 0xc564, 0xc434, 0xc30c
       .hword 0xc1e4, 0xc0c0, 0xbfa0, 0xbe80, 0xbd68, 0xbc50, 0xbb3c, 0xba2c
       .hword 0xb920, 0xb814, 0xb70c, 0xb608, 0xb508, 0xb408, 0xb30c, 0xb214
       .hword 0xb11c, 0xb02c, 0xaf38, 0xae4c, 0xad60, 0xac74, 0xab8c, 0xaaa8
       .hword 0xa9c8, 0xa8e8, 0xa808, 0xa72c, 0xa654, 0xa57c, 0xa4a8, 0xa3d4
       .hword 0xa304, 0xa234, 0xa168, 0xa0a0, 0x9fd8, 0x9f10, 0x9e4c, 0x9d88
       .hword 0x9cc8, 0x9c08, 0x9b4c, 0x9a90, 0x99d4, 0x991c, 0x9868, 0x97b4
       .hword 0x9700, 0x964c, 0x95a0, 0x94f0, 0x9444, 0x9398, 0x92f0, 0x9248
       .hword 0x91a0, 0x90fc, 0x9058, 0x8fb8, 0x8f14, 0x8e78, 0x8dd8, 0x8d3c
       .hword 0x8ca0, 0x8c08, 0x8b70, 0x8ad8, 0x8a40, 0x89ac, 0x8918, 0x8888
       .hword 0x87f4, 0x8764, 0x86d8, 0x8648, 0x85bc, 0x8534, 0x84a8, 0x8420
       .hword 0x8398, 0x8310, 0x828c, 0x8208, 0x8184, 0x8100, 0x8080, 0x8000


       .byte 0xfc, 0xf8, 0xf4, 0xf0, 0xec, 0xe8, 0xe6, 0xe2, 0xde, 0xdc, 0xd8, 0xd4, 0xd2, 0xd0, 0xcc, 0xca
       .byte 0xc6, 0xc4, 0xc2, 0xbe, 0xbc, 0xba, 0xb6, 0xb4, 0xb2, 0xb0, 0xae, 0xac, 0xaa, 0xa8, 0xa4, 0xa2
       .byte 0xa0, 0x9e, 0x9c, 0x9a, 0x9a, 0x98, 0x96, 0x94, 0x92, 0x90, 0x8e, 0x8c, 0x8c, 0x8a, 0x88, 0x86
       .byte 0x84, 0x84, 0x82, 0x80, 0x80, 0x7e, 0x7c, 0x7a, 0x7a, 0x78, 0x76, 0x76, 0x74, 0x74, 0x72, 0x70
       .byte 0x70, 0x6e, 0x6e, 0x6c, 0x6c, 0x6a, 0x68, 0x68, 0x66, 0x66, 0x64, 0x64, 0x62, 0x62, 0x60, 0x60
       .byte 0x60, 0x5e, 0x5e, 0x5c, 0x5c, 0x5a, 0x5a, 0x58, 0x58, 0x58, 0x56, 0x56, 0x54, 0x54, 0x54, 0x52
       .byte 0x52, 0x52, 0x50, 0x50, 0x4e, 0x4e, 0x4e, 0x4c, 0x4c, 0x4c, 0x4a, 0x4a, 0x4a, 0x4a, 0x48, 0x48
       .byte 0x48, 0x46, 0x46, 0x46, 0x44, 0x44, 0x44, 0x44, 0x42, 0x42, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40

END_RODATA __aeabi_ddiv_reciprocal_table
# 177 "./floatasmops_arm.s"
       .syntax unified
# 197 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fadd_ ##label

ARM_GLOBAL_FUNC __aeabi_fadd

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vadd.f32 s0, s0, s1
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define ADD32_WORKING_SET r4, r5


        movs r2, #1
        lsls r2, r2, #31


LOCAL_ENTRY .L__aeabi_fadd_fast_entry
        movs r3, r0
        eors r3, r3, r1
        bmi L(subtract)


        push {ADD32_WORKING_SET}



L(add_same_sign):
        subs r3, r0, r1
        bcs L(add_already_ordered)
        subs r0, r0, r3
        adds r1, r1, r3
L(add_already_ordered):


        lsls r3, r1, #1


        lsls r4, r0, #1
        lsrs r4, r4, #24


        cmp r4, #0xFF
        beq L(add_inf_or_nan)


        CBZx r4, L(zero)


        lsrs r3, r3, #24
        beq L(add_done)




        subs r3, r4, r3


        cmp r3, #24
        bgt L(add_done)



        lsls r1, r1, #8
        orrs r1, r1, r2


        lsrs r4, r0, #23


        lsls r0, r0, #8
        orrs r0, r0, r2


        negs r5, r3
        adds r5, r5, #25



        movs r2, r1
        lsls r2, r2, r5
        lsrs r2, r2, #7


        lsrs r1, r1, r3


        adds r5, r0, r1


        bcc L(add_no_normalization)
        lsrs r5, r5, #1
        adds r4, r4, #2


L(add_no_normalization):
        subs r4, r4, #1
        lsls r4, r4, #23


        lsrs r0, r5, #8



        movs r1, #1
        lsls r1, r1, #31


        lsls r5, r5, #24
        orrs r2, r2, r5



        sbcs r2, r2, r1
        adcs r0, r0, r4


        lsls r1, r0, #1
        lsrs r1, r1, #24
        cmp r1, #0xFF
        bcc L(add_done)



        lsrs r0, r0, #23
        lsls r0, r0, #23


L(add_done):
        pop {ADD32_WORKING_SET}
        bx lr


L(zero):
        lsrs r0, r0, #31
        lsls r0, r0, #31
        b L(add_done)


L(add_inf_or_nan):
        lsls r2, r0, #9
        beq L(add_done)


        movs r0, #0x7F
        lsls r0, r0, #4
        adds r0, r0, #0xC
        lsls r0, r0, #20
        b L(add_done)


L(subtract):


        mov ip, r4


        eors r1, r1, r2


        subs r3, r0, r1
        bcs L(sub_already_ordered)
        eors r3, r3, r2
        subs r0, r0, r3
        adds r1, r1, r3
L(sub_already_ordered):


        lsls r3, r1, #1


        lsls r1, r1, #8
        orrs r1, r1, r2


        lsrs r3, r3, #24


        lsls r4, r0, #1
        lsrs r4, r4, #24



        cmp r4, #0xFF
        beq L(sub_inf_or_nan)


        CBZx r3, L(sub_zero)



        negs r3, r3
        adds r3, r3, r4
        cmp r3, #1





        bcc L(exponents_equal)



        bne L(exponents_differ_by_more_than_1)



        lsrs r3, r0, #23



        lsls r0, r0, #9



        subs r0, r0, r1



        bcc L(normalization_steps)



        lsls r3, r3, #23



        movs r1, r0


        lsrs r0, r0, #9




        lsls r1, r1, #23


        sbcs r1, r1, r2


        adcs r0, r0, r3
L(sub_done):
        mov r4, ip
        bx lr


L(sub_zero):
        tst r4, r4
        bne L(sub_done)
        movs r0, #0
        b L(sub_done)



L(exponents_equal):


        lsrs r3, r0, #23



        lsls r0, r0, #9


        lsls r1, r1, #1
        subs r0, r0, r1


        beq L(sub_done)






L(normalization_steps):
        movs r1, #0


L(sub_normalize):
        adds r1, r1, #1
        lsls r0, r0, #1
        bcc L(sub_normalize)




        cmp r4, r1
        bls L(underflow)


        subs r3, r3, r1
        lsls r3, r3, #23


        lsrs r0, r0, #9


        adds r0, r0, r3
        b L(sub_done)


L(underflow):
        lsrs r0, r3, #8
        lsls r0, r0, #31
        b L(sub_done)



L(exponents_differ_by_more_than_1):
        cmp r3, #25
        bhi L(sub_done)


        adds r3, r3, #1




        movs r4, r1
        lsrs r1, r1, r3
        rors r4, r4, r3
        eors r4, r4, r1



        cmp r4, #1
        adcs r1, r1, r1


        lsrs r3, r0, #23


        lsls r0, r0, #8
        orrs r0, r0, r2




        subs r4, r0, r1




        bmi L(sub_already_normalized)



        lsls r4, r4, #2
        lsrs r4, r4, #1
L(sub_already_normalized):


        subs r3, r3, #1


        lsls r3, r3, #23


        lsrs r0, r4, #8


        lsls r4, r4, #24
        sbcs r4, r4, r2


        adcs r0, r0, r3


        mov r4, ip
        bx lr


L(sub_inf_or_nan):
        cmp r3, #0xFF
        beq L(sub_nan)


        lsls r1, r0, #9
        beq L(sub_done)


L(sub_nan):
        movs r0, #0x7F
        lsls r0, r0, #4
        adds r0, r0, #0xC
        lsls r0, r0, #20
        b L(sub_done)

#else


        mov ip, #0xFF000000


        teq r0, r1
        bmi L(subtract)


        subs r3, r0, r1
        itt cc
        subcc r0, r0, r3
        addcc r1, r1, r3


        cmp ip, r0, lsl #1
        bls L(add_inf_or_nan)


        tst ip, r1, lsl #1
        beq L(add_zero)


        lsrs r2, r0, #23




        subs r3, r2, r1, lsr #23

#if __SEGGER_RTL_TARGET_ISA != __SEGGER_RTL_ISA_T32

        cmp r3, #24
        it gt
        bxgt lr
#endif


        mov ip, #0x80000000
        orr r0, ip, r0, lsl #8
        orr r1, ip, r1, lsl #8



        rsb ip, r3, #32


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        lsl.w ip, r1, ip
        lsrs.w r1, r1, r3
        adds r0, r0, r1
#else
        lsl ip, r1, ip
        adds r0, r0, r1, lsr r3
#endif


        itee cc
        subcc r2, r2, #1
        movscs r0, r0, rrx
        orrcs r0, r0, #1


        orrs ip, ip, r0, lsl #25
        itt eq
        tsteq r0, #0x100
        biceq r0, r0, #0x80


        lsrs r0, r0, #8


        adc r0, r0, r2, lsl #23


        mov r1, #0x01000000
        cmn r1, r0, lsl #1
        it cc
        bxcc lr



#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        bfc r0, #0, #23
#else
        lsrs r0, r0, #23
        lsls r0, r0, #23
#endif
        bx lr

L(add_zero):
        tst ip, r0, lsl #1
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        bne L(return)
#else
        bxne lr
#endif


L(zero):
        and r0, r0, #0x80000000
L(return):
        bx lr


L(subtract):


        eor r1, r1, #0x80000000


        subs r3, r0, r1
        ittt cc
        eorcc r3, r3, #0x80000000
        subcc r0, r0, r3
        addcc r1, r1, r3



        cmp ip, r0, lsl #1
        bls L(sub_inf_or_nan)


        tst ip, r1, lsl #1
        beq L(sub_zero)


        lsrs r2, r0, #23




        sub r3, r2, r1, lsr #23


        mov ip, #0x80000000
        orr r1, ip, r1, lsl #8
        orr r0, ip, r0, lsl #8


        rsb ip, r3, #32
        lsls ip, r1, ip


        lsr r1, r1, r3
        it ne
        orrne r1, r1, #1


        subs r0, r0, r1
        bmi L(sub_already_normalized)



        beq L(done)


        lsrs r3, r2, #8
        UXTBs r2, r2


        NORM32D r0, r0, r2, r1, f_exp
        ble L(sub_zero_result)


        add r2, r2, r3, lsl #8


L(sub_already_normalized):


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r1, r0, #8, #23
        lsls r0, r0, #25
#else
        lsls r0, r0, #1
        lsrs r1, r0, #9
        lsls r0, r0, #24
#endif
        adc r0, r1, r2, lsl #23


        it cc
        bxcc lr
        it eq
        biceq r0, r0, #1
        bx lr


L(sub_zero):
        tst ip, r0, lsl #1
        it eq
        moveq r0, #0
L(done):
        bx lr


L(sub_zero_result):
        lsls r0, r3, #31
        bx lr
# 801 "./floatasmops_arm.s"
L(sub_inf_or_nan):
        cmp ip, r1, lsl #1
        beq L(return_nan)


L(add_inf_or_nan):
        cmp ip, r0, lsl #1
        it eq
        bxeq lr

L(return_nan):
        li r0, 0x7fc00000
        bx lr

#endif

END_FUNC __aeabi_fadd
# 837 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dadd_ ##label

ARM_GLOBAL_FUNC __aeabi_dadd

#if __SEGGER_RTL_FP_HW >= 2


        vmov d0, xl, xh
        vmov d1, yl, yh
        vadd.f64 d0, d0, d1
        vmov xl, xh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define ADD64_WORKING_SET r4, r5, r6, r7

        push {ADD64_WORKING_SET}


        movs r5, #1
        lsls r5, r5, #31


LOCAL_ENTRY .L__aeabi_dadd_fast_entry
        movs r7, xh
        eors r7, r7, yh
        bmi L(subtract)


L(signs_identical):
        cmp yh, xh
        bne 1f
        cmp yl, xl
1: bls L(already_ordered)


        eors xl, xl, yl
        eors yl, yl, xl
        eors xl, xl, yl
        eors xh, xh, yh
        eors yh, yh, xh
        eors xh, xh, yh


L(already_ordered):
        adds r6, xh, xh
        lsrs r6, r6, #21


        adds r7, yh, yh
        lsrs r7, r7, #21


        beq L(add_zero)


        adds r4, r6, #1
        lsls r4, r4, #21
        beq L(done)


        subs r4, r6, r7


        cmp r4, #53
        bhi L(done)


        lsrs r6, xh, #20


        lsls yh, yh, #11
        orrs yh, yh, r5
        lsrs yh, yh, #11


        lsls xh, xh, #11
        orrs xh, xh, r5
        asrs xh, xh, #11
# 926 "./floatasmops_arm.s"
        movs r7, yl


        cmp r4, #32
        bcs L(add_shifted_word)




        rors r7, r7, r4
        lsrs yl, yl, r4
        eors r7, r7, yl



        rors yh, yh, r4
        eors yl, yl, yh
        lsls yh, yh, r4
        lsrs yh, yh, r4
        eors yl, yl, yh


        movs r4, #0


        adds xl, xl, yl
        adcs xh, xh, yh


        bcc L(already_normalized)


L(normalization_required):


        adds yl, r6, #2
        lsls yl, yl, #21
        beq L(inf)





        lsls yl, xl, #31
        cmp r7, #1
        adcs yl, yl, r4
        movs r7, yl


        lsrs xl, xl, #1
        lsls yh, xh, #31
        orrs xl, xl, yh
        lsrs xh, xh, #1


L(already_normalized):
        adds r6, r6, #1
        lsls r6, r6, #20


        lsrs yl, xl, #1
        sbcs r7, r7, r5
        adcs xl, xl, r4
        adcs xh, xh, r6


L(done):
        pop {ADD64_WORKING_SET}
        bx lr



L(add_shifted_word):




        subs r4, #32
        beq L(already_aligned)




        movs r7, yh
        rors r7, r7, r4
        lsrs yh, yh, r4
        eors r7, r7, yh
        movs r4, #0
        cmp yl, #1
        adcs r7, r7, r4


L(already_aligned):
        adds xl, xl, yh
        adcs xh, xh, r4
        bcc L(already_normalized)
        b L(normalization_required)



L(add_zero):
        cmp r6, #0
        bne L(done)


        ands xh, xh, r5
        movs xl, #0
        b L(done)


L(inf):
        adds r6, r6, #1
        lsls xh, r6, #20
        movs xl, #0
        b L(done)



L(sub_inf_or_nan):
        cmn r7, r4
        bne L(done)


L(nan):
        movs xl, #0
        mvns xh, xl
        lsrs xh, xh, #20
        lsls xh, xh, #19
        b L(done)


L(subtract):


        eors yh, yh, r5


        movs r6, xh
        subs r7, xl, yl
        sbcs r6, r6, yh
        bcs L(sub_already_ordered)


        eors r6, r6, r5
        subs xl, xl, r7
        sbcs xh, xh, r6
        adds yl, yl, r7
        adcs yh, yh, r6


L(sub_already_ordered):
        adds r6, xh, xh
        adds r7, yh, yh



        lsrs r4, r5, #10
        cmn r6, r4
        bcs L(sub_inf_or_nan)


        lsrs r6, r6, #21
        lsrs r7, r7, #21
        beq L(subtracting_zero)


        subs r4, r6, r7
        cmp r4, #54
        bhi L(done)


        mov ip, r6
        lsrs r6, xh, #20


        lsls yh, yh, #11
        orrs yh, yh, r5
        lsrs yh, yh, #11


        lsls xh, xh, #11
        orrs xh, xh, r5
        lsrs xh, xh, #11





        cmp r4, #1
        bhi L(sub_align_far)
        bne L(sub_already_aligned)



        lsls r4, yl, #31
        lsrs yl, yl, #1
        lsls r7, yh, #31
        orrs yl, yl, r7
        lsrs yh, yh, #1



L(sub_already_aligned):
        lsrs r7, r5, #11



        negs r4, r4
        sbcs xl, xl, yl
        sbcs xh, xh, yh




        beq L(high_word_cancelled)



        movs yl, #0
        tst xh, r7
        bne L(sub_normalized)




L(first_normalization_step):
        adds r4, r4, r4
        adcs xl, xl, xl
        adcs xh, xh, xh
        movs r4, #1


        tst xh, r7
        bne L(normalized)


L(normalize):
        adds r4, r4, #1
        adds xl, xl, xl
        adcs xh, xh, xh
L(pre_normalize):
        tst xh, r7
        beq L(normalize)



L(normalized):
        mov yl, ip
        cmp yl, r4
        bls L(signed_zero)


        subs r6, r6, r4


        subs r6, r6, #1
        lsls r6, r6, #20
        adds xh, xh, r6
        b L(done)


L(signed_zero):
        lsrs xh, r6, #11
        lsls xh, xh, #31
        movs xl, #0
        b L(done)


L(subtracting_zero):



        tst r6, r6
        bne L(done)


        movs xl, #0
        movs xh, #0
        b L(done)



L(high_word_cancelled):



        movs yl, xl
        orrs yl, yl, r4
        beq L(done)



        cmp xl, r7
        bcs L(first_normalization_step)



        movs xh, xl
        movs xl, r4
        movs r4, #32
        bne L(pre_normalize)






L(sub_align_far):
        cmp r4, #32
        ble L(aligned_on_top)
# 1255 "./floatasmops_arm.s"
        subs r4, r4, #32




        rors yl, yl, r4
        movs r7, yl
        lsls yl, yl, r4
        lsrs yl, yl, r4
        eors r7, r7, yl
        rors yh, yh, r4
        eors yl, yl, yh
        lsls yh, yh, r4
        lsrs yh, yh, r4
        eors yl, yl, yh
# 1282 "./floatasmops_arm.s"
        cmp r7, #1
        sbcs r7, r7, r7
        adds r7, r7, #1
        orrs r7, r7, yl
        movs yl, #0


        negs r4, r7
        sbcs xl, xl, yh
        sbcs xh, xh, yl
        b L(sub_normalize)


L(aligned_on_top):
# 1312 "./floatasmops_arm.s"
        movs r7, yl
        rors r7, r7, r4
        lsrs yl, yl, r4
        eors r7, r7, yl

        rors yh, yh, r4
        eors yl, yl, yh
        lsls yh, yh, r4
        lsrs yh, yh, r4
        eors yl, yl, yh
# 1332 "./floatasmops_arm.s"
        negs r4, r7
        sbcs xl, xl, yl
        sbcs xh, xh, yh
        movs yl, #0


L(sub_normalize):
        lsls r7, xh, #12
        bcs L(sub_normalized)


        subs r6, r6, #1
        adds r4, r4, r4
        adcs xl, xl, xl
        adcs xh, xh, xh


L(sub_normalized):




        subs r6, r6, #1


        lsls r6, r6, #20


        lsrs r7, xl, #1
        sbcs r4, r4, r5
        adcs xl, xl, yl
        adcs xh, xh, r6


        pop {ADD64_WORKING_SET}
        bx lr

#else






#define ADD64_WORKING_SET r4, r5
#define z0 ip
#define z1 lr


        push {ADD64_WORKING_SET, lr}


        teq xh, yh
        bmi L(subtract)


        subs r4, xl, yl
        sbcs z0, xh, yh
        bcs L(add_already_ordered)


        adds yl, yl, r4
        adcs yh, yh, z0
        subs xl, xl, r4
        sbcs xh, xh, z0


L(add_already_ordered):
        li z0, 0xFFE00000




        tst z0, yh, lsl #1
        beq L(add_zero)



        cmp z0, xh, lsl #1
        bls L(add_inf_nan)



        lsrs r4, xh, #20




        sub z1, r4, yh, lsr #20


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        movs z0, #1
        bfi xh, z0, #20, #12
        bfi yh, z0, #20, #12
#else
        bics xh, xh, z0
        orr xh, xh, #0x00100000
        bics yh, yh, z0
        orr yh, yh, #0x00100000
#endif



        rsbs z0, z1, #32
        bcc L(add_shifted_word)



#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        adds xl, xl, yh, lsl z0
        adc xh, xh, #0
        adds xl, xl, yl, lsr z1
        adc xh, xh, yh, lsr z1
        mov yl, yl, lsl z0
#else
        lsl r5, yh, z0
        adds xl, xl, r5
        adc xh, xh, #0
        lsr r5, yl, z1
        adds xl, xl, r5
        lsr r5, yh, z1
        adcs xh, xh, r5
        lsls yl, yl, z0
#endif



L(align_check):
        lsls r5, xh, #11
        bcc L(round)


        lsrs xh, xh, #1
        movs xl, xl, rrx
        movs yl, yl, rrx
        it cs
        orrcs yl, yl, #1
        adds r4, r4, #1


L(round):
        subs r4, r4, #1
        lsrs z0, xl, #1
        sbcs yl, yl, #0x80000000
        adcs xl, xl, #0
        adcs xh, xh, r4, lsl #20


        mov yh, #0x00200000
        cmn yh, xh, lsl #1
        it cc
        RET2cc cc, ADD64_WORKING_SET


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        bfc xh, #0, #20
#else
        lsrs xh, xh, #20
        lsls xh, xh, #20
#endif
        movs xl, #0
        RET2 ADD64_WORKING_SET




L(add_shifted_word):


        subs z1, z1, #32
        cmp z1, #32
        bcs L(too_many_shifts)


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        adds xl, xl, yh, lsr z1
#else
        lsr r5, yh, z1
        adds xl, xl, r5
#endif
        adc xh, xh, #0



        rsb z0, z1, #32


        tst yl, yl
        it ne
        movne yl, #1
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orr yl, yl, yh, lsl z0
#else
        lsl r5, yh, z0
        orrs yl, yl, r5
#endif
        b L(align_check)


L(sub_zero):
        tst xh, z0, lsr #1
#if __SEGGER_RTL_CORE_HAS_CLRM
        it eq
        clrmeq {xl, xh}
#else
        itt eq
        moveq xl, #0
        moveq xh, #0
#endif
L(zero_add):
        RET2 ADD64_WORKING_SET

L(add_zero):
        tst z0, xh, lsl #1
        itt eq
        andeq xh, xh, #0x80000000
        moveq xl, #0
        RET2 ADD64_WORKING_SET


L(add_zeroes):
        and xh, xh, #0x80000000
        movs xl, #0
        RET2 ADD64_WORKING_SET


L(too_many_shifts):
        bic xh, xh, #0x00100000
        add xh, xh, r4, lsl #20
        RET2 ADD64_WORKING_SET



L(add_inf_nan):
#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        tst xl, xl
        it ne
        orrne xh, xh, #1
#endif
        cmp z0, xh, lsl #1
        it eq
        RET2cc eq, ADD64_WORKING_SET


L(nan_result):
        mov xh, #0x7f000000
        orr xh, xh, #0x00f80000
        movs xl, #0
        RET2 ADD64_WORKING_SET


L(subtract):


        eor yh, yh, #0x80000000


        subs r4, xl, yl
        sbcs z1, xh, yh
        bcs L(sub_already_ordered)


        eor z1, z1, #0x80000000
        subs xl, xl, r4
        sbcs xh, xh, z1
        adds yl, yl, r4
        adcs yh, yh, z1


L(sub_already_ordered):
        li z0, 0xFFE00000


        tst z0, yh, lsl #1
        beq L(sub_zero)



        cmp z0, xh, lsl #1
        bls L(sub_inf_nan)



        lsrs r4, xh, #20




        sub z1, r4, yh, lsr #20


#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL
        lsll xl, xh, #11
#else
        lsls xh, xh, #11
        orr xh, xh, xl, lsr #21
        lsls xl, xl, #11
#endif
        orr xh, xh, #0x80000000
#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL
        lsll yl, yh, #11
#else
        lsls yh, yh, #11
        orr yh, yh, yl, lsr #21
        lsls yl, yl, #11
#endif
        orr yh, yh, #0x80000000



        rsbs z0, z1, #32
        bcc L(sub_shifted_word)



        lsls r5, yl, z0
        lsr yl, yl, z1
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orr yl, yl, yh, lsl z0
#else
        lsl r5, yh, z0
        orr yl, yl, r5
#endif
        it ne
        orrne yl, yl, #1
        lsr yh, yh, z1
        subs xl, xl, yl
        sbcs xh, xh, yh


L(subtract_normalization):
        lsrs yh, r4, #11
#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r4, r4, #0, #11
#else
        lsls r4, r4, #21
        lsrs r4, r4, #21
#endif


        tst xh, #0xC0000000
        bmi L(normalized)
        beq L(general_normalize)


        subs r4, r4, #1
        lsls xl, xl, #1
        adcs xh, xh, xh


L(normalized):
        subs r4, r4, #1
        bmi L(underflow)


        lsls yl, xl, #21


#if __SEGGER_RTL_CORE_HAS_LSLL_LSRL_ASRL
        lsrl xl, xh, #11
#else
        lsrs xl, xl, #11
        orr xl, xl, xh, lsl #21
        lsrs xh, xh, #11
#endif


        orrs xh, xh, yh, lsl #31


        lsrs z0, xl, #1
        sbcs yl, yl, #0x80000000
        adcs xl, xl, #0
        adcs xh, xh, r4, lsl #20


        RET2 ADD64_WORKING_SET

L(normalize_again):
        movs xh, xl
        beq L(sub_zero_result)
        movs xl, #0
        subs r4, r4, #32


L(general_normalize):
        cmp xh, #0
        beq L(normalize_again)

#if __SEGGER_RTL_CORE_HAS_CLZ

        clz z0, xh
        rsbs z1, z0, #32
        lsls xh, xh, z0
        lsrs r5, xl, z1
        lsls xl, xl, z0
        orrs xh, xh, r5
        sub r4, r4, z0

#else


        cmp xh, #0x00010000
        itttt cc
        subcc r4, r4, #16
        movcc xh, xh, lsl #16
        orrcc xh, xh, xl, lsr #16
        movcc xl, xl, lsl #16


        cmp xh, #0x01000000
        itttt cc
        subcc r4, r4, #8
        lslcc xh, xh, #8
        orrcc xh, xh, xl, lsr #24
        lslcc xl, xl, #8


        cmp xh, #0x10000000
        itttt cc
        subcc r4, r4, #4
        lslcc xh, xh, #4
        orrcc xh, xh, xl, lsr #28
        lslcc xl, xl, #4



        tst xh, #0xc0000000
        itttt eq
        subeq r4, r4, #2
        lsleq xh, xh, #2
        orreq xh, xh, xl, lsr #30
        lsleq xl, xl, #2
        tst xh, xh
L(one_bit_normalize):
        itttt pl
        subpl r4, r4, #1
        lslpl xh, xh, #1
        orrpl xh, xh, xl, lsr #31
        lslpl xl, xl, #1

#endif

        b L(normalized)


L(underflow):
        movs xl, #0
        lsls xh, yh, #31
        RET2 ADD64_WORKING_SET

L(sub_shifted_word):

        sub z1, z1, #32
        cmp z1, #32
        bcs L(sub_too_many_shifts)


        rsb z0, z1, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs yl, yl, yh, lsl z0
        mov yh, yh, lsr z1
#else
        lsl r5, yh, z0
        lsrs yh, yh, z1
        orrs yl, yl, r5
#endif
        it ne
        orrne yh, yh, #1


        subs xl, xl, yh
        sbc xh, xh, #0
        b L(subtract_normalization)


L(sub_too_many_shifts):
        bic xh, xh, #0x80000000
        lsrs xl, xl, #11
        orr xl, xl, xh, lsl #21
        lsrs xh, xh, #11


        add xh, xh, r4, lsl #20
L(sub_zero_result):
        RET2 ADD64_WORKING_SET


L(positive_zero_result):
#if __SEGGER_RTL_CORE_HAS_CLRM
        clrm {xl, xh}
#else
        movs xl, #0
        movs xh, #0
#endif
        RET2 ADD64_WORKING_SET



L(sub_inf_nan):
#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        tst xl, xl
        it ne
        orrne xh, xh, #1
#endif
        cmp z0, xh, lsl #1
        bne L(nan_result)
        cmp z0, yh, lsl #1
        beq L(nan_result)
        RET2 ADD64_WORKING_SET

#endif

END_FUNC __aeabi_dadd
# 1866 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_fsub

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vsub.f32 s0, s0, s1
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        movs r2, #1
        lsls r2, r2, #31


        eors r1, r1, r2
        la r3, .L__aeabi_fadd_fast_entry
        bx r3

#else


        eor r1, #0x80000000
        b __aeabi_fadd

#endif

END_FUNC __aeabi_fsub
# 1915 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_dsub

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vsub.f64 d0, d0, d1
        vmov xl, xh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        push {ADD64_WORKING_SET}


        movs r5, #1
        lsls r5, r5, #31


        eors yh, yh, r5
        la r4, .L__aeabi_dadd_fast_entry
        bx r4

#else


        eor yh, yh, #0x80000000
        b __aeabi_dadd

#endif

END_FUNC __aeabi_dsub
# 1966 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_frsub

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vsub.f32 s0, s1, s0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        movs r2, #1
        lsls r2, r2, #31


        eors r0, r0, r2
        la r3, .L__aeabi_fadd_fast_entry
        bx r3

#else


        eor r0, r0, #0x80000000
        b __aeabi_fadd

#endif

END_FUNC __aeabi_frsub
# 2015 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_drsub

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vsub.f64 d0, d1, d0
        vmov xl, xh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        push {ADD64_WORKING_SET}


        movs r5, #1
        lsls r5, r5, #31


        eors xh, xh, r5
        la r4, .L__aeabi_dadd_fast_entry
        bx r4

#else


        eor xh, xh, #0x80000000
        b __aeabi_dadd

#endif

END_FUNC __aeabi_drsub
# 2066 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_fmul

#undef L
#define L(label) .L__aeabi_fmul_ ##label

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vmul.f32 s0, s0, s1
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define MUL_WORKING_SET r4, r5


        push {MUL_WORKING_SET}


        movs r5, r0
        eors r5, r5, r1
        movs r4, #1
        lsls r4, r4, #31
        ands r5, r5, r4



        lsls r2, r0, #1
        lsls r3, r1, #1


        lsrs r2, r2, #24
        beq L(lhs_zero_or_subnormal)


        lsrs r3, r3, #24
        beq L(rhs_zero_or_subnormal)


        cmp r2, #0xFF
        beq L(lhs_inf_or_nan)


        cmp r3, #0xFF
        beq L(rhs_inf_or_nan)


        adds r2, r2, r3
# 2128 "./floatasmops_arm.s"
        lsls r0, r0, #8
        orrs r0, r0, r4
        lsrs r0, r0, #8
        lsls r1, r1, #8
        orrs r1, r1, r4
        lsrs r1, r1, #8


        UXTBs r4, r0
        muls r4, r4, r1


        lsrs r0, r0, #8
        UXTBs r3, r0
        muls r3, r3, r1


        lsrs r0, r0, #8
        muls r0, r0, r1
# 2158 "./floatasmops_arm.s"
        lsrs r1, r4, #8
        adds r3, r3, r1
        lsrs r1, r3, #8


        adds r1, r1, r0




        bmi L(normalized)
        lsls r1, r1, #1
        subs r2, r2, #1


L(normalized):
        lsrs r0, r1, #8


        subs r2, #127
        blt L(zero_or_underflow)


        cmp r2, #254
        bcs L(inf)


        lsls r2, r2, #23



        orrs r4, r4, r3
        lsls r4, r4, #24
        beq L(no_fold)
        movs r4, #1
        orrs r1, r1, r4


L(no_fold):
        UXTBs r1, r1


        cmp r1, #0x80
        adcs r0, r0, r2


        cmp r1, #0x80
        bne L(apply_sign)
        lsrs r0, r0, #1
        lsls r0, r0, #1


L(apply_sign):
        orrs r0, r0, r5


L(done):
        pop {MUL_WORKING_SET}
        bx lr


L(inf):
        movs r0, #0xFF
        lsls r0, r0, #23
        b L(apply_sign)


L(lhs_zero_or_subnormal):


        lsrs r3, r3, #24


        cmp r3, #0xFF
        beq L(nan)


L(signed_zero):
        movs r0, r5
        b L(done)


L(lhs_inf_or_nan):


        lsls r0, r0, #9
        bne L(nan)


        cmp r3, #0xFF
        bne L(inf)


        lsls r1, r1, #9
        bne L(nan)


        b L(inf)



L(rhs_zero_or_subnormal):
        cmp r2, #0xFF
        bne L(signed_zero)




L(nan):
        movs r0, #0x7F
        lsls r0, r0, #4
        adds r0, r0, #0xC
        lsls r0, r0, #20
        b L(done)


L(rhs_inf_or_nan):


        lsls r1, r1, #9
        bne L(nan)



        b L(inf)




L(zero_or_underflow):


        lsls r3, r0, #9



        adds r2, r2, #1
        bne L(signed_zero)




        asrs r3, r3, #9
        adds r3, r3, #2
        bls L(signed_zero)



        lsls r0, r3, #23
        b L(signed_zero)

#else





        mov ip, #0xff


        ands r2, ip, r0, lsr #23
        ittt ne
        andsne r3, ip, r1, lsr #23


        cmpne r2, #0xFF
        cmpne r3, #0xFF


        beq L(inf_nan_zero)


        add r2, r2, r3







        mov ip, #0x80000000
        eors r3, r0, r1
        ands r3, r3, ip


        orr r1, ip, r1, lsl #8
        orr r0, ip, r0, lsl #8




        umull ip, r1, r0, r1




        cmp r1, #0x80000000
        sbc r2, r2, #0x7f
        it cc
        lslcc r1, r1, #1




        orr ip, ip, r1, lsl #25




        cmp r2, #0xfe
        bcs L(overflow_or_underflow)


        orrs r0, r3, r1, lsr #8
        orr ip, ip, r0, lsl #31
        it cs
        subscs r3, ip, #1


        adc r0, r0, r2, lsl #23


        bx lr



L(overflow_or_underflow):



        tst r2, r2
        itt mi
        movmi r0, r3
        bxmi lr


        movs r0, #0xff
        orr r0, r3, r0, lsl #23
        bx lr
# 2411 "./floatasmops_arm.s"
L(inf_nan_zero):


        tst r0, ip, lsl #23
        it eq
        andeq r0, #0x80000000
        tst r1, ip, lsl #23
        it eq
        andeq r1, #0x80000000


        and r3, ip, r1, lsr #23


        cmp r2, #0xff
        it ne
        cmpne r3, #0xff
        beq L(inf_nan)


        eors r0, r0, r1
        and r0, #0x80000000
        bx lr


L(inf_nan):


        cmp r0, #0x0
        ittt ne
        cmpne r0, #0x80000000
        cmpne r1, #0x0
        cmpne r1, #0x80000000



        beq L(nan_result)


        cmp r2, #0xff
        bne L(test_multiplier)



        lsls r2, r0, #9
        bne L(nan_result)


L(test_multiplier):
        cmp r3, #0xff



        bne L(inf_result)



        lsls r2, r1, #9
        bne L(nan_result)


L(inf_result):
#if (__SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32) && __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        eors r0, r0, r1
        movs r1, #0x7f800000
        bfi r0, r1, #0, #31
#else
        eors r0, r0, r1
        lsls r0, r0, #1
        mov r0, #0xff000000
        rrxs r0, r0
#endif
        bx lr


L(nan_result):
        li r0, 0x7fc00000
        bx lr

#endif

END_FUNC __aeabi_fmul
# 2512 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dmul_ ##label

#if __SEGGER_RTL_FP_HW >= 2

ARM_GLOBAL_FUNC __aeabi_dmul

        vmov d0, xl, xh
        vmov d1, yl, yh
        vmul.f64 d0, d0, d1
        vmov xl, xh, d0
        bx lr

END_FUNC __aeabi_dmul

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

ARM_LOCAL_FUNC __aeabi_dmul_aux


L(lhs_nan_or_inf):
        bne L(nan)
        CBNZx xl, L(nan)


        cmn r5, r6
        bhi L(nan)
        bcc L(rhs_could_be_zero)


        CBNZx yl, L(nan)


L(rhs_could_be_zero):


        lsrs r5, r5, #21
        bne L(inf)


L(nan):
        movs xl, #0
        mvns xh, xl
        lsrs xh, xh, #20
        lsls xh, xh, #19


L(done):
        RET4 r4, r5, r6, r7


L(rhs_nan_or_inf):
        bne L(nan)
        tst yl, yl
        bne L(nan)


        lsrs r4, r4, #21
        beq L(nan)


L(inf):
        movs xl, #0
        mvns xh, xl
        lsls xh, xh, #21
        lsrs xh, xh, #1
        b L(apply_sign)


L(signed_zero):
        movs xl, #0
        mov xh, ip
        RET4 r4, r5, r6, r7

ALIAS_LABEL __aeabi_dmul



        push {r4-r7, lr}


        movs r7, #1
        lsls r7, r7, #31


        movs r6, xh
        eors r6, r6, yh
        ands r6, r6, r7
        mov ip, r6


        lsrs r6, r7, #10


        adds r4, xh, xh
        adds r5, yh, yh


        cmn r4, r6
        bcs L(lhs_nan_or_inf)


        cmn r5, r6
        bcs L(rhs_nan_or_inf)


        lsrs r4, r4, #21
        beq L(signed_zero)


        lsrs r5, r5, #21
        beq L(signed_zero)


        adds r4, r4, r5



        lsls xh, xh, #11
        orrs xh, xh, r7
        lsrs r6, xl, #21
        lsls xl, xl, #11
        orrs xh, xh, r6


        lsls yh, yh, #11
        orrs yh, yh, r7
        lsrs yh, yh, #11
# 2716 "./floatasmops_arm.s"
        push {r4}
        mov lr, xh



        UXTHs r5, xl
        UXTHs r7, yl
        muls r7, r7, r5



        lsrs r4, yl, #16
        muls r4, r4, r5







        lsrs r6, r7, #16
        adds r4, r4, r6





        lsrs r6, r4, #16
        lsls r4, r4, #16
        UXTHs r7, r7
        orrs r7, r7, r4






        UXTHs r4, yh
        muls r4, r4, r5
        adds r4, r4, r6



        lsrs xh, yh, #16
        muls xh, xh, r5






        lsrs r5, r4, #16
        UXTHs r4, r4
        adds xh, xh, r5






        lsls r5, xh, #16
        lsrs xh, xh, #16
        adds r4, r4, r5



        lsrs xl, xl, #16
        UXTHs r5, yl
        muls r5, r5, xl
# 2797 "./floatasmops_arm.s"
        lsrs r6, r7, #16
        adds r6, r6, r5
        orrs r7, r7, r6
        UXTHs r7, r7
        lsrs r6, r6, #16
# 2822 "./floatasmops_arm.s"
        lsrs r5, yl, #16
        muls r5, r5, xl







        adds r5, r5, r6
# 2860 "./floatasmops_arm.s"
        UXTHs r6, r4
        lsrs r4, r4, #16
        adds r5, r5, r6
# 2874 "./floatasmops_arm.s"
        lsls r6, r5, #16
        orrs r7, r7, r6
        lsrs r6, r5, #16
# 2887 "./floatasmops_arm.s"
        adds r6, r6, r4



        UXTHs r5, yh
        muls r5, r5, xl
# 2903 "./floatasmops_arm.s"
        adds r5, r5, r6
# 2916 "./floatasmops_arm.s"
        UXTHs r4, r5
        lsrs r6, r5, #16
        adds xh, xh, r6



        lsrs r5, yh, #16
        muls r5, r5, xl
# 2935 "./floatasmops_arm.s"
        adds r5, r5, xh
# 2945 "./floatasmops_arm.s"
        lsls r6, r5, #16
        lsrs xh, r5, #16
        orrs r4, r4, r6


        mov xl, lr



        UXTHs xl, xl
        UXTHs r5, yl
        muls r5, r5, xl
# 2973 "./floatasmops_arm.s"
        lsrs r6, r7, #16
        adds r6, r6, r5
        orrs r7, r7, r6
        UXTHs r7, r7
        lsrs r6, r6, #16
# 2992 "./floatasmops_arm.s"
        lsrs r5, yl, #16
        muls r5, r5, xl
# 3003 "./floatasmops_arm.s"
        adds r5, r5, r6
# 3019 "./floatasmops_arm.s"
        UXTHs r6, r4
        adds r5, r5, r6
        lsrs r4, r4, #16
# 3032 "./floatasmops_arm.s"
        lsls r6, r5, #16
        orrs r7, r7, r6
        lsrs r6, r5, #16
        adds r6, r6, r4



        UXTHs r5, yh
        muls r5, r5, xl
# 3052 "./floatasmops_arm.s"
        adds r5, r5, r6
# 3064 "./floatasmops_arm.s"
        UXTHs r4, r5
        lsrs r6, r5, #16
        adds xh, xh, r6



        lsrs r5, yh, #16
        muls r5, r5, xl
# 3084 "./floatasmops_arm.s"
        adds r5, r5, xh
# 3096 "./floatasmops_arm.s"
        lsls r6, r5, #16
        orrs r4, r4, r6
        lsrs xh, r5, #16


        mov r5, lr



        lsrs r5, r5, #16
        UXTHs xl, yl
        muls xl, xl, r5
# 3123 "./floatasmops_arm.s"
        lsrs r6, r7, #16
        adds xl, xl, r6
        lsls r6, xl, #16
        UXTHs r7, r7
        orrs r6, r6, r7
# 3143 "./floatasmops_arm.s"
        lsrs r7, xl, #16
        UXTHs xl, r4
        adds r7, r7, xl



        lsrs yl, yl, #16
        muls yl, yl, r5
# 3162 "./floatasmops_arm.s"
        adds xl, yl, r7
# 3176 "./floatasmops_arm.s"
        lsrs yl, xl, #16
        UXTHs xl, xl
# 3190 "./floatasmops_arm.s"
        lsrs r4, r4, #16
        adds r4, r4, yl



        UXTHs yl, yh
        muls yl, yl, r5
# 3210 "./floatasmops_arm.s"
        adds yl, yl, r4
# 3223 "./floatasmops_arm.s"
        lsls r4, yl, #16
        orrs xl, xl, r4
        lsrs yl, yl, #16
        adds xh, xh, yl



        lsrs yh, yh, #16
        muls yh, yh, r5
# 3251 "./floatasmops_arm.s"
        adds xh, xh, yh


        pop {r4}


        movs r7, #1
        lsls r5, r7, #20


        tst xh, r5
        bne L(normalized)


        adds r6, r6, r6
        adcs xl, xl, xl
        adcs xh, xh, xh
        subs r4, r4, #1


L(normalized):
        lsls r7, r7, #31
        lsrs r5, r7, #21
        subs r5, r5, #1


        subs r4, r4, r5
        blt L(signed_zero_trampoline)


        lsls r5, r5, #1
        cmp r4, r5
        bge L(inf_trampoline)


        lsls r4, r4, #20



        movs r5, #0
        lsrs yl, xl, #1
        sbcs r6, r6, r7
        adcs xl, xl, r5
        adcs xh, xh, r4


L(apply_sign):
        mov r6, ip
        orrs xh, xh, r6
        RET4 r4, r5, r6, r7

L(signed_zero_trampoline):
        b L(signed_zero)

L(inf_trampoline):
        b L(inf)

END_FUNC __aeabi_dmul_aux

#else

#define MUL64_WORKING_SET r4, r5, r6, r7

ARM_GLOBAL_FUNC __aeabi_dmul


        push {MUL64_WORKING_SET, lr}


        li r6, 0x7ff


        eor ip, xh, yh



        ands lr, r6, xh, lsr #20
        ittt ne
        cmpne lr, r6
        andsne r5, r6, yh, lsr #20
        cmpne r5, r6
        beq L(inf_nan_zero)


        bic xh, xh, r6, lsl #21
        orr xh, xh, #0x100000


        umull r4, r7, xh, yl
        bic yh, yh, r6, lsl #21
        orr yh, yh, #0x100000
        add lr, lr, r5
        umull r6, r5, xl, yh
        and ip, ip, #0x80000000
        adds r6, r6, r4
        adcs r5, r5, r7
        umull r4, r7, xh, yh
        adc yh, r7, #0
        umull xh, r7, xl, yl
        adds r6, r6, r7
        adcs r5, r5, r4
        adcs yh, yh, #0


        tst xh, xh
        it ne
        orrne r6, r6, #1


        li r4, 0x7fe
        cmp yh, #0x200
        bcs L(must_norm)


        sub lr, lr, #0x400
        cmp lr, r4
        bcs L(underflow_or_overflow)


        orr xh, ip, yh, lsl #12
        lsls xl, r5, #12
        orr xh, xh, r5, lsr #20
        orr xl, xl, r6, lsr #20


        lsls yl, r6, #12
        lsrs r5, xl, #1
        sbcs yl, yl, #0x80000000
        adcs xl, xl, #0
        adcs xh, xh, lr, lsl #20
        RET4 MUL64_WORKING_SET


L(must_norm):
#if __SEGGER_RTL_CORE_HAS_ADDW_SUBW
        sub lr, lr, #0x3ff
#else
        sub lr, lr, #0x400
        add lr, lr, #1
#endif
        cmp lr, r4
        bcs L(underflow_or_overflow)


        orr xh, ip, yh, lsl #11
        lsls xl, r5, #11
        orr xh, xh, r5, lsr #21
        orr xl, xl, r6, lsr #21


        lsls yl, r6, #11
        lsrs r5, xl, #1
        sbcs yl, yl, #0x80000000
        adcs xl, xl, #0
        adcs xh, xh, lr, lsl #20
        RET4 MUL64_WORKING_SET



L(underflow_or_overflow):
        tst lr, lr
        bpl L(overflow)


L(underflow):
        and xh, ip, #0x80000000
        movs xl, #0
        RET4 MUL64_WORKING_SET
# 3431 "./floatasmops_arm.s"
L(inf_nan_zero):




        tst r6, xh, lsr #20
        itt eq
        andeq xh, xh, #0x80000000
        moveq xl, #0
#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        tst xl, xl
        it ne
        orrne xh, xh, #1
#endif
        tst r6, yh, lsr #20
        itt eq
        andeq yh, #0x80000000
        moveq yl, #0
#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        tst yl, yl
        it ne
        orrne yh, yh, #1
#endif


        and r4, r6, yh, lsr #20


        cmp r4, r6
        it ne
        cmpne lr, r6
        beq L(inf_nan)


        and xh, ip, #0x80000000
        movs xl, #0
        RET4 MUL64_WORKING_SET



L(inf_nan):
        bic xh, xh, #0x80000000
        bic yh, yh, #0x80000000


        cmp xh, r6, lsl #20
        bhi L(nan_result)
        cmp yh, r6, lsl #20
        bhi L(nan_result)







#if __SEGGER_RTL_CORE_HAS_CBZ_CBNZ
        cbz xh, L(nan_result)
        cbz yh, L(nan_result)
#else
        cmp xh, #0x0
        it ne
        cmpne yh, #0x0
        beq L(nan_result)
#endif


L(overflow):
        and xh, ip, #0x80000000
        orr xh, xh, #0x7f000000
        orr xh, xh, #0x00f00000
        movs xl, #0
        RET4 MUL64_WORKING_SET


L(nan_result):
        li xh, 0x7ff80000
        movs xl, #0
        RET4 MUL64_WORKING_SET

END_FUNC __aeabi_dmul

#endif
# 3533 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fdiv_ ##label

ARM_GLOBAL_FUNC __aeabi_fdiv

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vdiv.f32 s0, s0, s1
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define DIV_WORKING_SET r4, r5


        push {DIV_WORKING_SET}


        movs r5, r0
        eors r5, r5, r1
        movs r4, #1
        lsls r4, r4, #31
        ands r5, r5, r4



        lsls r2, r0, #1
        lsls r3, r1, #1


        lsrs r2, r2, #24
        beq L(lhs_zero_or_subnormal)


        lsrs r3, r3, #24
        beq L(rhs_zero_or_subnormal)


        cmp r2, #0xff
        beq L(lhs_inf_or_nan)


        cmp r3, #0xff
        beq L(rhs_inf_or_nan)


        subs r2, r2, r3


        lsls r0, r0, #8
        orrs r0, r0, r4
        lsls r1, r1, #8
        orrs r1, r1, r4


        lsrs r3, r0, #1
        lsrs r1, r1, #1





        lsrs r0, r4, #22



        subs r3, r3, r1
        bcs L(shift_and_subtract)


        subs r2, r2, #1
        lsls r3, r3, #1


        adds r3, r3, r1


L(shift_and_subtract):
        lsls r3, r3, #1
        cmp r3, r1
        bcc L(cant_subtract)
        subs r3, r3, r1
L(cant_subtract):
        adcs r0, r0, r0
        bcc L(shift_and_subtract)


        adds r2, #127
        ble L(signed_zero)


        cmp r2, #255
        bcs L(inf)




        lsls r2, r2, #23




        subs r1, r1, r3
        cmp r3, r1


        adcs r0, r0, r2
# 3652 "./floatasmops_arm.s"
L(apply_sign):
        orrs r0, r0, r5


L(done):
        pop {DIV_WORKING_SET}
        bx lr


L(inf):
        movs r0, #0xff
        lsls r0, r0, #23
        b L(apply_sign)


L(lhs_zero_or_subnormal):


        lsrs r3, r3, #24


        beq L(nan)



        cmp r3, #0xff
        bne L(signed_zero)



        lsls r1, r1, #9
        beq L(signed_zero)


L(nan):
        movs r0, #0x7f
        lsls r0, r0, #4
        adds r0, r0, #0xc
        lsls r0, r0, #20
        b L(done)


L(lhs_inf_or_nan):



        lsls r0, r0, #9
        bne L(nan)


        cmp r3, #0xff
        bne L(inf)


        b L(nan)


L(rhs_zero_or_subnormal):


        cmp r2, #0xff
        bne L(inf)


        lsls r0, r0, #9
        bne L(nan)


        b L(inf)


L(rhs_inf_or_nan):


        lsls r1, r1, #9
        bne L(nan)


L(signed_zero):
        movs r0, r5
        b L(done)

#else

#if __SEGGER_RTL_OPTIMIZE >= 2 && !__SEGGER_RTL_CORE_HAS_IDIV






#define DIV_WORKING_SET r4, r5

        push {DIV_WORKING_SET}
        mov r3, #0x3fc
        ands r5, r3, r1, lsr #21
        ittt ne
        andsne r4, r3, r0, lsr #21
        cmpne r3, r5
        cmpne r3, r4
        beq L(special)



        la ip, __aeabi_fdiv_reciprocal_table
#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r3, r1, #17, #6
        ldr ip, [ip, r3, lsl #2]
#else
        and r3, r1, #0x7e0000
        ldr ip, [ip, r3, lsr #15]
#endif



        eor r3, r0, r1
        orr r4, r4, r3, lsr #31
        subs r4, r4, r5



        asr r2, ip, #24
        bic ip, ip, #0xff000000


        lsls r3, r1, #15
        lsrs r3, r3, #25
        sbc r3, r3, #63
        mla r2, r3, r2, ip



#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        movw ip, #1
        bfi r1, ip, #23, #9
#else
        bic r1, r1, #0xff000000
        orr r1, r1, #0x00800000
#endif


        mul r3, r1, r2


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        bfi r0, ip, #23, #9
#else
        bic r0, r0, #0xff000000
        orr r0, r0, #0x00800000
#endif




        smull ip, r5, r3, r2


        cmp r0, r1
        itte cc
        subcc r4, r4, #4
        lslcc r0, r0, #3
        lslscs r0, r0, #2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        rsc r2, r5, r2, lsl #11
#else
        lsls r2, r2, #11
        sbc r2, r2, r5
#endif




        smull ip, r5, r2, r0



        asrs r2, r4, #2
        adds r2, r2, #0x7e


        rsb r0, r1, r0, lsl #22
        mul r3, r5, r1


        cmp r2, #0xfe
        bcs L(underflow_or_overflow)


        subs r0, r3, r0
        it mi
        addmi r5, r5, #1
        lsrs r4, r4, #1
        rrxs r0, r5
        adc r0, r0, r2, lsl #23
        pop {DIV_WORKING_SET}
        bx lr


L(underflow_or_overflow):
        lsl r0, r4, #31
        itt ge
        orrge r0, r0, #0x7f000000
        addge r0, r0, #0x00800000
        pop {DIV_WORKING_SET}
        bx lr


L(special):
        pop {DIV_WORKING_SET}
        lsrs r3, r3, #2
        and r2, r3, r0, lsr #23

#else

#define DIV_WORKING_SET r4, r5


        movs r3, #0xff


        ands r2, r3, r0, lsr #23
        ittt ne
        andsne r3, r3, r1, lsr #23


        cmpne r2, #0xff
        cmpne r3, #0xff
        beq L(inf_nan_zero)


        subs r2, r2, r3
        adds r2, r2, #0x7f


        eor ip, r1, r0
        and ip, ip, #0x80000000


        mov r3, #0x80000000
        orr r0, r3, r0, lsl #8
        orr r1, r3, r1, lsl #8






#if 0 && (__SEGGER_RTL_OPTIMIZE >= 0) && __SEGGER_RTL_CORE_HAS_IDIV
# 3908 "./floatasmops_arm.s"
        push {r4, r5, r6}


        lsrs r0, r0, #1


        movs r6, #1
        add r4, r6, r1, lsr #11
        lsrs r3, r1, #22
        li r6, 0xFFC200
        udiv r5, r6, r3
        mul r3, r5, r5
        umull r3, r6, r3, r4
        mvns r6, r6
        add r4, r6, r5, lsl #4
        and r3, r1, #1
        rsbs r6, r3, #0
        and r6, r6, r4, lsr #1
        add r3, r3, r1, lsr #1
        mls r6, r4, r3, r6
        umull r6, r3, r4, r6
        lsls r4, r4, #15
        add r4, r4, r3, lsr #1
        mov r3, r1
        mov r6, r1
        umlal r3, r6, r4, r1


        sub r6, r4, r6
        umull r4, r3, r6, r0
        add r0, r0, r3
        adds r3, r0, #1
        mul r6, r3, r1
        rsbs r6, r6, #0
        cmp r4, r6
        ite cs
        movcs r0, r3
        mlscc r6, r3, r1, r1
        cmp r6, r1
        adcs r0, r0, #0


        itt pl
        lslpl r0, r0, #1
        subpl r2, r2, #1


        subs r2, r2, #1
        orrs r0, ip, r0, lsr #8







        adcs r0, r0, r2, lsl #23
        adds r2, r2, #1


        pop {r4, r5, r6}

#elif (__SEGGER_RTL_OPTIMIZE >= 0) && __SEGGER_RTL_CORE_HAS_IDIV






        push {DIV_WORKING_SET}
        subs r3, r0, r1
        itt cc
        addcc r3, r1, r3, lsl #1
        subcc r2, r2, #1



        lsrs r1, r1, #8


        udiv r5, r3, r1
        mls r3, r5, r1, r3


        lsls r3, r3, #8
        udiv r0, r3, r1
        mls r3, r1, r0, r3
        add r0, r0, r5, lsl #8


        lsls r3, r3, #8
        udiv r5, r3, r1


        add r0, r5, r0, lsl #8


        orrs r0, ip, r0, lsr #1







        adcs r0, r0, r2, lsl #23
        pop {DIV_WORKING_SET}

#else


        mov ip, ip, lsr #23


        lsrs r3, r0, #1
        lsrs r1, r1, #1
        subs r3, r3, r1
        itt cc
        subcc r2, r2, #1
        addcc r3, r1, r3, lsl #1
#if __SEGGER_RTL_OPTIMIZE >= 0
       .rept 23
        rsbs r3, r1, r3, lsl #1
        it cc
        addcc r3, r3, r1
        adc ip, ip, ip
       .endr
#else
        push {r4}
        movs r4, #23
L(divide):
        rsbs r3, r1, r3, lsl #1
        it cc
        addcc r3, r3, r1
        adc ip, ip, ip
        subs r4, r4, #1
        bne L(divide)
        pop {r4}
#endif


        subs r1, r1, r3
        cmp r3, r1
        adcs r0, ip, r2, lsl #23

#endif


        cmp r2, #0
        ble L(underflow)


        cmp r2, #0xff
        it cc
        bxcc lr


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        mov r0, #0x7f800000
        ands r1, ip, #0x80000000
        orrs r0, r0, r1
        bx lr
#else
        mov r0, #0xff000000
        and ip, ip, #0x80000000
        orr r0, ip, r0, lsr #1
        bx lr
#endif


L(underflow):
        and r0, ip, #0x80000000
        bx lr

#endif
# 4095 "./floatasmops_arm.s"
L(inf_nan_zero):


        and r3, r3, r1, lsr #23


        cmp r3, #0xff
        bne L(divisor_finite)


        cmp r2, #0xff
        beq L(nan_result)


        movs ip, r1, lsl #9
        beq L(zero_result)


        mov r0, #0x00c00000
        b L(inf_nan_common)


L(divisor_finite):


        cmp r2, #0xff
        bne L(dividend_finite)


        lsls r3, r0, #1
        cmp r3, 0xff000000
        beq L(inf_result)
        b L(nan_result)


L(dividend_finite):
        orrs r2, r2, r3
        beq L(nan_result)


        cmp r3, #0
        beq L(inf_result)

L(zero_result):
        eors r0, r0, r1
        and r0, #0x80000000
        bx lr


L(nan_result):
        mov r0, #0x00c00000
        b L(inf_nan_common)

L(inf_result):
        eors r0, r0, r1
        and r0, #0x80000000
        orr r0, #0x00800000
L(inf_nan_common):
        orr r0, #0x7f000000
        bx lr

#endif

END_FUNC __aeabi_fdiv
# 4178 "./floatasmops_arm.s"
#undef z0
#undef L
#define L(label) .L__aeabi_ddiv_ ##label

ARM_GLOBAL_FUNC __aeabi_ddiv

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vdiv.f64 d0, d0, d1
        vmov xl, xh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
# 4203 "./floatasmops_arm.s"
#define DIV64_WORKING_SET r4, r5, r6, r7

        push {DIV64_WORKING_SET}


        movs r5, #1
        lsls r5, r5, #31


        movs r4, xh
        eors r4, r4, yh
        ands r4, r4, r5
        mov ip, r4


        lsrs r6, r5, #10


        adds r4, xh, xh
        adds r7, yh, yh


        cmn r4, r6
        bcs L(lhs_inf_or_nan)
        cmn r7, r6
        bcs L(rhs_inf_or_nan)



        lsrs r4, r4, #21
        beq L(lhs_zero_or_subnormal)




        lsrs r7, r7, #21
        beq L(inf)


        subs r4, r4, r7


        lsls xh, xh, #11
        orrs xh, xh, r5
        lsrs r7, xh, #11


        lsls yh, yh, #11
        orrs yh, yh, r5
        lsrs yh, yh, #11



        movs r6, xl
        subs r6, r6, yl
        sbcs r7, r7, yh


        bcs L(shift_and_subtract)


        subs r4, r4, #1
        adds r6, r6, r6
        adcs r7, r7, r7


        adds r6, r6, yl
        adcs r7, r7, yh


L(shift_and_subtract):
        asrs xl, r5, #9
        lsrs xl, xl, #22
        adds r4, r4, xl



        ble L(signed_zero)


        adds xl, xl, xl
        cmp r4, xl
        bhi L(inf)





        lsrs xl, r5, #19
        movs xh, #0


L(divide_one_bit):


        adds r6, r6, r6
        adcs r7, r7, r7


        subs r6, r6, yl
        sbcs r7, r7, yh
        bcc L(cant_subtract)


        adcs xl, xl, xl
        adcs xh, xh, xh


        bcc L(divide_one_bit)
        b L(rounding)


L(cant_subtract):
        adds r6, r6, yl
        adcs r7, r7, yh


        adds xl, xl, xl
        adcs xh, xh, xh


        bcc L(divide_one_bit)


L(rounding):


        lsls r4, r4, #20




        adds r6, r6, r6
        adcs r7, r7, r7
        subs r6, r6, yl
        sbcs r7, r7, yh
        bcc L(insert_exponent)




        orrs r7, r7, r6
        lsls yl, xl, #31
        orrs r7, r7, yl
        movs yl, #0
        cmp r7, #1
        adcs xl, xl, yl




L(insert_exponent):
        adcs xh, xh, r4


L(apply_sign):
        mov yl, ip
        orrs xh, xh, yl


L(done):
        pop {DIV64_WORKING_SET}
        bx lr



L(lhs_inf_or_nan):
        bne L(nan)
        CBNZx xl, L(nan)



        cmn r7, r6
        bcs L(nan)



L(inf):
        movs xl, #0
        mvns xh, xl
        lsrs xh, xh, #21
        lsls xh, xh, #20
        b L(apply_sign)



L(rhs_inf_or_nan):
        CBNZx yl, L(nan)
        cmn r7, r6
        beq L(signed_zero)


L(nan):
        movs xl, #0
        mvns xh, xl
        lsrs xh, xh, #20
        lsls xh, xh, #19
        b L(done)



L(lhs_zero_or_subnormal):
        lsrs r7, r7, #21
        beq L(nan)


L(signed_zero):
        movs xl, #0
        mov xh, ip
        b L(done)

#elif __SEGGER_RTL_OPTIMIZE >= 0




#define DIV64_WORKING_SET r4, r5, r6, r7, r8, r9


        push {DIV64_WORKING_SET, lr}


        eors lr, xh, yh
        and lr, #0x80000000


        li r7, 0xffe00000
        ands r5, r7, xh, asl #1
        ittt ne
        cmpne r5, r7
        andsne r5, r7, yh, lsl #1
        cmpne r5, r7
        beq L(inf_nan_zero)


        lsrs r7, r7, #21


        ands r6, r7, yh, lsr #20
        bic yh, yh, r7, lsl #21
        orr yh, yh, #0x100000


        ands r5, r7, xh, lsr #20
        bic xh, xh, r7, lsl #21
        orr xh, xh, #0x100000


        subs r5, r5, r6
#if __SEGGER_RTL_CORE_HAS_ADDW_SUBW
        add r5, r5, #0x3fd
#else
        add r5, r5, #0x300
        adds r5, r5, #0x0fd
#endif
# 4466 "./floatasmops_arm.s"
#if __SEGGER_RTL_CORE_HAS_IDIV






        lsr ip, yh, #7
        adds ip, ip, #1
        mov r7, #0x80000000
        udiv r7, r7, ip
        lsls r7, r7, #5

#else







        la ip, __aeabi_ddiv_reciprocal_table-0x100
        add r9, ip, #0x180


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        ldrb r9, [r9, yh, lsr #13]
#else
        lsrs r7, yh, #13
        ldrb r9, [r9, r7]
#endif


        mvn r7, #1
        and r7, r7, yh, lsr #12
        ldrh r7, [ip, r7]


        lsrs ip, yh, #5
        ands ip, ip, #0xfe
        rsbs ip, ip, #0xfe
        lsls r7, r7, #7
        mla r7, r9, ip, r7

#endif


        umull r9, ip, yl, r7
        movs r4, #0
        umlal ip, r4, yh, r7
        rsbs r9, r9, #0
        sbc ip, ip, ip, lsl #1


        umull r6, yl, xl, r7
        movs xl, #0
        umlal yl, xl, xh, r7
# 4533 "./floatasmops_arm.s"
        movs r7, #0
        lsls r8, r6, #11
        umlal r8, r7, xl, r9
        lsrs r6, r6, #21
        orr r6, r6, yl, lsl #11
        lsrs yl, yl, #21
        adds r6, r6, r7
        movs r7, #0
        adcs yl, yl, r7
        umlal r6, yl, xl, ip






        lsls yh, r8, #11
        umlal yh, r7, yl, r9
        lsrs r8, r8, #21
        orr r8, r8, r6, lsl #11
        lsrs r6, r6, #21
        adds r8, r8, r7
        movs xh, #0
        adcs r6, r6, xh
        umlal r8, r6, yl, ip
        add xl, yl, xl, lsl #11


        lsls yl, yh, #11
        umlal yl, xh, r6, r9
        lsrs yh, yh, #21
        orr yh, yh, r8, lsl #11
        lsrs r8, r8, #21
        adds yh, yh, xh
        movs r7, #0
        adcs r8, r8, r7
        umlal yh, r8, r6, ip


        lsls xh, yl, #11
        umlal xh, r7, r8, r9
        lsrs yl, yl, #21
        orr yl, yl, yh, lsl #11
        lsrs yh, yh, #21
        adds yl, yl, r7
        movs r7, #0
        adcs yh, yh, r7
        umlal yl, yh, r8, ip
        add r6, r8, r6, lsl #11


        lsls r8, xh, #11
        umlal r8, r7, yh, r9
        lsrs xh, xh, #21
        orr xh, xh, yl, lsl #11
        lsrs yl, yl, #21
        adds xh, xh, r7
        adc yl, yl, #0
        umlal xh, yl, yh, ip


        lsls r7, xl, #1
        adds r9, r9, r8
        adcs ip, ip, xh
        sbcs r4, yl, r4
        adcs xl, yh, r6, lsl #11
        adc yh, r7, r6, lsr #21
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        movs r6, #2
        cmp yh, #0x800000
        adc r6, r6, #0
        adc r5, r5, #0
#else
        movs r6, #0
        cmp yh, #0x800000
        adcs r6, r6, r6
        adds r5, r5, r6
        adds r6, r6, #2
#endif


        rsbs r9, r6, #32
        lsls r4, xl, r9
        lsrs xl, xl, r6
        lsls yl, yh, r9
        orrs xl, xl, yl
        lsrs yh, yh, r6


        lsrs r4, r4, #31
        adds xl, xl, r4
        adc yh, yh, #0


        cmp yh, #0x200000
        itt cs
        lsrcs yh, yh, #1
        addcs r5, r5, #1


        li r7, 0x7fe
        cmp r5, r7
        bcs L(zero_or_inf_result)


        orr xh, lr, r5, lsl #20
        add xh, xh, yh


        RET6 DIV64_WORKING_SET


L(zero_or_inf_result):
        tst r5, r5
        bpl L(inf_result)


L(zero_result):
        mov xh, lr
        b L(zero_low_half_return)


L(inf_nan_zero):
#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        tst xl, xl
        it ne
        orrne xh, xh, #1
        tst yl, yl
        it ne
        orrne yh, yh, #1
#endif


        cmp r7, xh, lsl #1
        ite cs
        cmpcs r7, yh, lsl #1
        bcc L(nan_result)


        cmp r7, xh, lsl #1
        itt eq
        cmpeq r7, yh, lsl #1
        beq L(nan_result)


        tst r7, xh, lsl #1
        itt eq
        tsteq r7, yh, lsl #1
        beq L(nan_result)


        tst r7, xh, lsl #1
        beq L(zero_result)


        tst r7, yh, lsl #1
        beq L(inf_result)


        cmp r7, yh, lsl #1
        beq L(zero_result)


L(inf_result):
        orr xh, lr, #0x7f000000
        orr xh, xh, #0x00f00000
L(zero_low_half_return):
        movs xl, #0
        RET6 DIV64_WORKING_SET


L(nan_result):
        li xh, 0x7ff80000
        b L(zero_low_half_return)

#else

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
  #define DIV64_WORKING_SET r4, r5, r6, lr
  #define z0 ip
#else
  #define DIV64_WORKING_SET r4, r5, r6, r7, lr
  #define z0 r7
#endif


        push {DIV64_WORKING_SET}


        eor lr, xh, yh
        and lr, #0x80000000


        li z0, 0xffe00000
        ands r5, z0, xh, asl #1
        ittt ne
        teqne r5, z0
        andsne r4, z0, yh, lsl #1
        teqne r4, z0
        beq L(inf_nan_zero)


        lsrs r5, r5, #21
        sub z0, r5, r4, lsr #21
        add z0, z0, #0x400


        mov r6, #0x80000000
        orr r4, r6, xh, lsl #11
        orr r4, r4, xl, lsr #21
        lsls xl, xl, #11


        orr yh, r6, yh, lsl #11
        orr yh, yh, yl, lsr #21
        lsls yl, yl, #11
# 4758 "./floatasmops_arm.s"
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcs L(aligned_correctly)



        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh


        subs z0, z0, #1


L(aligned_correctly):
        movs yh, yh, lsr #1
        mov yl, yl, rrx


#if __SEGGER_RTL_CORE_HAS_CLRM
        clrm {xh, r5}
#else
        movs r5, #0
        movs xh, #0
#endif


        orr xl, xl, #1


        mov r6, #7
        b L(step_1x)





L(step_1):
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0a)
L(step_1a):
        adcs xl, xl, xl
        adcs r4, r4, r4
L(step_1x):
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0b)
L(step_1b):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0c)
L(step_1c):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0d)
L(step_1d):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0e)
L(step_1e):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs r6, r6, #1
        beq L(step_1i)
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0f)
L(step_1f):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0g)
L(step_1g):
        adcs xl, xl, xl
        adcs r4, r4, r4
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(step_0h)
L(step_1h):
        adcs xl, xl, xl
        adcs r4, r4, r4
        lsls xh, xh, #8
        add xh, xh, r5, lsr #24
        eors r5, xl, r5, lsl #8
        bic xl, xl, #0xff
        eors r5, r5, xl
        b L(step_1)


L(step_1i):
        subs xl, xl, yl
        sbcs r4, r4, yh
        bcc L(no_rounding)
        b L(with_rounding)


L(step_0):
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1a)
L(step_0a):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1b)
L(step_0b):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1c)
L(step_0c):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1d)
L(step_0d):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1e)
L(step_0e):
        adds xl, xl, xl
        adcs r4, r4, r4
        subs r6, r6, #1
        beq L(step_0i)
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1f)
L(step_0f):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1g)
L(step_0g):
        adds xl, xl, xl
        adcs r4, r4, r4
        adds xl, xl, yl
        adcs r4, r4, yh
        bcs L(step_1h)
L(step_0h):
        adds xl, xl, xl
        adcs r4, r4, r4
        lsls xh, xh, #8
        add xh, xh, r5, lsr #24
        eors r5, xl, r5, lsl #8
        bic xl, xl, #0xff
        eors r5, r5, xl
        b L(step_0)


L(step_0i):
        adds xl, xl, yl
        adcs r4, r4, yh
        bcc L(no_rounding)


L(with_rounding):
        lsrs yl, xl, #5
        it ne
        orrne r4, r4, #1


        lsls xh, xh, #5
        add xh, xh, r5, lsr #27
        and xl, xl, #0x1f
        add xl, xl, r5, lsl #5


        bic xh, xh, #0x00100000


        orr xh, xh, lr


        adds xl, xl, #1
        adc xh, xh, #0


        tst r4, r4
        it eq
        biceq xl, xl, #1


        cmp z0, #0x800
        bge L(inf_result)
        subs z0, z0, #1
        ble L(zero_result)
        add xh, xh, z0, lsl #20
        pop {DIV64_WORKING_SET}
        bx lr


L(no_rounding):
        lsls xh, xh, #5
        add xh, xh, r5, lsr #27
        and xl, xl, #0x1f
        add xl, xl, r5, lsl #5


        bic xh, xh, #0x00100000


        orr xh, xh, lr


        cmp z0, #0x800
        bge L(inf_result)
        subs z0, z0, #1
        ble L(zero_result)
        add xh, xh, z0, lsl #20
        pop {DIV64_WORKING_SET}
        bx lr


L(inf_nan_zero):
        tst xl, xl
        it ne
        orrne xh, xh, #1
        tst yl, yl
        it ne
        orrne yh, yh, #1


        cmp z0, xh, lsl #1
        ite cs
        cmpcs z0, yh, lsl #1
        bcc L(nan_result)


        cmp z0, xh, lsl #1
        itt eq
        cmpeq z0, yh, lsl #1
        beq L(nan_result)


        tst z0, xh, lsl #1
        itt eq
        tsteq z0, yh, lsl #1
        beq L(nan_result)


        tst z0, xh, lsl #1
        beq L(zero_result)


        tst z0, yh, lsl #1
        beq L(inf_result)


        cmp z0, yh, lsl #1
        beq L(zero_result)


L(inf_result):
        orr xh, lr, #0x7f000000
        orr xh, xh, #0x00f00000
L(zero_low_half_return):
        movs xl, #0
        pop {DIV64_WORKING_SET}
        bx lr


L(nan_result):
        mov xh, #0x7f000000
        orr xh, #0x00f80000
        b L(zero_low_half_return)


L(zero_result):
        mov xh, lr
        b L(zero_low_half_return)

#endif

END_FUNC __aeabi_ddiv
# 5066 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmple

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        fmstat
        CSETx r0, ls
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #1
        lsls r2, r2, #24
        lsls r3, r0, #1
        cmn r2, r3
        bhi L(zero)
        lsls r3, r1, #1
        cmn r2, r3
        bhi L(zero)




        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(one)
        bcs L(negative)


        cmp r1, r0
        sbcs r0, r0, r0
        adds r0, r0, #1
        bx lr


L(negative):
        cmp r0, r1
        sbcs r0, r0, r0
        adds r0, r0, #1
        bx lr

L(one):
        movs r0, #1
        bx lr

L(zero):
        movs r0, #0
        bx lr

#else


        lsls r2, r0, #1
        lsls r3, r1, #1
        cmn r2, #0x01000000


        ite ls
        cmnls r3, #0x01000000


        bhi L(zero)




        orrs r2, r0, r1
        lsls r2, r2, #1
        beq L(one)
        bcs L(negative)


        cmp r1, r0
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr


L(negative):
        cmp r0, r1
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr

L(zero):
        movs r0, #0
        bx lr

L(one):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_fcmple
# 5199 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmple

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        fmstat
        CSETx r0, ls
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64LE_WORKING_SET {r4, r5}



        push CMP64LE_WORKING_SET
        movs r5, #1
        lsls r5, #21
        lsls r4, xh, #1
        cmn r5, r4
        bhi L(zero)
        lsls r4, yh, #1
        cmn r5, r4
        bhi L(zero)



        movs r4, xh
        orrs r4, r4, yh
        lsls r4, r4, #1
        orrs r4, r4, xl
        orrs r4, r4, yl
        beq L(one)
        bcs L(negative)


        cmp yl, xl
        sbcs yh, yh, xh
        sbcs r0, r0, r0
        adds r0, r0, #1
        pop CMP64LE_WORKING_SET
        bx lr

L(negative):
        cmp xl, yl
        sbcs xh, xh, yh
        sbcs r0, r0, r0
        adds r0, r0, #1
        pop CMP64LE_WORKING_SET
        bx lr


L(zero):
        movs r0, #0
        pop CMP64LE_WORKING_SET
        bx lr


L(one):
        movs r0, #1
        pop CMP64LE_WORKING_SET
        bx lr

#else



        mov ip, #0x00200000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        bhi L(zero)



        orrs ip, xh, yh
        orrs ip, xl, ip, lsl #1
        orrs ip, ip, yl
        beq L(one)
        bcs L(negative)


        cmp yl, xl
        sbcs yh, yh, xh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr

L(negative):
        cmp xl, yl
        sbcs xh, xh, yh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr


L(zero):
        movs r0, #0
        bx lr


L(one):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_dcmple
# 5339 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmpeq_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmpeq

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        fmstat
        CSETx r0, eq
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16



        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(equal)




        cmp r0, r1
        bne L(notequal)



        lsls r0, r0, #1
        movs r1, #1
        lsls r1, r1, #24
        cmn r0, r1
        bls L(equal)

L(notequal):
        movs r0, #0
        bx lr

L(equal):
        movs r0, #1
        bx lr

#else



        orrs r2, r0, r1
        lsls r2, r2, #1
        beq L(equal)




        cmp r0, r1
        bne L(notequal)



        lsls r0, r0, #1
        cmn r0, #0x01000000
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, ls
        bx lr
#else
        bls L(equal)
#endif

L(notequal):
        movs r0, #0
        bx lr

L(equal):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_fcmpeq
# 5439 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmpeq_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmpeq

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        fmstat
        CSETx r0, eq
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64EQ_WORKING_SET {r4, r5, r6}



        push CMP64EQ_WORKING_SET
        movs r6, #1
        lsls r6, #21
        lsls r4, xh, #1
        lsls r5, yh, #1
        cmn r6, r4
        bhi L(zero)
        cmn r6, r5
        bhi L(zero)



        orrs r5, r5, r4
        orrs r5, r5, xl
        orrs r5, r5, yl
        beq L(one)


L(compare):
        cmp xh, yh
        bne L(zero)
        cmp xl, yl
        bne L(zero)


L(one):
        movs r0, #1
        pop CMP64EQ_WORKING_SET
        bx lr


L(zero):
        movs r0, #0
        pop CMP64EQ_WORKING_SET
        bx lr

#else



        mov ip, #0x00200000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        bhi L(zero)



        orrs ip, xl, xh, lsl #1
        it eq
        orrseq ip, yl, yh, lsl #1
        beq L(one)


L(compare):
        cmp xl, yl
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        it eq
        cmpeq xh, yh
        cset r0, eq
#else
        itte eq
        cmpeq xh, yh
        moveq r0, #1
        movne r0, #0
#endif
        bx lr


L(zero):
        movs r0, #0
        bx lr


L(one):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_dcmpeq
# 5559 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmpge_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmpge

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        fmstat
        CSETx r0, ge
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #1
        lsls r2, r2, #24
        lsls r3, r0, #1
        cmn r2, r3
        bhi L(zero)
        lsls r3, r1, #1
        cmn r2, r3
        bhi L(zero)




        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(one)
        bcs L(negative)


        cmp r0, r1
        sbcs r0, r0, r0
        adds r0, r0, #1
        bx lr


L(negative):
        cmp r1, r0
        sbcs r0, r0, r0
        adds r0, r0, #1
        bx lr

L(one):
        movs r0, #1
        bx lr

L(zero):
        movs r0, #0
        bx lr

#else


        lsls r2, r0, #1
        lsls r3, r1, #1
        cmn r2, #0x01000000


        ite ls
        cmnls r3, #0x01000000


        bhi L(zero)




        orrs r2, r0, r1
        lsls r2, r2, #1
        beq L(one)
        bcs L(negative)


        cmp r0, r1
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr


L(negative):
        cmp r1, r0
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr

L(zero):
        movs r0, #0
        bx lr

L(one):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_fcmpge
# 5692 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmpge_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmpge

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        fmstat
        CSETx r0, ge
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64GE_WORKING_SET {r4, r5}



        push CMP64GE_WORKING_SET
        movs r5, #1
        lsls r5, #21
        lsls r4, xh, #1
        cmn r5, r4
        bhi L(zero)
        lsls r4, yh, #1
        cmn r5, r4
        bhi L(zero)



        movs r4, xh
        orrs r4, r4, yh
        lsls r4, r4, #1
        orrs r4, r4, xl
        orrs r4, r4, yl
        beq L(one)
        bcs L(negative)


        cmp xl, yl
        sbcs xh, xh, yh
        sbcs r0, r0, r0
        adds r0, r0, #1
        pop CMP64GE_WORKING_SET
        bx lr

L(negative):
        cmp yl, xl
        sbcs yh, yh, xh
        sbcs r0, r0, r0
        adds r0, r0, #1
        pop CMP64GE_WORKING_SET
        bx lr


L(zero):
        movs r0, #0
        pop CMP64GE_WORKING_SET
        bx lr


L(one):
        movs r0, #1
        pop CMP64GE_WORKING_SET
        bx lr

#else



        mov ip, #0x00200000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        bhi L(zero)



        orrs ip, xh, yh
        orrs ip, xl, ip, lsl #1
        orrs ip, ip, yl
        beq L(one)
        bcs L(negative)


        cmp xl, yl
        sbcs xh, xh, yh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr

L(negative):
        cmp yl, xl
        sbcs yh, yh, xh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cs
#else
        sbcs r0, r0, r0
        adds r0, r0, #1
#endif
        bx lr


L(zero):
        movs r0, #0
        bx lr


L(one):
        movs r0, #1
        bx lr

#endif

END_FUNC __aeabi_dcmpge
# 5832 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmpgt_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmpgt

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        fmstat
        CSETx r0, gt
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #1
        lsls r2, r2, #24
        lsls r3, r0, #1
        cmn r2, r3
        bhi L(zero)
        lsls r3, r1, #1
        cmn r2, r3
        bhi L(zero)




        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(zero)
        bcs L(negative)


        cmp r1, r0
        sbcs r0, r0, r0
        negs r0, r0
        bx lr


L(negative):
        cmp r0, r1
        sbcs r0, r0, r0
        negs r0, r0
        bx lr

L(zero):
        movs r0, #0
        bx lr

#else


        lsls r2, r0, #1
        lsls r3, r1, #1
        cmn r2, #0x01000000


        ite ls
        cmnls r3, #0x01000000


        bhi L(zero)




        orrs r2, r0, r1
        lsls r2, r2, #1
        beq L(zero)
        bcs L(negative)


        cmp r1, r0
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr


L(negative):
        cmp r0, r1
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr

L(zero):
        movs r0, #0
        bx lr

#endif

END_FUNC __aeabi_fcmpgt
# 5957 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmpgt_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmpgt

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        fmstat
        CSETx r0, gt
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64GT_WORKING_SET {r4, r5}



        push CMP64GT_WORKING_SET
        movs r5, #1
        lsls r5, #21
        lsls r4, xh, #1
        cmn r5, r4
        bhi L(zero)
        lsls r4, yh, #1
        cmn r5, r4
        bhi L(zero)



        movs r4, xh
        orrs r4, r4, yh
        lsls r4, r4, #1
        orrs r4, r4, xl
        orrs r4, r4, yl
        beq L(zero)
        bcs L(negative)


        cmp yl, xl
        sbcs yh, yh, xh
        sbcs r0, r0, r0
        negs r0, r0
        pop CMP64GT_WORKING_SET
        bx lr

L(negative):
        cmp xl, yl
        sbcs xh, xh, yh
        sbcs r0, r0, r0
        negs r0, r0
        pop CMP64GT_WORKING_SET
        bx lr


L(zero):
        movs r0, #0
        pop CMP64GT_WORKING_SET
        bx lr

#else



        mov ip, #0x00200000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        bhi L(zero)



        orrs ip, xh, yh
        orrs ip, xl, ip, lsl #1
        orrs ip, ip, yl
        beq L(zero)
        bcs L(negative)


        cmp yl, xl
        sbcs yh, yh, xh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr

L(negative):
        cmp xl, yl
        sbcs xh, xh, yh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr


L(zero):
        movs r0, #0
        bx lr

#endif

END_FUNC __aeabi_dcmpgt
# 6086 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmplt_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmplt

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        fmstat
        CSETx r0, mi
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #1
        lsls r2, r2, #24
        lsls r3, r0, #1
        cmn r2, r3
        bhi L(zero)
        lsls r3, r1, #1
        cmn r2, r3
        bhi L(zero)




        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(zero)
        bcs L(negative)


        cmp r0, r1
        sbcs r0, r0, r0
        negs r0, r0
        bx lr


L(negative):
        cmp r1, r0
        sbcs r0, r0, r0
        negs r0, r0
        bx lr

L(zero):
        movs r0, #0
        bx lr

#else


        lsls r2, r0, #1
        lsls r3, r1, #1
        cmn r2, #0x01000000


        ite ls
        cmnls r3, #0x01000000


        bhi L(zero)




        orrs r2, r0, r1
        lsls r2, r2, #1
        beq L(zero)
        bcs L(negative)


        cmp r0, r1
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr


L(negative):
        cmp r1, r0
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr

L(zero):
        movs r0, #0
        bx lr

#endif

END_FUNC __aeabi_fcmplt
# 6211 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmplt_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmplt

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        fmstat
        CSETx r0, mi
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64LT_WORKING_SET {r4, r5}



        push CMP64LT_WORKING_SET
        movs r5, #1
        lsls r5, #21
        lsls r4, xh, #1
        cmn r5, r4
        bhi L(zero)
        lsls r4, yh, #1
        cmn r5, r4
        bhi L(zero)



        movs r4, xh
        orrs r4, r4, yh
        lsls r4, r4, #1
        orrs r4, r4, xl
        orrs r4, r4, yl
        beq L(zero)
        bcs L(negative)


        cmp xl, yl
        sbcs xh, xh, yh
        sbcs r0, r0, r0
        negs r0, r0
        pop CMP64LT_WORKING_SET
        bx lr

L(negative):
        cmp yl, xl
        sbcs yh, yh, xh
        sbcs r0, r0, r0
        negs r0, r0
        pop CMP64LT_WORKING_SET
        bx lr


L(zero):
        movs r0, #0
        pop CMP64LT_WORKING_SET
        bx lr

#else



        mov ip, #0x00200000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        bhi L(zero)



        orrs ip, xh, yh
        orrs ip, xl, ip, lsl #1
        orrs ip, ip, yl
        beq L(zero)
        bcs L(negative)


        cmp xl, yl
        sbcs xh, xh, yh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr

L(negative):
        cmp yl, xl
        sbcs yh, yh, xh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cset r0, cc
#else
        sbcs r0, r0, r0
        negs r0, r0
#endif
        bx lr


L(zero):
        movs r0, #0
        bx lr

#endif

END_FUNC __aeabi_dcmplt
# 6340 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_fcmpun_ ##label

ARM_GLOBAL_FUNC __aeabi_fcmpun

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmp.f32 s0, s1
        vmrs APSR_nzcv, fpscr
        CSETx r0, vs
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16







        lsls r2, r0, #1
        lsrs r2, r2, #24
        cmp r2, #0xff
        bne L(lhs_finite)



        lsls r2, r0, #9
        bne L(unordered)


L(lhs_finite):
        lsls r2, r1, #1
        lsrs r2, r2, #24
        cmp r2, #0xff
        bne L(rhs_finite)
        lsls r2, r1, #9
        bne L(unordered)


L(rhs_finite):
        movs r0, #0
        bx lr


L(unordered):
        movs r0, #1
        bx lr

#else






        lsls r0, r0, #1
        cmp r0, 0xff000000



#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        itt ls
        lslls r1, r1, #1
        cmpls r1, 0xff000000
        cset r0, hi
        bx lr
#else
        ittet ls
        lslls r1, r1, #1
        cmpls r1, 0xff000000
        movhi r0, #1
        movls r0, #0
        bx lr
#endif

#endif

END_FUNC __aeabi_fcmpun
# 6440 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_dcmpun_ ##label

ARM_GLOBAL_FUNC __aeabi_dcmpun

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmp.f64 d0, d1
        vmrs APSR_nzcv, fpscr
        CSETx r0, vs
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
# 6463 "./floatasmops_arm.s"
        lsls xl, xh, #1
        mvns xl, xl
        lsrs xl, xl, #21
        bne L(lhs_finite)






        lsls xh, xh, #12
        bne L(unordered)


L(lhs_finite):
        lsls yl, yh, #1
        mvns yl, yl
        lsrs yl, yl, #21
        bne L(rhs_finite)
        lsls yh, yh, #12
        bne L(unordered)


L(rhs_finite):
        movs r0, #0
        bx lr


L(unordered):
        movs r0, #1
        bx lr

#else





#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        cmp xl, #0
        it ne
        orrne xh, xh, #1
#endif
        lsls xh, xh, #1
        cmp xh, #0xffe00000
        bhi L(unordered)


#if __SEGGER_RTL_NAN_FORMAT == __SEGGER_RTL_NAN_FORMAT_IEEE
        cmp yl, #0
        it ne
        orrne yh, yh, #1
#endif
        lsls yh, yh, #1
        cmp yh, #0xffe00000

#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
L(unordered):
        cset r0, hi
        bx lr
#else
        bhi L(unordered)


        movs r0, #0
        bx lr


L(unordered):
        movs r0, #1
        bx lr
#endif

#endif

END_FUNC __aeabi_dcmpun
# 6564 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cfcmpeq_ ##label

ARM_GLOBAL_FUNC __aeabi_cfcmpeq

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmp.f32 s0, s1
        vmrs apsr_nzcv, fpscr
        bx lr

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

        push {r0-r3, lr}
        bl __aeabi_cfcmp_impl
        cmp r0, #0
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
        RET4 r0, r1, r2, r3

#else

        push {r0-r3, lr}
        bl __aeabi_cfcmp_impl
        cmp r0, #0
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
        it mi
        cmnmi r0, #0
        RET4 r0, r1, r2, r3

#endif

#endif

END_FUNC __aeabi_cfcmpeq
# 6631 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cdcmpeq_ ##label

ARM_GLOBAL_FUNC __aeabi_cdcmpeq

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmp.f64 d0, d1
        vmrs apsr_nzcv, fpscr
        bx lr

#else

        push {r0-r3, lr}
        bl __aeabi_cdcmp_impl
        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
#else
        it mi
        cmnmi r0, #0
#endif

        RET4 r0, r1, r2, r3

#endif

END_FUNC __aeabi_cdcmpeq
# 6689 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cfcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_cfcmple

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s0, s1
        vmrs apsr_nzcv, fpscr
        bx lr

#else

        push {r0-r3, lr}
        bl __aeabi_cfcmp_impl
        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
#else
        it mi
        cmnmi r0, #0
#endif

        RET4 r0, r1, r2, r3

#endif

END_FUNC __aeabi_cfcmple
# 6747 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cdcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_cdcmple

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmpe.f64 d0, d1
        vmrs apsr_nzcv, fpscr
        bx lr

#else

        push {r0-r3, lr}
        bl __aeabi_cdcmp_impl
        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
#else
        it mi
        cmnmi r0, #0
#endif

        RET4 r0, r1, r2, r3

#endif

END_FUNC __aeabi_cdcmple
# 6805 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cfrcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_cfrcmple

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vmov s1, r1
        vcmpe.f32 s1, s0
        vmrs apsr_nzcv, fpscr
        bx lr

#else

        push {r0-r3, lr}
        mov lr, r0
        movs r0, r1
        mov r1, lr
        bl __aeabi_cfcmp_impl
        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
#else
        it mi
        cmnmi r0, #0
#endif

        RET4 r0, r1, r2, r3

#endif

END_FUNC __aeabi_cfrcmple
# 6866 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cdrcmple_ ##label

ARM_GLOBAL_FUNC __aeabi_cdrcmple

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        vcmp.f64 d1, d0
        vmrs apsr_nzcv, fpscr
        bx lr

#else

        push {r0-r3, lr}
        mov lr, r0
        movs r0, r2
        mov r2, lr
        mov lr, r1
        movs r1, r3
        mov r3, lr
        bl __aeabi_cdcmp_impl
        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16
        bpl 1f
        movs r1, #0
        cmn r0, r1
1:
#else
        it mi
        cmnmi r0, #0
#endif

        RET4 r0, r1, r2, r3

#endif

END_FUNC __aeabi_cdrcmple
# 6926 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cfcmp_impl_ ##label

ARM_LOCAL_FUNC __aeabi_cfcmp_impl

#if __SEGGER_RTL_FP_HW >= 1

        fmsr s0, r0
        fmsr s1, r1
        fcmps s0, s1
        fmstat
        beq L(zflagset)
        bcs L(cflagset)
        movs r0, #-1
        bx lr
L(cflagset):
        movs r0, #1
        bx lr
L(zflagset):
        movs r0, #0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #1
        lsls r2, r2, #24
        lsls r3, r0, #1
        cmn r2, r3
        bhi L(both_operands_zero)
        lsls r3, r1, #1
        cmn r2, r3
        bhi L(both_operands_zero)





        movs r2, r0
        orrs r2, r2, r1
        lsls r2, r2, #1
        beq L(both_operands_zero)



        bcs L(different_signs)
        subs r0, r0, r1
        beq L(done)
        bcs L(one)
        sbcs r0, r0, r0
        bx lr
L(different_signs):
        subs r0, r1, r0
        beq L(done)
        bcs L(one)
        sbcs r0, r0, r0
        bx lr
L(one): movs r0, #+1
L(done): bx lr


L(both_operands_zero):
        movs r0, #0
        bx lr

#else






        mov r2, #0x1000000
        cmn r2, r0, lsl #1
        it ls
        cmnls r2, r1, lsl #1
        it hi
        bhi L(both_operands_zero)





        orr r2, r0, r1
        lsls r2, r2, #1
        it eq
        beq L(both_operands_zero)



        bcs L(different_signs)
        subs r0, r0, r1
        it eq
        bxeq lr
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        movs r0, #1
        cneg r0, r0, cc
#else
        ite cs
        movcs r0, #+1
        movcc r0, #-1
#endif
        bx lr
L(different_signs):
        subs r0, r1, r0
        it eq
        bxeq lr
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        movs r0, #1
        cneg r0, r0, cc
#else
        ite cs
        movcs r0, #+1
        movcc r0, #-1
#endif
        bx lr


L(both_operands_zero):
        movs r0, #0
        bx lr

#endif
# 7074 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_cdcmp_impl_ ##label

ARM_LOCAL_FUNC __aeabi_cdcmp_impl

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vmov d1, yl, yh
        fcmpd d0, d1
        fmstat
        beq L(zflagset)
        bcs L(cflagset)
        movs r0, #-1
        bx lr
L(cflagset):
        movs r0, #1
        bx lr
L(zflagset):
        movs r0, #0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16

#define CMP64_WORKING_SET {r4, r5, r6}



        push CMP64_WORKING_SET
        movs r6, #1
        lsls r6, #20
        lsls r4, xh, #1
        lsls r5, yh, #1
        cmn r6, r4
        bhi L(inf_nan)
        cmn r6, r5
        bhi L(inf_nan)



        movs r6, r5
        orrs r6, r6, r4
        orrs r6, r6, xl
        orrs r6, r6, yl
        beq L(both_operands_equal)


        cmp xl, yl
        bne L(compare)
        cmp xh, yh
        beq L(both_operands_equal)



L(compare):

        movs r6, xh
        eors r6, yh
        bmi L(not_rhs_sign)


        cmp xh, yh
        bne L(compared)
        cmp xl, yl
L(compared):
        bcc L(not_rhs_sign)


        asrs r0, xh, #31
        movs r6, #1
        orrs r0, r0, r6
        pop CMP64_WORKING_SET
        bx lr


L(not_rhs_sign):
        asrs r0, yh, #31
        mvns r0, r0
        movs r6, #1
        orrs r0, r0, r6
        pop CMP64_WORKING_SET
        bx lr



L(inf_nan):
        movs r6, #1
        CBZx xl, 1f
        orrs xh, xh, r6
1: CBZx yl, 2f
        orrs yh, yh, r6
2:


        lsls r6, r6, #20
        lsls r4, xh, #1
        cmn r6, r4
        bhi L(both_operands_equal)
        lsls r4, yh, #1
        cmn r6, r4
        bls L(compare)


L(both_operands_equal):
        movs r0, #0
        pop CMP64_WORKING_SET
        bx lr

#else



        mov ip, #0x00100000
        cmn ip, xh, lsl #1
        it ls
        cmnls ip, yh, lsl #1
        it hi
        bhi L(inf_nan)



        orrs ip, xl, xh, lsl #1
        it eq
        orrseq ip, yl, yh, lsl #1
        beq L(both_operands_equal)


        cmp xl, yl
        itt eq
        cmpeq xh, yh
        beq L(both_operands_equal)



L(compare):
        cmn xl, #0


        teq xh, yh


        it pl
        cmppl xh, yh


        it eq
        cmpeq xl, yl


        ite cs
        movcs r0, xh, asr #31
        mvncc r0, yh, asr #31
        orr r0, r0, #1
        bx lr



L(inf_nan):
        tst xl, xl
        it ne
        orrne xh, xh, #1
        tst yl, yl
        it ne
        orrne yh, #1


        cmn ip, xh, lsl #1
        itt ls
        cmnls ip, yh, lsl #1
        bls L(compare)


L(both_operands_equal):
        movs r0, #0
        bx lr

#endif

END_FUNC __aeabi_cdcmp_impl
# 7271 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_f2iz_ ##label

ARM_GLOBAL_FUNC __aeabi_f2iz

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        vcvt.s32.f32 s0, s0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r2, r0, #1
        lsrs r1, r2, #24


        subs r1, r1, #0x7f
        bmi L(zero_result)


        movs r3, #1
        lsls r3, r3, #31



        negs r1, r1
        adds r1, r1, #0x1f
        ble L(overflow_result)


        lsls r0, r0, #1
        bcs L(negative)


        lsls r0, r0, #7


        orrs r0, r0, r3


        lsrs r0, r0, r1
        bx lr

L(negative):

        lsls r0, r0, #7


        orrs r0, r0, r3


        lsrs r0, r0, r1


        negs r0, r0
        bx lr


L(zero_result):
        movs r0, #0
        bx lr



L(overflow_result):
        movs r1, #0xff
        lsls r1, r1, #24
        cmp r2, r1
        bls L(not_nan)
        bics r0, r0, r3
L(not_nan):
        ands r0, r0, r3
        bmi L(done)
        mvns r0, r3
L(done):
        bx lr

#else


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r1, r0, #23, #8
#else
        lsls r1, r0, #1
        lsrs r1, r1, #24
#endif



#if __SEGGER_RTL_CORE_HAS_LONG_SHIFT
        rsbs r1, r1, #0x9e
        bls L(overflow_result)
#else
        rsbs r1, r1, #0x7e
        bhs L(zero_result)
        adds r1, r1, #32
        bls L(overflow_result)
#endif


        orrs r0, r0, #0x800000


        lsl r0, r0, #8
#if __SEGGER_RTL_CORE_HAS_LONG_SHIFT
        lsr.w r0, r0, r1
#else
        lsr r0, r0, r1
#endif


#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cneg r0, r0, mi
#else
        it mi
        negmi r0, r0
#endif


        bx lr

#if !__SEGGER_RTL_CORE_HAS_LONG_SHIFT

L(zero_result):
        mov r0, #0
        bx lr
#endif



L(overflow_result):
        lsls r2, r0, #1
        cmp r2, #0xff000000
        it hi
        bichi r0, #0x80000000
        ands r0, r0, #0x80000000
        it pl
        mvnpl r0, #0x80000000
        bx lr
#endif

END_FUNC __aeabi_f2iz
# 7434 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_d2iz_ ##label

ARM_GLOBAL_FUNC __aeabi_d2iz

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vcvt.s32.f64 s0, d0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        mov ip, lr


        adds r2, xh, xh
        bcs L(negative)


        bl .L__aeabi_d2uiz_fast_entry



        bpl L(return)


        asrs r0, r0, #31
        lsrs r0, r0, #1
L(return):
        bx ip



L(negative):
        movs r3, #1
        lsls r3, r3, #21
        cmn r3, r2
        bcs L(nan_inf)
L(inf): bl .L__aeabi_d2uiz_fast_entry




        bpl L(negate)
        movs r0, #1
        lsls r0, r0, #31
L(negate):
        negs r0, r0
        bx ip


L(nan_inf):
        bne L(nan)
        tst xl, xl
        beq L(inf)




L(nan):
        asrs r0, r2, #31
        lsrs r0, r0, #1
        bx lr

#else


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX

        ubfx r3, xh, #20, #11
        li r2, 0x3ff+31
        subs r2, r2, r3
        ble L(overflow_result)
        cmp r2, #32
        bhi L(zero_result)

#else

        lsls r2, xh, #1
        lsrs r2, r2, #21
        subs r2, r2, #0x300
        subs r2, r2, #0x0ff


        bmi L(zero_result)





        rsbs r2, r2, #0x1f
        ble L(overflow_result)

#endif


        lsls r3, xh, #11
        orr xl, r3, xl, lsr #21


        orr xl, xl, #0x80000000


        lsrs xl, xl, r2


#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cmp xh, #0
        cneg r0, xl, mi
#else
        eors xl, xl, xh, asr #31
        subs r0, xl, xh, asr #31
#endif
        bx lr


L(zero_result):
        movs r0, #0
        bx lr



L(overflow_result):
        lsls r3, xh, #1
        tst xl, xl
        it ne
        orrne r3, r3, #1
        cmn r3, #0x00200000
        it hi
        bichi xh, #0x80000000
        ands r0, xh, #0x80000000
        it pl
        mvnpl r0, #0x80000000
        bx lr

#endif

END_FUNC __aeabi_d2iz

#undef L
#define L(label) .L__aeabi_f2lz_ ##label
# 7596 "./floatasmops_arm.s"
ARM_GLOBAL_FUNC __aeabi_f2lz

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r3, r0, #1
        lsrs r2, r3, #24


        subs r2, r2, #0x7f
        bmi L(zero_result)


        cmp r2, #32
        bge L(long_shift)


        movs r3, #1
        lsls r3, r3, #31



        negs r2, r2
        adds r2, r2, #0x1f


        lsls r0, r0, #1
        bcs L(negative_0)


        lsls r0, r0, #7


        orrs r0, r0, r3


        movs zl, r0
        lsrs zl, r2


        movs zh, #0
        bx lr


L(negative_0):
        lsls r0, r0, #7


        orrs r0, r0, r3


        movs zl, r0
        lsrs zl, r2


        negs zl, zl
        movs zh, 1
        negs zh, zh
        bx lr




L(long_shift):
        negs r2, r2
        adds r2, r2, #0x3f
        ble L(overflow_result)


        movs r3, #1
        lsls r3, r3, #31


        lsls zh, r0, #1
        bcs L(negative_1)


        lsls zh, zh, #7


        orrs zh, zh, r3


        movs zl, zh
        rors zl, zl, r2
        lsrs zh, zh, r2
        eors zl, zl, zh


        bx lr


L(negative_1):
        lsls zh, zh, #7


        orrs zh, zh, r3


        movs zl, zh
        rors zl, zl, r2
        lsrs zh, zh, r2
        eors zl, zl, zh


        movs r3, #0
        negs zh, zh
        negs zl, zl
        sbcs zh, zh, r3
        bx lr


L(zero_result):
        movs zl, #0x0
#if __SEGGER_RTL_OPTIMIZE <= -1
        b L(copy_lo_to_hi)
#else
        movs zh, #0x0
        bx lr
#endif



L(overflow_result):
        movs r2, #0xff
        lsls r2, r2, #24
        cmp r3, r2
        bls L(not_nan)
        lsls r0, r0, #1
        lsrs r0, r0, #1
L(not_nan):
        lsrs zh, r0, #31
        movs zl, #0
        lsls zh, zh, #31
        bmi L(done)
        subs zl, zl, #1
L(copy_lo_to_hi):
        lsrs zh, zl, #1
L(done):
        bx lr

#else


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r2, r0, #23, #8
#else
        lsls r2, r0, #1
        lsrs r2, r2, #24
#endif


        rsbs r2, r2, #0x7f+31


        cmp r2, #32
        bcs L(long_shift)


        lsls r0, r0, #1


        lsl r0, r0, #7


        orr r0, r0, #0x80000000


        lsr zl, r0, r2


        eors zh, zh, zh
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cneg zl, zl, cs
        cinv zh, zh, cs
#else
        itt cs
        negcs zl, zl
        mvncs zh, zh
#endif
        bx lr




L(long_shift):
        adds r2, r2, #32
        bls L(overflow_or_zero)


        lsls zh, r0, #1


        lsl zh, zh, #7


        orr zh, zh, #0x80000000


        ror zl, zh, r2
        lsr zh, zh, r2
        eor zl, zl, zh


        it cc
        bxcc lr


        rsbs zl, zl, #0
        sbc zh, zh, zh, lsl #1
        bx lr

L(overflow_or_zero):
        ble L(overflow_result)


#if __SEGGER_RTL_CORE_HAS_CLRM
        clrm {zl, zh}
#else
        movs zl, #0x0
        movs zh, #0x0
#endif
        bx lr



L(overflow_result):
        lsls r3, r0, #1
        cmp r3, #0xff000000
        it hi
        bichi r0, r0, #0x80000000
        ands zh, r0, #0x80000000
        mov zl, #0
        itt pl
        mvnpl zh, #0x80000000
        mvnpl zl, #0
        bx lr

#endif

END_FUNC __aeabi_f2lz
# 7855 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_d2lz_ ##label

ARM_GLOBAL_FUNC __aeabi_d2lz

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r2, xh, #1
        lsrs r2, r2, #21


        movs r3, #1
        lsls r3, r3, #10
        subs r2, r2, r3
        adds r2, r2, #1
        bmi L(zero_result)



        negs r2, r2
        adds r2, r2, 0x3f
        ble L(overflow_result)


        mov ip, xh


        lsls xh, xh, #11
        lsrs r3, xl, #21
        orrs xh, xh, r3
        lsls xl, xl, #11


        movs r3, #1
        lsls r3, r3, #31
        orrs xh, xh, r3


        cmp r2, #32
        bcc L(full_shift)
        movs xl, xh
        movs xh, #0
        subs r2, r2, #32


L(full_shift):
        rors xh, xh, r2
        lsrs xl, xl, r2
        eors xl, xl, xh
        lsls xh, xh, r2
        lsrs xh, xh, r2
        eors xl, xl, xh


        mov r3, ip
        tst r3, r3
        bpl L(positive)


        movs r3, #0
        negs xl, xl
        sbcs r3, r3, xh
        movs xh, r3
L(positive):
        bx lr


L(zero_result):
        movs xl, #0
        movs xh, #0
        bx lr



L(overflow_result):
        CBZx xl, L(no_fold)
        movs r2, #1
        orrs xh, xh, r2
L(no_fold):
        lsls r3, xh, #1
        movs r2, #1
        lsls r2, r2, #21
        cmn r3, r2
        bls L(not_nan)
        lsrs xh, r3, #1
L(not_nan):
        movs xl, #0
        lsrs xh, xh, #31
        lsls xh, xh, #31
        bmi L(done)
        mvns xl, xl
        lsrs xh, xl, #1
L(done):
        bx lr

#else


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r2, xh, #20, #11
#else
        lsls r2, xh, #1
        lsrs r2, r2, #21
#endif



        li r3, 0x3ff+0x1f
        subs r2, r3, r2
        bge L(small_shift)


        adds r2, r2, #32
        ble L(overflow_result)


        asrs r3, xh, #31


        lsls xh, xh, #11
        orr xh, xh, xl, lsr #21
        lsls xl, xl, #11


        orr xh, xh, #0x80000000


        rors xh, xh, r2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        eor xl, xh, xl, lsr r2
#else
        lsrs xl, xl, r2
        eors xl, xl, xh
#endif
        lsls xh, xh, r2
        lsrs xh, xh, r2
        eors xl, xl, xh


        adds r3, r3, #1
#if __SEGGER_RTL_OPTIMIZE < 0
        CBNZx r3, L(done)
#else
        it ne
        bxne lr
#endif


        negs xl, xl
        sbc xh, r3, xh
        bx lr


L(small_shift):
        asrs r3, xh, #31


        lsls xh, xh, #11
        orr xh, xh, xl, lsr #21
        lsls xl, xl, #11


        orr xh, xh, #0x80000000


        cmp r2, #32
        it cs
        movcs r2, #32


        lsrs xl, xh, r2
        movs xh, r3


        it eq
        bxeq lr


        negs xl, xl
        sbcs xh, xh, xh
L(done):
        bx lr



L(overflow_result):
        lsls r3, xh, #1
        tst xl, xl
        it ne
        orrne r3, r3, #1
        cmp r3, #0xffe00000
        it hi
        bichi xh, #0x80000000
        movs xl, #0
        ands xh, xh, #0x80000000
        itt pl
        mvnpl xh, #0x80000000
        mvnpl xl, xl
        bx lr

#endif

END_FUNC __aeabi_d2lz
# 8077 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_f2uiz_ ##label

ARM_GLOBAL_FUNC __aeabi_f2uiz

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        ftouizs s0, s0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r1, r0, #1
        bcs L(zero_result)


        lsrs r1, r1, #24


        subs r1, r1, #0x7f
        bmi L(zero_result)


        negs r1, r1
        adds r1, r1, #0x1f
        bmi L(max_result)


        lsls r0, r0, #8


        movs r2, #1
        lsls r2, r2, #31
        orrs r0, r0, r2


        lsrs r0, r0, r1
        bx lr


L(max_result):
        asrs r0, r1, #31
        bx lr


L(zero_result):
        movs r0, #0
        bx lr

#elif __SEGGER_RTL_CORE_HAS_LONG_SHIFT


        lsrs r1, r0, #23


        rsbs r1, r1, #0x7f+32-1
        blt L(negative_or_overflow)


        lsls r0, r0, #8


        orr r0, r0, #0x80000000


        lsr.w r0, r0, r1



        bx lr


L(negative_or_overflow):
        lsls r0, r0, #1
        eors r0, r0, r0
        it cc
        subcc r0, r0, #1
        bx lr

#else


        lsrs r1, r0, #23


        rsbs r1, r1, #0x7f+32-1
        blt L(negative_or_overflow)


        lsls r0, r0, #8


        orr r0, r0, #0x80000000


        cmp r1, #32
        it cs
        movcs r0, #0


        lsrs r0, r0, r1
        bx lr


L(negative_or_overflow):
        lsls r0, r0, #1
        eors r0, r0, r0
        it cc
        subcc r0, r0, #1
        bx lr

#endif

END_FUNC __aeabi_f2uiz
# 8212 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_d2uiz_ ##label

ARM_GLOBAL_FUNC __aeabi_d2uiz

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        ftouizd s0, d0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r2, xh, #1
        bcs L(zero_result)


LOCAL_ENTRY .L__aeabi_d2uiz_fast_entry
        lsrs r2, r2, #21


        movs r3, #0x03
        lsls r3, r3, #8
        adds r3, r3, #0xFF
        subs r2, r2, r3
        bmi L(zero_result)



        negs r2, r2
        adds r2, #31
        bmi L(overflow_result)


        lsrs xl, xl, #21
        lsls xh, xh, #11
        orrs xl, xl, xh


        movs r3, #1
        lsls r3, r3, #31
        orrs xl, xl, r3


#if __SEGGER_RTL_BYTE_ORDER < 0
        lsrs r0, xl, r2
#else
        movs r0, xl
        lsrs r0, r0, r2
#endif
        bx lr


L(zero_result):
        movs r0, #0
        bx lr


L(overflow_result):
        asrs r0, r2, #31
        bx lr

#else


        lsrs r3, xh, #20
        li r2, 0x3ff+31
        subs r2, r2, r3
        blt L(overflow_result)


        lsls r3, xh, #11
        orr xl, r3, xl, lsr #21


        orr xl, xl, #0x80000000


        cmp r2, #32
        it cs
        movcs r2, #32
        lsrs r0, xl, r2
        bx lr


L(overflow_result):
        lsls xh, xh, #1
        sbcs r0, r0, r0
        bx lr

#endif

END_FUNC __aeabi_d2uiz
# 8325 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_f2ulz_ ##label

ARM_GLOBAL_FUNC __aeabi_f2ulz

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r2, r0, #1
        bcs L(zero_result)


        lsrs r2, r2, #24


        subs r2, r2, #0x7f
        bmi L(zero_result)


        movs r3, #0x80
        lsls r3, r3, #24


        cmp r2, #32
        bge L(long_shift)



        negs r2, r2
        adds r2, r2, #0x1f


        lsls r0, r0, #8


        orrs r0, r0, r3


#if __SEGGER_RTL_BYTE_ORDER < 0
        lsrs zl, r0, r2
#else
        movs zl, r0
        lsrs zl, zl, r2
#endif


        movs zh, #0
        bx lr




L(long_shift):
        negs r2, r2
        adds r2, r2, #0x3f
        blt L(overflow_result)


        lsls zh, r0, #8


        orrs zh, zh, r3


        movs zl, zh
        rors zl, zl, r2
        lsrs zh, zh, r2
        eors zl, zl, zh
        bx lr


L(zero_result):
        movs zl, #0
#if __SEGGER_RTL_OPTIMIZE <= -1
        b L(copy_to_high)
#else
        movs zh, zl
        bx lr
#endif


L(overflow_result):
        asrs zl, r2, #31
L(copy_to_high):
        movs zh, zl
        bx lr

#else


        lsls r2, r0, #1
        bcs L(zero_result)


        lsrs r2, r2, #24


        rsbs r2, r2, #0x7f+0x1f


        cmp r2, #32
        bcs L(long_shift)





        lsls r0, r0, #8


        orr r0, r0, #0x80000000


        lsrs zl, r0, r2


        movs zh, #0
        bx lr



L(long_shift):
        adds r2, r2, #32
        bcc L(overflow_or_zero)


        lsls zh, r0, #8


        orr zh, zh, #0x80000000


        ror zl, zh, r2
        lsrs zh, zh, r2
        eors zl, zl, zh
        bx lr

L(overflow_or_zero):
        ble L(overflow_result)


L(zero_result):
#if __SEGGER_RTL_CORE_HAS_CLRM
        clrm {zl, zh}
#else
        movs zl, #0
        movs zh, #0
#endif
        bx lr


L(overflow_result):
        mvn zl, #0
        mov zh, zl
        bx lr

#endif

END_FUNC __aeabi_f2ulz
# 8502 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_d2ulz_ ##label

ARM_GLOBAL_FUNC __aeabi_d2ulz

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r3, xh, #1
        bcs L(zero_result)


        lsrs r2, r3, #21


        movs r3, #1
        lsls r3, r3, #10
        subs r2, r2, r3
        adds r2, r2, #1
        bmi L(zero_result)



        negs r2, r2
        adds r2, r2, #0x3f
        blt L(overflow_result)


        lsls xh, xh, #11
        lsrs r3, xl, #21
        orrs xh, xh, r3
        lsls xl, xl, #11


        movs r3, #1
        lsls r3, r3, #31
        orrs xh, xh, r3


        cmp r2, #32
        bcc 1f
        movs xl, xh
        movs xh, #0
        subs r2, r2, #32


1: rors xh, xh, r2
        lsrs xl, xl, r2
        eors xl, xl, xh
        lsls xh, xh, r2
        lsrs xh, xh, r2
        eors xl, xl, xh
        bx lr


L(zero_result):
        movs xl, #0
#if __SEGGER_RTL_OPTIMIZE <= -1
        b L(copy_to_high)
#else
        movs xh, #0
        bx lr
#endif


L(overflow_result):
        asrs xl, r2, #31
L(copy_to_high):
        movs xh, xl
        bx lr

#else


        asrs r2, xh, #20


        lsls xh, xh, #11
        orr xh, xh, xl, lsr #21
        lsls xl, xl, #11


        orr xh, xh, #0x80000000



        li r3, 0x3ff+0x1f
        subs r2, r3, r2
        bge L(small_shift)


        adds r2, r2, #32
        bmi L(overflow_result)


        rors xh, xh, r2
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        eors xl, xh, xl, lsr r2
#else
        lsrs xl, xl, r2
        eors xl, xl, xh
#endif
        lsls xh, xh, r2
        lsrs xh, xh, r2
        eors xl, xl, xh
        bx lr


L(small_shift):
        cmp r2, #32
        it cs
        movcs r2, #32
        lsrs xl, xh, r2
        movs xh, #0
        bx lr


L(overflow_result):
        mvn xh, #0
        mov xl, xh
        bx lr

#endif

END_FUNC __aeabi_d2ulz
# 8645 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_i2f_ ##label

ARM_GLOBAL_FUNC __aeabi_i2f

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        fsitos s0, s0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsrs r2, r0, #31
        lsls r2, r2, #8






        adds r2, r2, #31+0x7f-1


        movs r1, r0



        beq L(done)


        bpl L(normalize)


        negs r1, r1


        bmi L(normalized)


L(normalize):
        subs r2, r2, #1
        lsls r1, r1, #1
        bpl L(normalize)


L(normalized):
        lsls r2, r2, #23


        lsrs r0, r1, #8



        lsls r1, r1, #24


        adcs r1, r1, r1
        bcc L(round_down)




        cmp r1, #1


L(round_down):
        adcs r0, r0, r2
L(done):
        bx lr

#elif __SEGGER_RTL_CORE_HAS_CLZ







        ands r1, r0, #0x80000000
#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cneg r0, r0, ne
#else
        it ne
        negne r0, r0
#endif


        clz r2, r0
        lsls r3, r0, r2
        beq L(done)
        rsbs r2, r2, #31+0x7f-1


        orr r1, r1, r2, lsl #23

#if __SEGGER_RTL_OPTIMIZE < 0




        lsls r2, r3, #24
        sbcs r2, r2, #0x80000000
        adc r0, r1, r3, lsr #8
L(done):
        bx lr

#else




        add r0, r1, r3, lsr #8


        lsls r3, r3, #25
        it cc
        bxcc lr
        add r0, r0, #1
        it ne
        bxne lr
        bic r0, r0, #1
L(done):
        bx lr
# 8785 "./floatasmops_arm.s"
#endif

#else






        movs r2, #31+0x7f-1


        cmp r0, #0
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        bxeq lr
#else
        beq L(done)
#endif



        itt mi
        negmi r0, r0
        orrmi r2, #0x100


        NORM32D r0, r0, r2, r3


        lsls r2, r2, #23


        lsls r1, r0, #24
        sbcs r1, r1, #0x80000000
        adc r0, r2, r0, lsr #8
L(done):
        bx lr

#endif

END_FUNC __aeabi_i2f
# 8844 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_i2d_ ##label

ARM_GLOBAL_FUNC __aeabi_i2d

#if __SEGGER_RTL_FP_HW >= 2

        vmov s0, r0
        fsitod d0, s0
        vmov zl, zh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        la r3, __aeabi_ui2d


        tst r0, r0
        bpl L(positive)


        negs r0, r0
        push {lr}
        BLXx __aeabi_ui2d, r3
        pop {r3}


        movs r2, #1
        lsls r2, r2, #31
        orrs zh, zh, r2


L(positive):
        bx r3

#else


        ands r1, r0, #0x80000000
        CBZx r0, L(zero)


#if __SEGGER_RTL_CORE_HAS_CSINC_CSNEG_CSINV
        cneg r0, r0, mi
#else
        it mi
        negmi r0, r0
#endif






        lsrs r2, r1, #20
#if __SEGGER_RTL_CORE_HAS_ADDW_SUBW
        add r2, r2, #0x41d
#else
        add r2, r2, #0x400
        add r2, r2, #0x01d

#endif


        NORM32D r0, r0, r2, r3


        lsrs r3, r0, #11
        lsls zl, r0, #21
        add zh, r3, r2, lsl #20
L(zero):
        bx lr

#endif

END_FUNC __aeabi_i2d
# 8939 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_l2f_ ##label

ARM_GLOBAL_FUNC __aeabi_l2f

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        la r3, __aeabi_ul2f


        tst xh, xh
        bpl L(positive)


        movs r2, #0
        negs xh, xh
        negs xl, xl
        sbcs xh, r2


        push {lr}
        BLXx __aeabi_ul2f, r3
        pop {r3}


        movs r1, #1
        lsls r1, r1, #31
        orrs r0, r0, r1


L(positive):
        bx r3

#else


        lsrs r2, xh, #31
        beq L(positive)


        lsls r2, r2, #8


        rsbs xl, xl, #0
        sbc xh, xh, xh, lsl #1


L(positive):
        CBZx xh, L(high_word_zero)

#if __SEGGER_RTL_CORE_HAS_CLZ


        clz r3, xh
        adds r2, r2, #63+0x7f-1
        subs r2, r2, r3
        lsls xh, xh, r3
        lsls ip, xl, r3
        it ne
        orrne xh, xh, #1
        rsbs r3, r3, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs xh, xh, xl, lsr r3
#else
        lsrs r3, xl, r3
        orrs xh, xh, r3
#endif

#else

        adds r2, r2, #63+0x7f-1



        cmp xh, #0x10000
        itttt cc
        subcc r2, r2, #16
        movcc xh, xh, lsl #16
        orrcc xh, xh, xl, lsr #16
        movcc xl, xl, lsl #16


        cmp xh, #0x01000000
        itttt cc
        subcc r2, r2, #8
        movcc xh, xh, lsl #8
        orrcc xh, xh, xl, lsr #24
        movcc xl, xl, lsl #8


        cmp xh, #0x10000000
        itttt cc
        subcc r2, r2, #4
        movcc xh, xh, lsl #4
        orrcc xh, xh, xl, lsr #28
        movcc xl, xl, lsl #4



        tst xh, #0xc0000000
        itttt eq
        subeq r2, r2, #2
        moveq xh, xh, lsl #2
        orreq xh, xh, xl, lsr #30
        moveq xl, xl, lsl #2
        tst xh, xh
        ittt pl
        movpl xh, xh, lsl #1
        orrpl xh, xh, xl, lsr #31
        subpl r2, r2, #1

        cmp xl, #0
        it ne
        orrne xh, xh, #1
#endif


        lsls r2, r2, #23
        lsls r3, xh, #25
        adc r0, r2, xh, lsr #8
        it cc
        bxcc lr
        it ne
        bxne lr
        bic r0, r0, #1
        bx lr


L(high_word_zero):
        CBZx xl, L(done)
        adds r2, r2, #31+0x7f-1
        NORM32D xl, xl, r2, r3
        lsls r2, r2, #23
        lsls r3, xl, #25
        adc r0, r2, xl, lsr #8
        it cc
        bxcc lr
        it ne
        bxne lr
        bic r0, r0, #1
L(done):
        bx lr

#endif

END_FUNC __aeabi_l2f
# 9104 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_l2d_ ##label

ARM_GLOBAL_FUNC __aeabi_l2d

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        movs r3, xh
        orrs r3, r3, xl
        beq L(done)


        lsrs r2, xh, #31






        lsls r2, r2, #3
        adds r2, r2, #0x04
        lsls r2, r2, #8
        adds r2, r2, #0x3d


        tst xh, xh
        bpl .L__aeabi_l2d_common


        movs r3, #0
        negs xh, xh
        negs xl, xl
        sbcs xh, r3



LOCAL_ENTRY .L__aeabi_l2d_common
        bne L(no_quick_shift)
        movs xh, xl
        movs xl, #0
        subs r2, r2, #32


L(no_quick_shift):
        lsrs r3, xh, #16
        bne L(clockwork_shifts)
        subs r2, r2, #16
        lsls xh, xh, #16
        lsrs r3, xl, #16
        orrs xh, xh, r3
        lsls xl, xl, #16


L(clockwork_shifts):


        tst xh, xh
        bmi L(normalized)


L(normalize):
        subs r2, r2, #1
        adds xl, xl, xl
        adcs xh, xh, xh
        bpl L(normalize)


L(normalized):


        mov ip, xl


        lsrs xl, xl, #11
        lsls r3, xh, #21
        orrs xl, xl, r3
        lsrs xh, xh, #11


        lsls r2, r2, #20


        mov r3, ip


        lsls r3, r3, #21
        adcs r3, r3, r3
        bcc L(no_rounding)
        cmp r3, #1
        movs r3, #0
        adcs xl, xl, r3
L(no_rounding):
        adcs xh, xh, r2


L(done):
        bx lr

#else


        lsrs r2, xh, #31
        beq L(positive)


        lsls r2, r2, #11


        rsbs xl, xl, #0
        sbc xh, xh, xh, lsl #1


L(positive):
        CBZx xh, L(high_word_zero)

#if __SEGGER_RTL_CORE_HAS_ADDW_SUBW
        add r2, r2, #0x43d
#else
        add r2, r2, #0x400
        add r2, r2, #0x03d
#endif

#if __SEGGER_RTL_CORE_HAS_CLZ


        clz r3, xh
        subs r2, r2, r3
        rsb ip, r3, #32

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        lsls xh, xh, r3
        orrs xh, xh, xl, lsr ip
        lsls xl, xl, r3
#else
        lsrs ip, xl, ip
        lsls xl, xl, r3
        lsls xh, xh, r3
        orrs xh, xh, ip
#endif

#else


        cmp xh, #0x10000
        itttt cc
        subcc r2, r2, #16
        lslcc xh, xh, #16
        orrcc xh, xh, xl, lsr #16
        lslcc xl, xl, #16


        cmp xh, #0x01000000
        itttt cc
        subcc r2, r2, #8
        lslcc xh, xh, #8
        orrcc xh, xh, xl, lsr #24
        lslcc xl, xl, #8


        cmp xh, #0x10000000
        itttt cc
        subcc r2, r2, #4
        lslcc xh, xh, #4
        orrcc xh, xh, xl, lsr #28
        lslcc xl, xl, #4



        tst xh, #0xc0000000
        itttt eq
        subeq r2, r2, #2
        moveq xh, xh, lsl #2
        orreq xh, xh, xl, lsr #30
        moveq xl, xl, lsl #2
        tst xh, xh
        itttt pl
        lslpl xh, xh, #1
        orrpl xh, xh, xl, lsr #31
        lslpl xl, xl, #1
        subpl r2, r2, #1

#endif


        lsls r3, xl, #22
        lsr xl, xl, #11
        orr xl, xl, xh, lsl #21
        lsr xh, xh, #11
        add xh, xh, r2, lsl #20
        it cc
        bxcc lr
        adds xl, xl, #1
        adc xh, xh, #0
        tst r3, r3
        it eq
        biceq xl, xl, #1
        bx lr

L(high_word_zero):
        CBZx xl, L(done)


#if __SEGGER_RTL_CORE_HAS_ADDW_SUBW
        add r2, r2, #0x41d
#else
        add r2, r2, #0x400
        add r2, r2, #0x01d
#endif
        NORM32D xl, xl, r2, r3


        lsrs xh, xl, #11
        lsls xl, xl, #21
        add xh, xh, r2, lsl #20
L(done):
        bx lr

#endif

END_FUNC __aeabi_l2d
# 9343 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_ui2f_ ##label

ARM_GLOBAL_FUNC __aeabi_ui2f

#if __SEGGER_RTL_FP_HW >= 1

        vmov s0, r0
        fuitos s0, s0
        vmov r0, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #31+0x7f-1



        movs r1, r0
        beq L(done)


        bmi L(normalized)


L(normalize):
        subs r2, r2, #1
        lsls r1, r1, #1
        bpl L(normalize)


L(normalized):
        lsls r2, r2, #23


        lsrs r0, r1, #8



        lsls r1, r1, #24


        adcs r1, r1, r1
        bcc L(round_down)




        cmp r1, #1


L(round_down):
        adcs r0, r0, r2
L(done):
        bx lr

#else

#if __SEGGER_RTL_CORE_HAS_CLZ







        clz r1, r0
        lsls r3, r0, r1
        beq L(done)
        rsbs r1, r1, #31+0x7f-1

#else


        CBZx r0, L(done)
        movs r1, #31+0x7f-1
        NORM32D r3, r0, r1, unused

#endif


        lsls r1, r1, #23


        add r0, r1, r3, lsr #8


        lsls r3, r3, #25
        it cc
        bxcc lr
        add r0, r0, #1
        it ne
        bxne lr
        bic r0, r0, #1
L(done):
        bx lr

#endif

END_FUNC __aeabi_ui2f
# 9466 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_ui2d_ ##label

ARM_GLOBAL_FUNC __aeabi_ui2d

#if __SEGGER_RTL_FP_HW >= 2

        vmov s0, r0
        fuitod d0, s0
        vmov zl, zh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






#if __SEGGER_RTL_CORE_HAS_MOVW_MOVT
        movw r2, #0x41D
#else
        movs r2, #0x42
        lsls r2, r2, #4
        subs r2, r2, #3
#endif


        movs r1, r0
        beq L(zero)


        bmi L(normalized)


L(normalize):
        subs r2, r2, #1
        adds r0, r0, r0
        bpl L(normalize)


L(normalized):
        lsls r2, r2, #20


        lsrs r3, r0, #11
        lsls zl, r0, #21


        adds zh, r3, r2
L(zero):
        bx lr

#else


        CBZx r0, L(zero)






        li r2, 0x41d




L(normalize):
        NORM32D r0, r0, r2, r1


        lsrs r3, r0, #11
        lsls zl, r0, #21
        add zh, r3, r2, lsl #20
        bx lr


L(zero):
        movs r1, r0
        bx lr
#endif

END_FUNC __aeabi_ui2d
# 9568 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_ul2f_ ##label

ARM_GLOBAL_FUNC __aeabi_ul2f

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16






        movs r2, #63+0x7f-1



        tst xh, xh
        beq L(small_value)


        bmi L(normalized)


L(normalize):
        subs r2, r2, #1
        adds xl, xl, xl
        adcs xh, xh, xh
        bpl L(normalize)


L(normalized):
        lsls r2, r2, #23


        cmp xl, #1
        sbcs xl, xl
        adds xl, xl, #1
        orrs xh, xl


        lsrs xl, xh, #8



        lsls xh, xh, #24


        adcs xh, xh, xh
        bcc L(round_down)




        cmp xh, #1


L(round_down):
        adcs xl, xl, r2
#if __SEGGER_RTL_BYTE_ORDER > 0
        movs r0, xl
#endif
        bx lr


L(small_value):
#if __SEGGER_RTL_BYTE_ORDER > 0
        movs r0, r1
#endif
        la r1, __aeabi_ui2f
        bx r1

#else


        CBZx xh, L(high_word_zero)

#if __SEGGER_RTL_CORE_HAS_CLZ


        clz r3, xh
        rsbs r2, r3, #63+0x7f-1
        lsls xh, xh, r3
        lsls ip, xl, r3
        it ne
        orrne xh, xh, #1
        rsbs r3, r3, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        orrs xh, xh, xl, lsr r3
#else
        lsrs r3, xl, r3
        orrs xh, xh, r3
#endif

#else

        movs r2, #63+0x7f-1



        cmp xh, #0x10000
        itttt cc
        subcc r2, r2, #16
        movcc xh, xh, lsl #16
        orrcc xh, xh, xl, lsr #16
        movcc xl, xl, lsl #16


        cmp xh, #0x01000000
        itttt cc
        subcc r2, r2, #8
        movcc xh, xh, lsl #8
        orrcc xh, xh, xl, lsr #24
        movcc xl, xl, lsl #8


        cmp xh, #0x10000000
        itttt cc
        subcc r2, r2, #4
        movcc xh, xh, lsl #4
        orrcc xh, xh, xl, lsr #28
        movcc xl, xl, lsl #4



        tst xh, #0xc0000000
        itttt eq
        subeq r2, r2, #2
        moveq xh, xh, lsl #2
        orreq xh, xh, xl, lsr #30
        moveq xl, xl, lsl #2
        tst xh, xh
        ittt pl
        movpl xh, xh, lsl #1
        orrpl xh, xh, xl, lsr #31
        subpl r2, r2, #1


        cmp xl, #0
        it ne
        orrne xh, xh, #1
#endif


        lsls r2, r2, #23
        lsls r3, xh, #25
        adc r0, r2, xh, lsr #8
        it cc
        bxcc lr
        it eq
        biceq r0, r0, #1
        bx lr


L(high_word_zero):
        CBZx xl, L(done)

#if __SEGGER_RTL_CORE_HAS_CLZ
        clz r3, xl
        lsls xl, xl, r3
        rsbs r2, r3, #31+0x7f-1
#else
        movs r2, #31+0x7f-1
        NORM32D xl, xl, r2, unused
#endif


        lsls r2, r2, #23
        lsls r3, xl, #25
        adc r0, r2, xl, lsr #8
        it cc
        bxcc lr
        it eq
        biceq r0, r0, #1
L(done):
        bx lr

#endif

END_FUNC __aeabi_ul2f
# 9765 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_ul2d_ ##label

ARM_GLOBAL_FUNC __aeabi_ul2d

#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        movs r3, xh
        orrs r3, r3, xl
        beq L(done)






        movs r2, #0x04
        lsls r2, r2, #8
        adds r2, r2, #0x3d


        tst xh, xh
        la r3, .L__aeabi_l2d_common
        bx r3

L(done):
        bx lr

#else


        CBZx xh, L(high_word_zero)

        li r2, 0x43d

#if __SEGGER_RTL_CORE_HAS_CLZ


        clz r3, xh
        subs r2, r2, r3
        rsb ip, r3, #32
#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM
        lsls xh, xh, r3
        orrs xh, xh, xl, lsr ip
        lsls xl, xl, r3
#else
        lsrs ip, xl, ip
        lsls xl, xl, r3
        lsls xh, xh, r3
        orrs xh, xh, ip
#endif

#else


        cmp xh, #0x10000
        itttt cc
        subcc r2, r2, #16
        lslcc xh, xh, #16
        orrcc xh, xh, xl, lsr #16
        lslcc xl, xl, #16


        cmp xh, #0x01000000
        itttt cc
        subcc r2, r2, #8
        lslcc xh, xh, #8
        orrcc xh, xh, xl, lsr #24
        lslcc xl, xl, #8


        cmp xh, #0x10000000
        itttt cc
        subcc r2, r2, #4
        lslcc xh, xh, #4
        orrcc xh, xh, xl, lsr #28
        lslcc xl, xl, #4



        tst xh, #0xc0000000
        itttt eq
        subeq r2, r2, #2
        moveq xh, xh, lsl #2
        orreq xh, xh, xl, lsr #30
        moveq xl, xl, lsl #2
        tst xh, xh
        itttt pl
        lslpl xh, xh, #1
        orrpl xh, xh, xl, lsr #31
        lslpl xl, xl, #1
        subpl r2, r2, #1

#endif


        lsls r3, xl, #22
        lsr xl, xl, #11
        orr xl, xl, xh, lsl #21
        lsr xh, xh, #11
        add xh, xh, r2, lsl #20
        it cc
        bxcc lr
        adds xl, xl, #1
        adc xh, xh, #0
        tst r3, r3
        it eq
        biceq xl, xl, #1
        bx lr

L(high_word_zero):
        CBZx xl, L(done)


        li r2, 0x41d
        NORM32D xl, xl, r2, r3


        lsrs xh, xl, #11
        lsls xl, xl, #21
        add xh, xh, r2, lsl #20
L(done):
        bx lr

#endif

END_FUNC __aeabi_ul2d
# 9911 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_f2d_ ##label

ARM_GLOBAL_FUNC __aeabi_f2d

#if __SEGGER_RTL_FP_HW >= 2

        vmov s0, r0
        vcvt.f64.f32 d0, s0
        vmov xl, xh, d0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16


        lsls r1, r0, #1
        mov ip, r1


        movs r2, #1
        lsls r2, r2, #24


        cmp r2, r1
        bhi L(subnormal)


        lsrs r1, r1, #4


        movs r3, #0x38
        lsls r3, r3, #24
        adds r1, r1, r3

#if __SEGGER_RTL_BYTE_ORDER < 0


        lsrs r3, r0, #31
        lsls r3, r3, #31
        orrs r1, r1, r3


        lsls r0, r0, #29

#else


        lsrs r3, r0, #31
        lsls r3, r3, #31
        orrs r3, r3, r1


        lsls r1, r0, #29
        movs r0, r3

#endif


        mov r3, ip
        cmn r2, r3
        bcs L(inf_nan)
        bx lr


L(subnormal):
        lsrs zh, r0, #31
        lsls zh, zh, #31


        movs zl, #0
        bx lr


L(inf_nan):
        bne L(nan)
        movs r3, #0x7f-0x47
        lsls r3, r3, #24
        adds zh, zh, r3
        bx lr


L(nan):
        movs r3, #0x7f-0x47
        lsls r3, r3, #24
        adds zh, zh, r3
        movs r2, #1
        lsls r2, r2, #19
        orrs zh, zh, r2
        bx lr

#elif (__SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_ARM)


        lsls r2, r0, #1


        lsl xl, r2, #28


        lsr xh, r2, #3
        rrx xh, xh


        ands r2, xh, #0x0ff00000


        cmpne r2, #0xff00000


        addne xh, xh, #0x38000000
        bxne lr


        cmp r2, #0


        andeq xh, xh, #0x80000000
        moveq xl, #0
        bxeq lr


        lsls r2, xh, #4
        orr xh, xh, #0x70000000


        cmp xl, #0
        cmpeq r2, #0xff000000
        orrne xh, xh, #0x00080000


        bx lr

#else


#if __SEGGER_RTL_CORE_HAS_BFC_BFI_BFX
        ubfx r1, r0, #23, #8
        CBZx r1, L(zero)
#else
        movs ip, #0xff000000
        tst ip, r0, lsl #1
        beq L(zero)
#endif


        lsls r2, r0, #1


        lsl xl, r0, #29



        lsr xh, r2, #3
        rrx xh, xh




        add xh, xh, #0x38000000


        cmp r2, #0xFF000000
        it cc
        bxcc lr


        add xh, xh, #0x7ff00000-0x47f00000
        it ne
        orrne xh, xh, #0x00080000
        bx lr


L(zero):
        ands xh, r0, #0x80000000
        movs xl, #0
        bx lr

#endif

END_FUNC __aeabi_f2d
# 10109 "./floatasmops_arm.s"
#undef L
#define L(label) .L__aeabi_d2f_ ##label

ARM_GLOBAL_FUNC __aeabi_d2f

#if __SEGGER_RTL_FP_HW >= 2

        vmov d0, xl, xh
        vcvt.f32.f64 s0, d0
        vmov xl, s0
        bx lr

#elif __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T16



        adds r3, xh, xh
        movs r2, #1
        lsls r2, r2, #21
        cmn r2, r3
        bcs L(inf_nan)



        lsrs r3, r3, #21


        movs r2, #7
        lsls r2, r2, #7
        subs r3, r3, r2


        bls L(underflow)


        cmp r3, #255
        bcs L(inf)


        lsls r3, r3, #23


        lsrs r2, xh, #31
        lsls r2, r2, #31



        orrs r3, r3, r2


        lsls xh, xh, #12
        lsrs r2, xl, #20
        orrs xh, xh, r2


        lsrs xh, xh, #9


        lsls r2, xl, #3
        adcs r2, r2, r2
        bls L(no_round_tie)
        adds xh, xh, #1



L(no_round_tie):
        adds r0, xh, r3
        bx lr



L(underflow):
        lsrs r0, xh, #31
        lsls r0, r0, #31
        bx lr



L(inf_nan):
        bne L(nan)


        CBNZx xl, L(nan)




L(inf):
        lsrs r0, xh, #31
        lsls r0, r0, #8
        adds r0, #0xff
        lsls r0, r0, #23
        bx lr



L(nan):


        movs r3, #1
        lsls r3, r3, #31


        movs r2, xh


        lsls xh, xh, #3
        lsrs xl, xl, #32-3
        orrs r0, xl, xh


        bics r0, r0, r3
        ands r2, r2, r3
        orrs r0, r0, r2


        lsrs r3, r3, #9
        orrs r0, r0, r3
        bx lr

#else


        and r2, xh, #0x80000000


        subs r3, xh, r2


        sub xh, r3, #+0x3ff00000-0x07f00000


        cmp xh, #0x100000
        blt L(zero)


        cmp xh, #0xff00000
        bcs L(overflow_inf_nan)


        orr r2, r2, xh, lsl #3


        lsls xh, xl, #3
        sbcs xh, xh, #0x80000000
        adc r0, r2, xl, lsr #29
        bx lr


L(zero):
        mov r0, r2
        bx lr


L(overflow_inf_nan):
        cmp xl, #1
        adcs r3, r3, r3


        cmp r3, #0xffe00000
        bhi L(nan)


#if __SEGGER_RTL_TARGET_ISA == __SEGGER_RTL_ISA_T32
        orr r0, r2, #0x7f800000
#else
        orr r0, r2, #0x7f000000
        orr r0, r0, #0x00800000
#endif
        bx lr


L(nan):
        lsls xh, xh, #3
        orr r0, xh, xl, lsr #32-3
        orrs r0, r0, r2
        orr r0, r0, #0x00400000
        orr r0, r0, #0x40000000
        bx lr

#endif

END_FUNC __aeabi_d2f

#endif

#endif

       .end
