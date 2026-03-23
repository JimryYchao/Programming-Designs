#ifndef CARETAKER_HPP
#define CARETAKER_HPP

#include "Memento.hpp"
#include <map>

class Caretaker {
private:
    std::map<int, Memento*> mementoMap;

public:
    Caretaker();
    ~Caretaker();
    void saveMemento(int version, Memento* memento);
    Memento* getMemento(int version) const;
};


Caretaker::Caretaker() {
}

Caretaker::~Caretaker() {
    for (auto& pair : mementoMap) {
        delete pair.second;
    }
}

void Caretaker::saveMemento(int version, Memento* memento) {
    mementoMap[version] = memento;
}

Memento* Caretaker::getMemento(int version) const {
    auto it = mementoMap.find(version);
    if (it != mementoMap.end()) {
        return it->second;
    }
    return nullptr;
}


#endif // CARETAKER_HPP
