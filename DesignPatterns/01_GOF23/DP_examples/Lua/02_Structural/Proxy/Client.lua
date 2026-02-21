-- 加载 RealImage 和 ImageProxy 模块
require("Proxy")

-- 测试 Proxy 模式
function testProxyPattern()
    -- 创建实体对象
    local img1 = RealImage:new("//path/image1")
    local img2 = RealImage:new("//path/image2")
    local img3 = RealImage:new("//path/image3")
    local img4 = RealImage:new("//path/image4")
    local img5 = RealImage:new("//path/image5")
    
    -- 创建代理对象
    local imageProxy = ImageProxy:new()
    imageProxy:addImages(img1, img2, img3, img4, img5)
    imageProxy:loadFromDisk()
    imageProxy:operation()
end

-- 执行测试
testProxyPattern()

--- lua Client.lua