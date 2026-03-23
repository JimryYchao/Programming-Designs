// 非终结符表达式 - 处理运算符
#include "AbstractExpression.h"

typedef struct OperationExpr OperationExpr;

struct OperationExpr {
    ArithmeticExpr base;
    ArithmeticExpr* exp1;
    ArithmeticExpr* exp2;
};

// 加法表达式
typedef struct AdditionExpr AdditionExpr;
struct AdditionExpr {
    OperationExpr base;
};

// 减法表达式
typedef struct SubtractionExpr SubtractionExpr;
struct SubtractionExpr {
    OperationExpr base;
};

// 乘法表达式
typedef struct MultiplicationExpr MultiplicationExpr;
struct MultiplicationExpr {
    OperationExpr base;
};

// 除法表达式
typedef struct DivisionExpr DivisionExpr;
struct DivisionExpr {
    OperationExpr base;
};

// 构造函数
AdditionExpr* addition_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2);
SubtractionExpr* subtraction_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2);
MultiplicationExpr* multiplication_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2);
DivisionExpr* division_expr_create(ArithmeticExpr* exp1, ArithmeticExpr* exp2);

// 解释方法
double addition_expr_interpret(ArithmeticExpr* self);
double subtraction_expr_interpret(ArithmeticExpr* self);
double multiplication_expr_interpret(ArithmeticExpr* self);
double division_expr_interpret(ArithmeticExpr* self);

// 销毁方法
void operation_expr_destroy(ArithmeticExpr* self);