-- 状态模式实现

-- TCPConnection 上下文类
local TCPConnection = {}
TCPConnection.__index = TCPConnection

function TCPConnection:new()
    local instance = {
        tcpState = GetTCPUnconnectedInstance(),
        connector = nil,
        ipAddress = "127.0.0.1",
        port = 7777
    }
    setmetatable(instance, self)
    return instance
end

function TCPConnection:connect()
    self.tcpState:connect(self)
end

function TCPConnection:receive()
    return self.tcpState:receive(self)
end

function TCPConnection:close()
    self.tcpState:close(self)
end

function TCPConnection:sendMessage(buffer)
    self.tcpState:sendMessage(self, buffer)
end

function TCPConnection:isConnected()
    return self.connector ~= nil
end

function TCPConnection:changeState(state)
    print("Switch state to >> " .. tostring(state))
    self.tcpState = state
end

-- TCPState 状态接口
local TCPState = {}
TCPState.__index = TCPState

function TCPState:new()
    local instance = {}
    setmetatable(instance, self)
    return instance
end

function TCPState:connect(connection)
    -- 空实现
end

function TCPState:receive(connection)
    return nil
end

function TCPState:close(connection)
    -- 空实现
end

function TCPState:sendMessage(connection, buffer)
    -- 空实现
end

function TCPState:changeState(connection, state)
    connection:changeState(state)
end

-- TCPEstablished 具体状态
local TCPEstablished = TCPState:new()
TCPEstablished.__index = TCPEstablished

function TCPEstablished:new()
    local instance = TCPState:new()
    setmetatable(instance, self)
    return instance
end

function TCPEstablished:sendMessage(connection, buffer)
    if connection:isConnected() then
        connection.connector:send(buffer)
    else
        self:changeState(connection, TCPUnconnected:new())
        return
    end
    self:changeState(connection, TCPListen:new())
end

function TCPEstablished:close(connection)
    if connection.connector then
        connection.connector:close()
        connection.connector = nil
    end
    self:changeState(connection, TCPUnconnected:new())
end

-- TCPListen 具体状态
local TCPListen = TCPState:new()
TCPListen.__index = TCPListen

function TCPListen:new()
    local instance = TCPState:new()
    setmetatable(instance, self)
    return instance
end

function TCPListen:receive(connection)
    if not connection:isConnected() then
        self:changeState(connection, TCPUnconnected:new())
        return nil
    end

    local buffer, err = connection.connector:receive(1024)
    if not buffer then
        if connection.connector then
            connection.connector:close()
            connection.connector = nil
        end
        self:changeState(connection, TCPUnconnected:new())
        return nil
    end

    self:changeState(connection, TCPEstablished:new())
    return buffer
end

-- TCPUnconnected 具体状态
local TCPUnconnected = TCPState:new()
TCPUnconnected.__index = TCPUnconnected

function TCPUnconnected:new()
    local instance = TCPState:new()
    setmetatable(instance, self)
    return instance
end

function TCPUnconnected:connect(connection)
    local socket = require("socket")
    local addr = connection.ipAddress .. ":" .. connection.port
    
    while true do
        local connector, err = socket.connect(connection.ipAddress, connection.port)
        if connector then
            connection.connector = connector
            print("Connect to >>> " .. addr)
            self:changeState(connection, TCPEstablished:new())
            break
        else
            print("Cannot connect to >>> " .. addr .. ": " .. err)
            socket.sleep(1)
        end
    end
end

-- 单例实例
local establishedInstance = nil
local listenInstance = nil
local unconnectedInstance = nil

function GetTCPEstablishedInstance()
    if not establishedInstance then
        establishedInstance = TCPEstablished:new()
    end
    return establishedInstance
end

function GetTCPListenInstance()
    if not listenInstance then
        listenInstance = TCPListen:new()
    end
    return listenInstance
end

function GetTCPUnconnectedInstance()
    if not unconnectedInstance then
        unconnectedInstance = TCPUnconnected:new()
    end
    return unconnectedInstance
end

-- 导出模块
return {
    TCPConnection = TCPConnection,
    GetTCPEstablishedInstance = GetTCPEstablishedInstance,
    GetTCPListenInstance = GetTCPListenInstance,
    GetTCPUnconnectedInstance = GetTCPUnconnectedInstance
}
