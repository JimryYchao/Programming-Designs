package Adapter

import "fmt"

// 媒体类型枚举
type MediaType int

const (
	MP3 MediaType = iota
	AIFF
	MIDI
	Wave
	MP4
	MOV
	AVI
	M4V
)

// 被适配的接口
type IAdvancedMediaPlayer interface {
	PlayMedia(fileName string, typ MediaType)
}

// 音频播放器（被适配的类）
type AudioPlayer struct{}

func (ap *AudioPlayer) PlayMedia(fileName string, typ MediaType) {
	switch typ {
	case AIFF:
		fmt.Println("PlayAudio AIFF :", fileName)
	case MIDI:
		fmt.Println("PlayAudio MIDI :", fileName)
	case Wave:
		fmt.Println("PlayAudio wave :", fileName)
	}
}

// 视频播放器（被适配的类）
type VideoPlayer struct{}

func (vp *VideoPlayer) PlayMedia(fileName string, typ MediaType) {
	switch typ {
	case MP4:
		fmt.Println("PlayVideo mp4 :", fileName)
	case MOV:
		fmt.Println("PlayVideo mov :", fileName)
	case AVI:
		fmt.Println("PlayVideo avi :", fileName)
	case M4V:
		fmt.Println("PlayVideo m4v :", fileName)
	}
}
