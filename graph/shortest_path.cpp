//shortedt path in undirected graph using bfs
#include<bits/stdc++.h>

#include<unordered_map>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    // ADJ LIST
    unordered_map<int,list<int>>adj;
    for(int i=0; i<edges.size();i++)
    {

        int u=edges[i].first;
        int v= edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //do bfs

    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;
    
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        
        for(auto neighbour :adj[front])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;
                parent[neighbour]=front;
                q.push(neighbour);
            
            }
        }
    }

    
    // prepare short path
    vector<int>ans;
    int currentnode= t;
    ans.push_back(t);
    while(currentnode!=s)
    {
        currentnode=parent[currentnode];
        ans.push_back(currentnode);
        
    }
    reverse(ans.begin(),ans.end());
    return ans;

} //tc && sc O(n+e)

//shortest path in directed asyclic graph
class graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addedge(int u, int v, int weight);
    pair<int, int> p = make_pair(v,weight);
    adj[u].push_back(p);

    void printadj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }
//depth first search
    void dfs(int node, unorderd_map<int, bool> & visited, stack<int> &s){
        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!vis[neighbour.first]){
                dfs(neighbour.first, visited, s);
            }
        }
        //push the node inside the stack
        s.push[node];
    }

    void getshortestpath(int src, vector<int> &dist, stack<int> &s){
        //suppose distance of source node is zero
        dist[src] = 0;
        //checking the node one by one
        while(!s.empty()){
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top]+ i.second<dist[i.first]){
                        dist[i.first] = dist[top]+ i.second;
                    }
                }
            }
        }
    }
};
int main(){
    //generating graph and add all the edges
    Graph g;
g.addedge(0,1,5);
g.addedge(0,2,3);
g.addedge(1,3,3);
g.addedge(1,3,6);
g.addedge(2,3,7);
g.addedge(2,4,4);
g.addedge(2,5,2);
g.addedge(3,4,-1);

//print the adjency list
g.printadj();
int n = 6;
//totplogical sort
unordered_map<int,bool> visited;
stack<int>s;
    for(int  i =0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }

    int src =1;
    vector<int>dist(n);
//distance vector creating
    for(int i =0; i<n; i++){
        dist[i] = INT_MAX;

g.getshortestpath(src, dist, s);
cout<<"ans is"<<endl;

for (int i = 0; i < dist.size(); i++)
{
    cout<<dist[i]<<" ";
}cout<<endl;
    }
    return 0;
}
// tc & sc both O(N+e)


