package Memento

import "errors"

// Caretaker 管理者类
type Caretaker struct {
	mementoMap map[int]*Memento
}

// NewCaretaker 创建管理者
func NewCaretaker() *Caretaker {
	return &Caretaker{
		mementoMap: make(map[int]*Memento),
	}
}

// SaveMemento 保存备忘录
func (c *Caretaker) SaveMemento(version int, m *Memento) {
	c.mementoMap[version] = m
}

// GetMemento 获取备忘录
func (c *Caretaker) GetMemento(version int) (*Memento, error) {
	if m, ok := c.mementoMap[version]; ok {
		return m, nil
	}
	return nil, errors.New("version not found")
}
