package Observer

import "sync"

// Subject 具体主题
type Subject struct {
	name     string
	password string
	changeMgr *SimpleChangeManager
}

var subjectInstance *Subject
var subjectOnce sync.Once

// GetSubject 获取主题实例
func GetSubject() *Subject {
	subjectOnce.Do(func() {
		subjectInstance = &Subject{
			changeMgr: NewSimpleChangeManager(subjectInstance),
		}
		// 重新设置changeMgr的subject为当前实例
		subjectInstance.changeMgr = NewSimpleChangeManager(subjectInstance)
	})
	return subjectInstance
}

// RegisterAccount 注册账户
func (s *Subject) RegisterAccount(name, password string) {
	s.name = name
	s.password = password
	s.Attach(GetRegisterObserver())
}

// LoginAccount 登录账户
func (s *Subject) LoginAccount(name, password string) {
	s.name = name
	s.password = password
	s.Attach(GetLoginObserver())
}

// GetState 获取状态
func (s *Subject) GetState(state int) string {
	switch state {
	case 0:
		return s.name
	case 1:
		return s.password
	default:
		return ""
	}
}

// Attach 附加观察者
func (s *Subject) Attach(observer IObserver) {
	s.changeMgr.Register(s, observer)
}

// Detach 分离观察者
func (s *Subject) Detach(observer IObserver) {
	s.changeMgr.Unregister(s, observer)
}

// Notify 通知观察者
func (s *Subject) Notify() {
	s.changeMgr.Notify()
	s.changeMgr.ClearObserver()
}
