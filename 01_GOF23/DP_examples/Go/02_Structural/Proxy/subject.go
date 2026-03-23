package Proxy

// Image 接口定义了图像处理的方法
type Image interface {
	Operation()
	LoadFromDisk()
}
