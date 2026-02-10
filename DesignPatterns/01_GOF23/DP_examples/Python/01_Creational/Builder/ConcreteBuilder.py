from Builder import IBuilder, IMealBuilder, Item
from Product import (
    Burger,
    ColdDrink,
    ItemKind,
    VegetableBurger,
    ChickenBurger,
    CokeCola,
    PepsiCola,
)
from typing import Type, List


# 汉堡建造者
class BurgerBuilder(IBuilder):
    def __init__(self, burger_class: Type[Burger]):
        self.burger_class = burger_class

    def Build(self):
        return self.burger_class()


# 冷饮建造者
class ColdDrinkBuilder(IBuilder):
    def __init__(self, drink_class: Type[ColdDrink]):
        self.drink_class = drink_class

    def Build(self):
        return self.drink_class()


# 鸡肉套餐建造者
class ChickenMealBuilder(IMealBuilder):
    _instance = None

    def GetInstance(self):
        if self._instance is None:
            self._instance = ChickenMealBuilder()
        return self._instance

    def GetBuilders(self) -> List[IBuilder]:
        return [BurgerBuilder(ChickenBurger), ColdDrinkBuilder(PepsiCola)]


# 素食套餐建造者
class VegMealBuilder(IMealBuilder):
    _instance = None

    def GetInstance(self):
        if self._instance is None:
            self._instance = VegMealBuilder()
        return self._instance

    def GetBuilders(self) -> List[IBuilder]:
        return [BurgerBuilder(VegetableBurger), ColdDrinkBuilder(CokeCola)]


class MealBuilder:
 

    def __init__(self, builders: List[IBuilder]):
        self._builders: List[IBuilder] = builders
        self._items: List[Item] = []

    def Add(self, kind: ItemKind):
        match kind:
            case ItemKind.VegetableBurger:
                self._builders.append(BurgerBuilder(VegetableBurger))
            case ItemKind.ChickenBurger:
                self._builders.append(BurgerBuilder(ChickenBurger))
            case ItemKind.CokeCola:
                self._builders.append(ColdDrinkBuilder(CokeCola))
            case ItemKind.PepsiCola:
                self._builders.append(ColdDrinkBuilder(PepsiCola))

    def Remove(self, kind: ItemKind):
        for builder in self._builders:
            if isinstance(builder, BurgerBuilder) and builder.burger_class.__name__ == kind.name:
                self._builders.remove(builder)
            elif isinstance(builder, ColdDrinkBuilder) and builder.drink_class.__name__ == kind.name:
                self._builders.remove(builder)

    def Build(self):
        for builder in self._builders:
            self._items.append(builder.Build())

    def Pack(self):
        for item in self._items:
            item.Packer.Pack(item)

    def GetCost(self) -> float:
        return sum(item.Price for item in self._items)
