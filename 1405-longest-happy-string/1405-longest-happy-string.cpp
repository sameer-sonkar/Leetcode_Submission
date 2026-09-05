class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        if (a > 0)
            q.push({a, 'a'});
        if (b > 0)
            q.push({b, 'b'});
        if (c > 0)
            q.push({c, 'c'});
        string ans = "";
        while (q.size()) {
            int curr = q.top().first;
            char x = q.top().second;
            q.pop();
            if (ans.size() >= 2 && ans[ans.size() - 1] == x &&
                ans[ans.size() - 2] == x) {
                if (q.size() == 0)
                    break;
                int next = q.top().first;
                char y = q.top().second;
                q.pop();
                ans += y;
                next--;
                if (next > 0)
                    q.push({next, y});
            } else {
                ans += x;
                curr--;
            }
            if (curr > 0)
                q.push({curr, x});
        }
        return ans;
    }
};