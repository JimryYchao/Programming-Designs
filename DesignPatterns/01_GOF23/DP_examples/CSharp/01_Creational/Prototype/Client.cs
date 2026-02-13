namespace Creational;

using Creational.Prototype;

public class PrototypeDemo {
    public static void Example() {
        Shape circle = ShapeCache.Instance.GetShapeByDeepClone(ShapeKind.Circle);
        circle?.Draw();
        circle?.Fill(Color.Red);

        Shape Rectangle = ShapeCache.Instance.GetShapeByWiseClone(ShapeKind.Rectangle);
        Rectangle?.Draw();
        Rectangle?.Fill(Color.Blue);
    }
}
