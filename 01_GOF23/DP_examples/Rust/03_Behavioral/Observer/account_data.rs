use std::collections::HashMap;
use std::sync::Arc;
use std::sync::Mutex;
use std::any::Any;
use crate::subject::{Subject, Observer};
use crate::observer::{LoginSuccessful, LoginFailed, RegisterSuccessful, RegisterFailed};

// 账户数据管理
pub struct AccountData {
    accounts: HashMap<String, String>,
    observers: Vec<Box<dyn Observer>>,
}

impl AccountData {
    fn new() -> Self {
        Self {
            accounts: HashMap::new(),
            observers: Vec::new(),
        }
    }
    
    pub fn get_instance() -> Arc<Mutex<Self>> {
        static mut INSTANCE: Option<Arc<Mutex<AccountData>>> = None;
        static ONCE: std::sync::Once = std::sync::Once::new();
        
        ONCE.call_once(|| {
            unsafe {
                INSTANCE = Some(Arc::new(Mutex::new(AccountData::new())));
            }
        });
        
        unsafe {
            INSTANCE.as_ref().unwrap().clone()
        }
    }
    
    pub fn login_account(&mut self, account: &str, password: &str) {
        if let Some(pwd) = self.accounts.get(account) {
            if pwd == password {
                self.attach(Box::new(LoginSuccessful::new()));
                return;
            }
        }
        self.attach(Box::new(LoginFailed::new()));
    }
    
    pub fn register_account(&mut self, account: &str, password: &str) {
        if !self.accounts.contains_key(account) {
            self.accounts.insert(account.to_string(), password.to_string());
            self.attach(Box::new(RegisterSuccessful::new()));
        } else {
            self.attach(Box::new(RegisterFailed::new()));
        }
    }
}

impl Subject for AccountData {
    fn attach(&mut self, observer: Box<dyn Observer>) {
        // 立即通知观察者（模拟LoggerManager的行为）
        observer.update(self);
    }
    
    fn detach(&mut self, _observer: &dyn Observer) {
        // 空实现
    }
    
    fn notify(&self) {
        // 空实现，因为我们在attach时已经立即通知了
    }
    
    fn as_any(&self) -> &dyn Any {
        self
    }
}

// 为了支持单例模式，需要导入Mutex和Any
