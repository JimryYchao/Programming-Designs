namespace Structural;

using Structural.Flyweight;
public class FlyweightDemo
{
    static void BuildCircles()
    {
        Circle redCircle = FlyweightFactory.GetCircle("Red", 10, 0,0);
        redCircle.Draw();
        redCircle.Fill();
        Console.WriteLine();
        CircleAddition greenBigCircle = FlyweightFactory.GetSpecialCircle("Green", 100,100,100);
        greenBigCircle.Draw();
        greenBigCircle.Fill();
        greenBigCircle.ResetRadius(10);
        greenBigCircle.MovePosition(0, 0);
    }
    static void BuildFlyweightCircle()
    {
        Circle redCircle = (Circle)FlyweightFactory.GetCircle("Red", 10, 10086, 10010);
        redCircle.Draw();
        redCircle.Fill();
    }
    public static void Example()
    {
        BuildCircles();
        Console.WriteLine();
        BuildFlyweightCircle();
    }
}