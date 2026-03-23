#include <stdlib.h>
#include "Director.h"

// 指挥者实现
static MealBuilder* Director_Construct(Director* director) {
    int count = 0;
    IBuilder** builders = director->meal_builder->GetBuilders(&count);
    return MealBuilder_Create(builders, count);
}

static void Director_Destroy(Director* director) {
    if (director) {
        free(director);
    }
}

Director* Director_Create(IMealBuilder* meal_builder) {
    Director* director = (Director*)malloc(sizeof(Director));
    director->meal_builder = meal_builder;
    director->Construct = Director_Construct;
    director->Destroy = Director_Destroy;
    return director;
}   