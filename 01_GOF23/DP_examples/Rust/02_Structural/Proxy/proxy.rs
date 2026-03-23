use crate::component::Image;

// ImageProxy 是图像代理类，实现了 Image trait
pub struct ImageProxy {
    images: Vec<Box<dyn Image>>,
}

impl ImageProxy {
    pub fn new() -> Self {
        Self {
            images: Vec::new(),
        }
    }
    
    pub fn add_image(&mut self, image: Box<dyn Image>) {
        self.images.push(image);
    }
    
    pub fn add_images(&mut self, images: Vec<Box<dyn Image>>) {
        self.images.extend(images);
    }
    
    pub fn remove(&mut self, index: usize) -> Option<Box<dyn Image>> {
        if index < self.images.len() {
            Some(self.images.remove(index))
        } else {
            None
        }
    }
}

impl Image for ImageProxy {
    fn operation(&self) {
        for image in &self.images {
            image.operation();
        }
    }
    
    fn load_from_disk(&self) {
        for image in &self.images {
            image.load_from_disk();
        }
    }
}
