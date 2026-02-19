from Subsystem import Circle, Rectangle, Square, IShape

# 形状类型枚举
class ShapeType:
    CIRCLE = 0
    RECTANGLE = 1
    SQUARE = 2


def build_shape(shape_type, *args) -> IShape:
    if shape_type == ShapeType.CIRCLE:
        if len(args) >= 1:
            return Circle(args[0])
    elif shape_type == ShapeType.RECTANGLE:
        if len(args) >= 2:
            return Rectangle(args[0], args[1])
    elif shape_type == ShapeType.SQUARE:
        if len(args) >= 1:
            return Square(args[0])
    return None
