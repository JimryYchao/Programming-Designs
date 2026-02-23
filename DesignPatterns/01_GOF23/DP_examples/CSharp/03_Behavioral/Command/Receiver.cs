namespace Behavioral.Command;

public record struct Stock(string Name, int Quantity);
public interface IReceiver
{
    void Action();
}
public class BuyStock(Stock stock) : IReceiver
{
    public void BuyStocks()
    {
        Console.WriteLine($"Buy {stock.Quantity} Stocks which name is {stock.Name}");
    }
    public void Action() => BuyStocks();
}
public class SellStock(Stock stock) : IReceiver
{
    public void SellStocks()
    {
        Console.WriteLine($"Sell {stock.Quantity} Stocks which name is {stock.Name}");
    }
    public void Action() => SellStocks();
}
