// 抽象表达式接口
package Interpreter

type ArithmeticExpr interface {
	Interpret() float64
}
