#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Product.h"

// 包装器实现
static void wrapper_pack(Burger* item) {
    printf("Wrapper a %s\n", item->Name);
}

static void bottle_pack(ColdDrink* item) {
    printf("Bottle a %s\n", item->Name);
}

// 包装器实例
static IPacker Wrapper_Instance = { wrapper_pack };
static IPacker Bottle_Instance = { bottle_pack };


// 产品实例
Burger VegetableBurger = {
    "VegetableBurger",
    8.5f,
    &Wrapper_Instance
};

Burger ChickenBurger = {
    "ChickenBurger",
    15.0f,
    &Wrapper_Instance
};

ColdDrink CokeCola = {
    "CokeCola",
    3.5f,
    &Bottle_Instance
};

ColdDrink PepsiCola = {
    "PepsiCola",
    3.0f,
    &Bottle_Instance
};


static void Item_destroy(Item* self) {
    if (self) {
        free(self);
    }
}
Item* Item_create(ItemKind kind) {
    Item* item = malloc(sizeof(Item));
    if (item) {
        switch (kind) {
            case VEGETABLE_BURGER:
                memcpy_s(item, sizeof(Burger), &VegetableBurger, sizeof(Burger));
                item->destroy = Item_destroy;
                break;
            case CHICKEN_BURGER:
                memcpy_s(item, sizeof(Burger), &ChickenBurger, sizeof(Burger));
                item->destroy = Item_destroy;
                break;
            case COKE_COLA:
                memcpy_s(item, sizeof(ColdDrink), &CokeCola, sizeof(ColdDrink));
                item->destroy = Item_destroy;   
                break;
            case PEPSI_COLA:
                memcpy_s(item, sizeof(ColdDrink), &PepsiCola, sizeof(ColdDrink));
                item->destroy = Item_destroy;
                break;
        }
    }
    return item;
} 

