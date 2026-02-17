from Component import Composite

# 员工类
class Employee(Composite):
    def __init__(self, is_base_employee):
        super().__init__(is_base_employee)
        self.name = ""
        self.sex = ""
        self.age = 0
        self.salary = 0
    
    # 初始化员工信息
    def init(self, name, sex, age, salary):
        self.name = name
        self.sex = sex
        self.age = age
        self.salary = salary
        return self
    
    # 重写 operation 方法
    def operation(self):
        print(f"[Name:{self.name}][Age:{self.age}][Sex:{self.sex}]:Doing some work, and ", end="")
        if self.sex == "man":
            print(f"his salary is {self.salary}.", end="")
        else:
            print(f"her salary is {self.salary}.", end="")
        if not self.is_leaf():
            print(f" who has {len(self._sub_composites)} Employees work under.")
        else:
            print()
        super().operation()
