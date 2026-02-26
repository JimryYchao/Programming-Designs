mod mediator;

use mediator::{User, PrivateChatRoom, PublicChatRoom};

fn main() {
    // 创建用户
    let tom = User::new("Tom");
    let lily = User::new("Lily");

    // 获取聊天室实例
    let private_room = PrivateChatRoom::get_instance();
    let public_room = PublicChatRoom::get_instance();

    // 发送消息
    tom.send_message(public_room, None, "Hi! I'm Tom");
    lily.send_message(public_room, None, "Hi! I'm Lily");
    tom.send_message(private_room, Some(&lily), "How are U! Lily");
    lily.send_message(private_room, Some(&tom), "Fine!");
}
