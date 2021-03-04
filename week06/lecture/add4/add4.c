#include <stdio.h>

int add4_c(int a, int b, int c, int d);
int add4_s(int a, int b, int c, int d);

int main(int argc, char **argv) {
    printf("add4_c: %d\n", add4_c(1, 2, 3, 4));
    printf("add4_s: %d\n", add4_s(1, 2, 3, 4));
    return 0;
}
