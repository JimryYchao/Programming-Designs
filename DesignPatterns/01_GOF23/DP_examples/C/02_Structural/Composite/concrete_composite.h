#pragma once
#include "component.h"

// 员工结构体
typedef struct Employee {
    Composite composite;
    char name[50];
    char sex[10];
    int age;
    int salary;
} Employee;

// 初始化员工
void Employee_init(Employee* employee, bool is_base_employee);
Employee* Employee_init_info(Employee* employee, const char* name, const char* sex, int age, int salary);
void Employee_destroy(Employee* employee);

// 销毁员工
