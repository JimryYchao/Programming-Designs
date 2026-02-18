#pragma once

typedef enum {
    UNKNOWN,
    RED,
    GREEN,
    BLUE
} Color;


typedef struct IShape IShape;

struct IShape {
    void (*draw)(IShape* self);
    void (*fill)(IShape* self, Color color);
};
