
namespace Creational.Prototype;

public enum Color {
    Unknown,
    Red,
    Green,
    Blue,
    Yellow,
}


public interface IShape {
    string Name { get; }
    void Draw();
    void Fill(Color kind);
}

// 缺省
[Serializable]
public class Shape(int id = 0, string name = "") : IShape {
    public int ID => id;
    public string Name => name;
    // default
    public virtual void Draw() { }
    public virtual void Fill(Color kind) { }
    public virtual T Clone<T>() where T : Shape => MemberwiseClone() as T;
}

// different products
public enum ShapeKind {
    Unknown,
    Circle,
    Square,
    Rectangle
}
[Serializable]
public class Circle : Shape {
    // maybe contain other datas
    public Circle(int id = (int)ShapeKind.Circle, string type = "Circle") : base(id, type) { }
    public override void Draw() => Console.WriteLine("Draw a Circle");
    public override void Fill(Color color) => Console.WriteLine("Fill with " + color.ToString());
}
[Serializable]
public class Square : Shape {
    public Square(int id = (int)ShapeKind.Square, string type = "Square") : base(id, type) { }
    public override void Draw() => Console.WriteLine("Draw a Square");
    public override void Fill(Color color) => Console.WriteLine("Fill with " + color.ToString());
}
[Serializable]
public class Rectangle : Shape {
    public Rectangle(int id = (int)ShapeKind.Rectangle, string type = "Rectangle") : base(id, type) { }
    public override void Draw() => Console.WriteLine("Draw a Rectangle");
    public override void Fill(Color color) => Console.WriteLine("Fill with " + color.ToString());
}
