package mediator

import "fmt"

// IMediator 中介者接口
type IMediator interface {
	ShowMessage(oriUser *User, desUser *User, message string)
}

// User 用户类
type User struct {
	Name string
}

// NewUser 创建用户
func NewUser(name string) *User {
	return &User{Name: name}
}

// SendMessage 发送消息
func (u *User) SendMessage(room IMediator, desUser *User, message string) {
	room.ShowMessage(u, desUser, message)
}

// PrivateChatRoom 私聊房间
type PrivateChatRoom struct{}

// privateChatRoomInstance 静态实例
var privateChatRoomInstance *PrivateChatRoom

// GetPrivateChatRoomInstance 获取私聊房间实例
func GetPrivateChatRoomInstance() *PrivateChatRoom {
	if privateChatRoomInstance == nil {
		privateChatRoomInstance = &PrivateChatRoom{}
	}
	return privateChatRoomInstance
}

// ShowMessage 显示消息
func (r *PrivateChatRoom) ShowMessage(oriUser *User, desUser *User, message string) {
	fmt.Printf("[PrivateChatRoom][%s] sent to [%s]: %s\n", oriUser.Name, desUser.Name, message)
}

// PublicChatRoom 公共聊天室
type PublicChatRoom struct{}

// publicChatRoomInstance 静态实例
var publicChatRoomInstance *PublicChatRoom

// GetPublicChatRoomInstance 获取公共聊天室实例
func GetPublicChatRoomInstance() *PublicChatRoom {
	if publicChatRoomInstance == nil {
		publicChatRoomInstance = &PublicChatRoom{}
	}
	return publicChatRoomInstance
}

// ShowMessage 显示消息
func (r *PublicChatRoom) ShowMessage(user *User, desUser *User, message string) {
	fmt.Printf("[PublicChatRoom][%s]: %s\n", user.Name, message)
}

// ShowMessagePublic 显示公共消息
func (r *PublicChatRoom) ShowMessagePublic(user *User, message string) {
	r.ShowMessage(user, nil, message)
}
