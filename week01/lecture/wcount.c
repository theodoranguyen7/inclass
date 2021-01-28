#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool is_word_char(char ch) {
    return ch != ' ' && ch != '\t' && ch != '\n';
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("usage: wcount <pathname>\n");
        exit(-1);
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        printf("failed to open %s\n", argv[1]);
        exit(-1);
    }

    int count = 0;
    bool in_word = false;
    do {
        char ch;
        if (fread(&ch, sizeof(char), 1, f) != 1) {
            break;
        }
        if (in_word && !is_word_char(ch)) {
            count++;
        }
        in_word = is_word_char(ch);
    } while (true);

    fclose(f);
    printf("%d\n", count);
    
    return 0;
}
