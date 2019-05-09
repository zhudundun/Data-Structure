
# pragma once
#include <string>
using namespace std;

class Animal{
public:
  string food_;
  Animal();
  Animal(string t,string f);
  string getType();
  void setType(string t);
  string getFood();
  void setFood(string f);
  virtual string print();
  virtual ~Animal();
private:
  string type_;

};


/* end of iagma once */



// Animal.h
