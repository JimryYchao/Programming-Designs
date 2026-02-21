#ifndef REAL_SUBJECT_HPP
#define REAL_SUBJECT_HPP

#include "Subject.hpp"
#include <string>
#include <vector>

// RealImage 是真实的图像类，实现了 Image 接口
class RealImage : public Image {
private:
    std::string filename;
    std::vector<unsigned char> imageData;

public:
    RealImage(const std::string& filename);
    ~RealImage() override = default;
    
    void operation() override;
    void loadFromDisk() override;
};

// 构造函数
RealImage::RealImage(const std::string& filename) : filename(filename) {
}

// 执行图像处理操作
void RealImage::operation() {
    std::cout << "Do a operation with image:[" << filename << "]" << std::endl;
}

// 从磁盘加载图像
void RealImage::loadFromDisk() {
    std::cout << "load a Image from " << filename << std::endl;
    // 实际情况下，这里会从文件读取字节数据
    // std::ifstream file(filename, std::ios::binary);
    // if (file) {
    //     file.seekg(0, std::ios::end);
    //     size_t size = file.tellg();
    //     file.seekg(0, std::ios::beg);
    //     imageData.resize(size);
    //     file.read(reinterpret_cast<char*>(imageData.data()), size);
    // }
}


#endif // REAL_SUBJECT_HPP
