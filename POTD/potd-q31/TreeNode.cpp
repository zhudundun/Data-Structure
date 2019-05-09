#include "TreeNode.h"
#include <stdlib.h>


int heightOfTree(TreeNode* root){
  if (root==NULL) return 0;

  int lHeight=heightOfTree(root->left_);
  int rHeight=heightOfTree(root->right_);
  if(lHeight<=rHeight) return (rHeight+1);

return (lHeight+1);

}


bool isHeightBalanced(TreeNode* root) {
  // your code here
  if (root==NULL) return true;
  int diff=abs(heightOfTree(root->left_)-heightOfTree(root->right_));
  if(diff<=1) return true;
  return false;
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
