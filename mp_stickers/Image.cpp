#include "Image.h"
#include "PNG.h"

  Image::lighten(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.l=pixel.l+0.1;
        if (pixel.l>1){
          pixel.l=1;
        }
      }
    }

  }
  Image::lighten(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.l=pixel.l+amount;
        if (pixel.l>1){
          pixel.l=1;
        }
    }
  }
}
  Image::darken(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.l=pixel.l-0.1;
        if (pixel.l<0){
          pixel.l=0;
        }
    }
  }
}
  Image::darken(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.l=pixel.l-amount;
        if (pixel.l<0){
          pixel.l=0;
        }
    }
  }
}
  Image::rotateColor(double degrees){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.h=pixel.h+degrees;
        if (pixel.h<0){
          pixel.h=pixel.h+360;
        }
        pixel.h=fmod(pixel.h,360);
    }
  }
}
  Image::saturate(){
  for (unsigned int x=0;x<width();x++){
    for(unsigned int y=0;y<height();y++){
      HSLAPixel & pixel=??.getPixel(x,y);
      pixel.s=pixel.s+0.1;
      if (pixel.s>1){
        pixel.s=1;
      }
    }
  }
}
  Image::saturate(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.s=pixel.s+amount;
        if (pixel.s>1){
          pixel.s=1;
        }
      }
    }
  }
  Image::desaturate(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.s=pixel.s-0.1;
        if (pixel.s<0){
          pixel.s=0;
        }
      }
    }
  }
  Image::desaturate(double amount){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.s=pixel.s-amount;
        if (pixel.s<0){
          pixel.s=0;
        }
      }
    }
  }
  Image::greyscale(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        pixel.s=0;
      }
    }
  }
  Image::illinify(){
    for (unsigned int x=0;x<width();x++){
      for(unsigned int y=0;y<height();y++){
        HSLAPixel & pixel=??.getPixel(x,y);
        if (pixel.h >= 114 && pixel.h <= 243){
          pixel.h = 216;
        }
        else {
          pixel.h = 11;
        }
      }
    }
  }
  Image::scale(double factor){
    width_=width_*factor;
    height_=height_*factor;
  }
  Image::scale(unsigned w, unsigned h){
    width_=w;
    height_=h;
  }
