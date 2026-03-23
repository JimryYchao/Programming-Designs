## Singleton Pattern


单例模式 (Singleton) 保证一个类只有一个实例，并提供一个全局访问点。单例模式解决了全局实用类频繁创建与销毁的问题。

> **参与者**

- Singleton：定义一个 Instance 操作，允许客户访问它的唯一实例，Instance 是一个类操作 (类方法或静态成员等)。Instance 操作中有时需要使用同步锁防止多线程同时进入造成多次实例化。

> **设计要点**

1. Singleton 模式中的实例构造器可以设置为 protected 以允许子类派生。
2. Singleton 模式一般不要支持 ICloneable 接口，因为这可能会导致多个对象实例，与 Singleton 模式的初衷违背。
3. Singleton 模式一般不要支持序列化，因为这也有可能导致多个对象实例，同样与 Singleton 模式的初衷违背。
4. Singleton 模式只考虑到了对象创建的管理，没有考虑对象销毁的管理。就支持垃圾回收的平台和对象的开销来讲，我们一般没有必要对其销毁进行特殊的管理。
5. 不能应对多线程环境：在多线程环境下，使用 Singleton 模式仍然有可能得到 Singleton 类的多个实例对象。


> **案例实现**

<p align="left">
  <a href="../DP_examples/CSharp/01_Creational/Singleton/Singleton.cs"><img src="https://img.shields.io/badge/C%23-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C/01_Creational/Singleton/Singleton.c"><img src="https://img.shields.io/badge/C-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/C++/01_Creational/Singleton/Singleton.hpp"><img src="https://img.shields.io/badge/C++-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Lua/01_Creational/Singleton/Singleton.lua"><img src="https://img.shields.io/badge/Lua-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Go/01_Creational/Singleton/Singleton.go"><img src="https://img.shields.io/badge/Go-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Python/01_Creational/Singleton/Singleton.py"><img src="https://img.shields.io/badge/Python-00599C?for-the-badge&logoColor=white"></a>
  <a href="../DP_examples/Rust/01_Creational/Singleton/src/singleton.rs"><img src="https://img.shields.io/badge/Rust-00599C?for-the-badge&logoColor=white"></a>
</p>

>---

### 单例的常规实现
#### 单线程安全 (非多线程安全特性)

> 常规实现

```csharp
    public class Singleton{
        private static Singleton instance;
        private Singleton(){}
        public static Singleton getInstance(){
            if(instance == null)
                instance = new Singleton();
            return instance;
        }
    }
```

> CSharp 属性调用单例

```csharp
    public class Singleton{
        private static Singleton instance;
        private Singleton(){}
        public static Singleton Instance{
            get{
                if(instance == null)
                    instance = new Singleton();
                return instance;
            }
        }
    }
```

> 带参构造单例

```csharp
    public class Singleton{
        private static Singleton instance;
        int x,y;
        public static Singleton getInstance(int x, int y){
            if(instance == null)
                instance = new Singleton(x,y);
            else{
                instance.x = x;
                instance.y = y;
            }return instance;
        }
        private Singleton(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
```

#### 单例继承模式

> 反射法

```csharp
 public class InheritSingleton<T> where T : InheritSingleton<T>
{
    private InheritSingleton() { }
    private static readonly Lazy<T> instance = new Lazy<T>(() =>
    {
        var ctors = typeof(T).GetConstructors(
          BindingFlags.Instance
          | BindingFlags.NonPublic
          | BindingFlags.Public);
        if (ctors.Count() != 1)
            throw new InvalidOperationException(String.Format("Type {0} must have exactly one constructor.", typeof(T)));
        // 子类可以设置为仅拥有私有或受保护的构造函数
        var ctor = ctors.SingleOrDefault(c => !c.GetParameters().Any() &&
        /* 按需求选择搭配 */
        (c.IsPrivate /* 是否私有 */ || c.IsFamily /* 是否派生 */ || c.IsAssembly /* 是否程序集可见 */ ));
        if (ctor == null)
            throw new InvalidOperationException(String.Format("The constructor for {0} must be private or protected and take no parameters.", typeof(T)));
        return (T)ctor.Invoke(null);
    }, true);
    public static T Instance => instance.Value;
}
```

#### 多线程安全

> 内联初始化 (静态构造)

```csharp
    public class Singleton{
        public static readonly Singleton Instance = new Singleton();
    }
```

> 锁构造方式

```csharp
    public class Singleton{
        private static volatile Singleton instance = null;
        private static object locker = new object();
        public static Singleton Instance{
            get{
                if(instance == null)
                    lock(locker){
                        if(instance == null)
                            instance = new Singleton();
                    }
                return instance;
            }
        }
    }
```

> 延迟初始化 (System.Lazy)

```csharp
    public class Singleton{
        private static readonly Lazy<Singleton> instance =
            new Lazy<Singleton>(()=>new Singleton());
        public static Singleton Instance => instance.Value;
    }
```

#### 接口的抽象静态单例实现

- 可以在接口中声明，抽象静态单例属性，要求所有派生实现类需要提供这样的静态单例。

```csharp
public interface ISingleton<T> where T : ISingleton<T>
{
    static abstract T Instance { get; }
}
class SingleClassA : ISingleton<SingleClassA>
{
    private static readonly SingleClassA s_ins = new SingleClassA();
    public static SingleClassA Instance => s_ins;
}
class SingleClassB : ISingleton<SingleClassB>
{
    private static readonly SingleClassB s_ins = new SingleClassB();
    public static SingleClassB Instance => s_ins;
}
```

#### 线程单例模式

- 每个线程一个单例。

```csharp
internal class ThreadSingleton(int threadId)
{
    public int ThreadSingletonID => threadId;
    [ThreadStatic]
    private static ThreadSingleton s_instance;  // 不能使用 readonly，只读静态字段初始化只调用一次静态构造函数。
    public static ThreadSingleton Instance => s_instance ??= new ThreadSingleton(Thread.CurrentThread.ManagedThreadId); 
}
```

---