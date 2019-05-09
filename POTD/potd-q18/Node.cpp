#include "Node.h"
#include<iostream>

void mergeList(Node *first, Node *second) {
  // your code here!
  Node* tmp1=NULL;
  Node* tmp2=NULL;
  if (first==NULL || second==NULL){
    return;
  }
  while(first->next_!=NULL && second!=NULL){
  tmp1=first->next_;
  tmp2=second->next_;

  first->next_=second;
  second->next_=tmp1;
  first=tmp1;
  second=tmp2;
}

  while(second!=NULL){
  first->next_=second;
  return;
}
std::cout<<"reach"<<std::endl;
}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
