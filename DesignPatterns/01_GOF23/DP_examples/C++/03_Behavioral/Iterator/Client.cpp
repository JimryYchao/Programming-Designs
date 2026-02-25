#include "ConcreteAggregate.hpp"
#include <iostream>
#include <functional>

// 迭代器引擎
class IteratorEngine {
public:
    template <typename T>
    static void Execute(IAggregate<T>* aggregate, std::function<void(const T&)> action) {
        Iterator<T>* iterator = aggregate->GetIterator();
        if (iterator) {
            iterator->First();
            while (!iterator->IsDone()) {
                T item = iterator->CurrentItem();
                action(item);
                iterator->Next();
            }
            delete iterator;
        }
    }
};

int main() {
    // 创建聚合对象
    ConcreteAggregate<int>* aggregate = new ConcreteAggregate<int>();
    
    // 添加元素
    aggregate->Add(1);
    aggregate->Add(2);
    aggregate->Add(3);
    aggregate->Add(4);
    // 校验扩容
    aggregate->Add(5);
    aggregate->Add(6);
    
    // 执行迭代
    std::cout << "Iterating over aggregate:" << std::endl;
    IteratorEngine::Execute<int>(aggregate, [](const int& a) {
        std::cout << "Print : number >> " << a << std::endl;
    });
    
    // 释放资源
    delete aggregate;
}
