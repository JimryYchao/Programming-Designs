#include "facade.h"
#include <stdlib.h>

// 测试 Facade 模式
int main() {

    int circle_args[] = {10};
    IShape* circle = MakeShape(CIRCLE, circle_args, 1);
    if (circle) {
        circle->draw(circle);
        circle->destroy(circle);
    }

    // 创建矩形
    int rectangle_args[] = {10, 20};
    IShape* rectangle = MakeShape(RECTANGLE, rectangle_args, 2);
    if (rectangle) {
        rectangle->draw(rectangle);
        rectangle->destroy(rectangle);
    }

    // 创建正方形
    int square_args[] = {10};
    IShape* square = MakeShape(SQUARE, square_args, 1);
    if (square) {
        square->draw(square);
        square->destroy(square);
    }
}
// gcc -o client client.c facade.c subsystem.c