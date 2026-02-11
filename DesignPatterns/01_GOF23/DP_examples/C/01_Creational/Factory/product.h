#ifndef PRODUCT_H
#define PRODUCT_H

// 产品类型枚举
typedef enum ShapeKind {
    NONE,
    CIRCLE,
    SQUARE,
    RECTANGLE,
    BIG_CIRCLE
} ShapeKind;

// 产品接口结构体
typedef struct IShape {
    void (*draw)(struct IShape* self);
    void (*fill)(struct IShape* self);
} IShape;

// 具体产品结构体
typedef struct Circle {
    IShape base;
} Circle;

typedef struct Square {
    IShape base;
} Square;

typedef struct Rectangle {
    IShape base;
} Rectangle;

typedef struct UnknownShape {
    IShape base;
} UnknownShape;

// 构造函数
Circle* createCircle();
Square* createSquare();
Rectangle* createRectangle();
UnknownShape* createUnknownShape();

#endif // PRODUCT_H
