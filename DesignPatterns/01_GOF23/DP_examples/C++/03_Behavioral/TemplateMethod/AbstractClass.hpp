#ifndef ABSTRACT_CLASS_HPP
#define ABSTRACT_CLASS_HPP

#include <iostream>

// 饮料制作抽象类
class BeverageMaker {
public:
    // 模板方法：制作饮料的流程
    void makeBeverage() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }
    
protected:
    // 具体方法：烧水
    void boilWater() {
        std::cout << "Boiling water" << std::endl;
    }
    
    // 具体方法：倒入杯子
    void pourInCup() {
        std::cout << "Pouring into cup" << std::endl;
    }
    
    // 抽象方法：冲泡
    virtual void brew() = 0;
    
    // 抽象方法：添加调料
    virtual void addCondiments() = 0;
    
    // 钩子方法：顾客是否需要调料
    virtual bool customerWantsCondiments() {
        return true;
    }
};

#endif // ABSTRACT_CLASS_HPP
