#include "potd.h"
#include <iostream>
#include <string>

using namespace std;

string stringList(Node *head) {
    // your code here!
string output="Empty list";
if (head==NULL){

  return output;
}
else{
  output="";
  int count=0;
  while(head!=NULL){
    output=output+"Node "+to_string(count)+": "+to_string(head->data_);
    if(head->next_!=NULL){
      output=output+" -> ";
    }
    head=head->next_;
    count++;
  }
}

return output;
}
