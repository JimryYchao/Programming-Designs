#include "ConcreteComposite.hpp"
#include <memory>

// 构建团队
std::shared_ptr<IComponent> BuildATeam() {
    // 创建老板
    auto boss = std::make_shared<Employee>(false);
    boss->init("Tom", "man", 45, 50000);

    // 创建主管
    auto chargeA = std::make_shared<Employee>(false);
    chargeA->init("Lily", "woman", 25, 12000);

    auto chargeB = std::make_shared<Employee>(false);
    chargeB->init("Jerry", "man", 27, 11000);

    // 创建基础员工
    auto baseA = std::make_shared<Employee>(true);
    baseA->init("Lee", "woman", 21, 8000);

    auto baseB = std::make_shared<Employee>(true);
    baseB->init("Ychao", "man", 21, 7500);

    auto baseC = std::make_shared<Employee>(true);
    baseC->init("Tomas", "man", 22, 7000);

    auto baseD = std::make_shared<Employee>(true);
    baseD->init("Jimmy", "man", 23, 8200);

    // 构建层级关系
    boss->add(chargeA);
    boss->add(chargeB);
    chargeA->add(baseA);
    chargeA->add(baseB);
    chargeB->add(baseC);
    chargeB->add(baseD);
    return boss;
}

// 测试 Composite 模式
int main() {
    auto tree = BuildATeam();
    tree->operation();
}