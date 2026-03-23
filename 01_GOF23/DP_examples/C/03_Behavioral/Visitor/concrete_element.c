#include "concrete_element.h"
#include "visitor.h"
#include <stdio.h>

// Keyboard 实现
static void Keyboard_accept(IComputerPart* self, IComputerPartVisitor* visitor) {
    visitor->visitKeyboard(visitor, (struct Keyboard*)self);
}

void Keyboard_init(Keyboard* self) {
    self->base.accept = Keyboard_accept;
}

void Keyboard_operation(Keyboard* self) {
    printf("Using Keyboard\n");
}

// Monitor 实现
static void Monitor_accept(IComputerPart* self, IComputerPartVisitor* visitor) {
    visitor->visitMonitor(visitor, (struct Monitor*)self);
}

void Monitor_init(Monitor* self) {
    self->base.accept = Monitor_accept;
}

void Monitor_operation(Monitor* self) {
    printf("Using Monitor\n");
}

// Mouse 实现
static void Mouse_accept(IComputerPart* self, IComputerPartVisitor* visitor) {
    visitor->visitMouse(visitor, (struct Mouse*)self);
}

void Mouse_init(Mouse* self) {
    self->base.accept = Mouse_accept;
}

void Mouse_operation(Mouse* self) {
    printf("Using Mouse\n");
}

// Computer 实现
static void Computer_accept(IComputerPart* self, IComputerPartVisitor* visitor) {
    Computer* computer = (Computer*)self;
    for (int i = 0; i < 3; i++) {
        computer->parts[i]->accept(computer->parts[i], visitor);
    }
    visitor->visitComputer(visitor, computer);
}

void Computer_init(Computer* self) {
    self->base.accept = Computer_accept;
    
    // 初始化部件
    static Keyboard keyboard;
    static Mouse mouse;
    static Monitor monitor;
    
    Keyboard_init(&keyboard);
    Mouse_init(&mouse);
    Monitor_init(&monitor);
    
    self->parts[0] = (IComputerPart*)&keyboard;
    self->parts[1] = (IComputerPart*)&mouse;
    self->parts[2] = (IComputerPart*)&monitor;
}