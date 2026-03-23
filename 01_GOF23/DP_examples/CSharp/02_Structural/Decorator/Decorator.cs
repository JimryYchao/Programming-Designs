namespace Structural.Decorator;

public abstract class Decorator : IShape {
    IShape ShapeComponent;
    public Decorator(IShape shape) { ShapeComponent = shape; }
    public virtual void Draw() {
        ShapeComponent?.Draw();
    }

    public virtual void Fill(Color color) {
        ShapeComponent?.Fill(color);
    }
}