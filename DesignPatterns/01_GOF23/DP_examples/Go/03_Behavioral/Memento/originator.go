package Memento

import "fmt"

// Originator 发起人类
type Originator struct {
	state1 string
	state2 string
	state3 string
}

// NewOriginator 创建发起人
func NewOriginator(s1, s2, s3 string) *Originator {
	return &Originator{
		state1: s1,
		state2: s2,
		state3: s3,
	}
}

// ConsoleState 打印状态
func (o *Originator) ConsoleState() {
	fmt.Printf("State_1: %s\n", o.state1)
	fmt.Printf("State_2: %s\n", o.state2)
	fmt.Printf("State_3: %s\n", o.state3)
}

// CreateMemento 创建备忘录
func (o *Originator) CreateMemento(version int) *Memento {
	memento := NewMemento(version)
	memento.SetState("state1", o.state1)
	memento.SetState("state2", o.state2)
	memento.SetState("state3", o.state3)
	return memento
}

// SetMemento 恢复状态
func (o *Originator) SetMemento(m *Memento) {
	o.state1 = m.GetState("state1").(string)
	o.state2 = m.GetState("state2").(string)
	o.state3 = m.GetState("state3").(string)
}
