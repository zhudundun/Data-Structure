/* Your code here! */
#pragma once

#include<vector>
#include<queue>
#include<time.h>
#include<cstdlib>
#include<iostream>
#include<map>
#include<algorithm>

#include"cs225/PNG.h"
#include"cs225/HSLAPixel.h"
#include "dsets.h"

using namespace std;
using namespace cs225;

class SquareMaze{
public:
SquareMaze();
void makeMaze(int width, int height);
bool canTravel(int x, int y, int dir) const;
void setWall(int x,int y,int dir, bool exists);
vector<int> solveMaze();
PNG* drawMaze()const;

PNG* drawMazeWithSolution();

private:
  vector<bool> downwalls;
  vector<bool> rightwalls;
  int height;
  int width;


};
