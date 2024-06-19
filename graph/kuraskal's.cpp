//disjoint set is used for kurskal's algo
//2 operations are important for find disjoint
//find parent() or find set()
//find union() or find union set()

 //efficient implimantion of disjoint union w can do by -  union by rank and path commpression
//in kuraskal's algo we didn't need of any adjancy list
//we need a linear data structure array, vector in this data structure we store u and v and weight

#include<bits/stdc++.h>

bool cmp(vector<int>&a, vector<int> &b){
  return a[2]<b[2];
}
void makeset(vector<int> &parent, vector<int> &rank, int n){
  //making sets of parent and rank
  for(int i =0; i<n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int findparent(vector<int> &parent, int node){
  //if our node is equal to our desired parent node the nreturn that  node
  if(parent[node] == node){
    return node;
  }
  //recursive call and set the parent of that particular node
  return parent[node] = findparent(parent, parent[node]);
}

void unionset(int u, int v, vector<int> &parent, vector<int>&rank){
  //find the parents
  u = findparent(parent,u);
  v = findparent(parent, v);

//check their rank greater,leser or equal
  if(rank[u]< rank[v]){
    parent[u] = v;
  }
  else if(rank[v]<rank[u]){
    parent[v] = u;
  }
  else{
    parent[v] = u;
    rank[u]++;
  }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
//sorting the edges 
  sort(edges.begin(), edges.end(), cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  //calling the f/n 
  makeset(parent, rank, n);
  int minweight = 0;

//traverse all the edges
  for(int i =0; i<edges.size(); i++){
   int u = findparent(parent, edges[i][0]);
   int v = findparent(parent, edges[i][1]);
   int w = edges[i][2];

   if(u!=v){

     minweight+= w;
     unionset(u, v , parent, rank);
   }


  }
return minweight;

}//tc - O(mlogm)
//sc O(n)
