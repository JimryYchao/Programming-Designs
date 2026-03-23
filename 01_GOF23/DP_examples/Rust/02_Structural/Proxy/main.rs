mod component;
mod proxy;

use crate::component::{Image, RealImage};
use crate::proxy::ImageProxy;

// 测试 Proxy 模式
fn main() {
    // 创建实体对象
    let img1 = Box::new(RealImage::new("//path/image1"));
    let img2 = Box::new(RealImage::new("//path/image2"));
    let img3 = Box::new(RealImage::new("//path/image3"));
    let img4 = Box::new(RealImage::new("//path/image4"));
    let img5 = Box::new(RealImage::new("//path/image5"));
    
    // 创建代理对象
    let mut image_proxy = ImageProxy::new();
    image_proxy.add_images(vec![img1, img2, img3, img4, img5]);
    image_proxy.load_from_disk();
    image_proxy.operation();
}
