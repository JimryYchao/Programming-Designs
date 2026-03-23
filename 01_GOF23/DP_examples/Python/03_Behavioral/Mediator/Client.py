from Mediator import User, PrivateChatRoom, PublicChatRoom

if __name__ == "__main__":
    # 创建用户
    Tom = User("Tom")
    Lily = User("Lily")

    # 获取聊天室实例
    private_room = PrivateChatRoom()
    public_room = PublicChatRoom()

    # 发送消息
    Tom.send_message(public_room, None, "Hi! I'm Tom")
    Lily.send_message(public_room, None, "Hi! I'm Lily")
    Tom.send_message(private_room, Lily, "How are U! Lily")
    Lily.send_message(private_room, Tom, "Fine!")
