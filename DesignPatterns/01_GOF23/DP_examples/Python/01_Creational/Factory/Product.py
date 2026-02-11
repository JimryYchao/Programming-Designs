from abc import ABC, abstractmethod

# 产品接口
class IShape(ABC):
    @abstractmethod
    def draw(self):
        pass
    
    @abstractmethod
    def fill(self):
        pass

# 产品类型枚举
class ShapeKind:
    NoneType = 0
    Circle = 1
    Square = 2
    Rectangle = 3
    BigCircle = 4

# 圆形产品
class Circle(IShape):
    def draw(self):
        print("Draw a Circle")
    
    def fill(self):
        print("Fill red")

# 正方形产品
class Square(IShape):
    def draw(self):
        print("Draw a Square")
    
    def fill(self):
        print("Fill Green")

# 矩形产品
class Rectangle(IShape):
    def draw(self):
        print("Draw a Rectangle")
    
    def fill(self):
        print("Fill Blue")

# 未知形状产品
class UnknownShape(IShape):
    def draw(self):
        pass
    
    def fill(self):
        pass
