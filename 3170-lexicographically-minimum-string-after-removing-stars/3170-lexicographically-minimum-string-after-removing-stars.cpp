class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                q.push({s[i] - 'a', -1 * i});
            } else if (q.size() > 0) {
                int idx = abs(q.top().second);
                q.pop();
                vis[idx] = 1;
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '*' || vis[i])
                continue;
            ans += s[i];
        }
        return ans;
    }
};