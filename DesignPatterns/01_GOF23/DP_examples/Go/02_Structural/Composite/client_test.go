package Composite_test

import (
	. "Composite"
	"testing"
)

// 构建团队
func BuildATeam() IComponent {
	// 创建老板
	boss := NewEmployee(false).Init("Tom", "man", 45, 50000)

	// 创建主管
	chargeA := NewEmployee(false).Init("Lily", "woman", 25, 12000)
	chargeB := NewEmployee(false).Init("Jerry", "man", 27, 11000)

	// 创建基础员工
	baseA := NewEmployee(true).Init("Lee", "woman", 21, 8000)
	baseB := NewEmployee(true).Init("Ychao", "man", 21, 7500)
	baseC := NewEmployee(true).Init("Tomas", "man", 22, 7000)
	baseD := NewEmployee(true).Init("Jimmy", "man", 23, 8200)

	// 构建层级关系
	boss.Add(chargeA)
	boss.Add(chargeB)
	chargeA.Add(baseA)
	chargeA.Add(baseB)
	chargeB.Add(baseC)
	chargeB.Add(baseD)

	return boss
}

// 测试 Composite 模式
func TestCompositePattern(t *testing.T) {
	tree := BuildATeam()
	tree.Operation()
}
