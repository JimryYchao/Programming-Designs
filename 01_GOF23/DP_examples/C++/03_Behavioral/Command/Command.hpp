// 命令模式的 C++ 实现
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

// 命令接口
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() = 0;
};

// 接收者接口
class IReceiver {
public:
    virtual ~IReceiver() = default;
    virtual void action() = 0;
};

// 具体命令实现
class ConcreteCommand : public ICommand {
private:
    IReceiver* receiver;
public:
    ConcreteCommand(IReceiver* receiver) : receiver(receiver) {}
    void execute() override {
        if (receiver) {
            receiver->action();
        }
    }
};

#endif // COMMAND_HPP
