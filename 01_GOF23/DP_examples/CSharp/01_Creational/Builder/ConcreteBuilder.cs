namespace Creational.Builder;

public class BugerBuilder<T> : IBuilder where T : Burger, new() {
    public static readonly BugerBuilder<T> Instance = new BugerBuilder<T>();
    public Item Build() => new T();
}
public class ColdDrinkBuilder<T> : IBuilder where T : ColdDrink, new() {
    public static readonly ColdDrinkBuilder<T> Instance = new ColdDrinkBuilder<T>();
    public Item Build() => new T();
}

// meals
public class ChickenMealBuilder : IMealBuilder {
    public static readonly ChickenMealBuilder Instance = new ChickenMealBuilder();
    public List<IBuilder> GetBuilders() {
        return new() {
            BugerBuilder<ChickenBurger>.Instance,
            ColdDrinkBuilder<PepsiCola>.Instance,
        };
    }
}
public class VegMealBuilder : IMealBuilder {
    public static readonly VegMealBuilder Instance = new VegMealBuilder();

    public List<IBuilder> GetBuilders() {
        return new() {
            BugerBuilder<VegetableBurger>.Instance,
            ColdDrinkBuilder<CokeCola>.Instance,
        };
    }
}

// Meal Product
public class MealBuilder(List<IBuilder> builders) {
    private List<IBuilder> builders = builders ?? new List<IBuilder>();
    private List<Item> items = new List<Item>();
    internal void Add(ItemKind kind) => builders.Add(kind switch {
        ItemKind.VegetableBurger => BugerBuilder<VegetableBurger>.Instance,
        ItemKind.ChickenBurger => BugerBuilder<ChickenBurger>.Instance,
        ItemKind.CokeCola => ColdDrinkBuilder<CokeCola>.Instance,
        ItemKind.PepsiCola => ColdDrinkBuilder<PepsiCola>.Instance,
        _ => throw new NotImplementedException()
    });
    internal void Remove(ItemKind kind) => builders.Remove(kind switch {
        ItemKind.VegetableBurger => BugerBuilder<VegetableBurger>.Instance,
        ItemKind.ChickenBurger => BugerBuilder<ChickenBurger>.Instance,
        ItemKind.CokeCola => ColdDrinkBuilder<CokeCola>.Instance,
        ItemKind.PepsiCola => ColdDrinkBuilder<PepsiCola>.Instance,
        _ => throw new NotImplementedException()
    });

    public void Build() {
        foreach (var b in builders)
            items.Add(b.Build());
    }
    public void Pack() {
        foreach (var item in items)
            item.Packer.Pack(item);
    }
    public float GetCost() {
        float sum = 0;
        foreach (var item in items)
            sum += item.price;
        return sum;
    }
}
