from Subject import Image

# ImageProxy 是图像代理类，实现了 Image 抽象基类
class ImageProxy(Image):
    def __init__(self):
        self.images = []
    
    def operation(self):
        for image in self.images:
            image.operation()
    
    def load_from_disk(self):
        for image in self.images:
            image.load_from_disk()
    
    def add_image(self, image):
        self.images.append(image)
    
    def add_images(self, *images):
        self.images.extend(images)
    
    def remove(self, image):
        if image in self.images:
            self.images.remove(image)
            return True
        return False
