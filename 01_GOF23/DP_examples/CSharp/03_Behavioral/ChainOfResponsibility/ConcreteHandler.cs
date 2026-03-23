namespace Behavioral.ChainOfResponsibility;

public class ConsoleLogger : LoggerHandler
{
    public ConsoleLogger(int level) : base(level) { }
    protected override void Write(string message)
    {
        Console.WriteLine("Standard Console: " + message);
    }
}
public class ErrorLogger : LoggerHandler
{
    public ErrorLogger(int level) : base(level) { }
    protected override void Write(string message)
    {
        Console.WriteLine("Error Console: " + message);
    }
}
public class WarningLogger : LoggerHandler
{
    public WarningLogger(int level) : base(level) { }
    protected override void Write(string message)
    {
        Console.WriteLine("Warning Console: " + message);
    }

}