.global main
.global printf

.data

greeting:
    .asciz "Hello ARM\n"

.text

main:
    sub sp, sp, #8          @ prologue
    str lr, [sp]
    
    ldr r0, =greeting       @ load the address of greeting into r0
    bl printf               @ call C library printf function

    ldr lr, [sp]            @ epilogue
    add sp, sp, #8
    bx lr
