from ConcreteComposite import Employee

# 构建团队
def build_a_team():
    # 创建老板
    boss = Employee(False).init("Tom", "man", 45, 50000)

    # 创建主管
    charge_a = Employee(False).init("Lily", "woman", 25, 12000)
    charge_b = Employee(False).init("Jerry", "man", 27, 11000)

    # 创建基础员工
    base_a = Employee(True).init("Lee", "woman", 21, 8000)
    base_b = Employee(True).init("Ychao", "man", 21, 7500)
    base_c = Employee(True).init("Tomas", "man", 22, 7000)
    base_d = Employee(True).init("Jimmy", "man", 23, 8200)

    # 构建层级关系
    boss.add(charge_a)
    boss.add(charge_b)
    charge_a.add(base_a)
    charge_a.add(base_b)
    charge_b.add(base_c)
    charge_b.add(base_d)

    return boss

# 测试 Composite 模式
if __name__ == "__main__":
    tree = build_a_team()
    tree.operation()
