#pragma once

#include <string>
#include"Base.h"

using namespace std;

class Derived:public Base{
public:
  string foo();
  virtual string bar();
  virtual ~Derived();

};
