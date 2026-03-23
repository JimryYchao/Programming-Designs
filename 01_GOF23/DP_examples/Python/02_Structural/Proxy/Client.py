from RealSubject import RealImage
from Proxy import ImageProxy

# 测试 Proxy 模式
def test_proxy_pattern():
    # 创建实体对象
    img1 = RealImage("//path/image1")
    img2 = RealImage("//path/image2")
    img3 = RealImage("//path/image3")
    img4 = RealImage("//path/image4")
    img5 = RealImage("//path/image5")
    
    # 创建代理对象
    image_proxy = ImageProxy()
    image_proxy.add_images(img1, img2, img3, img4, img5)
    image_proxy.load_from_disk()
    image_proxy.operation()

if __name__ == "__main__":
    test_proxy_pattern()
