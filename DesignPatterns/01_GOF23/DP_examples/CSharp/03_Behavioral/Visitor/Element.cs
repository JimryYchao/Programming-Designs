namespace Behavioral.Visitor;

public interface IComputerPart
{
    void Accept(IComputerPartVisitor computer);
}