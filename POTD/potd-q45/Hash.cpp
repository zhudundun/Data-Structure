#include <vector>
#include "Hash.h"







void doubleHashInput(std::vector<int> &v, int elem){
	//your code here
  int length=v.size();
  int idx=firstHash(elem,length);
  int stepsize=secondHash(elem);
  if(v[idx]==-1) {v[idx] = elem;
    return;}
  while(v[idx]!=-1){
idx=(idx+stepsize)%length;
  }
  //remove this
  v[idx] = elem;
}

//make a hash function called firstHash
//make a second function called secondHash
int firstHash(int elem, int length){
  int idx=(4*elem) %length;
  return idx;
}

int secondHash(int elem){
  int idx=3-elem %3;
  return idx;
}
