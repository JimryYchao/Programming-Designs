#pragma once

#include "component.h"

typedef IShape Circle;
typedef IShape Rectangle;

Circle* circle_create(IShape* self);
Rectangle* rectangle_create(IShape* self);

