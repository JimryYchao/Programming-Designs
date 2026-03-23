# 终结符表达式 - 处理数字
class NumberExpr:
    def __init__(self, num):
        self.num = num
    
    def interpret(self):
        return self.num