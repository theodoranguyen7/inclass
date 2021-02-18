#include "project02.h"

int main(int argc, char **argv) {
    struct scan_table_st scan_table;
    struct parse_table_st parse_table;
    struct parse_node_st *parse_tree;

    char input[SCAN_INPUT_LEN];
    int len;
    int result;
    bool verbose = false;

    /*
        TODO: 
        parse command line arguments to get -b <base> -w <width> and -u
        optional: make up a config struct?
    */
    if ((argc != 3) || (strncmp(argv[1], "-e", SCAN_TOKEN_LEN) != 0)) {
        printf("usage: project02 -e \"expr\"\n");
        printf("  example: project02 -e \"1 + 2\"\n");
        exit(-1);
    }

    strncpy(input, argv[2], SCAN_INPUT_LEN);
    len = strnlen(input, SCAN_INPUT_LEN);

    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input, len);
    if (verbose) {
        scan_table_print(&scan_table);
    }

    parse_table_init(&parse_table);
    parse_tree = parse_expression(&parse_table, &scan_table);
    if (verbose) {
        parse_tree_print(parse_tree);
    }

    result = eval_tree(parse_tree);
    eval_print(result);

    return 0;
}
