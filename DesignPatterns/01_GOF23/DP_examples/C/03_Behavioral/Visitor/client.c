#include "concrete_element.h"
#include "concrete_visitor.h"

int main() {
    // 创建 Computer 对象
    Computer computer;
    Computer_init(&computer);
    
    // 创建访问者
    ComputerPartDisplayVisitor visitor;
    ComputerPartDisplayVisitor_init(&visitor);
    
    // 接受访问
    computer.base.accept((IComputerPart*)&computer, (IComputerPartVisitor*)&visitor);
}

// gcc -o client client.c concrete_element.c concrete_visitor.c