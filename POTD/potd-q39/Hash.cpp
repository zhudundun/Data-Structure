#include <vector>
#include <string>
#include "Hash.h"
#include<iostream>

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
int sum=0;
   for(unsigned i=0;i<s.size();i++){
     sum=sum+s[i];
   }
   return sum%M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  vector<int> num (inputs.size(),0);
  vector<int> col (M,0);
  for(unsigned i=0;i<inputs.size();i++){
num[i]=hashFunction(inputs[i], M);
for(unsigned j=0;j<i;j++){
  if(num[j]==num[i]){
    collisions++;
    break;
  }
}
  }
//   for(int i=0;i<M;i++){
//     for(unsigned j=0;j<inputs.size();j++){
//       if(num[j]==i) col[i]=col[i]+1;
// }}
 // for (int i=0;i<M;i++) {
 //   if (col[i]>1) col[i]=col[i]-1;
 //    else col[i]=0;}
 // for (unsigned k : col){collisions=collisions+k;}
  //for (unsigned k : col){std::cout<<k<<std::endl;}
	return collisions;
}
