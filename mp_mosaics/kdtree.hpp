/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if(first[curDim]!=second[curDim]) return (first[curDim]<second[curDim]);

    return (first<second);
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
if(distance(target,potential)<distance(target, currentBest)) return true;
if(distance(target,potential)>distance(target, currentBest)) return false;
     return (potential<currentBest);

}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& Points, int start, int end, int pivotIndex, int dimension){
  Point<Dim> PivotValue=Points[pivotIndex];
int record=start;
swap(Points[pivotIndex],Points[end]);
for(int i=start; i<end;i++){
  if(smallerDimVal(Points[i],PivotValue,dimension)){
    swap(Points[record],Points[i]);
    record++;
  }
}
swap(Points[record],Points[end]);
return record;
}




template <int Dim>
void KDTree<Dim>::quickSelect(vector<Point<Dim>>& Points, int start, int end, int k, int dimension){
  if(start==end) return;
  int pivotIndex=(start+end)/2;
  pivotIndex=partition(Points, start,end,pivotIndex,dimension);
  if(k==pivotIndex) return;
  else if(k<pivotIndex) return quickSelect(Points, start, pivotIndex-1,k , dimension);
else  return quickSelect(Points, pivotIndex+1,end ,k , dimension);
return;
}


template <int Dim>
typename KDTree<Dim>::KDTreeNode*    KDTree<Dim>::createTree(vector<Point<Dim>>& Points, int start, int end, int dimension){
  if(end<start) return NULL;
  KDTreeNode* node=new KDTreeNode();
  int middle=(start+end)/2;
  quickSelect(start,end,middle,dimension%Dim);
  node->point=Points[middle];
  node->start=createTree(Points,start,middle-1,(dimension+1)%Dim);
  node->end=createTree(Points,middle+1,end,(dimension+1)%Dim);
return node;
}



template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     vector<Point<Dim>> Points(newPoints);
     size=Points.size();
     root=createTree(Points,0,Points.size()-1,0);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other):root(copy(other.root)) {
  /**
   * @todo Implement this function!
   */
size=other.size();
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copy(const KDTreeNode* subRoot){
if(subRoot==NULL) return NULL;
KDTreeNode* newNode=new KDTreeNode(subRoot->point);
newNode->left=copy(subRoot->left);
newNode->right=copy(subRoot->right);
return newNode;
}


template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
void KDTree<Dim>::clear(KDTreeNode* subRoot){
if(subRoot==NULL) return;
delete(subRoot);
clear(subRoot->left);
clear(subRoot->right);

}



template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   clear(root);
   root=NULL;
}



template <int Dim>
double KDTree<Dim>::getDistance(const Point<Dim>& query, const Point<Dim>& currBest)const{
  double distance=0;
  for(int i=0;i<Dim;i++){
    distance+=pow((query[i]-currBest[i]),2);
  }
  return distance;
}


template <int Dim>
bool KDTree<Dim>::possibleOtherSide(const Point<Dim>&query,const Point<Dim>&curr,int dimension,double distance){
  return (pow((query[dimension]-curr[dimension]),2)<=distance);
}


template <int Dim>
void KDTree<Dim>::findNearestNeighborHelper(const Point<Dim>& query, Point<Dim>& currBest,int start ,int end,int dimension ,double& distance,bool& first)const{
if(start>end) return;
if(start==end){
  if(first){
    currBest=points[start];
    distance=getDistance(query,currBest);
    first=false;
  }
  else{
    if(shouldReplace(query,currBest,points[start])){
      currBest=points[start];
      distance=getDistance(currBest,query);
    }
  }
  return;
}
int mid=(start+end)/2;
if(smallerDimVal(query,points[mid],dimension){
  findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
  if(shouldReplace(query,currBest,points[mid])){
    currBest=points[mid];
    distance=getDistance(currBest,query);
    first=false;
  }
  if(possibleOtherSide(query,points[mid],dimension,distance){
findNearestNeighborHelper(query, currBest,mid+1 ,end,(dimension+1)%Dim ,distance, first);
  }
}
else{
  findNearestNeighborHelper(query, currBest,mid+1,end,(dimension+1)%Dim ,distance, first);
  if(shouldReplace(query,currBest,points[mid])){
    currBest=points[mid];
    distance=getDistance(currBest,query);
    first=false;
  }
  if(possibleOtherSide(query,points[mid],dimension,distance){
    findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
  }
}

}




template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
Point<Dim> currentBest;
double distacne=0
bool firstSide=True;
findNearestNeighborHelper(query, currentBest,0,points.size()-1,0,distance,firstSide);
return currentBest;
}
