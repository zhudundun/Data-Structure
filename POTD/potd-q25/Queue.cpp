#include "Queue.h"
using namespace std;
// Queue::Queue() {
// head=NULL;
// tail=NULL;
// }
//
//
// Queue::~Queue() {
//   node* temp;
//   while(head!=NULL){
// temp=head;
//     head=head->next;
//     delete temp;
//
//   }
//   tail=NULL;
// }
// // `int size()` - returns the number of elements in the stack (0 if empty)
// int Queue::size() const{
//    if(head==NULL) return 0;
//    node* temp=head;
//    int count=0;
// while(temp!=NULL){
//   temp=temp->next;
//  count ++;
// }
//   return count;
// }
//
// // `bool isEmpty()` - returns if the list has no elements, else false
// bool Queue::isEmpty() const {
//   return ((head==NULL && tail==NULL)? true: false);
// }
//
// // `void enqueue(int val)` - enqueue an item to the queue in O(1) time
// void Queue::enqueue(int value) {
// if(head==NULL){
//   head=new node;
//   tail=head;
// }
// else{
//   tail->next=new node;
//   tail=tail->next;
// }
// tail->val=value;
// tail->next=NULL;
// }
//
// // `int dequeue()` - removes an item off the queue and returns the value in O(1) time
// int Queue::dequeue() {
//   if(head==NULL && tail==NULL) return -1;
//   node* temp=head;
//   head=head->next;
//   int result=temp->val;
//   delete temp;
//   if(head==NULL){
//     head=NULL;
//     tail=NULL;
//   }
//   return result;
// }



Queue::Queue(){

}

void Queue::enqueue(int t) {
    elem.push_back(t);
}

int Queue::dequeue() {

    while(!empty()) {
      int temp=*elem.begin();
      elem.erase(elem.begin());
      return temp;
    }
    return -1;
}

int Queue::peek() {
    if (!empty()) return elem.front();
    return -1;
}
