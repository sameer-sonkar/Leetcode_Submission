class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int mx = -1;
        int idx = -1;
        vector<int> mn(n, INT_MAX);
        mn[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(nums[i], mn[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx - mn[i] <= k) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};