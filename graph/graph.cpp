#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:
    unordered_map<T,list<T>> adj;

    void addEdg(T u, T v, bool direction){
        //direction = 0 -> undirected 
        //direction 1 ->directed graph

        //creating a edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};
int main(){

int n;
cout<<"enter the number of nodes"<<endl;
cin>>n;

int m;
cout<<"enter the numbers of edges"<<endl;
cin>>m;

 graph<int> g;

for (int i = 0; i < m; i++)
{
    int u,v;
    cin>>u>>v;
    //undirected 
    g.addEdg(u, v,0);
}

//printing the graph
g.printAdjList();


    return 0;
}


//creating and printing a non directed graph
// #include <bits/stdc++.h> 
// using namespace std;

// vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
//     vector<vector<int>> ans(n); // Store adjacent nodes for each index

//     for (int i = 0; i < m; i++) {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }

//     vector<vector<int>> adj(n);

//     for (int i = 0; i < n; i++) {
//         adj[i].push_back(i); // Include the node itself in its adjacency list

//         for (int j = 0; j < ans[i].size(); j++) {
//             adj[i].push_back(ans[i][j]); // Add neighbors to adjacency list
//         }
//     }

//     return adj;
// }
