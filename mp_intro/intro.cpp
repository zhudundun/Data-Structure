#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>


void rotate(std::string inputFile, std::string outputFile) {

    // Load in.png
  PNG* original= new PNG()
  original->readFromFile(inputFile);
  unsigned width = original->width();
  unsigned height = original->height();

  // Create out.png
  PNG* output=new PNG(width, height);
  // Go over the whole image, and if a pixel differs from that to its upper
  for (unsigned y = 1; y < height; y++) {
      for (unsigned x = 1;  x < width; x++) {
          // Calculate the pixel difference
          HSLAPixel* ori = &(original->getPixel(x,y));
  	      HSLAPixel* out = &(output->getPixel(width-x,height-y));
  	      *out = *ori;
      }
  }
  
  output->writeToFile(outputFile);

      delete output;
      delete original;
  // TODO: Part 2
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  return png;
}
