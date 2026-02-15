package Adapter_test

import (
	. "Adapter"
	"testing"
)

func TestAdapterPattern(t *testing.T) {
	// 创建适配器实例
	player := NewPlayerAdapter()
	// 播放背景音乐
	player.Play("BGMusic.wave", Wave)
	// 播放 CG 视频
	player.Play("CG.mp4", MP4)
}
