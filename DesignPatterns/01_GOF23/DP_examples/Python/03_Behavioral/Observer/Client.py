from concrete_subject import Subject

# 测试代码
def main():
    # 测试注册
    subject = Subject()
    subject.RegisterAccount("test", "123456")
    subject.Notify()
    
    # 测试重复注册
    subject.RegisterAccount("test", "123456")
    subject.Notify()
    
    # 测试登录
    subject.LoginAccount("test", "123456")
    subject.Notify()
    
    # 测试登录失败
    subject.LoginAccount("test", "wrong")
    subject.Notify()

# 运行测试
if __name__ == "__main__":
    main()
