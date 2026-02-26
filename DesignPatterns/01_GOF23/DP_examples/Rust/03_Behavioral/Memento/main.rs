mod memento;

use memento::{Originator, Caretaker};

fn main() {
    // 创建发起人
    let mut originator = Originator::new("Hello", "World", "!");
    // 创建 caretaker
    let mut caretaker = Caretaker::new();

    // 保存第一版
    caretaker.save_memento(1, originator.create_memento(1));

    // 创建新的状态
    originator = Originator::new("X", "Y", "Z");
    println!("Current state:");
    originator.console_state();

    // 恢复第一版
    if let Some(memento) = caretaker.get_memento(1) {
        originator.set_memento(memento);
        println!("\nRestored state:");
        originator.console_state();
    }
}
