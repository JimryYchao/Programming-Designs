using Structural.Composite;
namespace Structural;

public class CompositeDemo
{
    static IComponent BuildATeam()
    {
        IComponent boss = new Employee(false).Init("Tom", "man", 45, 50000);

        IComponent chargeA = new Employee(false).Init("Lily", "woman", 25, 12000);
        IComponent chargeB = new Employee(false).Init("Jerry", "man", 27, 11000);

        IComponent baseA = new Employee(true).Init("Lee", "woman", 21, 8000);
        IComponent baseB = new Employee(true).Init("Ychao", "man", 21, 7500);
        IComponent baseC = new Employee(true).Init("Tomas", "man", 22, 7000);
        IComponent baseD = new Employee(true).Init("Jimmy", "man", 23, 8200);

        boss.Add(chargeA);
        boss.Add(chargeB);
        chargeA.Add(baseA);
        chargeA.Add(baseB);
        chargeB.Add(baseC);
        chargeB.Add( baseD);
        return boss;
    }

    public static void Example()
    {
        var tree = BuildATeam();
        tree.Operation();
    }
}
