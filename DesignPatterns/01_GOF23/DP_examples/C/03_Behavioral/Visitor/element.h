#ifndef ELEMENT_H
#define ELEMENT_H

// 前向声明
typedef struct IComputerPartVisitor IComputerPartVisitor;

// 元素接口
typedef struct IComputerPart {
    void (*accept)(struct IComputerPart* self, IComputerPartVisitor* visitor);
} IComputerPart;

#endif // ELEMENT_H