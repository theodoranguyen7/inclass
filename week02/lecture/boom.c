#include <stdio.h>

void foo(char *p) {
    *p = 'f';
}

int main(int argc, char **argv) {
    foo(NULL);
}
