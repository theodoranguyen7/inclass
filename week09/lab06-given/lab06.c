#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "armemu.h"

#define CMD_LEN 32
#define STR_LEN 4096

int max3_c(int a0, int a1, int a2);
int max3_s(int a0, int a1, int a2);

int find_max_c(int *array, int len);
int find_max_s(int *array, int len);

int fib_rec_c(int n);
int fib_rec_s(int n);

// gen_array_string makes a string representation of the integer array
void gen_array_string(int array[], int len, char *outstr) {
    int i;
    char numstr[STR_LEN];

    *outstr = '\0';
    strncat(outstr, "[", STR_LEN);

    for (i = 0; i < len; i += 1) {
        snprintf(numstr, STR_LEN, "%d", array[i]);
        strncat(outstr, numstr, STR_LEN);
        if ((i + 1) != len) {
            strncat(outstr, ",", STR_LEN);
        }
    }
    strncat(outstr, "]",STR_LEN);
}

// max3_test calls the C, assembly, and emulated versions of max3
void max3_test(int a0, int a1, int a2) {
    int r;
    struct arm_state state;

    r = max3_c(a0, a1, a2);
    printf("max3_c(%d, %d, %d) = %d\n", a0, a1, a2, r);

    r = max3_s(a0, a1, a2);
    printf("max3_s(%d, %d, %d) = %d\n", a0, a1, a2, r);

    armemu_init(&state, (uint32_t *) max3_s, a0, a1, a2, 0);
    r = armemu(&state);
    printf("max3_e(%d, %d, %d) = %d\n", a0, a1, a2, r);
}

// find_max_test calls the C, assembly, and emulated versions of find_max
void find_max_test(int array[], int len) {
    int r;
    char arrstr[4096];
    struct arm_state state;

    gen_array_string(array, len, arrstr);

    r = find_max_c(array, len);
    printf("find_max_c(%s, %d) = %d\n", arrstr, len, r);

    r = find_max_s(array, len);
    printf("find_max_s(%s, %d) = %d\n", arrstr, len, r);

    armemu_init(&state, (uint32_t *) find_max_s, 
                (uint32_t) array, (uint32_t) len, 0, 0);
    r = armemu(&state);
    printf("find_max_e(%s, %d) = %d\n", arrstr, len, r);
}

// fib_rec_test calls the C, assembly, and emulated versions of fib_rec
void fib_rec_test(int n) {
    int r;
    struct arm_state state;

    r = fib_rec_c(n);
    printf("fib_rec_c(%d) = %d\n", n, r);

    r = fib_rec_s(n);
    printf("fib_rec_s(%d) = %d\n", n, r);

    armemu_init(&state, (uint32_t *) fib_rec_s, n, 0, 0, 0);
    r = armemu(&state);
    printf("fib_rec_e(%d) = %d\n", n, r);
}

// args_get_array converts a sequence of numbers from their string 
// representation to an array of integers
void args_get_array(char **argv, int a[], int *n) {
    int i;
    
    *n = atoi(argv[2]);
    for (i = 0; i < *n; i++) {
        a[i] = atoi(argv[3 + i]);
    }
}

int main(int argc, char **argv) {
    int n;
    int a[4096];

    if (argc == 1) {
        printf("usage: lab06 <prog> [<arg1> ...]\n");
        exit(-1);
    }

    if (strncmp(argv[1], "max3", CMD_LEN) == 0) {
        max3_test(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    } else if (strncmp(argv[1], "find_max", CMD_LEN) == 0) {
        args_get_array(argv, a, &n);
        find_max_test(a, n);
    } else if (strncmp(argv[1], "fib_rec", CMD_LEN) == 0) {
        fib_rec_test(atoi(argv[2]));
    }

    return 0;
}
