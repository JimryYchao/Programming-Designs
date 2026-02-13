#include "shape_cache.h"

int main() {
    // 获取形状缓存实例
    ShapeCache* cache = ShapeCache_instance();

    // 克隆不同形状
    IShape* circle = cache->GetShape(cache, ShapeCircle);
    if (circle) {
        circle->draw(circle);
        circle->fill(circle, Red);
        circle->destroy(circle);
    }

    IShape* square = cache->GetShape(cache, ShapeSquare);
    if (square) {
        square->draw(square);
        square->fill(square, Green);
        square->destroy(square);
    }

    IShape* rectangle = cache->GetShape(cache, ShapeRectangle); 
    if (rectangle) {
        rectangle->draw(rectangle);
        rectangle->fill(rectangle, Blue);
        rectangle->destroy(rectangle);
    }
        
    // 销毁缓存实例
    cache->Destroy(cache);
}

// gcc -o client client.c shape_cache.c product.c