#include "OfficeHour.h"
#include "Student.h"
#include <iostream>

#include <vector>

using namespace std;

int main() {
    Student Billy = Student(12, "POTD");
    Student Joel = Student(15, "MP");
    Student Jean = Student(8, "MP");
    Student Taylor = Student(6, "LAB");
    Student TimTim = Student(13, "POTD");

    queue<Student> officeHourQueue;
    officeHourQueue.push(Billy);
    officeHourQueue.push(Joel);
    officeHourQueue.push(Jean);
    officeHourQueue.push(Taylor);
    officeHourQueue.push(TimTim);

    Staffer Wade = Staffer("LAB", 2);
    Staffer Mattox = Staffer("MP", 0);
    vector<Staffer> onDutyStaff {Wade, Mattox};

    int expectedWaitTime = waitTime(officeHourQueue, onDutyStaff, 4);
// std::vector<int> a;
// a.push_back(1);
// a.push_back(2);
// int p=a[0];
// swap(a[0],a[1]);
// std::cout<<a[0]<<a[1]<<p<<std::endl;
    cout << "The expected wait time for Taylor, the fourth student in the queue, is " << to_string(expectedWaitTime) << " minutes." << endl;

    // add your own tests here!

    return 0;
};
