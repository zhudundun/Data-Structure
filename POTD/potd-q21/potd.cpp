#include "potd.h"
#include <iostream>
#include <vector>


// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end){
  double sum=0;
  for (vector<double>::iterator i=start;i<end;++i){
    sum+=*i;

  }
  return sum;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
   vector<double>::iterator max;
   max=start;
  for (vector<double>::iterator i=start;i<end;++i){
    if (*max<*i) max=i;

  }
  return max;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator max;
  double temp;
  vector<double> sort (start,end);
  for (vector<double>::iterator i=start;i<end;++i){
    max=max_iter(i,end);
    temp=*max;
    sort.erase(max);
    sort.insert(i,temp);
    //std::cout<<*start<<std::endl;


  }
}
