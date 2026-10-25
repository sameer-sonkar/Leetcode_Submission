class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j,
             int& flag) {
        int n = grid.size(), m = grid[0].size();

        if (grid[i][j] == 0 && (i <= 0 || i >= n - 1 || j <= 0 || j >= m - 1)) {
            flag = 0;
        }
        if (vis[i][j] == 1)
            return;
        vis[i][j] = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int dx = i + x[k];
            int dy = j + y[k];
            if (dx >= 0 && dx <= n - 1 && dy >= 0 && dy <= m - 1 &&
                vis[dx][dy] == 0 && grid[dx][dy] != 1) {
                dfs(grid, vis, dx, dy, flag);
            }
        }
        return;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] != 1 && vis[i][j] == 0) {
                    int flag = 1;
                    dfs(grid, vis, i, j, flag);
                    ans += flag;
                }
            }
        }
        return ans;
    }
};