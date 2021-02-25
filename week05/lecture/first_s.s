.global main

main:
    mov r0, #1      @ x = 1
    mov r1, #2      @ y = 2
    add r0, r0, r1  @ r = x + y
                    @ r0 is the conventional place to put the return value
    bx lr           @ pc = lr
