-- Builder.lua
-- 建造者接口

---@class IMealBuilder
local IMealBuilder = {
    ---@return table<IBuilder>
    GetBuilders = function(self) 
        error("子类必须实现 GetBuilder 方法")
    end,
}

---@class IBuilder
local IBuilder = {
    ---@type ItemKind
    Kind = nil,
    ---@return Item
    Build = function(self)
        error("子类必须实现 build 方法")
    end
}

---@class IPacker
local IPacker = {
    Pack = function(item)
        error("子类必须实现 pack 方法")
    end
}

---@class Item  
local Item = {
    ---@type string
    Name = "",
    ---@type number
    Price = 0,
    ---@return IPacker
    Packer = nil
}

return {
    IMealBuilder = IMealBuilder,
    IBuilder = IBuilder,
    IPacker = IPacker,
    Item = Item
}
