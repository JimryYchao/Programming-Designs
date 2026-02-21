#ifndef REAL_SUBJECT_H
#define REAL_SUBJECT_H

#include "subject.h"
#include <stddef.h>

// RealImage 结构体
typedef struct RealImage {
    Image image; // 继承 Image
    const char* filename;
    unsigned char* image_data;
    size_t image_size;
} RealImage;

// 创建 RealImage 实例
RealImage* createRealImage(const char* filename);

// 释放 RealImage 实例
void releaseRealImage(RealImage* realImage);

#endif // REAL_SUBJECT_H
