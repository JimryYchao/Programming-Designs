#include "concrete_component.h"
#include "decorator.h"
#include "stdio.h"

int main() {
    IShape circle, rectangle;
    ShapeDecorator circle_d, rectangle_d;

    ShapeDecorator *red_circle = ShapeDecorator_create(&circle_d, circle_create(&circle));
    red_circle->draw(red_circle);
    red_circle->fill(red_circle, RED);

    ShapeDecorator *blue_rectangle = ShapeDecorator_create(&rectangle_d, rectangle_create(&rectangle));
    blue_rectangle->draw(blue_rectangle);
    blue_rectangle->fill(blue_rectangle, BLUE);
}

// gcc client.c concrete_component.c decorator.c -o client