from abc import ABC, abstractmethod

# 颜色枚举
class Color:
    UNKNOWN = 0
    RED = 1
    GREEN = 2
    BLUE = 3

    @classmethod
    def to_string(cls, color):
        if color == cls.RED:
            return "red"
        elif color == cls.GREEN:
            return "green"
        elif color == cls.BLUE:
            return "blue"
        else:
            return "unknown"

class DrawAPI(ABC):
    @abstractmethod
    def draw(self):
        pass
    
    def fill(self, color):
        print(f"Fill with {Color.to_string(color)}")

class Circle(DrawAPI):
    def draw(self):
        print("Draw a Circle")

class Square(DrawAPI):
    def draw(self):
        print("Draw a Square")

class Rectangle(DrawAPI):
    def draw(self):
        print("Draw a Rectangle")

class BigCircle(Circle):
    def draw(self):
        print("Draw a Big Circle")
