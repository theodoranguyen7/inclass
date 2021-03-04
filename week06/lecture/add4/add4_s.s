.global add4_s

add2_s:
    add r0, r0, r1  @ return a + b
    bx lr

@ r0 = a, r1 = b, r2 = c, r3 = d
add4_s:
    sub sp, sp, #8      @ allocate space for two four-byte registers
    str lr, [sp]        @ preserve the value of lr
    
    bl add2_s           @ add2_s(a, b)
    str r0, [sp, #4]    @ preserve sum of a + b
    mov r0, r2          @ set up r0 and r1 to call add2_s(c, d)
    mov r1, r3
    bl add2_s
    ldr r1, [sp, #4]    @ restore sum of a+b into r1
    add r0, r0, r1      @ add sum of a+b to sum of c+d
    
    ldr lr, [sp]        @ restore the value of lr
    add sp, sp, #8
    
    bx lr
