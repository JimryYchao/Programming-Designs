namespace Structural;

using Structural.Bridge;

public class BridgeDemo {
    public static void Example() {
        Shape circle = new Shape(new Circle());
        circle.Draw(Color.green);

        Shape square = new ShapeAdvance(new Square(), () => { Console.WriteLine("Drew Completly"); });
        square.Draw(Color.blue);
    }
}