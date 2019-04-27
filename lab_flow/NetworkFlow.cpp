/**
 * @file NetworkFlow.cpp
 * CS 225: Data Structures
 */

#include <vector>
#include <algorithm>
#include <set>

#include "graph.h"
#include "edge.h"

#include "NetworkFlow.h"

int min(int a, int b) {
  if (a<b)
    return a;
  else return b;
}

NetworkFlow::NetworkFlow(Graph & startingGraph, Vertex source, Vertex sink) :
  g_(startingGraph), residual_(Graph(true,true)), flow_(Graph(true,true)), source_(source), sink_(sink) {
vector<Vertex> allv = g_.getVertices();
vector<Edge> alle=g_.getEdges();
for (auto j:allv)
{
  residual_.insertVertex(j);
  flow_.insertVertex(j);

}


for (auto k:alle)
{ int weight=k.getWeight();
  Vertex vs=k.source;
  Vertex vd=k.dest;
  residual_.insertEdge(vs,vd);
  residual_.insertEdge(vd,vs);

  residual_.setEdgeWeight(vs, vd, weight);
  residual_.setEdgeWeight(vd, vs, 0);

  flow_.insertEdge(vs,vd);
  flow_.setEdgeWeight(vs, vd, 0);


}



  // YOUR CODE HERE
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the helper function.
   *
   * @param source  The starting (current) vertex
   * @param sink    The destination vertex
   * @param path    The vertices in the path
   * @param visited A set of vertices we have visited
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink,
  std::vector<Vertex> &path, std::set<Vertex> &visited) {

  if (visited.count(source) != 0)
    return false;
  visited.insert(source);

  if (source == sink) {
    return true;
  }

  vector<Vertex> adjs = residual_.getAdjacent(source);
  for(auto it = adjs.begin(); it != adjs.end(); it++) {
    if (visited.count(*it) == 0 && residual_.getEdgeWeight(source,*it) > 0) {
      path.push_back(*it);
      if (findAugmentingPath(*it,sink,path,visited))
        return true;
      else {
        path.pop_back();
      }
    }

  }

  return false;
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the main function.  It initializes a set to keep track of visited vertices.
   *
   * @param source The starting (current) vertex
   * @param sink   The destination vertex
   * @param path   The vertices in the path
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, std::vector<Vertex> &path) {
   std::set<Vertex> visited;
   path.clear();
   path.push_back(source);
   return findAugmentingPath(source,sink,path,visited);
}

  /**
   * pathCapacity - Determine the capacity of a path in the residual graph.
   *
   * @param path   The vertices in the path
   */

int NetworkFlow::pathCapacity(const std::vector<Vertex> & path) const {
  // YOUR CODE HERE
  int minWeight=1000;
  vector<Vertex> path1=path;
  vector<Vertex> path2=path;
  path1.pop_back();
  path2.erase(path2.begin());
  for(unsigned i=0;i<path1.size();i++){

      int edgeWeight=residual_.getEdgeWeight(path1[i],path2[i]);
      if(minWeight>edgeWeight) minWeight=edgeWeight;

  }
  return minWeight;
}

  /**
   * calculuateFlow - Determine the capacity of a path in the residual graph.
   * Sets the member function `maxFlow_` to be the flow, and updates the
   * residual graph and flow graph according to the algorithm.
   *
   * @return The network flow graph.
   */

const Graph & NetworkFlow::calculateFlow() {
  // YOUR CODE HERE
  std::vector<Vertex> p;
  //findAugmentingPath(source_, sink_, p);
  maxFlow_=0;

  while(findAugmentingPath(source_, sink_, p)){
    int cap=pathCapacity(p);
    maxFlow_+=cap;
  std::vector<Vertex> path1=p;
  std::vector<Vertex> path2=p;

    path1.pop_back();
    path2.erase(path2.begin());
    for(unsigned i=0;i<path1.size();i++){
        int edgeWeight1=residual_.getEdgeWeight(path1[i], path2[i]);

        int edgeWeight2=residual_.getEdgeWeight(path2[i], path1[i]);
        residual_.setEdgeWeight(path1[i], path2[i], edgeWeight1-cap);
        residual_.setEdgeWeight(path2[i], path1[i], edgeWeight2+cap);
if(flow_.edgeExists(path1[i], path2[i])) {
  int edgeWeight=flow_.getEdgeWeight(path1[i], path2[i]);
  flow_.setEdgeWeight(path1[i], path2[i], edgeWeight+cap);
}
else {
  int edgeWeight=flow_.getEdgeWeight(path2[i], path1[i]);

  flow_.setEdgeWeight(path2[i], path1[i], edgeWeight-cap);}

      }
    }
    // vector<Vertex> adjs = flow_.getAdjacent(source_);
    // for(auto it = adjs.begin(); it != adjs.end(); it++) {
    //   maxFlow_+=flow_.getEdgeWeight(source_,*it);
    // }
  return flow_;
}

int NetworkFlow::getMaxFlow() const {
  return maxFlow_;
}

const Graph & NetworkFlow::getGraph() const {
  return g_;
}

const Graph & NetworkFlow::getFlowGraph() const {
  return flow_;
}

const Graph & NetworkFlow::getResidualGraph() const {
  return residual_;
}
