#pragma once

#include <vector>
#include <memory>

// 叶子接口
class ILeaf
{
public:
    virtual ~ILeaf() = default;
    bool isLeaf;
    virtual void operation() = 0;
};

// 组件接口
class IComponent : virtual public ILeaf
{
public:
    virtual int add(std::shared_ptr<IComponent> component) = 0;
    virtual bool remove(std::shared_ptr<IComponent> component) = 0;
    virtual std::shared_ptr<IComponent> getChild(int index) const = 0;
    virtual ~IComponent() = default;
};

// 组合类
class Composite : virtual public IComponent
{
protected:
    std::vector<std::shared_ptr<IComponent>> _subComposites;

public:
    Composite(bool isLeaf)
    {
        this->isLeaf = isLeaf;
    }
    virtual ~Composite() = default;
    virtual void operation() override;
    int add(std::shared_ptr<IComponent> component) override;
    bool remove(std::shared_ptr<IComponent> component) override;
    std::shared_ptr<IComponent> getChild(int index) const override;
};

// 添加组件
int Composite::add(std::shared_ptr<IComponent> component)
{
    if (isLeaf || component == nullptr)
        return -1;
    // 检查是否已存在
    for (const auto &comp : _subComposites)
    {
        if (comp == component)
            return -1;
    }
    _subComposites.push_back(component);
    return _subComposites.size();
}

// 移除组件
bool Composite::remove(std::shared_ptr<IComponent> component)
{
    if (isLeaf)
        return false;
    for (auto it = _subComposites.begin(); it != _subComposites.end(); ++it)
        if (*it == component)
        {
            _subComposites.erase(it);
            return true;
        }
    return false;
}

// 获取子组件
std::shared_ptr<IComponent> Composite::getChild(int index) const
{
    if (index < 0 || index >= static_cast<int>(_subComposites.size()))
        return nullptr;
    return _subComposites[index];
}

void Composite::operation()
{
    if (!isLeaf)
        for (const auto &comp : _subComposites)
            comp->operation();
}
