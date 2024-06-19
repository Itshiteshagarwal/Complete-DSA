//  #include <bits/stdc++.h>

// bool isSafe(int newx, int newy, int n, vector<vector<bool> >&visited, vector<vector<int> >&arr){

//     if(newx>=0 && newx<n && newy>=0 && newy<n && visited[newx][newy]==0 && arr[newx][newy]==1){

//         return true;

//     }

//     else{

//         return false;

//     }

// } 

// void solve(int x, int y, vector<string> &ans, vector<vector<bool> > visited, string path, int n, vector<vector<int> > &arr){

//     if(x==n-1 && y==n-1){

//         ans.push_back(path);

//         return;

//     }

//     //down

//     if(isSafe(x+1, y, n, visited, arr)){

//         visited[x][y]=1;

//         solve(x+1, y, ans, visited, path+"D", n, arr);

//         visited[x][y]=0;

//     }

//     //left

//     if(isSafe(x, y-1, n, visited, arr)){

//         visited[x][y]=1;

//         solve(x, y-1, ans, visited, path+"L", n, arr);

//         visited[x][y]=0;

//     }

//     //right

//     if(isSafe(x, y+1, n, visited, arr)){

//         visited[x][y]=1;

//         solve(x, y+1, ans, visited, path+"R", n, arr);

//         visited[x][y]=0;

//     }

//     //up

//     if(isSafe(x-1, y, n, visited, arr)){

//         visited[x][y]=1;

//         solve(x-1, y, ans, visited, path+"U", n, arr);

//         visited[x][y]=0;

//     }

// }

// vector < string > searchMaze(vector < vector < int >> & arr, int n) {

//     vector<string> ans;

//     vector<vector<bool>> visited(n, vector<bool>(n, 0));

//     string path="";

//     int x=0, y=0;

//     if(arr[x][y]==0){

//         return ans;

//     }

//     else{

//         solve(x, y, ans, visited, path, n, arr);

//         return ans;

//     }

// } tc 4(n^2);
// sc = (n*m);