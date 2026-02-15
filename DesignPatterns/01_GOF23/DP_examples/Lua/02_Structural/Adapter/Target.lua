require("Adaptee")

-- 目标接口
---@class IPlayer
IPlayer = {
    ---@param fileName string
    ---@param typ MediaType
    ---@type fun(self: IPlayer, fileName: string, typ: MediaType)
    play = function(self, fileName, typ)
        error("Subclass must implement play method")
    end
}

function IPlayer:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 具体目标类
---@class Player : IPlayer
Player = IPlayer:new()

function Player:play(fileName, typ)
    if typ == MediaType.MP3 then
        print("PlayAudio mp3 : " .. fileName)
    end
end