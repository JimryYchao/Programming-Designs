from abc import abstractmethod, ABC
from enum import Enum

class Color(Enum):
    unknown = 0
    red = 1
    green = 2
    blue = 3


class IShape(ABC):
    @abstractmethod
    def draw(self): 
        pass
    
    @abstractmethod
    def fill(self, color: Color):
        pass
