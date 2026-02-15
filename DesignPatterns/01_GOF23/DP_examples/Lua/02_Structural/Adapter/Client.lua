-- 加载适配器模块
require("Adapter")

-- 创建适配器实例
local player = PlayerAdapter:new()

-- 播放背景音乐
player:play("BGMusic.wave", MediaType.Wave)

-- 播放 CG 视频
player:play("CG.mp4", MediaType.MP4)
