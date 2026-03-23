#ifndef CONCRETE_ELEMENT_HPP
#define CONCRETE_ELEMENT_HPP

#include "Element.hpp"

// 具体元素：Keyboard
class Keyboard : public IComputerPart {
public:
    void accept(IComputerPartVisitor* visitor) override;
    void operation();
};

// 具体元素：Monitor
class Monitor : public IComputerPart {
public:
    void accept(IComputerPartVisitor* visitor) override;
    void operation();
};

// 具体元素：Mouse
class Mouse : public IComputerPart {
public:
    void accept(IComputerPartVisitor* visitor) override;
    void operation();
};

// 具体元素：Computer (ObjectStructure)
class Computer : public IComputerPart {
private:
    IComputerPart* parts[3];
public:
    Computer();
    ~Computer();
    void accept(IComputerPartVisitor* visitor) override;
};

#endif // CONCRETE_ELEMENT_HPP