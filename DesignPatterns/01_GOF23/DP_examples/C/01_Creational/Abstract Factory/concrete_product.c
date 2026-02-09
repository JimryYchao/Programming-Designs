// abstract_product.c
// 产品接口和具体实现

#include <stdio.h>
#include <stdlib.h>
#include "abstract_product.h"


// Colors
static Color* color_create(ColorType type);
Color * red_create(){
    return color_create(RED);
}
Color * green_create(){
    return color_create(GREEN);
}
Color * blue_create(){
    return color_create(BLUE);
}
Color * unknownColor_create(){
    return color_create(UNKNOWN_COLOR);
}
static void red_fill(Color* self) {
    // use self->data here
    printf("Fill Red\n");
}
static void green_fill(Color* self) {
    printf("Fill Green\n");
}
static void blue_fill(Color* self) {
    printf("Fill Blue\n");
}
static void unknownColor_fill(Color* self) {
    (void)self;
}
static void color_destroy(Color* self) {
    if (self && self->data) 
        free(self->data);
    if (self) 
        free(self);
}
Color* color_create(ColorType type) {
    Color* color = (Color*)malloc(sizeof(Color));
    color->destroy = color_destroy;
    switch (type) {
        case RED:
            color->Fill = red_fill;
            color->data = (RedData*)malloc(sizeof(RedData));
            break;
        case GREEN:
            color->Fill = green_fill;
            color->data = (GreenData*)malloc(sizeof(GreenData));
            break;
        case BLUE:
            color->Fill = blue_fill;
            color->data = (BlueData*)malloc(sizeof(BlueData));
            break;
        default:
            color->data = NULL;
            color->Fill = unknownColor_fill;
            break;
    }
    return color;   
}

// Shapes
static Shape* shape_create(ShapeType type);
Shape* circle_create(){
    return shape_create(CIRCLE);
}
Shape* square_create(){
    return shape_create(SQUARE);
}
Shape* rectangle_create(){
    return shape_create(RECTANGLE);
}
Shape* unknownShape_create(){
    return shape_create(UNKNOWN_SHAPE);
}
static void circle_draw(Shape* self) {
    // use self->data here
    printf("Draw a Circle\n");
}
static void square_draw(Shape* self) {
    printf("Draw a Square\n");
}
static void rectangle_draw(Shape* self) {
    printf("Draw a Rectangle\n");
}
static void unknownShape_draw(Shape* self) {
    (void)self;
}
static void shape_destroy(Shape* self) {
    if (self && self->data) 
        free(self->data);
    if (self) 
        free(self);
}
static Shape* shape_create(ShapeType type) {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    switch (type) {
        case CIRCLE:
            shape->data = (CircleData*)malloc(sizeof(CircleData));
            shape->Draw = circle_draw;
            break;
        case SQUARE:
            shape->data = (SquareData*)malloc(sizeof(SquareData));
            shape->Draw = square_draw;
            break;
        case RECTANGLE:
            shape->data = (RectangleData*)malloc(sizeof(RectangleData));
            shape->Draw = rectangle_draw;
            break;
        default:
            shape->data = NULL;
            shape->Draw = unknownShape_draw;
            break;
        }
        shape->destroy = shape_destroy;
    return shape;
}