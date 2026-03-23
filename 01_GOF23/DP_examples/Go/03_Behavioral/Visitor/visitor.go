package visitor

// IComputerPartVisitor 访问者接口
type IComputerPartVisitor interface {
	VisitComputer(computer *Computer)
	VisitMouse(mouse *Mouse)
	VisitKeyboard(keyboard *Keyboard)
	VisitMonitor(monitor *Monitor)
}
