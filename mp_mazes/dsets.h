/* Your code here! */
#pragma once


#include <vector>

using namespace std;

class DisjointSets{
public:
DisjointSets();
DisjointSets(int num);

//Creates n unconnected root nodes at the end of the vector.
void addelements (int num);

//This function should compress paths and works as described in lecture.
int find (int elem);

//This function should be implemented as union-by-size.
void setunion (int a, int b);

int size (int elem);

private:
  vector<int> elements;
};
