class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                ans = max(ans, cnt);
                cnt--;

            } else if (s[i] == '(') {
                cnt++;
            }
        }
        return ans;
    }
};