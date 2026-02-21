from Subject import Image

# RealImage 是真实的图像类，实现了 Image 抽象基类
class RealImage(Image):
    def __init__(self, filename):
        self.filename = filename
        self.image = None
    
    def operation(self):
        print(f"Do a operation with image:[{self.filename}]")
    
    def load_from_disk(self):
        print(f"load a Image from {self.filename}")
        # 实际情况下，这里会从文件读取字节数据
        # self.image = open(self.filename, 'rb').read()
