namespace Behavioral.Interpreter;

// 用于解释四则运算，例如 123+321，123*123 等，数字为终结符，运算符为非终结符
public interface ArithmeticExpr
{
    double Interpret();
}