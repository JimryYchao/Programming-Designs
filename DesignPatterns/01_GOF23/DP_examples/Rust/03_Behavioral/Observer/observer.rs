use crate::subject::{Observer, Subject};
use crate::account_data::AccountData;

// 登录观察者
pub struct LoginObserver {
    // 单例实例
}

impl LoginObserver {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for LoginObserver {
    fn update(&self, subject: &dyn Subject) {
        // 尝试将subject转换为ConcreteSubject
        if let Some(concrete_subject) = subject.as_any().downcast_ref::<super::subject::ConcreteSubject>() {
            let name = concrete_subject.get_state(0);
            let password = concrete_subject.get_state(1);
            AccountData::get_instance().lock().unwrap().login_account(&name, &password);
        }
    }
}

// 注册观察者
pub struct RegisterObserver {
    // 单例实例
}

impl RegisterObserver {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for RegisterObserver {
    fn update(&self, subject: &dyn Subject) {
        // 尝试将subject转换为ConcreteSubject
        if let Some(concrete_subject) = subject.as_any().downcast_ref::<super::subject::ConcreteSubject>() {
            let name = concrete_subject.get_state(0);
            let password = concrete_subject.get_state(1);
            AccountData::get_instance().lock().unwrap().register_account(&name, &password);
        }
    }
}

// 登录成功观察者
pub struct LoginSuccessful {
    // 单例实例
}

impl LoginSuccessful {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for LoginSuccessful {
    fn update(&self, _subject: &dyn Subject) {
        println!("Login Successful");
    }
}

// 登录失败观察者
pub struct LoginFailed {
    // 单例实例
}

impl LoginFailed {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for LoginFailed {
    fn update(&self, _subject: &dyn Subject) {
        println!("Login Failed");
    }
}

// 注册成功观察者
pub struct RegisterSuccessful {
    // 单例实例
}

impl RegisterSuccessful {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for RegisterSuccessful {
    fn update(&self, _subject: &dyn Subject) {
        println!("Register-Account Successful");
    }
}

// 注册失败观察者
pub struct RegisterFailed {
    // 单例实例
}

impl RegisterFailed {
    pub fn new() -> Self {
        Self {}
    }
    
    pub fn get_instance() -> Box<dyn Observer> {
        Box::new(Self::new())
    }
}

impl Observer for RegisterFailed {
    fn update(&self, _subject: &dyn Subject) {
        println!("Register-Account Failed");
    }
}
