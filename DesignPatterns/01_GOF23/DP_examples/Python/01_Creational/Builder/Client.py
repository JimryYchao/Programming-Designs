from ConcreteBuilder import VegMealBuilder, ChickenMealBuilder, ItemKind
from Director import Director

def BuilderDemo():
    meal = Director(VegMealBuilder()).Construct()
    meal.Add(ItemKind.ChickenBurger)
    meal.Remove(ItemKind.VegetableBurger)
    
    meal.Build()
    meal.Pack()
    print(f"Total Cost: {meal.GetCost()}\n")

    meal = Director(ChickenMealBuilder()).Construct()
    meal.Add(ItemKind.CokeCola)
    meal.Add(ItemKind.PepsiCola)
    
    meal.Build()
    meal.Pack()
    print(f"Total Cost: {meal.GetCost()}")

if __name__ == "__main__":
    BuilderDemo()
