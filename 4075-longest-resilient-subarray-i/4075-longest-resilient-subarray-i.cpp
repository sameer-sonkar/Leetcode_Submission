class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            long long cnt = 0;
            unordered_set<long long> s;
            for (int j = i; j < n; j++) {
                cnt += (nums[j]) % k;
                cnt %= k;
                s.insert((nums[j]) % k);
                if (s.find(cnt) != s.end() && s.size() == 1) {

                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};