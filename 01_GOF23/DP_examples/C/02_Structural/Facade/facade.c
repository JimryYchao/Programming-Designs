#include "facade.h"
#include <stdlib.h>

// 构建形状
IShape *MakeShape(ShapeType shape_type, int *args, int arg_count)
{
    switch (shape_type)
    {
    case CIRCLE:
        if (arg_count >= 1)
            return (IShape *)Circle_create(args[0]);
    case RECTANGLE:
        if (arg_count >= 2)
            return (IShape *)Rectangle_create(args[0], args[1]);
    case SQUARE:
        if (arg_count >= 1)
            return (IShape *)Square_create(args[0]);
    default:
        return NULL;
    }
}