// 客户端代码，用于测试解释器模式
#include "Calculator.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << Calculator::calculate("1+2+3") << endl;
    cout << Calculator::calculate("2*(1+2)") << endl;
    cout << Calculator::calculate("2+(1+2*5)") << endl;
    cout << Calculator::calculate("2*(1+2*6)") << endl;
    cout << Calculator::calculate("(68*(115+20)+10)") << endl;
}