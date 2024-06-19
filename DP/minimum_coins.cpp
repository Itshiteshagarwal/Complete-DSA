#include <bits/stdc++.h> 
//recursion  normal
int solve(vector<int> &num, int x){
    if(x == 0)
    return 0;

    if(x<0)
    return INT_MAX;

    int mini = INT_MAX;

    for(int i =0; i<num.size(); i++){
        int ans = solve(num, x- num[i]);
        if(ans!= INT_MAX)
        mini = min(mini, 1+ans);
    }
    return mini;
}

//dp wala method recursion+memoization
int solve1(vector<int> &num, int x, vector<int> &dp){
    if(x == 0)
    return 0;

    if(x<0)
    return INT_MAX;

    if(dp[x]!=-1)
    return dp[x];

    int mini = INT_MAX;

    for(int i =0; i<num.size(); i++){
        int ans = solve(num, x- num[i]);
        if(ans!= INT_MAX)
        mini = min(mini, 1+ans);
    }
    dp[x] = mini;
}

//tabulation wala method
int solve3(vector<int> &num, int x){

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i<=x; i++){
        for(int j =0; j<num.size(); j++){
          if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
            dp[i] = min(dp[i], 1 + dp[i - num[j]]);
          }
        }
    }
    if(dp[x] == INT_MAX)
    return -1;

    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // int ans = solve(num,x);
    // if(ans == INT_MAX)
    // return -1;
    // return ans;

    // vector<int> dp(x+1, -1);
    // int ans = solve1(num, x, dp);
    // if(ans == INT_MAX)
    //  return -1;
    //  else
    //  return ans;

    return solve3(num,x);
}