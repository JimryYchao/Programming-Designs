namespace Structural.Decorator;

public class Circle : IShape {
    public void Draw() {
        Console.WriteLine("Draw a Circle.");
    }
    public void Fill(Color color) {
        Console.WriteLine($"Fill with {color}.");
    }
}
public class Rectangle : IShape {
    public void Draw() {
        Console.WriteLine("Draw a Rectangle.");
    }
    public void Fill(Color color) {
        Console.WriteLine($"Fill with {color}.");
    }
}