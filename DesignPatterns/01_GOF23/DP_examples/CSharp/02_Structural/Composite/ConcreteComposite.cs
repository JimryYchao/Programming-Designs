namespace Structural.Composite;

public class Employee(bool isBaseEmployee) : Composite(isBaseEmployee) {
    public string name;
    public string sex;
    public int salary;
    public int age;
    public Employee Init(string name, string sex, int age, int salary) {
        this.name = name;
        this.sex = sex;
        this.salary = salary;
        this.age = age;
        return this;
    }
    public override void Operation() {
        Console.Write($"[Name:{name}][Age:{age}][Sex:{sex}]:Doing some work, and {(sex == "man" ? "his" : "her")} salary is {salary}.");
        if (!isBaseEmployee)
            Console.WriteLine($"who has {subComposites.Count} Employees work under.");
        else Console.WriteLine();
        base.Operation();
    }
}