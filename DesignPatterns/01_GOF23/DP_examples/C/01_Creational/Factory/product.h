#pragma once

// 产品类型枚举
#define SHAPE_KIND_COUNT  1+4

typedef enum ShapeKind {
    UNKNOWN_SHAPE = 0,
    CIRCLE,
    SQUARE,
    RECTANGLE,
    BIG_CIRCLE
} ShapeKind;

// 产品接口结构体
typedef struct IShape {
    void *data;
    void (*draw)(struct IShape* self);
    void (*fill)(struct IShape* self);
    void (*destroy)(struct IShape* self);
} IShape;
typedef  struct IShape  IShape;

// 具体产品结构体
typedef struct CircleData {} CircleData;
typedef struct SquareData {} SquareData;
typedef struct RectangleData {} RectangleData;
typedef struct UnknownShapeData {} UnknownShapeData;

IShape* createShape(ShapeKind kind);