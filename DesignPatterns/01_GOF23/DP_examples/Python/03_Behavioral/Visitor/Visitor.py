# 访问者接口
from abc import ABC, abstractmethod

class IComputerPartVisitor(ABC):
    @abstractmethod
    def visit_computer(self, computer):
        pass
    
    @abstractmethod
    def visit_mouse(self, mouse):
        pass
    
    @abstractmethod
    def visit_keyboard(self, keyboard):
        pass
    
    @abstractmethod
    def visit_monitor(self, monitor):
        pass
