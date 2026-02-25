#ifndef CONCRETE_AGGREGATE_HPP
#define CONCRETE_AGGREGATE_HPP

#include "Iterator.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>

// 具体聚合类
template <typename T>
class ConcreteAggregate : public IAggregate<T> {
private:
    std::vector<T> array;
    static const int defaultCapacity = 4;

    // 具体迭代器实现
    class AggregateIterator : public Iterator<T> {
    private:
        ConcreteAggregate<T>* aggregate;
        int index;

    public:
        AggregateIterator(ConcreteAggregate<T>* agg) : aggregate(agg), index(-1) {}

        void First() override {
            if (!aggregate->array.empty()) {
                index = 0;
            }
        }

        void Next() override {
            if (index < static_cast<int>(aggregate->array.size())) {
                index++;
            }
        }

        bool IsDone() const override {
            return index >= static_cast<int>(aggregate->array.size());
        }

        T CurrentItem() const override {
            if (index >= 0 && index < static_cast<int>(aggregate->array.size())) {
                return aggregate->array[index];
            }
            throw std::out_of_range("Iterator out of range");
        }
    };

public:
    ConcreteAggregate() : array() {
        array.reserve(defaultCapacity);
    }

    explicit ConcreteAggregate(int capacity) : array() {
        if (capacity < defaultCapacity) {
            capacity = defaultCapacity;
        }
        array.reserve(capacity);
    }

    int Count() const override {
        return static_cast<int>(array.size());
    }

    void Add(const T& item) override {
        array.push_back(item);
    }

    bool Remove(const T& item) override {
        auto it = std::find(array.begin(), array.end(), item);
        if (it != array.end()) {
            array.erase(it);
            return true;
        }
        return false;
    }

    bool Contains(const T& item) const override {
        return std::find(array.begin(), array.end(), item) != array.end();
    }

    void Clear() override {
        array.clear();
    }

    Iterator<T>* GetIterator() override {
        return new AggregateIterator(this);
    }
};

#endif // CONCRETE_AGGREGATE_HPP
