namespace Structural.Flyweight;

public class FlyweightFactory {
   static Dictionary<string, Dictionary<float, CircleData>> ShapeDic = new();
    public static Circle GetCircle(string color, float radius, float x, float y) {
        CircleData data = null;
        Circle circle = null;
        if (ShapeDic.TryGetValue(color, out var dic)) {
            if (dic.TryGetValue(radius, out data))
                return CircleFactory.GetCircle(data, x, y);
            else {
                circle = CircleFactory.GetCircle(color, radius, x, y);
                dic.Add(radius, circle.data);
            }
        } else {
            dic = new();
            circle = CircleFactory.GetCircle(color, radius, x, y);
            ShapeDic.Add(color, new() { { radius, circle.data } });
        }
        Console.WriteLine("Create a New Circle Filled with " + color);
        return circle;
    }
    public static CircleAddition GetSpecialCircle(string color, float radius, float x, float y) {
        return CircleFactory.GetSpacialCircle(GetCircle(color, radius, x, y));
    }
}