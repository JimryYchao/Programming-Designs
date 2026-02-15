-- 加载产品模块
require("Target")

-- 适配器类
---@class PlayerAdapter : IPlayer
PlayerAdapter = IPlayer:new()

function PlayerAdapter:new(o)
    o = o or {}
    ---@type Player
    o.player = Player:new()
    ---@type AudioPlayer
    o.audioPlayer = AudioPlayer:new()
    ---@type VideoPlayer
    o.videoPlayer = VideoPlayer:new()
    setmetatable(o, self)
    self.__index = self
    return o
end

function PlayerAdapter:play(fileName, typ)
    -- 调用原始播放器
    self.player:play(fileName, typ)
    -- 调用音频播放器
    self.audioPlayer:playMedia(fileName, typ)
    -- 调用视频播放器
    self.videoPlayer:playMedia(fileName, typ)
end
