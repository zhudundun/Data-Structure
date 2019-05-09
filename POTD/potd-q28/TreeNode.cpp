#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {

//TreeNode* node=this;
if(left_==NULL && right_==NULL) return 0;
else if(left_==NULL) return right_->getHeight()+1;
else if(right_==NULL) return left_->getHeight()+1;
  else{
    return (std::max(left_->getHeight(),right_->getHeight())+1);
  }
}
