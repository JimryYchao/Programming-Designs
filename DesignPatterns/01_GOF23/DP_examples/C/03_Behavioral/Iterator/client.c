#include "concrete_aggregate.h"
#include <stdio.h>
#include <stdlib.h>

// 迭代器引擎
void IteratorEngine_Execute(IAggregate* aggregate, void (*action)(void*)) {
    Iterator* iterator = aggregate->iterable.GetIterator((Iterable*)aggregate);
    if (iterator) {
        iterator->First(iterator);
        while (!iterator->IsDone(iterator)) {
            void* item = iterator->CurrentItem(iterator);
            if (item) {
                action(item);
            }
            iterator->Next(iterator);
        }
        iterator->Destroy(iterator);
    }
}

// 测试函数
void PrintInt(void* item) {
    int* value = (int*)item;
    printf("Print : number >> %d\n", *value);
}

int main() {
    // 创建聚合对象
    ConcreteAggregate* aggregate = CreateConcreteAggregate(4);
    if (!aggregate) {
        printf("Failed to create aggregate\n");
        return 1;
    }
    
    // 添加元素
    int* values = (int*)malloc(6 * sizeof(int));
    if (values) {
        for (int i = 0; i < 6; i++) {
            values[i] = i + 1;
            aggregate->aggregate.Add((IAggregate*)aggregate, &values[i]);
        }
        
        // 执行迭代
        printf("Iterating over aggregate:\n");
        IteratorEngine_Execute((IAggregate*)aggregate, PrintInt);
        
        free(values);
    }
    
    // 释放资源
    aggregate->aggregate.Destroy((IAggregate*)aggregate);
}

// gcc -o client client.c concrete_aggregate.c