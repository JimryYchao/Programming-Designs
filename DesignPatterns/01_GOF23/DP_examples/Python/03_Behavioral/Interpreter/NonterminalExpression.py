# 非终结符表达式 - 处理运算符
class OperationExpression:
    def __init__(self, exp1, exp2):
        self.exp1 = exp1
        self.exp2 = exp2
    
    def interpret(self):
        pass

class AdditionExpression(OperationExpression):
    def interpret(self):
        return self.exp1.interpret() + self.exp2.interpret()

class SubtractionExpression(OperationExpression):
    def interpret(self):
        return self.exp1.interpret() - self.exp2.interpret()

class MultiplicationExpression(OperationExpression):
    def interpret(self):
        return self.exp1.interpret() * self.exp2.interpret()

class DivisionExpression(OperationExpression):
    def interpret(self):
        return self.exp1.interpret() / self.exp2.interpret()