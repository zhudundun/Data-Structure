#include "Node.h"
#include <list>
#include <iostream>


/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
    Node* temp;
    Node* prev;
    Node* insert=new Node;
    insert->data_=data;
    temp=first;
    while(temp!=NULL && temp->data_<data){
      prev=temp;
      temp=temp->next_;

    }
    if(temp->data_==data){
      return first;
    }
    if(temp==NULL){
      prev->next_=insert;
      return first;
    }
    insert->next_=temp;
    if(temp==first){

      first=insert;

    }
    else{
      prev->next_=insert;
    }


    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node* out = NULL;
    Node* prev;



      out=first;
      prev=first;
      first=first->next_;
      while (first != NULL && first->data_!=prev->data_) {
         insertSorted(out,first->data_);
         prev=first;

         first=first->next_;
        // your code here
        // hint: call insertSorted and update l1
    }
    prev=second;
    second=second->next_;

    while (second != NULL&& second->data_!=prev->data_ ) {



      insertSorted(out,second->data_);
      prev=second;
      second=second->next_;
    }
        // your code here



    return out;
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
