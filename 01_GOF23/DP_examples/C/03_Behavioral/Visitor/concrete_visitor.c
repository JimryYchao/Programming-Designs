#include "concrete_visitor.h"
#include "concrete_element.h"
#include <stdio.h>

// 访问 Computer
static void visitComputer(void* visitor, struct Computer* computer) {
    printf("Displaying Computer\n");
}

// 访问 Mouse
static void visitMouse(void* visitor, struct Mouse* mouse) {
    printf("Displaying Mouse\n");
    Mouse_operation((Mouse*)mouse);
}

// 访问 Keyboard
static void visitKeyboard(void* visitor, struct Keyboard* keyboard) {
    printf("Displaying Keyboard\n");
    Keyboard_operation((Keyboard*)keyboard);
}

// 访问 Monitor
static void visitMonitor(void* visitor, struct Monitor* monitor) {
    printf("Displaying Monitor\n");
    Monitor_operation((Monitor*)monitor);
}

void ComputerPartDisplayVisitor_init(ComputerPartDisplayVisitor* self) {
    self->base.visitComputer = visitComputer;
    self->base.visitMouse = visitMouse;
    self->base.visitKeyboard = visitKeyboard;
    self->base.visitMonitor = visitMonitor;
}