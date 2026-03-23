#pragma once
#include <stdbool.h>

// 叶子接口
typedef struct ILeaf {
    bool is_leaf;
    void (*operation)(struct ILeaf* self);
} ILeaf;

// 组件接口
typedef struct IComponent {
    ILeaf base;
    int (*add)(struct IComponent* self, struct IComponent* component);
    bool (*remove)(struct IComponent* self, struct IComponent* component);
    struct IComponent* (*get_child)(struct IComponent* self, int index);
    void (*operation)(struct IComponent* self);
} IComponent;

// 组合结构体
typedef struct Composite {
    IComponent base;
    struct IComponent** sub_composites;
    int count;
    int capacity;
} Composite;
void Composite_init(Composite* composite, bool is_leaf);
void Composite_destroy(Composite* composite);

