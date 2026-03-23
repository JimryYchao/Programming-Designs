#include "concrete_component.h"
#include <stdio.h>
#include <stdlib.h>

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
static void circle_draw(Circle* self) {
    printf("Draw a Circle.\n");
}
static void circle_fill(Circle* self, Color color) {
    printf("Fill with %s.\n", color_to_string(color));
}
static void rectangle_draw(Rectangle* self) {
    printf("Draw a Rectangle.\n");
}

static void rectangle_fill(Rectangle* self, Color color) {
    printf("Fill with %s.\n", color_to_string(color));
}

Circle* circle_create(IShape* self) {
    self->draw = circle_draw;
    self->fill = circle_fill;
    return self;
}

Rectangle* rectangle_create(IShape* self) {
    self->draw = rectangle_draw;
    self->fill = rectangle_fill;
    return self;
}