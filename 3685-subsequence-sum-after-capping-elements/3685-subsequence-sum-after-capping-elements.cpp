class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ans(n, false);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        sort(nums.begin(), nums.end());
        for (int idx = 1; idx <= n; idx++) {
            for (int target = k; target >= 0; target--) {
                int a = dp[idx - 1][target];
                if (target >= nums[idx - 1]) {
                    a = (a | dp[idx - 1][target - nums[idx - 1]]);
                }
                dp[idx][target] = a;
            }
        }
        for (int i = 0; i < n; i++) {
            int idx =
                lower_bound(nums.begin(), nums.end(), i + 1) - nums.begin();
            int cnt = n - idx;
            for (int j = 0; j <= cnt; j++) {
                long long temp = k;
                long long p = (j) * (i + 1);
                if (p > temp)
                    break;
                temp -= p;
                if (dp[idx][temp]) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans;
    }
};