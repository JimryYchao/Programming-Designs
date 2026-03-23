using Structural.Decorator;
namespace Structural;

public class DecoratorDemo {
    public static void Example() {
        IShape RedCircle = new ShapeDecorator(new Circle());
        RedCircle.Draw();
        RedCircle.Fill(Color.red);

        IShape BlueRectangle = new ShapeDecorator(new Rectangle());
        BlueRectangle.Draw();
        BlueRectangle.Fill(Color.blue);
    }
}