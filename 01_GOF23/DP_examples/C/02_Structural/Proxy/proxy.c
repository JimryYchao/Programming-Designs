#include "proxy.h"
#include <stdlib.h>

// ImageProxy 的 operation 方法
static void imageProxyOperation(Image* image) {
    ImageProxy* proxy = (ImageProxy*)image;
    for (int i = 0; i < proxy->count; i++) 
        proxy->images[i]->operation(proxy->images[i]);
}

// ImageProxy 的 loadFromDisk 方法
static void imageProxyLoadFromDisk(Image* image) {
    ImageProxy* proxy = (ImageProxy*)image;
    for (int i = 0; i < proxy->count; i++) 
        proxy->images[i]->loadFromDisk(proxy->images[i]);
}

// 创建 ImageProxy 实例
ImageProxy* ImageProxy_init(ImageProxy* proxy) {
    if (proxy == NULL) {
        return NULL;
    }
    // 初始化函数指针
    proxy->image.operation = imageProxyOperation;
    proxy->image.loadFromDisk = imageProxyLoadFromDisk;
    proxy->images = (Image**)calloc(default_capacity, sizeof(Image*));
    proxy->capacity = default_capacity;
    proxy->count = 0;
    return proxy;
}

// 释放 ImageProxy 实例
void releaseImageProxy(ImageProxy* proxy) {
    if (proxy == NULL) 
        return;
    free(proxy->images);  // 仅释放图像数组
}

// 添加单个图像
void addImage(ImageProxy* proxy, Image* image) {
    if (proxy == NULL || image == NULL ) {
        return;
    }
    // 检查是否需要扩展容量
    if (proxy->count >= proxy->capacity) {
        proxy->capacity *= 2;
        proxy->images = (Image**)realloc(proxy->images, proxy->capacity * sizeof(Image*));
    }
    proxy->images[proxy->count] = image;
    proxy->count++;
}

// 移除图像
bool removeImage(ImageProxy* proxy, Image* image) {
    if (proxy == NULL || image == NULL) {
        return false;
    }
    for (int i = 0; i < proxy->count; i++) {
        if (proxy->images[i] == image) {
            for (int j = i; j < proxy->count - 1; j++) 
                proxy->images[j] = proxy->images[j + 1];
            proxy->images[proxy->count - 1] = NULL;
            proxy->count--;
            return true;
        }
    }
    return false;
}
