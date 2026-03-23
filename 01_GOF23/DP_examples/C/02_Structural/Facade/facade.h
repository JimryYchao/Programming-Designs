#pragma once

#include "subsystem.h"

// 形状类型枚举
typedef enum {
    CIRCLE,
    RECTANGLE,
    SQUARE
} ShapeType;

IShape* MakeShape(ShapeType shape_type, int* args, int arg_count);