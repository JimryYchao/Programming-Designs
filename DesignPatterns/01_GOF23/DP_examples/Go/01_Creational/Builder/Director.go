package Builder

type Director[Builder IMealBuilder] struct {
	mealBuilder *Builder
}

func (d *Director[Builder]) Construct() MealBuilder {
	if d.mealBuilder == nil {
		d.mealBuilder = new(Builder)
	}
	return MealBuilder{
		builders: (*d.mealBuilder).GetBuilders(),
	}
}
