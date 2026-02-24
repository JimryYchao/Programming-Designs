// 非终结符表达式 - 处理运算符
#ifndef NONTERMINAL_EXPRESSION_HPP
#define NONTERMINAL_EXPRESSION_HPP

#include "AbstractExpression.hpp"

class OperationExpr : public ArithmeticExpr {
protected:
    ArithmeticExpr* exp1;
    ArithmeticExpr* exp2;
public:
    OperationExpr(ArithmeticExpr* exp1, ArithmeticExpr* exp2) : exp1(exp1), exp2(exp2) {}
    virtual ~OperationExpr() {
        delete exp1;
        delete exp2;
    }
};

class AdditionExpr : public OperationExpr {
public:
    AdditionExpr(ArithmeticExpr* exp1, ArithmeticExpr* exp2) : OperationExpr(exp1, exp2) {}
    double interpret() override {
        return exp1->interpret() + exp2->interpret();
    }
};

class SubtractionExpr : public OperationExpr {
public:
    SubtractionExpr(ArithmeticExpr* exp1, ArithmeticExpr* exp2) : OperationExpr(exp1, exp2) {}
    double interpret() override {
        return exp1->interpret() - exp2->interpret();
    }
};

class MultiplicationExpr : public OperationExpr {
public:
    MultiplicationExpr(ArithmeticExpr* exp1, ArithmeticExpr* exp2) : OperationExpr(exp1, exp2) {}
    double interpret() override {
        return exp1->interpret() * exp2->interpret();
    }
};

class DivisionExpr : public OperationExpr {
public:
    DivisionExpr(ArithmeticExpr* exp1, ArithmeticExpr* exp2) : OperationExpr(exp1, exp2) {}
    double interpret() override {
        return exp1->interpret() / exp2->interpret();
    }
};

#endif // NONTERMINAL_EXPRESSION_HPP