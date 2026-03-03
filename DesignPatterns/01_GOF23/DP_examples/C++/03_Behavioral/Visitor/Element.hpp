#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// 前向声明
class IComputerPartVisitor;

// 元素接口
class IComputerPart {
public:
    virtual ~IComputerPart() = default;
    virtual void accept(IComputerPartVisitor* visitor) = 0;
};

#endif // ELEMENT_HPP