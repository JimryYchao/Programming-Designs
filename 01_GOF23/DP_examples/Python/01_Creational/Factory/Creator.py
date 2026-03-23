from abc import ABC, abstractmethod
from Product import UnknownShape, Circle, Square, Rectangle

# 创建者接口
class ICreator(ABC):
    @abstractmethod
    def get_shape(self):
        pass

class UnknownShapeCreator(ICreator):
    def get_shape(self):
        return UnknownShape()

# 圆形创建者
class CircleCreator(ICreator):
    def get_shape(self):
        return Circle()

# 正方形创建者
class SquareCreator(ICreator):
    def get_shape(self):
        return Square()

# 矩形创建者
class RectangleCreator(ICreator):
    def get_shape(self):
        return Rectangle()

# 大圆形创建者
class BigCircleCreator(CircleCreator):
    def _set_radius(self, circle):
        print("Set Radius to 10")
        return circle
    
    def get_shape(self):
        return self._set_radius(super().get_shape())


