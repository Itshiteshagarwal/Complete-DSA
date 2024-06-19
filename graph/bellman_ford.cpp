//this algo is used for negative weight between the nodes
//the graph should not contain negative cycle
//by using this algo we can also check that a graph contains a negative cycle or not
//we also find shortest path
//directed graph with ngative wegights

//n-1 times apply this formula
//if(dist[i]+weight<dist[v])
//dist[v] = dist[u]+weight
//again use this formula if distance updates then it means negative cycle present there // skip
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
//update all the distances for n-1 times
    for(int i=1; i<=n; i++){
        //traverse on edge list
        for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u]!=1e9 && ((dist[u]+ w)<dist[v])){
                dist[v] = dist[u]+w;
            }
        }
    }

    //check for negative cycle
    bool flag = 0;
            for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u]!=1e9 && ((dist[u]+ w)<dist[v])){
               flag = 1;
            }
        }

        if(flag == 0){
            return dist[dest];
        }
        return -1;

}

