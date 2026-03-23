namespace Creational.Factory;

public interface IShape {
    void Draw();
    void Fill();
}

public enum ShapeKind {
    None, Circle, Square, Rectangle, BigCircle
}
internal class Circle : IShape {
    public void Draw() => Console.WriteLine("Draw a Circle");
    public void Fill() => Console.WriteLine("Fill red");
}
internal class Square : IShape {
    public void Draw() => Console.WriteLine("Draw a Square");
    public void Fill() => Console.WriteLine("Fill Green");
}
internal class Rectangle : IShape {
    public void Draw() => Console.WriteLine("Draw a Rectangle");
    public void Fill() => Console.WriteLine("Fill Blue");
}

internal class UnknownShape : IShape {
    public void Draw() { }
    public void Fill() { }
}
