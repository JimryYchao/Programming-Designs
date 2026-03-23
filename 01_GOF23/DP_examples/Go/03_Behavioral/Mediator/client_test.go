package mediator_test

import (
	. "mediator"
	"testing"
)

func TestMediatorPattern(t *testing.T) {
	// 创建用户
	Tom := NewUser("Tom")
	Lily := NewUser("Lily")

	// 获取聊天室实例
	privateRoom := GetPrivateChatRoomInstance()
	publicRoom := GetPublicChatRoomInstance()

	// 发送消息
	Tom.SendMessage(publicRoom, nil, "Hi! I'm Tom")
	Lily.SendMessage(publicRoom, nil, "Hi! I'm Lily")
	Tom.SendMessage(privateRoom, Lily, "How are U! Lily")
	Lily.SendMessage(privateRoom, Tom, "Fine!")
}
