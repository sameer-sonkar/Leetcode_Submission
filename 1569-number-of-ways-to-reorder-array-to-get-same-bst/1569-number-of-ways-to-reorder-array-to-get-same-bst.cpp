class Solution {
    vector<vector<int>> pt;
    long long MOD = 1e9 + 7;

private:
    long long fun(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 1;
        int root = nums[0];
        vector<int> left;
        vector<int> right;
        for (long long i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else {
                right.push_back(nums[i]);
            }
        }
        long long x = fun(left);
        long long y = fun(right);
        long long z = pt[n - 1][left.size()];
        long long ans = (((x * y) % MOD) * z) % MOD;
        return ans;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pt.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pt[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pt[i][j] = (pt[i - 1][j] + pt[i - 1][j - 1]) % MOD;
            }
        }
        int ans = fun(nums);
        return (ans - 1) % MOD;
    }
};