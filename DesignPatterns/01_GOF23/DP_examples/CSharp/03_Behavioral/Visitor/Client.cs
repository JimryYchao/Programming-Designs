namespace Behavioral;

using Behavioral.Visitor;

public class VisitorDemo
{
    public static void Example()
    {
        IComputerPart computer = new Computer();
        computer.Accept(new ComputerPartDisplayVisitor());
    }
}
