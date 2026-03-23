namespace Structural.Flyweight;


public interface IShape
{
    void Draw();
    void Fill();
}

public record CircleData(string color, float radius /* other data */);

