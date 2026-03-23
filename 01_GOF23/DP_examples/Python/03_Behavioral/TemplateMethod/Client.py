# 客户端代码
from ConcreteClass import CoffeeMaker, TeaMaker

def main():
    # 制作咖啡
    print("Making coffee:")
    coffee = CoffeeMaker()
    coffee.make_beverage()
    print()
    
    # 制作茶
    print("Making tea:")
    tea = TeaMaker()
    tea.make_beverage()

if __name__ == "__main__":
    main()
