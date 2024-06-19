//cycle detection in undirected graph using bfs and dfs both
 #include<bits/stdc++.h>

using namespace std;

bool iscyclicbfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (visited[neighbour] && neighbour != parent[front]) {
                return true; // Cycle detected
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false; // No cycle detected
}

bool iscyclicdfs(int node, int parent,  unordered_map<int, bool> &visited,  unordered_map<int, list<int>> adj){
    visited[node] = true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycledetected = iscyclicdfs(neighbour, node, visited, adj);
            if(cycledetected)
            return true;
        }
        else if(neighbour!=parent){
                return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = iscyclicdfs(i,-1, visited, adj);
            if (ans) {
                return "Yes"; // Cycle detected
            }
        }
    }
    return "No"; // No cycle detected
}