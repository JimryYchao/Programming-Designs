package singleton

import (
	"fmt"
	"sync"
)

// 非线程安全单例
type Singleton struct {
	Value int
}

var instance *Singleton

func GetSingleton() *Singleton {
	if instance == nil {
		instance = &Singleton{Value: 0}
	}
	return instance
}

// 线程安全单例
type SingletonLock struct {
	Value int
}

var (
	lockInstance *SingletonLock
	lock         sync.Mutex
)

func GetSingletonLock() *SingletonLock {
	if lockInstance == nil {
		lock.Lock()
		defer lock.Unlock()
		if lockInstance == nil {
			lockInstance = &SingletonLock{Value: 0}
		}
	}
	return lockInstance
}

// 使用 sync.Once 实现线程安全单例
type SingletonOnce struct {
	Value int
}

var (
	onceInstance *SingletonOnce
	once         sync.Once
)

func GetSingletonOnce() *SingletonOnce {
	once.Do(func() {
		onceInstance = &SingletonOnce{Value: 0}
	})
	return onceInstance
}

// 内联单例
type SingletonInline struct {
	Value int
}

var inlineInstance = &SingletonInline{Value: 0}

func GetSingletonInline() *SingletonInline {
	return inlineInstance
}

// 继承式单例
type SingletonInherit interface {
	Log()
}

type MonoSingleton struct {
	Value int
}

var monoInstance *MonoSingleton

func GetMonoSingleton() *MonoSingleton {
	if monoInstance == nil {
		monoInstance = &MonoSingleton{Value: 0}
	}
	return monoInstance
}

func (m *MonoSingleton) Log() {
	fmt.Println("MonoSingleton is created")
}

type GameSingleton struct {
	Value int
}

var gameInstance *GameSingleton

func GetGameSingleton() *GameSingleton {
	if gameInstance == nil {
		gameInstance = &GameSingleton{Value: 0}
	}
	return gameInstance
}

func (g *GameSingleton) Log() {
	fmt.Println("GameSingleton is created")
}