class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.rbegin(), nums.rend());
        int i = 0;
        for (; i < (n+1) / 2; i++) {
            ans += (1LL * nums[i] * nums[i]);
        }
        for (int j = i; j < n; j++) {
            ans -= (1LL * nums[j] * nums[j]);
        }
        return ans;
    }
};