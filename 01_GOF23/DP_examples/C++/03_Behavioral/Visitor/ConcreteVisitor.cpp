#include "ConcreteVisitor.hpp"
#include "ConcreteElement.hpp"
#include <iostream>

// 访问 Computer
void ComputerPartDisplayVisitor::visit(Computer* computer) {
    std::cout << "Displaying Computer" << std::endl;
}

// 访问 Mouse
void ComputerPartDisplayVisitor::visit(Mouse* mouse) {
    std::cout << "Displaying Mouse" << std::endl;
    mouse->operation();
}

// 访问 Keyboard
void ComputerPartDisplayVisitor::visit(Keyboard* keyboard) {
    std::cout << "Displaying Keyboard" << std::endl;
    keyboard->operation();
}

// 访问 Monitor
void ComputerPartDisplayVisitor::visit(Monitor* monitor) {
    std::cout << "Displaying Monitor" << std::endl;
    monitor->operation();
}