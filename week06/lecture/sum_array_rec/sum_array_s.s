.global sum_array_s
.global sum_array_rec_s

@ r0 = the array, r1 = array len
sum_array_rec_s:
                        @ prologue
    sub sp, sp, #8      @ allocate stack space for 2 regs
    str lr, [sp]        @ preserve lr
    str r2, [sp, #4]    @ preserve r2

    ldr r2, [r0]        @ r2 is the sum. sum = *arr
    cmp r1, #1          @ base case?
    beq done_rec        @ return *arr
    add r0, r0, #4      @ walk arr forward to the next elem
    sub r1, r1, #1      @ subtract from len
    bl sum_array_rec_s  @ recursion step
    add r2, r2, r0      @ accumulate sum
done_rec:
    mov r0, r2          @ set up sum as return value
                        @ epilogue
    ldr r2, [sp, #4]    @ restore r2
    ldr lr, [sp]        @ restore lr
    add sp, sp, #8      @ deallocate space on the stack
    bx lr
    
@ r0 = the array, r1 = array len
sum_array_s:
    mov r2, #0      @ r2 is the sum
    mov ip, #0      @ ip/r12 is the loop index
loop:
    cmp ip, r1      @ done?
    beq done
    ldr r3, [r0]    @ load r3 with the integer r0 points to
    add r2, r2, r3  @ accumulate sum
    add r0, r0, #4  @ walk r0 to the next 4-byte integer in the array
    add ip, ip, #1  @ increment loop index
    b loop
done:
    mov r0, r2      @ set up sum in r0
    bx lr
