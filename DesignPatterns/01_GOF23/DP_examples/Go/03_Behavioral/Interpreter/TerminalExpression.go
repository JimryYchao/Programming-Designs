// 终结符表达式 - 处理数字
package Interpreter

type NumberExpr struct {
	num float64
}

func NewNumberExpr(num float64) *NumberExpr {
	return &NumberExpr{num: num}
}

func (n *NumberExpr) Interpret() float64 {
	return n.num
}
