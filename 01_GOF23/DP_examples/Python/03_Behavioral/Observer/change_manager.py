from observer import IChangeManager

# 简单变更管理器
class SimpleChangeManager(IChangeManager):
    def __init__(self, subject):
        self.subject = subject
        self.observers = []
    
    def Register(self, subject, observer):
        if observer not in self.observers:
            self.observers.append(observer)
    
    def Unregister(self, subject, observer):
        if observer in self.observers:
            self.observers.remove(observer)
    
    def Notify(self):
        for observer in self.observers:
            observer.Update(self.subject)
    
    def ClearObserver(self):
        self.observers = []

# 多主题变更管理器
class DCGChangeManager(IChangeManager):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(DCGChangeManager, cls).__new__(cls)
            cls._instance.subject_observers = {}
        return cls._instance
    
    def Register(self, subject, observer):
        if subject not in self.subject_observers:
            self.subject_observers[subject] = []
        if observer not in self.subject_observers[subject]:
            self.subject_observers[subject].append(observer)
    
    def Unregister(self, subject, observer):
        if subject in self.subject_observers:
            if observer in self.subject_observers[subject]:
                self.subject_observers[subject].remove(observer)
    
    def Notify(self):
        for subject, observers in self.subject_observers.items():
            for observer in observers:
                observer.Update(subject)

# 日志管理器
class LoggerManager(IChangeManager):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(LoggerManager, cls).__new__(cls)
        return cls._instance
    
    def Register(self, subject, observer):
        observer.Update(subject)
    
    def Unregister(self, subject, observer):
        # 未实现
        pass
    
    def Notify(self):
        # 未实现
        pass
