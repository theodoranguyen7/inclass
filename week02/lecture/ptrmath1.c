#include <stdio.h>

int main(int argc, char **argv) {
    char *p = "hello world";
    while (*p != '\0') {
        printf("%c\n", *p);
        p++;
    }
}
