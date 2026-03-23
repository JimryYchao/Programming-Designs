#include "ConcreteImplementor.hpp"
#include "Abstraction.hpp"

int main()
{
    Shape* circle = new Shape(std::make_shared<Circle>());
    circle->Draw(Color::red);

    Shape* square = static_cast<Shape*>(new ShapeAdvance(std::make_shared<Square>(), []() {
        std::cout << "Drew Completed" << std::endl;
    }));
    square->Draw(Color::green);
}
