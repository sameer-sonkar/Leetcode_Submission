class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(nums[i] - nums[n / 2]);
        }
        if (n % 2 == 0) {
            int ans2 = 0;
            for (int i = 0; i < n;i++) {
                ans2 += abs(nums[i] - nums[n / 2] + 1);
            }
            ans = min(ans, ans2);
        }

        return ans;
    }
};