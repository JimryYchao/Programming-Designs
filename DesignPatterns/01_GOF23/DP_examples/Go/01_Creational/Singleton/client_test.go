package singleton

import (
	"fmt"
	"testing"
)

func TestSingleton(t *testing.T) {
	// 测试非线程安全单例
	s1 := GetSingleton()
	s2 := GetSingleton()
	if s1 != s2 {
		t.Error("Singleton instances should be the same")
	}

	// 测试线程安全单例
	sl1 := GetSingletonLock()
	sl2 := GetSingletonLock()
	if sl1 != sl2 {
		t.Error("SingletonLock instances should be the same")
	}

	// 测试 sync.Once 单例
	sonce1 := GetSingletonOnce()
	sonce2 := GetSingletonOnce()
	if sonce1 != sonce2 {
		t.Error("SingletonOnce instances should be the same")
	}

	// 测试内联单例
	si1 := GetSingletonInline()
	si2 := GetSingletonInline()
	if si1 != si2 {
		t.Error("SingletonInline instances should be the same")
	}

	// 测试继承式单例
	ms := GetMonoSingleton()
	gs := GetGameSingleton()
	fmt.Printf("MonoSingleton: %p\n", ms)
	fmt.Printf("GameSingleton: %p\n", gs)
	ms.Log()
	gs.Log()
}
