#include "abstraction.h"

// 形状绘制方法
static void Shape_draw(Shape* self, Color color) {
    self->draw->draw(self->draw);
    self->draw->fill(self->draw, color);
}

// 初始化形状
void Shape_init(Shape* shape, DrawAPI* draw) {
    shape->draw = draw;
    shape->draw_shape = Shape_draw;
}

// 高级形状绘制方法
static void ShapeAdvance_draw(ShapeAdvance* self, Color color) {
    self->base.draw_shape(&self->base, color);
    if (self->on_draw_completed) 
        self->on_draw_completed();
}
void ShapeAdvance_init(ShapeAdvance* shapeAdvance, DrawAPI* draw, DrawCompletedCallback on_draw_completed) {
    Shape_init(&shapeAdvance->base, draw);
    shapeAdvance->on_draw_completed = on_draw_completed;
    shapeAdvance->draw_shape = ShapeAdvance_draw;
}
