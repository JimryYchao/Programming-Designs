namespace Creational;

using Creational.Singleton;
using System.Diagnostics;
using System.Threading;

public class SingletonDemo {
    public static void Example() {
        var s = Singleton.Singleton.Instance;
        Debug.Assert(object.ReferenceEquals(s, Singleton.Singleton.Instance));

        var sl = Singleton_Lock.Instance;
        Debug.Assert(object.ReferenceEquals(sl, Singleton_Lock.Instance));

        var slazy = Singleton_Lazy.Instance;
        Debug.Assert(object.ReferenceEquals(slazy, Singleton_Lazy.Instance));

        var sinline = Singleton_Inline.Instance;
        Debug.Assert(object.ReferenceEquals(sinline, Singleton_Inline.Instance));

        var st = Singleton_Thread.Instance;
        Debug.Assert(object.ReferenceEquals(st, Singleton_Thread.Instance));
        new Thread(() => {
            var st_otherThread = Singleton_Thread.Instance;
            Debug.Assert(!object.ReferenceEquals(st, st_otherThread));
        }).Start();

        MonoSingleton.Instance.Log();
        GameSingleton.Instance.Log();

        getISingleton<SingleClassA>().Log();
        getISingleton<SingleClassB>().Log();
    }

    static T getISingleton<T>() where T : ISingleton<T> {
        return T.Instance;
    }

}

