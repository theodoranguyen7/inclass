@ max3_s.s - find the maximum value of three arguments using max2

.global max3_s

max2_s:
    @ TODO calculate the max of two numbers (hint: similar to min_s from lab04)
    bx lr

/* v0 - r0
 * v1 - r1
 * v2 - r2
 */
max3_s:
    @ TODO calculate the max of three numbers using max2_s
    mov r0, #0
    bx lr
