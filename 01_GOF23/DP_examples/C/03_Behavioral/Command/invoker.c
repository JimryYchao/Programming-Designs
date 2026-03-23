// 命令调用者实现
#include <stdio.h>
#include <stdlib.h>
#include "invoker.h"

// 创建命令调用者
Invoker* create_invoker() {
    Invoker* invoker = (Invoker*)malloc(sizeof(Invoker));
    if (invoker) {
        invoker->capacity = 10;
        invoker->count = 0;
        invoker->commands = (ICommand**)malloc(sizeof(ICommand*) * invoker->capacity);
        if (!invoker->commands) {
            free(invoker);
            return NULL;
        }
    }
    return invoker;
}

// 存储命令
void invoker_store_command(Invoker* invoker, ICommand* command) {
    if (!invoker || !command) {
        return;
    }
    
    // 检查容量是否足够
    if (invoker->count >= invoker->capacity) {
        invoker->capacity *= 2;
        ICommand** new_commands = (ICommand**)realloc(invoker->commands, sizeof(ICommand*) * invoker->capacity);
        if (!new_commands) {
            return;
        }
        invoker->commands = new_commands;
    }
    
    invoker->commands[invoker->count++] = command;
}

// 移除命令
int invoker_remove_command(Invoker* invoker, ICommand* command) {
    if (!invoker || !command || invoker->count == 0) {
        return 0;
    }
    
    int i;
    for (i = 0; i < invoker->count; i++) {
        if (invoker->commands[i] == command) {
            // 移除命令
            for (int j = i; j < invoker->count - 1; j++) {
                invoker->commands[j] = invoker->commands[j + 1];
            }
            invoker->count--;
            return 1;
        }
    }
    
    return 0;
}

// 获取命令数量
int invoker_count(Invoker* invoker) {
    if (!invoker) {
        return 0;
    }
    return invoker->count;
}

// 执行所有命令
void invoker_invoke(Invoker* invoker) {
    if (!invoker) {
        return;
    }
    
    for (int i = 0; i < invoker->count; i++) {
        if (invoker->commands[i]) {
            invoker->commands[i]->execute(invoker->commands[i]);
        }
    }
}

// 释放命令调用者
void destroy_invoker(Invoker* invoker) {
    if (!invoker) {
        return;
    }
    
    // 释放所有命令
    for (int i = 0; i < invoker->count; i++) {
        if (invoker->commands[i]) {
            invoker->commands[i]->destroy(invoker->commands[i]);
        }
    }
    
    free(invoker->commands);
    free(invoker);
}
