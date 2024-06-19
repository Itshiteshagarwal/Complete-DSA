 //approaches of dp

 //1.  top-down -> recursion + memoization
 //2.  bottom-up-> tabulation

 //fibonacci
 #include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){
        if(n<=1)
        return n;

        if(dp[n]!= -1)
        return dp[n];
        dp[n] = fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}
int main()
{
      int n;
      cin>>n;
      vector<int> dp(n+1);

      for(int i =0; i<=n; i++)
              dp[i] = -1;

              cout<<fib(n, dp)<<endl;

              return 0;
} //tc & sc O(n);



//tabultion form

#include<bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin>>n;
      vector<int> dp(n+1);
        dp[1] = 1;
        dp[0] = 0;

for(int i =2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
}
cout<<dp[n]<<endl;
}
//space optimization
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
   cin>>n;
   
   int prev1 = 1;
  int prev0 = 0;
        if(n==0){
                return prev1;
        }
  for (int i = 2; i <= n; i++) {
        int curr = prev0 +prev1;
        prev0 = prev1;
        prev1 = curr;
  }
  cout<<prev1<<endl;
  return 0;
}


//  Min Cost Climbing Stairs
class Solution {
public:
// int solve(vector<int>& cost, int n, vector<int> &dp){
//     if(n==0)
//     return cost[0];

//     if(n==1)
//     return cost[1];

//     if(dp[n]!= -1)
//     return dp[n];

//     dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
//     return dp[n];
// }

// int solve2(vector<int>& cost, int n){
//         vector<int> dp(n+1);

//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for(int i =2; i<n; i++){
//             dp[i] = cost[i]+ min(dp[i-1], dp[i-2]);
//         }

//         return min(dp[n-1], dp[n-2]);
// }
int solve3(vector<int>& cost, int n){


        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i =2; i<n; i++){
            int curr = cost[i]+ min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
}
    int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();

    //     return solve2(cost, n);
    // }
    int n =cost.size();
    return solve3(cost, n);
    }
}; 