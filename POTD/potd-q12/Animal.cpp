#include <string>
#include <iostream>

#include "Animal.h"

using namespace std;

Animal::Animal(){
  type_="cat";
  food_="fish";
}

Animal::Animal(string t,string f){
  type_=t;
  food_=f;
}

string Animal::getType(){
return type_;
}

string Animal::getFood(){
return food_;
}

void Animal::setType(string t){
  type_=t;
}

void Animal::setFood(string f){
  food_=f;
}

string Animal::print(){
  return "I am a "+type_+".";
}

Animal::~Animal(){

}


// Animal.cpp
