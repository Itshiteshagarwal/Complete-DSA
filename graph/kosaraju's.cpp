#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            revdfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Topological sort
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false; // Reset the vis array for reuse
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // DFS call using above rendering
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            count++;
            revdfs(top, vis, transpose);
        }
    }
    return count;
}
