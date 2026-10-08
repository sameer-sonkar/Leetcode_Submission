class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        vector<bool> remove(n, false);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push_back(i);
            } else {
                int idx = stk.back();
                stk.pop_back();
                if (stk.size() == 0) {
                    remove[idx] = true;
                    remove[i] = true;
                }
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (remove[i])
                continue;
            ans += s[i];
        }
        return ans;
    }
};