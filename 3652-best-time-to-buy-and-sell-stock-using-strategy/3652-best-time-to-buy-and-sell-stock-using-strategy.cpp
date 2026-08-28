class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> pre(n + 1, 0);
        vector<long long> pre2(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + 1LL * prices[i - 1] * strategy[i - 1];
            pre2[i] = pre2[i - 1] + prices[i - 1];
        }
        long long ans = pre[n];
        for (int i = k; i <= n; i++) {
            long long rem = pre[n] - pre[i] + pre[i - k];
            long long lastk = pre2[i] - pre2[i - k / 2];
            ans = max(ans, rem + lastk);
        }
        return ans;
    }
};