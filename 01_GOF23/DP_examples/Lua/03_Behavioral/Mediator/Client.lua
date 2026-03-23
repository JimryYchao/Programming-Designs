local MediatorModule = require("Mediator")

local User = MediatorModule.User
local PrivateRoomInstance = MediatorModule.GetPrivateChatRoomInstance
local PublicRoomInstance = MediatorModule.GetPublicChatRoomInstance

-- 创建用户
local Tom = User:new("Tom")
local Lily = User:new("Lily")

-- 获取聊天室实例
local privateRoom = PrivateRoomInstance()
local publicRoom = PublicRoomInstance()

-- 发送消息
Tom:SendMessage(publicRoom, nil, "Hi! I'm Tom")
Lily:SendMessage(publicRoom, nil, "Hi! I'm Lily")
Tom:SendMessage(privateRoom, Lily, "How are U! Lily")
Lily:SendMessage(privateRoom, Tom, "Fine!")
