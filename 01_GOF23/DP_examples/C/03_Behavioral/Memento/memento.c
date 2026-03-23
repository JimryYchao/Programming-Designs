#include "memento.h"

// 创建备忘录
Memento* create_memento(int version) {
    Memento* memento = (Memento*)malloc(sizeof(Memento));
    if (memento == NULL) {
        return NULL;
    }
    memento->states = NULL;
    memento->version = version;
    return memento;
}

// 查找状态
State* find_state(State* head, const char* key) {
    State* current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 获取状态
void* get_state(Memento* memento, const char* identifier) {
    if (memento == NULL) {
        return NULL;
    }
    State* state = find_state(memento->states, identifier);
    if (state != NULL) {
        return state->value;
    }
    return NULL;
}

// 设置状态
void set_state(Memento* memento, const char* identifier, void* state, size_t size) {
    if (memento == NULL) {
        return;
    }
    
    // 查找是否已存在该状态
    State* existing_state = find_state(memento->states, identifier);
    if (existing_state != NULL) {
        // 更新已存在的状态
        free(existing_state->value);
        existing_state->value = malloc(size);
        if (existing_state->value != NULL) {
            memcpy(existing_state->value, state, size);
        }
        return;
    }
    
    // 创建新状态
    State* new_state = (State*)malloc(sizeof(State));
    if (new_state == NULL) {
        return;
    }
    new_state->key = strdup(identifier);
    new_state->value = malloc(size);
    if (new_state->key == NULL || new_state->value == NULL) {
        free(new_state->key);
        free(new_state->value);
        free(new_state);
        return;
    }
    memcpy(new_state->value, state, size);
    new_state->next = memento->states;
    memento->states = new_state;
}

// 销毁备忘录
void destroy_memento(Memento* memento) {
    if (memento == NULL) {
        return;
    }
    State* current = memento->states;
    while (current != NULL) {
        State* next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(memento);
}
