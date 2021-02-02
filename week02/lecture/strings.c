#include <stdio.h>

int main(int argc, char **argv) {
    char *p1 = "hello world";
    char p2[] = "hello world";
    char *p3 = "hello world";
    char s[4] = "foo";
    printf("p: %p, p2: %p, p3: %p, &p3: %p\n", p1, p2, p3, &p3);
}
