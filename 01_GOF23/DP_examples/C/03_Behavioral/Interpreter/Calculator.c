// 计算器实现
#include "Calculator.h"
#include "TerminalExpression.h"
#include "NonterminalExpression.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// 计算表达式
double calculator_calculate(const char* expression) {
    int len = strlen(expression);
    ArithmeticExpr* end_expre = calculator_create_expression_tree(expression, 0, len - 1);
    double result = end_expre->interpret(end_expre);
    end_expre->destroy(end_expre);
    return result;
}

// 查找分割点
int calculator_find_split(const char* expression, int start, int end) {
    int tag = -1;
    if (expression[start] == '(' && expression[end] == ')') {
        start++;
        end--;
    }
    int is_in_bracket = 0;
    int more_grade = 0;
    for (int i = start; i <= end; i++) {
        if (expression[i] == '(') {
            is_in_bracket++;
        } else if (expression[i] == ')') {
            is_in_bracket--;
        }
        if ((expression[i] == '+' || expression[i] == '-') && is_in_bracket == 0) {
            more_grade = 1;
            tag = i;
        } else if ((expression[i] == '*' || expression[i] == '/') && more_grade == 0 && is_in_bracket == 0) {
            tag = i;
        }
    }
    return tag;
}

// 创建表达式树
ArithmeticExpr* calculator_create_expression_tree(const char* expression, int start, int end) {
    ArithmeticExpr* ptree = NULL;
    
    // 提取子字符串
    int len = end - start + 1;
    char* substr = (char*)malloc(len + 1);
    if (substr) {
        strncpy(substr, expression + start, len);
        substr[len] = '\0';
        
        // 尝试解析为数字
        char* endptr;
        errno = 0;
        double num = strtod(substr, &endptr);
        if (*endptr == '\0' && errno == 0) {
            ptree = (ArithmeticExpr*)number_expr_create(num);
        } else {
            int tag = calculator_find_split(expression, start, end);
            if (tag < 0) {
                // 处理括号内的数字
                char* s = (char*)malloc(len + 1);
                if (s) {
                    int j = 0;
                    for (int i = 0; i < len; i++) {
                        if (substr[i] != '(' && substr[i] != ')') {
                            s[j++] = substr[i];
                        }
                    }
                    s[j] = '\0';
                    num = strtod(s, &endptr);
                    if (*endptr == '\0' && errno == 0) {
                        ptree = (ArithmeticExpr*)number_expr_create(num);
                    }
                    free(s);
                }
            } else {
                // 创建操作表达式
                ArithmeticExpr* left = calculator_create_expression_tree(expression, start, tag - 1);
                ArithmeticExpr* right = calculator_create_expression_tree(expression, tag + 1, end);
                
                if (expression[tag] == '+') {
                    ptree = (ArithmeticExpr*)addition_expr_create(left, right);
                } else if (expression[tag] == '-') {
                    ptree = (ArithmeticExpr*)subtraction_expr_create(left, right);
                } else if (expression[tag] == '*') {
                    ptree = (ArithmeticExpr*)multiplication_expr_create(left, right);
                } else if (expression[tag] == '/') {
                    ptree = (ArithmeticExpr*)division_expr_create(left, right);
                }
            }
        }
        free(substr);
    }
    return ptree;
}