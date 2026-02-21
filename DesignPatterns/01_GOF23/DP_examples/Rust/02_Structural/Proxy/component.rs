// Image trait 定义了图像处理的方法
pub trait Image {
    fn operation(&self);
    fn load_from_disk(&self);
}

// RealImage 是真实的图像类，实现了 Image trait
pub struct RealImage {
    filename: String,
    image_data: Option<Vec<u8>>,
}

impl RealImage {
    pub fn new(filename: &str) -> Self {
        Self {
            filename: filename.to_string(),
            image_data: None,
        }
    }
}

impl Image for RealImage {
    fn operation(&self) {
        println!("Do a operation with image:[{}]", self.filename);
    }
    
    fn load_from_disk(&self) {
        println!("load a Image from {}", self.filename);
        // 实际情况下，这里会从文件读取字节数据
        // self.image_data = Some(std::fs::read(&self.filename).unwrap());
    }
}
