// 终结符表达式 - 处理数字
#ifndef TERMINAL_EXPRESSION_HPP
#define TERMINAL_EXPRESSION_HPP

#include "AbstractExpression.hpp"

class NumberExpr : public ArithmeticExpr {
private:
    double num;
public:
    NumberExpr(double num) : num(num) {}
    double interpret() override {
        return num;
    }
};

#endif // TERMINAL_EXPRESSION_HPP