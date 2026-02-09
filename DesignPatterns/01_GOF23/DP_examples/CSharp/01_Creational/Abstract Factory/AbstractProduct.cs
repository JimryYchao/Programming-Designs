namespace Creational;

public interface IColor { void Fill(); }
public class Red : IColor {
    void IColor.Fill() => Console.WriteLine("Fill Red");
}
public class Green : IColor {
    void IColor.Fill() => Console.WriteLine("Fill Green");
}
public class Blue : IColor {
    void IColor.Fill() => Console.WriteLine("Fill Blue");
}
internal class UnknownColor : IColor {
    internal static readonly UnknownColor Default = new UnknownColor();
    void IColor.Fill() { }
}
public interface IShape { void Draw(); }
public class Circle : IShape {
    void IShape.Draw() => Console.WriteLine("Draw a Circle");
}
public class Square : IShape {
    void IShape.Draw() => Console.WriteLine("Draw a Square");
}
public class Rectangle : IShape {
    void IShape.Draw() => Console.WriteLine("Draw a Rectangle");
}
internal class UnknownShape : IShape {
    internal static readonly UnknownShape Default = new UnknownShape();
    void IShape.Draw() { }
}
