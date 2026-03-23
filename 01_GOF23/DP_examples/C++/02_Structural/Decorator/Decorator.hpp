#pragma once
#include "Component.hpp"
#include <iostream>
#include <memory>

class Decorator : public IShape {
protected:
    std::unique_ptr<IShape> shapeComponent;
public:
    Decorator(std::unique_ptr<IShape> shape) : shapeComponent(std::move(shape)) {}
    void Draw() override {
        if (shapeComponent) {
            shapeComponent->Draw();
        }
    }
    void Fill(Color color) override {
        if (shapeComponent) {
            shapeComponent->Fill(color);
        }
    }
};

class ShapeDecorator : public Decorator {
protected:
    virtual void BeforeDraw() {
        std::cout << "Before Draw() >> Do..." << std::endl;
    }
    virtual void AfterDraw() {
        std::cout << "When Draw Complete >> Do..." << std::endl;
    }
    virtual void BeforeFill() {
        std::cout << "Before Fill() >> Do..." << std::endl;
    }
    virtual void AfterFill() {
        std::cout << "When Fill Complete >> Do..." << std::endl;
    }
public:
    ShapeDecorator(std::unique_ptr<IShape> shape) : Decorator(std::move(shape)) {}
    void Draw() override {
        BeforeDraw();
        Decorator::Draw();
        AfterDraw();
    }
    void Fill(Color color) override {
        BeforeFill();
        Decorator::Fill(color);
        AfterFill();
    }
};
