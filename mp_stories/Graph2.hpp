#include <queue>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;

  std::unordered_map<std::string, bool> visited;
  std::unordered_map<std::string, std::string> pre;
  queue<string> Q;
  for(auto k: vertexMap){
visited[k.first]=false;
  }
  Q.push(start);
  while(!Q.empty()){
    string curr=Q.front();
    Q.pop();
    list<E_byRef> adjEdge=incidentEdges(curr);
    for(E  j:adjEdge){
      string dest=j.dest().key();
      string source=j.source().key();
      string destV;
      if(curr==dest) destV=source;
      else destV=dest;
      if(visited[destV]==false){
        Q.push(destV);
        visited[destV]=true;
        pre[destV]=curr;
      }

    }
  }

string traceBack=end;
while(traceBack!=start){
  path.push_front(traceBack);
  traceBack=pre[traceBack];
}

path.push_front(start);



  return path;
}
