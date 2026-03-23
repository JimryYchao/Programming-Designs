namespace Behavioral.Command;

public interface ICommand
{
    void Execute();
}

public class ConcreteCommand(IReceiver receiver) : ICommand {
    public void Execute() => receiver?.Action();
}
