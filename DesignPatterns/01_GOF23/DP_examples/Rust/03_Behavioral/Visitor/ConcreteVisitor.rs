// 具体访问者：ComputerPartDisplayVisitor
pub struct ComputerPartDisplayVisitor;

// 导入必要的类型
use crate::ConcreteElement::{IComputerPartVisitor, Mouse, Keyboard, Monitor};
use crate::ObjectStructure::Computer;

impl IComputerPartVisitor for ComputerPartDisplayVisitor {
    fn visit_computer(&self, _computer: &Computer) {
        println!("Displaying Computer");
    }

    fn visit_mouse(&self, mouse: &Mouse) {
        println!("Displaying Mouse");
        mouse.operation();
    }

    fn visit_keyboard(&self, keyboard: &Keyboard) {
        println!("Displaying Keyboard");
        keyboard.operation();
    }

    fn visit_monitor(&self, monitor: &Monitor) {
        println!("Displaying Monitor");
        monitor.operation();
    }
}
