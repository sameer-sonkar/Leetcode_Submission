class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        unordered_map<int, long long> m;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && s.top() > nums[i]) {
                m[s.top()]--;
                s.pop();
            }
            s.push(nums[i]);
            m[nums[i]]++;
            ans += ((long long)s.size() - m[nums[i]]);
        }
        return ans;
    }
};