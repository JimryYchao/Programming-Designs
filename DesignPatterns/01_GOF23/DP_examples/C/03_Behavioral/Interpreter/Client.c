// 客户端代码，用于测试解释器模式
#include "Calculator.h"
#include <stdio.h>

int main() {
    printf("%.0f\n", calculator_calculate("1+2+3"));
    printf("%.0f\n", calculator_calculate("2*(1+2)"));
    printf("%.0f\n", calculator_calculate("2+(1+2*5)"));
    printf("%.0f\n", calculator_calculate("2*(1+2*6)"));
    printf("%f\n", calculator_calculate("(68*(115+20)+10)"));
    return 0;
}

// gcc -o Client Client.c Calculator.c NonterminalExpression.c TerminalExpression.c