namespace Creational;

internal class BuilderDemo {
    public static void Example() {
        MealBuilder mMeal = Director<VegMealBuilder>.Construct();

        mMeal.Add(ItemKind.ChickenBurger);
        mMeal.Remove(ItemKind.VegetableBurger);

        mMeal.Build();
        mMeal.Pack();
        Console.WriteLine(mMeal.GetCost());
    }
}
