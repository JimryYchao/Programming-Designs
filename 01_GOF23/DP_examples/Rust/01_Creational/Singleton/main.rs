mod singleton;
use singleton::{SINGLETON_IMMUTABLE, SINGLETON_MUTABLE, THREAD_SAFE_SINGLETON, get_singleton_once_cell};

use std::thread;

fn main() {
    println!("=== Testing Immutable Singletons ===");
    
    // 测试 Lazy 单例
    println!("Accessing Lazy singleton...");
    println!("Lazy singleton value: {}", SINGLETON_IMMUTABLE.value);
    println!("Accessing Lazy singleton again...");
    println!("Lazy singleton value: {}", SINGLETON_IMMUTABLE.value);
    
    // 测试 OnceCell 单例
    println!("\nAccessing OnceCell singleton...");
    println!("OnceCell singleton value: {}", get_singleton_once_cell().value);
    println!("Accessing OnceCell singleton again...");
    println!("OnceCell singleton value: {}", get_singleton_once_cell().value);
    
    println!("\n=== Testing Mutable Singletons ===");
    
    // 测试可变单例
    {
        let mut singleton = SINGLETON_MUTABLE.lock().unwrap();
        println!("Initial mutable singleton value: {}", singleton.get_value());
        singleton.increment();
        println!("After increment: {}", singleton.get_value());
    }
    
    {
        let mut singleton = SINGLETON_MUTABLE.lock().unwrap();
        singleton.increment();
        println!("After second increment: {}", singleton.get_value());
    }
    
    println!("\n=== Testing Thread-Safe Mutable Singleton ===");
    
    // 测试线程安全的可变单例
    let singleton_clone = THREAD_SAFE_SINGLETON.clone();
    
    let handle = thread::spawn(move || {
        for _ in 0..1000 {
            let mut singleton = singleton_clone.lock().unwrap();
            singleton.increment();
        }
    });
    
    let singleton_clone2 = THREAD_SAFE_SINGLETON.clone();
    let handle2 = thread::spawn(move || {
        for _ in 0..1000 {
            let mut singleton = singleton_clone2.lock().unwrap();
            singleton.increment();
        }
    });
    
    handle.join().unwrap();
    handle2.join().unwrap();
    
    let singleton = THREAD_SAFE_SINGLETON.lock().unwrap();
    println!("Final value after 2000 increments: {}", singleton.get_value());
}
