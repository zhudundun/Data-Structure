#include "Node.h"

using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
if(first==NULL && second!=NULL) return second;
if(first!=NULL && second==NULL) return first;
if(first==NULL && second==NULL) return NULL;

Node* iterFirst=first;
Node* iterSecond=second;
Node* iterThird=NULL;
Node* third=iterThird;
bool isFound=false;

while(iterFirst){
  iterSecond=second;
  iterThird=third;
  isFound=false;
  while(iterThird){
    if(iterThird->data_==iterFirst->data_){
      isFound=true;
      break;
    }
  iterThird=iterThird->next_;
  }
  if(isFound){
    iterFirst=iterFirst->next_;
    continue;
  }

while(iterSecond){
  if(iterSecond->data_==iterFirst->data_) break;
  iterSecond=iterSecond->next_;
}

if (iterSecond==NULL){
  iterThird=new Node();
  iterThird->data_=iterFirst->data_;
  iterThird->next_=third;
  third=iterThird;
}
iterFirst=iterFirst->next_;
}

 iterFirst=first;
 iterSecond=second;

 isFound=false;

while(iterSecond){
  iterFirst=first;
  iterThird=third;
  isFound=false;
  while(iterThird){
  if(iterThird->data_==iterSecond->data_){
    isFound=true;
    break;
  }
  iterThird=iterThird->next_;
}
if(isFound){
  iterSecond=iterSecond->next_;
  continue;
}

while(iterFirst){
  if(iterFirst->data_==iterSecond->data_) break;


  iterFirst=iterFirst->next_;
}
if (iterFirst==NULL){
  iterThird=new Node();
  iterThird->data_=iterSecond->data_;
  iterThird->next_=third;
  third=iterThird;
}

iterSecond=iterSecond->next_;
}


  return third;
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
