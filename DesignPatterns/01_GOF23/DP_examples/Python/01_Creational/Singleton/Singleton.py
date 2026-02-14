import threading

# 非线程安全单例
class Singleton:
    _instance = None
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance
    
    def show_message(self):
        print("Singleton instance")

# 线程安全单例
class Singleton_Lock:
    _instance = None
    _lock = threading.Lock()
    
    def __new__(cls):
        if cls._instance is None:
            with cls._lock:
                if cls._instance is None:
                    cls._instance = super().__new__(cls)
        return cls._instance
    
    def show_message(self):
        print("Singleton_Lock instance")

# 延迟加载单例
class Singleton_Lazy:
    _instance = None
    
    @classmethod
    def get_instance(cls):
        if cls._instance is None:
            cls._instance = cls()
        return cls._instance
    
    def show_message(self):
        print("Singleton_Lazy instance")

# 继承单例基类
class Singleton_Inherit:
    _instances = {}
    
    @classmethod
    def get_instance(cls):
        if cls not in cls._instances:
            cls._instances[cls] = cls()
        return cls._instances[cls]
    
    def log(self):
        pass

class MonoSingleton(Singleton_Inherit):
    def log(self):
        print("MonoSingleton is created")

class GameSingleton(Singleton_Inherit):
    def log(self):
        print("GameSingleton is created")

# 装饰器实现单例
def singleton(cls):
    instances = {}
    
    def get_instance(*args, **kwargs):
        if cls not in instances:
            instances[cls] = cls(*args, **kwargs)
        return instances[cls]
    
    return get_instance

@singleton
class DecoratorSingleton:
    def show_message(self):
        print("DecoratorSingleton instance")