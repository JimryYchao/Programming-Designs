#include "real_subject.h"
#include "proxy.h"

// 测试 Proxy 模式
int main() {
    // 创建实体对象
    RealImage* img1 = createRealImage("//path/image1");
    RealImage* img2 = createRealImage("//path/image2");
    RealImage* img3 = createRealImage("//path/image3");
    RealImage* img4 = createRealImage("//path/image4");
    RealImage* img5 = createRealImage("//path/image5");
    
    // 创建代理对象
    ImageProxy imageProxy; 
    ImageProxy* proxy = ImageProxy_init(&imageProxy);
    
    // 添加图像
    addImage(proxy, (Image*)img1);
    addImage(proxy, (Image*)img2);
    addImage(proxy, (Image*)img3);
    addImage(proxy, (Image*)img4);
    addImage(proxy, (Image*)img5);
    
    // 加载图像
    proxy->image.loadFromDisk((Image*)proxy);
    
    // 执行操作
    proxy->image.operation((Image*)proxy);
    
    // 释放资源
    releaseImageProxy(proxy);
    releaseRealImage(img1);
    releaseRealImage(img2);
    releaseRealImage(img3);
    releaseRealImage(img4);
    releaseRealImage(img5);
}

// gcc -o client client.c real_subject.c proxy.c