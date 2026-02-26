#include "mediator.h"

// 静态实例
static PrivateChatRoom* privateChatRoomInstance = NULL;
static PublicChatRoom* publicChatRoomInstance = NULL;

// 用户方法实现
static void User_SendMessage(User* self, IMediator* room, User* desUser, const char* message) {
    room->ShowMessage(room, self, desUser, message);
}

static void User_Destroy(User* self) {
    if (self->name) {
        free(self->name);
    }
    free(self);
}

// 创建用户
User* CreateUser(const char* name) {
    User* user = (User*)malloc(sizeof(User));
    if (user) {
        user->name = strdup(name);
        user->SendMessage = User_SendMessage;
        user->Destroy = User_Destroy;
    }
    return user;
}

// 私聊房间方法实现
static void PrivateChatRoom_ShowMessage(IMediator* self, User* oriUser, User* desUser, const char* message) {
    printf("[PrivateChatRoom][%s] sent to [%s]: %s\n", oriUser->name, desUser->name, message);
}

static void PrivateChatRoom_Destroy(IMediator* self) {
    // 单例模式，不在这里释放
}

// 获取私聊房间实例
PrivateChatRoom* GetPrivateChatRoomInstance() {
    if (!privateChatRoomInstance) {
        privateChatRoomInstance = (PrivateChatRoom*)malloc(sizeof(PrivateChatRoom));
        if (privateChatRoomInstance) {
            privateChatRoomInstance->mediator.ShowMessage = PrivateChatRoom_ShowMessage;
            privateChatRoomInstance->mediator.Destroy = PrivateChatRoom_Destroy;
        }
    }
    return privateChatRoomInstance;
}

// 公共聊天室方法实现
static void PublicChatRoom_ShowMessage(IMediator* self, User* user, User* desUser, const char* message) {
    printf("[PublicChatRoom][%s]: %s\n", user->name, message);
}

static void PublicChatRoom_Destroy(IMediator* self) {
    // 单例模式，不在这里释放
}

static void PublicChatRoom_ShowMessagePublic(PublicChatRoom* self, User* user, const char* message) {
    self->mediator.ShowMessage((IMediator*)self, user, NULL, message);
}

// 获取公共聊天室实例
PublicChatRoom* GetPublicChatRoomInstance() {
    if (!publicChatRoomInstance) {
        publicChatRoomInstance = (PublicChatRoom*)malloc(sizeof(PublicChatRoom));
        if (publicChatRoomInstance) {
            publicChatRoomInstance->mediator.ShowMessage = PublicChatRoom_ShowMessage;
            publicChatRoomInstance->mediator.Destroy = PublicChatRoom_Destroy;
            publicChatRoomInstance->ShowMessagePublic = PublicChatRoom_ShowMessagePublic;
        }
    }
    return publicChatRoomInstance;
}
