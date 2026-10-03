class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        vector<long long> pre(n + 1, 0);
        for (long long i = 0; i < n; i++) {
            pre[i + 1] = nums[i] + pre[i];
        }
        for (int i = 0; i <= n; i++) {
            unordered_set<long long> s;
            s.insert(0);
            for (int j = i + 1; j <= n; j++) {
                s.insert(((2 * nums[j-1]) % k+k)%k);
                long long sum = ((pre[j] - pre[i])%k+k)%k;
                // cout<<(sum%k)<<endl;
                if (sum % k == 0 || s.find(sum % k)!=s.end()) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};