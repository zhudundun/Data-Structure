#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel;
  pixel.s=0.8;
  pixel.h=360-360.0*y/400;
  pixel.l=0.2;
  pixel.a=1;
  return pixel;
  // return HSLAPixel();
  // return HSLAPixel(170,0.8,0.2);
}
