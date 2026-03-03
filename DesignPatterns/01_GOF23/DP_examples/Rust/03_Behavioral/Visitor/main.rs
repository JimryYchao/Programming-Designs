
mod ConcreteElement;
mod ConcreteVisitor;
mod ObjectStructure;

use crate::ConcreteElement::IComputerPart;
use crate::ObjectStructure::Computer;
use crate::{ConcreteVisitor::ComputerPartDisplayVisitor};

fn main() {
    // 创建计算机对象
    let computer = Computer::new();
    
    // 创建访问者
    let visitor = ComputerPartDisplayVisitor;
    
    // 接受访问
    computer.accept(&visitor);
}
