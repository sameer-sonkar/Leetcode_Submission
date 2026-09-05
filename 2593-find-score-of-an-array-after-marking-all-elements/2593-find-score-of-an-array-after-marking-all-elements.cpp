class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            s.insert({nums[i], i});
        }
        long long ans=0;
        while (s.size()) {
            auto it = s.begin();
            int idx = it->second;
            int val = it->first;
            ans += val;
            s.erase(it);
            if (idx - 1 >= 0 && s.find({nums[idx - 1], idx - 1}) != s.end()) {
                s.erase({nums[idx - 1], idx - 1});
            }
            if (idx + 1 < n && s.find({nums[idx + 1], idx + 1}) != s.end()) {
                s.erase({nums[idx + 1], idx + 1});
            }
        }
        return ans;
    }
};