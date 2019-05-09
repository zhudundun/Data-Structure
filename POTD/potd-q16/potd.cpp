#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {
  // your code here!
 Node* current;
  if(*head==NULL || insert->data_<(*head)->data_){
    insert->next_=*head;
    *head=insert;
  }
  else{
    current=*head;
  while( current->next_!=NULL && insert->data_>current->next_->data_){
    current=current->next_;
  }
  insert->next_=current->next_;
  current->next_=insert;
}
}
