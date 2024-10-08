### 通用职责分配软件模式 (GRASP) 

GRASP (General Responsibility Assignment Software) 通用职责分配软件模式，包括 4 个基本模式和 5 个扩展模式，描述了对象设计和职责分配的基本原则。

>---
#### 创建者 (Creator) 

对象的创建是面向对象系统中最常见的活动。**哪个类负责创建对象是衡量特定类的对象之间关系的一个重要特征，降低类与类之间的耦合度**。实际应用中，符合下列任一条件的时候，都应该由类 A 来创建类 B，这时 A 是 B 的创建者：
  - A 是 B 的聚合或容器。
  - A 持有初始化 B 的信息 (数据)。
  - A 记录 B 的实例。
  - A 频繁使用 B。

>---
#### 信息专家 (Information Expert) 

信息专家 (也称专家或专家原则) 是一个用于确定将职责委托给谁的原则。分配职责的一般方法是查看给定的职责所需信息存储在哪里。**把职责分配给具有履行该职责所需信息最多的类**。信息专家模式经常用于职责分配，完成职责往往需要分布在不同对象中的信息，许多 “局部” 的信息专家要通过协作来完成任务。

>---
#### 低耦合 (Low Coupling) 

**耦合是对某元素和其他元素之间的链接、感知和依赖程度的度量**。低耦合是在制定设计决策期间需要牢记的原则，是评估所有设计结果时要运用的评估原则。低耦合不能脱离专家和高内聚等模式孤立地考虑，应该作为影响职责分配的原则之一。

>---
#### 高内聚 (High Cohesion) 

高内聚是一种评估模式，使用该模式可以让对象保持适当的集中性、可管理性和可理解性。高内聚通常用于支持低耦合。**高内聚意味着给定元素的职责是紧密相关且高度集中的**。将程序分解成类和子系统是增加系统内聚性的一个例子。另外，低内聚性是指给定元素承担了太多不相关的职责。**内聚是对元素职责的相关性和集中度的度量。如果元素具有高度相关的职责，而且只完成有限的功能，则这个元素就具有高内聚性。**

>---
#### 控制器 (Controller) 

控制器模式将处理系统事件的责任分配给一个代表整体系统或用例场景的非 UI 类。**控制器对象是一个非用户界面对象，负责接收或处理系统事件**。通常，控制器应当把要完成的工作委派给其他对象，它只负责协调或控制，本身并不完成太多功能。把接收和协调 (控制) 系统事件的职责分配给一个类，这个类可以代表：
  - 整个系统、设备或者子系统。
  - 系统事件发生时对应的用例场景，在相同的用例场景中使用相同的控制器来处理所有的系统事件。

>---
#### 多态 (Polymorphism) 

根据多态原则，定义基于类型的行为变化，并由发生这种变化的类型负责。不同类型应使用多态操作，而不是基于类型的显式分支。**当相关选择或行为随类型而变化时，使用多态操作来为变化的行为分配职责**。

>---
#### 纯虚构 (Pure Fabrication) 

**纯虚构类并不表示具体的业务领域概念，把它构造出来是为了达到低耦合、高内聚的目的**，因此也提供了复用的潜力 (当基于信息专家的方案无法实现这些目的时)。如果信息专家所提供的方案，能够实现低耦合、高内聚，那没有必要用纯虚构，可以直接采用信息专家方案；当信息专家方案无法实现低耦合和高内聚时，那可以引入纯虚构方案。基本所有的设计模式都是纯虚构，比如控制器，适配器，观察者。

>---
#### 间接性 (Indirection) 

**间接性模式通过将两个元素之间的协调职责分配给一个中介对象**，来实现两个元素之间的低耦合以及提高其可复用的潜力。将职责分配给中介对象，使其作为其他构件或服务之间的媒介，以避免他们之间的直接耦合。中介实现了其他构件之间的间接性。

>---
#### 防止异变 (Protected Variations) 

**防止变异通过提供稳定接口 (并利用多态来创建这个接口的各种实现)**，从而保护元素不受其他元素 (对象、系统、子系统) 变化的影响。识别预计变化或不稳定之处，分配职责以在这些变化之外创建稳定接口。防止变异是最基本的软件设计原则，大部分设计原则和模式都是防止异变的机制。

---