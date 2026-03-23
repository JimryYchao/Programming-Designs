package Proxy

// ImageProxy 是图像代理类，实现了 Image 接口
type ImageProxy struct {
	Images []Image
}

// NewImageProxy 创建一个新的 ImageProxy 实例
func NewImageProxy() *ImageProxy {
	return &ImageProxy{
		Images: make([]Image, 0),
	}
}

// Operation 执行所有图像的操作
func (p *ImageProxy) Operation() {
	for _, image := range p.Images {
		image.Operation()
	}
}

// LoadFromDisk 加载所有图像
func (p *ImageProxy) LoadFromDisk() {
	for _, image := range p.Images {
		image.LoadFromDisk()
	}
}

// AddImage 添加单个图像
func (p *ImageProxy) AddImage(image Image) {
	p.Images = append(p.Images, image)
}

// AddImages 添加多个图像
func (p *ImageProxy) AddImages(images ...Image) {
	p.Images = append(p.Images, images...)
}

// Remove 移除图像
func (p *ImageProxy) Remove(image Image) bool {
	for i, img := range p.Images {
		if img == image {
			p.Images = append(p.Images[:i], p.Images[i+1:]...)
			return true
		}
	}
	return false
}
