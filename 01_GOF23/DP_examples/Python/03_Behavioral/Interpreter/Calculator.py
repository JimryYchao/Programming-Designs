# 导入必要的类
from TerminalExpression import NumberExpr
from NonterminalExpression import AdditionExpression, SubtractionExpression, MultiplicationExpression, DivisionExpression

# 计算器类，用于构建和解析表达式
class Calculator:
    @staticmethod
    def calculate(expression):
        end_expre = Calculator.create_expression_tree(expression, 0, len(expression) - 1)
        return end_expre.interpret()
    
    @staticmethod
    def find_split(expression, start, end):
        tag = -1
        if expression[start] == '(' and expression[end] == ')':
            start += 1
            end -= 1
        is_in_bracket = 0
        more_grade = 0
        for i in range(start, end + 1):
            if expression[i] == '(':
                is_in_bracket += 1
            elif expression[i] == ')':
                is_in_bracket -= 1
            if (expression[i] == '+' or expression[i] == '-') and is_in_bracket == 0:
                more_grade = 1
                tag = i
            elif (expression[i] == '*' or expression[i] == '/') and more_grade == 0 and is_in_bracket == 0:
                tag = i
        return tag
    
    @staticmethod
    def create_expression_tree(expression, start, end):
        ptree = None
        try:
            num = float(expression[start:end+1])
            ptree = NumberExpr(num)
        except ValueError:
            tag = Calculator.find_split(expression, start, end)
            if tag < 0:
                # 处理括号内的数字
                s = expression[start:end+1].replace('(', '').replace(')', '')
                num = float(s)
                ptree = NumberExpr(num)
            else:
                if expression[tag] == '+':
                    ptree = AdditionExpression(
                        Calculator.create_expression_tree(expression, start, tag - 1),
                        Calculator.create_expression_tree(expression, tag + 1, end)
                    )
                elif expression[tag] == '-':
                    ptree = SubtractionExpression(
                        Calculator.create_expression_tree(expression, start, tag - 1),
                        Calculator.create_expression_tree(expression, tag + 1, end)
                    )
                elif expression[tag] == '*':
                    ptree = MultiplicationExpression(
                        Calculator.create_expression_tree(expression, start, tag - 1),
                        Calculator.create_expression_tree(expression, tag + 1, end)
                    )
                elif expression[tag] == '/':
                    ptree = DivisionExpression(
                        Calculator.create_expression_tree(expression, start, tag - 1),
                        Calculator.create_expression_tree(expression, tag + 1, end)
                    )
        return ptree