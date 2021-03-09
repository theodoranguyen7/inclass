@ max3_s.s - find the maximum value of three arguments using max2

.global max3_s

@ r0 is v0, r1 is v1
max2_s:
    cmp r0, r1      @ if v0 > v1, max is already in r0
    bgt max2_end
    mov r0, r1      @ max is v1
max2_end:
    bx lr

/* 
r0 is v0
r1 is v1
r2 is v2
*/
max3_s:
    sub sp, sp, #8          @ prologue
    str lr, [sp]            @ preserve the link register since we use bl

    str r2, [sp, #4]        @ preserve v2 on the stack since it's caller-preserved
    bl max2_s               @ max(v0, v1)

    ldr r1, [sp, #4]        @ restore v2 into r1
    bl max2_s               @ r0 is already max(v0, v1). Ask for max(rv, v2)

    ldr lr, [sp]            @ epilogue
    add sp, sp, #8
    bx lr
