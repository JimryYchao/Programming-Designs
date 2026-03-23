// Client.cpp
// 客户端代码

#include "Director.hpp"
#include <iostream>

void example() {
    // 素食套餐
    auto meal = Director<VegMealBuilder>::Construct();
    meal.Add(ItemKind::CHICKEN_BURGER);
    meal.Remove(ItemKind::VEGETABLE_BURGER);
    meal.Build();
    meal.Pack();
    std::cout << "Total Cost: " << meal.GetPrice() << std::endl;
    
    // 鸡肉套餐
    auto meal2 = Director<ChickenMealBuilder>::Construct();
    meal2.Build();
    meal2.Pack();
    std::cout << "Total Cost: " << meal2.GetPrice() << std::endl;   
}

int main() {
    example();
    return 0;
}
