using System.Linq;

namespace Structural.Proxy;

public class ImageProxy : Image
{
    public List<Image> Images = new();
    public void Operation()
    {
        foreach (var image in Images)
            image.Operation();
    }
    public void loadFromDisk()
    {
        foreach (var item in Images)
            item.loadFromDisk();
    }
    public void AddImage(Image image)
    {
        Images.Add(image);
    }
    public void AddImages(params IEnumerable<Image> imgs) {
        Images.AddRange(imgs);
    }

    public bool Remove(Image image)
    {
        return Images.Remove(image);
    }
}