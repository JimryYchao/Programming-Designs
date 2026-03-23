
namespace Structural.Composite;

public class Composite(bool isLeaf) : IComponent
{
    // Operation for self
    public bool IsLeaf => isLeaf;
    public virtual void Operation() {
        if (!isLeaf)
            foreach (IComponent em in subComposites)
                em.Operation();
    }
    protected List<IComponent> subComposites = new List<IComponent>();
    int IComponent.Add(IComponent component)
    {
        if (isLeaf || component == null)
            return -1;
        if (!subComposites.Contains(component))
        {
            subComposites.Add(component);
            return subComposites.Count;
        }
        else return -1;
    }
    IComponent IComponent.GetChild(int index)
    {
        return (index < 0 || index > subComposites.Count) ? null : subComposites[index];
    }
    bool IComponent.Remove(IComponent component)
    {
        if (isLeaf)
            return false;
        return subComposites.Remove(component);
    }
}