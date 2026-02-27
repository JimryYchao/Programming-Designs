package Observer_test

import (
	. "Observer"
	"testing"
)

func TestObserverPattern(t *testing.T) {
	// 测试注册
	subject := GetSubject()
	subject.RegisterAccount("test", "123456")
	subject.Notify()
	
	// 测试重复注册
	subject.RegisterAccount("test", "123456")
	subject.Notify()
	
	// 测试登录
	subject.LoginAccount("test", "123456")
	subject.Notify()
	
	// 测试登录失败
	subject.LoginAccount("test", "wrong")
	subject.Notify()
}
