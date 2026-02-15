package Adapter

import "fmt"

// 目标接口
type IPlayer interface {
	Play(fileName string, typ MediaType)
}

// 具体目标类
type Player struct{}

func (p *Player) Play(fileName string, typ MediaType) {
	if typ == MP3 {
		fmt.Println("PlayAudio mp3 :", fileName)
	}
}
