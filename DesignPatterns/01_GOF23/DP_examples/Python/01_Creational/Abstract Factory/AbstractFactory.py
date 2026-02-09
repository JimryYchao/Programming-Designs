"""
AbstractFactory.py
"""

from abc import ABC, abstractmethod

class AbstractFactory(ABC):
    @abstractmethod
    def GetColor(self):
        pass
    
    @abstractmethod
    def GetShape(self):
        pass
