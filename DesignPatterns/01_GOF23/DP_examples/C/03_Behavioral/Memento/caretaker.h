#ifndef CARETAKER_H
#define CARETAKER_H

#include "memento.h"

// 管理者结构
typedef struct Caretaker {
    Memento** mementos;
    int count;
    int capacity;
} Caretaker;

// 创建管理者
Caretaker* create_caretaker(int capacity);

// 保存备忘录
void save_memento(Caretaker* caretaker, int version, Memento* memento);

// 获取备忘录
Memento* get_memento(Caretaker* caretaker, int version);

// 销毁管理者
void destroy_caretaker(Caretaker* caretaker);

#endif // CARETAKER_H
