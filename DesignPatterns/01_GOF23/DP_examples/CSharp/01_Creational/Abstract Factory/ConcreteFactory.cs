
namespace Creational;
internal class ProductFactory<Color, Shape> : AbstractFactory
    where Color : IColor, new()
    where Shape : IShape, new() {
    public override IColor GetColor() => new Color();
    public override IShape GetShape() => new Shape();
}

public enum ProductKind {
    RedCircle,
    GreenSquare,
    BlueRectangle
}
public class FactoryProducer {
    static Dictionary<ProductKind, AbstractFactory> factorys = new Dictionary<ProductKind, AbstractFactory>();
    static AbstractFactory CreateFactory(ProductKind kind) {
        return kind switch {
            ProductKind.RedCircle => new ProductFactory<Red, Circle>(),
            ProductKind.GreenSquare => new ProductFactory<Green, Square>(),
            ProductKind.BlueRectangle => new ProductFactory<Blue, Rectangle>(),
            _ => new ProductFactory<UnknownColor, UnknownShape>()
        };
    }
    public static AbstractFactory GetFactory(ProductKind kind) {
        if (!factorys.ContainsKey(kind))
            factorys.Add(kind, CreateFactory(kind));
        return factorys[kind];
    }
}
