namespace Structural.Bridge;


// 桥接对象


public class Shape(DrawAPI draw) {
    public virtual void Draw(Color color) {
        draw.Draw();
        draw.Fill(color);
    }
}

public class ShapeAdvance(DrawAPI draw, Action onDrawCompleted) : Shape(draw) {
    public override void Draw(Color color) {
        base.Draw(color);
        onDrawCompleted?.Invoke();
    }
}
