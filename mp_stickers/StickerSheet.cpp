#include "StickerSheet.h"

using namespace cs225;


stickerSheet::stickerSheet(const Image &pic, unsigned max){
xPos= new int[max];
yPos=new int[max];
count=new int[max];
sticker_ct=0;
sticker_max=max;
stickers= new Image*[max];
picture= new Image(pic);
for (unsigned i=0;i<max;i++){
  xPos[i]=0;
  yPos[i]=0;
  count[i]=0;
  stickers[i]=NULL;
}
}

void stickerSheet::_destroy(){
  for (unsigned i=0;i<sticker_max;i++){
    if (count[i]!=0){
      delete stickers[i];
    }

  }
  delete [] stickers;
  delete picture;
  delete [] xPos;
  delete [] yPos;
  delete [] count;

}

stickerSheet::~stickerSheet (){
  _destroy();
}

void stickerSheet::_copy(const stickerSheet& other){
  sticker_ct=other.sticker_ct;
  sticker_max=other.sticker_max;
  xPos= new int[sticker_max];
  yPos=new int[sticker_max];
  count=new int[sticker_max];
  stickers= new Image*[sticker_max];
  picture= new Image(*other.picture);
  for (unsigned i=0;i<sticker_max;i++){
    if (other.count[i]!=0){
    xPos[i]=other.xPos[i];
    yPos[i]=other.yPos[i];
    count[i]=other.count[i];
    stickers[i]=new Image(*other.stickers[i]);
  }
    else{
      xPos[i]=0;
      yPos[i]=0;
      count[i]=0;
      stickers[i]=NULL;
    }
  }
}

stickerSheet::stickerSheet (const stickerSheet &other){
  _copy(other);
}

const stickerSheet& stickerSheet::operator= (const stickerSheet& other){
  if (this != &other)
  {
    _destroy();
    _copy(other);
  }
  return *this;
}

int stickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
  if (sticker_ct<sticker_max){
    for(unsigned i=0;i<sticker_max;i++){
      if (count[i]==0){
        stickers[i]=&sticker;
        xPos[i]=x;
        yPos[i]=y;
        count[i]=count[i]+1;
        sticker_ct=sticker_ct+1;
        return i;
      }
    }
  }
  return -1;
}

Image* 	stickerSheet::getSticker (unsigned index){
  if (index<=sticker_max && count[index]!=0){
  return stickers[index];
}
 return NULL;
}

void 	stickerSheet::removeSticker (unsigned index){
  if (index<=sticker_max && count[index]!=0){
  delete stickers[index];
  stickers[index]=NULL;
  xPos[index]=0;
  yPos[index]=0;
  count=count-1;
  sticker_ct=sticker_ct-1;
}
}

bool 	stickerSheet::translate (unsigned index, unsigned x, unsigned y){
  if (index<=sticker_max && count[index]!=0){
    xPos[index]=x;
    yPos[index]=y;
    return true;
}
   return false;
}
