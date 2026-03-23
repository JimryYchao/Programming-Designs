#ifndef PROXY_H
#define PROXY_H

#include "subject.h"

#define default_capacity 16

// ImageProxy 结构体
typedef struct ImageProxy {
    Image image; // 继承 Image
    Image** images;
    int count;
    int capacity;
} ImageProxy;

// 创建 ImageProxy 实例
ImageProxy* ImageProxy_init(ImageProxy* proxy);
void addImage(ImageProxy* proxy, Image* image);
bool removeImage(ImageProxy* proxy, Image* image);
void releaseImageProxy(ImageProxy* proxy);

#endif // PROXY_H
