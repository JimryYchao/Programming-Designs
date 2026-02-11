namespace Creational.Builder;

public class Director<Builder> where Builder : IMealBuilder, new() {
    static Builder builder = new Builder();
    public static MealBuilder Construct() {
        return new MealBuilder(builder.GetBuilders());
    }
}
