#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <iostream>

// Image 接口定义了图像处理的方法
class Image {
public:
    virtual ~Image() = default;
    virtual void operation() = 0;
    virtual void loadFromDisk() = 0;
};

#endif // SUBJECT_HPP
