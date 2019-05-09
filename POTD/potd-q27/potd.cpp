#include "potd.h"
#include <iostream>
#include <string>

using namespace std;

string getFortune(const string &s){
  int  given=s.size();
  string a="A";
  string b="ab";
  string c="abc";
  string d="abcd";
  string e="abcde";
  int mod=given%5;
  if(mod==0) return a;
  if(mod==1) return b;
  if(mod==2) return c;
  if(mod==3) return d;
  return e;

}// Your code here
