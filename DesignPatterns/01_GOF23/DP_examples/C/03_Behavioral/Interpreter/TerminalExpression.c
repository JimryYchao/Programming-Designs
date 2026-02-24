// 终结符表达式实现
#include "TerminalExpression.h"
#include <stdlib.h>

// 解释方法
double number_expr_interpret(ArithmeticExpr* self) {
    NumberExpr* expr = (NumberExpr*)self;
    return expr->num;
}

// 销毁方法
void number_expr_destroy(ArithmeticExpr* self) {
    free(self);
}

// 构造函数
NumberExpr* number_expr_create(double num) {
    NumberExpr* expr = (NumberExpr*)malloc(sizeof(NumberExpr));
    if (expr) {
        expr->base.interpret = number_expr_interpret;
        expr->base.destroy = number_expr_destroy;
        expr->num = num;
    }
    return expr;
}