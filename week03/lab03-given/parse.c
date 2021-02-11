/* parse.c - parsing and parse tree construction */

#include "lab03.h"


void parse_table_init(struct parse_table_st *pt) {
    pt->len = 0;
}

// "Allocate" a parse node from the table of parse nodes
struct parse_node_st * parse_node_new(struct parse_table_st *pt) {
    struct parse_node_st *np;

    np = &(pt->table[pt->len]);
    pt->len += 1;

    return np;
}

void parse_error(char *err) {
    printf("parse_error: %s\n", err);
    exit(-1);
}

// These are names of operators for printing
char *parse_oper_strings[] = {"PLUS", "MINUS", "MULT", "DIV"};

// Print the dots which represent tree depth in the output
void parse_tree_print_indent(int level) {
    level *= 2;
    for (int i = 0; i < level; i++) {
        printf(".");
    }
}

// Traverse the tree recursively to print out the structs
void parse_tree_print_expr(struct parse_node_st *np, int level) {
    parse_tree_print_indent(level);
    printf("EXPR ");

    // TODO: add support for oper1
    
    if (np->type == EX_INTVAL) {
        printf("INTVAL %d\n", np->intval.value);
    } else if (np->type == EX_OPER2) {
        printf("OPER2 %s\n", parse_oper_strings[np->oper2.oper]);
        parse_tree_print_expr(np->oper2.left, level+1);
        parse_tree_print_expr(np->oper2.right, level+1);
    }
}

void parse_tree_print(struct parse_node_st *np) {
    parse_tree_print_expr(np, 0);
}

// Parse the "program" part of the EBNF
// A program is composed of an expression followed by EOT
struct parse_node_st * parse_program(struct parse_table_st *pt, 
                                        struct scan_table_st *st) {
    struct parse_node_st *np1;

    np1 = parse_expression(pt, st);

    if (!scan_table_accept(st, TK_EOT)) {
        parse_error("Expecting EOT");        
    }

    return np1;                                       
}

// Build the tree for expressions
// Expressions are defined in the EBNF as an operator followed
// by zero or more operator operand pairs
struct parse_node_st * parse_expression(struct parse_table_st *pt, 
                                        struct scan_table_st *st) {
    struct scan_token_st *tp;
    struct parse_node_st *np1, *np2;

    np1 = parse_operand(pt, st);

    /*
        TODO
        add cases for other OPER2 operators
    */
    while (true) {    
        tp = scan_table_get(st, 0);
        if (tp->id == TK_PLUS) {
            scan_table_accept(st, TK_ANY);
            np2 = parse_node_new(pt);
            np2->type = EX_OPER2;
            np2->oper2.oper = OP_PLUS;
            np2->oper2.left = np1;
            np2->oper2.right = parse_operand(pt, st);
            np1 = np2;
        } else {
            break;
        }
    }

    return np1;
}

// Parse operands, which are defined in the EBNF to be 
// integer literals or unary minus or expressions 
struct parse_node_st * parse_operand(struct parse_table_st *pt,
                                     struct scan_table_st *st) {
    struct scan_token_st *tp;
    struct parse_node_st *np1;

    /*
        TODO 
        add case for unary minus e.g. "-1 + 1"
        add case for operands which are expressions (i.e. begin with '(')
            (hint: recurse to parse_expression)
    */

    if (scan_table_accept(st, TK_INTLIT)) {
        tp = scan_table_get(st, -1);
        np1 = parse_node_new(pt);
        np1->type = EX_INTVAL;
        np1->intval.value = atoi(tp->value);
    } else {
        parse_error("Bad operand");
    }

    return np1;
}
