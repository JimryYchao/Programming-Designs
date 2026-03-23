-- 加载 Image 接口
require("RealSubject")

-- ImageProxy 是图像代理类，实现了 Image 接口
---@class ImageProxy : Image
---@field images table
ImageProxy = Image:new()
function ImageProxy:new()
    local o = Image.new(self)
    o.images = {}
    return o
end
function ImageProxy:operation()
    for _, image in ipairs(self.images) do
        image:operation()
    end
end

-- 加载所有图像
function ImageProxy:loadFromDisk()
    for _, image in ipairs(self.images) do
        image:loadFromDisk()
    end
end

-- 添加单个图像
function ImageProxy:addImage(image)
    table.insert(self.images, image)
end

-- 添加多个图像
function ImageProxy:addImages(...)  
    for _, image in ipairs({...}) do
        table.insert(self.images, image)
    end
end

-- 移除图像
function ImageProxy:remove(image)
    for i, img in ipairs(self.images) do
        if img == image then
            table.remove(self.images, i)
            return true
        end
    end
    return false
end
