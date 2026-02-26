#include "Originator.hpp"
#include "Caretaker.hpp"

int main() {
    // 创建发起人
    Originator* o = new Originator("Hello", "World", "!");
    
    // 创建管理者
    Caretaker* caretaker = new Caretaker();
    
    // 保存第一版
    caretaker->saveMemento(1, o->createMemento(1));
    
    // 修改状态
    delete o;
    o = new Originator("X", "Y", "Z");
    o->consoleState();
    
    // 恢复第一版
    Memento* memento = caretaker->getMemento(1);
    o->setMemento(memento);
    o->consoleState();
    
    // 清理资源
    delete o;
    delete caretaker;
    
    return 0;
}
