using System.IO;
namespace Structural.Proxy;

public class RealImage(string filename) : Image
{
    private byte[] Image;
    public void Operation()
    {
        Console.WriteLine($"Do a operation with image:[{filename}]");
    }
    public void loadFromDisk()
    {
        Console.WriteLine($"load a Image from {filename}");
        // Image = File.ReadAllBytes(filename);
    }
}
