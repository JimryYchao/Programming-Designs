#include "concrete_aggregate.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CAPACITY 4

// 具体迭代器实现
typedef struct AggregateIterator AggregateIterator;

struct AggregateIterator {
    Iterator iterator;
    ConcreteAggregate* aggregate;
    int index;
    void* currentItem;
};

// 迭代器方法实现
static void First(Iterator* iter) {
    AggregateIterator* self = (AggregateIterator*)iter;
    if (self->aggregate->size > 0) {
        self->index = 0;
        self->currentItem = self->aggregate->array[0];
    }
}

static void Next(Iterator* iter) {
    AggregateIterator* self = (AggregateIterator*)iter;
    if (self->index < self->aggregate->size) {
        self->index++;
        if (self->index < self->aggregate->size) {
            self->currentItem = self->aggregate->array[self->index];
        }
    }
}

static bool IsDone(Iterator* iter) {
    AggregateIterator* self = (AggregateIterator*)iter;
    return self->index >= self->aggregate->size;
}

static void* CurrentItem(Iterator* iter) {
    AggregateIterator* self = (AggregateIterator*)iter;
    return self->currentItem;
}

static void DestroyIterator(Iterator* iter) {
    free(iter);
}

// 创建迭代器
static Iterator* GetIterator(Iterable* iterable) {
    ConcreteAggregate* aggregate = (ConcreteAggregate*)iterable;
    AggregateIterator* iterator = (AggregateIterator*)malloc(sizeof(AggregateIterator));
    if (iterator) {
        iterator->iterator.First = First;
        iterator->iterator.Next = Next;
        iterator->iterator.IsDone = IsDone;
        iterator->iterator.CurrentItem = CurrentItem;
        iterator->iterator.Destroy = DestroyIterator;
        iterator->aggregate = aggregate;
        iterator->index = -1;
        iterator->currentItem = NULL;
    }
    return (Iterator*)iterator;
}

// 聚合方法实现
static int Count(IAggregate* agg) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    return self->size;
}

static void EnsureCapacity(ConcreteAggregate* self) {
    if (self->size >= self->capacity) {
        int newCapacity = self->capacity * 2;
        void** newArray = (void**)realloc(self->array, newCapacity * sizeof(void*));
        if (newArray) {
            self->array = newArray;
            self->capacity = newCapacity;
        }
    }
}

static void Add(IAggregate* agg, void* item) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    if (item) {
        EnsureCapacity(self);
        self->array[self->size++] = item;
    }
}

static bool Remove(IAggregate* agg, void* item) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    if (!item) return false;
    
    for (int i = 0; i < self->size; i++) {
        if (self->array[i] == item) {
            if (i < self->size - 1) {
                memmove(&self->array[i], &self->array[i + 1], (self->size - i - 1) * sizeof(void*));
            }
            self->size--;
            return true;
        }
    }
    return false;
}

static bool Contains(IAggregate* agg, void* item) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    if (!item) return false;
    
    for (int i = 0; i < self->size; i++) {
        if (self->array[i] == item) {
            return true;
        }
    }
    return false;
}

static void Clear(IAggregate* agg) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    self->size = 0;
}

static void Destroy(IAggregate* agg) {
    ConcreteAggregate* self = (ConcreteAggregate*)agg;
    free(self->array);
    free(self);
}

// 创建具体聚合对象
ConcreteAggregate* CreateConcreteAggregate(int capacity) {
    if (capacity < DEFAULT_CAPACITY) {
        capacity = DEFAULT_CAPACITY;
    }
    
    ConcreteAggregate* aggregate = (ConcreteAggregate*)malloc(sizeof(ConcreteAggregate));
    if (aggregate) {
        aggregate->array = (void**)malloc(capacity * sizeof(void*));
        if (aggregate->array) {
            aggregate->size = 0;
            aggregate->capacity = capacity;
            
            // 初始化接口
            aggregate->aggregate.iterable.GetIterator = GetIterator;
            aggregate->aggregate.Count = Count;
            aggregate->aggregate.Add = Add;
            aggregate->aggregate.Remove = Remove;
            aggregate->aggregate.Contains = Contains;
            aggregate->aggregate.Clear = Clear;
            aggregate->aggregate.Destroy = Destroy;
        } else {
            free(aggregate);
            aggregate = NULL;
        }
    }
    return aggregate;
}
