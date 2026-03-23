#include "ConcreteElement.hpp"
#include "ConcreteVisitor.hpp"

int main() {
    // 创建 Computer 对象
    Computer* computer = new Computer();
    
    // 创建访问者
    ComputerPartDisplayVisitor* visitor = new ComputerPartDisplayVisitor();
    
    // 接受访问
    computer->accept(visitor);
    
    // 释放资源
    delete computer;
    delete visitor;
}

// g++ -o client Client.cpp ConcreteElement.cpp ConcreteVisitor.cpp