from Visitor import IComputerPartVisitor

# 具体访问者：ComputerPartDisplayVisitor
class ComputerPartDisplayVisitor(IComputerPartVisitor):
    def visit_computer(self, computer):
        print("Displaying Computer")
    
    def visit_mouse(self, mouse):
        print("Displaying Mouse")
        mouse.operation()
    
    def visit_keyboard(self, keyboard):
        print("Displaying Keyboard")
        keyboard.operation()
    
    def visit_monitor(self, monitor):
        print("Displaying Monitor")
        monitor.operation()
