#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
  TreeNode::RotationType decision=TreeNode::right;
  int balance=getHeight(subroot->right_)-getHeight(subroot->left_);
  if(balance==-2){
    int l_balance=getHeight(subroot->left_->right_)-getHeight(subroot->left_->left_);
    if(l_balance==-1) decision=TreeNode::right;
    else decision=TreeNode::leftRight;
  }
  else if (balance==2){
    int r_balance=getHeight(subroot->right_->right_)-getHeight(subroot->right_->left_);
    if(r_balance==1) decision=TreeNode::left;
    else decision=TreeNode::rightLeft;
  }
  //subroot->height=max(heightOrNeg1(subroot->left),heightOrNeg1(subroot->right))+1;
  return decision;
}

TreeNode* copyTree(const TreeNode* root){
  if(root==NULL) return NULL;
  TreeNode* ntree=new TreeNode(root->val_);
  ntree->left_=copyTree(root->left_);
  ntree->right_=copyTree(root->right_);
  return ntree;
}


// bool findTree(TreeNode*& root,int num){
//   if(root==NULL) return false;
//   if(root->val_==num) return true;
//   else if (root->val_>num) return findTree(root->left_,num);
//    return findTree(root->right_,num);
// }

TreeNode* findTree(TreeNode* root,int num){
  if(root==NULL) return root;
  if(root->val_==num) return root;
  else if (root->val_>num) return findTree(root->left_,num);
   return findTree(root->right_,num);
}
// TreeNode* mirror(const TreeNode* root){
//   if(root==NULL) return NULL;
//   TreeNode* ntree=new TreeNode(root->val_);
//   ntree->left_=copyTree(root->right_);
//   ntree->right_=copyTree(root->left_);
//   return ntree;
//
// }

void TreeNode::mirror2(TreeNode* root){
  if(root==NULL) return ;
  TreeNode* temp=root->left_;
  root->left_=root->right_;
  root->right_=temp;

  mirror2(root->right_);
  mirror2(root->left_);

}

TreeNode* insertTree(TreeNode*& root,int num){
if(root==NULL ) {root=new TreeNode(num);
  return root;}
if(num<root->val_) insertTree(root->left_,num);
else insertTree(root->right_,num);
return root;
}
