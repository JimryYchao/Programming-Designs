from observer import ISubject
from change_manager import SimpleChangeManager

# 具体主题
class Subject(ISubject):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Subject, cls).__new__(cls)
            cls._instance.name = ""
            cls._instance.password = ""
            cls._instance.changeMgr = SimpleChangeManager(cls._instance)
        return cls._instance
    
    def RegisterAccount(self, name, password):
        self.name = name
        self.password = password
        self.Attach(RegisterObserver())
    
    def LoginAccount(self, name, password):
        self.name = name
        self.password = password
        self.Attach(LoginObserver())
    
    def GetState(self, state):
        if state == 0:
            return self.name
        elif state == 1:
            return self.password
        else:
            return ""
    
    def Attach(self, observer):
        self.changeMgr.Register(self, observer)
    
    def Detach(self, observer):
        self.changeMgr.Unregister(self, observer)
    
    def Notify(self):
        self.changeMgr.Notify()
        self.changeMgr.ClearObserver()

# 登录观察者
class LoginObserver:
    def Update(self, subject):
        from account_data import AccountData
        AccountData().LoginAccount(subject.GetState(0), subject.GetState(1))

# 注册观察者
class RegisterObserver:
    def Update(self, subject):
        from account_data import AccountData
        AccountData().RegisterAccount(subject.GetState(0), subject.GetState(1))
