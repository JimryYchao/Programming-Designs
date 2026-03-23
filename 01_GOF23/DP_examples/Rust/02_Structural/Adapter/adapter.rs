use crate::adaptee::{AudioPlayer, VideoPlayer, MediaType, IAdvancedMediaPlayer};
use crate::target::{IPlayer, Player};

// 适配器类
pub struct PlayerAdapter {
    player: Player,
    audio_player: AudioPlayer,
    video_player: VideoPlayer,
}

impl PlayerAdapter {
    pub fn new() -> Self {
        Self {
            player: Player,
            audio_player: AudioPlayer,
            video_player: VideoPlayer,
        }
    }
}

impl IPlayer for PlayerAdapter {
    fn play(&self, file_name: &str, typ: MediaType) {
        // 调用原始播放器
        self.player.play(file_name, typ);
        // 调用音频播放器
        self.audio_player.play_media(file_name, typ);
        // 调用视频播放器
        self.video_player.play_media(file_name, typ);
    }
}
