// Director.h
// 指挥者

#pragma once
#include "ConcreteBuilder.h"

// 指挥者
typedef struct Director {
    IMealBuilder* meal_builder;
    MealBuilder* (*Construct)(struct Director* self);
    void (*Destroy)(struct Director* self);
} Director;

Director* Director_Create(IMealBuilder* meal_builder);
