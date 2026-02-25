#pragma once

// 抽象表达式接口
typedef struct ArithmeticExpr {
    double (*interpret)(struct ArithmeticExpr* self);
    void (*destroy)(struct ArithmeticExpr* self);
} ArithmeticExpr;

// 虚函数表
typedef struct ArithmeticExprVTable {
    double (*interpret)(ArithmeticExpr* self);
    void (*destroy)(ArithmeticExpr* self);
} ArithmeticExprVTable;