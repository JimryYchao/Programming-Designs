package Memento_test

import (
	. "Memento"
	"testing"
)

func TestMementoPattern(t *testing.T) {
	// 创建发起人
	o := NewOriginator("Hello", "World", "!")
	
	// 创建管理者
	caretaker := NewCaretaker()
	
	// 保存第一版
	caretaker.SaveMemento(1, o.CreateMemento(1))
	
	// 修改状态
	o = NewOriginator("X", "Y", "Z")
	o.ConsoleState()
	
	// 恢复第一版
	memento, err := caretaker.GetMemento(1)
	if err != nil {
		t.Fatal(err)
	}
	o.SetMemento(memento)
	o.ConsoleState()
}
