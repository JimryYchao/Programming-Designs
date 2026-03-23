namespace Behavioral.Command;

public class Invoker {
    public static readonly Invoker Instance = new Invoker();
    List<ICommand> commands = new();
    public int Count => commands.Count;
    public void StoreCommand(ICommand command) {
        commands.Add(command);
    }
    public bool RemoveCommand(ICommand command) {
        if (commands.Count == 0)
            return false;
        return commands.Remove(command);
    }
    public void Invoke() {
        foreach (ICommand command in commands)
            command.Execute();
    }
}