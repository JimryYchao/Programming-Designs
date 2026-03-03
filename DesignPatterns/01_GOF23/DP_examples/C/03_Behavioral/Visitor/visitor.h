#ifndef VISITOR_H
#define VISITOR_H

// 前向声明
typedef struct Computer Computer;
typedef struct Mouse Mouse;
typedef struct Keyboard Keyboard;
typedef struct Monitor Monitor;

// 访问者接口
typedef struct IComputerPartVisitor {
    void (*visitComputer)(void* visitor, Computer* computer);
    void (*visitMouse)(void* visitor, Mouse* mouse);
    void (*visitKeyboard)(void* visitor, Keyboard* keyboard);
    void (*visitMonitor)(void* visitor, Monitor* monitor);
} IComputerPartVisitor;

#endif // VISITOR_H