class Solution {
    long long dp[100][5001];

private:
    long long fun(vector<int>& nums, int sum, int idx ) {
        if (sum == 0)
            return 0;
        if (idx >= nums.size()) {
            if (sum == 0)
                return 0;

            return INT_MAX;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        long long a = INT_MAX, b = INT_MAX, c = INT_MAX;
        long long ans = fun(nums, sum, idx + 1);
        long long temp = nums[idx];
        long long cnt1 = 0;
        while (temp > 0) {

            long long val = temp;
            long long cnt2 = 0;
            while (val <= sum) {
                b = min(b, fun(nums, sum - val, idx + 1) + cnt1 + cnt2);
                if (val == 0)
                    break;
                cnt2++;
                val *= 2;
            }
            cnt1++;
            temp /= 2;
        }

        ans = min({ans, b, c});

        return dp[idx][sum] = ans;
    }

public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = fun(nums, sum, 0);
        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }
};