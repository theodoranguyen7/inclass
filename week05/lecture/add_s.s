.global add_s

/* Parameters in assembly language:
    r0: left-most parameter
    r1: second-from-left parameter
    r2, r3: same 
*/
add_s:
    add r0, r0, r1
    bx lr
