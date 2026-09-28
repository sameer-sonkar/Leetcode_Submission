class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ans = 0;
        map<pair<int, int>, int> m;
        for (int i = 1; i < n; i++) {
            int x = min(nums[i], nums[i - 1]);
            int y = max(nums[i], nums[i - 1]);
            if (x == y)
                cnt++;
            else {
                m[{x, y}]++;
            }
            ans = max(ans, m[{x, y}]);
        }
        return ans + cnt;
    }
};