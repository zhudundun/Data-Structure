/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"

namespace cs225{
  class stickerSheet{
  public:
 	stickerSheet (const Image &pic, unsigned max);
  ~stickerSheet ();
  stickerSheet (const stickerSheet &other);
  const stickerSheet & 	operator= (const stickerSheet &other);
  void 	changeMaxStickers (unsigned max);
  int 	addSticker (Image &sticker, unsigned x, unsigned y);
  bool 	translate (unsigned index, unsigned x, unsigned y);
  void 	removeSticker (unsigned index);
  Image * 	getSticker (unsigned index);
  Image 	render () const;
private:
  Image** stickers;
  Image* picture;
  unsigned sticker_ct;
  unsigned sticker_max;
  int* xPos;
  int* yPos;
  int* count;
  void _destroy();
  void _copy(const stickerSheet& other);

  };
}
