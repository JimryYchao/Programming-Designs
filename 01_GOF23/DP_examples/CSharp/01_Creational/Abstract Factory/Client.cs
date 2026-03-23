using Creational.AbstractFactory;
namespace Creational;

internal class AbstractFactoryDemo {
    static void DrawShape(AbstractFactory.AbstractFactory ab) {
        var shape = ab.GetShape();
        var color = ab.GetColor();
        shape?.Draw();
        color?.Fill();
    }
    public static void Example() {
        var redCircleF = FactoryProducer.GetFactory(ProductKind.RedCircle);
        DrawShape(redCircleF);

        DrawShape(FactoryProducer.GetFactory(ProductKind.BlueRectangle));
    }
}