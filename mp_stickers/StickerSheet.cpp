#include "StickerSheet.h"

using namespace cs225;


StickerSheet::StickerSheet(const Image &pic, unsigned max){
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

void StickerSheet::_destroy(){
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

StickerSheet::~StickerSheet (){
  _destroy();


}

void StickerSheet::_copy(const StickerSheet& other){
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

StickerSheet::StickerSheet (const StickerSheet &other){
  _copy(other);
}

const StickerSheet& StickerSheet::operator= (const StickerSheet& other){
  if (this != &other)
  {
    _destroy();
    _copy(other);
  }
  return *this;
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y){
  if (sticker_ct<sticker_max){
    for(unsigned i=0;i<sticker_max;i++){
      if (count[i]==0){
        stickers[i]=new Image(sticker);
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

Image* 	StickerSheet::getSticker (unsigned index){
  if (index<=sticker_max && count[index]!=0){
  return stickers[index];
}
 return NULL;
}

void 	StickerSheet::removeSticker (unsigned index){
  if (index<=sticker_max && count[index]!=0){
  delete stickers[index];
  stickers[index]=NULL;
  xPos[index]=0;
  yPos[index]=0;
  count[index]=count[index]-1;
  sticker_ct=sticker_ct-1;
}
}

bool 	StickerSheet::translate (unsigned index, unsigned x, unsigned y){
  if (index<=sticker_max && count[index]!=0){
    xPos[index]=x;
    yPos[index]=y;
    return true;
}
   return false;
}

void 	StickerSheet::changeMaxStickers (unsigned max){
  if (max==sticker_max){
    return;
  }
  Image** newStickers=new Image* [max];
  int* newXpos= new int [max];
  int* newYpos=new int [max];
  int* newCount=new int[max];
  unsigned newSticker_ct=0;
  Image* newPicture= new Image(*picture);
  if (max<sticker_max)
{
  for (unsigned j=max; j<sticker_max;j++){
    if(count[j]!=0){
      delete stickers[j];
      stickers[j]=NULL;
      count[j]=count[j]-1;
    }
  }
}
  else{
    for(unsigned j=sticker_max;j<max;j++){
      newStickers[j]=NULL;
      newCount[j]=0;
    }
  }
  for(unsigned j=0;j<sticker_max;j++){
    if(count[j]!=0){
      newStickers[j]=new Image(*stickers[j]);
      newXpos[j]=xPos[j];
      newYpos[j]=yPos[j];
      newCount[j]=count[j];
      newSticker_ct=newSticker_ct+1;
    }
    else{
      newCount[j]=0;
    }
  }
  _destroy();
  sticker_ct=newSticker_ct;
  sticker_max=max;
  xPos=newXpos;
  yPos=newYpos;
  count=newCount;
  stickers=newStickers;
  picture=newPicture;

}

Image 	StickerSheet::render () const{
  unsigned xSheet=picture->width();
  unsigned ySheet=picture->height();
  for (unsigned i=0;i<sticker_max;i++ ){
    if (count[i]!=0){
    unsigned x=xPos[i]+stickers[i]->width();
    unsigned y=yPos[i]+stickers[i]->height();
    xSheet=(x>=xSheet) ? x:xSheet;
    ySheet=(y>=ySheet) ? y:ySheet;
    //if (xSheet< x) xSheet = x;
    //if (ySheet < y) ySheet = y;
  }
  }
  Image* result=new Image(*picture);
  result->resize(xSheet,ySheet);
for (unsigned i=0;i<sticker_max;i++){
  if(count[i]!=0){
  for(unsigned x=xPos[i];x<xPos[i]+stickers[i]->width();x++){
    for(unsigned y=yPos[i];y<yPos[i]+stickers[i]->height();y++){
    HSLAPixel& oldP=result->getPixel(x,y);
    HSLAPixel& newP=stickers[i]->getPixel(x-xPos[i],y-yPos[i]);
    if(newP.a!=0){
      oldP=newP;
    }
  }
  }
}
}
Image output=*result;
delete result;
result=NULL;
return output;
}
