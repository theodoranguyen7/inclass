#include <stdint.h>
#include <stdio.h>

int add2_s(int, int);

void emu_run(uint32_t *code, uint32_t r0, uint32_t r1) {
    uint32_t *pc = code;
    uint32_t instr = *pc;  // add r0, r0, r1 => 0xE0800001
    printf("%X\n", instr);

    uint32_t bits_26_27 = (instr >> 26) & 0b11;
    if (bits_26_27 == 0) {
        // it's a data processing instruction
        uint32_t cond = (instr >> 28) & 0b1111;
        uint32_t i_bit = (instr >> 25) & 0b1;
        uint32_t opcode = (instr >> 21) & 0b1111;
        uint32_t s_bit = (instr >> 20) & 0b1;
        uint32_t rn = (instr >> 16) & 0b1111;
        uint32_t rd = (instr >> 12) & 0b1111;
        uint32_t rm = instr & 0b1111;
        
        printf("cond: %d\n", cond);
        printf("I bit: %d\n", i_bit);
        printf("opcode: %d\n", opcode);
        printf("S bit: %d\n", s_bit);
        printf("rn: %d\n", rn);
        printf("rd: %d\n", rd);
        printf("rm: %d\n", rm);
    }
}

int main(int argc, char **argv) {
    printf("Asm: %d\n", add2_s(1, 2));
    emu_run((uint32_t*) add2_s, 1, 2);
    return 0;
}
