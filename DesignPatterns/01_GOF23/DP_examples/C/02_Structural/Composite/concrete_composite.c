#include "concrete_composite.h"
#include <stdio.h>
#include <string.h>

// 员工操作方法
static void Employee_operation(struct ILeaf *self)
{
    Employee *employee = (Employee *)self;
    printf("[Name:%s][Age:%d][Sex:%s]:Doing some work, and ", employee->name, employee->age, employee->sex);
    if(strcmp(employee->sex, "man") == 0) {
            printf("his salary is %d.", employee->salary);
    } else if(strcmp(employee->sex, "woman") == 0) 
        printf("her salary is %d.", employee->salary);
    if (!employee->composite.base.base.is_leaf) {
        printf(" who has %d Employees work under.", employee->composite.count);
    }
    puts("");
}

// 初始化员工
void Employee_init(Employee* employee, bool is_base_employee) {
    Composite_init(&employee->composite, is_base_employee);
    // 重写 operation 方法
    employee->composite.base.base.operation = Employee_operation;
    // 初始化成员变量
    employee->name[0] = '\0';
    employee->sex[0] = '\0';
    employee->age = 0;
    employee->salary = 0;
}

// 初始化员工信息
Employee* Employee_init_info(Employee* employee, const char* name, const char* sex, int age, int salary) {
    strncpy_s(employee->name, sizeof(employee->name), name, sizeof(employee->name) - 1);
    employee->name[sizeof(employee->name) - 1] = '\0';
    strncpy_s(employee->sex, sizeof(employee->sex), sex, sizeof(employee->sex) - 1);
    employee->sex[sizeof(employee->sex) - 1] = '\0';
    employee->age = age;
    employee->salary = salary;
    return employee;
}

void Employee_destroy(Employee* employee) {
    Composite_destroy(&employee->composite);
}
