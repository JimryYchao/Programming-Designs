# 饮料制作抽象类
class BeverageMaker:
    # 模板方法：制作饮料的流程
    def make_beverage(self):
        self.boil_water()
        self.brew()
        self.pour_in_cup()
        if self.customer_wants_condiments():
            self.add_condiments()
    
    # 具体方法：烧水
    def boil_water(self):
        print("Boiling water")
    
    # 具体方法：倒入杯子
    def pour_in_cup(self):
        print("Pouring into cup")
    
    # 抽象方法：冲泡
    def brew(self):
        pass
    
    # 抽象方法：添加调料
    def add_condiments(self):
        pass
    
    # 钩子方法：顾客是否需要调料
    def customer_wants_condiments(self):
        return True
