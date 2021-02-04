#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "scan.h"

void scan_table_init(struct scan_table_st *tt) {
    tt->len = 0;
}

struct scan_token_st *scan_table_new_token(struct scan_table_st *tt) {
    struct scan_token_st *tp;

    tp = &tt->table[tt->len];
    tt->len += 1;
    return tp;
}

void scan_token(struct scan_token_st *tp, char *p, char *end) {

    if (*p == '(') {
        
    } else if (*p == ')') {
        
    } else if (*p == '*') {
        
    }

}

void scan_table_scan(struct scan_table_st *tt, char *p) {
    char *end = p + strlen(p);
    do {
        struct scan_token_st *tp = scan_table_new_token(tt);
        scan_token(tp, p, end);
        if (tp->id == TK_EOT) {
            break;
        }
    } while (true);
}

void scan_table_print(struct scan_table_st *tt) {
    
}

int main(int argc, char **argv) {
    struct scan_table_st table;

    if (argc == 1) {
        printf("Usage: lab02 <expression>");
        return -1;
    }

    scan_table_init(&table);
    scan_table_scan(&table, argv[1]);
    scan_table_print(&table);
}
