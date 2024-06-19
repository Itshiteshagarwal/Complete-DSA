//topological sort in directed asyclic graph
//ts linear ordering of vertexe such that of every edge u->v in this u always appers before v in that ordering
#include <bits/stdc++.h> 

using namespace std;

void topsort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topsort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Call dfs topological sort function for all components
    vector<bool> visited(v);
    stack<int> s;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topsort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//tc and sc O(v+e)

//topological sort khan's algo
#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(v, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    // 0 indegree walo ko push kardo
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for (auto neighbour : adj[front]) {
            if (--indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}//tc & sc - O(m+e)




