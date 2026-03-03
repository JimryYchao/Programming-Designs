#ifndef VISITOR_HPP
#define VISITOR_HPP

// 前向声明
class Computer;
class Mouse;
class Keyboard;
class Monitor;

// 访问者接口
class IComputerPartVisitor {
public:
    virtual ~IComputerPartVisitor() = default;
    virtual void visit(Computer* computer) = 0;
    virtual void visit(Mouse* mouse) = 0;
    virtual void visit(Keyboard* keyboard) = 0;
    virtual void visit(Monitor* monitor) = 0;
};

#endif // VISITOR_HPP