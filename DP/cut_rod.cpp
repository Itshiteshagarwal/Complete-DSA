#include<bits/stdc++.h>
int solve(int n, int x, int y, int z ){
	if(n == 0)
	return 0;

	if(n<0)
	return INT_MIN;
	int a = solve(n-x , x, y ,z) + 1;
	int b = solve(n-y , x, y ,z) + 1;
	int c = solve(n-z , x, y ,z) + 1;

	int ans = max(a, max(b,c));
	return ans;

}
int solve2(int n, int x, int y, int z,vector<int> &dp ){
	if(n == 0)
	return 0;

	if(n<0)
	return INT_MIN;

	if(dp[n] != -1)
	return dp[n];
	int a = solve2(n-x , x, y ,z, dp) + 1;
	int b = solve2(n-y , x, y ,z, dp) + 1;
	int c = solve2(n-z , x, y ,z, dp) + 1;

	dp[n] = max(a, max(b,c));
	return dp[n];

}
int solvetab(int n, int x, int y, int z) {
	vector<int> dp(n+1, INT_MIN);
	dp[0] = 0;
	for(int  i =1; i<=n; i++){
		if(i-x>=0)
		dp[i] = max(dp[i], dp[i-x]+1);
		if(i-y>=0)
		dp[i] = max(dp[i], dp[i-y]+1);
		if(i-z>=0)
		dp[i] = max(dp[i], dp[i-z]+1);
	}

	if(dp[n]<0)
	return 0;
	else
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// int ans = solve(n, x, y , z);

	// if(ans<0)
	// return 0;

	// else
	// return ans;

//memoization
	// vector<int> dp(n+1, -1);
	// int ans  = solve2(n, x,y,z,dp);
	// if(ans <0)
	// return 0;
	// else
	// return ans;

	return solvetab(n,x,y,z);
}