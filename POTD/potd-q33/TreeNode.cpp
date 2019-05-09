#include "TreeNode.h"
#include <algorithm>






void rightRotate(TreeNode* root) {

    // Your code here
    if(root==NULL) return;
    TreeNode* leftNode=root->left_;
    root->left_=leftNode->right_;
    if(leftNode->right_!=NULL)  leftNode->right_->parent_=root;
    TreeNode* above;
    if(root->parent_!=NULL) above=root->parent_;
    else above=NULL;
    //TreeNode* temp=leftNode;

     leftNode->parent_=above;
      if(above!=NULL){

        above->left_=leftNode;}
        leftNode->right_=root;
        root->parent_=leftNode;







}


void leftRotate(TreeNode* root) {

    // your code here

    if(root==NULL) return;

    TreeNode* rightNode=root->right_;
    root->right_=rightNode->left_;
    if(rightNode->left_!=NULL)  rightNode->left_->parent_=root;

    TreeNode* above;
    if(root->parent_!=NULL) above=root->parent_;
    else above=NULL;
    //TreeNode* temp=leftNode;

    rightNode->parent_=above;
    if(above!=NULL){

     above->right_=rightNode;
   }
   rightNode->left_=root;
   root->parent_=rightNode;

}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
