namespace Behavioral.ChainOfResponsibility;

public abstract class LoggerHandler
{
    public static int DEFAULT = 1;
    public static int WARNING = 2;
    public static int ERROR = 3;

    private LoggerHandler nextLogger;
    public int Level { get; private set; }
    public LoggerHandler SetSupHandler(LoggerHandler logger)
    {
        logger.nextLogger = this;
        return logger;
    }
    public LoggerHandler(int level)
    {
        Level = level;
        nextLogger = null;
    }
    public virtual void Log(int level, string message)
    {
        if (level == Level)
        {
            Write(message);
            return;
        }
        if (nextLogger != null)
            nextLogger.Log(level, message);
        else
            DefaultWrite(message);
    }
    protected abstract void Write(string message);
    private void DefaultWrite(string message)
    {
        Console.WriteLine("Default Console: " + message);
    }
}