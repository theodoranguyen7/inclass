/* parse.c - parsing and parse tree construction */

#include "project02.h"

struct parse_node_st * parse_operand(struct parse_table_st *pt,
                                    struct scan_table_st *st);
struct parse_node_st * parse_expression(struct parse_table_st *pt,
                                        struct scan_table_st *st);

void parse_table_init(struct parse_table_st *pt) {
    pt->len = 0;
    pt->next = 0;
}

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

struct parse_node_st * parse_operand(struct parse_table_st *pt,
                                    struct scan_table_st *st) {
    struct scan_token_st *tp;
    struct parse_node_st *np, *np1;

    if (scan_table_accept(st, TK_LPAREN)) {
        np = parse_expression(pt, st);
        if (!scan_table_accept(st, TK_RPAREN)) {
            parse_error("Missing right paren");
        }
    } else if (scan_table_accept(st, TK_INTLIT)) {
        tp = scan_table_get(st, -1);
        np = parse_node_new(pt);
        np->type = INTVAL;
        np->intval.value = atoi(tp->value);
    } else if (scan_table_accept(st, TK_MINUS)) {
        tp = scan_table_get(st, -1);
        np1 = parse_node_new(pt);
        np1->type = OPER1;
        if (tp->value[0] != '-') {
            parse_error("unary operator must be -");
        }
        np1->oper1.oper = MINUS;
        np1->oper1.expr = parse_operand(pt, st);
        np = np1;
    } else {
       parse_error("Bad expression");
    }
    return np;
}

enum parse_oper_enum parse_get_oper(enum scan_token_enum id) {
    enum parse_oper_enum rv;
    switch (id) {
        case TK_PLUS:
            rv = PLUS; break;
        case TK_MINUS:
            rv = MINUS; break;
        case TK_MULT:
            rv = MULT; break;
        case TK_DIV:
            rv = DIV; break;
        default:
            parse_error("Invalid operator");
    }
    return rv;
}

struct parse_node_st * parse_expression(struct parse_table_st *pt,
                                        struct scan_table_st *st) {
    struct scan_token_st *tp;
    struct parse_node_st *np, *np1;

    np = parse_operand(pt, st);

    while (true) {
        tp = scan_table_get(st, 0);
        if ((tp->id == TK_PLUS) || (tp->id == TK_MINUS) ||
            (tp->id == TK_MULT) || (tp->id == TK_DIV)) {
            scan_table_accept(st, TK_ANY);
            np1 = parse_node_new(pt);
            np1->type = OPER2;
            np1->oper2.oper = parse_get_oper(tp->id);
            np1->oper2.left = np;
            np1->oper2.right = parse_operand(pt, st);
            np = np1;
        } else {
            break;
        }
    }

    return np;
}

/*
 * Parse tree pretty printing
 */

char *parse_oper_strings[] = {"PLUS", "MINUS", "MULT", "DIV"};

void parse_tree_print_indent(int level) {
    level *= 2;
    for (int i = 0; i < level; i++) {
        printf(".");
    }
}

void parse_tree_print_expr(struct parse_node_st *np, int level) {
    parse_tree_print_indent(level);
    printf("EXPR ");

    if (np->type == INTVAL) {
        printf("INTVAL %d\n", np->intval.value);
    } else if (np->type == OPER1) {
        printf("OPER1 %s\n", parse_oper_strings[np->oper1.oper]);
        parse_tree_print_expr(np->oper1.expr, level+1);
    } else if (np->type == OPER2) {
        printf("OPER2 %s\n", parse_oper_strings[np->oper2.oper]);
        parse_tree_print_expr(np->oper2.left, level+1);
        parse_tree_print_expr(np->oper2.right, level+1);
    }
}

void parse_tree_print(struct parse_node_st *np) {
    parse_tree_print_expr(np, 0);
}
