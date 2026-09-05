class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        multiset<pair<int, int>> m;
        for (int i = 0; i < n; i++) {
            m.insert({nums[i][0], i});
        }
        int ans = m.rbegin()->first - m.begin()->first + 1;
        vector<int> temp = {m.begin()->first, m.rbegin()->first};
        int i = 0;
        vector<int> idx(n, 0);
        int cnt = 0;
        for (auto& x : nums) {
            for (auto& y : x) {
                cnt++;
            }
        }

        while (cnt--) {
            int i = m.begin()->second;
            if (i == n)
                i = 0;
            int j = idx[i];
            int x = m.begin()->first;
            int y = m.rbegin()->first;
            if (y - x + 1 < ans) {
                temp = {x, y};
                ans = y - x + 1;
            }

            if (j >= nums[i].size() - 1)
                break;
            pair<int, int> p = {nums[i][j], i};
            if (m.find(p) != m.end()) {
                m.erase(m.find(p));
            }
            m.insert({nums[i][j + 1], i});

            idx[i]++;
        }

        return temp;
    }
};