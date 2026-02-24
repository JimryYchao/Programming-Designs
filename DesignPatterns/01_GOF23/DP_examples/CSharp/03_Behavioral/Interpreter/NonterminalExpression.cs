namespace Behavioral.Interpreter;

/// <summary>
/// 对运算符进行解释
/// </summary>
public abstract class OperationExpression(ArithmeticExpr exp1, ArithmeticExpr exp2) : ArithmeticExpr
{
    public abstract double Interpret();
    protected ArithmeticExpr exp1 = exp1, exp2 = exp2;
}
public class AdditionExpression(ArithmeticExpr exp1, ArithmeticExpr exp2) : OperationExpression(exp1, exp2)  
{
    public override double Interpret() => exp1.Interpret() + exp2.Interpret();
}
public class SubtractionExpression(ArithmeticExpr exp1, ArithmeticExpr exp2) : OperationExpression(exp1, exp2)  
{
    public override double Interpret() => exp1.Interpret() - exp2.Interpret();
}
public class MultiplicationExpression(ArithmeticExpr exp1, ArithmeticExpr exp2) : OperationExpression(exp1, exp2)  
{
    public override double Interpret() => exp1.Interpret() * exp2.Interpret();
}
public class DivisionExpression(ArithmeticExpr exp1, ArithmeticExpr exp2) : OperationExpression(exp1, exp2)  
{
    public override double Interpret() => exp1.Interpret() / exp2.Interpret();
}