namespace Structural.Facade;

public enum ShapeType
{
    Circle,
    Rectangle,
    Square
}

public class ShapeMaker
{
    public static readonly ShapeMaker Instance = new ShapeMaker();
    public IShape BuildShape(ShapeType shapeType, params int[] args)
    {
        switch (shapeType)
        {
            case ShapeType.Circle:
                return new Circle(args[0]);
            case ShapeType.Rectangle:
                return new Rectangle(args[0], args[1]);
            case ShapeType.Square:
                return new Square(args[0]);
            default:
                return null;
        }
    }
}