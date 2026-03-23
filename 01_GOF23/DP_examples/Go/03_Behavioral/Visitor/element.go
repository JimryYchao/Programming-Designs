package visitor

// IComputerPart 元素接口
type IComputerPart interface {
	Accept(visitor IComputerPartVisitor)
}

// Keyboard 具体元素：键盘
type Keyboard struct{}

// Accept 接受访问者
func (k *Keyboard) Accept(visitor IComputerPartVisitor) {
	visitor.VisitKeyboard(k)
}

// Operation 键盘操作
func (k *Keyboard) Operation() {
	println("Using Keyboard")
}

// Monitor 具体元素：显示器
type Monitor struct{}

// Accept 接受访问者
func (m *Monitor) Accept(visitor IComputerPartVisitor) {
	visitor.VisitMonitor(m)
}

// Operation 显示器操作
func (m *Monitor) Operation() {
	println("Using Monitor")
}

// Mouse 具体元素：鼠标
type Mouse struct{}

// Accept 接受访问者
func (m *Mouse) Accept(visitor IComputerPartVisitor) {
	visitor.VisitMouse(m)
}

// Operation 鼠标操作
func (m *Mouse) Operation() {
	println("Using Mouse")
}

// Computer 具体元素：计算机（对象结构）
type Computer struct {
	parts []IComputerPart
}

// NewComputer 创建计算机实例
func NewComputer() *Computer {
	return &Computer{
		parts: []IComputerPart{
			&Keyboard{},
			&Mouse{},
			&Monitor{},
		},
	}
}

// Accept 接受访问者
func (c *Computer) Accept(visitor IComputerPartVisitor) {
	for _, part := range c.parts {
		part.Accept(visitor)
	}
	visitor.VisitComputer(c)
}
