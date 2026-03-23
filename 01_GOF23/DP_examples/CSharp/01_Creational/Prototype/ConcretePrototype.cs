using Newtonsoft.Json;
using System.IO;
using System.Reflection;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Xml.Serialization;

namespace Creational.Prototype;

public class CircleProto : ShapePrototype {
    protected Shape shapeProto;
    public CircleProto(Circle clrcle) {
        shapeProto = clrcle;
    }
    protected CircleProto(Shape shape) {
        shapeProto = shape;
    }
    public override Shape DeepClone() {
        // 自由选择深拷贝方式
        return shapeProto.SerializerClone();
    }
    public override Shape WiseClone() {
        try {
            Circle? cir = shapeProto.Clone<Circle>();
            return cir;
        } catch (Exception ex) {
            Console.WriteLine(ex.Message);
        }
        return null;
    }
}
public class RectangleProto : CircleProto {
    public RectangleProto(Rectangle rec) : base(rec) { }
    public override Shape WiseClone() {
        try {
            Rectangle? cir = shapeProto.Clone<Rectangle>();
            return cir;
        } catch (Exception ex) {
            Console.WriteLine(ex.Message);
        }
        return null;
    }
}
public class SquarePrototype : CircleProto {
    public SquarePrototype(Square sq) : base(sq) { }
    public override Shape WiseClone() {
        try {
            Square? cir = shapeProto.Clone<Square>();
            return cir;
        } catch (Exception ex) {
            Console.WriteLine(ex.Message);
        }
        return null;
    }
}
