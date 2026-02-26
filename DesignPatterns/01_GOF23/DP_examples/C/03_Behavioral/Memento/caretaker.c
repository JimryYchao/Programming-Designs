#include "caretaker.h"

// 创建管理者
Caretaker* create_caretaker(int capacity) {
    Caretaker* caretaker = (Caretaker*)malloc(sizeof(Caretaker));
    if (caretaker == NULL) {
        return NULL;
    }
    caretaker->mementos = (Memento**)malloc(sizeof(Memento*) * capacity);
    if (caretaker->mementos == NULL) {
        free(caretaker);
        return NULL;
    }
    caretaker->count = 0;
    caretaker->capacity = capacity;
    return caretaker;
}

// 保存备忘录
void save_memento(Caretaker* caretaker, int version, Memento* memento) {
    if (caretaker == NULL || memento == NULL) {
        return;
    }
    if (caretaker->count < caretaker->capacity) {
        caretaker->mementos[caretaker->count] = memento;
        caretaker->count++;
    }
}

// 获取备忘录
Memento* get_memento(Caretaker* caretaker, int version) {
    if (caretaker == NULL) {
        return NULL;
    }
    for (int i = 0; i < caretaker->count; i++) {
        if (caretaker->mementos[i]->version == version) {
            return caretaker->mementos[i];
        }
    }
    return NULL;
}

// 销毁管理者
void destroy_caretaker(Caretaker* caretaker) {
    if (caretaker == NULL) {
        return;
    }
    for (int i = 0; i < caretaker->count; i++) {
        destroy_memento(caretaker->mementos[i]);
    }
    free(caretaker->mementos);
    free(caretaker);
}
