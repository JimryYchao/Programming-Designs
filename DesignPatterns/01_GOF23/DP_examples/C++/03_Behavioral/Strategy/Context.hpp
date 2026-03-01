#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "Strategy.hpp"

// 上下文类
class Context {
private:
    IStrategy* strategy;
public:
    Context(IStrategy* strategy) : strategy(strategy) {}
    
    void setStrategy(IStrategy* strategy) {
        this->strategy = strategy;
    }
    
    void sort(int* array, int length) {
        if (strategy) {
            strategy->sort(array, length);
        }
    }
};

#endif // CONTEXT_HPP
