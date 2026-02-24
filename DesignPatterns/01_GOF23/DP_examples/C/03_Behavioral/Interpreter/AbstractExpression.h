// 抽象表达式接口
typedef struct ArithmeticExpr ArithmeticExpr;

struct ArithmeticExpr {
    double (*interpret)(ArithmeticExpr* self);
    void (*destroy)(ArithmeticExpr* self);
};

// 虚函数表
typedef struct ArithmeticExprVTable {
    double (*interpret)(ArithmeticExpr* self);
    void (*destroy)(ArithmeticExpr* self);
} ArithmeticExprVTable;