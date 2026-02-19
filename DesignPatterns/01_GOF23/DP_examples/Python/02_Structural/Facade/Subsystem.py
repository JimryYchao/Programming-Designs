from abc import ABC, abstractmethod

# 形状接口
class IShape(ABC):
    @abstractmethod
    def draw(self):
        pass

# 圆形实现
class Circle(IShape):
    def __init__(self, radius):
        self.radius = radius
    
    def draw(self):
        print(f"Draw a circle with radius {self.radius}")

# 矩形实现
class Rectangle(IShape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def draw(self):
        print(f"Draw a rectangle with width {self.width} and height {self.height}")

# 正方形实现
class Square(IShape):
    def __init__(self, side):
        self.side = side
    
    def draw(self):
        print(f"Draw a square with side {self.side}")
