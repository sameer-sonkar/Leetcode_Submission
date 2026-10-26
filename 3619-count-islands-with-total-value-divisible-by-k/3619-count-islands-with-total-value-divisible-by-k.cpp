class Solution {
private:
    long long fun(vector<vector<int>>& grid, int i, int j, int k,
                  vector<vector<int>>& vis) {
        if (vis[i][j] == 1)
            return 0;
        vis[i][j] = 1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        long long temp = grid[i][j];
        for (int w = 0; w < 4; w++) {
            int row = i + dx[w];
            int col = j + dy[w];
            if (row >= 0 && row < grid.size() && col >= 0 &&
                col < grid[0].size() && vis[row][col] == 0 &&
                grid[row][col] != 0) {
                temp += fun(grid, row, col, k, vis);
            }
        }
        return temp;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 || vis[i][j] == 1)
                    continue;
                long long check = fun(grid, i, j, k, vis) % k;
                if (check == 0)
                    ans++;
            }
        }
        return ans;
    }
};