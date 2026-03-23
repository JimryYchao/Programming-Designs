package Builder

// burger builder
type burgerBuilder[T burger] struct{}

func (b *burgerBuilder[T]) Build() Item {
	return *new(T)
}
func NewBurgerBuilder[T burger]() *burgerBuilder[T] {
	return &burgerBuilder[T]{}
}

// coldDrink builder
type coldDrinkBuilder[T coldDrink] struct{}

func (c *coldDrinkBuilder[T]) Build() Item {
	return *new(T)
}

func NewColdDrinkBuilder[T coldDrink]() *coldDrinkBuilder[T] {
	return &coldDrinkBuilder[T]{}
}

// 实例
var (
	VegetableBurgerBuilder IBuilder = NewBurgerBuilder[vegetableBurger]()
	ChickenBurgerBuilder   IBuilder = NewBurgerBuilder[chickenBurger]()
	CokeColaBuilder        IBuilder = NewColdDrinkBuilder[cokeCola]()
	PepsiColaBuilder       IBuilder = NewColdDrinkBuilder[pepsiCola]()
)

// 套餐建造者
type ChickenMealBuilder struct{}

type VegMealBuilder struct{}

func (c ChickenMealBuilder) GetBuilders() []IBuilder {
	return []IBuilder{
		ChickenBurgerBuilder,
		PepsiColaBuilder,
	}
}

func (v VegMealBuilder) GetBuilders() []IBuilder {
	return []IBuilder{
		VegetableBurgerBuilder,
		CokeColaBuilder,
	}
}

// 套餐产品
type MealBuilder struct {
	builders []IBuilder
	items    []Item
}

func newMealBuilder(builders []IBuilder) *MealBuilder {
	return &MealBuilder{
		builders: builders,
		items:    make([]Item, 0),
	}
}

func (m *MealBuilder) Add(kind ItemKind) {
	switch kind {
	case VEGETABLE_BURGER:
		m.builders = append(m.builders, VegetableBurgerBuilder)
	case CHICKEN_BURGER:
		m.builders = append(m.builders, ChickenBurgerBuilder)
	case COKE_COLA:
		m.builders = append(m.builders, CokeColaBuilder)
	case PEPSI_COLA:
		m.builders = append(m.builders, PepsiColaBuilder)
	}
}

func (m *MealBuilder) Remove(kind ItemKind) {
	var remove IBuilder
	switch kind {
	case VEGETABLE_BURGER:
		remove = VegetableBurgerBuilder
	case CHICKEN_BURGER:
		remove = ChickenBurgerBuilder
	case COKE_COLA:
		remove = CokeColaBuilder
	case PEPSI_COLA:
		remove = PepsiColaBuilder
	}
	for i, b := range m.builders {
		if b == remove {
			m.builders = append(m.builders[:i], m.builders[i+1:]...)
			break
		}
	}
}

func (m *MealBuilder) Build() {
	m.items = make([]Item, 0, len(m.builders))
	for _, b := range m.builders {
		m.items = append(m.items, b.Build())
	}
}

func (m *MealBuilder) Pack() {
	for _, item := range m.items {
		item.Packer().Pack(item)
	}
}

func (m *MealBuilder) GetCost() float64 {
	var sum float64
	for _, item := range m.items {
		sum += item.Price()
	}
	return sum
}
