/* eval.c */

#include "project02.h"

void eval_error(char *err) {
    printf("intper_error: %s\n", err);
    exit(-1);
}

void eval_print(uint32_t value) {
    printf("%d\n", value);
}

uint32_t eval_tree_expr(struct parse_node_st *np) {
    struct parse_node_st *np1, *np2;
    uint32_t v1, v2, result;

    if (np->type == INTVAL) {
        v1 = np->intval.value;
    } else if (np->type == OPER1) {
        np1 = np->oper1.expr;
        v1 = eval_tree_expr(np1);
        if (np->oper1.oper == MINUS) {
            v1 = -(v1);
        } else {
            eval_error("Invalid unary operator");
        }
    } else if (np->type == OPER2) {
        np1 = np->oper2.left;
        np2 = np->oper2.right;
        v1 = eval_tree_expr(np1);
        v2 = eval_tree_expr(np2);
        if (np->oper2.oper == PLUS) {
            result = v1 + v2;
        } else if (np->oper2.oper == MINUS) {
            result = v1 - v2;
        } else if (np->oper2.oper == MULT) {
            result = v1 * v2;
        } else if (np->oper2.oper == DIV) {
            result = v1 / v2;
        }
        v1 = result;
    }
    return v1;
}

uint32_t eval_tree(struct parse_node_st *np) {
    return eval_tree_expr(np);
}
