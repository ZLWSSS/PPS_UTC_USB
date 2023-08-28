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
# 1 "./compilerasmops_arm.s"
# 21 "./compilerasmops_arm.s"
#include "asmdefs_arm.ah"

#if !defined(__aarch64__ )

@gnu_syntax
# 34 "./compilerasmops_arm.s"
THUMB_GLOBAL_FUNC __gnu_thumb1_case_shi
        push {r0, r1}
        mov r1, lr
        lsrs r1, r1, #1
        lsls r0, r0, #1
        lsls r1, r1, #1
        ldrsh r1, [r1, r0]
        lsls r1, r1, #1
        add lr, lr, r1
        pop {r0, r1}
        bx lr
END_FUNC __gnu_thumb1_case_shi

THUMB_GLOBAL_FUNC __gnu_thumb1_case_si
        push {r0, r1}
        mov r1, lr
        adds r1, r1, #2
        lsrs r1, r1, #2
        lsls r0, r0, #2
        lsls r1, r1, #2
        ldr r0, [r1, r0]
        adds r0, r0, r1
        mov lr, r0
        pop {r0, r1}
        bx lr
END_FUNC __gnu_thumb1_case_si

THUMB_GLOBAL_FUNC __gnu_thumb1_case_sqi
        mov ip, r1
        mov r1, lr
        lsrs r1, r1, #1
        lsls r1, r1, #1
        ldrsb r1, [r1, r0]
        lsls r1, r1, #1
        add lr, lr, r1
        mov r1, ip
        bx lr
END_FUNC __gnu_thumb1_case_sqi

THUMB_GLOBAL_FUNC __gnu_thumb1_case_uhi
        push {r0, r1}
        mov r1, lr
        lsrs r1, r1, #1
        lsls r0, r0, #1
        lsls r1, r1, #1
        ldrh r1, [r1, r0]
        lsls r1, r1, #1
        add lr, lr, r1
        pop {r0, r1}
        bx lr
END_FUNC __gnu_thumb1_case_uhi

THUMB_GLOBAL_FUNC __gnu_thumb1_case_uqi
        mov ip, r1
        mov r1, lr
        lsrs r1, r1, #1
        lsls r1, r1, #1
        ldrb r1, [r1, r0]
        lsls r1, r1, #1
        add lr, lr, r1
        mov r1, ip
        bx lr
END_FUNC __gnu_thumb1_case_uqi

#endif
