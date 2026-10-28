class Solution {
private:
    int inf = 1e9;
    int fun(vector<vector<int>>& grid, int i, int j,int zor, int n, int m,
            vector<vector<vector<int>>>& dp) {
        if (i >= n || j >= m)
            return inf;
        if (dp[i][j][zor] != inf)
            return dp[i][j][zor];
        if ((i == n - 1 && j == m - 1))
            return dp[i][j][zor] = zor^grid[n - 1][m - 1];

        int a = fun(grid, i + 1, j,zor^ grid[i][j] ,n, m, dp) ;
        int b = fun(grid, i, j + 1,zor^ grid[i][j], n, m, dp) ;
        return dp[i][j][zor] = min(a, b);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        int inf = 1e9;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1,vector<int>(1024,inf)));
        int ans = fun(grid, 0, 0,0, n, m, dp);
        return ans;
    }
};