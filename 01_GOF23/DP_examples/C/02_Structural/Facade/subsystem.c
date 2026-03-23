#include "subsystem.h"
#include <stdlib.h>

// 圆形绘制方法
static void Circle_draw(IShape* self) {
    Circle* circle = (Circle*)self;
    printf("Draw a circle with radius %d\n", circle->radius);
}
static void Circle_destroy(IShape* self) {
    Circle* circle = (Circle*)self;
    free(circle);
}

// 初始化圆形
Circle* Circle_create(int radius) {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    if (circle) {
        circle->base.draw = Circle_draw;
        circle->radius = radius;
        circle->base.destroy = Circle_destroy;
    }
    return circle;
}

// 矩形绘制方法
static void Rectangle_draw(IShape* self) {
    Rectangle* rectangle = (Rectangle*)self;
    printf("Draw a rectangle with width %d and height %d\n", rectangle->width, rectangle->height);
}
static void Rectangle_destroy(IShape* self) {
    Rectangle* rectangle = (Rectangle*)self;
    free(rectangle);
}

// 初始化矩形
Rectangle* Rectangle_create(int width, int height) {
    Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    if (rectangle) {
        rectangle->base.draw = Rectangle_draw;
        rectangle->width = width;
        rectangle->height = height;
        rectangle->base.destroy = Rectangle_destroy;
    }
    return rectangle;
}

// 正方形绘制方法
static void Square_draw(IShape* self) {
    Square* square = (Square*)self;
    printf("Draw a square with side %d\n", square->side);
}
static void Square_destroy(IShape* self) {
    Square* square = (Square*)self;
    free(square);
}

// 初始化正方形
Square* Square_create(int side) {
    Square* square = (Square*)malloc(sizeof(Square));
    if (square) {
        square->base.draw = Square_draw;
        square->side = side;
        square->base.destroy = Square_destroy;
    }
    return square;
}


