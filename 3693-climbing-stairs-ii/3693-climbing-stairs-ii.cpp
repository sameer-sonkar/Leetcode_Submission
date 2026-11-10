class Solution {
private:
    int fun(int n, vector<int>& costs, int idx,vector<int>&dp) {
        if (idx >= n)
            return 0;
        if (dp[idx] != INT_MAX)
            return dp[idx];
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (idx < n) {
            a = costs[idx] + 1 + fun(n, costs, idx + 1,dp);
        }
        if (idx + 1 < n) {
            b = costs[idx + 1] + 4 + fun(n, costs, idx + 2,dp);
        }
        if (idx + 2 < n) {
            c = costs[idx + 2] + 9 + fun(n, costs, idx + 3,dp);
        }
        int ans = min(c, min(a, b));
        return dp[idx] = ans;
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        int ans = fun(n, costs, 0, dp);
        return ans;
    }
};