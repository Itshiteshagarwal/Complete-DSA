//cycle detection in directed graph using bfs 
#include<bits/stdc++.h>
bool chekcycledfs(int node, unordered_map<int, bool> &visited,   unordered_map<int, bool> &dfsvisited,  unordered_map<int, list<int>> &adj){
  //mark both node true for begining
  visited[node] = true;
  dfsvisited[node] = true;

  for(auto neighbour: adj[node]){
    if(!visited[neighbour]){
      //recursive call
      bool cycledetected = chekcycledfs(neighbour, visited, dfsvisited, adj);
      if(cycledetected)
      return true;
    }
    //checking that the neighbour of dfs visited is true 
    else if(dfsvisited[neighbour] == true){
        return true;
    }
  }
  //mark all node of dfs visited false
  dfsvisited[node] = false;
  return false;
}
        
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   //create adj list
   unordered_map<int, list<int>> adj;
   for(int i =0; i<edges.size(); i++){
     int u = edges[i].first;
     int v = edges[i].second;
//directed graph so only push from u->v
     adj[u].push_back(v);
   }

   //call dfs for alll components
  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsvisited;
   for(int i=1; i<=n; i++){
     if(!visited[i]){
       bool cyclefound = chekcycledfs(i , visited, dfsvisited, adj);
       if(cyclefound)
       return true;
     }
   }
   return false;
}// tcO(n+e)
//sc linear


//cycle detection in directed graph using khan's
#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int cnt = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // count store
        cnt++;

        // neighbour indegree update
        for (auto neighbour : adj[front]) {
            if (--indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(cnt == n)
    return false;
    else
    return true;
}//same time nd space complex.
