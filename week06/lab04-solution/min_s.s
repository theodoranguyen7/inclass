/* min_s.s - simple min function */

.global min_s

/* a is r0, b is r1 */
min_s:
    cmp r0, r1      @ r0 - r1, set condition codes for a subsequent conditional branch
    blt less        @ branch if r0 < r1 to less label
    mov r0, r1      @ else r1 is smaller, set it up in r0 and return it
less:
    bx lr
