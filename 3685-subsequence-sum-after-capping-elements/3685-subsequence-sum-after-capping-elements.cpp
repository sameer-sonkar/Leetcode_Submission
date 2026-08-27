class Solution {
private:
    int check(int idx, vector<int>& nums, vector<vector<int>>& dp, int target) {
        if (target == 0)
            return 1;
        if (idx < 0)
            return 0;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int a = check(idx - 1, nums, dp, target);
        if (nums[idx] <= target) {
            a = (a | (check(idx - 1, nums, dp, target - nums[idx])));
        }
        return dp[idx][target] = a;
    }

public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ans(n, false);
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        sort(nums.begin(), nums.end());
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
                if (check(idx - 1, nums, dp, temp)) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans;
    }
};