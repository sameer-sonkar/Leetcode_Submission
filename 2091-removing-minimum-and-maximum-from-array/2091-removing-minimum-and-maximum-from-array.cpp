class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx1 = -1, idx2 = -1;
        int mx1 = INT_MIN, mn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx1) {
                idx1 = i;
                mx1 = nums[i];
            }
            if (mn > nums[i]) {
                idx2 = i;
                mn = nums[i];
            }
        }
        if (idx1 > idx2)
            swap(idx1, idx2);
        // cout<<idx1<<" "<<idx2<<endl;
        int ans = 0;
        ans = min({idx2 + 1, n - idx1, idx1 + 1 + n - idx2});
        return ans;
    }
};