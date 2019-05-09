#include "TreeNode.h"
#include <stdlib.h>
#include<vector>

using namespace std;

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

vector<TreeNode*> findAllUnbalanced(TreeNode* root, vector<TreeNode*> allUnbalance) {
  // your code here


  if(root==NULL) return allUnbalance;
   if( isHeightBalanced(root)==false) {

  allUnbalance.push_back(root);
 }
allUnbalance=findAllUnbalanced(root->left_, allUnbalance);
allUnbalance=findAllUnbalanced(root->right_, allUnbalance);
return allUnbalance;
}



TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  vector<TreeNode*> all;
  all=findAllUnbalanced(root,all);
  TreeNode* temp=NULL;

  if(all.empty()) return temp;

TreeNode* min=all.back();
all.pop_back();

   while( !all.empty()) {
temp=all.back();
all.pop_back();
if(heightOfTree(temp)<heightOfTree(min)) min=temp;

 }
return min;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
