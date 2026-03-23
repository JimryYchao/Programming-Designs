// 命令调用者
#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <vector>
#include "Command.hpp"

class Invoker {
private:
    std::vector<ICommand*> commands;
public:
    ~Invoker() {
        // 释放命令
        for (ICommand* command : commands) {
            delete command;
        }
    }
    
    void storeCommand(ICommand* command) {
        commands.push_back(command);
    }
    
    bool removeCommand(ICommand* command) {
        if (commands.empty()) {
            return false;
        }
        for (auto it = commands.begin(); it != commands.end(); ++it) {
            if (*it == command) {
                delete *it;
                commands.erase(it);
                return true;
            }
        }
        return false;
    }
    
    int count() const {
        return commands.size();
    }
    
    void invoke() {
        for (ICommand* command : commands) {
            command->execute();
        }
    }
};

#endif // INVOKER_HPP
