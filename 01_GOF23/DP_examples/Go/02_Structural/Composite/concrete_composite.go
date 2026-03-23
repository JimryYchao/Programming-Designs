package Composite

import "fmt"

// 员工类
type Employee struct {
	*Composite
	Name   string
	Sex    string
	Age    int
	Salary int
}

// 创建员工实例
func NewEmployee(isBaseEmployee bool) *Employee {
	return &Employee{
		Composite: NewComposite(isBaseEmployee),
	}
}

// 初始化员工信息
func (e *Employee) Init(name, sex string, age, salary int) *Employee {
	e.Name = name
	e.Sex = sex
	e.Age = age
	e.Salary = salary
	return e
}

// 重写 Operation 方法
func (e *Employee) Operation() {
	fmt.Printf("[Name:%s][Age:%d][Sex:%s]:Doing some work, and ", e.Name, e.Age, e.Sex)
	if e.Sex == "man" {
		fmt.Printf("his salary is %d.", e.Salary)
	} else {
		fmt.Printf("her salary is %d.", e.Salary)
	}
	if !e.IsLeaf() {
		fmt.Printf(" who has %d Employees work under.", len(e.subComposites))
	}
	fmt.Println()
	e.Composite.Operation()
}
