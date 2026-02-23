// 命令调用者
#ifndef INVOKER_H
#define INVOKER_H

#include "command.h"

// 命令调用者
typedef struct Invoker {
    ICommand** commands;
    int count;
    int capacity;
} Invoker;

// 创建命令调用者
Invoker* create_invoker();

// 存储命令
void invoker_store_command(Invoker* invoker, ICommand* command);

// 移除命令
int invoker_remove_command(Invoker* invoker, ICommand* command);

// 获取命令数量
int invoker_count(Invoker* invoker);

// 执行所有命令
void invoker_invoke(Invoker* invoker);

// 释放命令调用者
void destroy_invoker(Invoker* invoker);

#endif // INVOKER_H
