# 元素接口
from abc import ABC, abstractmethod

class IComputerPart(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass

# 具体元素：Keyboard
class Keyboard(IComputerPart):
    def accept(self, visitor):
        visitor.visit_keyboard(self)
    
    def operation(self):
        print("Using Keyboard")

# 具体元素：Monitor
class Monitor(IComputerPart):
    def accept(self, visitor):
        visitor.visit_monitor(self)
    
    def operation(self):
        print("Using Monitor")

# 具体元素：Mouse
class Mouse(IComputerPart):
    def accept(self, visitor):
        visitor.visit_mouse(self)
    
    def operation(self):
        print("Using Mouse")

# 具体元素：Computer (ObjectStructure)
class Computer(IComputerPart):
    def __init__(self):
        self.parts = [
            Keyboard(),
            Mouse(),
            Monitor()
        ]
    
    def accept(self, visitor):
        for part in self.parts:
            part.accept(visitor)
        visitor.visit_computer(self)
