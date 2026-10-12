class Solution {
    int mod = 1e9 + 7;
    void modadd(long long& cnt, long long temp) {
        cnt = (cnt % mod + ((temp % mod) * (temp % mod)) % mod) % mod;
        return;
    }

public:
    int maxSum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 31; j++) {
                if ((nums[i] & (1 << j))) {
                    m[j]++;
                }
            }
        }
        long long cnt = 0;
        while (k) {
            long long temp = 0;
            for (int i = 31; i >= 0; i--) {
                if (m.size() > 0 && m.find(i) != m.end()) {
                    temp |= (1 << i);
                    m[i]--;
                    if (m[i] == 0) {
                        m.erase(i);
                    }
                }
            }
            modadd(cnt, temp);
            k--;
        }
        return (int)cnt;
    }
};