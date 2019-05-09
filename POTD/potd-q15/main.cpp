#include "potd.h"
#include <iostream>

using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  head = new Node;
  head->data_=100;
  head->next_=NULL;

  cout << stringList(head) << endl;


  // Test 3: A list with more than one node
  Node * first = new Node;
  Node * second = new Node;

  head->next_=first;
  first->data_=200;
  first->next_=second;
  second->data_=300;
  second->next_=NULL;





  cout << stringList(head) << endl;


  return 0;
}
