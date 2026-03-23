-- Image 接口定义了图像处理的方法
---@class Image
Image = {}
function Image:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end
function Image:operation()
    error("子类必须实现 operation 方法")
end
function Image:loadFromDisk()
    error("子类必须实现 loadFromDisk 方法")
end