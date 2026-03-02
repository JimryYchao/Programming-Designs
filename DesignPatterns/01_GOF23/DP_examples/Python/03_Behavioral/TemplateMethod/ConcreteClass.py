# 具体饮料实现
from AbstractClass import BeverageMaker

# 咖啡制作类
class CoffeeMaker(BeverageMaker):
    # 实现冲泡方法
    def brew(self):
        print("Brewing coffee grounds")
    
    # 实现添加调料方法
    def add_condiments(self):
        print("Adding sugar and milk")
    
    # 重写钩子方法
    def customer_wants_condiments(self):
        print("Customer wants sugar and milk")
        return True

# 茶制作类
class TeaMaker(BeverageMaker):
    # 实现冲泡方法
    def brew(self):
        print("Steeping the tea bag")
    
    # 实现添加调料方法
    def add_condiments(self):
        print("Adding lemon")
    
    # 重写钩子方法
    def customer_wants_condiments(self):
        print("Customer wants lemon")
        return True
