// 计算器类，用于构建和解析表达式
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>
#include <cstdlib>
#include "AbstractExpression.hpp"
#include "TerminalExpression.hpp"
#include "NonterminalExpression.hpp"

class Calculator {
public:
    static double calculate(const std::string& expression) {
        ArithmeticExpr* endExpre = createExpressionTree(expression, 0, expression.length() - 1);
        double result = endExpre->interpret();
        delete endExpre;
        return result;
    }

private:
    static int findSplit(const std::string& expression, int start, int end) {
        int tag = -1;
        if (expression[start] == '(' && expression[end] == ')') {
            start++;
            end--;
        }
        int isInBracket = 0;
        int moreGrade = 0;
        for (int i = start; i <= end; i++) {
            if (expression[i] == '(') {
                isInBracket++;
            } else if (expression[i] == ')') {
                isInBracket--;
            }
            if ((expression[i] == '+' || expression[i] == '-') && isInBracket == 0) {
                moreGrade = 1;
                tag = i;
            } else if ((expression[i] == '*' || expression[i] == '/') && moreGrade == 0 && isInBracket == 0) {
                tag = i;
            }
        }
        return tag;
    }

    static ArithmeticExpr* createExpressionTree(const std::string& expression, int start, int end) {
        ArithmeticExpr* ptree = nullptr;
        std::string substr = expression.substr(start, end - start + 1);
        
        // 尝试解析为数字
        char* endptr;
        double num = strtod(substr.c_str(), &endptr);
        if (*endptr == '\0') {
            ptree = new NumberExpr(num);
        } else {
            int tag = findSplit(expression, start, end);
            if (tag < 0) {
                // 处理括号内的数字
                std::string s;
                for (char c : substr) {
                    if (c != '(' && c != ')') {
                        s += c;
                    }
                }
                num = strtod(s.c_str(), &endptr);
                if (*endptr == '\0') {
                    ptree = new NumberExpr(num);
                }
            } else {
                if (expression[tag] == '+') {
                    ptree = new AdditionExpr(
                        createExpressionTree(expression, start, tag - 1),
                        createExpressionTree(expression, tag + 1, end)
                    );
                } else if (expression[tag] == '-') {
                    ptree = new SubtractionExpr(
                        createExpressionTree(expression, start, tag - 1),
                        createExpressionTree(expression, tag + 1, end)
                    );
                } else if (expression[tag] == '*') {
                    ptree = new MultiplicationExpr(
                        createExpressionTree(expression, start, tag - 1),
                        createExpressionTree(expression, tag + 1, end)
                    );
                } else if (expression[tag] == '/') {
                    ptree = new DivisionExpr(
                        createExpressionTree(expression, start, tag - 1),
                        createExpressionTree(expression, tag + 1, end)
                    );
                }
            }
        }
        return ptree;
    }
};

#endif // CALCULATOR_HPP