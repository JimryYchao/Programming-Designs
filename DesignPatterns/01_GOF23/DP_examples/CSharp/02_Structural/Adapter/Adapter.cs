namespace Structural.Adapter;

public class PlayerAdapter : IPlayer {
    // Adaptee
    AudioPlayer audioPlayer = new AudioPlayer();
    VideoPlayer videoPlayer = new VideoPlayer();
    // Adapter
    Player Player = new Player();

    public void Play(string fileName, MediaType type) {
        // 适配接口
        Player.Play(fileName, type);
        audioPlayer.PlayMedia(fileName, type);
        videoPlayer.PlayMedia(fileName, type);
    }
}