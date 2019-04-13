/* Your code here! */
#include"maze.h"

using namespace std;

SquareMaze::SquareMaze(){}


void SquareMaze::makeMaze(int width, int height){
  this->width=width;
  this->height=height;
  for(int i=0;i<width*height;i++){
    downwalls.push_back(true);
    rightwalls.push_back(true);
  }

  DisjointSets dsets;
  dsets.addelements(height*width);

  int bound=0;

  while(bound<width*height-1){
    int randx=rand()%width;
    int randy=rand()%height;
    bool randr=rand()%2;//0 false or 1 true to break right wall

    if(randr){
      if(randx<width-1 && rightwalls[randx+randy*width] && dsets.find(randx+randy*width)!=dsets.find(randx+randy*width+1)){
        rightwalls[randx+randy*width]=false;
        dsets.setunion(dsets.find(randx+randy*width),dsets.find(randx+randy*width+1));
        bound++;

      }
    }
    else{
      if(randy<height-1 && downwalls[randx+randy*width] && dsets.find(randx+randy*width)!=dsets.find(randx+(randy+1)*width)){
        downwalls[randx+randy*width]=false;
        dsets.setunion(dsets.find(randx+randy*width),dsets.find(randx+(randy+1)*width));
        bound++;
      }
    }

  }
}

bool SquareMaze::canTravel(int x, int y,int dir) const{
  if(dir==0) return !(rightwalls[x+y*width]);
  if(dir==1) return !(downwalls[x+y*width]);
  if(dir==2){
     if(x==0) return false;
     else return !(rightwalls[x+y*width-1]);
   }
   if(dir==3){
      if(y==0) return false;
      else return !(downwalls[x+(y-1)*width]);
    }
return false;
}

void SquareMaze::setWall(int x,int y,int dir, bool exists){
  if(dir==0) rightwalls[x+y*width]=exists;
  else if(dir==1) downwalls[x+y*width]=exists;
}

vector<int> SquareMaze::solveMaze(){
  vector<int> lastRows;
  map<int,int> steps;
  vector<bool> visited;
  for(int i=0;i<width*height;i++) visited.push_back(false);

  queue<int> q;
  q.push(0);
  visited[0]=true;
  while(!q.empty()){
    int v=q.front();
    q.pop();
    int x=v%width;
    int y=v/width;
    if(y==height-1) lastRows.push_back(v);
if(canTravel(x,y,0) && !visited[v+1]){
  steps.insert(pair<int,int>(v+1,v));
  visited[v+1]=true;
  q.push(v+1);
}
if(canTravel(x,y,1) && !visited[v+width]){
  steps.insert(pair<int,int>(v+width,v));
  visited[v+width]=true;
  q.push(v+width);
}

if(canTravel(x,y,2) && !visited[v-1]){
  steps.insert(pair<int,int>(v-1,v));
  visited[v-1]=true;
  q.push(v-1);
}
if(canTravel(x,y,3) && !visited[v-width]){
  steps.insert(pair<int,int>(v-width,v));
  visited[v-width]=true;
  q.push(v-width);
}

  }
  vector<int> dirs;
  int last=width-1;
  while(lastRows[last]==lastRows[last-1]) last-=1;
  int start=lastRows[last];
  while(start!=0){
    int former=steps[start];
    if(start==former+1) dirs.push_back(0);
    else if (start==former-1) dirs.push_back(2);
    else if (start==former+width) dirs.push_back(1);
    else if (start==former-width) dirs.push_back(3);
    start=former;
  }
  reverse(dirs.begin(),dirs.end());
  return dirs;
}

PNG* SquareMaze::drawMaze()const{
  int pH=height*10+1;
  int pW=width*10+1;
  PNG* unsolved=new PNG(pW,pH);
  for(int i=0;i<pH;i++){
    HSLAPixel& pixel=unsolved->getPixel(0,i);
    pixel.l=0.0;
  }
  for(int i=0;i<pW;i++){
    HSLAPixel& pixel=unsolved->getPixel(i,0);
    pixel.l=0.0;
  }
  for(int x=0;x<width;x++){
    for(int y=0;y<height;y++){
      if(rightwalls[x+y*width]){
        for(int i=0;i<11;i++){
          HSLAPixel& pixel=unsolved->getPixel(10*x+10,10*y+i);
          pixel.l=0.0;
        }
      }
      if(downwalls[x+y*width]){
        for(int i=0;i<11;i++){
          HSLAPixel& pixel=unsolved->getPixel(10*x+i,10*y+10);
          pixel.l=0.0;
        }
      }
    }
  }
return unsolved;
}

PNG* SquareMaze::drawMazeWithSolution(){
  PNG* unsolved=drawMaze();
  vector<int> dirs=solveMaze();
  int x=5;
  int y=5;
  for(unsigned i=0;i<dirs.size();i++){
    if(dirs[i]==0){
      for(int i=0;i<10;i++){
        HSLAPixel& pixel=unsolved->getPixel(x,y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        x+=1;
      }
    }
    else if(dirs[i]==1){
      for(int i=0;i<10;i++){
        HSLAPixel& pixel=unsolved->getPixel(x,y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
        y+=1;
      }
      }
      else if(dirs[i]==2){
        for(int i=0;i<10;i++){
          HSLAPixel& pixel=unsolved->getPixel(x,y);
          pixel.h=0;
          pixel.s=1;
          pixel.l=0.5;
          x-=1;
        }
        }
        else if(dirs[i]==3){
          for(int i=0;i<10;i++){
            HSLAPixel& pixel=unsolved->getPixel(x,y);
            pixel.h=0;
            pixel.s=1;
            pixel.l=0.5;
            y-=1;
          }
          }
    }
    HSLAPixel& p=unsolved->getPixel(x,y);
    p.h=0.0;
    p.s=1.0;
    p.l=0.5;
    p.a=1.0;
    x-=4;
    y+=5;
    for(int i=0;i<9;i++){
      HSLAPixel& pixel=unsolved->getPixel(x,y);
      pixel.l=1.0;
      pixel.a=1.0;
      x+=1;
    }
return unsolved;
  }
