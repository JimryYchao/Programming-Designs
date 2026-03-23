mod component;
mod concrete_composite;

use concrete_composite::Employee;
use component::IComponent;

// 构建团队
fn build_a_team() -> Box<dyn IComponent> {
    // 创建老板
    let mut boss = Employee::new(false).init("Tom", "man", 45, 50000);

    // 创建主管
    let mut charge_a = Employee::new(false).init("Lily", "woman", 25, 12000);
    let mut charge_b = Employee::new(false).init("Jerry", "man", 27, 11000);

    // 创建基础员工
    let base_a = Employee::new(true).init("Lee", "woman", 21, 8000);
    let base_b = Employee::new(true).init("Ychao", "man", 21, 7500);
    let base_c = Employee::new(true).init("Tomas", "man", 22, 7000);
    let base_d = Employee::new(true).init("Jimmy", "man", 23, 8200);

    // 构建层级关系
    charge_a.add(Box::new(base_a));
    charge_a.add(Box::new(base_b));
    charge_b.add(Box::new(base_c));
    charge_b.add(Box::new(base_d));
    boss.add(Box::new(charge_a));
    boss.add(Box::new(charge_b));

    Box::new(boss)
}

// 测试 Composite 模式
fn main() {
    let tree = build_a_team();
    tree.operation();
}
