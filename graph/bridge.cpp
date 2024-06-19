//bridge is edge if we remove it then our number of conected component are going to increase or graph is going to disconnect

//here we take 4 array's - disc, low,parent set as -1  and visited set as false in begining

//if we found back edge in a node then we update the low node by using formula
// low[node] = min(low[node], disc[neighbour]);
//we need to update the parent node of the child also and the formula for this is
//low[node] = min(low[node], low[child]);

//to check bridge formula is
// low[neighbour]>disc[node]  -> bridge is present bro

#include<bits/stdc++.h>

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;

        if (!vis[nbr]) {
            dfs(nbr, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nbr]);

            // check if the edge is a bridge or not
            if (low[nbr] > disc[node]) {
                vector<int> ans;
                ans.push_back(nbr);
                ans.push_back(node);
                result.push_back(ans);
            }
        } else {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // adjacency
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // declaration of data structures
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> vis;

    vector<vector<int>> result;
    // dfs
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}
//O(v+e) tc & sc (linear)
