class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size();
        vector<vector<int>> bitpos(n, vector<int>(m));
        vector<int> start(2, -1);
        int cnt = 0;
        int ans = 0;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char a = classroom[i][j];
                if (a == 'L') {
                    bitpos[i][j] = cnt;
                    cnt++;
                } else if (a == 'S') {
                    start[0] = i;
                    start[1] = j;
                }
            }
        }

        if ((1 << cnt) - 1 == 0)
            return 0;
        queue<tuple<int, int, int, int>> q;
        q.push({start[0], start[1], energy, 0});
        int vis[n][m][energy + 1][(1 << cnt)];
        memset(vis, 0, sizeof(vis));
        vis[start[0]][start[1]][energy][0] = 1;
        while (q.size()) {
            int size = q.size();
            while (size--) {
                auto [row, col, curr, mask] = q.front();
                q.pop();
                if (mask == (1 << cnt) - 1)
                    return ans;
                if (curr == 0)
                    continue;
                for (int i = 0; i < 4; i++) {
                    int dx = x[i] + row;
                    int dy = y[i] + col;
                    int p = curr - 1;
                    int nextmask = mask;

                    if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                        classroom[dx][dy] != 'X') {
                        if (classroom[dx][dy] == 'R') {
                            p = energy;
                        } else if (classroom[dx][dy] == 'L') {
                            nextmask |= (1 << (bitpos[dx][dy]));
                        }
                        if (vis[dx][dy][p][nextmask] == 0) {
                            q.push({dx, dy, p, nextmask});
                            vis[dx][dy][p][nextmask] = 1;
                        }
                    }
                }
            }

            ans++;
        }
        return -1;
    }
};