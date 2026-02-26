namespace Behavioral.Memento;

public class Memento
{
    Dictionary<string, object> states;
    public int Version { get; private set; }
    public Memento(int version)
    {
        this.Version = version;
        states = new Dictionary<string, object>();
    }
    public object GetState(string identifier)
    {
        if (states.TryGetValue(identifier, out object? value))
            return value;
        return null;
    }
    public void SetState(string identifier, object state)
    {
        states.Add(identifier, state);
    }
}