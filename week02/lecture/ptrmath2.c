#include <stdio.h>

struct foo_st {
    int i;
    int j;
};

int main(int argc, char **argv) {
    struct foo_st foos[2];
    struct foo_st *pf = foos;

    foos[0].i = 0;
    foos[0].j = 1;
    foos[1].i = 2;
    foos[1].j = 3;

    printf("sizeof(foo_st) = %d", sizeof(struct foo_st));
    
    for (int i = 0; i < 2; i++) {
        printf("i: %d, j: %d\n", pf->i, pf->j);
        pf++;
    }    
}
