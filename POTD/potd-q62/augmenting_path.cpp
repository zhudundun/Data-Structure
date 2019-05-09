#include "network_flow.cpp"
#include <queue>
// TODO: Implement this function. Try using BFS/DFS
bool hasAugmentingPath(ResidualNetwork r) {
  // Create an array for all nodes we visited. Initialized to false.
   int n = r.adjacencyMatrix.size();
   vector<bool> visited(n) ;
   for(int i=0;i<n;i++) visited[i]=false;

   // Create a queue to check each node.
   queue<int> q;

   // Push our source into the queue and mark it as visited. It has no parent.
   q.push(r.source);
   visited[r.source] = true;
   //parent[source] = -1;

   // Keep visiting vertices.
   while(q.empty() == false)
       {
       int u = q.front();
       q.pop();

       // Check all of u's friends.
       for(int i = 0; i < n; i++)
           {
           int v = i;
           int capacity = r.adjacencyMatrix[u][v];

           // We find a neighbor that hasn't been visited, and the capacity is bigger than 0.
           if(visited[v] == false && capacity > 0)
               {
               // Push the neighbor onto the queue, mark it's parent, and mark it as visited.
               q.push(v);
               //parent[v] = u;
               visited[v] = true;
               }
           }
       }

   // If the sink got visited, then we found a path to it.
   if(visited[r.sink] == true)
       { return true; }

   return false;
}
