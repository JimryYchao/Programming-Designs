package Adapter

// 适配器类
type PlayerAdapter struct {
	player       *Player
	audioPlayer  *AudioPlayer
	videoPlayer  *VideoPlayer
}

// 构造函数
func NewPlayerAdapter() *PlayerAdapter {
	return &PlayerAdapter{
		player:      &Player{},
		audioPlayer: &AudioPlayer{},
		videoPlayer: &VideoPlayer{},
	}
}

// 实现目标接口
func (pa *PlayerAdapter) Play(fileName string, typ MediaType) {
	// 调用原始播放器
	pa.player.Play(fileName, typ)
	// 调用音频播放器
	pa.audioPlayer.PlayMedia(fileName, typ)
	// 调用视频播放器
	pa.videoPlayer.PlayMedia(fileName, typ)
}
