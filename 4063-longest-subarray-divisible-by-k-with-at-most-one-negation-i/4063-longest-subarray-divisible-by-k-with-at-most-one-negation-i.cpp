class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        vector<long long> pre(n + 1, 0);
        for (long long i = 0; i < n; i++) {
            pre[i + 1] = nums[i] + pre[i];
        }
        for (int i = 0; i <n; i++) {
            unordered_set<long long> s;
            s.insert(0);
            int cnt=0;
            for (int j = i; j < n; j++) {
                s.insert(((2 * nums[j]) % k+k)%k);
                cnt+=nums[j];

                long long sum = ((cnt)%k+k)%k;
                // cout<<(sum%k)<<endl;
                if (s.find(sum % k)!=s.end()) {
                    ans = max(ans, j - i+1);
                }
            }
        }
        return ans;
    }
};