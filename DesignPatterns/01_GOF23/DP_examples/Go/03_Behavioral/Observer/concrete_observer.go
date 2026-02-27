package Observer

import "fmt"
import "sync"

// LoginObserver 登录观察者
type LoginObserver struct{}

var loginObserverInstance *LoginObserver
var loginObserverOnce sync.Once

// GetLoginObserver 获取登录观察者实例
func GetLoginObserver() *LoginObserver {
	loginObserverOnce.Do(func() {
		loginObserverInstance = &LoginObserver{}
	})
	return loginObserverInstance
}

// Update 更新
func (lo *LoginObserver) Update(subject ISubject) {
	if s, ok := subject.(*Subject); ok {
		GetAccountData().LoginAccount(s.GetState(0), s.GetState(1))
	}
}

// RegisterObserver 注册观察者
type RegisterObserver struct{}

var registerObserverInstance *RegisterObserver
var registerObserverOnce sync.Once

// GetRegisterObserver 获取注册观察者实例
func GetRegisterObserver() *RegisterObserver {
	registerObserverOnce.Do(func() {
		registerObserverInstance = &RegisterObserver{}
	})
	return registerObserverInstance
}

// Update 更新
func (ro *RegisterObserver) Update(subject ISubject) {
	if s, ok := subject.(*Subject); ok {
		GetAccountData().RegisterAccount(s.GetState(0), s.GetState(1))
	}
}

// LoginSuccessful 登录成功观察者
type LoginSuccessful struct{}

var loginSuccessfulInstance *LoginSuccessful
var loginSuccessfulOnce sync.Once

// GetLoginSuccessfulObserver 获取登录成功观察者实例
func GetLoginSuccessfulObserver() *LoginSuccessful {
	loginSuccessfulOnce.Do(func() {
		loginSuccessfulInstance = &LoginSuccessful{}
	})
	return loginSuccessfulInstance
}

// Update 更新
func (ls *LoginSuccessful) Update(subject ISubject) {
	fmt.Println("Login Successful")
}

// LoginFailed 登录失败观察者
type LoginFailed struct{}

var loginFailedInstance *LoginFailed
var loginFailedOnce sync.Once

// GetLoginFailedObserver 获取登录失败观察者实例
func GetLoginFailedObserver() *LoginFailed {
	loginFailedOnce.Do(func() {
		loginFailedInstance = &LoginFailed{}
	})
	return loginFailedInstance
}

// Update 更新
func (lf *LoginFailed) Update(subject ISubject) {
	fmt.Println("Login Failed")
}

// RegisterSuccessful 注册成功观察者
type RegisterSuccessful struct{}

var registerSuccessfulInstance *RegisterSuccessful
var registerSuccessfulOnce sync.Once

// GetRegisterSuccessfulObserver 获取注册成功观察者实例
func GetRegisterSuccessfulObserver() *RegisterSuccessful {
	registerSuccessfulOnce.Do(func() {
		registerSuccessfulInstance = &RegisterSuccessful{}
	})
	return registerSuccessfulInstance
}

// Update 更新
func (rs *RegisterSuccessful) Update(subject ISubject) {
	fmt.Println("Register-Account Successful")
}

// RegisterFailed 注册失败观察者
type RegisterFailed struct{}

var registerFailedInstance *RegisterFailed
var registerFailedOnce sync.Once

// GetRegisterFailedObserver 获取注册失败观察者实例
func GetRegisterFailedObserver() *RegisterFailed {
	registerFailedOnce.Do(func() {
		registerFailedInstance = &RegisterFailed{}
	})
	return registerFailedInstance
}

// Update 更新
func (rf *RegisterFailed) Update(subject ISubject) {
	fmt.Println("Register-Account Failed")
}
