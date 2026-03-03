#ifndef CONCRETE_ELEMENT_H
#define CONCRETE_ELEMENT_H

#include "element.h"

// 具体元素：Keyboard
typedef struct Keyboard {
    IComputerPart base;
} Keyboard;

void Keyboard_init(Keyboard* self);
void Keyboard_operation(Keyboard* self);

// 具体元素：Monitor
typedef struct Monitor {
    IComputerPart base;
} Monitor;

void Monitor_init(Monitor* self);
void Monitor_operation(Monitor* self);

// 具体元素：Mouse
typedef struct Mouse {
    IComputerPart base;
} Mouse;

void Mouse_init(Mouse* self);
void Mouse_operation(Mouse* self);

// 具体元素：Computer (ObjectStructure)
typedef struct Computer {
    IComputerPart base;
    IComputerPart* parts[3];
} Computer;

void Computer_init(Computer* self);

#endif // CONCRETE_ELEMENT_H