namespace Creational.Factory;

public interface ICreator {
    IShape getShape();
    static virtual ICreator Instance { get; }
}

public sealed partial class ShapeFactory {
    class Creator {
        public static ICreator GetCreator(ShapeKind kind) {
            return kind switch {
                ShapeKind.Circle => CircleCreator.Instance,
                ShapeKind.BigCircle => BigCircleCreator.Instance,
                ShapeKind.Rectangle => RectangleCreator.Instance,
                ShapeKind.Square => SquareCreator.Instance, 
                _ => UnknownShapeCreator.Instance,
            };
        }
    }
    internal class UnknownShapeCreator : ICreator {
        public static ICreator Instance { get; } = new UnknownShapeCreator();
        public virtual IShape getShape() => new UnknownShape();
    }
    internal class CircleCreator : ICreator {
        public static ICreator Instance { get; } = new CircleCreator();
        public virtual IShape getShape() => new Circle();
    }
    internal class SquareCreator : ICreator {
        public static ICreator Instance { get; } = new SquareCreator();
        public virtual IShape getShape() => new Square();
    }
    internal class RectangleCreator : ICreator {
        public static ICreator Instance { get; } = new RectangleCreator();
        public virtual IShape getShape() => new Rectangle();
    }
    // 扩展 Circle
    internal class BigCircleCreator : CircleCreator, ICreator {
        public static new ICreator Instance => new BigCircleCreator();
        private IShape SetRadius(IShape circle) {
            // use circle
            Console.WriteLine("Set Radius to 10");
            return circle;
        }
        public override IShape getShape() => SetRadius(base.getShape());
    }

   
}
