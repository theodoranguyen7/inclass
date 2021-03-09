@ fib_rec_s - calculate the Nth element of the Fibonacci sequence

.global fib_rec2_s

@ r0 is N
fib_rec2_s:
    sub sp, sp, #16         @ prologue
    str lr, [sp]            @ preserve link register since we're using bl
    str r4, [sp, #4]        @ preserve r4
    str r5, [sp, #8]        @ preserve r5

    cmp r0, #0              @ base case n == 0
    beq exit
    cmp r0, #1              @ base case n == 1
    beq exit

    mov r4, r0              @ preserve N in r4
    sub r0, r0, #1          @ set up N-1 to pass as a parameter
    bl fib_rec2_s           @ recursion

    mov r5, r0              @ preserve return value in r5
    mov r0, r4              @ restore N into r0
    sub r0, r0, #2          @ set up N-2 to pass as a parameter
    bl fib_rec2_s           @ recurse
    mov r1, r5              @ restore the first return value to r1
    add r0, r1, r0          @ accumulate the sum of both return values

exit:
    ldr r5, [sp, #8]        @ epilogue
    ldr r4, [sp, #4]
    ldr lr, [sp]
    add sp, sp, #16
    bx lr
