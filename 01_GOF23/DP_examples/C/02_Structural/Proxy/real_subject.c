#include "real_subject.h"
#include <stdlib.h>
#include <string.h>

// RealImage 的 operation 方法
static void realImageOperation(Image* image) {
    RealImage* realImage = (RealImage*)image;
    printf("Do a operation with image:[%s]\n", realImage->filename);
}

// RealImage 的 loadFromDisk 方法
static void realImageLoadFromDisk(Image* image) {
    RealImage* realImage = (RealImage*)image;
    printf("load a Image from %s\n", realImage->filename);
    // 模拟从文件读取字节数据
    // realImage->image_data = readFile(realImage->filename, &realImage->image_size);
}

// 创建 RealImage 实例
RealImage* createRealImage(const char* filename) {
    RealImage* realImage = (RealImage*)malloc(sizeof(RealImage));
    if (!realImage) 
        return NULL;
    // 初始化函数指针
    realImage->image.operation = realImageOperation;
    realImage->image.loadFromDisk = realImageLoadFromDisk;
    
    // 复制文件名
    realImage->filename = filename;
    realImage->image_data = NULL;
    realImage->image_size = 0;
    
    return realImage;
}

// 释放 RealImage 实例
void releaseRealImage(RealImage* realImage) {
    if (realImage == NULL) {
        return;
    }
    if (realImage->image_data != NULL) {
        free(realImage->image_data);
    }
    
    free(realImage);
}
