package Observer

// IObserver 观察者接口
type IObserver interface {
	Update(subject ISubject)
}

// ISubject 主题接口
type ISubject interface {
	Attach(observer IObserver)
	Detach(observer IObserver)
	Notify()
}

// IChangeManager 变更管理器接口
type IChangeManager interface {
	Register(subject ISubject, observer IObserver)
	Unregister(subject ISubject, observer IObserver)
	Notify()
}
