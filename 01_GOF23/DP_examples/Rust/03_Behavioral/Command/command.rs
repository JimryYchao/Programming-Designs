// 命令实现

// 导入接收者接口
use crate::receiver::IReceiver;
use std::sync::Arc;

// 命令接口
pub trait ICommand {
    fn execute(&self);
}

// 具体命令实现
pub struct ConcreteCommand {
    receiver: Box<dyn IReceiver>,
}

impl ConcreteCommand {
    pub fn new(receiver: Box<dyn IReceiver>) -> Self {
        ConcreteCommand {
            receiver,
        }
    }
}

impl ICommand for ConcreteCommand {
    fn execute(&self) {
        self.receiver.action();
    }
}

// 类型别名，使用Arc管理命令对象
pub type CommandPtr = Arc<dyn ICommand>;
