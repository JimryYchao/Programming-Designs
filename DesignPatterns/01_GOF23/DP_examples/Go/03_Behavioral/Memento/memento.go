package Memento

// Memento 备忘录类
type Memento struct {
	states  map[string]interface{}
	Version int
}

// NewMemento 创建备忘录
func NewMemento(version int) *Memento {
	return &Memento{
		states:  make(map[string]interface{}),
		Version: version,
	}
}

// GetState 获取状态
func (m *Memento) GetState(identifier string) interface{} {
	if value, ok := m.states[identifier]; ok {
		return value
	}
	return nil
}

// SetState 设置状态
func (m *Memento) SetState(identifier string, state interface{}) {
	m.states[identifier] = state
}
