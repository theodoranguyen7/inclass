#include <stdbool.h>

#include <stdio.h>

int main(int argc, char *argv[]) {

    // instrinsic scalar types
    int i = 0;
    char c = 'a';
    bool b = false;
    float f = 0.0;

    // structured/composite types
    int iv[3] = {0, 1, 2};
    int *piv = iv;
    int *piv2 = &iv[0];
    //piv == piv2 == iv == &iv[0] // pseudocode, but all are equal
    iv[2] = 3;
    //piv[2] == 3 // pseudocode euqlaity
    //piv2[2] == 3

    struct foo_st {
        int f1;
        int f2;
    };

    /* C style comments */
    struct foo_st foo;foo.f1=1;foo.f2=2;
    
    printf("hello CS 315\n");
}
