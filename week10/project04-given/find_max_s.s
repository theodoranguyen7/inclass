@ find_max_s - find the maximum value in an integer array 

.global find_max_s

@ r0 = the array, r1 = array len
    
find_max_s:
    ldr r2, [r0] 	@ r2 is where the max is stored
    mov ip, #0		@ the counter

loop:
    cmp ip, r1		@ when ip is the length of array
    beq done
    ldr r3, [r0]	@ loading r3 with what r0 is pointing to
    cmp r3, r2
    bgt swap
	
next:
    add r0, r0, #4	@ r0 goes to the next 4-byte int in the array
    add ip, ip, #1	@ incrementing loop by index
    b loop

swap:
    mov r2, r3
    b next

done:
    mov r0, r2
    bx lr
