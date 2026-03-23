-- 客户端实现
local socket = require("socket")
local stateModule = require("State")

-- 创建服务器端
local server = socket.tcp()
server:setoption("reuseaddr", true)
server:bind("127.0.0.1", 7777)
server:listen(10)
print("Server is Builded")

-- 创建客户端TCPConnection
local client = stateModule.TCPConnection:new()

-- 启动服务器接受连接的协程
local serverThread = coroutine.create(function()
    while true do
        local clientSocket, err = server:accept()
        if clientSocket then
            print("Server accepted connection")
            
            -- 处理服务器端接收和发送
            local receiveBuffer, err = clientSocket:receive(1024)
            if receiveBuffer then
                print("Server received: " .. receiveBuffer)
                
                -- 发送响应
                local response = "Successful"
                clientSocket:send(response)
                print("Server sent response: " .. response)
                clientSocket:close()
            end
        end
    end
end)

-- 主循环
while true do
    -- 1. 建立连接
    if not client:isConnected() then
        client:connect()
        io.write("Input Buffer: ")
        local message = io.read()
        if not message or message == "" then
            goto continue
        end

        -- 2. 客户端发送消息
        client:sendMessage(message)

        -- 3. 执行服务器协程
        coroutine.resume(serverThread)

        -- 4. 客户端接收状态
        local buffer = client:receive()

        -- 5. 客户端打印状态
        if buffer and buffer ~= "" then
            print("Client received: " .. buffer)
            client:close()
            print("Test Finished, and input anyKey to exit")
            io.read()
            break
        end
    end
    ::continue::
end

-- 清理
server:close()
--- lua Client.lua
