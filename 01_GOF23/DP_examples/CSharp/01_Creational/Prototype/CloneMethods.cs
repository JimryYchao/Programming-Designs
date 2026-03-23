
using Newtonsoft.Json;
using System.IO;
using System.Reflection;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Xml.Serialization;

namespace Creational.Prototype;

internal static class CloneMethodsExt {
    /// <summary>
    /// 使用二进制流进行 对象深拷贝, 要求对象必须具有 [Serializable] 属性
    /// </summary>
    [Obsolete("在 5.0 后续版本中被弃用")]
    public static T CloneObject<T>(this T source) where T : Shape {
        if (!typeof(T).IsSerializable)
            throw new ArgumentException("The type must be Serializable.", "source");
        if (Object.ReferenceEquals(source, null))
            return default(T);
        IFormatter formatter = new BinaryFormatter();
        Stream stream = new MemoryStream();
        using (stream) {
            formatter.Serialize(stream, source);
            stream.Seek(0, SeekOrigin.Begin);
            stream.Close();
            return (T)formatter.Deserialize(stream);
        }
    }
    /// <summary>
    /// 利用序列化与反序列化进行 对象深拷贝
    /// </summary>
    public static T SerializerClone<T>(this T source) where T : Shape {
        if (Object.ReferenceEquals(source, null))
            return default(T);
        JsonSerializerSettings serializerSettings = new JsonSerializerSettings {
            ObjectCreationHandling = ObjectCreationHandling.Replace
        };
        return JsonConvert.DeserializeObject<T>(JsonConvert.SerializeObject(source), serializerSettings);
    }
    /// <summary>
    /// 利用反射进行 对象深拷贝
    /// </summary>
    public static T ReflectClone<T>(this T source) where T : class {
        if (source is string || source.GetType().IsValueType)
            return source;
        object retval = Activator.CreateInstance(source.GetType());
        FieldInfo[] fields = source.GetType().GetFields(BindingFlags.Public
            | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
        foreach (FieldInfo item in fields) {
            try {
                item.SetValue(retval, ReflectClone(item.GetValue(source)));
            } catch (Exception) {
                Console.WriteLine("ReflectClone failed");
            }
        }
        return retval as T;
    }
    /// <summary>
    /// 利用 XML 序列化进行 对象深拷贝
    /// </summary>
    public static T XMLSerClone<T>(this T source) where T : Shape, new() {
        T docItms = new T();
        using (MemoryStream ms = new MemoryStream()) {
            XmlSerializer xms = new XmlSerializer(docItms.GetType());
            xms.Serialize(ms, source);
            ms.Seek(0, SeekOrigin.Begin);
            docItms = (T)xms.Deserialize(ms);
            ms.Close();
        }
        return docItms == null ? default(T) : docItms;
    }
    /// <summary>
    /// 利用 DataContract 序列化进行 对象深拷贝
    /// </summary>
    public static T DataSerClone<T>(this T source) where T : Shape, new() {
        T docItms = new T();
        using (MemoryStream ms = new MemoryStream()) {
            DataContractSerializer ser = new DataContractSerializer(docItms.GetType());
            ser.WriteObject(ms, source);
            ms.Seek(0, SeekOrigin.Begin);
            docItms = (T)ser.ReadObject(ms);
            ms.Close();
        }
        return docItms == null ? default(T) : docItms;
    }
}
