#include "Node.h"
#include <iostream>


using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here

  Node* temp1;
  Node* temp2;
  Node* temp3;
  Node* head=NULL;


  int value;
  temp1=first;
  //Node* newNode=new Node;
  temp2=second;
  temp3=head;

  while(temp1!=NULL){
      temp3=head;
      temp2=second;
      value=temp1->data_;

      while(temp3!=NULL){
        if (temp3->data_==value) break;
        temp3=temp3->next_;
      }

      if (temp3!=NULL) temp2=NULL;
      while(temp2!=NULL){

        if(temp2->data_==value) {

          if(head==NULL){
            Node* newNode=new Node;
            head=newNode;
            head->data_=value;
            break;
        }

        temp3=head;
        while(temp3->next_!=NULL)  temp3=temp3->next_;

        Node* newNode=new Node;
        newNode->data_=value;
        temp3->next_=newNode;        //result=result->next_;
        //std::cout<<value<<std::endl;
        break;

      }
      temp2=temp2->next_;

    }
    temp1=temp1->next_;

  }
  return head;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
