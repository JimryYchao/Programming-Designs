require("Subject")

---@class RealImage : Image
---@field filename string
---@field imageData table
RealImage = Image:new()
function RealImage:new(filename)
    local o = Image.new(self)
    o.filename = filename
    o.imageData = {}
    return o
end
function RealImage:operation()
    print("Do a operation with image:[" .. self.filename .. "]")
end
function RealImage:loadFromDisk()
    print("load a Image from " .. self.filename)
    -- 实际情况下，这里会从文件读取字节数据
    -- self.imageData = readFile(self.filename)
end
