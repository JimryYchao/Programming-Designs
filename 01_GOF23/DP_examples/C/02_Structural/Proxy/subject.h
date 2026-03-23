#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdio.h>

// Image 结构体，包含函数指针
typedef struct Image {
    void (*operation)(struct Image*);
    void (*loadFromDisk)(struct Image*);
} Image;

#endif // SUBJECT_H
