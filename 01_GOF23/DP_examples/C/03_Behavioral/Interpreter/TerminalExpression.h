// 终结符表达式 - 处理数字
#include "AbstractExpression.h"

typedef struct NumberExpr NumberExpr;

struct NumberExpr {
    ArithmeticExpr base;
    double num;
};

// 构造函数
NumberExpr* number_expr_create(double num);
// 解释方法
double number_expr_interpret(ArithmeticExpr* self);
// 销毁方法
void number_expr_destroy(ArithmeticExpr* self);