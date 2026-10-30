class Solution {
public:
    int inf = 1e9;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& x : edges) {
            graph[x[0]].push_back({x[1], x[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k + 1, inf));
        vector<vector<bool>> vis(n, vector<bool>(k + 1, false));
        priority_queue<tuple<int, int, int>> q;
        dist[0][1] = 0;

        q.push({0, 0, 1});
        while (!q.empty()) {
            auto [cost, node, cnt] = q.top();

            q.pop();
            if (vis[node][cnt])
                continue;
            vis[node][cnt] = true;
            for (auto& x : graph[node]) {
                // x.second=-1*x.second;
                if (labels[x.first] == labels[node]) {
                    if (cnt + 1 <= k &&
                        dist[x.first][cnt + 1] > dist[node][cnt] + x.second &&
                        vis[x.first][cnt + 1] == false) {

                        dist[x.first][cnt + 1] = dist[node][cnt] + x.second;
                        // vis[x.first][cnt + 1] == true;
                        q.push({-1 * dist[x.first][cnt + 1], x.first, cnt + 1});
                    }

                } else {
                    if (dist[x.first][1] > dist[node][cnt] + x.second &&
                        vis[x.first][1] == false) {
                        dist[x.first][1] = dist[node][cnt] + x.second;
                        // vis[x.first][1] == true;
                        q.push({-1 * dist[x.first][1], x.first, 1});
                    }
                }
            }
        }
        int ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        if (ans == inf)
            return -1;
        return ans;
    }
};