#ifndef MEMENTO_H
#define MEMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 状态结构
typedef struct State {
    char* key;
    void* value;
    struct State* next;
} State;

// 备忘录结构
typedef struct Memento {
    State* states;
    int version;
} Memento;

// 创建备忘录
Memento* create_memento(int version);

// 获取状态
void* get_state(Memento* memento, const char* identifier);

// 设置状态
void set_state(Memento* memento, const char* identifier, void* state, size_t size);

// 销毁备忘录
void destroy_memento(Memento* memento);

#endif // MEMENTO_H
