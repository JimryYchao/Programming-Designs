namespace Structural.Composite;


public interface ILeaf
{
    bool IsLeaf { get; }
    void Operation();
}
public interface IComponent : ILeaf
{
    int Add(IComponent component);
    bool Remove(IComponent component);
    IComponent GetChild(int index);
}