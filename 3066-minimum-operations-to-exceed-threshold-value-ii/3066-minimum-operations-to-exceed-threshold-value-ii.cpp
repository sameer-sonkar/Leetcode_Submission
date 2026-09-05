class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<long long > m;
        for (auto& x : nums) {
            m.insert(x);
        }
        int cnt = 0;
        while (1) {
            auto it = m.begin();
            if (*it >= k)
                break;
            long long  x = *m.begin();
            m.erase(m.begin());
            long long y = *m.begin();
            m.erase(m.begin());
            m.insert(2 * x + y);
            cnt++;
        }
        return cnt;
    }
};