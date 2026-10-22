class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc = 1, dsc = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == (nums[i - 1] + 1) % n)
                asc++;
            if ((nums[i] + 1) % n == (nums[i - 1]))
                dsc++;
        }
        if (asc == n && nums[0] == 0)
            return 0;        // already sorted in asc order;
        else if (asc == n) { // in asc order need nums[0] swaps to correct pos;
            return min(n - nums[0], nums[0] + 2);
        } else if (dsc == n) { // two choices either reverse first then swap or
                               // swap then reverse;
            return min(n - nums[n - 1], nums[n - 1]) + 1;
        }
        return -1;
    }
};