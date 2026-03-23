### Iterator

迭代器模式（Iterator）提供一种方法顺序访问一个聚合对象中各个元素，而又不暴露该对象的内部表示。

  ![迭代器模式](.img/迭代器模式设计.png)

- Iterator：定义访问和遍历元素的接口。
- ConcreteIterator：实现迭代器接口，对该聚合遍历时跟踪当前位置。
- Aggregate：定义创建相应迭代器对象的接口。
- ConcreteAggregate：实现创建相应迭代器的接口，返回一个合适的 ConcreteIterator 实例。

> **设计要点**

1. 迭代器模式的核心是将聚合对象的遍历操作与聚合对象本身分离，使得遍历操作可以独立于聚合对象的结构。
2. 迭代器模式提供了一种统一的方式来遍历不同类型的聚合对象，客户端可以使用相同的代码来遍历不同的聚合。
3. 迭代器模式可以与组合模式结合使用，以遍历复杂的树形结构。

> **案例实现**

创建一个集合类，它可以存储多个元素，并提供一个迭代器来遍历这些元素。

![案例示意](.img/迭代器模式案例.png)

<p align="left">
  <a href="../DP_examples/CSharp/03_Behavioral/Iterator/Client.cs"><img src="https://img.shields.io/badge/C%23-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C/03_Behavioral/Iterator/client.c"><img src="https://img.shields.io/badge/C-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C++/03_Behavioral/Iterator/Client.cpp"><img src="https://img.shields.io/badge/C++-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Lua/03_Behavioral/Iterator/Client.lua"><img src="https://img.shields.io/badge/Lua-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Go/03_Behavioral/Iterator/Client_test.go"><img src="https://img.shields.io/badge/Go-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Python/03_Behavioral/Iterator/Client.py"><img src="https://img.shields.io/badge/Python-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Rust/03_Behavioral/Iterator/main.rs"><img src="https://img.shields.io/badge/Rust-00599C?for-the-badge&logoColor=white"></a>
</p>

---
