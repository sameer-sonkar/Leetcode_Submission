class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int ans = 0;
        int n = nums1.size();
        k1 += k2;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int x = abs(nums1[i] - nums2[i]);
            temp.push_back(x);
            ans = max(ans, temp.back());
        }

        vector<int> freq(ans + 1, 0);
        for (auto& x : temp) {
        freq[x]++;
        }
        for (int i = ans; i > 0; i--) {
            if (freq[i] == 0)
                continue;
            if (k1 >= freq[i]) {
                k1 -= freq[i];
                freq[i - 1] += freq[i];
                freq[i] = 0;

            } else {
                freq[i] -= k1;
                freq[i - 1] += k1;
                break;
            }
        }
        long long ans2 = 0;
        for (int i = 0; i <= ans; i++) {
            ans2 += 1LL * freq[i] * i*i;
        }
        return ans2;
    }
};