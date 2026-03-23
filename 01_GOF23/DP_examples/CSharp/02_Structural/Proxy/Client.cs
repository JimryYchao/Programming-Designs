namespace Structural;
using Structural.Proxy;

public class ProxyDemo
{
    public static void Example()
    {
        // 实体对象
        RealImage img1 = new RealImage("//path/image1");
        RealImage img2 = new RealImage("//path/image2");
        RealImage img3 = new RealImage("//path/image3");
        RealImage img4 = new RealImage("//path/image4");
        RealImage img5 = new RealImage("//path/image5");
        // 代理对象
        ImageProxy imageProxy = new ImageProxy();
        imageProxy.AddImages(img1, img2, img3, img4, img5);
        imageProxy.loadFromDisk();
        imageProxy.Operation();
    }
}