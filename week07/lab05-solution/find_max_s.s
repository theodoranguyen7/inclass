@ find_max_s - find the maximum value in an interger array 

.global find_max_s

@ r0 is the int *array
@ r1 is the length of the array
    
find_max_s:
    mov ip, #1          @ loop index
    ldr r2, [r0]        @ set up arr[0] as the candidate max

loop:
    cmp ip, r1          @ if (i < len)
    bge exit
    lsl r3, ip, #2      @ r3 = ip << 2. Calculates offset
    ldr r3, [r0, r3]    @ r3 = *(r0 + r3). Loads array[i]
@    ldr r3, [r0, ip, LSL #2]
    cmp r3, r2          @ if array[i] > max
    ble next
    mov r2, r3          @ new max
next:
    add ip, ip, #1      @ increment loop index
    b loop

exit:
    mov r0, r2          @ set up return value
    bx lr
