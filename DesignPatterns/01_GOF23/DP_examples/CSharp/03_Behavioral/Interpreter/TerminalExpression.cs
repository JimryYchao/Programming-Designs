namespace Behavioral.Interpreter;

public class NumberExpr(double num) : ArithmeticExpr
{
    public double Interpret() => num;
}
