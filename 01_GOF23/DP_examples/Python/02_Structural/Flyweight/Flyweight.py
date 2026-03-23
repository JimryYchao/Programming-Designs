from abc import ABC, abstractmethod

# 形状接口
class IShape(ABC):
    @abstractmethod
    def draw(self):
        pass
    
    @abstractmethod
    def fill(self):
        pass

# 圆形数据
class CircleData:
    def __init__(self, color, radius):
        self.color = color
        self.radius = radius

# 圆形实现
class Circle(IShape):
    def __init__(self, data: CircleData, x: float, y: float):
        self.data = data
        self.x = x
        self.y = y
    
    def draw(self):
        print(f"Draw a Circle with radius {self.data.radius:.2f} at ({self.x:.2f}, {self.y:.2f})")
    
    def fill(self):
        print(f"Fill with {self.data.color}")

