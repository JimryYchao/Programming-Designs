namespace Creational;
public interface IMealBuilder {
    List<IBuilder> GetBuilders();
}
public interface IBuilder {
    Item Build();
}
public interface IPacker {
    void Pack(Item item);
}
public interface Item {
    string name { get; }
    float price { get; }
    IPacker Packer { get; }
}