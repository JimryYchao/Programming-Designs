#include "implementor.h"

static const char* color_to_string(Color color) {
    switch (color) {
        case RED:
            return "red";
        case GREEN:
            return "green";
        case BLUE:
            return "blue";
        default:
            return "unknown";
    }
}

// 填充方法
static void Shape_fill(DrawAPI* self, Color color) {
    printf("Fill with %s\n", color_to_string(color));
}

// Circle
static void Circle_draw(DrawAPI* self) {
    printf("Draw a Circle\n");
}
DrawAPI* Circle_init(Circle* circle) {
    circle->base.draw = Circle_draw;
    circle->base.fill = Shape_fill;
    return &circle->base;
}

// Square
static void Square_draw(DrawAPI* self) {
    printf("Draw a Square\n");
}
DrawAPI* Square_init(Square* square) {
    square->base.draw = Square_draw;
    square->base.fill = Shape_fill;
    return &square->base;
}

// Rectangle
static void Rectangle_draw(DrawAPI* self) {
    printf("Draw a Rectangle\n");
}
DrawAPI* Rectangle_init(Rectangle* rectangle) {
    rectangle->base.draw = Rectangle_draw;
    rectangle->base.fill = Shape_fill;
    return &rectangle->base;
}

// BigCircle
static void BigCircle_draw(DrawAPI* self) {
    printf("Draw a Big Circle\n");
}
DrawAPI* BigCircle_init(BigCircle* bigCircle) {
    Circle_init(&bigCircle->base);
    bigCircle->base.base.draw = BigCircle_draw;
    return &bigCircle->base.base;
}
