namespace Behavioral.Mediator;

public interface IMediator
{
    void ShowMessage(User oriUser, User desUser, string message);
}