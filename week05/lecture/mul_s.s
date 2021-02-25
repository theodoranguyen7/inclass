.global mul_s

/* Parameters:
    r0 = a0
    r1 = a1
    r2 = a2
*/
mul_s:
    mul r0, r1, r0      @ r0 = a1 * a0
    mul r0, r2, r0      @ r0 = r0 * a2
                        @ now r0 contains a0 * a1 * a2
    bx lr               @ return to caller. pc = lr
