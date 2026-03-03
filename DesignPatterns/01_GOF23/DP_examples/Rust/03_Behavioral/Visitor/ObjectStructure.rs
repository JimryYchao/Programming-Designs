// 具体元素：Computer (ObjectStructure)
pub struct Computer {
    pub parts: Vec<Box<dyn crate::ConcreteElement::IComputerPart>>,
}

use crate::{ConcreteElement::{IComputerPart, IComputerPartVisitor, Keyboard, Mouse, Monitor}};

// 具体元素：Computer (ObjectStructure) 实现
impl Computer {
    pub fn new() -> Self {
        Self {
            parts: vec![
                Box::new(Keyboard),
                Box::new(Mouse),
                Box::new(Monitor),
            ],
        }
    }
}

impl IComputerPart for Computer {
    fn accept(&self, visitor: &dyn IComputerPartVisitor) {
        for part in &self.parts {
            part.accept(visitor);
        }
        visitor.visit_computer(self);
    }
}
