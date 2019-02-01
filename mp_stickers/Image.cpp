#include "Image.h"
#include "cs225/PNG.h"
#include <math.h>

using cs225::Image;

  void Image::lighten(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.l=pixel.l+0.1;
        if (pixel.l>1){
          pixel.l=1;
        }
      }
    }

  }
  void Image::lighten(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.l=pixel.l+amount;
        if (pixel.l>1){
          pixel.l=1;
        }
    }
  }
}
  void Image::darken(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.l=pixel.l-0.1;
        if (pixel.l<0){
          pixel.l=0;
        }
    }
  }
}
  void Image::darken(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.l=pixel.l-amount;
        if (pixel.l<0){
          pixel.l=0;
        }
    }
  }
}
  void Image::rotateColor(double degrees){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.h=pixel.h+degrees;
        if (pixel.h<0){
          pixel.h=pixel.h+360;
        }
        pixel.h=fmod(pixel.h,360);
    }
  }
}
  void Image::saturate(){
  for (unsigned int x=0;x<width();x++){
    for(unsigned int y=0;y<height();y++){
      HSLAPixel& pixel=this->getPixel(x,y);
      pixel.s=pixel.s+0.1;
      if (pixel.s>1){
        pixel.s=1;
      }
    }
  }
}
  void Image::saturate(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.s=pixel.s+amount;
        if (pixel.s>1){
          pixel.s=1;
        }
      }
    }
  }
  void Image::desaturate(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.s=pixel.s-0.1;
        if (pixel.s<0){
          pixel.s=0;
        }
      }
    }
  }
  void Image::desaturate(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.s=pixel.s-amount;
        if (pixel.s<0){
          pixel.s=0;
        }
      }
    }
  }
  void Image::greyscale(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        pixel.s=0;
      }
    }
  }
  void Image::illinify(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel& pixel=this->getPixel(x,y);
        if (pixel.h >= 114 && pixel.h <= 243){
          pixel.h = 216;
        }
        else {
          pixel.h = 11;
        }
      }
    }
  }
  void Image::scale(double factor){
    PNG* original= new PNG(*this);
    this->resize(width()*factor,height()*factor);
      for (unsigned x=0; x<width();x++){
        for (unsigned y=0;y<height();y++){
          HSLAPixel& newPixel= this->getPixel(x,y);
          HSLAPixel& oldPixel= original->getPixel(x/factor,y/factor);
          newPixel.h=oldPixel.h;
          newPixel.s=oldPixel.s;
          newPixel.l=oldPixel.l;
          newPixel.a=oldPixel.a;
          }
        }
      }


  void Image::scale(unsigned w, unsigned h){
    double widthRatio=w/width();
    double heightRatio=h/height();
    if (widthRatio<heightRatio){
      scale(widthRatio);
    }
    else{
      scale(heightRatio);
    }
  }
