from Singleton import Singleton, Singleton_Lock, Singleton_Lazy, MonoSingleton, GameSingleton, DecoratorSingleton

if __name__ == "__main__":
    # 测试非线程安全单例
    s1 = Singleton()
    s2 = Singleton()
    if id(s1) == id(s2):
        s1.show_message()
    
    # 测试线程安全单例
    sl1 = Singleton_Lock()
    sl2 = Singleton_Lock()
    if id(sl1) == id(sl2):
        sl1.show_message()
    
    # 测试延迟加载单例
    slazy1 = Singleton_Lazy.get_instance()
    slazy2 = Singleton_Lazy.get_instance()
    if id(slazy1) == id(slazy2):
        slazy1.show_message()
    
    
    # 测试继承单例
    ms = MonoSingleton.get_instance()
    gs = GameSingleton.get_instance()
    if id(ms) != id(gs):
        ms.log()
        gs.log()
    
    # 测试装饰器单例
    ds1 = DecoratorSingleton()
    ds2 = DecoratorSingleton()
    if id(ds1) == id(ds2):
        ds1.show_message()
