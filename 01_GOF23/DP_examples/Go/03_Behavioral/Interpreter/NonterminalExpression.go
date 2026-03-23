// 非终结符表达式 - 处理运算符
package Interpreter

type OperationExpr struct {
	exp1 ArithmeticExpr
	exp2 ArithmeticExpr
}

// 加法表达式
type AdditionExpr struct {
	OperationExpr
}

func NewAdditionExpr(exp1, exp2 ArithmeticExpr) *AdditionExpr {
	return &AdditionExpr{
		OperationExpr: OperationExpr{exp1: exp1, exp2: exp2},
	}
}

func (a *AdditionExpr) Interpret() float64 {
	return a.exp1.Interpret() + a.exp2.Interpret()
}

// 减法表达式
type SubtractionExpr struct {
	OperationExpr
}

func NewSubtractionExpr(exp1, exp2 ArithmeticExpr) *SubtractionExpr {
	return &SubtractionExpr{
		OperationExpr: OperationExpr{exp1: exp1, exp2: exp2},
	}
}

func (s *SubtractionExpr) Interpret() float64 {
	return s.exp1.Interpret() - s.exp2.Interpret()
}

// 乘法表达式
type MultiplicationExpr struct {
	OperationExpr
}

func NewMultiplicationExpr(exp1, exp2 ArithmeticExpr) *MultiplicationExpr {
	return &MultiplicationExpr{
		OperationExpr: OperationExpr{exp1: exp1, exp2: exp2},
	}
}

func (m *MultiplicationExpr) Interpret() float64 {
	return m.exp1.Interpret() * m.exp2.Interpret()
}

// 除法表达式
type DivisionExpr struct {
	OperationExpr
}

func NewDivisionExpr(exp1, exp2 ArithmeticExpr) *DivisionExpr {
	return &DivisionExpr{
		OperationExpr: OperationExpr{exp1: exp1, exp2: exp2},
	}
}

func (d *DivisionExpr) Interpret() float64 {
	return d.exp1.Interpret() / d.exp2.Interpret()
}