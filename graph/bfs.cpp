//breadth first search

#include <bits/stdc++.h>

void prepareadjList(unordered_map<int, set<int> >&adjList, vector<pair<int, int>> &edges)
{
   for(int i = 0; i<edges.size(); i++)   
   {
       int u = edges[i].first;
       int v = edges[i].second;


       adjList[u].insert(v);
       adjList[v].insert(u);
   }
}

void bsf(unordered_map<int, set<int> >&adjList,  unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
   queue<int>q;

   // Putting source node into queue and marking it visited
   q.push(node);
   visited[node] = true;

   while(!q.empty())
   {
       // Taking 1st node and poping it out from queue
       int frontNode = q.front();
       q.pop();

       // Storing the answer
       ans.push_back(frontNode);

       // Traverse all the neightbours
       for(auto i : adjList[frontNode])
       {
           if(!visited[i])
           {
               // Put into queue
               q.push(i);

               // Mark it visited
               visited[i] = true;
           }
       }
   }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   
   unordered_map<int, set<int> >adjList;

   vector<int>ans;

   unordered_map<int, bool> visited;

   // Step 1 : We have to create our own adjacency list
   prepareadjList(adjList, edges);
   
   // Step 2 : Traverse all componenets of graph even if it is disconnected graph
   for(int i = 0; i<vertex; i++)
   {
       if(!visited[i])
       {
           bsf(adjList, visited, ans, i);
       }
   }

   return ans;
}

//tc and sc - O(n+e)
//n - no of vetrex
//e - no of edges