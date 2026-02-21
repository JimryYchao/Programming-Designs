-- 加载 Flyweight 模块
require("Flyweight")
require("UnsharedFlyweight")

-- 享元工厂
---@class FlyweightFactory
---@field shapeDic table<string, table<number, CircleData>>
---@field circleFactory CircleFactory
FlyweightFactory = {
    shapeDic = { __mode = "v" },
}

-- 获取圆形
---@param color string
---@param radius number
---@param x number
---@param y number
---@return Circle
function FlyweightFactory:getCircle(color, radius, x, y)
    local circle = nil
    -- 查找颜色
    if self.shapeDic[color] then
        -- 查找半径
        if self.shapeDic[color][radius] then
            -- 复用已有的 CircleData
            return CircleFactory:getCircleByData(self.shapeDic[color][radius], x, y)
        else
            -- 创建新的圆形
            circle = CircleFactory:getCircle(color, radius, x, y)
            if circle then
                self.shapeDic[color][radius] = circle.data
            end
        end
    else
        -- 创建新的颜色条目
        self.shapeDic[color] = {}
        -- 创建新的圆形
        circle = CircleFactory:getCircle(color, radius, x, y)
        if circle then
            self.shapeDic[color][radius] = circle.data
        end
    end
    if circle then
        print(string.format("Create a New Circle Filled with %s", color))
    end
    return circle
end

-- 获取特殊圆形
function FlyweightFactory:getSpecialCircle(color, radius, x, y)
    local circle = self:getCircle(color, radius, x, y)
    if circle then
        return CircleFactory:getSpacialCircle(circle)
    end
    return nil
end
