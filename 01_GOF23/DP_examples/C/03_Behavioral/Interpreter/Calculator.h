// 计算器类，用于构建和解析表达式
#include "AbstractExpression.h"

// 计算表达式
double calculator_calculate(const char* expression);

// 查找分割点
int calculator_find_split(const char* expression, int start, int end);

// 创建表达式树
ArithmeticExpr* calculator_create_expression_tree(const char* expression, int start, int end);