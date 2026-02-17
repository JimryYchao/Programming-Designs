#pragma once
#include "Component.hpp"
#include <string>
#include <iostream>

// 员工类
class Employee : public Composite {
private:
    std::string _name;
    std::string _sex;
    int _age;
    int _salary;

public:
    Employee(bool isBaseEmployee) : Composite(isBaseEmployee) {}
    virtual ~Employee() = default;
    
    // 初始化员工信息
    Employee* init(const std::string& name, const std::string& sex, int age, int salary);
    void operation() override;
};

// 初始化员工信息
Employee *Employee::init(const std::string &name, const std::string &sex, int age, int salary)
{
    _name = name;
    _sex = sex;
    _age = age;
    _salary = salary;
    return this;
}

// 重写 operation 方法
void Employee::operation() 
{
    std::cout << "[Name:" << _name << "]";
    std::cout << "[Age:" << _age << "]";
    std::cout << "[Sex:" << _sex << "]";
    std::cout << ":Doing some work, and ";

    if (_sex == "man")
        std::cout << "his salary is " << _salary << ".";
    else if (_sex == "woman")
        std::cout << "her salary is " << _salary << ".";
    else ;

    if (!isLeaf)
        std::cout << " who has " << _subComposites.size() << " Employees work under.";
    std::cout << std::endl;
    Composite::operation();
}
