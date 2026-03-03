#ifndef CONCRETE_VISITOR_HPP
#define CONCRETE_VISITOR_HPP

#include "Visitor.hpp"

// 具体访问者：ComputerPartDisplayVisitor
class ComputerPartDisplayVisitor : public IComputerPartVisitor {
public:
    void visit(Computer* computer) override;
    void visit(Mouse* mouse) override;
    void visit(Keyboard* keyboard) override;
    void visit(Monitor* monitor) override;
};

#endif // CONCRETE_VISITOR_HPP