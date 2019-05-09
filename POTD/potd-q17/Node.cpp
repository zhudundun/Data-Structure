#include "Node.h"
#include <iostream>

void sortList(Node **head) {
  // your code here!

  /*
  Selection sort:
  Repeatedly moving the minimum node
  to the beginning
  */


  // Some variables you probably will need
  Node *minNode = NULL;
  Node *minPrev = NULL;

  if (*head == NULL)
    return;



  int minData = (*head)->data_;
  Node *tmp = *head;
  Node *prev = NULL;
  prev=tmp;
  tmp=tmp->next_;
  while ( tmp != NULL ) {

    if(prev->data_>tmp->data_){
      prev=tmp;
      tmp=tmp->next_;
    }
    else{
      tmp=tmp->next_;
    }
      // TODO: Find the minimum node
  }

  minNode=prev;
  tmp=*head;


  while(tmp!=NULL ){
    if(minNode==*head){
      minPrev=NULL;
      break;
    }

    else if(tmp->next_ && tmp->next_==minNode){
      minPrev=tmp;
      break;
    }
    else{
      tmp=tmp->next_;
    }
  }
  // std::cout<<"reach"<<minPrev->data_<<std::endl;
  // std::cout<<"reach"<<minNode->data_<<std::endl;
  // std::cout<<"reach"<<minData<<std::endl;

  if (minPrev != NULL && minNode != NULL) {
      // TODO: Move the minimum node to the beginning
      // and update head
      if(minNode->data_!=minData){
      minPrev->next_=minNode->next_;
      minNode->next_=*head;
      *head=minNode;
    //  std::cout<<"reach"<<minData<<std::endl;

    }

  }
  //std::cout<<(*head)->data_<<std::endl;
  //std::cout<<"reach"<<std::endl;

  // Recurse on the rest of the list
  //std::cout<<(*head)->data_<<std::endl;

  sortList(& (*head)->next_);
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
