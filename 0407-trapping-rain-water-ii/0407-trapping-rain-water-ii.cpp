class Solution {
public:
    int trapRainWater(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            q;
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    q.push({nums[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int x[4] = {0, 0, -1, 1};
        int y[4] = {1, -1, 0, 0};
        long long ans = 0;
        while (q.size()) {
            auto [height, row, col] = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int dx = row + x[i];
                int dy = col + y[i];
                if (dx > 0 && dx < n - 1 && dy > 0 && dy < m - 1 &&
                    vis[dx][dy] == 0) {
                    ans += max(0, height-nums[dx][dy]);
                    q.push({max(nums[dx][dy], height), dx, dy});
                    vis[dx][dy] = 1;
                }
            }
        }
        return ans;
    }
};