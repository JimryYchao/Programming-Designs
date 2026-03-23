namespace Behavioral.Iterator;

public interface Iterator<T>
{
    void First();
    void Next();
    bool IsDone();
    T CurrentItem { get; }
}
public interface Iterable<T>
{
    Iterator<T> GetIterator();
}