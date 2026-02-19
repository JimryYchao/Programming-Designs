namespace Structural.Facade;

public interface IShape {
    void Draw();
}

class Circle(int radius) : IShape {
    public void Draw() {
        Console.WriteLine($"Draw a circle with radius {radius}");
    }
}

class Rectangle(int width, int height) : IShape {
    public void Draw() {
        Console.WriteLine($"Draw a rectangle with width {width} and height {height}");
    }
}

class Square(int side) : IShape {
    public void Draw() {
        Console.WriteLine($"Draw a square with side {side}");
    }
}
