use std::collections::{HashMap};
use std::sync::Arc;
use std::sync::Mutex;
use crate::subject::{Observer, Subject, ConcreteSubject};

// 变更管理器接口
pub trait ChangeManager {
    fn register(&mut self, subject: &dyn Subject, observer: Box<dyn Observer>);
    fn unregister(&mut self, subject: &dyn Subject, observer: &dyn Observer);
    fn notify(&self);
}

// 简单变更管理器：更新每一个目标的所有观察者
pub struct SimpleChangeManager {
    subject: Arc<dyn Subject>,
    observers: Vec<Box<dyn Observer>>,
}

impl SimpleChangeManager {
    pub fn new(subject: Arc<dyn Subject>) -> Self {
        Self {
            subject,
            observers: Vec::new(),
        }
    }
    
    pub fn clear_observer(&mut self) {
        self.observers.clear();
    }
}

impl ChangeManager for SimpleChangeManager {
    fn register(&mut self, _subject: &dyn Subject, ob: Box<dyn Observer>) {
        // 检查观察者是否已经存在
        if !self.observers.iter().any(|o| {
            // 简单比较，实际应用中可能需要更复杂的比较
            std::any::type_name::<dyn Observer>() == std::any::type_name_of_val(o)
        }) {
            self.observers.push(ob);
        }
    }
    
    fn unregister(&mut self, _subject: &dyn Subject, observer: &dyn Observer) {
        self.observers.retain(|o| {
            // 简单比较，实际应用中可能需要更复杂的比较
            std::any::type_name_of_val(o) != std::any::type_name_of_val(observer)
        });
    }
    
    fn notify(&self) {
        for observer in &self.observers {
            observer.update(&*self.subject);
        }
    }
}

// DCG变更管理器：一个观察者观察多个目标
pub struct DCGChangeManager {
    // 使用usize作为key，存储subject的引用和对应的观察者列表
    subject_observers: HashMap<usize, Vec<Box<dyn Observer>>>,
}

impl DCGChangeManager {
    pub fn new() -> Self {
        Self {
            subject_observers: HashMap::new(),
        }
    }
    
    pub fn get_instance() -> Arc<Mutex<Self>> {
        static mut INSTANCE: Option<Arc<Mutex<DCGChangeManager>>> = None;
        static ONCE: std::sync::Once = std::sync::Once::new();
        
        ONCE.call_once(|| {
            unsafe {
                INSTANCE = Some(Arc::new(Mutex::new(DCGChangeManager::new())));
            }
        });
        
        unsafe {
            INSTANCE.as_ref().unwrap().clone()
        }
    }
    
    // 生成subject的唯一标识符
    fn get_subject_id(&self, subject: &dyn Subject) -> usize {
        // 使用std::ptr::addr_of获取subject的地址
        let ptr = std::ptr::addr_of!(subject);
        ptr as usize
    }
}

impl ChangeManager for DCGChangeManager {
    fn register(&mut self, subject: &dyn Subject, observer: Box<dyn Observer>) {
        let subject_id = self.get_subject_id(subject);
        
        if let Some(observers) = self.subject_observers.get_mut(&subject_id) {
            // 检查观察者是否已经存在
            if !observers.iter().any(|o| {
                std::any::type_name_of_val(o) == std::any::type_name_of_val(&*observer)
            }) {
                observers.push(observer);
            }
        } else {
            let mut observers = Vec::new();
            observers.push(observer);
            self.subject_observers.insert(subject_id, observers);
        }
    }
    
    fn unregister(&mut self, subject: &dyn Subject, observer: &dyn Observer) {
        let subject_id = self.get_subject_id(subject);
        
        if let Some(observers) = self.subject_observers.get_mut(&subject_id) {
            observers.retain(|o| {
                std::any::type_name_of_val(o) != std::any::type_name_of_val(observer)
            });
        }
    }
    
    fn notify(&self) {
        // 注意：由于我们只存储了subject的ID，而没有存储subject本身
        // 这里的notify方法实际上无法实现，因为我们没有办法获取到subject
        // 实际应用中，应该修改API设计，让DCGChangeManager能够访问到subject
        // 或者在调用notify时传入subject
        println!("DCGChangeManager notify called");
    }
}

// 日志管理器：瞬发消息，报告状态
pub struct LoggerManager {
    // 单例实例
}

impl LoggerManager {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Arc<Mutex<Self>> {
        static mut INSTANCE: Option<Arc<Mutex<LoggerManager>>> = None;
        static ONCE: std::sync::Once = std::sync::Once::new();
        
        ONCE.call_once(|| {
            unsafe {
                INSTANCE = Some(Arc::new(Mutex::new(LoggerManager::new())));
            }
        });
        
        unsafe {
            INSTANCE.as_ref().unwrap().clone()
        }
    }
}

impl ChangeManager for LoggerManager {
    fn register(&mut self, subject: &dyn Subject, observer: Box<dyn Observer>) {
        // 立即通知观察者
        observer.update(subject);
    }
    
    fn unregister(&mut self, _subject: &dyn Subject, _observer: &dyn Observer) {
        // 空实现
    }
    
    fn notify(&self) {
        // 空实现
    }
}

