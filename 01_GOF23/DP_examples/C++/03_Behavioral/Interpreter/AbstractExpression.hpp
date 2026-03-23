// 抽象表达式接口
#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

class ArithmeticExpr {
public:
    virtual ~ArithmeticExpr() = default;
    virtual double interpret() = 0;
};

#endif // ABSTRACT_EXPRESSION_HPP