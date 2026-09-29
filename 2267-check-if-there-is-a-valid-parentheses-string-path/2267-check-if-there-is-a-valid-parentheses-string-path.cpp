class Solution {
    int dp[101][101][202];

private:
    int fun(vector<vector<char>>& grid, int i, int j, int cnt) {
        if (i == grid.size() || j == grid[0].size())
            return 0;
        int x = grid[i][j] == '(' ? 1 : -1;
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (cnt + x == 0)
                return 1;
            return 0;
        }
        if (dp[i][j][cnt] != -1)
            return dp[i][j][cnt];
        if (cnt + x < 0)
            return dp[i][j][cnt] = 0;
        int a = fun(grid, i + 1, j, cnt + x) | fun(grid, i, j + 1, cnt + x);
        return dp[i][j][cnt] = a;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        memset(dp, -1, sizeof(dp));
        int ans = fun(grid, 0, 0, 0);
        return ans == 1;
    }
};