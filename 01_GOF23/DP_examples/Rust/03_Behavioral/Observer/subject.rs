use std::sync::{Arc, Mutex};
use std::any::Any;
use crate::observer::{LoginObserver, RegisterObserver};

pub trait Observer {
    fn update(&self, subject: &dyn Subject);
}

pub trait Subject {
    fn attach(&mut self, observer: Box<dyn Observer>);
    fn detach(&mut self, observer: &dyn Observer);
    fn notify(&self);
    fn as_any(&self) -> &dyn Any;
}

// 具体主题实现
pub struct ConcreteSubject {
    name: String,
    password: String,
    observers: Mutex<Vec<Box<dyn Observer>>>,
}

impl ConcreteSubject {
    fn new() -> Self {
        Self {
            name: String::new(),
            password: String::new(),
            observers: Mutex::new(Vec::new()),
        }
    }
    
    pub fn get_instance() -> Arc<Mutex<Self>> {
        static mut INSTANCE: Option<Arc<Mutex<ConcreteSubject>>> = None;
        static ONCE: std::sync::Once = std::sync::Once::new();
        
        ONCE.call_once(|| {
            unsafe {
                INSTANCE = Some(Arc::new(Mutex::new(ConcreteSubject::new())));
            }
        });
        
        unsafe {
            INSTANCE.as_ref().unwrap().clone()
        }
    }
    
    pub fn register_account(&mut self, name: &str, password: &str) {
        self.name = name.to_string();
        self.password = password.to_string();
        self.attach(Box::new(RegisterObserver::new()));
    }
    
    pub fn login_account(&mut self, name: &str, password: &str) {
        self.name = name.to_string();
        self.password = password.to_string();
        self.attach(Box::new(LoginObserver::new()));
    }
    
    pub fn get_state(&self, state: i32) -> String {
        match state {
            0 => self.name.clone(),
            1 => self.password.clone(),
            _ => String::new(),
        }
    }
}

impl Subject for ConcreteSubject {
    fn attach(&mut self, observer: Box<dyn Observer>) {
        let mut observers = self.observers.lock().unwrap();
        // 检查观察者是否已经存在
        if !observers.iter().any(|o| {
            // 简单比较，实际应用中可能需要更复杂的比较
            std::any::type_name_of_val(o) == std::any::type_name_of_val(&observer)
        }) {
            observers.push(observer);
        }
    }
    
    fn detach(&mut self, observer: &dyn Observer) {
        let mut observers = self.observers.lock().unwrap();
        observers.retain(|o| {
            // 简单比较，实际应用中可能需要更复杂的比较
            std::any::type_name_of_val(o) != std::any::type_name_of_val(observer)
        });
    }
    
    fn notify(&self) {
        let mut observers = self.observers.lock().unwrap();
        for observer in &*observers {
            observer.update(self);
        }
        // 清空观察者列表
        observers.clear();
    }
    
    fn as_any(&self) -> &dyn Any {
        self
    }
}
