#include <bits/stdc++.h> 
using namespace std;
//memoization
int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
    //base case // if only one item steal and just compare it with knapsack capacity
    if(index == 0){
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1) {
      return dp[index][capacity];
    }
    int include = 0;
    if(weight[index] <= capacity)
        include = value[index] + solve(weight, value, index-1, capacity - weight[index], dp);

    int exclude = solve(weight, value, index-1, capacity, dp);
	dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

//tabulation
int solve2(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
	for(int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity)
		dp[0][w] = value[0];

		else
		dp[0][w] = 0;

	}

	for(int index =1; index<n; index++){
		for(int w =0; w<=capacity; w++){
	int include = 0;
    if(weight[index] <= w)
    include = value[index] + dp[index-1][w-weight[index]];

    int exclude =0+ dp[index-1][w];
	dp[index][w] = max(include, exclude);

		}
	}
	    return dp[n-1][capacity];
}
//space optimization
int solve3(vector<int> &weight, vector<int> &value, int n, int capacity){
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);
	for(int w = weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity)
		prev[w] = value[0];

		else
		prev[w] = 0;

	}

	for(int index =1; index<n; index++){
		for(int w =0; w<=capacity; w++){
	int include = 0;
    if(weight[index] <= w)
    include = value[index] + prev[w-weight[index]];

    int exclude =0+prev[w];
	curr[w] = max(include, exclude);

		}
		prev = curr;
	}
	    return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
   // return solve(weight, value, n-1, capacity);
//    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
//     return solve(weight, value, n-1, maxWeight, dp);

	// return solve2(weight,value,n,maxWeight);
	
	return solve3(weight,value,n,maxWeight);
	}