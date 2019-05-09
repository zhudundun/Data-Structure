#include "Stack.h"

// `int size()` - returns the number of elements in the stack (0 if empty)
// Stack::Stack(){
//   head=NULL;
//
// }
// Stack::~Stack(){
//   node* temp;
//   while(head!=NULL){
// temp=head;
//     head=head->next;
//     delete temp;
//
//   }
// }
// int Stack::size() const {
//   if(head==NULL) return 0;
//   node* temp=head;
//   int count=0;
// while(temp!=NULL){
//  temp=temp->next;
// count ++;
// }
//  return count;
// }
//
// // `bool isEmpty()` - returns if the list has no elements, else false
// bool Stack::isEmpty() const {
//   return ((head==NULL )? true: false);
// }
//
// // `void push(int val)` - pushes an item to the stack in O(1) time
// void Stack::push(int value) {
//   node* temp=new node;
//   temp->val=value;
//   temp->next=head;
//   head=temp;
//
// }
//
// // `int pop()` - removes an item off the stack and returns the value in O(1) time
// int Stack::pop() {
//   if(head==NULL) return -1;
//   node* temp=head;
//   int result=temp->val;
//   head=head->next;
//   delete temp;
//   return result;
//
// }
Stack::Stack(){}

int Stack::size() const{
  return vec_.size();
}

bool Stack::isEmpty() const{
  return vec_.empty();
}

void Stack::push(int value){
  vec_.push_back(value);
}

int Stack::pop(){
  int back=vec_.back();
  vec_.pop_back();
  return back;
}
