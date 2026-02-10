namespace Creational;
// 模拟复杂的内部
// IPacker
internal class Wrapper : IPacker {
    internal static IPacker Instance = new Wrapper();
    void IPacker.Pack(Item item) => Console.WriteLine("Wrapper a " + item.name);
}
internal class Bottle : IPacker {
    internal static IPacker Instance = new Bottle();
    void IPacker.Pack(Item item) => Console.WriteLine("Bottle a " + item.name);
}

// Items
public enum ItemKind {
    VegetableBurger, ChickenBurger, PepsiCola, CokeCola
}
public interface Burger : Item;
public interface ColdDrink : Item;
internal struct VegetableBurger : Burger {
    public string name => "VegetableBurger";
    public float price => 8.5f;
    public IPacker Packer => Wrapper.Instance;

}
internal struct ChickenBurger : Burger {
    public string name => "ChickenBurger";
    public float price => 15.0f;
    public IPacker Packer => Wrapper.Instance;
}
// ColdDrinks
internal struct CokeCola : ColdDrink {
    public string name => "CokeCola";
    public float price => 3.5f;
    public IPacker Packer => Bottle.Instance;
}
internal struct PepsiCola : ColdDrink {
    public string name => "PepsiCola";
    public float price => 3.0f;
    public IPacker Packer => Bottle.Instance;
}
