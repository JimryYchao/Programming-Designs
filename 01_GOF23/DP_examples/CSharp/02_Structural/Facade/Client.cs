namespace Structural;

using Structural.Facade;

public class FacadeDemo {
    public static void Example() {
        var circle_10 = ShapeMaker.Instance.BuildShape(ShapeType.Circle, 10);
        circle_10?.Draw();
        var rectangle_10x20 = ShapeMaker.Instance.BuildShape(ShapeType.Rectangle, 10, 20);
        rectangle_10x20?.Draw();
        var square_10 = ShapeMaker.Instance.BuildShape(ShapeType.Square, 10);
        square_10?.Draw();
    }
}