from originator import Originator
from caretaker import Caretaker

# 测试代码
def main():
    # 创建发起人
    o = Originator("Hello", "World", "!")
    
    # 创建管理者
    caretaker = Caretaker()
    
    # 保存第一版
    caretaker.save_memento(1, o.create_memento(1))
    
    # 修改状态
    o = Originator("X", "Y", "Z")
    o.console_state()
    
    # 恢复第一版
    memento = caretaker.get_memento(1)
    o.set_memento(memento)
    o.console_state()

# 运行测试
if __name__ == "__main__":
    main()
