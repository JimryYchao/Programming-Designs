namespace Behavioral;
using Behavioral.ChainOfResponsibility;
public class ChainOfResponsibilityDemo
{
    public static void Example()
    {
        LoggerHandler logger = new ConsoleLogger(1).SetSupHandler(new WarningLogger(2)).SetSupHandler(new ErrorLogger(3));
        Console.WriteLine(logger.Level);
        logger.Log(2, "This is a warning log");
    }
}