package visitor

import "testing"

func TestVisitorPattern(t *testing.T) {
	// 创建计算机对象
	computer := NewComputer()
	
	// 创建访问者
	visitor := NewComputerPartDisplayVisitor()
	
	// 接受访问
	computer.Accept(visitor)
}
