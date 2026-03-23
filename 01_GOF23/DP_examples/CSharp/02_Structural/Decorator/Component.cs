namespace Structural.Decorator;

public enum Color  {
    unknown,
    red, green, blue,
}

public interface IShape {
    void Draw();
    void Fill(Color color);
}