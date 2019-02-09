#include "Image.h"
#include "StickerSheet.h"

using namespace cs225;


int main() {
Image picture;
Image sticker1;
Image sticker2;
Image sticker3;
picture.readFromFile("alma.png");
sticker1.readFromFile("i.png");
sticker2.readFromFile("i.png");
sticker3.readFromFile("i.png");
StickerSheet stickerSheet(picture, 5);
stickerSheet.addSticker(sticker1,20,50);
stickerSheet.addSticker(sticker2,600,50);
stickerSheet.addSticker(sticker3,300,150);
Image output=stickerSheet.render();


output.writeToFile("myImage.png");

return 0;

}






  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
