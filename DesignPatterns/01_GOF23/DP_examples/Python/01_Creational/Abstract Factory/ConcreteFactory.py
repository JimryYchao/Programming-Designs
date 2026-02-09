"""
ConcreteFactory.py
具体工厂和工厂生产者
"""

from AbstractProduct import Red, Green, Blue, Circle, Square, Rectangle, UnknownColor, UnknownShape
from AbstractFactory import AbstractFactory
from enum import Enum

# 具体工厂
class ProductFactory(AbstractFactory):
    def __init__(self, color, shape):
        self.color = color
        self.shape = shape
    
    def GetColor(self):
        return self.color()
    
    def GetShape(self):
        return self.shape()

# 工厂生产者
class ProductKind(Enum):
    RedCircle = 1
    GreenSquare = 2
    BlueRectangle = 3

class FactoryProducer:
    def __init__(self):
        self.factories = {}
    
    def createFactory(self, kind):
        if kind == ProductKind.RedCircle:
            return ProductFactory(Red, Circle)
        elif kind == ProductKind.GreenSquare:
            return ProductFactory(Green, Square)
        elif kind == ProductKind.BlueRectangle:
            return ProductFactory(Blue, Rectangle)
        else:
            return ProductFactory(UnknownColor, UnknownShape) 
    
    def GetFactory(self, kind):
        if kind not in self.factories:
            self.factories[kind] = self.createFactory(kind)
        return self.factories[kind]
