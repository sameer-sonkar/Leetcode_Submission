class Solution {
private:
    int fun(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i <= 500; i++) {
            int x = i * (i + 1) / 2;
            if (x <= n) {
                ans = min(ans, i + 1 + fun(n - x, dp));
            }
        }
        return dp[n] = ans;
    }

public:
    int minDays(int n) {
        vector<int> dp(n + 1, -1);
        int ans = fun(n, dp);
        return ans - 1;
    }
};