#include <stdio.h>
#include "concrete_class.h"

int main() {
    // 制作咖啡
    printf("Making coffee:\n");
    CoffeeMaker coffee;
    CoffeeMaker_init(&coffee);
    coffee.base.makeBeverage(&coffee.base);
    printf("\n");
    
    // 制作茶
    printf("Making tea:\n");
    TeaMaker tea;
    TeaMaker_init(&tea);
    tea.base.makeBeverage(&tea.base);
    
    return 0;
}

// gcc -o client client.c concrete_class.c abstract_class.c
