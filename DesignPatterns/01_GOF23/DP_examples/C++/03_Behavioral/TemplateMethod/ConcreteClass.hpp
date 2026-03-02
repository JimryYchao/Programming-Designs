#ifndef CONCRETE_CLASS_HPP
#define CONCRETE_CLASS_HPP

#include "AbstractClass.hpp"

// 咖啡制作类
class CoffeeMaker : public BeverageMaker {
protected:
    // 实现冲泡方法
    void brew() override {
        std::cout << "Brewing coffee grounds" << std::endl;
    }
    
    // 实现添加调料方法
    void addCondiments() override {
        std::cout << "Adding sugar and milk" << std::endl;
    }
    
    // 重写钩子方法
    bool customerWantsCondiments() override {
        std::cout << "Customer wants sugar and milk" << std::endl;
        return true;
    }
};

// 茶制作类
class TeaMaker : public BeverageMaker {
protected:
    // 实现冲泡方法
    void brew() override {
        std::cout << "Steeping the tea bag" << std::endl;
    }
    
    // 实现添加调料方法
    void addCondiments() override {
        std::cout << "Adding lemon" << std::endl;
    }
    
    // 重写钩子方法
    bool customerWantsCondiments() override {
        std::cout << "Customer wants lemon" << std::endl;
        return true;
    }
};

#endif // CONCRETE_CLASS_HPP
