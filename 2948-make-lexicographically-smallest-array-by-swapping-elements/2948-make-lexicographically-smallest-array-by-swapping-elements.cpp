class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        unordered_map<int, int> grpid;
        int id = -1;
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) {
            if (i == 0 || temp[i] - temp[i - 1] > limit) {
                id++;
            }
            m[id].push_back(temp[i]);
            grpid[temp[i]] = id;
        }
        vector<int> pos(m.size(), 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int id = grpid[nums[i]];
            int idx = pos[id];
            ans.push_back(m[id][idx]);
            pos[id]++;
        }
        return ans;
    }
};