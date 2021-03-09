#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_LEN 32
#define STR_LEN 4096

int max3_c(int a0, int a1, int a2);
int max3_s(int a0, int a1, int a2);

int find_max_c(int *array, int len);
int find_max_s(int *array, int len);

int fib_rec_c(int n);
int fib_rec_s(int n);

// gen_array_str turns an array of integers into a printable string
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

// max3_test calls the C and Asm versions of max3 for the given params
void max3_test(int a0, int a1, int a2) {
    int r;

    r = max3_c(a0, a1, a2);
    printf("max3_c(%d, %d, %d) = %d\n", a0, a1, a2, r);

    r = max3_s(a0, a1, a2);
    printf("max3_s(%d, %d, %d) = %d\n", a0, a1, a2, r);
    
}

// find_max_test calls the C and Asm versions of find_max for the given array
void find_max_test(int array[], int len) {
    int r;
    char arrstr[4096];  // arrstr is a string version of the input array

    gen_array_string(array, len, arrstr);

    r = find_max_c(array, len);
    printf("find_max_c(%s, %d) = %d\n", arrstr, len, r);

    r = find_max_s(array, len);
    printf("find_max_s(%s, %d) = %d\n", arrstr, len, r);
}

// fib_rec_test calls the C and Asm versions of fib_rec to get the Nth element of the sequence
void fib_rec_test(int n) {
    int r;

    r = fib_rec_c(n);
    printf("fib_rec_c(%d) = %d\n", n, r);

    r = fib_rec_s(n);
    printf("fib_rec_s(%d) = %d\n", n, r);
}

// args_get_array turns the command line parameters into an array of integers
void args_get_array(char **argv, int a[], int *n) {
    int i;
    
    *n = atoi(argv[2]); // length
    for (i = 0; i < *n; i++) {
        a[i] = atoi(argv[3 + i]); // array follows length
    }
}

int main(int argc, char **argv) {
    int arr[4096];
    int arr_len;

    if (argc == 1) {
        printf("usage: lab05 <prog> [<arg1> ...]\n");
        exit(-1);
    }

    if (strncmp(argv[1], "max3", CMD_LEN) == 0) {
        // max3 takes the three integers in argv
        max3_test(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    } else if (strncmp(argv[1], "find_max", CMD_LEN) == 0) {
        // find_max takes the length first, then the array
        args_get_array(argv, arr, &arr_len);
        find_max_test(arr, arr_len);
    } else if (strncmp(argv[1], "fib_rec", CMD_LEN) == 0) {
        // fib_rec takes one integer specifying the Nth element of the sequence
        fib_rec_test(atoi(argv[2]));
    }

    return 0;
}
