#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
//TreeNode* head=root;

if(root==NULL) return root;
if(key<root->val_) root->left_=deleteNode(root->left_,key);
else if(key>root->val_) root->right_=deleteNode(root->right_,key);

else{
if(root->left_==NULL && root->right_==NULL ){
  delete root;
  root=NULL;
}
else if(root->left_==NULL){
  TreeNode* temp=root->right_;
  delete root;
  root=temp;

}
else if(root->right_==NULL){
TreeNode* temp=root->left_;
  delete root;
  root=temp;
}
else{
  TreeNode*& IOP=root->left_;
while(IOP->right_!=NULL) IOP=IOP->right_;
int temp=root->val_;
root->val_=IOP->val_;
IOP->val_=temp;
root->left_=deleteNode(root->left_,key);
}


}
  return root;
}



void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";

    inorderPrint(node->right_);
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
