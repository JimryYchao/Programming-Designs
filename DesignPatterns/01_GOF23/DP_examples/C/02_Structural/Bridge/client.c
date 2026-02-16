#include "abstraction.h"

// 回调函数
static void on_draw_completed() {
    printf("Drew Completely\n");
}

// 测试 Bridge 模式
int main() {
    Circle circle;
    Shape redCircle;
    Shape_init(&redCircle,  Circle_init(&circle));
    redCircle.draw_shape(&redCircle, GREEN);
    
    // 创建正方形
    Square square;
    ShapeAdvance squareAdvance;
    ShapeAdvance_init(&squareAdvance, Square_init(&square), on_draw_completed);
    squareAdvance.draw_shape(&squareAdvance, BLUE);
}
// gcc -o client client.c implementor.c abstraction.c
