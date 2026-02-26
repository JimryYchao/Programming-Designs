// 中介者接口
pub trait IMediator {
    fn show_message(&self, ori_user: &User, des_user: Option<&User>, message: &str);
}

// 用户类
pub struct User {
    pub name: String,
}

impl User {
    pub fn new(name: &str) -> Self {
        Self {
            name: name.to_string(),
        }
    }
    
    pub fn get_name(&self) -> &str {
        &self.name
    }
    
    pub fn send_message(&self, room: &dyn IMediator, des_user: Option<&User>, message: &str) {
        room.show_message(self, des_user, message);
    }
}

// 具体中介者 - 私聊房间
pub struct PrivateChatRoom;

// 静态实例
static mut PRIVATE_CHAT_ROOM_INSTANCE: Option<PrivateChatRoom> = None;

impl PrivateChatRoom {
    pub fn get_instance() -> &'static mut PrivateChatRoom {
        unsafe {
            if PRIVATE_CHAT_ROOM_INSTANCE.is_none() {
                PRIVATE_CHAT_ROOM_INSTANCE = Some(PrivateChatRoom);
            }
            PRIVATE_CHAT_ROOM_INSTANCE.as_mut().unwrap()
        }
    }
}

impl IMediator for PrivateChatRoom {
    fn show_message(&self, ori_user: &User, des_user: Option<&User>, message: &str) {
        if let Some(des) = des_user {
            println!("[PrivateChatRoom][{}] sent to [{}]: {}", ori_user.get_name(), des.get_name(), message);
        }
    }
}

// 具体中介者 - 公共聊天室
pub struct PublicChatRoom;

// 静态实例
static mut PUBLIC_CHAT_ROOM_INSTANCE: Option<PublicChatRoom> = None;

impl PublicChatRoom {
    pub fn get_instance() -> &'static mut PublicChatRoom {
        unsafe {
            if PUBLIC_CHAT_ROOM_INSTANCE.is_none() {
                PUBLIC_CHAT_ROOM_INSTANCE = Some(PublicChatRoom);
            }
            PUBLIC_CHAT_ROOM_INSTANCE.as_mut().unwrap()
        }
    }
    
    pub fn show_message_public(&self, user: &User, message: &str) {
        self.show_message(user, None, message);
    }
}

impl IMediator for PublicChatRoom {
    fn show_message(&self, user: &User, des_user: Option<&User>, message: &str) {
        println!("[PublicChatRoom][{}]: {}", user.get_name(), message);
    }
}
