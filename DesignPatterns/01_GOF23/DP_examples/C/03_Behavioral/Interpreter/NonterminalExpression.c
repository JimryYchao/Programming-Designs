// 非终结符表达式实现
#include "NonterminalExpression.h"
#include <stdlib.h>

// 销毁方法
void operation_expr_destroy(ArithmeticExpr* self) {
    OperationExpr* expr = (OperationExpr*)self;
    if (expr->exp1) {
        expr->exp1->destroy(expr->exp1);
    }
    if (expr->exp2) {
        expr->exp2->destroy(expr->exp2);
    }
    free(self);
}

// 加法解释方法
double addition_expr_interpret(ArithmeticExpr* self) {
    OperationExpr* expr = (OperationExpr*)self;
    return expr->exp1->interpret(expr->exp1) + expr->exp2->interpret(expr->exp2);
}

// 减法解释方法
double subtraction_expr_interpret(ArithmeticExpr* self) {
    OperationExpr* expr = (OperationExpr*)self;
    return expr->exp1->interpret(expr->exp1) - expr->exp2->interpret(expr->exp2);
}

// 乘法解释方法
double multiplication_expr_interpret(ArithmeticExpr* self) {
    OperationExpr* expr = (OperationExpr*)self;
    return expr->exp1->interpret(expr->exp1) * expr->exp2->interpret(expr->exp2);
}

// 除法解释方法
double division_expr_interpret(ArithmeticExpr* self) {
    OperationExpr* expr = (OperationExpr*)self;
    return expr->exp1->interpret(expr->exp1) / expr->exp2->interpret(expr->exp2);
}

// 加法构造函数
AdditionExpr* addition_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2) {
    AdditionExpr* expr = (AdditionExpr*)malloc(sizeof(AdditionExpr));
    if (expr) {
        expr->base.base.interpret = addition_expr_interpret;
        expr->base.base.destroy = operation_expr_destroy;
        expr->base.exp1 = exp1;
        expr->base.exp2 = exp2;
    }
    return expr;
}

// 减法构造函数
SubtractionExpr* subtraction_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2) {
    SubtractionExpr* expr = (SubtractionExpr*)malloc(sizeof(SubtractionExpr));
    if (expr) {
        expr->base.base.interpret = subtraction_expr_interpret;
        expr->base.base.destroy = operation_expr_destroy;
        expr->base.exp1 = exp1;
        expr->base.exp2 = exp2;
    }
    return expr;
}

// 乘法构造函数
MultiplicationExpr* multiplication_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2) {
    MultiplicationExpr* expr = (MultiplicationExpr*)malloc(sizeof(MultiplicationExpr));
    if (expr) {
        expr->base.base.interpret = multiplication_expr_interpret;
        expr->base.base.destroy = operation_expr_destroy;
        expr->base.exp1 = exp1;
        expr->base.exp2 = exp2;
    }
    return expr;
}

// 除法构造函数
DivisionExpr* division_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2) {
    DivisionExpr* expr = (DivisionExpr*)malloc(sizeof(DivisionExpr));
    if (expr) {
        expr->base.base.interpret = division_expr_interpret;
        expr->base.base.destroy = operation_expr_destroy;
        expr->base.exp1 = exp1;
        expr->base.exp2 = exp2;
    }
    return expr;
}