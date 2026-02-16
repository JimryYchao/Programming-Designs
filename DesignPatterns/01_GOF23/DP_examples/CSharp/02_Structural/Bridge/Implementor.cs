namespace Structural.Bridge;

public enum Color {
    unknown,
    red, green, blue,
}
public abstract class DrawAPI {
    public abstract void Draw();
    public virtual void Fill(Color color) { 
        Console.WriteLine("Fill with " + color);
    } 
}