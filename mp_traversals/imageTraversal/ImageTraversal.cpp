#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  tra_=NULL;
  atEnd=false;
}

ImageTraversal::Iterator::Iterator(PNG png,Point startPoint,double tolerance,ImageTraversal* tra) {
  /** @todo [Part 1] */
png_=png;
curr_=startPoint;
start_=curr_;
tolerance_=tolerance;
tra_=tra;
for(unsigned i=0;i<png_.width()*png_.height();i++){
  visited_.push_back(false);
}
atEnd=false;

  if(canVisit(curr_)){
    visited_[curr_.x+curr_.y*png_.width()]=true;
    //path_.push_back(start_);

  }
  else{
    atEnd=true;
  }
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  Point p1=Point(curr_.x+1,curr_.y);
  Point p2=Point(curr_.x,curr_.y+1);
  Point p3=Point(curr_.x-1,curr_.y);
  Point p4=Point(curr_.x,curr_.y-1);

  if(canVisit(p1)) tra_->add(p1);
  if(canVisit(p2)) tra_->add(p2);
  if(canVisit(p3)) tra_->add(p3);
  if(canVisit(p4)) tra_->add(p4);

if(tra_->empty()){
  setEnd(true);
  return *this;
}
Point next=tra_->pop();
while(visited_[next.x+next.y*png_.width()]){
  if(tra_->empty()){
    setEnd(true);
    return *this;
  }
  next=tra_->pop();
}
curr_=next;
visited_[curr_.x+curr_.y*png_.width()]=true;
//path_.push_back(start_);
return *this;

}

void ImageTraversal::Iterator::setEnd(bool end){
  atEnd=end;
}

bool ImageTraversal::Iterator::canVisit(Point point){
  if(point.x>=png_.width() || point.y>=png_.height()) return false;
  HSLAPixel start=png_.getPixel(start_.x,start_.y);
  HSLAPixel desired=png_.getPixel(point.x,point.y);
  if(calculateDelta(start,desired)>=tolerance_) return false;
  return true;
}
/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return curr_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return (atEnd!=other.atEnd);
}
