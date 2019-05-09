#pragma once

#include <cstddef>
#include<stack>
#include<iterator>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }

};

class TreeTraversal{
  public:


class Iterator:std::iterator<std::forward_iterator_tag,TreeNode*>{
private:
TreeNode* root_;
TreeNode* curr_;
TreeTraversal* tra_;
public:
Iterator():tra_(NULL){};
Iterator(TreeNode* root,TreeTraversal* traversal):root_(root),tra_(traversal){curr_=traversal->peek();}

Iterator& operator++()  {
  if(!tra_->empty()){
    curr_=tra_->pop();
    tra_->add(curr_);
    curr_=tra_->peek();
  } return *this;
};

bool operator!=(const Iterator& other){
  bool otherEmpty=false;
  bool thisEmpty=false;
  if (tra_==NULL || tra_->empty()) thisEmpty=true;
  if (other.tra_==NULL || other.tra_->empty()) otherEmpty=true;
  if(thisEmpty && otherEmpty) return false;
  else if(!thisEmpty && !otherEmpty) return (tra_!=other.tra_);
return true;
};

TreeNode* operator*(){return curr_;}

  };

  virtual TreeNode* pop()=0;
  virtual void add(TreeNode*& subroot)=0;
  virtual TreeNode* peek() const=0;
  virtual bool empty() const=0;
  virtual Iterator begin()=0;
  virtual Iterator end()=0;


};


// class inorder:TreeTraversal{
// public:
//   inorder(TreeNode* root){while(root) {
//     stack_.push(root);
//     root=root->left_;
//   }}
//   TreeNode* pop(){
//     TreeNode* temp=stack_.top();
//     stack_.pop();
//     return temp;
//   }
//   void add(TreeNode*& subroot){
//     TreeNode* temp=subroot->right_;
// while(temp){
//   stack_.push(temp);
//   temp=temp->left_;
// }
//   }
//   TreeNode* peek() const{
// return stack_.empty()? NULL:stack_.top();
//   }
//   bool empty() const{return stack_.empty();}
//   Iterator begin(){return Iterator(root_,this);}
//   Iterator end(){return Iterator();}
// private:
// stack<TreeNode*> stack_;
// TreeNode* root_;
//
// };

class inorder:TreeTraversal{
public:
  inorder(TreeNode* root){while(root) {
    stack_.push(root);
    root=root->right_;
  }}
  TreeNode* pop(){
    TreeNode* temp=stack_.top();
    stack_.pop();
    return temp;
  }
  void add(TreeNode*& subroot){
    TreeNode* temp=subroot->left_;
while(temp){
  stack_.push(temp);
  temp=temp->right_;
}
  }
  TreeNode* peek() const{
return stack_.empty()? NULL:stack_.top();
  }
  bool empty() const{return stack_.empty();}
  Iterator begin(){return Iterator(root_,this);}
  Iterator end(){return Iterator();}
private:
stack<TreeNode*> stack_;
TreeNode* root_;

};


class odd:TreeTraversal{
public:
  odd(TreeNode* root){while(root) {
    if(root->val_%2==1){
    stack_.push(root);

  }
root=root->right_;}}
  TreeNode* pop(){
    TreeNode* temp=stack_.top();
    stack_.pop();
    return temp;
  }
  void add(TreeNode*& subroot){
    TreeNode* temp=subroot->left_;
while(temp){
  if(temp->val_%2==1){
  stack_.push(temp);

}
temp=temp->right_;}
  }
  TreeNode* peek() const{
return stack_.empty()? NULL:stack_.top();
  }
  bool empty() const{return stack_.empty();}
  Iterator begin(){return Iterator(root_,this);}
  Iterator end(){return Iterator();}
private:
stack<TreeNode*> stack_;
TreeNode* root_;

};
// class preorder:TreeTraversal{
// public:
//   preorder(TreeNode* root){stack_.push(root);}
//   TreeNode* pop(){
//     TreeNode* temp=stack_.top();
//     stack_.pop();
//     return temp;
//   }
//   void add(TreeNode*& subroot){
//
//     if(subroot->right_!=NULL)  stack_.push(subroot->right_);
//     if(subroot->left_!=NULL) stack_.push(subroot->left_);
//
//   }
//   TreeNode* peek() const{
//   return stack_.empty()? NULL:stack_.top();
//   }
//   bool empty() const{
//     return stack_.empty();
//   }
//   Iterator begin(){
//     return Iterator(root_,this);
//   }
//   Iterator end() {return Iterator();}
// private:
// stack<TreeNode*> stack_;
// TreeNode* root_;
// };


class preorder:TreeTraversal{
public:
  preorder(TreeNode* root){stack_.push(root);}
  TreeNode* pop(){
    TreeNode* temp=stack_.top();
    stack_.pop();
    return temp;
  }
  void add(TreeNode*& subroot){


    if(subroot->left_!=NULL) stack_.push(subroot->left_);
if(subroot->right_!=NULL)  stack_.push(subroot->right_);
  }
  TreeNode* peek() const{
  return stack_.empty()? NULL:stack_.top();
  }
  bool empty() const{
    return stack_.empty();
  }
  Iterator begin(){
    return Iterator(root_,this);
  }
  Iterator end() {return Iterator();}
private:
stack<TreeNode*> stack_;
TreeNode* root_;
};

TreeNode * deleteNode(TreeNode* root, int key);

void inorderPrint(TreeNode* node);

void deleteTree(TreeNode* root);
