#include <vector>
#include "BTreeNode.h"
#include<iostream>



void _traverse(BTreeNode* subroot,std::vector<int>& v) {
    // your code here
   if(subroot->is_leaf_){
     for(int i:subroot->elements_){
       v.push_back(i);
     }
     return;
   }

    for(unsigned i=0;i<subroot->children_.size();i++){
      _traverse(subroot->children_[i],v);
      if(i<subroot->elements_.size()){
        v.push_back(subroot->elements_[i]);
      }
    }


//std::cout<<n<<std::endl;

}

std::vector<int> traverse(BTreeNode* root){
  std::vector<int> v;
  _traverse(root,v);
  return v;
}
