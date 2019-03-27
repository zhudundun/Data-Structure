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
if(getDistance(target,potential)<getDistance(target, currentBest)) return true;
if(getDistance(target,potential)>getDistance(target, currentBest)) return false;
     return (potential<currentBest);

}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>> & Points, int start, int end, int pivotIndex, int dimension){
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
void KDTree<Dim>::quickSelect(vector<Point<Dim>> & Points, int start, int end, int k, int dimension){
  if(start>=end) return;
  int pivotIndex=(start+end)/2;
  pivotIndex=partition(Points, start,end,pivotIndex,dimension);
  if(k==pivotIndex) return;
  else if(k<pivotIndex) return quickSelect(Points, start, pivotIndex-1,k , dimension);
else  return quickSelect(Points, pivotIndex+1,end ,k , dimension);
return;
}


template <int Dim>
typename KDTree<Dim>::KDTreeNode *   KDTree<Dim>::build(vector<Point<Dim>>& Points,int start, int end, int dimension){
  if(end<start) return NULL;
  KDTreeNode * node = new KDTreeNode();

  int middle=(start+end)/2;
  quickSelect(Points,start,end,middle,dimension);
  node->point = Points[middle];
node->left =  build(Points,start,middle-1,(dimension+1)%Dim);
  node->right =build(Points,middle+1,end,(dimension+1)%Dim);
  return node;
}



template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     vector<Point<Dim>> points(newPoints);
     size=points.size();
     root=build(points,0,points.size()-1,0);
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
   if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
		size = rhs.size();
    }
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


// template <int Dim>
// bool KDTree<Dim>::possibleOtherSide(const Point<Dim>&query,const Point<Dim>&curr,int dimension,double distance){
//   return (pow((query[dimension]-curr[dimension]),2)<=distance);
// }
//

// template <int Dim>
// void KDTree<Dim>::findNearestNeighborHelper(const Point<Dim>& query, Point<Dim>& currBest,int start ,int end,int dimension ,double& distance,bool& first)const{
// if(start>end) return;
// if(start==end){
//   if(first){
//     currBest=Points[start];
//     distance=getDistance(query,currBest);
//     first=false;
//   }
//   else{
//     if(shouldReplace(query,currBest,Points[start])){
//       currBest=Points[start];
//       distance=getDistance(currBest,query);
//     }
//   }
//   return;
// }
// int mid=(start+end)/2;
// if(smallerDimVal(query,Points[mid],dimension)){
//   findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
//   if(shouldReplace(query,currBest,Points[mid])){
//     currBest=Points[mid];
//     distance=getDistance(currBest,query);
//     first=false;
//   }
//   if(possibleOtherSide(query,Points[mid],dimension,distance)){
// findNearestNeighborHelper(query, currBest,mid+1 ,end,(dimension+1)%Dim ,distance, first);
//   }
// }
// else{
//   findNearestNeighborHelper(query, currBest,mid+1,end,(dimension+1)%Dim ,distance, first);
//   if(shouldReplace(query,currBest,Points[mid])){
//     currBest=Points[mid];
//     distance=getDistance(currBest,query);
//     first=false;
//   }
//   if(possibleOtherSide(query,Points[mid],dimension,distance)){
//     findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
//   }
// }
//
// }




// template <int Dim>
// Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
// {
//     /**
//      * @todo Implement this function!
//      */
// Point<Dim> currentBest;
// double distacne=0;
// bool firstSide=true;
// findNearestNeighborHelper(query, currentBest,0,Points.size()-1,0,distance,firstSide);
// return currentBest;
// }

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::forwardtraversal(const Point<Dim>& query, KDTreeNode* subRoot,
																int d, int & bottom_d, double & Dist, stack<KDTreeNode*> & parents,
																stack<bool> & direction) const{
	if (query == subRoot->point)
	{
		parents.push(subRoot);
		direction.push(true);
		Dist = 0;
		bottom_d = d;
		return subRoot;
	}
	//go left
	if (smallerDimVal(query, subRoot->point, d)){
		//update the stacks
		parents.push(subRoot);
		direction.push(true);
		if (subRoot->left != NULL)
			return forwardtraversal(query, subRoot->left, (d+1)%Dim, bottom_d, Dist, parents, direction);
		else{
			Dist = getDistance(query, subRoot->point);     // The optimum distance
			bottom_d = d;              // The partition used in the leaf nodes
			return subRoot;
		}
	}
	//go right
	else{
		parents.push(subRoot);
		direction.push(false);
		if (subRoot->right != NULL)
			return forwardtraversal(query, subRoot->right, (d+1)%Dim, bottom_d, Dist, parents, direction);
		else{
			Dist = getDistance(query, subRoot->point);
			bottom_d = d;
			return subRoot;
		}
	}
	return subRoot;
}


template <int Dim>
bool KDTree<Dim>::hypersphere_check(const Point<Dim>& query, const Point<Dim>& target,
									int d, double & Dist) const{
	Point<Dim> boundary = query;
	boundary.set(d, target[d]);
	if (getDistance(query,boundary)<=Dist) return true;
	return false;
}

template <int Dim>
void KDTree<Dim>::backwardtraversal(const Point<Dim>& query, KDTreeNode* subRoot, KDTreeNode* & nearnode,
									int d, double & Dist, stack<KDTreeNode*> & parents, stack<bool> & direction) const{
	// current node near query point
	if (getDistance(query, subRoot->point)<Dist){
		Dist = getDistance(query, subRoot->point);
		nearnode = subRoot;
	}
	else if (getDistance(query, subRoot->point)==Dist){
		if (subRoot->point < nearnode->point)
			nearnode = subRoot;
	}
	// update the stacks
	bool direction_top = direction.top();
	parents.pop();
	direction.pop();
	// check the child
	if (hypersphere_check(query, subRoot->point, d, Dist)){
		if (direction_top==true && subRoot->right!=NULL){
			KDTreeNode* subnearnode = subRoot;//new KDTreeNode();
			double subDist = NearestNeighbor(query, subRoot->right, subnearnode, (d+1)%Dim);
			if ((subDist<Dist) || (subDist==Dist && subnearnode->point<nearnode->point)){
				nearnode = subnearnode;
				Dist = subDist;
			}
		}
		else if (direction_top==false && subRoot->left!=NULL){
			KDTreeNode* subnearnode = subRoot;//new KDTreeNode();
			double subDist = NearestNeighbor(query, subRoot->left, subnearnode, (d+1)%Dim);
			if ((subDist<Dist) || (subDist==Dist && subnearnode->point<nearnode->point)){
				nearnode = subnearnode;
				Dist = subDist;
			}
		}
	}
	// check the parent
	if (!parents.empty()){
		KDTreeNode* parent = parents.top();
		//if (hypersphere_check(query, parent->point, (d-1+Dim)%Dim, Dist))
			backwardtraversal(query, parent, nearnode, (d-1+Dim)%Dim, Dist, parents, direction);
	}
	return;
}

template <int Dim>
double KDTree<Dim>::NearestNeighbor(const Point<Dim>& query, KDTreeNode* subRoot,
									KDTreeNode* & nearnode, int d) const{
	stack<KDTreeNode*> * parents = new stack<KDTreeNode*>();
	stack<bool> * direction = new stack<bool>();
	int *bottom_d = new int();
	double *Dist = new double();
	//forward search
	KDTreeNode* node = forwardtraversal(query, subRoot, d, *bottom_d, *Dist, *parents, *direction);
	nearnode = node; // set the nearest node
	//backward search
	backwardtraversal(query, node, nearnode, *bottom_d, *Dist, *parents, *direction);
	double dist = *Dist;
	delete parents;
	delete direction;
	delete bottom_d;
	delete Dist;
	return dist;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
	//@todo Implement this function!
	KDTreeNode* nearnode = root;//new KDTreeNode();
	double Dist = NearestNeighbor(query, root, nearnode, 0);
	KDTreeNode* node = nearnode;
	return nearnode->point;
}

// template <int Dim>
// bool KDTree<Dim>::possibleOtherSide(const Point<Dim>&query,const Point<Dim>&curr,int dimension,double distance){
//   return (pow((query[dimension]-curr[dimension]),2)<=distance);
// }
//
//
// template <int Dim>
// void KDTree<Dim>::findNearestNeighborHelper(const Point<Dim>& query, Point<Dim>& currBest,int start ,int end,int dimension ,double& distance,bool& first)const{
// if(start>end) return;
// if(start==end){
//   if(first){
//     currBest=Points[start];
//     distance=getDistance(query,currBest);
//     first=false;
//   }
//   else{
//     if(shouldReplace(query,currBest,Points[start])){
//       currBest=Points[start];
//       distance=getDistance(currBest,query);
//     }
//   }
//   return;
// }
// int mid=(start+end)/2;
// if(smallerDimVal(query,Points[mid],dimension)){
//   findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
//   if(shouldReplace(query,currBest,Points[mid])){
//     currBest=Points[mid];
//     distance=getDistance(currBest,query);
//     first=false;
//   }
//   if(possibleOtherSide(query,Points[mid],dimension,distance)){
// findNearestNeighborHelper(query, currBest,mid+1 ,end,(dimension+1)%Dim ,distance, first);
//   }
// }
// else{
//   findNearestNeighborHelper(query, currBest,mid+1,end,(dimension+1)%Dim ,distance, first);
//   if(shouldReplace(query,currBest,Points[mid])){
//     currBest=Points[mid];
//     distance=getDistance(currBest,query);
//     first=false;
//   }
//   if(possibleOtherSide(query,Points[mid],dimension,distance)){
//     findNearestNeighborHelper(query, currBest,start ,mid-1,(dimension+1)%Dim ,distance, first);
//   }
// }
//
// }
//
//
//
//
// template <int Dim>
// Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
// {
//     /**
//      * @todo Implement this function!
//      */
// Point<Dim> currentBest;
// double distacne=0;
// bool firstSide=true;
// findNearestNeighborHelper(query, currentBest,0,Points.size()-1,0,distance,firstSide);
// return currentBest;
// }
