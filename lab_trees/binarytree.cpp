/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

using namespace std;

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout<<std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here

mirror(root);

}

template <typename T>
void BinaryTree<T>::mirror(Node* root) const{
  if (root==NULL) return;
  Node* temp;
  mirror(root->left);
  mirror(root->right);
  temp=root->left;
  root->left=root->right;
  root->right=temp;

}


/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    std::stack<T> s;
    int large_value;
    InorderTraversal<int> iot(this->getRoot());
    for(TreeTraversal<int>::Iterator it=iot.begin();it!=iot.end();++it){
      s.push((*it)->elem);
    }
    if(!s.empty()){
      large_value=s.top();
      s.pop();
    }
    while(!s.empty()){
      if(large_value<s.top()){
        return false;
      }
      large_value=s.top();
      s.pop();
    }
return true;

}

template <typename T>
bool BinaryTree<T>::isOrderedIterative(Node* root) const
{
    // your code here
    bool orderl=true;
    bool orderr=true;
    if (root==NULL) return true;
    while(root->left!=NULL){
    if(root->left<root) orderl=true;
    else {
      orderl=false;
      break;
    }
      root=root->left;
  }
  while(root->right!=NULL){
    if(root->right>root) orderr=true;
    else {
      orderr=false;
      break;
    }
    root=root->right;
  }

    if(orderl==true && orderr==true) return true;
    else return false;


}



/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return isOrderedRecursive(root);

}

template <typename T>
bool BinaryTree<T>::isOrderedRecursive(Node* root) const
{
    // your code here
    if(root==NULL) return true;// your code here
    if(root->left==NULL && root->right==NULL) return true;// your code here
    bool result=isOrderedRecursive(root->left) && isOrderedRecursive(root->right);
    // std::cout << "roooot: " << root->elem << std::endl;
    // std::cout << "Cur bool: " << result << std::endl;
    if (result==false) return result;
    if(root->left==NULL){
    if(root->elem<Min(root->right)) return true;
    else return false;
  }
  if(root->right==NULL){

    // std::cout << "roooot: " << root->elem << std::endl;
    // std::cout << "Max: " << Max(root->left) << std::endl;
  if(root->elem>Max(root->left)) return true;
  else return false;
}

// std::cout << "roooot 3: " << root->elem << std::endl;
//   std::cout << "Min: " << Min(root->right) << std::endl;
  if(root->elem>Max(root->left)&&root->elem<Min(root->right)) return true;
  else return false;

}

template <typename T>
int BinaryTree<T>::Max(Node* root) const{
  InorderTraversal<int> tree(root);
  int max=0;
  for(TreeTraversal<int>::Iterator it=tree.begin();it!=tree.end();++it){
    if((*it)->elem>max) max=(*it)->elem;
  }
return max;


}

template <typename T>
int BinaryTree<T>::Min(Node* root) const{
  InorderTraversal<int> tree(root);
  int min=root->elem;
  for(TreeTraversal<int>::Iterator it=tree.begin();it!=tree.end();++it){
    if((*it)->elem<min) min=(*it)->elem;
  }
return min;


}

/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here
     T array[1000];
     int index=0;
    Node* root=this->getRoot();
getPaths( paths,array, index,root);
}

template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths,  T array[], int index,Node* root) const
{
    // your code here
if(root==NULL) return;
else{
array[index]=root->elem;
index++;}
if(root->left==NULL && root->right==NULL){
  std::vector<T> store;

  for( int i=0;i<index;i++) {
    store.push_back(array[i]);
    }

  paths.push_back(store);

}
else{
  getPaths( paths, array,index,root->left);
  getPaths( paths, array,index,root->right);

}
index--;
}





/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    return -1;
}
