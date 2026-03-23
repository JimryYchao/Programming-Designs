#include "Director.h"
#include <stdio.h>

void example() {
    
    // 素食套餐
    Director* director = Director_Create(&VegMeal_Builder);
    MealBuilder* meal = director->Construct(director);

    meal->Add(meal, CHICKEN_BURGER);
    meal->Remove(meal, VEGETABLE_BURGER);
    
    meal->Build(meal);
    meal->Pack(meal);
    printf("Total Cost: %.2f\n", meal->GetCost(meal));
    director->Destroy(director);    
    meal->Destroy(meal);
}

int main() {
    example();
    return 0;
}

// gcc client.c ConcreteBuilder.c Director.c Product.c -o client