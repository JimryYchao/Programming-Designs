#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 前向声明
struct User;

// 中介者接口
typedef struct IMediator IMediator;

struct IMediator {
    void (*ShowMessage)(IMediator*, struct User* oriUser, struct User* desUser, const char* message);
    void (*Destroy)(IMediator*);
};

// 用户类
typedef struct User User;

struct User {
    char* name;
    void (*SendMessage)(User*, IMediator* room, User* desUser, const char* message);
    void (*Destroy)(User*);
};

// 创建用户
User* CreateUser(const char* name);

// 具体中介者 - 私聊房间
typedef struct PrivateChatRoom PrivateChatRoom;

struct PrivateChatRoom {
    IMediator mediator;
};

// 获取私聊房间实例
PrivateChatRoom* GetPrivateChatRoomInstance();

// 具体中介者 - 公共聊天室
typedef struct PublicChatRoom PublicChatRoom;

struct PublicChatRoom {
    IMediator mediator;
    void (*ShowMessagePublic)(PublicChatRoom*, User* user, const char* message);
};

// 获取公共聊天室实例
PublicChatRoom* GetPublicChatRoomInstance();

#endif // MEDIATOR_H
