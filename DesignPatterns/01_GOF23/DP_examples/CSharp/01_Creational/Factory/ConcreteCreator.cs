using System.Diagnostics.Contracts;

namespace Creational.Factory;

public partial class ShapeFactory {
    static Dictionary<ShapeKind, ICreator> Factories = new Dictionary<ShapeKind, ICreator>();
    public static IShape GetShape(ShapeKind kind) => getFactory(kind).getShape();
    static ICreator getFactory(ShapeKind kind) {
        ICreator creator = null;
        if (Factories.ContainsKey(kind))
            creator = Factories[kind];
        else {
            creator = Creator.GetCreator(kind);
            Factories.Add(kind, creator);
        }
        return creator;
    }
}
