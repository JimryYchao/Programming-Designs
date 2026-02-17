#include "component.h"
#include <stdlib.h>

// 操作方法（默认实现）
static void ILeaf_operation(struct ILeaf *self) {}

static void Composite_operation(struct IComponent *self)
{
    self->base.operation(&self->base);
    if (!self->base.is_leaf)
    {
        Composite *composite = (Composite *)self;
        for (int i = 0; i < composite->count; i++)
            Composite_operation(composite->sub_composites[i]);
    }
}

// 添加组件
static int Composite_add(struct IComponent *self, struct IComponent *component)
{
    if (self->base.is_leaf || component == NULL)
        return -1;
    Composite *composite = (Composite *)self;
    // 检查是否已存在
    for (int i = 0; i < composite->count; i++)
        if (composite->sub_composites[i] == component)
            return -1;
    // 扩容
    if (composite->count >= composite->capacity)
    {
        int new_capacity = composite->capacity == 0 ? 4 : composite->capacity * 2;
        struct IComponent **new_sub_composites = realloc(composite->sub_composites, new_capacity * sizeof(struct IComponent *));
        if (new_sub_composites == NULL)
            return -1;
        composite->sub_composites = new_sub_composites;
        composite->capacity = new_capacity;
    }
    // 添加组件
    composite->sub_composites[composite->count] = component;
    composite->count++;
    return composite->count;
}

// 移除组件
static bool Composite_remove(struct IComponent *self, struct IComponent *component)
{
    if (self->base.is_leaf)
        return false;
    Composite *composite = (Composite *)self;
    for (int i = 0; i < composite->count; i++)
    {
        if (composite->sub_composites[i] == component)
        {
            for (int j = i; j < composite->count - 1; j++)
                composite->sub_composites[j] = composite->sub_composites[j + 1];
            composite->count--;
            return true;
        }
    }
    return false;
}

// 获取子组件
static struct IComponent *Composite_get_child(struct IComponent *self, int index)
{
    Composite *composite = (Composite *)self;
    if (index < 0 || index >= composite->count)
        return NULL;
    return composite->sub_composites[index];
}

// 销毁组合
static void IComposite_destroy(IComponent *self)
{
    free(self);
}
void Composite_destroy(Composite *composite)
{
    if (composite->sub_composites != NULL)
    {
        for (int i = 0; i < composite->count; i++)
        {
            if (composite->sub_composites[i]->base.is_leaf)
                IComposite_destroy(composite->sub_composites[i]);
            else
                Composite_destroy((Composite *)composite->sub_composites[i]);
        }
        composite->sub_composites = NULL;
        composite->count = 0;
        composite->capacity = 0;
    }
    free(composite);
}

// 初始化组合
void Composite_init(Composite *composite, bool is_leaf)
{
    composite->base.base.is_leaf = is_leaf;
    composite->sub_composites = NULL;
    composite->count = 0;
    composite->capacity = 0;
    // 初始化接口方法
    composite->base.base.operation = ILeaf_operation; // 默认实现
    composite->base.operation = Composite_operation;
    composite->base.add = Composite_add;
    composite->base.remove = Composite_remove;
    composite->base.get_child = Composite_get_child;
}
