#include "RealSubject.hpp"
#include "Proxy.hpp"

// 测试 Proxy 模式
int main() {
    // 创建实体对象
    std::shared_ptr<Image> img1 = std::make_shared<RealImage>("//path/image1");
    std::shared_ptr<Image> img2 = std::make_shared<RealImage>("//path/image2");
    std::shared_ptr<Image> img3 = std::make_shared<RealImage>("//path/image3");
    std::shared_ptr<Image> img4 = std::make_shared<RealImage>("//path/image4");
    std::shared_ptr<Image> img5 = std::make_shared<RealImage>("//path/image5");
    
    // 创建代理对象
    ImageProxy imageProxy;
    imageProxy.addImages({img1, img2, img3, img4, img5});
    imageProxy.loadFromDisk();
    imageProxy.operation();
}
