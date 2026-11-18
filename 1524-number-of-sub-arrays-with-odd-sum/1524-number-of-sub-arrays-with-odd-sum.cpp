class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        int mod = 1e9 + 7;
        long long x = 0;
        int cnt0 = 1, cnt1 = 0;
        for (auto& a : arr) {
            x = (x + a) % 2;
            if (x == 0) {
                ans = (ans % mod + cnt1 % mod) % mod;
                cnt0++;
            } else {
                ans = (ans % mod + cnt0 % mod) % mod;
                cnt1++;
            }
        }
        return ans;
    }
};