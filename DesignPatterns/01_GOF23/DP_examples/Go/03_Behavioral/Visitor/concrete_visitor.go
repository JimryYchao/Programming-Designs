package visitor

// ComputerPartDisplayVisitor 具体访问者：显示计算机部件
type ComputerPartDisplayVisitor struct{}

// NewComputerPartDisplayVisitor 创建显示访问者实例
func NewComputerPartDisplayVisitor() *ComputerPartDisplayVisitor {
	return &ComputerPartDisplayVisitor{}
}

// VisitComputer 访问计算机
func (v *ComputerPartDisplayVisitor) VisitComputer(computer *Computer) {
	println("Displaying Computer")
}

// VisitMouse 访问鼠标
func (v *ComputerPartDisplayVisitor) VisitMouse(mouse *Mouse) {
	println("Displaying Mouse")
	mouse.Operation()
}

// VisitKeyboard 访问键盘
func (v *ComputerPartDisplayVisitor) VisitKeyboard(keyboard *Keyboard) {
	println("Displaying Keyboard")
	keyboard.Operation()
}

// VisitMonitor 访问显示器
func (v *ComputerPartDisplayVisitor) VisitMonitor(monitor *Monitor) {
	println("Displaying Monitor")
	monitor.Operation()
}
