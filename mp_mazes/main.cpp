#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
  SquareMaze maze;
	maze.makeMaze(2,2);
	PNG * actualOutput = maze.drawMaze_creative();
	actualOutput->writeToFile("creative" + string(".png"));
	PNG * actualOutput_sol = maze.drawMaze_creative_solution();
	actualOutput_sol->writeToFile("creative_solution" + string(".png"));
  return 0;

}
