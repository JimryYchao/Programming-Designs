from abc import ABC, abstractmethod

# Image 抽象基类定义了图像处理的方法
class Image(ABC):
    @abstractmethod
    def operation(self):
        pass
    
    @abstractmethod
    def load_from_disk(self):
        pass
