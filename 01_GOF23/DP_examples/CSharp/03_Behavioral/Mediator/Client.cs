namespace Behavioral;
using Behavioral.Mediator;

public class MediatorDemo
{
    public static void Example()
    {
        User Tom = new User("Tom");
        User Lily = new User("Lily");

        Tom.SendMessage(PublicChatRoom.Instance, null, "Hi! I'm Tom");
        Lily.SendMessage(PublicChatRoom.Instance, null, "Hi! I'm Lily");
        Tom.SendMessage(PrivateChatRoom.Instance, Lily, "How are U! Lily");
        Lily.SendMessage(PrivateChatRoom.Instance, Tom, "Fine!");
    }
}