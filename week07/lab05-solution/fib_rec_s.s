@ fib_rec_s - Calculate the Nth number of the Fibonacci sequence

.global fib_rec_s

fib_rec_s:
    sub sp, sp, #16         @ prologue
    str lr, [sp]

    cmp r0, #0              @ base case N == 0
    beq exit
    cmp r0, #1              @ base case N == 1
    beq exit

    str r0, [sp, #4]        @ preserve N on the stack
    sub r0, r0, #1          @ set up N - 1 as a parameter
    bl fib_rec_s            @ recurse

    str r0, [sp, #8]        @ preserve return value on the stack
    ldr r0, [sp, #4]        @ restore N from the stack
    sub r0, r0, #2          @ set up N - 2 as a parameter
    bl fib_rec_s            @ recurse
    ldr r1, [sp, #8]        @ restore previous return value
    add r0, r1, r0          @ set up return value with sum of both recursions

exit:
    ldr lr, [sp]            @ epilogue
    add sp, sp, #16
    bx lr
