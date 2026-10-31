class Solution {
    long long MOD = 1e9 + 7;
    long long dp[510][510][2];

private:
    long long fun(vector<vector<int>>& grid, int i, int j, int dir) {
        if (i >= grid.size() || j == grid[0].size())
            return 0;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;
        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];
        long long a = fun(grid, i + 1, j, 0);
        long long b = fun(grid, i, j + 1, 1);
        if (grid[i][j] == 1) {
            if (dir == 0) {
                a = 0;
            } else {
                b = 0;
            }
        }
        modadd(a, b);
        return dp[i][j][dir] = a;
    }

public:
    void modadd(long long& a, long long b) {
        a = (a % MOD + b % MOD) % MOD;
        return;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long ans = 0;
        memset(dp, -1, sizeof(dp));
        modadd(ans, fun(grid, 0, 0, 0));

        return ans;
    }
};