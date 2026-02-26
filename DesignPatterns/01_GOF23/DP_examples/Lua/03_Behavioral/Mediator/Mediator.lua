-- 中介者接口
local IMediator = {}
IMediator.__index = IMediator

function IMediator:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function IMediator:ShowMessage(oriUser, desUser, message)
    error("Subclass must implement ShowMessage method")
end

-- 用户类
local User = {}
User.__index = User

function User:new(name)
    local o = {name = name}
    setmetatable(o, self)
    return o
end

function User:GetName()
    return self.name
end

function User:SendMessage(room, desUser, message)
    room:ShowMessage(self, desUser, message)
end

-- 私聊房间
local PrivateChatRoom = {}
PrivateChatRoom.__index = PrivateChatRoom
setmetatable(PrivateChatRoom, IMediator)

-- 静态实例
local privateChatRoomInstance = nil

function PrivateChatRoom:new()
    local o = IMediator:new()
    setmetatable(o, self)
    return o
end

function PrivateChatRoom:ShowMessage(oriUser, desUser, message)
    print(string.format("[PrivateChatRoom][%s] sent to [%s]: %s", oriUser:GetName(), desUser:GetName(), message))
end

-- 获取私聊房间实例
function GetPrivateChatRoomInstance()
    if not privateChatRoomInstance then
        privateChatRoomInstance = PrivateChatRoom:new()
    end
    return privateChatRoomInstance
end

-- 公共聊天室
local PublicChatRoom = {}
PublicChatRoom.__index = PublicChatRoom
setmetatable(PublicChatRoom, IMediator)

-- 静态实例
local publicChatRoomInstance = nil

function PublicChatRoom:new()
    local o = IMediator:new()
    setmetatable(o, self)
    return o
end

function PublicChatRoom:ShowMessage(user, desUser, message)
    print(string.format("[PublicChatRoom][%s]: %s", user:GetName(), message))
end

function PublicChatRoom:ShowMessagePublic(user, message)
    self:ShowMessage(user, nil, message)
end

-- 获取公共聊天室实例
function GetPublicChatRoomInstance()
    if not publicChatRoomInstance then
        publicChatRoomInstance = PublicChatRoom:new()
    end
    return publicChatRoomInstance
end

return { User = User, GetPrivateChatRoomInstance = GetPrivateChatRoomInstance, GetPublicChatRoomInstance = GetPublicChatRoomInstance }
