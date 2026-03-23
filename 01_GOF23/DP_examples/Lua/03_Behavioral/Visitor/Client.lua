-- 导入模块
local Element = require("Element")
local ComputerPartDisplayVisitor = require("ConcreteVisitor")

-- 从返回的表中获取类
local Computer = Element[10]

-- 创建计算机对象
local computer = Computer:new()

-- 创建访问者
local visitor = ComputerPartDisplayVisitor:new()

-- 接受访问
computer:accept(visitor)
