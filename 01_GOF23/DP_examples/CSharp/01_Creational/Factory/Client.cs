using Creational.Factory;
namespace Creational;

public class FactoryDemo {
    public static void Example() {
        var circle = ShapeFactory.GetShape(ShapeKind.Circle);
        circle.Draw();
        circle.Fill();
        
        var BigCircle = ShapeFactory.GetShape(ShapeKind.BigCircle);
        BigCircle.Draw();
        BigCircle.Fill();

        var Square = ShapeFactory.GetShape(ShapeKind.Square);
        Square.Draw();
        Square.Fill();
    }
}
