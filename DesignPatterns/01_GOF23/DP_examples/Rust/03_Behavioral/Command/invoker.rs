// 命令调用者实现

// 导入命令接口和类型别名
use crate::command::CommandPtr;
use std::sync::Arc;

// 命令调用者
pub struct Invoker {
    commands: Vec<CommandPtr>,
}

impl Invoker {
    pub fn new() -> Self {
        Invoker {
            commands: Vec::new(),
        }
    }
    
    pub fn store_command(&mut self, command: &CommandPtr) {
        self.commands.push(command.clone());
    }
    
    pub fn remove_command(&mut self, command: &CommandPtr) -> bool {
        if self.commands.is_empty() {
            return false;
        }
        
        // 使用Arc的指针比较来找到并移除命令
        for i in 0..self.commands.len() {
            if Arc::ptr_eq(&self.commands[i], command) {
                self.commands.remove(i);
                return true;
            }
        }
        false
    }
    
    pub fn count(&self) -> usize {
        self.commands.len()
    }
    
    pub fn invoke(&self) {
        for command in &self.commands {
            command.execute();
        }
    }
}
