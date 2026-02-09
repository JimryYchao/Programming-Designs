// abstract_product.h
// 产品接口
#pragma once

typedef enum ColorType {
    RED,
    GREEN,
    BLUE,
    UNKNOWN_COLOR,
} ColorType;
typedef enum ShapeType {
    CIRCLE,
    SQUARE,
    RECTANGLE,
    UNKNOWN_SHAPE,
} ShapeType;

// IColor
typedef struct Color {
    void* data;
    void (*Fill)(struct Color* self);
    void (*destroy)(struct Color* self);
} Color;

typedef struct {
    // Red 特定数据
} RedData;
typedef struct {
    // Green 特定数据
} GreenData;
typedef struct {
    // Blue 特定数据
} BlueData;
Color * red_create();
Color * green_create();
Color * blue_create();
Color * unknownColor_create();    

// IShape
typedef struct Shape {
    void* data;
    void (*Draw)(struct Shape* self);
    void (*destroy)(struct Shape* self);
} Shape;

// Circle 实现
typedef struct {
    // Circle 特定数据
} CircleData;
typedef struct {
    // Rectangle 特定数据
} RectangleData;
typedef struct {
    // Square 特定数据
} SquareData;
Shape * circle_create();
Shape * rectangle_create();
Shape * square_create();
Shape * unknownShape_create();
