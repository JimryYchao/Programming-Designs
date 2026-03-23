namespace Structural.Flyweight;

public class CircleAddition(Circle circle) : IShape {
    IShape shape => circle;
    public void Draw() => shape.Draw();
    public void Fill() => shape.Fill();
    public void MovePosition(float x, float y) {
        Console.WriteLine($"Move Circle to ({x}, {y})");
    }
    public void ResetRadius(float radius) {
        Console.WriteLine($"Reset Radius to {radius}");
    }
}