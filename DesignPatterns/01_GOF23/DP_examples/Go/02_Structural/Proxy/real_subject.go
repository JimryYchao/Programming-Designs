package Proxy

import "fmt"

// RealImage 是真实的图像类，实现了 Image 接口
type RealImage struct {
	filename string
	image    []byte
}

// NewRealImage 创建一个新的 RealImage 实例
func NewRealImage(filename string) *RealImage {
	return &RealImage{
		filename: filename,
		image:    nil,
	}
}

// Operation 执行图像处理操作
func (r *RealImage) Operation() {
	fmt.Printf("Do a operation with image:[%s]\n", r.filename)
}

// LoadFromDisk 从磁盘加载图像
func (r *RealImage) LoadFromDisk() {
	fmt.Printf("load a Image from %s\n", r.filename)
	// 实际情况下，这里会从文件读取字节数据
	// r.image = ioutil.ReadFile(r.filename)
}
