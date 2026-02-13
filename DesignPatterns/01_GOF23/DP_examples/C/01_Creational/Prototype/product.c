#include "product.h"

const char* color_to_string(Color color) {
    switch (color) {
        case Red:
            return "Red";
        case Green:
            return "Green";
        case Blue:
            return "Blue";
        case Yellow:
            return "Yellow";
        default:
            return "Unknown";
    }
}

void shape_init(Shape* self, int id, const char* name) {
    self->base.id = id;
    strcpy_s(self->base.name, sizeof(self->base.name), name);
    self->base.draw = shape_draw;
    self->base.fill = shape_fill;
    self->base.clone = NULL;
    self->base.destroy = shape_destroy;
}

const char* shape_name(IShape* self) {
    return self->name;
}

void shape_draw(IShape* self) {
    // 空实现
}

void shape_fill(IShape* self, Color color) {
    // 空实现
}

void shape_destroy(IShape* self) {
    if (self) {
        free(self);
    }
}

Circle* circle_create() {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    if (circle) {
        shape_init(&circle->base, ShapeCircle, "Circle");
        circle->base.base.draw = circle_draw;
        circle->base.base.fill = circle_fill;
        circle->base.base.clone = circle_clone;
        circle->base.base.destroy = circle_destroy;
    }
    return circle;
}

void circle_draw(IShape* self) {
    printf("Draw a Circle\n");
}

void circle_fill(IShape* self, Color color) {
    printf("Fill with %s\n", color_to_string(color));
}

IShape* circle_clone(IShape* self) {
    Circle* circle = circle_create();
    if (circle) {
        circle->base.base.id = self->id;
        strcpy_s(circle->base.base.name, sizeof(circle->base.base.name), self->name);
    }
    return (IShape*)circle;
}

void circle_destroy(IShape* self) {
    if (self) {
        free(self);
    }
}

Square* square_create() {
    Square* square = (Square*)malloc(sizeof(Square));
    if (square) {
        shape_init(&square->base, ShapeSquare, "Square");
        square->base.base.draw = square_draw;
        square->base.base.fill = square_fill;
        square->base.base.clone = square_clone;
        square->base.base.destroy = square_destroy;
    }
    return square;
}

void square_draw(IShape* self) {
    printf("Draw a Square\n");
}

void square_fill(IShape* self, Color color) {
    printf("Fill with %s\n", color_to_string(color));
}

IShape* square_clone(IShape* self) {
    Square* square = square_create();
    if (square) {
        square->base.base.id = self->id;
        strcpy_s(square->base.base.name, sizeof(square->base.base.name), self->name);
    }
    return (IShape*)square;
}

void square_destroy(IShape* self) {
    if (self) {
        free(self);
    }
}

Rectangle* rectangle_create() {
    Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    if (rectangle) {
        shape_init(&rectangle->base, ShapeRectangle, "Rectangle");
        rectangle->base.base.draw = rectangle_draw;
        rectangle->base.base.fill = rectangle_fill;
        rectangle->base.base.clone = rectangle_clone;
        rectangle->base.base.destroy = rectangle_destroy;
    }
    return rectangle;
}

void rectangle_draw(IShape* self) {
    printf("Draw a Rectangle\n");
}

void rectangle_fill(IShape* self, Color color) {
    printf("Fill with %s\n", color_to_string(color));
}

IShape* rectangle_clone(IShape* self) {
    Rectangle* rectangle = rectangle_create();
    if (rectangle) {
        rectangle->base.base.id = self->id;
        strcpy_s(rectangle->base.base.name, sizeof(rectangle->base.base.name), self->name);
    }
    return (IShape*)rectangle;
}

void rectangle_destroy(IShape* self) {
    if (self) {
        free(self);
    }
}
