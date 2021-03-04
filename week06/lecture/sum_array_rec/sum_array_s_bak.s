.global sum_array_s
.global sum_array_rs

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

sum_array_rec_s:
    sub sp, sp, #8      @ prologue
    str r2, [sp]
    str lr, [sp, #4]
    ldr r2, [r0]        @ r2 is the sum
    cmp r1, #1          @ base case?
    beq done_rec
recurse:
    add r0, r0, #4      @ array += 1 (4 byte integer)
    sub r1, r1, #1      @ len += 1
    bl sum_array_rs     @ recursion
    add r2, r2, r0      @ accumulate return value into the sum
done_rec:
    mov r0, r2          @ set up return value
    ldr r2, [sp]        @ epilogue
    ldr lr, [sp, #4]
    add sp, sp, #8
    bx lr
