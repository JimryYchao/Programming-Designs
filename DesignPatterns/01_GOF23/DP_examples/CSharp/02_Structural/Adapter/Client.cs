namespace Structural;

using Structural.Adapter;

public class AdapterDemo {
    public static void Example() {

        IPlayer p = new PlayerAdapter();
        // play bg music
        p.Play("BGMusic.wave", MediaType.wave);

        // play CG
        p.Play("CG.mp4", MediaType.mp4);
    }
}
