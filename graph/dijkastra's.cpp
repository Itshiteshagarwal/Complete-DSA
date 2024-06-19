#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create an adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

//creation of distance array with infinite value initially
    vector<int> distance(vertices, INT_MAX);

    //creation of set on basis distance,node
    set<pair<int, int>> st;
    
//initalize distance and set with source node
    distance[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        // fetch top node
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
//remove top node now
        st.erase(st.begin());

        // traverse neighbors
        for(auto neighbor : adj[topNode]){
            if(nodeDistance + neighbor.second < distance[neighbor.first]){
                auto record = st.find(make_pair(distance[neighbor.first], neighbor.first));
    //if record found then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                distance[neighbor.first] = nodeDistance + neighbor.second;
                //record push in set
                st.insert(make_pair(distance[neighbor.first], neighbor.first));
            }
        }
    }

    return distance;
}
//tc = O(ElogV);
//sc = O(N+E);

