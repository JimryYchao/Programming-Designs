#ifndef ITERATOR_HPP
#define ITERATOR_HPP

// 迭代器接口
template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual T CurrentItem() const = 0;
};

// 可迭代接口
template <typename T>
class Iterable {
public:
    virtual ~Iterable() = default;
    virtual Iterator<T>* GetIterator() = 0;
};

// 聚合接口
template <typename T>
class IAggregate : public Iterable<T> {
public:
    virtual ~IAggregate() = default;
    virtual int Count() const = 0;
    virtual void Add(const T& item) = 0;
    virtual bool Remove(const T& item) = 0;
    virtual bool Contains(const T& item) const = 0;
    virtual void Clear() = 0;
};

#endif // ITERATOR_HPP
