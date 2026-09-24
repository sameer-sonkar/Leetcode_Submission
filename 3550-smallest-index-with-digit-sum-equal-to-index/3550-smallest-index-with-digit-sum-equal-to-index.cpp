class Solution {
public:
    int fun(int x) {
        int cnt = 0;
        while (x) {
            cnt += x % 10;
            x /= 10;
        }
        return cnt;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i == fun(nums[i]))
                return i;
        }
        return -1;
    }
};