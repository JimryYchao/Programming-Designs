#include "ConcreteElement.hpp"
#include "Visitor.hpp"
#include <iostream>

// Keyboard 实现
void Keyboard::accept(IComputerPartVisitor* visitor) {
    visitor->visit(this);
}

void Keyboard::operation() {
    std::cout << "Using Keyboard" << std::endl;
}

// Monitor 实现
void Monitor::accept(IComputerPartVisitor* visitor) {
    visitor->visit(this);
}

void Monitor::operation() {
    std::cout << "Using Monitor" << std::endl;
}

// Mouse 实现
void Mouse::accept(IComputerPartVisitor* visitor) {
    visitor->visit(this);
}

void Mouse::operation() {
    std::cout << "Using Mouse" << std::endl;
}

// Computer 实现
Computer::Computer() {
    parts[0] = new Keyboard();
    parts[1] = new Mouse();
    parts[2] = new Monitor();
}

Computer::~Computer() {
    for (int i = 0; i < 3; i++) {
        delete parts[i];
    }
}

void Computer::accept(IComputerPartVisitor* visitor) {
    for (int i = 0; i < 3; i++) {
        parts[i]->accept(visitor);
    }
    visitor->visit(this);
}