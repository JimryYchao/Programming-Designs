from abc import abstractmethod
from Builder import IPacker, Item
import enum


# 包装器
class Wrapper(IPacker):
    _instance = None
    def GetInstance():
        if Wrapper._instance is None:
            Wrapper._instance = Wrapper()
        return Wrapper._instance

    def Pack(self, item):
        print(f"Wrapper a {item.Name}")


class Bottle(IPacker):
    _instance = None

    def GetInstance():
        if Bottle._instance is None:
            Bottle._instance = Bottle()
        return Bottle._instance

    def Pack(self, item):
        print(f"Bottle a {item.Name}")


# Item 实现
@enum.unique
class ItemKind(enum.Enum):
    VegetableBurger = 1
    ChickenBurger = 2
    CokeCola = 3
    PepsiCola = 4


class Burger(Item):
    @abstractmethod
    def __init__(self, name, price, packer):
        super().__init__(name, price, packer)

class ColdDrink(Item):
    @abstractmethod
    def __init__(self, name, price, packer):
        super().__init__(name, price, packer)

class VegetableBurger(Burger):
    def __init__(self):
        super().__init__("VegetableBurger", 8.5, Wrapper.GetInstance())


class ChickenBurger(Burger):
    def __init__(self):
        super().__init__("ChickenBurger", 15.0, Wrapper.GetInstance())


class CokeCola(ColdDrink):
    def __init__(self):
        super().__init__("CokeCola", 3.5, Bottle.GetInstance())


class PepsiCola(ColdDrink):
    def __init__(self):
        super().__init__("PepsiCola", 3.0, Bottle.GetInstance())
