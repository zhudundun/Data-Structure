#include <iostream>
#include "OfficeHour.h"

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/

int answerTime(queue<Student> queue, vector<Staffer> onDutyStaff){
  Student studentI=queue.front();
  Staffer stafferI=onDutyStaff.front();
  int answerT=answerQuestion(studentI.qType, studentI.anticipatedTime);
  queue.pop();
  onDutyStaff.erase(onDutyStaff.begin());
}




int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
int wait=0;
//int pass=0;
int countStaffer=0;

if(onDutyStaff.empty() || queue.empty()) return wait;
vector<int> answerT;
vector<Staffer> record;

for(int i=1;i<nthStudent;i++){
  while(!onDutyStaff.empty()) {
    record.push(onDutyStaff.front());

  answerT[i]=answerTime(queue, onDutyStaff);
  //pass=pass+answerT[i];
  countStaffer++;
  continue;
}
wait=wait+min(answerT);
//currw=min(answerT);
for(int i=1;i<=countStaffer;i++){
if(w>answerT[i]) {
  Staffer T=record.begin()+i;
  record.erase(record.begin()+i);
  onDutyStaff.push_back(T);

}
}
}
    return -1;
}
