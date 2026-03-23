#include "ConcreteComponent.hpp"
#include "Decorator.hpp"

int main() {
    // 创建红色圆形
    auto redCircle = std::make_unique<ShapeDecorator>(std::unique_ptr<IShape>(new Circle()));
    redCircle->Draw();
    redCircle->Fill(Color::red);
    
    // 创建绿色矩形
    auto greenRectangle = std::make_unique<ShapeDecorator>(std::unique_ptr<IShape>(new Rectangle()));
    greenRectangle->Draw();
    greenRectangle->Fill(Color::green);
}