require("Component")

-- 员工类
---@class Employee : Composite
---@field name string
---@field sex string
---@field age number
---@field salary number
Employee = Composite:new(false)

-- 构造函数
function Employee:new(isBaseEmployee)
    local o = Composite.new(self, isBaseEmployee)
    o.name = ""
    o.sex = ""
    o.age = 0
    o.salary = 0
    return o
end

-- 初始化员工信息
---@param name string
---@param sex string
---@param age number
---@param salary number
---@return Employee
function Employee:init(name, sex, age, salary)
    self.name = name
    self.sex = sex
    self.age = age
    self.salary = salary
    return self
end

function Employee:operation()
    io.write(string.format("[Name:%s][Age:%d][Sex:%s]:Doing some work, and ", self.name, self.age, self.sex))
    if self.sex == "man" then
        io.write(string.format("his salary is %d.", self.salary))
    else
        io.write(string.format("her salary is %d.", self.salary))
    end
    if not self.isLeaf then
        io.write(string.format(" who has %d Employees work under.", #self._subComposites))
    end
    io.write("\n")
    Composite.operation(self)
end
