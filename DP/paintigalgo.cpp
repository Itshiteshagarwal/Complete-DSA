#include <bits/stdc++.h> 
#define mod 1000000007
int add(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mul(int a, int b){
    return ((a%mod)*1ll*(b%mod))%mod;
}
int solveMem(int n, int k, vector<int> &dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));
    return dp[n];
}
int solveTab(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
    // memoization
    // vector<int> dp(n+1, -1);
    // return solveMem(n, k, dp);    

    // tabulation
    // return solveTab(n, k);

    // space optimization
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    for(int i=3; i<=n; i++){
        int ans = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;

}