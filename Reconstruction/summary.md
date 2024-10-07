#### 坏味道与重构手法速查表

|坏味道|常用重构|
|:--|:---|
|[神秘命名](/Contents/代码的坏味道md#神秘命名mysterious-name)| [改变函数声明](/Contents/重构名录.md#改变函数声明change-function-declaration), [变量改名](/Contents/重构名录.md#变量改名rename-variable), [字段改名](/Contents/重构名录.md#字段改名rename-field)|
|[重复代码](/Contents/代码的坏味道md#重复代码duplicated-code)| [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [移动语句](/Contents/重构名录.md#移动语句slide-statements), [函数上移](/Contents/重构名录.md#函数上移pull-up-method)|
|[过长函数](/Contents/代码的坏味道md#过长函数long-function)| [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [以查询取代临时变量](/Contents/重构名录.md#以查询取代临时变量replace-temp-with-query), [引入参数对象](/Contents/重构名录.md#引入参数对象introduce-parameter-object), [保持对象完整](/Contents/重构名录.md#保持对象完整preserve-whole-object), [以命令取代函数](/Contents/重构名录.md#以命令取代函数replace-function-with-command), [分解条件表达式](/Contents/重构名录.md#分解条件表达式decompose-conditional), [以多态取代条件表达式](/Contents/重构名录.md#以多态取代条件表达式replace-conditional-with-polymorphism), [拆分循环](/Contents/重构名录.md#拆分循环split-loop)|
|[过长参数列表](/Contents/代码的坏味道md#过长参数列表long-parameter-list)| [以查询取代参数](/Contents/重构名录.md#以查询取代参数replace-parameter-with-query), [保持对象完整](/Contents/重构名录.md#保持对象完整preserve-whole-object), [引入参数对象](/Contents/重构名录.md#引入参数对象introduce-parameter-object), [移除标记参数](/Contents/重构名录.md#移除标记参数remove-flag-argument), [函数组合成类](/Contents/重构名录.md#函数组合成类combine-functions-into-class)|
|[全局数据](/Contents/代码的坏味道md#全局数据global-data)| [封装变量](/Contents/重构名录.md#封装变量encapsulate-variable)|
|[可变数据](/Contents/代码的坏味道md#可变数据mutable-data)| [封装变量](/Contents/重构名录.md#封装变量encapsulate-variable), [拆分变量](/Contents/重构名录.md#拆分变量split-variable), [移动语句](/Contents/重构名录.md#移动语句slide-statements), [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [将查询函数和修改函数分离](/Contents/重构名录.md#将查询函数和修改函数分离separate-query-from-modifier), [移除设值函数](/Contents/重构名录.md#移除设值函数remove-setting-method), [以查询取代派生变量](/Contents/重构名录.md#以查询取代派生变量replace-derived-variable-with-query), [函数组合成类](/Contents/重构名录.md#函数组合成类combine-functions-into-class), [函数组合成变换](/Contents/重构名录.md#函数组合成变换combine-functions-into-transform), [将引用对象改为值对象](/Contents/重构名录.md#将引用对象改为值对象change-reference-tovalue)|
|[发散式变化](/Contents/代码的坏味道md#发散式变化divergent-change)| [拆分阶段](/Contents/重构名录.md#拆分阶段split-phase), [搬移函数](/Contents/重构名录.md#搬移函数move-function), [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [提炼类](/Contents/重构名录.md#提炼类extract-class)|
|[霰弹式修改](/Contents/代码的坏味道md#霰弹式修改shotgun-surgery)| [搬移函数](/Contents/重构名录.md#搬移函数move-function), [搬移字段](/Contents/重构名录.md#搬移字段move-field), [函数组合成类](/Contents/重构名录.md#函数组合成类combine-functions-into-class), [函数组合成变换](/Contents/重构名录.md#函数组合成变换combine-functions-into-transform), [拆分阶段](/Contents/重构名录.md#拆分阶段split-phase), [内联函数](/Contents/重构名录.md#内联函数inline-function), [内联类](/Contents/重构名录.md#内联类inline-class)|
|[依恋情结](/Contents/代码的坏味道md#依恋情结feature-envy)| [搬移函数](/Contents/重构名录.md#搬移函数move-function), [提炼函数](/Contents/重构名录.md#提炼函数extract-function)|
|[数据泥团](/Contents/代码的坏味道md#数据泥团data-clumps)| [提炼类](/Contents/重构名录.md#提炼类extract-class), [引入参数对象](/Contents/重构名录.md#引入参数对象introduce-parameter-object), [保持对象完整](/Contents/重构名录.md#保持对象完整preserve-whole-object)|
|[基本类型偏执](/Contents/代码的坏味道md#基本类型偏执primitive-obsession)| [以对象取代基本类型](/Contents/重构名录.md#以对象取代基本类型replace-primitive-with-object), [以子类取代类型码](/Contents/重构名录.md#以子类取代类型码replace-type-code-with-subclasses), [以多态取代条件表达式](/Contents/重构名录.md#以多态取代条件表达式replace-conditional-with-polymorphism), [提炼类](/Contents/重构名录.md#提炼类extract-class), [引入参数对象](/Contents/重构名录.md#引入参数对象introduce-parameter-object)|
|[重复的 switch](/Contents/代码的坏味道md#重复的-switch-repeated-switches)| [以多态取代条件表达式](/Contents/重构名录.md#以多态取代条件表达式replace-conditional-with-polymorphism)|
|[循环语句](/Contents/代码的坏味道md#循环语句loops)| [以管道取代循环](/Contents/重构名录.md#以管道取代循环replace-loop-with-pipeline)|
|[冗赘的元素](/Contents/代码的坏味道md#冗赘的元素lazy-element)| [内联函数](/Contents/重构名录.md#内联函数inline-function), [内联类](/Contents/重构名录.md#内联类inline-class), [折叠继承体系](/Contents/重构名录.md#折叠继承体系collapse-hierarchy)|
|[夸夸其谈通用性](/Contents/代码的坏味道md#夸夸其谈通用性speculative-generality)| [折叠继承体系](/Contents/重构名录.md#折叠继承体系collapse-hierarchy), [内联函数](/Contents/重构名录.md#内联函数inline-function), [内联类](/Contents/重构名录.md#内联类inline-class), [改变函数声明](/Contents/重构名录.md#改变函数声明change-function-declaration), [移除死代码](/Contents/重构名录.md#移除死代码remove-dead-code)|
|[临时字段](/Contents/代码的坏味道md#临时字段temporary-field)| [提炼类](/Contents/重构名录.md#提炼类extract-class), [搬移函数](/Contents/重构名录.md#搬移函数move-function), [引入特例](/Contents/重构名录.md#引入特例introduce-special-case)|
|[过长的消息链](/Contents/代码的坏味道md#过长的消息链message-chains)| [隐藏委托关系](/Contents/重构名录.md#隐藏委托关系hide-delegate), [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [搬移函数](/Contents/重构名录.md#搬移函数move-function)|
|[中间人](/Contents/代码的坏味道md#中间人middle-man)| [移除中间人](/Contents/重构名录.md#移除中间人remove-middle-man), [内联函数](/Contents/重构名录.md#内联函数inline-function), [以委托取代超类](/Contents/重构名录.md#以委托取代超类replace-superclass-with-delegate), [以委托取代子类](/Contents/重构名录.md#以委托取代子类replace-subclass-with-delegate)|
|[内幕交易](/Contents/代码的坏味道md#内幕交易insider-trading)| [搬移函数](/Contents/重构名录.md#搬移函数move-function), [搬移字段](/Contents/重构名录.md#搬移字段move-field), [隐藏委托关系](/Contents/重构名录.md#隐藏委托关系hide-delegate), [以委托取代子类](/Contents/重构名录.md#以委托取代子类replace-subclass-with-delegate), [以委托取代超类](/Contents/重构名录.md#以委托取代超类replace-superclass-with-delegate)|
|[过大的类](/Contents/代码的坏味道md#过大的类large-class)| [提炼类](/Contents/重构名录.md#提炼类extract-class), [提炼超类](/Contents/重构名录.md#提炼超类extract-superclass), [以子类取代类型码](/Contents/重构名录.md#以子类取代类型码replace-type-code-with-subclasses)|
|[异曲同工的类](/Contents/代码的坏味道md#异曲同工的类alternative-classes-with-different-interfaces)| [改变函数声明](/Contents/重构名录.md#改变函数声明change-function-declaration), [搬移函数](/Contents/重构名录.md#搬移函数move-function), [提炼超类](/Contents/重构名录.md#提炼超类extract-superclass) |
|[纯数据类](/Contents/代码的坏味道md#纯数据类data-class)| [封装记录](/Contents/重构名录.md#封装记录encapsulate-record), [移除设值函数](/Contents/重构名录.md#移除设值函数remove-setting-method), [搬移函数](/Contents/重构名录.md#搬移函数move-function), [提炼函数](/Contents/重构名录.md#提炼函数extract-function), [拆分阶段](/Contents/重构名录.md#拆分阶段split-phase)|
|[被拒绝的遗赠](/Contents/代码的坏味道md#被拒绝的遗赠refused-bequest)| [函数下移](/Contents/重构名录.md#函数下移push-down-method), [字段下移](/Contents/重构名录.md#字段下移push-down-field), [以委托取代子类](/Contents/重构名录.md#以委托取代子类replace-subclass-with-delegate), [以委托取代超类](/Contents/重构名录.md#以委托取代超类replace-superclass-with-delegate)|
|[注释](/Contents/代码的坏味道md#注释comments)|[提炼函数](/Contents/重构名录.md#提炼函数extract-function), [改变函数声明](/Contents/重构名录.md#改变函数声明change-function-declaration), [引入断言](/Contents/重构名录.md#引入断言introduce-assertion)|

---
#### Contents

- [代码的坏味道](Contents/代码的坏味道.md)
- [重构名录](Contents/重构名录.md)

---