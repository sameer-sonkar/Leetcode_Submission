class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        set<pair<int, int>> s;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            q;
        vector<vector<int>> ans;
        q.push({nums1[0] + nums2[0], 0, 0});
        s.insert({0, 0});
        while (k && q.size() > 0) {
            auto [sum, row, col] = q.top();
            q.pop();
            ans.push_back({nums1[row], nums2[col]});

            if (row == n && col == m)
                break;
            if (row + 1 < n) {
                long long x = nums1[row + 1] + nums2[col];
                if (s.find({row + 1, col}) == s.end()) {
                    s.insert({row + 1, col});
                    q.push({x, row + 1, col});
                }
            }
            if (col + 1 < m) {
                long long y = nums1[row] + nums2[col + 1];
                if (s.find({row, col + 1}) == s.end()) {
                    s.insert({row, col + 1});
                    q.push({y, row, col + 1});
                }
            }

            k--;
        }
        return ans;
    }
};