#include "ConcreteClass.hpp"

int main() {
    // 制作咖啡
    std::cout << "Making coffee:" << std::endl;
    CoffeeMaker coffee;
    coffee.makeBeverage();
    std::cout << std::endl;
    
    // 制作茶
    std::cout << "Making tea:" << std::endl;
    TeaMaker tea;
    tea.makeBeverage();
}
