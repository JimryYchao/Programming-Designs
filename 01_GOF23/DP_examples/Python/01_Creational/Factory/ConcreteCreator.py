from Creator import UnknownShapeCreator, CircleCreator, SquareCreator, RectangleCreator, BigCircleCreator
from Product import ShapeKind

# 未知形状创建者
# 形状工厂
class ShapeFactory:
    _factories = {}
    def get_shape(kind):
        creator = ShapeFactory._get_factory(kind)
        return creator.get_shape()
    
    def _get_factory(kind):
        if kind in ShapeFactory._factories:
            return ShapeFactory._factories[kind]
        
        if kind == ShapeKind.Circle:
            creator = CircleCreator()
        elif kind == ShapeKind.Square:
            creator = SquareCreator()
        elif kind == ShapeKind.Rectangle:
            creator = RectangleCreator()
        elif kind == ShapeKind.BigCircle:
            creator = BigCircleCreator()
        else:
            creator = UnknownShapeCreator()
        
        ShapeFactory._factories[kind] = creator
        return creator
