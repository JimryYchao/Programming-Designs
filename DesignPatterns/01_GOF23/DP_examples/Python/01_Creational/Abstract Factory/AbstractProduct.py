"""
AbstractProduct.py
产品接口和具体实现
"""

from abc import ABC, abstractmethod

# 产品接口
class IColor(ABC):
    @abstractmethod
    def Fill(self):
        pass

class IShape(ABC):
    @abstractmethod
    def Draw(self):
        pass

# 具体产品 - 颜色
class Red(IColor):
    def Fill(self):
        print("Fill Red")
class Green(IColor):
    def Fill(self):
        print("Fill Green")
class Blue(IColor):
    def Fill(self):
        print("Fill Blue")
class UnknownColor(IColor):
    def Fill(self):
        pass

# 具体产品 - 形状
class Circle(IShape):
    def Draw(self):
        print("Draw a Circle")
class Square(IShape):
    def Draw(self):
        print("Draw a Square")
class Rectangle(IShape):
    def Draw(self):
        print("Draw a Rectangle")
class UnknownShape(IShape):
    def Draw(self):
        pass
