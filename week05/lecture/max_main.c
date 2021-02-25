#include <stdio.h>

int max_c(int a0, int a1);
int max_s(int a0, int a1);

int main(int argc, char **argv) {
    int r;

    r = max_c(2, 4);
    printf("max_c(2, 4) = %d\n", r);
    r = max_s(2, 4);
    printf("max_s(2, 4) = %d\n", r);
    
    return 0;
}
