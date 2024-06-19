class Solution {
public:
    int lis(vector<int>& ans, int n) {
        if (n == 0) {
            return 0;
        }
        
        vector<int> result;
        result.push_back(ans[0]);
        
        for (int i = 1; i < n; i++) {
            if (ans[i] > result.back()) {
                result.push_back(ans[i]);
            }
            else {
                int index = lower_bound(result.begin(), result.end(), ans[i]) - result.begin();
                result[index] = ans[i];
            }
        }
        
        return result.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // SORT THE VECTOR
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<int> ans;
        for (auto i : envelopes) {
            ans.push_back(i[1]);
        }
        
        int n = ans.size();
        return lis(ans, n);
    }
};