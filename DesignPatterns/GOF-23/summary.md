### GOF-23 设计模式


| Creational Patterns                                                                                                                   | Variable Part        |
| :------------------------------------------------------------------------------------------------------------------------------------ | :------------------- |
| [抽象工厂](./Contents/CreationalPatterns/_01_AbstractFactory_抽象工厂模式.md) (Abstract Factory) ：提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。                                | 产品对象家族         |
| [建造者](./Contents/CreationalPatterns/_02_Builder_建造者模式.md) (Builder) ：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。                                     | 如何创建一个组合对象 |
| [工厂方法](./Contents/CreationalPatterns/_03_Factory_工厂模式.md) (Factory Method) ：定义一个用于创建对象的接口，让子类决定将哪一个类实例化。Factory Method 使一个类的实例化延迟到其子类。 | 被实例化的子类       |
| [原型](./Contents/CreationalPatterns/_04_Prototype_原型模式.md) (Prototype) ：用原型实例指定创建对象的种类，并且通过拷贝这个原型来创建新的对象。                                             | 被实例化的类         |
| [单例](./Contents/CreationalPatterns/_05_Singleton_单例模式.md) (Singleton) ：保证一个类仅有一个实例，并提供一个访问它的全局访问点。                                                         | 一个类的唯一实例     |



| Structural Patterns                                                                                                                       | Variable Part                  |
| :---------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------- |
| [适配器](./Contents/StructuralPatterns/_01_Adapter_适配器模式.md) (Adapter) ：将一个类的接口转换成客户希望的另外一个接口，Adapter 模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。 | 对象的接口                     |
| [桥接](./Contents/StructuralPatterns/_02_Bridge_桥接模式.md) (Bridge) ：将抽象部分与它的实现部分分离，使它们都可以独立地变化。                                                                | 对象的实现                     |
| [组合](./Contents/StructuralPatterns/_03_Composite_组合模式.md) (Composite) ：将对象组合成树形结构以表示 “部分整体” 的层次结构。Composite 使得客户对单个对象和复合对象的使用具有一致性。         | 一个对象的结构和组成           |
| [装饰](./Contents/StructuralPatterns/_04_Decorator_装饰器模式.md.md) (Decorator) ：动态地给一个对象添加一些额外的职责。就扩展功能而言，Decorator 模式比生成子类方式更为灵活。                         | 对象的职责，不生成子类         |
| [外观](./Contents/StructuralPatterns/_05_Facade_外观模式.md) (Facade) ：为子系统中的一组接口提供一个一致的界面，Facade 模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。           | 一个子系统的接口               |
| [享元](./Contents/StructuralPatterns/_06_Flyweight_享元模式.md) (Flyweight) ：运用共享技术有效地支持大量细粒度的对象。                                                                           | 对象的存储开销                 |
| [代理](./Contents/StructuralPatterns/_07_Proxy_代理模式.md) (Proxy) ：为其他对象提供一个代理以控制对这个对象的访问。                                                                         | 如何访问一个对象；该对象的位置 |

| Behavioral Patterns                                                                                                                                                                 | Variable Part                                                  |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------- |
| [责任链](./Contents/BehavioralPatterns/_01_ChainOfResponsibility_责任链模式.md) (Chain of Responsibility) ：为解除请求的发送者和接收者之间的耦合，而使多个对象都有机会处理这个请求。将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它。 | 满足一个请求的对象                                             |
| [命令](./Contents/BehavioralPatterns/_02_Command_命令模式.md) (Command) ：将一个请求封装为一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可取消的操作。                                             | 何时、怎样满足一个需求                                         |
| [解释器](./Contents/BehavioralPatterns/_03_Interpreter_解释器模式.md) (Interpreter) ：给定一个语言，定义它的文法的一种表示，并定义一个解释器，该解释器使用该表示来解释语言中的句子。                                                           | 一个语言的文法及解释                                           |
| [迭代器](./Contents/BehavioralPatterns/_04_Iterator_迭代器模式.md) (Iterator) ：提供一种方法顺序访问一个聚合对象中各个元素，而又不需暴露该对象的内部表示。                                                                                  | 如何遍历、访问一个聚合的各元素                                 |
| [中介者](./Contents/BehavioralPatterns/_05_Mediator_中介者模式.md) (Mediator) ：用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。                              | 对象间怎样交互、和谁交互                                       |
| [备忘录](./Contents/BehavioralPatterns/_06_Memento_备忘录模式.md) (Memento) ：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到保存的状态。                                           | 一个对象中哪些私有信息存放在该对象之外，以及在什么时候进行存储 |
| [观察者](./Contents/BehavioralPatterns/_07_Observer_观察者模式.md) (Observer) ：定义对象间的一种一对多的依赖关系，以便当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并自动刷新。                                                  | 多个对象依赖于另外一个对象，而这些对象又如何保持一致           |
| [状态](./Contents/BehavioralPatterns/_08_State_状态模式.md) (State) ：允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它所属的类。                                                                                     | 对象的状态                                                     |
| [策略](./Contents/BehavioralPatterns/_09_Strategy_策略模式.md) (Strategy) ：定义一系列的算法把它们一个个封装起来，并且使它们可相互替换。本模式使得算法的变化可独立于使用它的客户。                                                        | 算法                                                           |
| [模板方法](./Contents/BehavioralPatterns/_10_TemplateMethod_模板方法模式.md) (Template Method) ：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。Template Method 使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。             | 算法中的某些步骤                                               |
| [访问者](./Contents/BehavioralPatterns/_11_Visitor_访问者模式.md) (Visitor) ：表示一个作用于某对象结构中的各元素的操作。它使你可以在不改变各元素的类的前提下定义作用于这些元素的新操作。                                                   | 某些可作用于一个 / 组对象上的操作，但不修改这些对象的类        |

>---
### Annex

- [设计模式常见术语](Contents/annex/_Annex_01_常见术语.md)
- [设计模式一般遵循的设计原则](Contents/annex/_Annex_02_设计模式一般遵循的设计原则.md)
- [通用职责分配软件模式](Contents/annex/_Annex_03_通用职责分配软件模式.md)
- [设计模式之间的关系](Contents/annex/_Annex_04_设计模式之间的关系.md)
- [设计模式怎样设计问题](Contents/annex/_Annex_05_设计模式怎样解决设计问题.md)
- [有关设计模式的讨论](Contents/annex/_Annex_06_有关设计模式的讨论.md)

---