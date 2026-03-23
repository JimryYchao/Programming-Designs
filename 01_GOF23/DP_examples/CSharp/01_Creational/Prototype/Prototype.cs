namespace Creational.Prototype;
    public interface IClone<T> {
        T WiseClone();
        T DeepClone();
    }
    public abstract class ShapePrototype : IClone<IShape> {
        public abstract IShape DeepClone();
        public abstract IShape WiseClone();
    }
