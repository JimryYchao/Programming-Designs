// 命令模式的 C 语言实现
#ifndef COMMAND_H
#define COMMAND_H

// 命令接口
typedef struct ICommand ICommand;

struct ICommand {
    void (*execute)(ICommand* self);
    void (*destroy)(ICommand* self);
};

// 具体命令实现
typedef struct ConcreteCommand ConcreteCommand;

struct ConcreteCommand {
    ICommand base;
    void* receiver;
    void (*receiver_action)(void* receiver);
};

// 创建具体命令
ConcreteCommand* create_concrete_command(void* receiver, void (*receiver_action)(void*));

#endif // COMMAND_H
