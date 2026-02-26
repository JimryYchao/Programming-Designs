#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "memento.h"

// 发起者结构
typedef struct Originator {
    char* state1;
    char* state2;
    char* state3;
} Originator;

// 创建发起者
Originator* create_originator(const char* s1, const char* s2, const char* s3);

// 打印状态
void console_state(Originator* originator);

// 创建备忘录
Memento* create_memento_from_originator(Originator* originator, int version);

// 恢复状态
void set_memento_to_originator(Originator* originator, Memento* memento);

// 销毁发起者
void destroy_originator(Originator* originator);

#endif // ORIGINATOR_H
