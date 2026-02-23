# 命令接口
from abc import ABC, abstractmethod


class ICommand(ABC):
    @abstractmethod
    def execute(self):
        pass


class ConcreteCommand(ICommand):
    def __init__(self, receiver):
        self.receiver = receiver
    
    def execute(self):
        if self.receiver:
            self.receiver.action()
