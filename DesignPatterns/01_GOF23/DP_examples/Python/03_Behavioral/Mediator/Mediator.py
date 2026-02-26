# 中介者接口
from abc import ABC, abstractmethod

class IMediator(ABC):
    @abstractmethod
    def show_message(self, ori_user, des_user, message):
        pass

# 用户类
class User:
    def __init__(self, name):
        self.name = name
    
    def get_name(self):
        return self.name
    
    def send_message(self, room, des_user, message):
        room.show_message(self, des_user, message)

# 具体中介者 - 私聊房间
class PrivateChatRoom(IMediator):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(PrivateChatRoom, cls).__new__(cls)
        return cls._instance
    
    def show_message(self, ori_user, des_user, message):
        print(f"[PrivateChatRoom][{ori_user.get_name()}] sent to [{des_user.get_name()}]: {message}")

# 具体中介者 - 公共聊天室
class PublicChatRoom(IMediator):
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(PublicChatRoom, cls).__new__(cls)
        return cls._instance
    
    def show_message(self, user, des_user, message):
        print(f"[PublicChatRoom][{user.get_name()}]: {message}")
    
    def show_message_public(self, user, message):
        self.show_message(user, None, message)
