#include "originator.h"

// 创建发起者
Originator* create_originator(const char* s1, const char* s2, const char* s3) {
    Originator* originator = (Originator*)malloc(sizeof(Originator));
    if (originator == NULL) {
        return NULL;
    }
    originator->state1 = strdup(s1);
    originator->state2 = strdup(s2);
    originator->state3 = strdup(s3);
    if (originator->state1 == NULL || originator->state2 == NULL || originator->state3 == NULL) {
        free(originator->state1);
        free(originator->state2);
        free(originator->state3);
        free(originator);
        return NULL;
    }
    return originator;
}

// 打印状态
void console_state(Originator* originator) {
    if (originator == NULL) {
        return;
    }
    printf("State_1: %s\n", originator->state1);
    printf("State_2: %s\n", originator->state2);
    printf("State_3: %s\n", originator->state3);
}

// 创建备忘录
Memento* create_memento_from_originator(Originator* originator, int version) {
    if (originator == NULL) {
        return NULL;
    }
    Memento* memento = create_memento(version);
    if (memento == NULL) {
        return NULL;
    }
    set_state(memento, "state1", originator->state1, strlen(originator->state1) + 1);
    set_state(memento, "state2", originator->state2, strlen(originator->state2) + 1);
    set_state(memento, "state3", originator->state3, strlen(originator->state3) + 1);
    return memento;
}

// 恢复状态
void set_memento_to_originator(Originator* originator, Memento* memento) {
    if (originator == NULL || memento == NULL) {
        return;
    }
    char* s1 = (char*)get_state(memento, "state1");
    char* s2 = (char*)get_state(memento, "state2");
    char* s3 = (char*)get_state(memento, "state3");
    if (s1 != NULL) {
        free(originator->state1);
        originator->state1 = strdup(s1);
    }
    if (s2 != NULL) {
        free(originator->state2);
        originator->state2 = strdup(s2);
    }
    if (s3 != NULL) {
        free(originator->state3);
        originator->state3 = strdup(s3);
    }
}

// 销毁发起者
void destroy_originator(Originator* originator) {
    if (originator == NULL) {
        return;
    }
    free(originator->state1);
    free(originator->state2);
    free(originator->state3);
    free(originator);
}
