// prim's algorithm basically used for find minimum spanning tree
// n nodes //every node is reachable by another node
// n-1 edges
// it should not contain cycle
// 3 data structure must, array of key(root node ko 0 baki sab infinite), array of mst(starting me sqbko false), array of parent(starting me sabko -1)

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // Algorithm starts from here
    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Finding the minimum node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // Mark the min node as true
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    // Start this loop from 2 because the parent of 1 is -1
    for (int i = 2; i <= n; i++)
    {
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }
    return result;
}
// tc = O(n^2)
// sc =