#ifndef ORIGINATOR_HPP
#define ORIGINATOR_HPP

#include "Memento.hpp"
#include <string>

class Originator {
private:
    std::string state1;
    std::string state2;
    std::string state3;

public:
    Originator(const std::string& s1, const std::string& s2, const std::string& s3);
    void consoleState() const;
    Memento* createMemento(int version) const;
    void setMemento(const Memento* memento);
};


Originator::Originator(const std::string& s1, const std::string& s2, const std::string& s3)
    : state1(s1), state2(s2), state3(s3) {
}

void Originator::consoleState() const {
    std::cout << "State_1: " << state1 << std::endl;
    std::cout << "State_2: " << state2 << std::endl;
    std::cout << "State_3: " << state3 << std::endl;
}

Memento* Originator::createMemento(int version) const {
    Memento* memento = new Memento(version);
    memento->setState("state1", state1);
    memento->setState("state2", state2);
    memento->setState("state3", state3);
    return memento;
}

void Originator::setMemento(const Memento* memento) {
    if (memento) {
        state1 = memento->getState("state1");
        state2 = memento->getState("state2");
        state3 = memento->getState("state3");
    }
}


#endif // ORIGINATOR_HPP
