# 观察者接口
class IObserver:
    def Update(self, subject):
        pass

# 主题接口
class ISubject:
    def Attach(self, observer):
        pass
    
    def Detach(self, observer):
        pass
    
    def Notify(self):
        pass

# 变更管理器接口
class IChangeManager:
    def Register(self, subject, observer):
        pass
    
    def Unregister(self, subject, observer):
        pass
    
    def Notify(self):
        pass
