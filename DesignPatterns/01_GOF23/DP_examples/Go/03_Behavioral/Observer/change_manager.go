package Observer

import "sync"

// SimpleChangeManager 简单变更管理器
type SimpleChangeManager struct {
	subject   ISubject
	observers []IObserver
}

// NewSimpleChangeManager 创建简单变更管理器
func NewSimpleChangeManager(subject ISubject) *SimpleChangeManager {
	return &SimpleChangeManager{
		subject:   subject,
		observers: make([]IObserver, 0),
	}
}

// Register 注册观察者
func (cm *SimpleChangeManager) Register(subject ISubject, observer IObserver) {
	for _, obs := range cm.observers {
		if obs == observer {
			return
		}
	}
	cm.observers = append(cm.observers, observer)
}

// Unregister 注销观察者
func (cm *SimpleChangeManager) Unregister(subject ISubject, observer IObserver) {
	for i, obs := range cm.observers {
		if obs == observer {
			cm.observers = append(cm.observers[:i], cm.observers[i+1:]...)
			break
		}
	}
}

// Notify 通知观察者
func (cm *SimpleChangeManager) Notify() {
	for _, observer := range cm.observers {
		observer.Update(cm.subject)
	}
}

// ClearObserver 清空观察者
func (cm *SimpleChangeManager) ClearObserver() {
	cm.observers = make([]IObserver, 0)
}

// DCGChangeManager 多主题变更管理器
type DCGChangeManager struct {
	subjectObservers map[ISubject][]IObserver
	mutex           sync.RWMutex
}

var dcgInstance *DCGChangeManager
var dcgOnce sync.Once

// GetDCGChangeManager 获取DCG变更管理器实例
func GetDCGChangeManager() *DCGChangeManager {
	dcgOnce.Do(func() {
		dcgInstance = &DCGChangeManager{
			subjectObservers: make(map[ISubject][]IObserver),
		}
	})
	return dcgInstance
}

// Register 注册观察者
func (cm *DCGChangeManager) Register(subject ISubject, observer IObserver) {
	cm.mutex.Lock()
	defer cm.mutex.Unlock()
	
	if _, ok := cm.subjectObservers[subject]; !ok {
		cm.subjectObservers[subject] = make([]IObserver, 0)
	}
	
	for _, obs := range cm.subjectObservers[subject] {
		if obs == observer {
			return
		}
	}
	
	cm.subjectObservers[subject] = append(cm.subjectObservers[subject], observer)
}

// Unregister 注销观察者
func (cm *DCGChangeManager) Unregister(subject ISubject, observer IObserver) {
	cm.mutex.Lock()
	defer cm.mutex.Unlock()
	
	if observers, ok := cm.subjectObservers[subject]; ok {
		for i, obs := range observers {
			if obs == observer {
				cm.subjectObservers[subject] = append(observers[:i], observers[i+1:]...)
				break
			}
		}
	}
}

// Notify 通知观察者
func (cm *DCGChangeManager) Notify() {
	cm.mutex.RLock()
	defer cm.mutex.RUnlock()
	
	for subject, observers := range cm.subjectObservers {
		for _, observer := range observers {
			observer.Update(subject)
		}
	}
}

// LoggerManager 日志管理器
type LoggerManager struct{}

var loggerInstance *LoggerManager
var loggerOnce sync.Once

// GetLoggerManager 获取日志管理器实例
func GetLoggerManager() *LoggerManager {
	loggerOnce.Do(func() {
		loggerInstance = &LoggerManager{}
	})
	return loggerInstance
}

// Register 注册观察者（瞬发消息）
func (lm *LoggerManager) Register(subject ISubject, observer IObserver) {
	observer.Update(subject)
}

// Unregister 注销观察者（未实现）
func (lm *LoggerManager) Unregister(subject ISubject, observer IObserver) {
	// 未实现
}

// Notify 通知观察者（未实现）
func (lm *LoggerManager) Notify() {
	// 未实现
}
