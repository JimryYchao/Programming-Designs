#ifndef CONCRETE_VISITOR_H
#define CONCRETE_VISITOR_H

#include "visitor.h"

// 具体访问者：ComputerPartDisplayVisitor
typedef struct ComputerPartDisplayVisitor {
    IComputerPartVisitor base;
} ComputerPartDisplayVisitor;

void ComputerPartDisplayVisitor_init(ComputerPartDisplayVisitor* self);

#endif // CONCRETE_VISITOR_H