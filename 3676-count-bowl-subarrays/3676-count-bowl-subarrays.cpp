class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && nums[i] > s.top()) {
                s.pop();
                if (s.size() > 0)
                    cnt++;
            }

            s.push(nums[i]);
        }
        return cnt;
    }
};