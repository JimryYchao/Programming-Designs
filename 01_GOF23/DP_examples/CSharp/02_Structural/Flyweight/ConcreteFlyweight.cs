namespace Structural.Flyweight;

// 固定直径的圆
public class Circle(CircleData Data, float x, float y) : IShape {
    public void Draw() {
        Console.WriteLine($"Draw a Circle with radius {data.radius} at ({x}, {y})");
    }
    public void Fill() => Console.WriteLine("Fill with " + data.color);
    public CircleData data => Data;
}
public class CircleFactory {
    public static Circle GetCircle(string color, float radius, float posX, float posY) => new (new (color, radius),posX, posY);
    public static Circle GetCircle(CircleData data, float x, float y) => new(data, x, y);
    public static CircleAddition GetSpacialCircle(Circle circle) => new (circle);
}