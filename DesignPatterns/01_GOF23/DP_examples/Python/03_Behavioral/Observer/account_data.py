from observer import ISubject
from change_manager import LoggerManager

# 账户数据
class AccountData(ISubject):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(AccountData, cls).__new__(cls)
            cls._instance.accounts = {}
            cls._instance.changer = LoggerManager()
        return cls._instance
    
    def LoginAccount(self, account, password):
        if account in self.accounts:
            if self.accounts[account] == password:
                self.Attach(LoginSuccessful())
                return
        self.Attach(LoginFailed())
    
    def RegisterAccount(self, account, password):
        if account not in self.accounts:
            self.accounts[account] = password
            self.Attach(RegisterSuccessful())
        else:
            self.Attach(RegisterFailed())
    
    def Attach(self, observer):
        self.changer.Register(self, observer)
    
    def Detach(self, observer):
        self.changer.Unregister(self, observer)
    
    def Notify(self):
        self.changer.Notify()

# 登录成功观察者
class LoginSuccessful:
    def Update(self, subject):
        print("Login Successful")

# 登录失败观察者
class LoginFailed:
    def Update(self, subject):
        print("Login Failed")

# 注册成功观察者
class RegisterSuccessful:
    def Update(self, subject):
        print("Register-Account Successful")

# 注册失败观察者
class RegisterFailed:
    def Update(self, subject):
        print("Register-Account Failed")
