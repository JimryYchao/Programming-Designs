-- 叶子接口

---@class ILeaf
---@field isLeaf boolean
---@field operation fun(self: ILeaf)
ILeaf = {}

-- 抽象操作方法
function ILeaf:operation()
    error("Subclass must implement operation method")
end
function ILeaf:isLeaf()
    return self.isLeaf
end

-- 创建 ILeaf 实例
---@param o table
function ILeaf:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 组件接口
---@class IComponent : ILeaf
---@func add fun(self: IComponent, component: IComponent)
---@func remove fun(self: IComponent, component: IComponent)
---@func getChild fun(self: IComponent, index: number)
IComponent = ILeaf:new()
---@param component IComponent
function IComponent:add(component)
    error("Subclass must implement add method")
end
---@param component IComponent
function IComponent:remove(component)
    error("Subclass must implement remove method")
end
---@param index number
function IComponent:getChild(index)
    error("Subclass must implement getChild method")
end
function IComponent:operation()
    error("Subclass must implement operation method")
end
-- 组合类
---@class Composite : IComponent
---@field _subComposites IComponent[]
Composite = IComponent:new()
function Composite:new(isLeaf)
    local o = IComponent.new(self)
    ---@type IComponent[]
    o._subComposites = {}
    o.isLeaf = isLeaf
    return o
end

function Composite:operation()
    if not self.isLeaf then
        for _, comp in ipairs(self._subComposites) do
            comp:operation()
        end
    end
end

-- 添加组件
---@param component IComponent
function Composite:add(component)
    if self.isLeaf or component == nil then
        return -1
    end
    for _, comp in ipairs(self._subComposites) do
        if comp == component then
            return -1
        end
    end
    table.insert(self._subComposites, component)
    return #self._subComposites
end

-- 移除组件
---@param component IComponent
function Composite:remove(component)
    if self.isLeaf then
        return false
    end

    for i, comp in ipairs(self._subComposites) do
        if comp == component then
            table.remove(self._subComposites, i)
            return true
        end
    end
    return false
end

-- 获取子组件
---@param index number
function Composite:getChild(index)
    if index < 1 or index > #self._subComposites then
        return nil
    end
    return self._subComposites[index]
end
