class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<int, int> m;
        int n = s.size();
        m[0] = -1;

        string ans = "#";
        int len = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt++;
            if (m.find(cnt - k) != m.end()) {
                int temp = i - m[cnt - k];
                int idx = m[cnt - k] + 1;
                if (temp < len) {
                    len = temp;
                    ans = s.substr(idx, len);

                } else if (temp == len) {
                    string temp2 = s.substr(idx, len);
                    if (temp2 < ans)
                        ans = temp2;
                }
            }
            m[cnt] = i;
        }
        if (ans == "#")
            return "";
        return ans;
    }
};