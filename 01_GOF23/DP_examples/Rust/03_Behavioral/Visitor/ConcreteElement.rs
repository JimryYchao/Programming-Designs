// 具体元素：Keyboard

use crate::ObjectStructure::Computer;


pub struct Keyboard;

// 具体元素：Monitor
pub struct Monitor;

// 具体元素：Mouse
pub struct Mouse;

// 元素接口
pub trait IComputerPart {
    fn accept(&self, visitor: &dyn IComputerPartVisitor);
}

// 访问者接口
pub trait IComputerPartVisitor {
    fn visit_computer(&self, computer: &Computer);
    fn visit_mouse(&self, mouse: &Mouse);
    fn visit_keyboard(&self, keyboard: &Keyboard);
    fn visit_monitor(&self, monitor: &Monitor);
}

// 具体元素：Keyboard 实现
impl IComputerPart for Keyboard {
    fn accept(&self, visitor: &dyn IComputerPartVisitor) {
        visitor.visit_keyboard(self);
    }
}

impl Keyboard {
    pub fn operation(&self) {
        println!("Using Keyboard");
    }
}

// 具体元素：Monitor 实现
impl IComputerPart for Monitor {
    fn accept(&self, visitor: &dyn IComputerPartVisitor) {
        visitor.visit_monitor(self);
    }
}

impl Monitor {
    pub fn operation(&self) {
        println!("Using Monitor");
    }
}

// 具体元素：Mouse 实现
impl IComputerPart for Mouse {
    fn accept(&self, visitor: &dyn IComputerPartVisitor) {
        visitor.visit_mouse(self);
    }
}

impl Mouse {
    pub fn operation(&self) {
        println!("Using Mouse");
    }
}
