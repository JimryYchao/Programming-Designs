using Creational.Prototype;


namespace Creational;

public class ShapeCache {
    public readonly static ShapeCache Instance = new ShapeCache();
    private ShapeCache() { loadCache(); }
    // 一般从配置表读取
    private void loadCache() {
        RegisterPrototype(ShapeKind.Rectangle, new RectangleProto(new Rectangle()));
        RegisterPrototype(ShapeKind.Circle, new CircleProto(new Circle()));
        RegisterPrototype(ShapeKind.Square, new SquarePrototype(new Square()));
    }

    private Dictionary<ShapeKind, ShapePrototype> shapeMap { get; } = new Dictionary<ShapeKind, ShapePrototype>();
    public void RegisterPrototype(ShapeKind key, ShapePrototype shape) {
        if (!shapeMap.ContainsKey(key))
            shapeMap.Add(key, shape);
    }
    public bool RemovePrototype(ShapeKind key) {
        return shapeMap.Remove(key);
    }
    public Shape GetShapeByWiseClone(ShapeKind Key) {
        if (!shapeMap.TryGetValue(Key, out ShapePrototype proto)) {
            Console.WriteLine($"Clone {Key} failed");
            return null;
        }
        return proto.WiseClone() as Shape;
    }
    public Shape GetShapeByDeepClone(ShapeKind Key) {
        if (!shapeMap.TryGetValue(Key, out ShapePrototype proto)) {
            Console.WriteLine($"Clone {Key} failed");
            return null;
        }
        return proto.DeepClone() as Shape;
    }
 
}
