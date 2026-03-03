use once_cell::sync::{Lazy, OnceCell};
use lazy_static::lazy_static;
use std::sync::{Mutex, Arc};

// 不可变单例 - 使用 once_cell::Lazy
#[derive(Debug)]
pub struct SingletonImmutable {
    pub value: i32,
}

pub static SINGLETON_IMMUTABLE: Lazy<SingletonImmutable> = Lazy::new(|| {
    println!("Creating immutable singleton");
    SingletonImmutable { value: 42 }
});

// 不可变单例 - 使用 once_cell::OnceCell
#[derive(Debug)]
pub struct SingletonOnceCell {
    pub value: String,
}

pub static SINGLETON_ONCE_CELL: OnceCell<SingletonOnceCell> = OnceCell::new();

pub fn get_singleton_once_cell() -> &'static SingletonOnceCell {
    SINGLETON_ONCE_CELL.get_or_init(|| {
        println!("Creating OnceCell singleton");
        SingletonOnceCell { value: String::from("Hello, OnceCell!") }
    })
}

// 可变单例 - 使用 Mutex
#[derive(Debug)]
pub struct SingletonMutable {
    pub value: i32,
}

impl SingletonMutable {
    pub fn increment(&mut self) {
        self.value += 1;
    }
    
    pub fn get_value(&self) -> i32 {
        self.value
    }
}

lazy_static! {
    pub static ref SINGLETON_MUTABLE: Mutex<SingletonMutable> = Mutex::new(
        SingletonMutable { value: 0 }
    );
}

// 可变单例 - 使用 Arc<Mutex> 用于多线程
#[derive(Debug, Clone)]
pub struct ThreadSafeSingleton {
    pub value: i32,
}

impl ThreadSafeSingleton {
    pub fn increment(&mut self) {
        self.value += 1;
    }
    
    pub fn get_value(&self) -> i32 {
        self.value
    }
}

lazy_static! {
    pub static ref THREAD_SAFE_SINGLETON: Arc<Mutex<ThreadSafeSingleton>> = Arc::new(
        Mutex::new(ThreadSafeSingleton { value: 0 })
    );
}

