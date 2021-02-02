#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "map.h"

enum {
    ARG_IPATH = 1,
    ARG_OPATH,
    ARG_FIRST_KEY
};

bool is_word_char(char ch) {
    return ch != ' ' && ch != '\t' && ch != '\n';
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("usage: replace template_path map_path key1 value1 [keyN valueN\n]");
        return -1;
    }

    struct map_st map;
    map_init(&map);
    for (int a = ARG_FIRST_KEY; a < argc; a += 2)
        map_add(&map, argv[a], argv[a+1]);

    FILE *inf = fopen(argv[ARG_IPATH], "r");
    if (!inf) {
        printf("failed to open %s\n", argv[ARG_IPATH]);
        return -1;
    }

    FILE *of = fopen(argv[ARG_OPATH], "w");
    if (!of) {
        printf("failed to open %s\n", argv[ARG_OPATH]);
        fclose(inf);
        return -1;
    }
    
    char key_cand[MAP_KEY_LEN];
    char *kcp = key_cand;
    bool in_word = true;
    do {
        if (!fread(kcp, sizeof(char), 1, inf))
            break;
        if (is_word_char(*kcp)) {
            in_word = is_word_char(*kcp);
            kcp++;
        } else if (in_word) {
            char nwc = *kcp; // save off this non-word char
            *kcp = '\0';
            char *val = map_lookup(&map, key_cand);
            if (!val)
                val = key_cand;
            fwrite(val, sizeof(char), strlen(val), of);
            fwrite(&nwc, sizeof(char), 1, of);
            in_word = false;
            kcp = key_cand;
        }
    } while(true);

    fclose(inf);
    fclose(of);

    return 0;
}
