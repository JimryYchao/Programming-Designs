namespace Structural.Decorator;

public class ShapeDecorator : Decorator {
    public ShapeDecorator(IShape shape) : base(shape) { }
    protected virtual void BeforeDraw() {
        Console.WriteLine("Before Draw() >> Do...");
    }
    protected virtual void AfterDraw() {
        Console.WriteLine("When Draw Complete >> Do...");
    }
    protected virtual void BeforeFill() {
        Console.WriteLine("Before Fill() >> Do...");
    }
    protected virtual void AfterFill() {
        Console.WriteLine("When Fill Complete >> Do...");
    }
    public override void Draw() {
        BeforeDraw();
        base.Draw();
        AfterDraw();
    }
    public override void Fill(Color color) {
        BeforeFill();
        base.Fill(color);
        AfterFill();
    }
}