// Director.hpp
// 指挥者

#pragma once
#include "ConcreteBuilder.hpp"
#include <vector>

// Meal Builder Generator
template <typename Builder>
    requires std::is_base_of_v<IMealBuilder, Builder>
class Director
{
public:
    static MealBuilder Construct() {
        static Builder builder; // 使用局部静态变量，自动管理生命周期
        return MealBuilder(builder.GetBuilders());
    }
};
