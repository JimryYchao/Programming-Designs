using System.Threading;

namespace Creational.Singleton;

// 非线程安全单例
public class Singleton {
    public static Singleton Instance => (field ??= new Singleton());
}
// 带锁线程安全单例
public class Singleton_Lock {
    private static Lock sync = new();
    public static Singleton_Lock Instance {
        get {
            if (field == null)
                lock (sync)
                    field ??= new Singleton_Lock();
            return field;
        }
    }
}
// 延时单例
public class Singleton_Lazy {
    private static Lazy<Singleton_Lazy> instance;
    public static Singleton_Lazy Instance => instance != null ? instance.Value : (instance = new Lazy<Singleton_Lazy>()).Value;
}
// 内联单例
public class Singleton_Inline {
    public readonly static Singleton_Inline Instance = new Singleton_Inline();
}

internal class Singleton_Thread {
    private Singleton_Thread(int threadid) => ThreadID = threadid;
    public int ThreadID { get; }
    [ThreadStatic]
    private static Singleton_Thread s_instance;
    public static Singleton_Thread Instance => s_instance ??= new Singleton_Thread(Thread.CurrentThread.ManagedThreadId);
}
// 继承单例
public abstract class Singleton_Inherit<T> where T : new() {
    protected static T instance;
    public static T Instance => instance ??= new T();
    public abstract void Log();
}
public class MonoSingleton : Singleton_Inherit<MonoSingleton> {
    public override void Log() {
        Console.WriteLine("MonoSingleton is Created");
    }
}
public class GameSingleton : Singleton_Inherit<GameSingleton> {
    public override void Log() {
        Console.WriteLine("GameSingleton is Created");
    }
}
// 抽象接口单例继承
public interface ISingleton<T> where T : ISingleton<T> {
    static abstract T Instance { get; }
    void Log();
}
class SingleClassA : ISingleton<SingleClassA> {
    static SingleClassA ISingleton<SingleClassA>.Instance => field ??= new SingleClassA();
    public void Log() {
        Console.WriteLine("SingleClassA is Created");
    }
}
class SingleClassB : ISingleton<SingleClassB> {
    static SingleClassB ISingleton<SingleClassB>.Instance => field ??= new SingleClassB();
    public void Log() {
        Console.WriteLine("SingleClassB is Created");
    }
}