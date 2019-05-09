#include "MinHeap.h"

vector<int> lastLevel(MinHeap & heap)
{
        // Your code here
        vector<int> leaf;
int size=heap.elements.size()-1;
int sum=0;
int i=0;
while(sum<size){
  if(sum+pow(2,i)>=size) break;
  sum+=pow(2,i);
  i++;
  //if (2*i>size-1) leaf.insert(leaf.begin(),heap.elements[i]);
}
//for (int k=sum+1;k<=size;k++) leaf.insert(leaf.begin(),heap.elements[k]);
for (int k=sum+1;k<=size;k++) leaf.push_back(heap.elements[k]);

//std::cout<<size<<std::endl;
        return leaf;
}
