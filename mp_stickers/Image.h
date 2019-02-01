/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include "cs225/PNG.h"


namespace cs225{
class Image: public PNG{
public:
  void lighten();
  void lighten(double amount);
  void darken();
  void darken(double amount);
  void rotateColor(double degrees);
  void saturate();
  void saturate(double amount);
  void desaturate();
  void desaturate(double amount);
  void greyscale();
  void illinify();
  void scale(double factor);
  void scale(unsigned w, unsigned h);

private:


};
}
