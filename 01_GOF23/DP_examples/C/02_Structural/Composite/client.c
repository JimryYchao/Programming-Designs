#include "concrete_composite.h"
#include <stdlib.h>


// 构建团队
static IComponent* BuildATeam() {
    // 创建老板
    Employee* boss = (Employee*)malloc(sizeof(Employee));
    Employee_init(boss, false);
    Employee_init_info(boss, "Tom", "man", 45, 50000);

    // 创建主管
    Employee* chargeA = (Employee*)malloc(sizeof(Employee));
    Employee_init(chargeA, false);
    Employee_init_info(chargeA, "Lily", "woman", 25, 12000);

    Employee* chargeB = (Employee*)malloc(sizeof(Employee));
    Employee_init(chargeB, false);
    Employee_init_info(chargeB, "Jerry", "man", 27, 11000);

    // 创建基础员工
    Employee* baseA = (Employee*)malloc(sizeof(Employee));
    Employee_init(baseA, true);
    Employee_init_info(baseA, "Lee", "woman", 21, 8000);

    Employee* baseB = (Employee*)malloc(sizeof(Employee));
    Employee_init(baseB, true);
    Employee_init_info(baseB, "Ychao", "man", 21, 7500);

    Employee* baseC = (Employee*)malloc(sizeof(Employee));
    Employee_init(baseC, true);
    Employee_init_info(baseC, "Tomas", "man", 22, 7000);

    Employee* baseD = (Employee*)malloc(sizeof(Employee));
    Employee_init(baseD, true);
    Employee_init_info(baseD, "Jimmy", "man", 23, 8200);

    // 构建层级关系
    ((struct IComponent*)boss)->add((struct IComponent*)boss, (struct IComponent*)chargeA);
    ((struct IComponent*)boss)->add((struct IComponent*)boss, (struct IComponent*)chargeB);
    ((struct IComponent*)chargeA)->add((struct IComponent*)chargeA, (struct IComponent*)baseA);
    ((struct IComponent*)chargeA)->add((struct IComponent*)chargeA, (struct IComponent*)baseB);
    ((struct IComponent*)chargeB)->add((struct IComponent*)chargeB, (struct IComponent*)baseC);
    ((struct IComponent*)chargeB)->add((struct IComponent*)chargeB, (struct IComponent*)baseD);

    return (IComponent*)boss;
}

// 测试 Composite 模式
int main() {
    IComponent* tree = BuildATeam();
    tree->operation(tree);
    Employee_destroy((Employee*)tree);
}

// gcc -o client client.c component.c concrete_composite.c