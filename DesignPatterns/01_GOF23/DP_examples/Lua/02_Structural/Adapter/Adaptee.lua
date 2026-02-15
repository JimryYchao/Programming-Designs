-- 媒体类型枚举
---@enum MediaType
MediaType = {
    MP3 = 0,
    AIFF = 1,
    MIDI = 2,
    Wave = 3,
    MP4 = 4,
    MOV = 5,
    AVI = 6,
    M4V = 7
}

-- 被适配的接口
---@class IAdvancedMediaPlayer
IAdvancedMediaPlayer = {
    ---@param fileName string
    ---@param typ MediaType
    playMedia = function(self, fileName, typ)
        error("Subclass must implement playMedia method")
    end
}
function IAdvancedMediaPlayer:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 音频播放器（被适配的类）
---@class AudioPlayer : IAdvancedMediaPlayer
AudioPlayer = IAdvancedMediaPlayer:new()
function AudioPlayer:playMedia(fileName, typ)
    if typ == MediaType.AIFF then
        print("PlayAudio AIFF : " .. fileName)
    elseif typ == MediaType.MIDI then
        print("PlayAudio MIDI : " .. fileName)
    elseif typ == MediaType.Wave then
        print("PlayAudio wave : " .. fileName)
    end
end

-- 视频播放器（被适配的类）
---@class VideoPlayer : IAdvancedMediaPlayer
VideoPlayer = IAdvancedMediaPlayer:new()
function VideoPlayer:playMedia(fileName, typ)
    if typ == MediaType.MP4 then
        print("PlayVideo mp4 : " .. fileName)
    elseif typ == MediaType.MOV then
        print("PlayVideo mov : " .. fileName)
    elseif typ == MediaType.AVI then
        print("PlayVideo avi : " .. fileName)
    elseif typ == MediaType.M4V then
        print("PlayVideo m4v : " .. fileName)
    end
end
