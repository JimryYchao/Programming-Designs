### State

状态模式（State）允许对象在内部状态改变时改变它的行为，对象看起来似乎修改了它的类。

  ![状态模式](.img/状态模式设计.png)

- Context：定义客户端感兴趣的接口，维护一个 ConcreteState 子类的实例，这个实例定义当前状态。
- State：定义一个接口，用以封装与 Context 的一个特定状态相关的行为。
- ConcreteState：实现与 Context 的一个特定状态相关的行为。

> **设计要点**

1. 状态模式的核心是将对象的状态封装成独立的类，并在对象状态变化时切换到不同的状态类。
2. 状态模式可以与策略模式结合使用，以实现更复杂的行为切换。
3. 状态模式可以与单例模式结合使用，以减少状态对象的创建。

> **案例实现**

创建一个电梯系统，电梯可以处于不同的状态（如停止、运行、开门、关门等），当电梯的状态变化时，它的行为也会相应地改变。

![案例示意](.img/状态模式案例.png)

<p align="left">
  <a href="../DP_examples/CSharp/03_Behavioral/State/Client.cs"><img src="https://img.shields.io/badge/C%23-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C/03_Behavioral/State/client.c"><img src="https://img.shields.io/badge/C-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C++/03_Behavioral/State/Client.cpp"><img src="https://img.shields.io/badge/C++-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Lua/03_Behavioral/State/Client.lua"><img src="https://img.shields.io/badge/Lua-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Go/03_Behavioral/State/Client_test.go"><img src="https://img.shields.io/badge/Go-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Python/03_Behavioral/State/Client.py"><img src="https://img.shields.io/badge/Python-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Rust/03_Behavioral/State/main.rs"><img src="https://img.shields.io/badge/Rust-00599C?for-the-badge&logoColor=white"></a>
</p>

---
