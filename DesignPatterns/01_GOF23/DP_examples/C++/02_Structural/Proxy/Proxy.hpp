#ifndef PROXY_HPP
#define PROXY_HPP

#include "Subject.hpp"
#include <vector>
#include <memory>
#include <initializer_list>

// ImageProxy 是图像代理类，实现了 Image 接口
class ImageProxy : public Image {
private:
    std::vector<std::shared_ptr<Image>> images;

public:
    ImageProxy() = default;
    ~ImageProxy() override = default;
    
    void operation() override;
    void loadFromDisk() override;
    
    void addImage(std::shared_ptr<Image> image);
    void addImages(std::initializer_list<std::shared_ptr<Image>> imgs);
    bool remove(std::shared_ptr<Image> image);
};


// 执行所有图像的操作
void ImageProxy::operation() {
    for (auto image : images) {
        image->operation();
    }
}

// 加载所有图像
void ImageProxy::loadFromDisk() {
    for (auto image : images) {
        image->loadFromDisk();
    }
}

// 添加单个图像
void ImageProxy::addImage(std::shared_ptr<Image> image) {
    images.push_back(image);
}

// 添加多个图像
void ImageProxy::addImages(std::initializer_list<std::shared_ptr<Image>> imgs) {
    images.insert(images.end(), imgs.begin(), imgs.end());
}

// 移除图像
bool ImageProxy::remove(std::shared_ptr<Image> image) {
    auto it = std::find(images.begin(), images.end(), image);
    if (it != images.end()) {
        images.erase(it);
        return true;
    }
    return false;
}


#endif // PROXY_HPP
