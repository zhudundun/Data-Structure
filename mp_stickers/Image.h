/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once

namespace cs225{
class Image: public PNG{
public:
  lighten();
  lighten(double amount);
  darken();
  darken(double amount);
  rotateColor(double degrees);
  saturate();
  saturate(double amount);
  desaturate();
  desaturate(double amount);
  greyscale();
  illinify();
  scale(double factor);
  scale(unsigned w, unsigned h);

private:


};
}
