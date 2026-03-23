-- 客户端代码，用于测试解释器模式
require("Calculator")

print(Calculator.calculate("1+2+3"))
print(Calculator.calculate("2*(1+2)"))
print(Calculator.calculate("2+(1+2*5)"))
print(Calculator.calculate("2*(1+2*6)"))
print(Calculator.calculate("(68*(115+20)+10)"))