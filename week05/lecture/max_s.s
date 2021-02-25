.global max_s

/* parameters:
    r0 = a0
    r1 = a1
*/
max_s:
    cmp r0, r1
    bgt return
    mov r0, r1
return:
    bx lr
