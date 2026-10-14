class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        int i = 0;
        int ans = 1;
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            m[nums[j] % k]++;
            while (m.size() > 1) {
                m[nums[i] % k]--;
                sum -= nums[i];
                if (m[nums[i] % k] == 0) {
                    m.erase(nums[i] % k);
                }
                i++;
            }
            if (sum % k == nums[j] % k) {
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};