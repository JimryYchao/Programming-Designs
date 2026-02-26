#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <iostream>
#include <string>
#include <map>

class Memento {
private:
    std::map<std::string, std::string> states;
    int version;

public:
    Memento(int version);
    std::string getState(const std::string& identifier) const;
    void setState(const std::string& identifier, const std::string& state);
    int getVersion() const;
};


Memento::Memento(int version) : version(version) {
}

std::string Memento::getState(const std::string& identifier) const {
    auto it = states.find(identifier);
    if (it != states.end()) {
        return it->second;
    }
    return "";
}

void Memento::setState(const std::string& identifier, const std::string& state) {
    states[identifier] = state;
}

int Memento::getVersion() const {
    return version;
}


#endif // MEMENTO_HPP
