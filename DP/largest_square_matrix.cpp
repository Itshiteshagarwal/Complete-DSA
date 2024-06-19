class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& mat, int& maxi) {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solve(i, j + 1, mat, maxi);
        int diagonal = solve(i + 1, j + 1, mat, maxi);
        int down = solve(i + 1, j, mat, maxi);

        if (mat[i][j] == 1) {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;  // Return the computed value
        } else {
            return 0;
        }
    }
    
    //memoization
 int solve2(vector<vector<int>>& mat, int i, int j, int& maxi, vector<vector<int>>& dp) {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve2(mat, i, j + 1, maxi, dp);
        int diagonal = solve2(mat, i + 1, j + 1, maxi, dp);
        int down = solve2(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == 1) {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }
    
    int solvetab(vector<vector<int>>& mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
        
        for(int i = row-1; i>=0; i--){
            for(int j =col-1; j>=0; j--){
             int right = dp[i][j+1];
             int diagonal = dp[i+1][j+1];
             int down = dp[i+1][j];

            if (mat[i][j] == 1) {
               dp[i][j] = 1 + min(right, min(diagonal, down));
               maxi = max(maxi, dp[i][j]);
            } else 
            {
            dp[i][j] = 0;
           }     
            }
        }
        return dp[0][0];
    }
        int solves(vector<vector<int>>& mat, int &maxi){
        int row = mat.size();
        int col = mat[0].size();
        vector<int> curr(col+1, 0);
        vector<int> next(col+1, 0);
        
        for(int i = row-1; i>=0; i--){
            for(int j =col-1; j>=0; j--){
             int right = curr[j+1];
             int diagonal = next[j+1];
             int down = next[j];

            if (mat[i][j] == 1) {
               curr[j] = 1 + min(right, min(diagonal, down));
               maxi = max(maxi, curr[j]);
            } else 
            {
            curr[j] = 0;
           }     
            }
            next = curr;
        }
        return next[0];
    }
    int maxSquare(int n, int m, vector<vector<int>>& mat) {
        // int maxi = 0;
        // solve(0, 0, mat, maxi);
        // return maxi;
        // int maxi = 0;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // solve2(mat, 0, 0, maxi, dp);
        // return maxi;
        
        // int maxi = 0;
        // solvetab(mat, maxi);
        // return maxi;

        int maxi = 0;
        solves(mat, maxi);
        return maxi;
    }
};