namespace Behavioral.Strategy;
public class Context
{
    private IStrategy strategy;
    private static Context instance;
    public static Context GetInstance(IStrategy strategy)
    {
        if (instance == null)
            instance = new Context();
        instance.strategy = strategy;
        return instance;
    }
    public void Sort(int[] array)
    {
        strategy.Sort(array);
    }
}