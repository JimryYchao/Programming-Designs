#ifndef STRATEGY_HPP
#define STRATEGY_HPP

// 策略接口
class IStrategy {
public:
    virtual ~IStrategy() {}
    virtual void sort(int* array, int length) = 0;
};

#endif // STRATEGY_HPP
