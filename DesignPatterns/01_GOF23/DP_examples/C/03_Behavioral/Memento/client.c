#include "originator.h"
#include "caretaker.h"

int main() {
    // 创建发起人
    Originator* o = create_originator("Hello", "World", "!");
    
    // 创建管理者
    Caretaker* caretaker = create_caretaker(10);
    
    // 保存第一版
    Memento* m1 = create_memento_from_originator(o, 1);
    save_memento(caretaker, 1, m1);
    
    // 修改状态
    destroy_originator(o);
    o = create_originator("X", "Y", "Z");
    console_state(o);
    
    // 恢复第一版
    Memento* memento = get_memento(caretaker, 1);
    set_memento_to_originator(o, memento);
    console_state(o);
    
    // 清理资源
    destroy_originator(o);
    destroy_caretaker(caretaker);
}

// gcc -o client client.c originator.c caretaker.c memento.c
