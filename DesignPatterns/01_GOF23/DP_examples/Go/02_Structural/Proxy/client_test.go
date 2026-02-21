package Proxy_test

import (
	. "Proxy"
	"testing"
)

// main 函数测试 Proxy 模式
func TestProxyDemo(t *testing.T) {
	// 创建实体对象
	img1 := NewRealImage("//path/image1")
	img2 := NewRealImage("//path/image2")
	img3 := NewRealImage("//path/image3")
	img4 := NewRealImage("//path/image4")
	img5 := NewRealImage("//path/image5")

	// 创建代理对象
	imageProxy := NewImageProxy()
	imageProxy.AddImages(img1, img2, img3, img4, img5)
	imageProxy.LoadFromDisk()
	imageProxy.Operation()
}
