// 命令模式的 C 语言实现
#include <stdio.h>
#include <stdlib.h>
#include "command.h"

// 具体命令的 execute 方法
static void concrete_command_execute(ICommand* self) {
    ConcreteCommand* command = (ConcreteCommand*)self;
    if (command->receiver && command->receiver_action) {
        command->receiver_action(command->receiver);
    }
}

// 具体命令的 destroy 方法
static void concrete_command_destroy(ICommand* self) {
    free(self);
}

// 创建具体命令
ConcreteCommand* create_concrete_command(void* receiver, void (*receiver_action)(void*)) {
    ConcreteCommand* command = (ConcreteCommand*)malloc(sizeof(ConcreteCommand));
    if (command) {
        command->base.execute = concrete_command_execute;
        command->base.destroy = concrete_command_destroy;
        command->receiver = receiver;
        command->receiver_action = receiver_action;
    }
    return command;
}
