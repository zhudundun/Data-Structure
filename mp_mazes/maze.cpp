/* Your code here! */
#include"maze.h"
#include <math.h>
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
  for(int i=10;i<pW;i++){
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

  pair<int,int> SquareMaze::func (int x, int y) const {
  	pair<int,int> ret(x,y);
  	int image_width2 = width*10+1;
  	int image_height2 = height*10+1;
  	int image_width = 2*image_width2;
  	int image_height = 1.5*image_height2;
  	float pi = 3.1415926;

  	float r = y+image_height2/3;
  	float degree = 4*image_width2/(2*pi*image_height2);
  	float degree_left = (pi-degree)/2;
  	float degree_y = degree_left + 4*x/(2*pi*image_height2);
  	ret.first = -r*cos(degree_y)+image_width/2;
  	ret.second = r*sin(degree_y);
  	return ret;
  }



  PNG* SquareMaze::drawMaze_creative(){

	int image_width2 = width*10+1;
	int image_height2 = height*10+1;
	int image_width = 2*image_width2;
	int image_height = 1.5*image_height2;
	float pi = 3.1415926;
  vector<vector<vector<bool>>> walls_(image_width);

  for (int i=0; i<image_width; i++) {
  		walls_[i] = vector<vector<bool>>(image_height);
  		for (int j=0; j<image_height; j++) {
  			walls_[i][j] = vector<bool>(2);
  			//have walls
  			//0 right 1 down
  			walls_[i][j][0] = true;
  			walls_[i][j][1] = true;
  }
}

	float r = image_height2/3;
	PNG* mazeImage = new PNG(image_width, image_height);

	HSLAPixel black(0, 0, 0);

	for (int i = 0; i<image_width; i++) {
		if ((i<1 || i>9) && i< image_height2) {
			HSLAPixel & pixel = mazeImage->getPixel(func(i,0).first, func(i,0).second);
			// pixel.s = black.s;
			// pixel.h = black.h;
			pixel.l = black.l;
		}
	}
	for (int i = 0; i<image_height; i++) {
		if (i< image_height2) {
			HSLAPixel & pixel = mazeImage->getPixel(func(0,i).first, func(0,i).second);
			// pixel.s = black.s;
			// pixel.h = black.h;
			pixel.l = black.l;
		}
	}
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			if (walls_[x][y][0]) {
				for (int k=0; k<=10; k++) {
					HSLAPixel & pixel = mazeImage->getPixel(func((x+1)*10,y*10+k).first, func((x+1)*10,y*10+k).second);
					// pixel.s = black.s;
					// pixel.h = black.h;
					pixel.l = black.l;
				}
			}
			if (walls_[x][y][1]) {
				for (int k=0; k<=10; k++) {
					HSLAPixel & pixel = mazeImage->getPixel(func(x*10+k,(y+1)*10).first, func(x*10+k,(y+1)*10).second);
					// pixel.s = black.s;
					// pixel.h = black.h;
					pixel.l = black.l;
				}
			}
		}
	}

	return mazeImage;


  }



  PNG * SquareMaze::drawMaze_creative_solution() {
  	PNG* mazeImage = drawMaze_creative();

  	HSLAPixel red(0,1,0.5,1);

  	vector<int> path = solveMaze();
  	int x = 5;
  	int y = 5;
  	int i;
  	for (int iter = 0; iter < (int)path.size(); iter++) {
  		if (path[iter]==0) {
  			for (i = 0; i <= 10; i++) {
  				HSLAPixel & pixel = mazeImage->getPixel(func(x+i,y).first, func(x+i,y).second);
  				pixel.s = red.s;
  				pixel.h = red.h;
  				pixel.l = red.l;
  			}
  			x += 10;
  		}
  		else if (path[iter]==1) {
  			for (i = 0; i <= 10; i++) {
  				HSLAPixel & pixel = mazeImage->getPixel(func(x,y+i).first, func(x,y+i).second);
  				pixel.s = red.s;
  				pixel.h = red.h;
  				pixel.l = red.l;
  			}
  			y += 10;
  		}
  		else if (path[iter]==2) {
  			for (i = 0; i <= 10; i++) {
  				HSLAPixel & pixel = mazeImage->getPixel(func(x-i,y).first, func(x-i,y).second);
  				pixel.s = red.s;
  				pixel.h = red.h;
  				pixel.l = red.l;
  			}
  			x -= 10;
  		}
  		else if (path[iter]==3) {
  			for (i = 0; i <= 10; i++) {
  				HSLAPixel & pixel = mazeImage->getPixel(func(x,y-i).first, func(x,y-i).second);
  				pixel.s = red.s;
  				pixel.h = red.h;
  				pixel.l = red.l;
  			}
  			y -= 10;
  		}
  	}
  	x -= 5;
  	y += 5;
  	for (i = 1; i < 10; i++) {
  		HSLAPixel & pixel = mazeImage->getPixel(func(x+i,y).first, func(x+i,y).second);
  		pixel.l = 1;
  	}
  	return mazeImage;
  }
