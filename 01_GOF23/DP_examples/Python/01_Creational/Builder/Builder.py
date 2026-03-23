from abc import ABC, abstractmethod


class IMealBuilder(ABC):
    @abstractmethod
    def GetBuilders(self):
        pass


class IBuilder(ABC):
    @abstractmethod
    def Build(self):
        pass


class IPacker(ABC):
    @abstractmethod
    def Pack(self, item):
        pass


class Item(ABC):
    @abstractmethod
    def __init__(self, name, price, packer):
        self.Name = name
        self.Price = price
        self.Packer = packer
