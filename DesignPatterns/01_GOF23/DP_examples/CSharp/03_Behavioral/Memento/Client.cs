namespace Behavioral;

using Behavioral.Memento;
public class MementoDemo
{
    public static void Example()
    {
        Originator o = new Originator("Hello", "World", "!");
        Caretaker.SaveMemento(1, o.CreateMemento(1));  // 保存第一版
        o = new Originator("X", "Y", "Z");
        o.ConsoleState();
        o.SetMemento(Caretaker.GetMemento(1));  // 恢复第一版
        o.ConsoleState();
    }
}