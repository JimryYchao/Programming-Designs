using Behavioral.Interpreter;

namespace Behavioral;

public class InterpreterDemo
{
    public static void Example()
    {
        Console.WriteLine(Calculator.Calculate("1+2+3"));

        Console.WriteLine(Calculator.Calculate("2*(1+2)"));

        Console.WriteLine(Calculator.Calculate("2+(1+2*5)"));

        Console.WriteLine(Calculator.Calculate("2*(1+2*6)"));

        Console.WriteLine(Calculator.Calculate("(68*(115+20)+10)"));
    }
}